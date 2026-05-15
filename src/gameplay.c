#include "defines.h"
#include "defines_battle.h"
#include "../include/battle_transition.h"
#include "../include/event_object_movement.h"
#include "../include/fieldmap.h"
#include "../include/field_player_avatar.h"
#include "../include/field_weather.h"
#include "../include/script.h"
#include "../include/rtc.h"
#include "../include/text.h"
#include "../include/wild_encounter.h"
#include "../include/random.h"

#include "../include/constants/flags.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/pokemon.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/species.h"
#include "../include/constants/trainer_classes.h"
#include "../include/constants/trainers.h"
#include "../include/constants/tutors.h"

#include "../include/new/ability_util.h"
#include "../include/new/battle_start_turn_start.h"
#include "../include/new/battle_transition.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/catching.h"
#include "../include/new/daycare.h"
#include "../include/new/dns.h"
#include "../include/new/dynamax.h"
#include "../include/new/evolution.h"
#include "../include/new/exp.h"
#include "../include/new/gameplay.h"
#include "../include/new/overworld.h"
#include "../include/new/roamer.h"
#include "../include/new/util.h"
#include "../include/new/wild_encounter.h"

#define LAND_HASH 0x87E2EF45
#define SURF_HASH 0xCA58E129
#define FISH_HASH 0xD3F408DF
#define ROCK_HASH 0x9EE34045

u32 hash_uint(u32 x)
{
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;

	return x;
}

static u16 GetLocationHashValue()
{
	u8 locGroup = gSaveBlock1->location.mapGroup;
	u8 locNum = gSaveBlock1->location.mapNum;

    return (u16)((locGroup << 8) | locNum);
}

static u16 GetWildEncounterHashValue(u16 species, u8 index)
{
    uint32_t hash = 2166136261;
    hash ^= species;
    hash *= 16777619;           
    hash ^= index;
    hash *= 16777619;
    return (u16)(hash ^ (hash >> 16));
}

extern const u16 gNumTier1List;
extern const u16 gNumTier2List;
extern const u16 gNumTier3List;
extern const u16 gNumTierLegendsList;

extern const species_t gTier1List[];
extern const species_t gTier2List[];
extern const species_t gTier3List[];
extern const species_t gTierLegendsList[];
extern const u16 SpeciesCountCapUnlocks[];
extern const u16 TrainerMaxSpeciesIndices[20][4];
extern const u16 gTrainerClassPokemonTypes[NUM_TRAINER_CLASSES][NUM_TRAINER_CLASS_SPECIFIC_TYPES];
extern const u16 gTypeBoosters[NUMBER_OF_MON_TYPES];
extern const u16 gTypeResistBerries[NUMBER_OF_MON_TYPES];
extern const u16 gTypeGems[NUMBER_OF_MON_TYPES];

extern const species_t gDeerlingForms[];
extern const species_t gSawsbuckForms[];
extern const species_t gVivillonForms[];
extern const species_t gFurfrouForms[];
extern const species_t gFlabebeForms[];
extern const species_t gFloetteForms[];
extern const species_t gFlorgesForms[];
extern const species_t gPikachuCapForms[];
extern const species_t gAlcremieForms[];
extern const species_t gSquawkabillyForms[];
extern const species_t gTatsugiriForms[];
extern const u8 gNumDeerlingForms;
extern const u8 gNumSawsbuckForms;
extern const u8 gNumVivillonForms;
extern const u8 gNumFlabebeForms;
extern const u8 gNumFloetteForms;
extern const u8 gNumFlorgesForms;
extern const u8 gNumFurfrouForms;
extern const u8 gNumPikachuCapForms;
extern const u8 gNumAlcremieForms;
extern const u8 gNumSquawkabillyForms;
extern const u8 gNumTatsugiriForms;


static u16 GetSpeciesCountBasedOnLevelCap(void)
{
	u8 capIndex = DetermineLevelCapIndex();
	u16 speciesCount = SpeciesCountCapUnlocks[capIndex];


	return speciesCount;
}

