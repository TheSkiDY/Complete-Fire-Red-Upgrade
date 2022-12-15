#pragma once

#include "../global.h"
#include "../pokemon.h"
#include "../gba/types.h"

u32 hash_uint(u32 x);
u16 GetSpeciesFromHashVal(u32 toHash);
u32 SetInitialHashValueForTrainerRandomizer(u16 trainerId);
void TryRandomizeForTrainers(unusedArg u16* species);
u16 InitialSpeciesRandomizer(unusedArg u16 species, u32 trainerId, u8 locationGroup, u8 locationId, u8 index, bool8 trainerBattle);
u16 BackupSpeciesRandomizer(unusedArg u16 species, u32 id, bool8 trainerBattle);
void TryRandomizeSpecies(unusedArg u16* species);
bool8 IsSpeciesBannedFromRandomizer(u16 species);
bool8 IsSpeciesBannedFromTrainerRandomizer(u16 species);
u16 GetRandomizedSpecies(u16 species);
move_t RandomizeMove(u16 move);
bool8 IsOriginalFormChangeAbilityBannedInRandomizer(u8 ability, u16 species);
bool8 IsOriginalAbilityBannedInRandomizer(u8 ability, u16 species);
bool8 IsNewFormChangeAbilityBannedInRandomizer(u8 ability, u16 species);
bool8 IsNewAbilityBannedInRandomizer(u8 ability, u16 species);

u8 TryRandomizeAbility(u8 originalAbility, unusedArg u16 species);