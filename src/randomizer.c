#include "defines.h"
#include "defines_battle.h"
#include "../include/battle_setup.h"
#include "../include/event_data.h"
#include "../include/mgba.h"
#include "../include/pokemon.h"
#include "../include/pokemon_storage_system.h"
#include "../include/random.h"
#include "../include/script.h"
#include "../include/string_util.h"
#include "../include/wild_encounter.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/pokemon.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/species.h"
#include "../include/constants/trainer_classes.h"
#include "../include/constants/trainers.h"
#include "../include/constants/tutors.h"

#include "../include/new/ability_tables.h"
#include "../include/new/ai_advanced.h"
#include "../include/new/battle_util.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/build_pokemon_2.h"
#include "../include/new/catching.h"
#include "../include/new/damage_calc.h"
#include "../include/new/dexnav.h"
#include "../include/new/dynamax.h"
#include "../include/new/exp.h"
#include "../include/new/form_change.h"
#include "../include/new/frontier.h"
#include "../include/new/item.h"
#include "../include/new/learn_move.h"
#include "../include/new/mega.h"
#include "../include/new/move_tables.h"
#include "../include/new/multi.h"
#include "../include/new/pokemon_storage_system.h"
#include "../include/new/randomizer.h"
#include "../include/new/rom_locs.h"
#include "../include/new/species_tables.h"
#include "../include/new/util.h"

extern const species_t gRandomizerSpeciesBanList[];
extern const u8 gTypeNames[][TYPE_NAME_LENGTH + 1];

#define TRIES_FOR_SINGLE_LOOPVAL 256
#define BITWISE_SHIFTS 32
#define BACKUP_TRIES 512
#define TRAINER_NEARBY_SEARCHES 6

u32 hash_uint(u32 x)
{
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;

	return x;
}

u16 GetSpeciesFromHashVal(u32 toHash)
{
	u16 speciesCount = NUM_SPECIES_RANDOMIZER;
	u32 s = hash_uint(toHash);
	u16 species = (u16)(s % (u32) speciesCount);
	return species; 
}

