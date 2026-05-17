#pragma once

#include "../global.h"
#include "../pokemon.h"

u16 ModifyEncounterSpecies(u16 species, u8 index, u8 level, u8 encounterType);
bool8 IsBossTrainerClass(u8 trainerClass);
u8 DeteminePartySize(u8 trainerClass);
u8 RandomizeLevelForTrainerMon(u8 trainerClass);
u16 AdjustTrainerSpecies(u16 originalSpecies, u8 level);
u16 RandomizeTrainerSpecies(u16* teamSpecies, u16 trainerId, u8 currIndex);
u16 RandomizeHeldItemForCasualTrainer(u16 species);
u16 GetRandomShardFromSpecies(u16 species);

#define CAP_BROCK 0
#define CAP_MISTY 1
#define CAP_LT_SURGE 2
#define CAP_ERIKA 3
#define CAP_KOGA 4
#define CAP_SABRINA 5
#define CAP_BLAINE 6
#define CAP_GIOVANNI 7
#define CAP_FALKNER 8
#define CAP_BUGSY 9
#define CAP_WHITNEY 10
#define CAP_MORTY 11
#define CAP_KAREN 12
#define CAP_JASMINE 13
#define CAP_PRYCE 14
#define CAP_CLAIR 15
#define CAP_LG1 16
#define CAP_LG2 17
#define CAP_LG3 18
#define CAP_ELITE_FOUR 19

#define NUM_TRAINER_CLASS_SPECIFIC_TYPES 5