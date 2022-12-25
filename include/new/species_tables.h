#pragma once

#include "../global.h"

/**
 * \file move_tables.h
 * \brief Contains declarations for many lists of species.
 */

struct SpecialSpeciesFlags
{
	bool8 telekinesisBan : 1;
	bool8 battleTowerStandardBan : 1;
	bool8 gsCupLegendaries : 1;
	bool8 smogonOUBan : 1;
	bool8 smogonNationalDexOUBan : 1;
	bool8 smogonOUDoublesBan : 1;
	bool8 smogonLittleCup : 1;
	bool8 middleCup : 1;
	bool8 smogonMonotypeBan : 1;
	bool8 smogonCamomonsBan : 1;
	bool8 smogonAverageMonsBan : 1;
	bool8 smogon350CupBan : 1;
	bool8 smogonScalemonsBan : 1;
	bool8 smogonBenjaminButterfreeBan : 1;
	bool8 smogonUUBan : 1;
	bool8 smogonRUBan : 1;
	bool8 smogonNUBan : 1;
	bool8 goodForUbers : 1;
	bool8 badForUbers : 1;
	bool8 setPerfectXIVs : 1;
	bool8 smartWild : 1;

	//randomizer:
	bool8 randomizerFullBan : 1;
	bool8 randomizerGettableBan : 1;

	bool8 isFakemon : 1;

	//for new abilities:
	bool8 hasVitalSpirit : 1;
	bool8 hasWhiteSmoke : 1;
	bool8 hasTeravolt : 1;
	bool8 hasTurboblaze : 1;
	bool8 hasMagician : 1;
	bool8 hasTempestuousSea : 1;
	bool8 hasShadowBoost : 1;
	
	bool8 hasStanceChange : 1;
	bool8 hasShieldsDown : 1;
	bool8 hasDisguise : 1;
	bool8 hasIceFace : 1;
	bool8 hasHungerSwitch : 1;
	bool8 hasZenMode : 1;
	bool8 hasGulpMissile : 1;
	bool8 hasRockyShelter : 1;
	bool8 hasSchooling : 1;
	bool8 hasBattleBond : 1;
	bool8 hasPowerConstruct : 1;

	bool8 hasVirtue : 1; 
	bool8 hasRampage : 1; 
	bool8 hasCyclone : 1; 
	bool8 hasBiohazard : 1; 
	bool8 hasUpheaval : 1; 
	bool8 hasBedrock : 1; 
	bool8 hasSwarm : 1; 
	bool8 hasHaunted : 1; 
	bool8 hasTemper : 1; 
	bool8 hasBlaze : 1; 
	bool8 hasTorrent : 1; 
	bool8 hasOvergrow : 1; 
	bool8 hasOvercharge : 1; 
	bool8 hasBrainstorm : 1; 
	bool8 hasSnowfall : 1; 
	bool8 hasMythicRage : 1; 
	bool8 hasWrath : 1; 
	bool8 hasEnchant : 1; 

	bool8 hasNormalAura : 1;
	bool8 hasFightingAura : 1;
	bool8 hasFlyingAura : 1;
	bool8 hasPoisonAura : 1;
	bool8 hasGroundAura : 1;
	bool8 hasRockAura : 1;
	bool8 hasBugAura : 1;
	bool8 hasGhostAura : 1;
	bool8 hasSteelAura : 1;
	bool8 hasFireAura : 1;
	bool8 hasWaterAura : 1;
	bool8 hasGrassAura : 1;
	bool8 hasElectricAura : 1;
	bool8 hasPsychicAura : 1;
	bool8 hasIceAura : 1;
	bool8 hasDragonAura : 1;
	bool8 hasDarkAura : 1;
	bool8 hasFairyAura : 1;
	
	bool8 hasWarfare : 1;
	bool8 hasAerilate : 1;
	bool8 hasToxinate : 1;
	bool8 hasEarthbound : 1;
	bool8 hasCragitate : 1;
	bool8 hasInfectate : 1;
	bool8 hasChanneling : 1;
	bool8 hasFortified : 1;
	bool8 hasEmpyreal : 1;
	bool8 hasHydrate : 1;
	bool8 hasNaturalize : 1;
	bool8 hasGalvanize : 1;
	bool8 hasCognitive : 1;
	bool8 hasRefrigerate : 1;
	bool8 hasWyvernate : 1;
	bool8 hasAntagonize : 1;
	bool8 hasPixilate : 1;

	bool8 hasElectricSurge : 1;
	bool8 hasGrassySurge : 1;
	bool8 hasMistySurge : 1;
	bool8 hasPsychicSurge : 1;
	bool8 hasShadowySurge : 1;
	bool8 hasDracoSurge : 1;

	bool8 hasModulator : 1;
	bool8 hasWizardry : 1;
	bool8 hasMiraculous : 1;
	bool8 hasWormhole : 1;
	bool8 hasPlasmaBurst : 1;

	bool8 hasDragonsMaw : 1;
	bool8 hasTransistor : 1;
	bool8 hasSteelworker : 1;
	bool8 hasRockyPayload : 1;

	bool8 hasSharpness : 1;
	bool8 hasAngerShell : 1;
	bool8 hasBeadsOfRuin : 1;
	bool8 hasSwordOfRuin : 1;
	bool8 hasTabletsOfRuin : 1;
	bool8 hasVesselOfRuin : 1;
	bool8 hasGuardDog : 1;
	bool8 hasHadronEngine : 1;
	bool8 hasOrichalcumPulse : 1;
	bool8 hasSeedSower : 1;
	bool8 hasThermalExchange : 1;
	bool8 hasWellBakedBody : 1;
	bool8 hasWindPower : 1;
	bool8 hasZeroToHero : 1;
};

extern const struct SpecialSpeciesFlags gSpecialSpeciesFlags[];