u32 SetInitialHashValueForTrainerRandomizer(u16 trainerId)
{
	u32 p = 31;
	u32 hashVal = 0;
	u32 m = 1e9 + 9;
	u32 p_pow = 1;

	for(u8 i = 0; gTrainers[trainerId].trainerName[i] != EOS; i++)
	{
		u8 letter = gTrainers[trainerId].trainerName[i];
		hashVal = (hashVal + (letter - CHAR_A + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	hashVal += (trainerId * p_pow) % m;

	return hashVal;
}

u32 GetLocationHash(u8 locGroup, u8 locNum)
{
	u32 hash = 0;
	locGroup += 2;
	u8 num = locNum + 3;
	for (u8 i = 0; i < locGroup; ++i)
	{
		hash += (num * (i + 1));
	}

	return hash;
}

u16 InitialSpeciesRandomizer(unusedArg u16 species, u32 seed, u8 locationGroup, u8 locationId, u8 index, bool8 trainerBattle)
{
	u32 loopValConst = 2654435761;
	u32 loopVal = loopValConst;
	u32 toHash;
	u16 j;
	u16 oldSpecies = species;
	u16 newSpecies = SPECIES_NONE;

	toHash = (seed * oldSpecies) ^ 0x9e3779b9;
	toHash += GetLocationHash(locationGroup, locationId);
	toHash += toHash * (index + 1);
	newSpecies = GetSpeciesFromHashVal(toHash);

	for(u8 i = 0; i < BITWISE_SHIFTS; i++)
	{
		loopVal = (loopValConst << i) | (loopValConst >> (32 - i));
		j = 1;
		while((trainerBattle ? !TryRandomizeTrainerMon(&newSpecies) : IsSpeciesBannedFromRandomizer(newSpecies)) 
			&& j <= TRIES_FOR_SINGLE_LOOPVAL)
		{
			toHash += (loopVal * j);
			newSpecies = GetSpeciesFromHashVal(toHash);
			j++;
		}
		if(j <= TRIES_FOR_SINGLE_LOOPVAL)
		{
			return newSpecies;
		}
	}

	return SPECIES_NONE;
}

u16 BackupSpeciesRandomizer(unusedArg u16 species, u32 seed, bool8 trainerBattle)
{
	u16 newSpecies;
	u16 speciesCount = NUM_SPECIES_RANDOMIZER;
	u16 startAt = (seed & 0xFFFF) % (u32) speciesCount;
	u16 xorVal = (seed >> 16) % (u32) 0x400; //Only set the bits likely to be in the species
	u32 numAttempts = 0;

	newSpecies = species + startAt;
	if (newSpecies >= speciesCount)
	{
		u16 overflow = newSpecies - (speciesCount - 2);
		newSpecies = overflow;
	}

	newSpecies ^= xorVal;
	newSpecies %= (u32) speciesCount; //Prevent overflow
	
	while ((trainerBattle ? !TryRandomizeTrainerMon(&newSpecies) : IsSpeciesBannedFromRandomizer(newSpecies))
		 && numAttempts < BACKUP_TRIES)
	{
		newSpecies *= xorVal;
		newSpecies %= (u32) speciesCount;
		++numAttempts;
	}

	if (numAttempts >= BACKUP_TRIES)
		newSpecies = SPECIES_DITTO;

	return newSpecies;
}

void TryRandomizeForTrainers(unusedArg u16* species)
{
	u16 oldSpecies = *species;
	u16 newSpecies = SPECIES_NONE;
	u32 trainerId = T1_READ_32(gSaveBlock2->playerTrainerId);
	u8 locationGroup = gSaveBlock1->location.mapGroup;
	u8 locationId = gSaveBlock1->location.mapNum;
	u8 index = gPartyIndexLoaded;
	u32 hashVal = gTrainerHashVal;
	
	newSpecies = InitialSpeciesRandomizer(oldSpecies, trainerId * hashVal, locationGroup, locationId, index * 10, TRUE);
	if(newSpecies == SPECIES_NONE)
		newSpecies = BackupSpeciesRandomizer(oldSpecies, trainerId * hashVal * (locationGroup+1) * (locationId+1) * (index+1), TRUE);

	if(FlagGet(FLAG_HARD_LEVEL_CAP))
	{
		DevolveSpeciesByLevel(&newSpecies, GetCurrentLevelCap());
		EvolveSpeciesByLevel(&newSpecies, GetCurrentLevelCap());
	}

	*species = newSpecies;
}

void TryRandomizeSpecies(unusedArg u16* species)
{
	#ifdef FLAG_POKEMON_RANDOMIZER
	if (FlagGet(FLAG_POKEMON_RANDOMIZER) && !FlagGet(FLAG_BATTLE_FACILITY)
	#ifdef FLAG_TEMP_DISABLE_RANDOMIZER
	&& !FlagGet(FLAG_TEMP_DISABLE_RANDOMIZER)
	#endif
	&& *species != SPECIES_NONE && *species != SPECIES_ZYGARDE_CELL && *species < NUM_SPECIES)
	{
		if(gNewBS->isTrainerBattle && !(gSaveBlock1->location.mapGroup == 4 && gSaveBlock1->location.mapNum == 3))
			TryRandomizeForTrainers(species);
		else
		{
			u16 oldSpecies = *species;
			u16 newSpecies = SPECIES_NONE;
			u32 seed = gSaveBlock1->randomizerSeed;
			u8 locationGroup = gSaveBlock1->location.mapGroup;
			u8 locationId = gSaveBlock1->location.mapNum;
			u8 index = gLastWildIndex;

			newSpecies = InitialSpeciesRandomizer(oldSpecies, seed, locationGroup, locationId, index, FALSE);
			if(newSpecies == SPECIES_NONE)
				newSpecies = BackupSpeciesRandomizer(oldSpecies, seed * (locationGroup + 1) * (locationId + 1) * (index + 1), FALSE);

			*species = newSpecies;
		}
	}
	*species = FindReplacementSpecies(*species);
	#endif
}

bool8 IsSpeciesBannedFromRandomizer(u16 species)
{
	return gSpecialSpeciesFlags[species].randomizerFullBan || gSpecialSpeciesFlags[species].randomizerGettableBan;
}

bool8 IsSpeciesAllowedInTrainerRandomizer(u16 species)
{
	u8 locGroup = gSaveBlock1->location.mapGroup;
	u8 locNum = gSaveBlock1->location.mapNum;
	u16 trainerId = gTrainerBattleOpponent_A;
	u16 trainerClass = gTrainers[trainerId].trainerClass;

	if(gSpecialSpeciesFlags[species].randomizerFullBan)
		return FALSE;

	//Check for specific trainer
	switch(trainerId)
	{
		case 0x15C:
		case 0x15D: // Giovanni
		case 0x15E:
			return IsSpeciesOfType(species, TYPE_GROUND);
		case 0x19A: 
		case 0x2DF: // Lorelei
			return IsSpeciesOfType(species, TYPE_ICE);
		case 0x19B:
		case 0x2E0: // Bruno
			return IsSpeciesOfType(species, TYPE_FIGHTING)
					+ IsSpeciesOfType(species, TYPE_ROCK);
		case 0x19C:
		case 0x2E1: // Agatha
			return IsSpeciesOfType(species, TYPE_GHOST)
					+ IsSpeciesOfType(species, TYPE_POISON);
		case 0x19D:
		case 0x2E2: // Lance
			return IsSpeciesOfType(species, TYPE_DRAGON);
	}

	//Check for specific location
	if (locGroup == 6 && locNum == 2) // Brock's gym
	{
		return IsSpeciesOfType(species, TYPE_ROCK);
	}
	else if (locGroup == 7 && locNum == 5) // Misty's gym
	{
		return IsSpeciesOfType(species, TYPE_WATER);
	}
	else if (locGroup == 9 && locNum == 6) // Surge's gym
	{
		return IsSpeciesOfType(species, TYPE_ELECTRIC);
	}
	else if (locGroup == 10 && locNum == 16) // Erika's gym
	{
		return IsSpeciesOfType(species, TYPE_GRASS);
	}
	else if (locGroup == 11 && locNum == 3) // Koga's gym
	{
		return IsSpeciesOfType(species, TYPE_POISON);
	}
	else if (locGroup == 14 && locNum == 3) // Sabrina's gym
	{
		return IsSpeciesOfType(species, TYPE_PSYCHIC);
	}
	else if (locGroup == 14 && locNum == 2) // Saffron Dojo
	{
		return IsSpeciesOfType(species, TYPE_FIGHTING);
	}
	else if (locGroup == 12 && locNum == 0) // Blaine's gym
	{
		return IsSpeciesOfType(species, TYPE_FIRE);
	}
	else if (locGroup == 5 && locNum == 1) // Giovanni's gym
	{
		return IsSpeciesOfType(species, TYPE_GROUND);
	}

	//Check for trainer class
	switch(trainerClass)
	{
		case CLASS_YOUNGSTER:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_GRASS)
					+ IsSpeciesOfType(species, TYPE_POISON)
					+ IsSpeciesOfType(species, TYPE_ELECTRIC)
					+ IsSpeciesOfType(species, TYPE_BUG)
					+ IsSpeciesOfType(species, TYPE_FLYING);
		case CLASS_BUG_CATCHER:
			return IsSpeciesOfType(species, TYPE_BUG);
		case CLASS_LASS:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_GRASS)
					+ IsSpeciesOfType(species, TYPE_FAIRY)
					+ IsSpeciesOfType(species, TYPE_WATER)
					+ IsSpeciesOfType(species, TYPE_ICE)
					+ IsSpeciesOfType(species, TYPE_FLYING);
		case CLASS_CAMPER:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_GRASS)
					+ IsSpeciesOfType(species, TYPE_POISON)
					+ IsSpeciesOfType(species, TYPE_GROUND)
					+ IsSpeciesOfType(species, TYPE_PSYCHIC);
		case CLASS_PICNICKER:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_GRASS)
					+ IsSpeciesOfType(species, TYPE_FAIRY)
					+ IsSpeciesOfType(species, TYPE_GROUND)
					+ IsSpeciesOfType(species, TYPE_PSYCHIC)
					+ IsSpeciesOfType(species, TYPE_FLYING);
		case CLASS_SUPER_NERD:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_STEEL)
					+ IsSpeciesOfType(species, TYPE_ELECTRIC)
					+ IsSpeciesOfType(species, TYPE_POISON);
		case CLASS_HIKER:
			return IsSpeciesOfType(species, TYPE_ROCK)
					+ IsSpeciesOfType(species, TYPE_STEEL)
					+ IsSpeciesOfType(species, TYPE_GROUND);
		case CLASS_BIKER:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_POISON)
					+ IsSpeciesOfType(species, TYPE_FIRE)
					+ IsSpeciesOfType(species, TYPE_DARK)
					+ IsSpeciesOfType(species, TYPE_GHOST)
					+ IsSpeciesOfType(species, TYPE_FIGHTING);
		case CLASS_BURGLAR:
			return IsSpeciesOfType(species, TYPE_FIRE)
					+ IsSpeciesOfType(species, TYPE_POISON);
		case CLASS_ENGINEER:
			return IsSpeciesOfType(species, TYPE_STEEL)
					+ IsSpeciesOfType(species, TYPE_ELECTRIC);
		case CLASS_SAILOR:
		case CLASS_FISHERMAN:
		case CLASS_SWIMMER_F:
		case CLASS_SWIMMER_M:
		case CLASS_TUBER:
			return IsSpeciesOfType(species, TYPE_WATER);
		case CLASS_CUE_BALL:
			return IsSpeciesOfType(species, TYPE_DARK)
					+ IsSpeciesOfType(species, TYPE_POISON)
					+ IsSpeciesOfType(species, TYPE_FIGHTING);
		case CLASS_BEAUTY:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_FAIRY);
		case CLASS_PSYCHIC:
			return IsSpeciesOfType(species, TYPE_PSYCHIC);
		case CLASS_ROCKER:
			return IsSpeciesOfType(species, TYPE_ELECTRIC);
		case CLASS_JUGGLER:
			return IsSpeciesOfType(species, TYPE_ELECTRIC)
					+ IsSpeciesOfType(species, TYPE_PSYCHIC);
		case CLASS_TAMER:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_GRASS)
					+ IsSpeciesOfType(species, TYPE_DARK);
		case CLASS_BIRD_KEEPER:
			return IsSpeciesOfType(species, TYPE_FLYING);
		case CLASS_BLACK_BELT:
			return IsSpeciesOfType(species, TYPE_FIGHTING);
		case CLASS_SCIENTIST:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_ELECTRIC)
					+ IsSpeciesOfType(species, TYPE_GHOST)
					+ IsSpeciesOfType(species, TYPE_STEEL);
		case CLASS_TEAM_ROCKET:
			return IsSpeciesOfType(species, TYPE_NORMAL)
					+ IsSpeciesOfType(species, TYPE_DARK)
					+ IsSpeciesOfType(species, TYPE_GROUND)
					+ IsSpeciesOfType(species, TYPE_POISON);
		case CLASS_CHANNELER:
			return IsSpeciesOfType(species, TYPE_GHOST);
	}

	return TRUE;
}