static u16 GetSpeciesFromNewSpeciesIndex(u16 newSpeciesIndex)
{
	u16 newSpecies;

	if (newSpeciesIndex >= gNumTier3List)
		newSpecies = gTierLegendsList[newSpeciesIndex - gNumTier3List];
	else if (newSpeciesIndex >= gNumTier2List)
		newSpecies = gTier3List[newSpeciesIndex - gNumTier2List];
	else if (newSpeciesIndex >= gNumTier1List)
		newSpecies = gTier2List[newSpeciesIndex - gNumTier1List];
	else
		newSpecies = gTier1List[newSpeciesIndex];

	return newSpecies;
}

bool8 IsHighestEvoStage(u16 species)
{
	for(u8 i = 0; i < EVOS_PER_MON; ++i)
	{
		if(gEvolutionTable[species][i].method != EVO_NONE 
			&& gEvolutionTable[species][i].method != EVO_MEGA 
			&& gEvolutionTable[species][i].method != EVO_GIGANTAMAX)
			return FALSE;
	}
	return TRUE;
}

u16 EnsureBasicSpeciesForm(u16 species)
{
	u16 nationalDexNum = SpeciesToNationalPokedexNum(species);

	switch(nationalDexNum)
	{
		case NATIONAL_DEX_CALYREX: 
			species = SPECIES_CALYREX;
			break;
		case NATIONAL_DEX_DEOXYS:
			species = SPECIES_DEOXYS;
			break;
		case NATIONAL_DEX_DIALGA:
			species = SPECIES_DIALGA;
			break;
		case NATIONAL_DEX_PALKIA:
			species = SPECIES_PALKIA;
			break;
		case NATIONAL_DEX_GIRATINA:
			species = SPECIES_GIRATINA;
			break;
		case NATIONAL_DEX_LANDORUS:
			species = SPECIES_LANDORUS;
			break;
		case NATIONAL_DEX_THUNDURUS:
			species = SPECIES_THUNDURUS;
			break;
		case NATIONAL_DEX_TORNADUS:
			species = SPECIES_TORNADUS;
			break;
		case NATIONAL_DEX_ENAMORUS:
			species = SPECIES_ENAMORUS;
			break;
		case NATIONAL_DEX_HOOPA:
			species = SPECIES_HOOPA;
			break;
		case NATIONAL_DEX_KYUREM:
			species = SPECIES_KYUREM;
			break;
		case NATIONAL_DEX_NECROZMA:
			species = SPECIES_NECROZMA;
			break;
		case NATIONAL_DEX_OGERPON:
			species = SPECIES_OGERPON;
			break;
		case NATIONAL_DEX_ROTOM:
			species = SPECIES_ROTOM;
			break;
	}

	return species;
}

static u16 AdjustEncounterAestheticSpecies(u16 species)
{
	u16 nationalDexNum = SpeciesToNationalPokedexNum(species);

	switch (nationalDexNum) {
		case NATIONAL_DEX_SHELLOS:
			if ((Random() & 1) == 0)
				species = SPECIES_SHELLOS;
			else
				species = SPECIES_SHELLOS_EAST;
			break;
		case NATIONAL_DEX_GASTRODON:
			if ((Random() & 1) == 0)
				species = SPECIES_GASTRODON;
			else
				species = SPECIES_GASTRODON_EAST;
			break;
		case NATIONAL_DEX_DEERLING:
			species = gDeerlingForms[Random() % gNumDeerlingForms];
			break;
		case NATIONAL_DEX_SAWSBUCK:
			species = gSawsbuckForms[Random() % gNumSawsbuckForms];
			break;
		case NATIONAL_DEX_VIVILLON:
			species = gVivillonForms[Random() % gNumVivillonForms];
			break;
		case NATIONAL_DEX_FLABEBE:
			species = gFlabebeForms[Random() % gNumFlabebeForms];
			break;
		case NATIONAL_DEX_FLOETTE:
			if (species != SPECIES_FLOETTE_ETERNAL)
				species = gFloetteForms[Random() % gNumFloetteForms];
			break;
		case NATIONAL_DEX_FLORGES:
			species = gFlorgesForms[Random() % gNumFlorgesForms];
			break;
		case NATIONAL_DEX_FURFROU:
			species = gFurfrouForms[Random() % gNumFurfrouForms];
			break;
		case NATIONAL_DEX_ALCREMIE:
			species = gAlcremieForms[Random() % gNumAlcremieForms];
			break;
		case NATIONAL_DEX_SQUAWKABILLY:
			species = gSquawkabillyForms[Random() % gNumSquawkabillyForms];
			break;
		case NATIONAL_DEX_TATSUGIRI:
			species = gTatsugiriForms[Random() & gNumTatsugiriForms];
			break;
		default:
			if (species == SPECIES_PIKACHU_CAP_ORIGINAL)
				species = gPikachuCapForms[Random() % gNumPikachuCapForms];
			break;
	}

	return species;
}

