#pragma once

#include "../global.h"
#include "../pokemon.h"

/**
 * \file anility_util.h
 * \brief Contains utility functions pertaining to Abilities.
 */

#define BRANCH_DRIZZLE 1
#define BRANCH_DROUGHT 2
#define BRANCH_SAND_STREAM 3
#define BRANCH_SNOW_WARNING 4
#define BRANCH_LIMBER 5
#define BRANCH_INSOMNIA 6
#define BRANCH_IMMUNITY 7
#define BRANCH_MAGMA_ARMOR 8
#define BRANCH_WATER_VEIL 9
#define BRANCH_VITAL_SPIRIT 10
#define BRANCH_SAND_VEIL 11
#define BRANCH_SNOW_CLOAK 12
#define BRANCH_SWIFT_SWIM 13
#define BRANCH_CHLOROPHYLL 14
#define BRANCH_SAND_RUSH 15
#define BRANCH_SLUSH_RUSH 16
#define BRANCH_STATIC 17
#define BRANCH_CUTE_CHARM 18
#define BRANCH_EFFECT_SPORE 19
#define BRANCH_POISON_POINT 20
#define BRANCH_CURSED_BODY 21
#define BRANCH_FLAME_BODY 22
#define BRANCH_VOLT_ABSORB 23
#define BRANCH_WATER_ABSORB 24
#define BRANCH_SHADOW_TAG 25
#define BRANCH_ARENA_TRAP 26
#define BRANCH_MAGNET_PULL 27
#define BRANCH_WHITE_SMOKE 28
#define BRANCH_FORECAST 29
#define BRANCH_ZEN_MODE 30
#define BRANCH_STANCE_CHANGE 31
#define BRANCH_SHIELDS_DOWN 32
#define BRANCH_SCHOOLING 33
#define BRANCH_DISGUISE 34
#define BRANCH_BATTLE_BOND 35
#define BRANCH_POWER_CONSTRUCT 36
#define BRANCH_GULP_MISSILE 37
#define BRANCH_ICE_FACE 38
#define BRANCH_HUNGER_SWITCH 39
#define BRANCH_MOXIE 40
#define BRANCH_BEAST_BOOST 41
#define BRANCH_CHILLING_NEIGH 42
#define BRANCH_GRIM_NEIGH 43
#define BRANCH_AS_ONE_CHILLING 44
#define BRANCH_AS_ONE_GRIM 45
#define BRANCH_PRIMORDIAL_SEA 46
#define BRANCH_DESOLATE_LAND 47
#define BRANCH_DELTA_STREAM 48
#define BRANCH_ELECTRIC_SURGE 49
#define BRANCH_PSYCHIC_SURGE 50
#define BRANCH_MISTY_SURGE 51
#define BRANCH_GRASSY_SURGE 52
#define BRANCH_ANGER_SHELL 53
#define BRANCH_TABLETS_OF_RUIN 54
#define BRANCH_SWORD_OF_RUIN 55
#define BRANCH_VESSEL_OF_RUIN 56
#define BRANCH_BEADS_OF_RUIN 57
#define BRANCH_EARTH_EATER 58
#define BRANCH_GUARD_DOG 59
#define BRANCH_HADRON_ENGINE 60
#define BRANCH_ORICHALCUM_PULSE 61
#define BRANCH_MINDS_EYE 62
#define BRANCH_THERMAL_EXCHANGE 63
#define BRANCH_TOXIC_CHAIN 64
#define BRANCH_WELL_BAKED_BODY 65
#define BRANCH_ZERO_TO_HERO 66


//Exported Functions
const u8* GetAbilityNameOverride(const u8 ability, const u16 species);
const u8* GetAbilityName(const u8 ability, const u16 species);
void CopyAbilityName(u8* dst, const u8 ability, const u16 species);
u16 GetProperAbilityPopUpSpecies(u8 bank);
void SetProperAbilityPopUpSpecies(u8 bank);
void SetTookAbilityFrom(u8 taker, u8 takenFrom);
void SwapTookAbilityFrom(u8 bank1, u8 bank2);
void ResetTookAbilityFrom(u8 bank);
bool8 IsTargetAbilityIgnored(u8 defAbility, u8 atkAbility, u16 move);
bool8 IsTargetAbilityIgnoredNoMove(u8 defAbility, u8 atkAbility);

bool8 SpeciesHasTurboblaze(u16 species);
bool8 SpeciesHasTeravolt(u16 species);
bool8 SpeciesHasDrillBeak(u16 species);
bool8 SpeciesHasGrassDash(u16 species);
bool8 SpeciesHasEvaporate(u16 species);
bool8 SpeciesHasSlipperyTail(u16 species);
bool8 IsClearBodyAbility(u8 ability);
bool8 IsMoldBreakerAbility(u8 ability);
bool8 IsMoxieAbility(u8 ability);
bool8 IsChoiceAbility(u8 ability);
bool8 IsHPAbsorptionAbility(u8 ability);
bool8 IsElectricAbsorptionAblity(u8 ability);
bool8 IsPlusMinusAbility(u8 ability);
bool8 IsMultiscaleAbility(u8 ability);
bool8 IsPriorityBlockingAbility(u8 ability);
bool8 IsUnnerveAbility(u8 ability, u16 species);
bool8 UnnerveOnOpposingField(u8 bank);
bool8 AbilityIncreasesWildItemChance(u8 ability);
bool8 AbilityBlocksIntimidate(u8 ability);
bool8 AbilityPreventsLoweringAtk(u8 ability);
bool8 AbilityPreventsLoweringStat(u8 ability, u8 statId);
bool8 AbilityRaisesOneStatWhenSomeStatIsLowered(u8 ability);
bool8 IsAffectedBySturdy(u8 defAbility, u8 bankDef);
bool8 IsAffectedByDisguse(u8 defAbility, u16 defSpecies, u8 moveSplit);
bool8 IsAffectedByBadDreams(u8 bank);
bool8 IsTrappedByAbility(u8 bankDef, u16 branch);
bool8 BankHasEvaporate(u8 bank);
bool8 BankOnFieldHasEvaporate(void);
bool8 IsVitalSpiritAbility(u8 ability, u16 species);

bool8 BankHasBranchAbility(u8 bank, u16 branch);
bool8 SpeciesHasBranchAbility(u16 species, u8 ability, u16 branch);
bool8 BankHasBlazeVariant(u8 bank, u8 type);
u8 GetBankBlazeVariant(u8 bank);
u8 GetSpeciesBlazeVariant(u16 species, u8 ability);
u8 GetBankNormalizeVariant(u8 bank);
u8 GetSpeciesNormalizeVariant(u16 species, u8 ability);
u8 GetBankTypePowerUpVariant(u8 bank);
u8 GetSpeciesTypePowerUpVariant(u16 species, u8 ability);
u8 GetBankAuraVariant(u8 bank);
u8 GetSpeciesAuraVariant(u16 species, u8 ability);
u8 GetAuraTypeOnField(void);
bool8 IsBranchAbilityOnTheField(u8 branch);
u8 GetHighestStatForProtosynthesisQuarkDrive(u8 bank);
bool8 BankProtosynthesisQuarkDriveActive(u8 bank);
bool8 MonProtosynthesisQuarkDriveActive(u8 side, struct Pokemon* mon);
u8 GetHighestStatForProtosynthesisQuarkDriveMon(struct Pokemon* mon);