bool8 TryRandomizeTrainerMon(u16* species)
{
	u16 consideredSpecies = *species;
	u8 loopLen = TRAINER_NEARBY_SEARCHES / 2;

	if (gSpecialSpeciesFlags[consideredSpecies].randomizerFullBan)
		return FALSE;

	if (!IsSpeciesAllowedInTrainerRandomizer(consideredSpecies))
	{
		for (u8 i = 0; i < loopLen; i++)
		{
			u16 mon1 = consideredSpecies - (i+1);
			u16 mon2 = consideredSpecies + (i+1);

			if (IsSpeciesAllowedInTrainerRandomizer(mon1))
			{
				*species = mon1;
				return TRUE;
			}

			if (IsSpeciesAllowedInTrainerRandomizer(mon2))
			{
				*species = mon2;
				return TRUE;
			}
		}
	}
	else
	{
		return TRUE;
	}
	return FALSE;
}

u16 GetRandomizedSpecies(u16 species)
{
	TryRandomizeSpecies(&species);
	return species;
}

move_t RandomizeMove(u16 move)
{
	if (move == MOVE_NONE)
		return move;

	u16 newMove;
	u32 id = T1_READ_32(gSaveBlock2->playerTrainerId);
	u16 startAt = (id & 0xFFFF) % (u32) NON_Z_MOVE_COUNT;
	u16 xorVal = (id >> 16) % (u32) 0x300; //Only set the bits likely to be in the move
	u32 numAttempts = 0;

	newMove = move + startAt;
	if (newMove >= NON_Z_MOVE_COUNT)
	{
		u16 overflow = newMove - (NON_Z_MOVE_COUNT - 2);
		newMove = overflow;
	}

	newMove ^= xorVal;
	newMove %= (u32) NON_Z_MOVE_COUNT; //Prevent overflow

	while (gSpecialMoveFlags[newMove].gRandomizerBanTable && numAttempts < 100)
	{
		newMove *= xorVal; //Multiply this time
		newMove %= (u32) NON_Z_MOVE_COUNT;
		++numAttempts;
	}

	if (numAttempts >= 100 && gSpecialMoveFlags[newMove].gRandomizerBanTable) //Tried 100 times to change move but can't find a legal one
		newMove = MOVE_TACKLE; //Just replace the move with tackle

	return newMove;
}