bool8 DevolveEncounterSpeciesByLevel(u16* originalSpecies, u8 level)
{
	int j, k;
	//bool8 found;
	u16 species = *originalSpecies;


	START:
	//found = FALSE;
	for (j = 1; j < NUM_SPECIES; ++j)
	{
		for (k = 0; k < EVOS_PER_MON; ++k)
		{
			if (gEvolutionTable[j][k].method == EVO_NONE) //Most likely end of entries
				break; //Break now to save time
			if(gEvolutionTable[j][k].targetSpecies == species && gEvolutionTable[j][k].method != EVO_MEGA && gEvolutionTable[j][k].method != EVO_GIGANTAMAX)
			{
				if (   (IsLevelUpEvolutionMethod(gEvolutionTable[j][k].method) && level < gEvolutionTable[j][k].param + 4)
					|| (IsFriendshipEvolutionMethod(gEvolutionTable[j][k].method))
					|| (IsItemEvolutionMethod(gEvolutionTable[j][k].method))
					|| (IsOtherEvolutionMethod(gEvolutionTable[j][k].method)))
				{
					species = j;
					goto START; //devolve until it can't
				}
			}
		}
	}

	if (species != *originalSpecies)
	{
		*originalSpecies = species;
		return TRUE;
	}
	else
		return FALSE;
}


void InitPlayerSeed(void)
{
	gSaveBlock1->playerSeed = Random32();
}

u16 ModifyEncounterSpecies(u16 species, u8 index, u8 level, u8 encounterType)
{
	u32 resultHash;
	u16 locationHash = GetLocationHashValue();
	u16 speciesHash = GetWildEncounterHashValue(species, index);
	u32 initialHash = ((locationHash << 16) | speciesHash);
	u32 playerSeed = gSaveBlock1->playerSeed;
	u16 speciesCount = GetSpeciesCountBasedOnLevelCap();
	u16 newSpeciesIndex;
	u16 newSpecies = species;

	switch(encounterType)
	{
    	case ENCOUNTER_SURF:
    		resultHash = initialHash ^ (SURF_HASH * playerSeed);
    		break;
    	case ENCOUNTER_FISH:
    		resultHash = initialHash ^ (FISH_HASH * playerSeed);
    		break;
    	case ENCOUNTER_ROCK:
    		resultHash = initialHash ^ (ROCK_HASH * playerSeed);
    		break;
    	case ENCOUNTER_LAND:
    	default:
    		resultHash = initialHash ^ (LAND_HASH * playerSeed);
    		break;
	}

	//resultHash = hash_uint(resultHash);
	newSpeciesIndex = resultHash % speciesCount;
	newSpecies = GetSpeciesFromNewSpeciesIndex(newSpeciesIndex);

	DevolveEncounterSpeciesByLevel(&newSpecies, level);
	newSpecies = EnsureBasicSpeciesForm(newSpecies);
	newSpecies = AdjustEncounterAestheticSpecies(newSpecies);
	return newSpecies;
}

