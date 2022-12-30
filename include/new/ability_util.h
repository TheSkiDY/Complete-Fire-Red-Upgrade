#pragma once

#include "../global.h"
#include "../pokemon.h"

/**
 * \file anility_util.h
 * \brief Contains utility functions pertaining to Abilities.
 */

//Exported Functions
const u8* GetAbilityNameOverride(const u8 ability, const u16 species);
const u8* GetAbilityName(const u8 ability, const u16 species);
void CopyAbilityName(u8* dst, const u8 ability, const u16 species);
u16 GetProperAbilityPopUpSpecies(u8 bank);
void SetProperAbilityPopUpSpecies(u8 bank);
void SetTookAbilityFrom(u8 taker, u8 takenFrom);
void SwapTookAbilityFrom(u8 bank1, u8 bank2);
void ResetTookAbilityFrom(u8 bank);
bool8 IsTargetAbilityIgnored(u8 defAbility, u8 atkAbility, u16 move, u16 defSpecies);
bool8 IsTargetAbilityIgnoredNoMove(u8 defAbility, u8 atkAbility, u16 defSpecies);

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
bool8 IsUnnerveAbility(u8 ability);
bool8 UnnerveOnOpposingField(u8 bank);
bool8 AbilityIncreasesWildItemChance(u8 ability);
bool8 AbilityBlocksIntimidate(u8 ability);
bool8 AbilityPreventsLoweringAtk(u8 ability, u16 species);
bool8 AbilityPreventsLoweringSpeed(u8 ability, u16 species);
bool8 AbilityPreventsLoweringStat(u8 ability, u8 statId, u16 species);
bool8 AbilityRaisesOneStatWhenSomeStatIsLowered(u8 ability);
bool8 IsAffectedBySturdy(u8 defAbility, u8 bankDef);
bool8 IsAffectedByDisguse(u8 defAbility, u16 defSpecies, u8 moveSplit);
bool8 IsAffectedByBadDreams(u8 bank);
bool8 IsTrappedByAbility(u8 bankDef, u8 trapAbility);
bool8 BankHasEvaporate(u8 bank);
bool8 BankOnFieldHasEvaporate(void);
bool8 IsWhiteSmokeAbility(u8 ability, u16 species);
bool8 IsVitalSpiritAbility(u8 ability, u16 species);

bool8 SpeciesHasMagician(u16 species);
bool8 SpeciesHasTempestuousSea(u16 species);
bool8 SpeciesHasShadowBoost(u16 species);

//Merging most form change abilities into one
bool8 SpeciesHasStanceChange(u16 species);
bool8 SpeciesHasShieldsDown(u16 species);
bool8 SpeciesHasDisguise(u16 species);
bool8 SpeciesHasIceFace(u16 species);
bool8 SpeciesHasHungerSwitch(u16 species);
bool8 SpeciesHasZenMode(u16 species);
bool8 SpeciesHasGulpMissile(u16 species);
bool8 SpeciesHasRockyShelter(u16 species);
bool8 SpeciesHasSchooling(u16 species);
bool8 SpeciesHasBattleBond(u16 species);
bool8 SpeciesHasPowerConstruct(u16 species);
const u8* GetAbilityNameOverrideForFormChange(const u8 ability, const u16 species);
const u8* GetAbilityDescriptionOverrideForFormChange(const u8 ability, const u16 species);

bool8 IsFormChangeAbilityIgnoredByMoldBreaker(u8 ability, u16 species);
bool8 IsAbilityIgnoredByMoldBreaker(u8 ability, u16 species);
bool8 IsFormChangeAbilityRolePlayBanned(u8 ability, u16 species);
bool8 IsAbilityRolePlayBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityRolePlayAttackerBanned(u8 ability, u16 species);
bool8 IsAbilityRolePlayAttackerBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilitySkillSwapBanned(u8 ability, u16 species);
bool8 IsAbilitySkillSwapBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityWorrySeedBanned(u8 ability, u16 species);
bool8 IsAbilityWorrySeedBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityGastroAcidBanned(u8 ability, u16 species);
bool8 IsAbilityGastroAcidBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityEntrainmentAttackerBanned(u8 ability, u16 species);
bool8 IsAbilityEntrainmentAttackerBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityEntrainmentTargetBanned(u8 ability, u16 species);
bool8 IsAbilityEntrainmentTargetBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilitySimpleBeamBanned(u8 ability, u16 species);
bool8 IsAbilitySimpleBeamBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityReceiverBanned(u8 ability, u16 species);
bool8 IsAbilityReceiverBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityTraceBanned(u8 ability, u16 species);
bool8 IsAbilityTraceBanned(u8 ability, u16 species);
bool8 IsFormChangeAbilityNeutralizingGasBanned(u8 ability, u16 species);
bool8 IsAbilityNeutralizingGasBanned(u8 ability, u16 species);

