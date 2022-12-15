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
#include "../include/new/species_tables.h"
#include "../include/new/util.h"

extern const species_t gRandomizerSpeciesBanList[];

#define TRIES_FOR_SINGLE_LOOPVAL 256
#define BITWISE_SHIFTS 32
#define BACKUP_TRIES 512

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

	return hashVal;
}

u16 InitialSpeciesRandomizer(unusedArg u16 species, u32 trainerId, u8 locationGroup, u8 locationId, u8 index, bool8 trainerBattle)
{
	u32 loopVal = 2654435761;
	u32 toHash;
	u16 j;
	u16 oldSpecies = species;
	u16 newSpecies = SPECIES_NONE;

	toHash = (trainerId * oldSpecies) ^ 0x9e3779b9;
	toHash ^= (toHash << locationGroup) + (toHash >> locationId);
	toHash += toHash * (index + 1);
	newSpecies = GetSpeciesFromHashVal(toHash);

	for(u8 i = 0; i < BITWISE_SHIFTS; i++)
	{
		loopVal = (loopVal << i) | (loopVal >> (32 - i));
		j = 1;
		while((trainerBattle ? IsSpeciesBannedFromTrainerRandomizer(newSpecies) : IsSpeciesBannedFromRandomizer(newSpecies)) 
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

u16 BackupSpeciesRandomizer(unusedArg u16 species, u32 id, bool8 trainerBattle)
{
	u16 newSpecies;
	u16 speciesCount = NUM_SPECIES_RANDOMIZER;
	u16 startAt = (id & 0xFFFF) % (u32) speciesCount;
	u16 xorVal = (id >> 16) % (u32) 0x400; //Only set the bits likely to be in the species
	u32 numAttempts = 0;

	newSpecies = species + startAt;
	if (newSpecies >= speciesCount)
	{
		u16 overflow = newSpecies - (speciesCount - 2);
		newSpecies = overflow;
	}

	newSpecies ^= xorVal;
	newSpecies %= (u32) speciesCount; //Prevent overflow
	
	while ((trainerBattle ? IsSpeciesBannedFromTrainerRandomizer(newSpecies) : IsSpeciesBannedFromRandomizer(newSpecies))
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
	u16 opponentId = gTrainerBattleOpponent_A;
	u8 index = gPartyIndexLoaded;
	u32 hashVal = SetInitialHashValueForTrainerRandomizer(opponentId);
	
	newSpecies = InitialSpeciesRandomizer(oldSpecies, trainerId * hashVal, locationGroup, locationId, index, TRUE);
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
		if(gNewBS->isTrainerBattle)
			TryRandomizeForTrainers(species);
		else
		{
			u16 oldSpecies = *species;
			u16 newSpecies = SPECIES_NONE;
			u32 trainerId = T1_READ_32(gSaveBlock2->playerTrainerId);
			u8 locationGroup = gSaveBlock1->location.mapGroup;
			u8 locationId = gSaveBlock1->location.mapNum;
			u8 index = gLastWildIndex;

			newSpecies = InitialSpeciesRandomizer(oldSpecies, trainerId, locationGroup, locationId, index, FALSE);
			if(newSpecies == SPECIES_NONE)
				newSpecies = BackupSpeciesRandomizer(oldSpecies, trainerId * (locationGroup + 1) * (locationId + 1) * (index + 1), FALSE);

			*species = newSpecies;
		}
	}
	#endif
}

bool8 IsSpeciesBannedFromRandomizer(u16 species)
{
	return gSpecialSpeciesFlags[species].randomizerFullBan || gSpecialSpeciesFlags[species].randomizerGettableBan;
}

bool8 IsMonSuitableForLocation(u16 species, bool8 *inCase)
{
	u8 locGroup = gSaveBlock1->location.mapGroup;
	u8 locNum = gSaveBlock1->location.mapNum;
	bool8 foundSuitableMon = FALSE;
	*inCase = FALSE;

	if (locGroup == 6 && locNum == 2) // Brock's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_ROCK);
		*inCase = TRUE;
	}
	else if (locGroup == 7 && locNum == 5) // Misty's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_WATER);
		*inCase = TRUE;
	}
	else if (locGroup == 9 && locNum == 6) // Surge's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_ELECTRIC);
		*inCase = TRUE;
	}
	else if (locGroup == 10 && locNum == 16) // Erika's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_GRASS);
		*inCase = TRUE;
	}
	else if (locGroup == 11 && locNum == 3) // Koga's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_POISON);
		*inCase = TRUE;
	}
	else if (locGroup == 14 && locNum == 3) // Sabrina's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_PSYCHIC);
		*inCase = TRUE;
	}
	else if (locGroup == 14 && locNum == 2) // Saffron Dojo
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_FIGHTING);
		*inCase = TRUE;
	}
	else if (locGroup == 12 && locNum == 0) // Blaine's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_FIRE);
		*inCase = TRUE;
	}
	else if (locGroup == 5 && locNum == 1) // Giovanni's gym
	{
		foundSuitableMon = IsSpeciesOfType(species, TYPE_GROUND);
		*inCase = TRUE;
	}
	else
	{
		foundSuitableMon = FALSE;
	}

	return foundSuitableMon;
}