bool8 IsBossTrainerClass(u8 trainerClass)
{
	return (trainerClass == CLASS_LEADER
		||  trainerClass == CLASS_ELITE_FOUR
		||  trainerClass == CLASS_BOSS
		||  trainerClass == CLASS_RIVAL_LATE
		||  trainerClass == CLASS_CHAMPION);
}

u8 TrainerPartySizes[][4] =
{						//trainer casual  //trainer challenge   //boss casual	//boss challenge
	[CAP_BROCK] = 			{2,					3,					5,				6,	},
	[CAP_MISTY] = 			{3,					3,					5,				6,	},
	[CAP_LT_SURGE] = 		{3,					4,					5,				6,	},
	[CAP_ERIKA] = 			{3,					4,					5,				6,	},
	[CAP_KOGA] = 			{3,					4,					6,				6,	},
	[CAP_SABRINA] = 		{3,					4,					6,				6,	},
	[CAP_BLAINE] = 			{3,					4,					6,				6,	},
	[CAP_GIOVANNI] = 		{3,					4,					6,				6,	},
	[CAP_FALKNER] = 		{4,					5,					6,				6,	},
	[CAP_BUGSY] = 			{4,					5,					6,				6,	},
	[CAP_WHITNEY] = 		{4,					5,					6,				6,	},
	[CAP_MORTY] = 			{4,					5,					6,				6,	},
	[CAP_KAREN] = 			{4,					5,					6,				6,	},
	[CAP_JASMINE] = 		{4,					5,					6,				6,	},
	[CAP_PRYCE] = 			{4,					5,					6,				6,	},
	[CAP_CLAIR] = 			{4,					5,					6,				6,	},
	[CAP_LG1] = 			{4,					5,					6,				6,	},
	[CAP_LG2] = 			{4,					5,					6,				6,	},
	[CAP_LG3] = 			{4,					5,					6,				6,	},
	[CAP_ELITE_FOUR] = 		{4,					5,					6,				6,	},
};

s16 TrainerLevelRanges[][8] =
{							//tr. casual      //tr. challenge 	  //boss casual      //boss challenge
	[CAP_BROCK] = 			{-5,	-2,			-3,		0,			-2,		0,		   -1,		0, },
	[CAP_MISTY] = 			{-5,	-2,			-3,		0,			-2,		0,		   -1,		0, },
	[CAP_LT_SURGE] = 		{-5,	-2,			-3,		0,			-2,		0,		   -1,		0, },
	[CAP_ERIKA] = 			{-5,	-2,			-3,		0,			-2,		0,		   -1,		0, },
	[CAP_KOGA] = 			{-4, 	-2,			-2,		0,			-2,		0,			0,		0, },
	[CAP_SABRINA] = 		{-4, 	-2,			-2,		0,			-2,		0,			0,		0, },
	[CAP_BLAINE] = 			{-4, 	-1,			-2,		0,			-2,		0,			0,		0, },
	[CAP_GIOVANNI] = 		{-4,	-1,			-2,		0,			-2,		0,			0,		0, },
	[CAP_FALKNER] = 		{-3,	-1,			-1,		0,			-1,		0,			0,		0, },
	[CAP_BUGSY] = 			{-3,	-1,			-1,		0,			-1,		0,			0,		0, },
	[CAP_WHITNEY] = 		{-3,	-1,			-1,		0,			-1,		0,			0,		0, },
	[CAP_MORTY] = 			{-3,	-1,			-1,		0,			-1,		0,			0,		0, },
	[CAP_KAREN] = 			{-3, 	 0,			 0,		0,			-1,		0,			0,		0, },
	[CAP_JASMINE] = 		{-3,	 0,			 0,		0,			-1,		0,			0,		0, },
	[CAP_PRYCE] = 			{-3, 	 0,			 0,		0,			-1,		0,			0,		0, },
	[CAP_CLAIR] = 			{-3, 	 0,			 0,		0,			-1,		0,			0,		0, },
	[CAP_LG1] = 			{-2, 	 0,			 0,		0,			 0,		0,			0,		0, },
	[CAP_LG2] = 			{-2, 	 0,			 0,		0,			 0,		0,			0,		0, },
	[CAP_LG3] = 			{-2, 	 0,			 0,		0,			 0,		0,			0,		0, },
	[CAP_ELITE_FOUR] = 		{-2, 	 0,			 0,		0,			 0,		0,			0,		0, },
};



