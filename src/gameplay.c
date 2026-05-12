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