bool8 IsMonSuitableForSpecificTrainer(u16 species, bool8 *inCase)
{
	u16 trainerId = gTrainerBattleOpponent_A;
	bool8 foundSuitableMon = FALSE;
	*inCase = FALSE;

	switch(trainerId)
	{
		case 0x15C:
		case 0x15D: // Giovanni
		case 0x15E:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_GROUND);
			*inCase = TRUE;
			break;
		case 0x19A: 
		case 0x2DF: // Lorelei
			foundSuitableMon = IsSpeciesOfType(species, TYPE_ICE);
			*inCase = TRUE;
			break;
		case 0x19B:
		case 0x2E0: // Bruno
			foundSuitableMon = IsSpeciesOfType(species, TYPE_FIGHTING)
							+ IsSpeciesOfType(species, TYPE_ROCK);
			*inCase = TRUE;
			break;
		case 0x19C:
		case 0x2E1: // Agatha
			foundSuitableMon = IsSpeciesOfType(species, TYPE_GHOST)
							+ IsSpeciesOfType(species, TYPE_POISON);
			*inCase = TRUE;
			break;
		case 0x19D:
		case 0x2E2: // Lance
			foundSuitableMon = IsSpeciesOfType(species, TYPE_DRAGON);
			*inCase = TRUE;
			break;
		default:
			foundSuitableMon = FALSE;
	}

	return foundSuitableMon;
}