u16 GetTrainerMaxSpeciesCount(u8 trainerClass)
{
	u8 capIndex = DetermineLevelCapIndex();
	u8 countIndex = FlagGet(FLAG_CHALLENGE_MODE) + (IsBossTrainerClass(trainerClass) ? 2 : 0);
	return TrainerMaxSpeciesIndices[capIndex][countIndex];
}

bool8 DoesMonFitTrainerClass(u16 species, u16 trainerId)
{//TO DO
	
	u8 locGroup = gSaveBlock1->location.mapGroup;
	u8 locNum = gSaveBlock1->location.mapNum;
	u8 trainerClass = gTrainers[trainerId].trainerClass;

	//Check for specific trainer
	switch(trainerId)
	{
		case TRAINER_BOSS_GIOVANNI:
		case TRAINER_BOSS_GIOVANNI_2:
		case TRAINER_LEADER_GIOVANNI:
			return IsSpeciesOfType(species, TYPE_GROUND);
		case TRAINER_ELITE_FOUR_LORELEI: 
		case TRAINER_ELITE_FOUR_LORELEI_2:
			return IsSpeciesOfType(species, TYPE_ICE) + IsSpeciesOfType(species, TYPE_WATER)
			 + IsSpeciesOfType(species, TYPE_ELECTRIC) + IsSpeciesOfType(species, TYPE_GRASS);
		case TRAINER_ELITE_FOUR_BRUNO:
		case TRAINER_ELITE_FOUR_BRUNO_2:
			return IsSpeciesOfType(species, TYPE_FIGHTING) + IsSpeciesOfType(species, TYPE_ROCK)
			+ IsSpeciesOfType(species, TYPE_STEEL) + IsSpeciesOfType(species, TYPE_GROUND);
		case TRAINER_ELITE_FOUR_AGATHA:
		case TRAINER_ELITE_FOUR_AGATHA_2:
			return IsSpeciesOfType(species, TYPE_GHOST) + IsSpeciesOfType(species, TYPE_POISON)
			+ IsSpeciesOfType(species, TYPE_DARK) + IsSpeciesOfType(species, TYPE_PSYCHIC);
		case TRAINER_ELITE_FOUR_LANCE:
		case TRAINER_ELITE_FOUR_LANCE_2:
			return IsSpeciesOfType(species, TYPE_DRAGON) + IsSpeciesOfType(species, TYPE_FLYING)
			+ IsSpeciesOfType(species, TYPE_FAIRY) + IsSpeciesOfType(species, TYPE_FIRE);
	}


	// Check if inside gym
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

	//Check trainer class-specific types
	u8 typeScore = 0, type;
	for(u8 i = 0; i < NUM_TRAINER_CLASS_SPECIFIC_TYPES; ++i)
	{	
		type = gTrainerClassPokemonTypes[trainerClass][i];

		if(type == TYPE_NONE)
			break;
		else if(type == TYPE_ANY)
			typeScore++;
		else
		{
			typeScore += IsSpeciesOfType(species, type);
		}
	}

	return (typeScore > 0);
}