bool8 IsOriginalFormChangeAbilityBannedInRandomizer(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species);
}

bool8 IsOriginalAbilityBannedInRandomizer(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRandomizerBannedOriginalAbilities || IsOriginalFormChangeAbilityBannedInRandomizer(ability, species);
}

bool8 IsNewFormChangeAbilityBannedInRandomizer(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsNewAbilityBannedInRandomizer(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRandomizerBannedNewAbilities || IsNewFormChangeAbilityBannedInRandomizer(ability, species);
}

u8 TryRandomizeAbility(u8 originalAbility, unusedArg u16 species)
{
	u32 newAbility = originalAbility;

	#ifdef FLAG_ABILITY_RANDOMIZER
	if (FlagGet(FLAG_ABILITY_RANDOMIZER) && !FlagGet(FLAG_BATTLE_FACILITY)
	&& !IsOriginalAbilityBannedInRandomizer(originalAbility, species)) //This Ability can be changed
	{
		u32 id = T1_READ_32(gSaveBlock2->playerTrainerId);
		u16 startAt = (id & 0xFFFF) % (u32) ABILITIES_COUNT + species;
		u16 xorVal = (id >> 16) % (u32) 0xFF; //Only set the bits likely to be in the ability
		u32 numAttempts = 0;

		newAbility = originalAbility + startAt;
		if (newAbility >= ABILITIES_COUNT)
		{
			u16 overflow = newAbility - (ABILITIES_COUNT - 2);
			newAbility = overflow;
		}

		newAbility ^= xorVal;
		newAbility %= (u32) ABILITIES_COUNT; //Prevent overflow

		while (IsNewAbilityBannedInRandomizer(newAbility, species) && numAttempts < 100)
		{
			newAbility *= xorVal; //Multiply this time
			newAbility %= (u32) ABILITIES_COUNT;
			++numAttempts;
		}

		if (numAttempts >= 100 && IsNewAbilityBannedInRandomizer(newAbility, species)) //If the Ability is still banned
			newAbility = originalAbility; //Just use the original ability
		else if (newAbility == ABILITY_NONE) //Somehow wound up with no Ability
			newAbility = originalAbility; //Just use the original ability
	}
	#endif

	return newAbility;
}