u8 GetTypeOfBlazeLikeAbilityFromSpecies(u16 species);
const u8* GetBlazeLikeNameFromSpecies(u16 species);
const u8* GetBlazeLikeDescriptionFromSpecies(u16 species);
u8 GetAuraTypeFromSpecies(u16 species);
const u8* GetAuraNameFromSpecies(u16 species);
const u8* GetAuraDescriptionFromSpecies(u16 species);
u16 GetCurrentAuraSpecies(u8 bankAtk, u8 bankDef);
u8 GetAteTypeFromSpecies(u16 species);
const u8* GetAteNameFromSpecies(u16 species);
const u8* GetAteDescriptionFromSpecies(u16 species);
u8 GetSurgeTerrainFromSpecies(u16 species);
const u8* GetSurgeNameFromSpecies(u16 species);
const u8* GetSurgeDescriptionFromSpecies(u16 species);

bool8 SpeciesHasModulator(u16 species);
bool8 SpeciesHasWizardry(u16 species);
bool8 SpeciesHasMiraculous(u16 species);
bool8 SpeciesHasWormhole(u16 species);
bool8 SpeciesHasPlasmaBurst(u16 species);

bool8 SpeciesHasSharpness(u16 species);
bool8 SpeciesHasAngerShell(u16 species);

bool8 SpeciesHasBeadsOfRuin(u16 species);
bool8 SpeciesHasSwordOfRuin(u16 species);
bool8 SpeciesHasTabletsOfRuin(u16 species);
bool8 SpeciesHasVesselOfRuin(u16 species);
bool8 BankHasBeadsOfRuin(u8 bank);
bool8 BankHasSwordOfRuin(u8 bank);
bool8 BankHasTabletsOfRuin(u8 bank);
bool8 BankHasVesselOfRuin(u8 bank);
const u8* GetTreasureOfRuinAbilityName(u16 species);
const u8* GetTreasureOfRuinAbilityDescription(u16 species);
bool8 IsBeadsOfRuinOnTheField();
bool8 IsSwordOfRuinOnTheField();
bool8 IsTabletsOfRuinOnTheField();
bool8 IsVesselOfRuinOnTheField();
bool8 SpeciesHasGuardDog(u16 species);
bool8 BankHasGuardDog(u8 bank);
bool8 SpeciesHasHadronEngine(u16 species);
bool8 BankHasHadronEngine(u8 bank);
bool8 SpeciesHasOrichalcumPulse(u16 species);
bool8 BankHasOrichalcumPulse(u8 bank);
u8 GetMostProficientStat(u8 bank);
u8 GetTypeBoostTypeFromSpecies(u16 species);
const u8* GetTypeBoostNameFromSpecies(u16 species);
const u8* GetTypeBoostDescriptionFromSpecies(u16 species);
bool8 BankHasTransistor(u8 bank);
bool8 BankHasDragonsMaw(u8 bank);
bool8 SpeciesHasSeedSower(u16 species);
bool8 SpeciesHasThermalExchange(u16 species);
bool8 BankHasThermalExchange(u8 bank);
bool8 SpeciesHasWellBakedBody(u16 species);
bool8 BankHasWellBakedBody(u8 bank);
bool8 SpeciesHasWindPower(u16 species);
bool8 BankHasWindPower(u8 bank);
bool8 SpeciesHasZeroToHero(u16 species);

bool8 SpeciesHasSurfersEntry(u16 species);
bool8 BankHasSurfersEntry(u8 bank);