u8 RandomizeLevelForTrainerMon(u8 trainerClass)
{
	u8 capIndex = DetermineLevelCapIndex();
	u8 isBoss = IsBossTrainerClass(trainerClass) ? 4 : 0;
	bool8 isChallengeMode = FlagGet(FLAG_CHALLENGE_MODE) ? 2 : 0;
	u8 minLevelDiff = TrainerLevelRanges[capIndex][isChallengeMode + isBoss + 0];
	u8 maxLevelDiff = TrainerLevelRanges[capIndex][isChallengeMode + isBoss + 1];
	u8 levelCap = GetCurrentLevelCap();
	u8 playerLevel = GetHighestMonLevel(gPlayerParty);

	if (playerLevel < levelCap)
		levelCap = playerLevel;

	u8 minLevel = levelCap + minLevelDiff;
	u8 maxLevel = levelCap + maxLevelDiff;

	u8 level = RandRange(minLevel, maxLevel + 1);

	return level;
}

u16 AdjustTrainerSpecies(u16 originalSpecies, u8 level)
{
	u16 newSpecies = originalSpecies;
	DevolveSpeciesByLevel(&newSpecies, level);

	newSpecies = AdjustEncounterAestheticSpecies(newSpecies);
	return newSpecies;
}

bool8 CheckSpeciesViabilityInTrainerParty(u16 species, u16* teamSpecies, u16 trainerId, u8 currIndex)
{
	bool8 speciesAlreadyInParty = FALSE;
	for(u8 i = 0; i < currIndex; ++i)
	{
		if(teamSpecies[i] == species)
			speciesAlreadyInParty = TRUE;
	}

	return (!speciesAlreadyInParty && DoesMonFitTrainerClass(species, trainerId));
}

u16 RandomizeHeldItemForCasualTrainer(u16 species)
{
	u16 randVal = Random() % 10;
	u16 heldItem = ITEM_NONE;
	u8 randAttackType = ((Random() & 1) == 0) ? gBaseStats[species].type1 : gBaseStats[species].type2;
	u8 randDefType = GetRandomSuperEffectiveType(species);

	switch (randVal)
	{
		case 0: 
		case 1: 
		case 2: 
		case 3: 
		case 4: 
			heldItem = ITEM_NONE;
			break;
		case 5:
		case 6:
			// random type-resist berry
			heldItem = gTypeResistBerries[randDefType];
			break;
		case 7:
		case 8:
			// random type gem
			heldItem = gTypeGems[randAttackType];
			break;
		case 9:
			// random type booster
			heldItem = gTypeBoosters[randAttackType];
			break;
	}
	return heldItem;
}

u16 RandomizeTrainerSpecies(u16* teamSpecies, u16 trainerId, u8 currIndex)
{
	u16 speciesCount = GetTrainerMaxSpeciesCount(gTrainers[trainerId].trainerClass);
	u16 randomSpeciesIndex;
	u16 consideredSpeciesIndex1, consideredSpeciesIndex2;
	u16 consideredSpecies1, consideredSpecies2;
	u8 iterations = 0;

	while (TRUE)
	{
		randomSpeciesIndex = Random32() % speciesCount;
		for(u8 i = 0; i < 6; ++i)
		{
			consideredSpeciesIndex1 = MathMin(randomSpeciesIndex + i, speciesCount - 1);
			consideredSpeciesIndex2 = MathMin(randomSpeciesIndex - i, randomSpeciesIndex); //because  may underflow

			consideredSpecies1 = GetSpeciesFromNewSpeciesIndex(consideredSpeciesIndex1);
			consideredSpecies2 = GetSpeciesFromNewSpeciesIndex(consideredSpeciesIndex2);

			if (CheckSpeciesViabilityInTrainerParty(consideredSpecies1, teamSpecies, trainerId, currIndex))
				return consideredSpecies1;

			if (CheckSpeciesViabilityInTrainerParty(consideredSpecies2, teamSpecies, trainerId, currIndex))
				return consideredSpecies2;
		}
		iterations++;
	}

	return SPECIES_DITTO;
}


u8 DeteminePartySize(u8 trainerClass)
{
	u8 capIndex = DetermineLevelCapIndex();
	u8 sizeIndex = FlagGet(FLAG_CHALLENGE_MODE) + (IsBossTrainerClass(trainerClass) ? 2 : 0);
	return TrainerPartySizes[capIndex][sizeIndex];
}