bool8 IsMonSuitableForTrainerClass(u16 species, bool8 *inCase)
{
	u16 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
	bool8 foundSuitableMon = TRUE;

	switch(trainerClass)
	{
		case CLASS_YOUNGSTER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_GRASS)
							+ IsSpeciesOfType(species, TYPE_POISON)
							+ IsSpeciesOfType(species, TYPE_ELECTRIC)
							+ IsSpeciesOfType(species, TYPE_BUG)
							+ IsSpeciesOfType(species, TYPE_FLYING);
			*inCase = TRUE;
			break;
		case CLASS_BUG_CATCHER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_BUG);
			*inCase = TRUE;
			break;
		case CLASS_LASS:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_GRASS)
							+ IsSpeciesOfType(species, TYPE_FAIRY)
							+ IsSpeciesOfType(species, TYPE_WATER)
							+ IsSpeciesOfType(species, TYPE_ICE)
							+ IsSpeciesOfType(species, TYPE_FLYING);
			*inCase = TRUE;
			break;
			foundSuitableMon = IsSpeciesOfType(species, TYPE_WATER);
			break;
		case CLASS_CAMPER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_GRASS)
							+ IsSpeciesOfType(species, TYPE_POISON)
							+ IsSpeciesOfType(species, TYPE_GROUND)
							+ IsSpeciesOfType(species, TYPE_PSYCHIC);
			*inCase = TRUE;
			break;
		case CLASS_PICNICKER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_GRASS)
							+ IsSpeciesOfType(species, TYPE_FAIRY)
							+ IsSpeciesOfType(species, TYPE_GROUND)
							+ IsSpeciesOfType(species, TYPE_PSYCHIC)
							+ IsSpeciesOfType(species, TYPE_FLYING);
			*inCase = TRUE;
			break;
		case CLASS_SUPER_NERD:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_STEEL)
							+ IsSpeciesOfType(species, TYPE_ELECTRIC)
							+ IsSpeciesOfType(species, TYPE_POISON);
			*inCase = TRUE;
			break;
		case CLASS_HIKER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_ROCK)
							+ IsSpeciesOfType(species, TYPE_STEEL)
							+ IsSpeciesOfType(species, TYPE_GROUND);
			*inCase = TRUE;
			break;
		case CLASS_BIKER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_POISON)
							+ IsSpeciesOfType(species, TYPE_FIRE)
							+ IsSpeciesOfType(species, TYPE_DARK)
							+ IsSpeciesOfType(species, TYPE_GHOST)
							+ IsSpeciesOfType(species, TYPE_FIGHTING);
			*inCase = TRUE;
			break;
		case CLASS_BURGLAR:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_FIRE)
							+ IsSpeciesOfType(species, TYPE_POISON);
			*inCase = TRUE;
			break;
		case CLASS_ENGINEER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_STEEL)
							+ IsSpeciesOfType(species, TYPE_ELECTRIC);
			*inCase = TRUE;
			break;
		case CLASS_SAILOR:
		case CLASS_FISHERMAN:
		case CLASS_SWIMMER_F:
		case CLASS_SWIMMER_M:
		case CLASS_TUBER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_WATER);
			*inCase = TRUE;
			break;
		case CLASS_CUE_BALL:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_DARK)
							+ IsSpeciesOfType(species, TYPE_POISON)
							+ IsSpeciesOfType(species, TYPE_FIGHTING);
			*inCase = TRUE;
			break;
		case CLASS_BEAUTY:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_FAIRY);
			*inCase = TRUE;
			break;
		case CLASS_PSYCHIC:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_PSYCHIC);
			*inCase = TRUE;
			break;
		case CLASS_ROCKER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_ELECTRIC);
			*inCase = TRUE;
			break;
		case CLASS_JUGGLER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_ELECTRIC)
							+ IsSpeciesOfType(species, TYPE_PSYCHIC);
			*inCase = TRUE;
			break;
		case CLASS_TAMER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_GRASS)
							+ IsSpeciesOfType(species, TYPE_DARK);
			*inCase = TRUE;
			break;
		case CLASS_BIRD_KEEPER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_FLYING);
			*inCase = TRUE;
			break;
		case CLASS_BLACK_BELT:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_FIGHTING);
			*inCase = TRUE;
			break;
		case CLASS_SCIENTIST:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_ELECTRIC)
							+ IsSpeciesOfType(species, TYPE_GHOST)
							+ IsSpeciesOfType(species, TYPE_STEEL);
			*inCase = TRUE;
			break;
		case CLASS_TEAM_ROCKET:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_NORMAL)
							+ IsSpeciesOfType(species, TYPE_DARK)
							+ IsSpeciesOfType(species, TYPE_GROUND)
							+ IsSpeciesOfType(species, TYPE_POISON);
			*inCase = TRUE;
			break;
		case CLASS_CHANNELER:
			foundSuitableMon = IsSpeciesOfType(species, TYPE_GHOST);
			*inCase = TRUE;
			break;
		default:
			foundSuitableMon = TRUE;
	}

	return foundSuitableMon;
}

bool8 IsSpeciesBannedFromTrainerRandomizer(u16 species)
{
	bool8 inCase = FALSE;

	if(gSpecialSpeciesFlags[species].randomizerFullBan)
		return TRUE;

	if(!IsMonSuitableForSpecificTrainer(species, &inCase) && inCase == TRUE)
		return TRUE;

	if(!IsMonSuitableForLocation(species, &inCase) && inCase == TRUE)
		return TRUE;

	if(!IsMonSuitableForTrainerClass(species, &inCase) && inCase == TRUE)
		return TRUE;

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