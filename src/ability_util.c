#include "defines.h"
#include "defines_battle.h"
#include "../include/string_util.h"
#include "../include/constants/abilities.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/species.h"

#include "../include/new/ability_tables.h"
#include "../include/new/ability_util.h"
#include "../include/new/ai_util.h"
#include "../include/new/battle_util.h"
#include "../include/new/move_tables.h"
#include "../include/new/util.h"

extern const u8 gAbilityNames[][ABILITY_NAME_LENGTH + 1];
extern const u8* gAbilityDescriptions[];
extern const u8 gText_AbilityName_AirLock[];
extern const u8 gText_AbilityName_VitalSpirit[];
extern const u8 gText_AbilityName_WhiteSmoke[];
extern const u8 gText_AbilityName_PurePower[];
extern const u8 gText_AbilityName_IronBarbs[];
extern const u8 gText_AbilityName_SolidRock[];
extern const u8 gText_AbilityName_Turboblaze[];
extern const u8 gText_AbilityName_Teravolt[];
extern const u8 gText_AbilityName_ChillingNeigh[];
extern const u8 gText_AbilityName_Libero[];
extern const u8 gText_AbilityName_TanglingHair[];
extern const u8 gText_AbilityName_WimpOut[];
extern const u8 gText_AbilityName_QueenlyMajesty[];
extern const u8 gText_AbilityName_PowerOfAlchemy[];
extern const u8 gText_AbilityName_PropellerTail[];

//Unbound Custom Abilities
extern const u8 gText_AbilityName_NineLives[];
extern const u8 gText_AbilityName_FocusBelt[];
extern const u8 gText_AbilityName_Evaporate[];
extern const u8 gText_AbilityName_FieryNeigh[];
extern const u8 gText_AbilityName_ShockingNeigh[];
extern const u8 gText_AbilityName_Pride[];
extern const u8 gText_AbilityName_Multieye[];
extern const u8 gText_AbilityName_Subterfuge[];
extern const u8 gText_AbilityName_TanglingWool[];
extern const u8 gText_AbilityName_BrainBond[];
extern const u8 gText_AbilityName_GrassDash[];
extern const u8 gText_AbilityName_SlipperyTail[];
extern const u8 gText_AbilityName_DrillBeak[];
extern const u8 gText_AbilityName_CottonCloud[];
extern const u8 gText_AbilityName_Bellow[];
extern const u8 gText_AbilityName_SoundWaves[];
extern const u8 gText_AbilityName_IcySkin[];
extern const u8 gText_AbilityName_DustyScales[];
extern const u8 gText_AbilityName_CrabbyTactics[];
extern const u8 gText_AbilityName_HoneyArmor[];
extern const u8 gText_AbilityName_FaceShield[];
extern const u8 gText_AbilityName_RoyalRoar[];

extern const u8 gText_AbilityDescription_Evaporate[];
extern const u8 gText_AbilityDescription_GrassDash[];
extern const u8 gText_AbilityDescription_SlipperyTail[];
extern const u8 gText_AbilityDescription_DrillBeak[];

extern const u8 NAME_FULL_METAL_BODY[];
extern const u8 NAME_PURE_POWER[];
extern const u8 NAME_SHELL_ARMOR[];
extern const u8 NAME_AIR_LOCK[];
extern const u8 NAME_IRON_BARBS[];
extern const u8 NAME_CACOPHONY[];
extern const u8 NAME_TURBOBLAZE[];
extern const u8 NAME_TERAVOLT[];
extern const u8 NAME_SOLID_ROCK[];
extern const u8 NAME_PRISM_ARMOR[];
extern const u8 NAME_SHADOW_SHIELD[];
extern const u8 NAME_TANGLING_HAIR[];
extern const u8 NAME_LIBERO[];
extern const u8 NAME_EMERGENCY_EXIT[];
extern const u8 NAME_QUEENLY_MAJESTY[];
extern const u8 NAME_POWER_OF_ALCHEMY[];
extern const u8 NAME_PROPELLER_TAIL[];
extern const u8 NAME_LINGERING_AROMA[];
extern const u8 NAME_ARMOR_TAIL[];

extern const u8 NAME_DRIZZLE[];
extern const u8 DESC_DRIZZLE[];
extern const u8 NAME_DROUGHT[];
extern const u8 DESC_DROUGHT[];
extern const u8 NAME_SAND_STREAM[];
extern const u8 DESC_SAND_STREAM[];
extern const u8 NAME_SNOW_WARNING[];
extern const u8 DESC_SNOW_WARNING[];
extern const u8 NAME_LIMBER[];
extern const u8 DESC_LIMBER[];
extern const u8 NAME_INSOMNIA[];
extern const u8 DESC_INSOMNIA[];
extern const u8 NAME_IMMUNITY[];
extern const u8 DESC_IMMUNITY[];
extern const u8 NAME_MAGMA_ARMOR[];
extern const u8 DESC_MAGMA_ARMOR[];
extern const u8 NAME_WATER_VEIL[];
extern const u8 DESC_WATER_VEIL[];
extern const u8 NAME_VITAL_SPIRIT[];
extern const u8 DESC_VITAL_SPIRIT[];
extern const u8 NAME_SAND_VEIL[];
extern const u8 DESC_SAND_VEIL[];
extern const u8 NAME_SNOW_CLOAK[];
extern const u8 DESC_SNOW_CLOAK[];
extern const u8 NAME_SWIFT_SWIM[];
extern const u8 DESC_SWIFT_SWIM[];
extern const u8 NAME_CHLOROPHYLL[];
extern const u8 DESC_CHLOROPHYLL[];
extern const u8 NAME_SAND_RUSH[];
extern const u8 DESC_SAND_RUSH[];
extern const u8 NAME_SLUSH_RUSH[];
extern const u8 DESC_SLUSH_RUSH[];
extern const u8 NAME_STATIC[];
extern const u8 DESC_STATIC[];
extern const u8 NAME_CUTE_CHARM[];
extern const u8 DESC_CUTE_CHARM[];
extern const u8 NAME_EFFECT_SPORE[];
extern const u8 DESC_EFFECT_SPORE[];
extern const u8 NAME_POISON_POINT[];
extern const u8 DESC_POISON_POINT[];
extern const u8 NAME_CURSED_BODY[];
extern const u8 DESC_CURSED_BODY[];
extern const u8 NAME_FLAME_BODY[];
extern const u8 DESC_FLAME_BODY[];
extern const u8 NAME_VOLT_ABSORB[];
extern const u8 DESC_VOLT_ABSORB[];
extern const u8 NAME_WATER_ABSORB[];
extern const u8 DESC_WATER_ABSORB[];
extern const u8 NAME_SHADOW_TAG[];
extern const u8 DESC_SHADOW_TAG[];
extern const u8 NAME_ARENA_TRAP[];
extern const u8 DESC_ARENA_TRAP[];
extern const u8 NAME_MAGNET_PULL[];
extern const u8 DESC_MAGNET_PULL[];
extern const u8 NAME_WHITE_SMOKE[];
extern const u8 DESC_WHITE_SMOKE[];
extern const u8 NAME_FORECAST[];
extern const u8 DESC_FORECAST[];
extern const u8 NAME_ZEN_MODE[];
extern const u8 DESC_ZEN_MODE[];
extern const u8 NAME_STANCE_CHANGE[];
extern const u8 DESC_STANCE_CHANGE[];
extern const u8 NAME_SHIELDS_DOWN[];
extern const u8 DESC_SHIELDS_DOWN[];
extern const u8 NAME_SCHOOLING[];
extern const u8 DESC_SCHOOLING[];
extern const u8 NAME_DISGUISE[];
extern const u8 DESC_DISGUISE[];
extern const u8 NAME_BATTLE_BOND[];
extern const u8 DESC_BATTLE_BOND[];
extern const u8 NAME_POWER_CONSTRUCT[];
extern const u8 DESC_POWER_CONSTRUCT[];
extern const u8 NAME_GULP_MISSILE[];
extern const u8 DESC_GULP_MISSILE[];
extern const u8 NAME_ICE_FACE[];
extern const u8 DESC_ICE_FACE[];
extern const u8 NAME_HUNGER_SWITCH[];
extern const u8 DESC_HUNGER_SWITCH[];
extern const u8 NAME_BLAZE[];
extern const u8 DESC_BLAZE[];
extern const u8 NAME_TORRENT[];
extern const u8 DESC_TORRENT[];
extern const u8 NAME_OVERGROW[];
extern const u8 DESC_OVERGROW[];
extern const u8 NAME_SWARM[];
extern const u8 DESC_SWARM[];
extern const u8 NAME_NORMALIZE[];
extern const u8 DESC_NORMALIZE[];
extern const u8 NAME_AERILATE[];
extern const u8 DESC_AERILATE[];
extern const u8 NAME_PIXILATE[];
extern const u8 DESC_PIXILATE[];
extern const u8 NAME_REFRIGERATE[];
extern const u8 DESC_REFRIGERATE[];
extern const u8 NAME_GALVANIZE[];
extern const u8 DESC_GALVANIZE[];
extern const u8 NAME_MOXIE[];
extern const u8 DESC_MOXIE[];
extern const u8 NAME_BEAST_BOOST[];
extern const u8 DESC_BEAST_BOOST[];
extern const u8 NAME_CHILLING_NEIGH[];
extern const u8 DESC_CHILLING_NEIGH[];
extern const u8 NAME_GRIM_NEIGH[];
extern const u8 DESC_GRIM_NEIGH[];
extern const u8 NAME_AS_ONE_CHILLING[];
extern const u8 DESC_AS_ONE_CHILLING[];
extern const u8 NAME_AS_ONE_GRIM[];
extern const u8 DESC_AS_ONE_GRIM[];
extern const u8 NAME_STEELWORKER[];
extern const u8 DESC_STEELWORKER[];
extern const u8 NAME_TRANSISTOR[];
extern const u8 DESC_TRANSISTOR[];
extern const u8 NAME_DRAGONS_MAW[];
extern const u8 DESC_DRAGONS_MAW[];
extern const u8 NAME_NORMAL_AURA[];
extern const u8 DESC_NORMAL_AURA[];
extern const u8 NAME_FIGHTING_AURA[];
extern const u8 DESC_FIGHTING_AURA[];
extern const u8 NAME_FLYING_AURA[];
extern const u8 DESC_FLYING_AURA[];
extern const u8 NAME_POISON_AURA[];
extern const u8 DESC_POISON_AURA[];
extern const u8 NAME_GROUND_AURA[];
extern const u8 DESC_GROUND_AURA[];
extern const u8 NAME_ROCK_AURA[];
extern const u8 DESC_ROCK_AURA[];
extern const u8 NAME_BUG_AURA[];
extern const u8 DESC_BUG_AURA[];
extern const u8 NAME_GHOST_AURA[];
extern const u8 DESC_GHOST_AURA[];
extern const u8 NAME_STEEL_AURA[];
extern const u8 DESC_STEEL_AURA[];
extern const u8 NAME_FIRE_AURA[];
extern const u8 DESC_FIRE_AURA[];
extern const u8 NAME_WATER_AURA[];
extern const u8 DESC_WATER_AURA[];
extern const u8 NAME_GRASS_AURA[];
extern const u8 DESC_GRASS_AURA[];
extern const u8 NAME_ELECTRIC_AURA[];
extern const u8 DESC_ELECTRIC_AURA[];
extern const u8 NAME_PSYCHIC_AURA[];
extern const u8 DESC_PSYCHIC_AURA[];
extern const u8 NAME_ICE_AURA[];
extern const u8 DESC_ICE_AURA[];
extern const u8 NAME_DRAGON_AURA[];
extern const u8 DESC_DRAGON_AURA[];
extern const u8 NAME_DARK_AURA[];
extern const u8 DESC_DARK_AURA[];
extern const u8 NAME_FAIRY_AURA[];
extern const u8 DESC_FAIRY_AURA[];
extern const u8 NAME_PRIMORDIAL_SEA[];
extern const u8 DESC_PRIMORDIAL_SEA[];
extern const u8 NAME_DESOLATE_LAND[];
extern const u8 DESC_DESOLATE_LAND[];
extern const u8 NAME_DELTA_STREAM[];
extern const u8 DESC_DELTA_STREAM[];
extern const u8 NAME_ELECTRIC_SURGE[];
extern const u8 DESC_ELECTRIC_SURGE[];
extern const u8 NAME_PSYCHIC_SURGE[];
extern const u8 DESC_PSYCHIC_SURGE[];
extern const u8 NAME_MISTY_SURGE[];
extern const u8 DESC_MISTY_SURGE[];
extern const u8 NAME_GRASSY_SURGE[];
extern const u8 DESC_GRASSY_SURGE[];
extern const u8 NAME_ANGER_SHELL[];
extern const u8 DESC_ANGER_SHELL[];
extern const u8 NAME_TABLETS_OF_RUIN[];
extern const u8 DESC_TABLETS_OF_RUIN[];
extern const u8 NAME_SWORD_OF_RUIN[];
extern const u8 DESC_SWORD_OF_RUIN[];
extern const u8 NAME_VESSEL_OF_RUIN[];
extern const u8 DESC_VESSEL_OF_RUIN[];
extern const u8 NAME_BEADS_OF_RUIN[];
extern const u8 DESC_BEADS_OF_RUIN[];
extern const u8 NAME_EARTH_EATER[];
extern const u8 DESC_EARTH_EATER[];
extern const u8 NAME_GUARD_DOG[];
extern const u8 DESC_GUARD_DOG[];
extern const u8 NAME_HADRON_ENGINE[];
extern const u8 DESC_HADRON_ENGINE[];
extern const u8 NAME_ORICHALCUM_PULSE[];
extern const u8 DESC_ORICHALCUM_PULSE[];
extern const u8 NAME_MINDS_EYE[];
extern const u8 DESC_MINDS_EYE[];
extern const u8 NAME_ROCKY_PAYLOAD[];
extern const u8 DESC_ROCKY_PAYLOAD[];
extern const u8 NAME_THERMAL_EXCHANGE[];
extern const u8 DESC_THERMAL_EXCHANGE[];
extern const u8 NAME_TOXIC_CHAIN[];
extern const u8 DESC_TOXIC_CHAIN[];
extern const u8 NAME_WELL_BAKED_BODY[];
extern const u8 DESC_WELL_BAKED_BODY[];
extern const u8 NAME_ZERO_TO_HERO[];
extern const u8 DESC_ZERO_TO_HERO[];


extern const u8 gText_NormalAuraActivate[];
extern const u8 gText_FightingAuraActivate[];
extern const u8 gText_FlyingAuraActivate[];
extern const u8 gText_PoisonAuraActivate[];
extern const u8 gText_GroundAuraActivate[];
extern const u8 gText_RockAuraActivate[];
extern const u8 gText_BugAuraActivate[];
extern const u8 gText_GhostAuraActivate[];
extern const u8 gText_SteelAuraActivate[];
extern const u8 gText_FireAuraActivate[];
extern const u8 gText_WaterAuraActivate[];
extern const u8 gText_GrassAuraActivate[];
extern const u8 gText_ElectricAuraActivate[];
extern const u8 gText_PsychicAuraActivate[];
extern const u8 gText_IceAuraActivate[];
extern const u8 gText_DragonAuraActivate[];
extern const u8 gText_DarkAuraActivate[];
extern const u8 gText_FairyAuraActivate[];


struct CloneAbilityName
{
	u16 species;
	u8 originalAbility;
	const u8* replaceAbilityName;
};

static struct CloneAbilityName sCloneNames[] = 
{
	// Clear Body -> Full Metal Body
	{
		.species = SPECIES_SOLGALEO,
		.originalAbility = ABILITY_CLEARBODY,
		.replaceAbilityName = NAME_FULL_METAL_BODY,
	},

	// Huge Power -> Pure Power
	{
		.species = SPECIES_MEDITITE,
		.originalAbility = ABILITY_HUGEPOWER,
		.replaceAbilityName = NAME_PURE_POWER,
	},
	{
		.species = SPECIES_MEDICHAM,
		.originalAbility = ABILITY_HUGEPOWER,
		.replaceAbilityName = NAME_PURE_POWER,
	},
	{
		.species = SPECIES_MEDICHAM_MEGA,
		.originalAbility = ABILITY_HUGEPOWER,
		.replaceAbilityName = NAME_PURE_POWER,
	},

	// Battle Armor -> Shell Armor
	{
		.species = SPECIES_SLOWBRO_MEGA,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_SHELLDER,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CLOYSTER,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_KRABBY,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_KINGLER,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_KINGLER_GIGA,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_LAPRAS,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_LAPRAS_GIGA,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_OMANYTE,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_OMASTAR,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_TORKOAL,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CORPHISH,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CRAWDAUNT,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CLAMPERL,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_TURTWIG,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_GROTLE,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_TORTERRA,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_OSHAWOTT,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_DEWOTT,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_SAMUROTT,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_SAMUROTT_H,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_DWEBBLE,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CRUSTLE,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_ESCAVALIER,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_SHELMET,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_SLIGGOO_H,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_GOODRA_H,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_TURTONATOR,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_CHEWTLE,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_DREDNAW,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},
	{
		.species = SPECIES_KLAWF,
		.originalAbility = ABILITY_BATTLEARMOR,
		.replaceAbilityName = NAME_SHELL_ARMOR,
	},

	// Cloud Nine -> Air Lock
	{
		.species = SPECIES_RAYQUAZA,
		.originalAbility = ABILITY_CLOUDNINE,
		.replaceAbilityName = NAME_AIR_LOCK,
	},

	// Rough Skin -> Iron Barbs
	{
		.species = SPECIES_FERROSEED,
		.originalAbility = ABILITY_ROUGHSKIN,
		.replaceAbilityName = NAME_IRON_BARBS,
	},
	{
		.species = SPECIES_FERROTHORN,
		.originalAbility = ABILITY_ROUGHSKIN,
		.replaceAbilityName = NAME_IRON_BARBS,
	},
	{
		.species = SPECIES_TOGEDEMARU,
		.originalAbility = ABILITY_ROUGHSKIN,
		.replaceAbilityName = NAME_IRON_BARBS,
	},

	// Soundproof -> Cacophony
	{
		.species = SPECIES_WHISMUR,
		.originalAbility = ABILITY_SOUNDPROOF,
		.replaceAbilityName = NAME_CACOPHONY,
	},
	{
		.species = SPECIES_LOUDRED,
		.originalAbility = ABILITY_SOUNDPROOF,
		.replaceAbilityName = NAME_CACOPHONY,
	},
	{
		.species = SPECIES_EXPLOUD,
		.originalAbility = ABILITY_SOUNDPROOF,
		.replaceAbilityName = NAME_CACOPHONY,
	},

	// Mold Breaker -> Turboblaze
	{
		.species = SPECIES_RESHIRAM,
		.originalAbility = ABILITY_MOLDBREAKER,
		.replaceAbilityName = NAME_TURBOBLAZE,
	},
	{
		.species = SPECIES_KYUREM_WHITE,
		.originalAbility = ABILITY_MOLDBREAKER,
		.replaceAbilityName = NAME_TURBOBLAZE,
	},

	// Mold Breaker -> Teravolt
	{
		.species = SPECIES_ZEKROM,
		.originalAbility = ABILITY_MOLDBREAKER,
		.replaceAbilityName = NAME_TERAVOLT,
	},
	{
		.species = SPECIES_KYUREM_BLACK,
		.originalAbility = ABILITY_MOLDBREAKER,
		.replaceAbilityName = NAME_TERAVOLT,
	},

	// Filter -> Solid Rock
	{
		.species = SPECIES_CAMERUPT,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_SOLID_ROCK,
	},
	{
		.species = SPECIES_RHYPERIOR,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_SOLID_ROCK,
	},
	{
		.species = SPECIES_TIRTOUGA,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_SOLID_ROCK,
	},
	{
		.species = SPECIES_CARRACOSTA,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_SOLID_ROCK,
	},

	// Filter -> Prism Armor
	{
		.species = SPECIES_NECROZMA,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_PRISM_ARMOR,
	},
	{
		.species = SPECIES_NECROZMA_DUSK_MANE,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_PRISM_ARMOR,
	},
	{
		.species = SPECIES_NECROZMA_DAWN_WINGS,
		.originalAbility = ABILITY_FILTER,
		.replaceAbilityName = NAME_PRISM_ARMOR,
	},

	// Multiscale -> Shadow Shield
	{
		.species = SPECIES_LUNALA,
		.originalAbility = ABILITY_MULTISCALE,
		.replaceAbilityName = NAME_SHADOW_SHIELD,
	},

	// Gooey -> Tangling Hair
	{
		.species = SPECIES_DIGLETT_A,
		.originalAbility = ABILITY_GOOEY,
		.replaceAbilityName = NAME_TANGLING_HAIR,
	},
	{
		.species = SPECIES_DUGTRIO_A,
		.originalAbility = ABILITY_GOOEY,
		.replaceAbilityName = NAME_TANGLING_HAIR,
	},

	// Protean - Libero
	{
		.species = SPECIES_SCORBUNNY,
		.originalAbility = ABILITY_PROTEAN,
		.replaceAbilityName = NAME_LIBERO,
	},
	{
		.species = SPECIES_RABOOT,
		.originalAbility = ABILITY_PROTEAN,
		.replaceAbilityName = NAME_LIBERO,
	},
	{
		.species = SPECIES_CINDERACE,
		.originalAbility = ABILITY_PROTEAN,
		.replaceAbilityName = NAME_LIBERO,
	},

	// Wimp Out -> Emergency Exit
	{
		.species = SPECIES_GOLISOPOD,
		.originalAbility = ABILITY_WIMPOUT,
		.replaceAbilityName = NAME_EMERGENCY_EXIT,
	},

	// Dazzling -> Queenly Majesty
	{
		.species = SPECIES_TSAREENA,
		.originalAbility = ABILITY_DAZZLING,
		.replaceAbilityName = NAME_QUEENLY_MAJESTY,
	},

	// Dazzling -> Armor Tail
	{
		.species = SPECIES_FARIGIRAF,
		.originalAbility = ABILITY_DAZZLING,
		.replaceAbilityName = NAME_ARMOR_TAIL,
	},

	// Receiver -> Power of Alchemy
	{
		.species = SPECIES_GRIMER_A,
		.originalAbility = ABILITY_RECEIVER,
		.replaceAbilityName = NAME_POWER_OF_ALCHEMY,
	},
	{
		.species = SPECIES_MUK_A,
		.originalAbility = ABILITY_RECEIVER,
		.replaceAbilityName = NAME_POWER_OF_ALCHEMY,
	},

	// Stalwart -> Propeller Tail
	{
		.species = SPECIES_ARROKUDA,
		.originalAbility = ABILITY_STALWART,
		.replaceAbilityName = NAME_PROPELLER_TAIL,
	},
	{
		.species = SPECIES_BARRASKEWDA,
		.originalAbility = ABILITY_STALWART,
		.replaceAbilityName = NAME_PROPELLER_TAIL,
	},

	// Mummy -> Lingering Aroma
	{
		.species = SPECIES_OINKOLOGNE,
		.originalAbility = ABILITY_MUMMY,
		.replaceAbilityName = NAME_LINGERING_AROMA,
	},

};


struct AbilityBranch
{
	u8 ability;
	const u8* name;
	const u8* description;
};

struct AbilityVariant
{
	const u8* name;
	const u8* description;
};

struct MonWithBranchedAbility
{
	u16 species;
	u16 branch;
};

struct BranchDataEntry
{
	struct MonWithBranchedAbility* data;
    u16 size;
};

struct MonWithTypeBasedAbilityVariant
{
	u16 species;
	u8 type;
};

static struct AbilityVariant sBlazeVariantTable[TYPE_FAIRY + 1] = 
{
	[TYPE_FIRE] = {.name = NAME_BLAZE, .description = DESC_BLAZE},
	[TYPE_WATER] = {.name = NAME_TORRENT, .description = DESC_TORRENT},
	[TYPE_GRASS] = {.name = NAME_OVERGROW, .description = DESC_OVERGROW},
	[TYPE_BUG] = {.name = NAME_SWARM, .description = DESC_SWARM},

};

static struct AbilityVariant sNormalizeVariantTable[TYPE_FAIRY + 1] = 
{
	[TYPE_NORMAL] = {.name = NAME_NORMALIZE, .description = DESC_NORMALIZE},
	[TYPE_FLYING] = {.name = NAME_AERILATE, .description = DESC_AERILATE},
	[TYPE_FAIRY] = {.name = NAME_PIXILATE, .description = DESC_PIXILATE},
	[TYPE_ICE] = {.name = NAME_REFRIGERATE, .description = DESC_REFRIGERATE},
	[TYPE_ELECTRIC] = {.name = NAME_GALVANIZE, .description = DESC_GALVANIZE},
};

static struct AbilityVariant sTypePowerUpVariantTable[TYPE_FAIRY + 1] = 
{
	[TYPE_STEEL] = {.name = NAME_STEELWORKER, .description = DESC_STEELWORKER},
	[TYPE_ELECTRIC] = {.name = NAME_TRANSISTOR, .description = DESC_TRANSISTOR},
	[TYPE_DRAGON] = {.name = NAME_DRAGONS_MAW, .description = DESC_DRAGONS_MAW},
	[TYPE_ROCK] = {.name = NAME_ROCKY_PAYLOAD, .description = DESC_ROCKY_PAYLOAD},
};

static struct AbilityVariant sAuraVariantTable[TYPE_FAIRY + 1] =
{
	[TYPE_NORMAL] = {.name = NAME_NORMAL_AURA, .description = DESC_NORMAL_AURA},
	[TYPE_FIGHTING] = {.name = NAME_FIGHTING_AURA, .description = DESC_FIGHTING_AURA},
	[TYPE_FLYING] = {.name = NAME_FLYING_AURA, .description = DESC_FLYING_AURA},
	[TYPE_POISON] = {.name = NAME_POISON_AURA, .description = DESC_POISON_AURA},
	[TYPE_GROUND] = {.name = NAME_GROUND_AURA, .description = DESC_GROUND_AURA},
	[TYPE_ROCK] = {.name = NAME_ROCK_AURA, .description = DESC_ROCK_AURA},
	[TYPE_BUG] = {.name = NAME_BUG_AURA, .description = DESC_BUG_AURA},
	[TYPE_GHOST] = {.name = NAME_GHOST_AURA, .description = DESC_GHOST_AURA},
	[TYPE_STEEL] = {.name = NAME_STEEL_AURA, .description = DESC_STEEL_AURA},
	[TYPE_FIRE] = {.name = NAME_FIRE_AURA, .description = DESC_FIRE_AURA},
	[TYPE_WATER] = {.name = NAME_WATER_AURA, .description = DESC_WATER_AURA},
	[TYPE_GRASS] = {.name = NAME_GRASS_AURA, .description = DESC_GRASS_AURA},
	[TYPE_ELECTRIC] = {.name = NAME_ELECTRIC_AURA, .description = DESC_ELECTRIC_AURA},
	[TYPE_PSYCHIC] = {.name = NAME_PSYCHIC_AURA, .description = DESC_PSYCHIC_AURA},
	[TYPE_ICE] = {.name = NAME_ICE_AURA, .description = DESC_ICE_AURA},
	[TYPE_DRAGON] = {.name = NAME_DRAGON_AURA, .description = DESC_DRAGON_AURA},
	[TYPE_DARK] = {.name = NAME_DARK_AURA, .description = DESC_DARK_AURA},
	[TYPE_FAIRY] = {.name = NAME_FAIRY_AURA, .description = DESC_FAIRY_AURA},
};

const u8* gAuraEntryStrings[TYPE_FAIRY + 1] =
{
	[TYPE_NORMAL] = gText_NormalAuraActivate,
	[TYPE_FIGHTING] = gText_FightingAuraActivate,
	[TYPE_FLYING] = gText_FlyingAuraActivate,
	[TYPE_POISON] = gText_PoisonAuraActivate,
	[TYPE_GROUND] = gText_GroundAuraActivate,
	[TYPE_ROCK] = gText_RockAuraActivate,
	[TYPE_BUG] = gText_BugAuraActivate,
	[TYPE_GHOST] = gText_GhostAuraActivate,
	[TYPE_STEEL] = gText_SteelAuraActivate,
	[TYPE_FIRE] = gText_FireAuraActivate,
	[TYPE_WATER] = gText_WaterAuraActivate,
	[TYPE_GRASS] = gText_GrassAuraActivate,
	[TYPE_ELECTRIC] = gText_ElectricAuraActivate,
	[TYPE_PSYCHIC] = gText_PsychicAuraActivate,
	[TYPE_ICE] = gText_IceAuraActivate,
	[TYPE_DRAGON] = gText_DragonAuraActivate,
	[TYPE_DARK] = gText_DarkAuraActivate,
	[TYPE_FAIRY] = gText_FairyAuraActivate,
};

static struct MonWithTypeBasedAbilityVariant sBlazeVariantsData[] =
{
	{.species = SPECIES_ESCAVALIER, .type = TYPE_BUG},
};


static struct MonWithTypeBasedAbilityVariant sNormalizeVariantsData[] =
{
	{.species = SPECIES_SKITTY, .type = TYPE_NORMAL },
	{.species = SPECIES_DELCATTY, .type = TYPE_NORMAL },
	{.species = SPECIES_PINSIR_MEGA, .type = TYPE_FLYING },
	{.species = SPECIES_SALAMENCE_MEGA, .type = TYPE_FLYING },
	{.species = SPECIES_GARDEVOIR_MEGA, .type = TYPE_FAIRY },
	{.species = SPECIES_ALTARIA_MEGA, .type = TYPE_FAIRY },
	{.species = SPECIES_SYLVEON, .type = TYPE_FAIRY },
	{.species = SPECIES_GLALIE_MEGA, .type = TYPE_ICE },
	{.species = SPECIES_AMAURA, .type = TYPE_ICE },
	{.species = SPECIES_AURORUS, .type = TYPE_ICE },
	{.species = SPECIES_GEODUDE_A, .type = TYPE_ELECTRIC },
	{.species = SPECIES_GRAVELER_A, .type = TYPE_ELECTRIC },
	{.species = SPECIES_GOLEM_A, .type = TYPE_ELECTRIC },
};

static struct MonWithTypeBasedAbilityVariant sTypePowerUpVariantsData[] =
{
	{.species = SPECIES_DHELMISE, .type = TYPE_STEEL},
	{.species = SPECIES_REGIELEKI, .type = TYPE_ELECTRIC},
	{.species = SPECIES_REGIDRAGO, .type = TYPE_DRAGON},
	{.species = SPECIES_BOMBIRDIER, .type = TYPE_ROCK},
};

static struct MonWithTypeBasedAbilityVariant sAuraVariantsData[] = 
{
	{.species = SPECIES_XERNEAS, .type = TYPE_FAIRY},
	//{.species = SPECIES_YVELTAL, .type = TYPE_DARK},
};

static struct AbilityBranch sBranchTable[] =
{
	[BRANCH_DRIZZLE] = {.ability = ABILITYBRANCH_WEATHER_ON_SWITCHIN, .name = NAME_DRIZZLE, .description = DESC_DRIZZLE},
	[BRANCH_DROUGHT] = {.ability = ABILITYBRANCH_WEATHER_ON_SWITCHIN, .name = NAME_DROUGHT, .description = DESC_DROUGHT},
	[BRANCH_SAND_STREAM] = {.ability = ABILITYBRANCH_WEATHER_ON_SWITCHIN, .name = NAME_SAND_STREAM, .description = DESC_SAND_STREAM},
	[BRANCH_SNOW_WARNING] = {.ability = ABILITYBRANCH_WEATHER_ON_SWITCHIN, .name = NAME_SNOW_WARNING, .description = DESC_SNOW_WARNING},
	[BRANCH_LIMBER] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_LIMBER, .description = DESC_LIMBER},
	[BRANCH_INSOMNIA] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_INSOMNIA, .description = DESC_INSOMNIA},
	[BRANCH_IMMUNITY] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_IMMUNITY, .description = DESC_IMMUNITY},
	[BRANCH_MAGMA_ARMOR] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_MAGMA_ARMOR, .description = DESC_MAGMA_ARMOR},
	[BRANCH_WATER_VEIL] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_WATER_VEIL, .description = DESC_WATER_VEIL},
	[BRANCH_VITAL_SPIRIT] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_VITAL_SPIRIT, .description = DESC_VITAL_SPIRIT},
	[BRANCH_SAND_VEIL] = {.ability = ABILITYBRANCH_EVASION_IN_WEATHER, .name = NAME_SAND_VEIL, .description = DESC_SAND_VEIL},
	[BRANCH_SNOW_CLOAK] = {.ability = ABILITYBRANCH_EVASION_IN_WEATHER, .name = NAME_SNOW_CLOAK, .description = DESC_SNOW_CLOAK},
	[BRANCH_SWIFT_SWIM] = {.ability = ABILITYBRANCH_SPEED_IN_WEATHER, .name = NAME_SWIFT_SWIM, .description = DESC_SWIFT_SWIM},
	[BRANCH_CHLOROPHYLL] = {.ability = ABILITYBRANCH_SPEED_IN_WEATHER, .name = NAME_CHLOROPHYLL, .description = DESC_CHLOROPHYLL},
	[BRANCH_SAND_RUSH] = {.ability = ABILITYBRANCH_SPEED_IN_WEATHER, .name = NAME_SAND_RUSH, .description = DESC_SAND_RUSH},
	[BRANCH_SLUSH_RUSH] = {.ability = ABILITYBRANCH_SPEED_IN_WEATHER, .name = NAME_SLUSH_RUSH, .description = DESC_SLUSH_RUSH},
	[BRANCH_STATIC] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_STATIC, .description = DESC_STATIC},
	[BRANCH_CUTE_CHARM] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_CUTE_CHARM, .description = DESC_CUTE_CHARM},
	[BRANCH_EFFECT_SPORE] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_EFFECT_SPORE, .description = DESC_EFFECT_SPORE},
	[BRANCH_POISON_POINT] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_POISON_POINT, .description = DESC_POISON_POINT},
	[BRANCH_CURSED_BODY] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_CURSED_BODY, .description = DESC_CURSED_BODY},
	[BRANCH_FLAME_BODY] = {.ability = ABILITYBRANCH_STATUS_ON_CONTACT, .name = NAME_FLAME_BODY, .description = DESC_FLAME_BODY},
	[BRANCH_VOLT_ABSORB] = {.ability = ABILITYBRANCH_TYPE_ABSORPTION, .name = NAME_VOLT_ABSORB, .description = DESC_VOLT_ABSORB},
	[BRANCH_WATER_ABSORB] = {.ability = ABILITYBRANCH_TYPE_ABSORPTION, .name = NAME_WATER_ABSORB, .description = DESC_WATER_ABSORB},
	[BRANCH_SHADOW_TAG] = {.ability = ABILITYBRANCH_SWITCHOUT_PREVENTION, .name = NAME_SHADOW_TAG, .description = DESC_SHADOW_TAG},
	[BRANCH_ARENA_TRAP] = {.ability = ABILITYBRANCH_SWITCHOUT_PREVENTION, .name = NAME_ARENA_TRAP, .description = DESC_ARENA_TRAP},
	[BRANCH_MAGNET_PULL] = {.ability = ABILITYBRANCH_SWITCHOUT_PREVENTION, .name = NAME_MAGNET_PULL, .description = DESC_MAGNET_PULL},
	[BRANCH_WHITE_SMOKE] = {.ability = ABILITY_CLEARBODY, .name = NAME_WHITE_SMOKE, .description = DESC_WHITE_SMOKE},
	[BRANCH_FORECAST] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_FORECAST, .description = DESC_FORECAST},
	[BRANCH_ZEN_MODE] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_ZEN_MODE, .description = DESC_ZEN_MODE},
	[BRANCH_STANCE_CHANGE] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_STANCE_CHANGE, .description = DESC_STANCE_CHANGE},
	[BRANCH_SHIELDS_DOWN] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_SHIELDS_DOWN, .description = DESC_SHIELDS_DOWN},
	[BRANCH_SCHOOLING] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_SCHOOLING, .description = DESC_SCHOOLING},
	[BRANCH_DISGUISE] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_DISGUISE, .description = DESC_DISGUISE},
	[BRANCH_BATTLE_BOND] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_BATTLE_BOND, .description = DESC_BATTLE_BOND},
	[BRANCH_POWER_CONSTRUCT] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_POWER_CONSTRUCT, .description = DESC_POWER_CONSTRUCT},
	[BRANCH_GULP_MISSILE] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_GULP_MISSILE, .description = DESC_GULP_MISSILE},
	[BRANCH_ICE_FACE] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_ICE_FACE, .description = DESC_ICE_FACE},
	[BRANCH_HUNGER_SWITCH] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_HUNGER_SWITCH, .description = DESC_HUNGER_SWITCH},
	[BRANCH_MOXIE] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_MOXIE, .description = DESC_MOXIE},
	[BRANCH_BEAST_BOOST] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_BEAST_BOOST, .description = DESC_BEAST_BOOST},
	[BRANCH_CHILLING_NEIGH] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_CHILLING_NEIGH, .description = DESC_CHILLING_NEIGH},
	[BRANCH_GRIM_NEIGH] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_GRIM_NEIGH, .description = DESC_GRIM_NEIGH},
	[BRANCH_AS_ONE_CHILLING] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_AS_ONE_CHILLING, .description = DESC_AS_ONE_CHILLING},
	[BRANCH_AS_ONE_GRIM] = {.ability = ABILITYBRANCH_KO_STAT_BOOST, .name = NAME_AS_ONE_GRIM, .description = DESC_AS_ONE_GRIM},
	[BRANCH_PRIMORDIAL_SEA] = {.ability = ABILITYBRANCH_PRIMAL_WEATHER, .name = NAME_PRIMORDIAL_SEA, .description = DESC_PRIMORDIAL_SEA},
	[BRANCH_DESOLATE_LAND] = {.ability = ABILITYBRANCH_PRIMAL_WEATHER, .name = NAME_DESOLATE_LAND, .description = DESC_DESOLATE_LAND},
	[BRANCH_DELTA_STREAM] = {.ability = ABILITYBRANCH_PRIMAL_WEATHER, .name = NAME_DELTA_STREAM, .description = DESC_DELTA_STREAM},
	[BRANCH_ELECTRIC_SURGE] = {.ability = ABILITYBRANCH_TERRAIN_SWITCHIN, .name = NAME_ELECTRIC_SURGE, .description = DESC_ELECTRIC_SURGE},
	[BRANCH_PSYCHIC_SURGE] = {.ability = ABILITYBRANCH_TERRAIN_SWITCHIN, .name = NAME_PSYCHIC_SURGE, .description = DESC_PSYCHIC_SURGE},
	[BRANCH_MISTY_SURGE] = {.ability = ABILITYBRANCH_TERRAIN_SWITCHIN, .name = NAME_MISTY_SURGE, .description = DESC_MISTY_SURGE},
	[BRANCH_GRASSY_SURGE] = {.ability = ABILITYBRANCH_TERRAIN_SWITCHIN, .name = NAME_GRASSY_SURGE, .description = DESC_GRASSY_SURGE},
	[BRANCH_ANGER_SHELL] = {.ability = ABILITY_BERSERK, .name = NAME_ANGER_SHELL, .description = DESC_ANGER_SHELL},
	[BRANCH_TABLETS_OF_RUIN] = {.ability = ABILITYBRANCH_TREASURES_OF_RUIN, .name = NAME_TABLETS_OF_RUIN, .description = DESC_TABLETS_OF_RUIN},
	[BRANCH_SWORD_OF_RUIN] = {.ability = ABILITYBRANCH_TREASURES_OF_RUIN, .name = NAME_SWORD_OF_RUIN, .description = DESC_SWORD_OF_RUIN},
	[BRANCH_VESSEL_OF_RUIN] = {.ability = ABILITYBRANCH_TREASURES_OF_RUIN, .name = NAME_VESSEL_OF_RUIN, .description = DESC_VESSEL_OF_RUIN},
	[BRANCH_BEADS_OF_RUIN] = {.ability = ABILITYBRANCH_TREASURES_OF_RUIN, .name = NAME_BEADS_OF_RUIN, .description = DESC_BEADS_OF_RUIN},
	[BRANCH_EARTH_EATER] = {.ability = ABILITYBRANCH_TYPE_ABSORPTION, .name = NAME_EARTH_EATER, .description = DESC_EARTH_EATER},
	[BRANCH_GUARD_DOG] = {.ability = ABILITY_SUCTIONCUPS, .name = NAME_GUARD_DOG, .description = DESC_GUARD_DOG},
	[BRANCH_HADRON_ENGINE] = {.ability = ABILITYBRANCH_TERRAIN_SWITCHIN, .name = NAME_HADRON_ENGINE, .description = DESC_HADRON_ENGINE},
	[BRANCH_ORICHALCUM_PULSE] = {.ability = ABILITYBRANCH_WEATHER_ON_SWITCHIN, .name = NAME_ORICHALCUM_PULSE, .description = DESC_ORICHALCUM_PULSE},
	[BRANCH_MINDS_EYE] = {.ability = ABILITY_KEENEYE, .name = NAME_MINDS_EYE, .description = DESC_MINDS_EYE},
	[BRANCH_THERMAL_EXCHANGE] = {.ability = ABILITYBRANCH_STATUS_PREVENTION, .name = NAME_THERMAL_EXCHANGE, .description = DESC_THERMAL_EXCHANGE},
	[BRANCH_TOXIC_CHAIN] = {.ability = ABILITY_POISONTOUCH, .name = NAME_TOXIC_CHAIN, .description = DESC_TOXIC_CHAIN},
	[BRANCH_WELL_BAKED_BODY] = {.ability = ABILITY_FLASHFIRE, .name = NAME_WELL_BAKED_BODY, .description = DESC_WELL_BAKED_BODY},
	[BRANCH_ZERO_TO_HERO] = {.ability = ABILITYBRANCH_SIGNATURE_FORM_CHANGE, .name = NAME_ZERO_TO_HERO, .description = DESC_ZERO_TO_HERO},
};

static struct MonWithBranchedAbility sWeatherSwitchInBranchData[] = 
{
	{ .species = SPECIES_POLITOED, 			.branch = BRANCH_DRIZZLE,},
	{ .species = SPECIES_PELIPPER, 			.branch = BRANCH_DRIZZLE,},
	{ .species = SPECIES_KYOGRE, 			.branch = BRANCH_DRIZZLE,},
	{ .species = SPECIES_CHARIZARD_MEGA_Y, 	.branch = BRANCH_DROUGHT,},
	{ .species = SPECIES_VULPIX, 			.branch = BRANCH_DROUGHT,},
	{ .species = SPECIES_NINETALES, 		.branch = BRANCH_DROUGHT,},
	{ .species = SPECIES_TORKOAL, 			.branch = BRANCH_DROUGHT,},
	{ .species = SPECIES_GROUDON, 			.branch = BRANCH_DROUGHT,},
	{ .species = SPECIES_TYRANITAR, 		.branch = BRANCH_SAND_STREAM,},
	{ .species = SPECIES_TYRANITAR_MEGA, 	.branch = BRANCH_SAND_STREAM,},
	{ .species = SPECIES_HIPPOPOTAS, 		.branch = BRANCH_SAND_STREAM,},
	{ .species = SPECIES_HIPPOWDON, 		.branch = BRANCH_SAND_STREAM,},
	{ .species = SPECIES_GIGALITH, 			.branch = BRANCH_SAND_STREAM,},
	{ .species = SPECIES_VULPIX_A, 			.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_NINETALES_A, 		.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_SNOVER, 			.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_ABOMASNOW, 		.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_ABOMASNOW_MEGA, 	.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_VANILLUXE, 		.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_AMAURA, 			.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_AURORUS, 			.branch = BRANCH_SNOW_WARNING,},
	{ .species = SPECIES_KORAIDON, 			.branch = BRANCH_ORICHALCUM_PULSE,},
};

static struct MonWithBranchedAbility sStatusPreventionBranchData[] =
{
	{ .species = SPECIES_PERSIAN, 			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_HITMONLEE,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_DITTO,				.branch = BRANCH_LIMBER },
	{ .species = SPECIES_BUNEARY,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_LOPUNNY,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_GLAMEOW,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_PURRLOIN,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_LIEPARD,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_STUNFISK,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_HAWLUCHA,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_MAREANIE,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_TOXAPEX,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_CLOBBOPUS,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_GRAPPLOCT,			.branch = BRANCH_LIMBER },
	{ .species = SPECIES_DROWZEE,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_HYPNO,				.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_MEWTWO,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_MEWTWO_MEGA_Y,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_HOOTHOOT,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_NOCTOWL,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_SPINARAK,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_ARIADOS,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_MURKROW,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_DELIBIRD,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_SHUPPET,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_BANETTE,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_HONCHKROW,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_PUMPKABOO,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_PUMPKABOO_XL,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_PUMPKABOO_L,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_PUMPKABOO_M,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_GOURGEIST,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_GOURGEIST_XL,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_GOURGEIST_L,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_GOURGEIST_M,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_TAROUNTULA,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_SPIDOPS,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_CAPSAKID,			.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_SCOVILLAIN,		.branch = BRANCH_INSOMNIA },
	{ .species = SPECIES_SNORLAX,			.branch = BRANCH_IMMUNITY },
	{ .species = SPECIES_GLIGAR,			.branch = BRANCH_IMMUNITY },
	{ .species = SPECIES_ZANGOOSE,			.branch = BRANCH_IMMUNITY },
	{ .species = SPECIES_SLUGMA,			.branch = BRANCH_MAGMA_ARMOR },
	{ .species = SPECIES_MAGCARGO,			.branch = BRANCH_MAGMA_ARMOR },
	{ .species = SPECIES_CAMERUPT,			.branch = BRANCH_MAGMA_ARMOR },
	{ .species = SPECIES_GOLDEEN,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_SEAKING,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_MANTINE,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_WAILMER,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_WAILORD,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_HUNTAIL,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_BUIZEL,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_FLOATZEL,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_FINNEON,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_LUMINEON,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_MANTYKE,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_FINIZEN,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_DONDOZO,			.branch = BRANCH_WATER_VEIL },
	{ .species = SPECIES_MANKEY,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_PRIMEAPE,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_MR_MIME_G,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_ELECTABUZZ,		.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_MAGMAR,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_DELIBIRD,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_TYROGUE,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_ELEKID,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_MAGBY,				.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_VIGOROTH,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_ELECTIVIRE,		.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_MAGMORTAR,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_LILLIPUP,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_ROCKRUFF,			.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_LYCANROC_N,		.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_ANNIHILAPE,		.branch = BRANCH_VITAL_SPIRIT },
	{ .species = SPECIES_FRIGIBAX,			.branch = BRANCH_THERMAL_EXCHANGE },
	{ .species = SPECIES_ARCTIBAX,			.branch = BRANCH_THERMAL_EXCHANGE },
	{ .species = SPECIES_BAXCALIBUR,		.branch = BRANCH_THERMAL_EXCHANGE },
};

static struct MonWithBranchedAbility sWeatherEvasionBranchData[] = 
{
	{ .species = SPECIES_SANDSHREW,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_SANDSLASH,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_DIGLETT,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_DIGLETT_A,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_DUGTRIO,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_DUGTRIO_A,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GEODUDE,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GRAVELER,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GOLEM,				.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GLIGAR,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_PHANPY,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_DONPHAN,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_LARVITAR,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_CACNEA,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_CACTURNE,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GIBLE,				.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GABITE,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GARCHOMP,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_GLISCOR,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_STUNFISK,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_HELIOPTILE,		.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_HELIOLISK,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_SANDYGAST,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_PALOSSAND,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_SILICOBRA,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_SANDACONDA,		.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_WIGLETT,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_WUGTRIO,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_ORTHWORM,			.branch = BRANCH_SAND_VEIL },
	{ .species = SPECIES_SANDSHREW_A,		.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_SANDSLASH_A,		.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_VULPIX_A,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_NINETALES_A,		.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_ARTICUNO,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_SWINUB,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_PILOSWINE,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_GLACEON,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_MAMOSWINE,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_FROSLASS,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_VANILLITE,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_VANILLISH,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_CUBCHOO,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_BEARTIC,			.branch = BRANCH_SNOW_CLOAK },
	{ .species = SPECIES_CETODDLE,			.branch = BRANCH_SNOW_CLOAK },

};

static struct MonWithBranchedAbility sWeatherSpeedBranchData[] = 
{
	{ .species = SPECIES_PSYDUCK,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_GOLDUCK,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_POLIWAG,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_POLIWHIRL,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_POLIWRATH,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_HORSEA,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_GOLDEEN,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_SEAKING,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_MAGIKARP,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_OMANYTE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_OMASTAR,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_KABUTO,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_KABUTOPS,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_QWILFISH,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_QWILFISH_H,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_MANTINE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_KINGDRA,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_SWAMPERT_MEGA,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_LOTAD,				.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_LOMBRE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_LUDICOLO,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_SURSKIT,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_ANORITH,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_ARMALDO,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_FEEBAS,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_HUNTAIL,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_GOREBYSS,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_RELICANTH,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_LUVDISC,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BUIZEL,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_FLOATZEL,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_FINNEON,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_LUMINEON,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_MANTYKE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_TYMPOLE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_PALPITOAD,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_SEISMITOAD,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_TIRTOUGA,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_CARRACOSTA,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BEARTIC,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_CHEWTLE,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_DREDNAW,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_ARROKUDA,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BARRASKEWDA,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BASCULEGION,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BASCULEGION_F,		.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_OVERQWIL,			.branch = BRANCH_SWIFT_SWIM },
	{ .species = SPECIES_BULBASAUR,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_IVYSAUR,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_VENUSAUR,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_ODDISH,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_GLOOM,				.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_VILEPLUME,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_BELLSPROUT,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_WEEPINBELL,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_VICTREEBEL,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_EXEGGCUTE,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_EXEGGUTOR,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_TANGELA,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_BELLOSSOM,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_HOPPIP,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SKIPLOOM,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_JUMPLUFF,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SUNKERN,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SUNFLORA,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SEEDOT,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_NUZLEAF,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SHIFTRY,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_TROPIUS,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_CHERUBI,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_TANGROWTH,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_LEAFEON,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SEWADDLE,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SWADLOON,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_LEAVANNY,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_COTTONEE,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_WHIMSICOTT,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_PETILIL,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_LILLIGANT,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_LILLIGANT_H,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_MARACTUS,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_DEERLING,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SAWSBUCK,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_CAPSAKID,			.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SCOVILLAIN,		.branch = BRANCH_CHLOROPHYLL },
	{ .species = SPECIES_SANDSHREW,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_SANDSLASH,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_HERDIER,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_STOUTLAND,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_DRILBUR,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_EXCADRILL,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_LYCANROC,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_DRACOZOLT,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_DRACOVISH,			.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_HOUNDSTONE,		.branch = BRANCH_SAND_RUSH },
	{ .species = SPECIES_SANDSHREW_A,		.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_SANDSLASH_A,		.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_CUBCHOO,			.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_BEARTIC,			.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_ARCTOZOLT,			.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_ARCTOVISH,			.branch = BRANCH_SLUSH_RUSH },
	{ .species = SPECIES_CETITAN,			.branch = BRANCH_SLUSH_RUSH },
};


static struct MonWithBranchedAbility sStatusContactBranchData[] = 
{
	{ .species = SPECIES_PICHU,					.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_PICHU_SPIKY,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_SURFING,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_FLYING,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_COSPLAY,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_LIBRE,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_POP_STAR,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_ROCK_STAR,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_BELLE,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_PHD,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_ORIGINAL,	.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_HOENN,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_SINNOH,	.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_UNOVA,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_KALOS,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_ALOLA,		.branch = BRANCH_STATIC },
	{ .species = SPECIES_PIKACHU_CAP_PARTNER,	.branch = BRANCH_STATIC },
	{ .species = SPECIES_RAICHU,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_VOLTORB,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_VOLTORB_H,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_ELECTRODE,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_ELECTRODE_H,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_ELECTABUZZ,			.branch = BRANCH_STATIC },
	{ .species = SPECIES_ZAPDOS,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_MAREEP,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_FLAAFFY,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_AMPHAROS,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_ELEKID,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_ELECTRIKE,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_MANECTRIC,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_EMOLGA,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_STUNFISK,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_TOXEL,					.branch = BRANCH_STATIC },
	{ .species = SPECIES_ARCTOZOLT,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_PAWMI,					.branch = BRANCH_STATIC },
	{ .species = SPECIES_TADBULB,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_BELLIBOLT,				.branch = BRANCH_STATIC },
	{ .species = SPECIES_CLEFAIRY,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_CLEFABLE,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_JIGGLYPUFF,			.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_WIGGLYTUFF,			.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_CLEFFA,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_IGGLYBUFF,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_SKITTY,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_DELCATTY,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_MILOTIC,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_LOPUNNY,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_MINCCINO,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_CINCCINO,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_SYLVEON,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_STUFFUL,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_ENAMORUS,				.branch = BRANCH_CUTE_CHARM },
	{ .species = SPECIES_VILEPLUME,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_PARAS,					.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_PARASECT,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_SHROOMISH,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_BRELOOM,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_FOONGUS,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_AMOONGUSS,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_MORELULL,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_SHIINOTIC,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_GOSSIFLEUR,			.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_ELDEGOSS,				.branch = BRANCH_EFFECT_SPORE },
	{ .species = SPECIES_NIDORAN_F,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_NIDORINA,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_NIDOQUEEN,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_NIDORAN_M,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_NIDORINO,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_NIDOKING,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_SEADRA,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_WOOPER,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_QWILFISH,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_QWILFISH_H,			.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_ROSELIA,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_BUDEW,					.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_ROSERADE,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_VENIPEDE,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_WHIRLIPEDE,			.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_SCOLIPEDE,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_SKRELP,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_DRAGALGE,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_OVERQWIL,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_CLODSIRE,				.branch = BRANCH_POISON_POINT },
	{ .species = SPECIES_GENGAR,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_MAROWAK_A,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_CORSOLA_G,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_SHUPPET,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_BANETTE,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_FROSLASS,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_FRILLISH,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_FRILLISH_F,			.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_JELLICENT,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_JELLICENT_F,			.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_SINISTEA,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_POLTEAGEIST,			.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_DREEPY,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_DRAKLOAK,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_DRAGAPULT,				.branch = BRANCH_CURSED_BODY },
	{ .species = SPECIES_PONYTA,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_RAPIDASH,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_MAGMAR,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_MOLTRES,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_SLUGMA,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_MAGCARGO,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_MAGBY,					.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_MAGMORTAR,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_HEATRAN,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_LITWICK,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_LAMPENT,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_CHANDELURE,			.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_LARVESTA,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_VOLCARONA,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_FLETCHINDER,			.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_TALONFLAME,			.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_CARKOL,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_COALOSSAL,				.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_SIZZLIPEDE,			.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_CENTISKORCH,			.branch = BRANCH_FLAME_BODY },
	{ .species = SPECIES_CHARCADET,				.branch = BRANCH_FLAME_BODY },

};

static struct MonWithBranchedAbility sTypeAbsorptionBranchData[] =
{
	{ .species = SPECIES_JOLTEON,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_CHINCHOU,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_LANTURN,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_MINUN,					.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_PACHIRISU,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_THUNDURUS_THERIAN,		.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_ZERAORA,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_DRACOZOLT,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_ARCTOZOLT,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_PAWMO,					.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_PAWMOT,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_WATTREL,				.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_KILOWATTREL,			.branch = BRANCH_VOLT_ABSORB },
	{ .species = SPECIES_POLIWAG,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_POLIWHIRL,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_POLIWRATH,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_LAPRAS,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_VAPOREON,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_CHINCHOU,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_LANTURN,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_POLITOED,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_WOOPER,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_WOOPER_P,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_QUAGSIRE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_MANTINE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_CACNEA,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_CACTURNE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_MANTYKE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_TYMPOLE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_PALPITOAD,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_SEISMITOAD,			.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_MARACTUS,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_FRILLISH,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_FRILLISH_F,			.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_JELLICENT,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_JELLICENT_F,			.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_VOLCANION,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_DEWPIDER,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_ARAQUANID,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_DRACOVISH,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_ARCTOVISH,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_CLODSIRE,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_OGERPON_WELLSPRING,	.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_TATSUGIRI,				.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_TATSUGIRI_DROOPY,		.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_TATSUGIRI_STRETCHY,	.branch = BRANCH_WATER_ABSORB },
	{ .species = SPECIES_ORTHWORM,				.branch = BRANCH_EARTH_EATER },
};

static struct MonWithBranchedAbility sSwitchoutPreventionBranchData[] =
{
	{ .species = SPECIES_GENGAR_MEGA,			.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_WOBBUFFET,				.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_WYNAUT,				.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_GOTHITA,				.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_GOTHORITA,				.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_GOTHITELLE,			.branch = BRANCH_SHADOW_TAG },
	{ .species = SPECIES_GEODUDE_A,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_GRAVELER_A,			.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_GOLEM_A,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_MAGNEMITE,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_MAGNETON,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_NOSEPASS,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_MAGNEZONE,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_PROBOPASS,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_MELTAN,				.branch = BRANCH_MAGNET_PULL },
	{ .species = SPECIES_DIGLETT,				.branch = BRANCH_ARENA_TRAP },
	{ .species = SPECIES_DUGTRIO,				.branch = BRANCH_ARENA_TRAP },
	{ .species = SPECIES_TRAPINCH,				.branch = BRANCH_ARENA_TRAP },
};

static struct MonWithBranchedAbility sClearBodyBranchData[] =
{
	{ .species = SPECIES_TORKOAL,				.branch = BRANCH_WHITE_SMOKE },
	{ .species = SPECIES_HEATMOR,				.branch = BRANCH_WHITE_SMOKE },
	{ .species = SPECIES_SIZZLIPEDE,			.branch = BRANCH_WHITE_SMOKE },
	{ .species = SPECIES_CENTISKORCH,			.branch = BRANCH_WHITE_SMOKE },
};


static struct MonWithBranchedAbility sSignatureFormChangeBranchData[] = 
{
	{ .species = SPECIES_CASTFORM,				.branch = BRANCH_FORECAST },
	{ .species = SPECIES_DARMANITAN,			.branch = BRANCH_ZEN_MODE },
	{ .species = SPECIES_DARMANITANZEN,			.branch = BRANCH_ZEN_MODE },
	{ .species = SPECIES_DARMANITAN_G,			.branch = BRANCH_ZEN_MODE },
	{ .species = SPECIES_DARMANITAN_G_ZEN,		.branch = BRANCH_ZEN_MODE },
	{ .species = SPECIES_AEGISLASH,				.branch = BRANCH_STANCE_CHANGE },
	{ .species = SPECIES_AEGISLASH_BLADE,		.branch = BRANCH_STANCE_CHANGE },
	{ .species = SPECIES_MINIOR_SHIELD,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_RED,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_BLUE,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_ORANGE,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_YELLOW,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_INDIGO,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_GREEN,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_MINIOR_VIOLET,			.branch = BRANCH_SHIELDS_DOWN },
	{ .species = SPECIES_WISHIWASHI,			.branch = BRANCH_SCHOOLING },
	{ .species = SPECIES_WISHIWASHI_S,			.branch = BRANCH_SCHOOLING },
	{ .species = SPECIES_MIMIKYU,				.branch = BRANCH_DISGUISE },
	{ .species = SPECIES_MIMIKYU_BUSTED,		.branch = BRANCH_DISGUISE },
	{ .species = SPECIES_GRENINJA,				.branch = BRANCH_BATTLE_BOND },
	{ .species = SPECIES_ASHGRENINJA,			.branch = BRANCH_BATTLE_BOND },
	{ .species = SPECIES_ZYGARDE,				.branch = BRANCH_POWER_CONSTRUCT },
	{ .species = SPECIES_ZYGARDE_10,			.branch = BRANCH_POWER_CONSTRUCT },
	{ .species = SPECIES_ZYGARDE_COMPLETE,		.branch = BRANCH_POWER_CONSTRUCT },
	{ .species = SPECIES_CRAMORANT,				.branch = BRANCH_GULP_MISSILE },
	{ .species = SPECIES_CRAMORANT_GULPING,		.branch = BRANCH_GULP_MISSILE },
	{ .species = SPECIES_CRAMORANT_GORGING,		.branch = BRANCH_GULP_MISSILE },
	{ .species = SPECIES_EISCUE,				.branch = BRANCH_ICE_FACE },
	{ .species = SPECIES_EISCUE_NOICE,			.branch = BRANCH_ICE_FACE },
	{ .species = SPECIES_MORPEKO,				.branch = BRANCH_HUNGER_SWITCH },
	{ .species = SPECIES_MORPEKO_HANGRY,		.branch = BRANCH_HUNGER_SWITCH },
	{ .species = SPECIES_PALAFIN,				.branch = BRANCH_ZERO_TO_HERO },
	{ .species = SPECIES_PALAFIN_HERO,			.branch = BRANCH_ZERO_TO_HERO },
};

static struct MonWithBranchedAbility sKOStatBoostBranchData[] = 
{
	{ .species = SPECIES_PINSIR, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_GYARADOS, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_HERACROSS, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_MIGHTYENA, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_SALAMENCE, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_HONCHKROW, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_SANDILE, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_KROKOROK, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_KROOKODILE, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_SCRAGGY, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_SCRAFTY, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_LITLEO, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_PYROAR, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_QUAXLY, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_QUAXWELL, 				.branch = BRANCH_MOXIE },
	{ .species = SPECIES_QUAQUAVAL, 			.branch = BRANCH_MOXIE },
	{ .species = SPECIES_NIHILEGO,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_BUZZWOLE,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_PHEROMOSA,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_XURKITREE,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_CELESTEELA,			.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_KARTANA,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_GUZZLORD,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_POIPOLE,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_NAGANADEL,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_STAKATAKA,				.branch = BRANCH_BEAST_BOOST },
	{ .species = SPECIES_BLACEPHALON,			.branch = BRANCH_BEAST_BOOST },	
	{ .species = SPECIES_GLASTRIER,				.branch = BRANCH_CHILLING_NEIGH },	
	{ .species = SPECIES_SPECTRIER,				.branch = BRANCH_GRIM_NEIGH },	
	{ .species = SPECIES_CALYREX_ICE_RIDER,		.branch = BRANCH_AS_ONE_CHILLING },	
	{ .species = SPECIES_CALYREX_SHADOW_RIDER,	.branch = BRANCH_AS_ONE_GRIM },	
};

static struct MonWithBranchedAbility sPrimalWeatherBranchData[] = 
{
	{ .species = SPECIES_KYOGRE_PRIMAL,			.branch = BRANCH_PRIMORDIAL_SEA },
	{ .species = SPECIES_GROUDON_PRIMAL,		.branch = BRANCH_DESOLATE_LAND },
	{ .species = SPECIES_RAYQUAZA_MEGA,			.branch = BRANCH_DELTA_STREAM },
};

static struct MonWithBranchedAbility sTerrainSwitchinBranchData[] = 
{
	{ .species = SPECIES_TAPU_KOKO,				.branch = BRANCH_ELECTRIC_SURGE },
	{ .species = SPECIES_PINCURCHIN,			.branch = BRANCH_ELECTRIC_SURGE },
	{ .species = SPECIES_TAPU_LELE,				.branch = BRANCH_PSYCHIC_SURGE },
	{ .species = SPECIES_INDEEDEE,				.branch = BRANCH_PSYCHIC_SURGE },
	{ .species = SPECIES_INDEEDEE_FEMALE,		.branch = BRANCH_PSYCHIC_SURGE },
	{ .species = SPECIES_TAPU_BULU,				.branch = BRANCH_GRASSY_SURGE },
	{ .species = SPECIES_GROOKEY,				.branch = BRANCH_GRASSY_SURGE },
	{ .species = SPECIES_THWACKEY,				.branch = BRANCH_GRASSY_SURGE },
	{ .species = SPECIES_RILLABOOM,				.branch = BRANCH_GRASSY_SURGE },
	{ .species = SPECIES_WEEZING_G,				.branch = BRANCH_MISTY_SURGE },
	{ .species = SPECIES_TAPU_FINI,				.branch = BRANCH_MISTY_SURGE },
	{ .species = SPECIES_MIRAIDON, 				.branch = BRANCH_HADRON_ENGINE },
};

static struct MonWithBranchedAbility sBerserkBranchData[] =
{
	{ .species = SPECIES_KLAWF,					.branch = BRANCH_ANGER_SHELL },
};

static struct MonWithBranchedAbility sTreasuresOfRuinBanchData[] =
{
	{ .species = SPECIES_WO_CHIEN,				.branch = BRANCH_TABLETS_OF_RUIN },
	{ .species = SPECIES_CHIEN_PAO,				.branch = BRANCH_SWORD_OF_RUIN },
	{ .species = SPECIES_TING_LU,				.branch = BRANCH_VESSEL_OF_RUIN },
	{ .species = SPECIES_CHI_YU,				.branch = BRANCH_BEADS_OF_RUIN },
};

static struct MonWithBranchedAbility sSuctionCupsBranchData[] = 
{
	{ .species = SPECIES_MABOSSTIFF, 			.branch = BRANCH_GUARD_DOG },
	{ .species = SPECIES_OKIDOGI, 				.branch = BRANCH_GUARD_DOG },
};

static struct MonWithBranchedAbility sKeenEyeBranchData[] = 
{
	{ .species = SPECIES_URSALUNA_BLOODMOON,	.branch = BRANCH_MINDS_EYE },
};

static struct MonWithBranchedAbility sPoisonTouchBranchData[] =
{
	{ .species = SPECIES_OKIDOGI,				.branch = BRANCH_TOXIC_CHAIN },
	{ .species = SPECIES_MUNKIDORI,				.branch = BRANCH_TOXIC_CHAIN },
	{ .species = SPECIES_FEZANDIPITI,			.branch = BRANCH_TOXIC_CHAIN },
};

static struct MonWithBranchedAbility sFlashFireBranchData[] =
{
	{ .species = SPECIES_DACHSBUN, 				.branch = BRANCH_WELL_BAKED_BODY },
};

static struct BranchDataEntry sAbilityToBranchDataTable[] = 
{
	[ABILITYBRANCH_WEATHER_ON_SWITCHIN] = {.data = sWeatherSwitchInBranchData, .size = ARRAY_COUNT(sWeatherSwitchInBranchData),},
	[ABILITYBRANCH_STATUS_PREVENTION] = {.data = sStatusPreventionBranchData, .size = ARRAY_COUNT(sStatusPreventionBranchData),},
	[ABILITYBRANCH_EVASION_IN_WEATHER] = {.data = sWeatherEvasionBranchData, .size = ARRAY_COUNT(sWeatherEvasionBranchData),},
	[ABILITYBRANCH_SPEED_IN_WEATHER] = {.data = sWeatherSpeedBranchData, .size = ARRAY_COUNT(sWeatherSpeedBranchData),},
	[ABILITYBRANCH_STATUS_ON_CONTACT] = {.data = sStatusContactBranchData, .size = ARRAY_COUNT(sStatusContactBranchData),},
	[ABILITYBRANCH_TYPE_ABSORPTION] = {.data = sTypeAbsorptionBranchData, .size = ARRAY_COUNT(sTypeAbsorptionBranchData),},
	[ABILITYBRANCH_SWITCHOUT_PREVENTION] = {.data = sSwitchoutPreventionBranchData, .size = ARRAY_COUNT(sSwitchoutPreventionBranchData),},
	[ABILITY_CLEARBODY] = {.data = sClearBodyBranchData, .size = ARRAY_COUNT(sClearBodyBranchData),},
	[ABILITYBRANCH_SIGNATURE_FORM_CHANGE] = {.data = sSignatureFormChangeBranchData, .size = ARRAY_COUNT(sSignatureFormChangeBranchData),},
	[ABILITYBRANCH_KO_STAT_BOOST] = {.data = sKOStatBoostBranchData, .size = ARRAY_COUNT(sKOStatBoostBranchData),},
	[ABILITYBRANCH_PRIMAL_WEATHER] = {.data = sPrimalWeatherBranchData, .size = ARRAY_COUNT(sPrimalWeatherBranchData),},
	[ABILITYBRANCH_TERRAIN_SWITCHIN] = {.data = sTerrainSwitchinBranchData, .size = ARRAY_COUNT(sTerrainSwitchinBranchData),},
	[ABILITY_BERSERK] = {.data = sBerserkBranchData, .size = ARRAY_COUNT(sBerserkBranchData),},
	[ABILITYBRANCH_TREASURES_OF_RUIN] = {.data = sTreasuresOfRuinBanchData, .size = ARRAY_COUNT(sTreasuresOfRuinBanchData),},
	[ABILITY_SUCTIONCUPS] = {.data = sSuctionCupsBranchData, .size = ARRAY_COUNT(sSuctionCupsBranchData),},
	[ABILITY_KEENEYE] = {.data = sKeenEyeBranchData, .size = ARRAY_COUNT(sKeenEyeBranchData), },
	[ABILITY_POISONTOUCH] = {.data = sPoisonTouchBranchData, .size = ARRAY_COUNT(sPoisonTouchBranchData), },
	[ABILITY_FLASHFIRE] = {.data = sFlashFireBranchData, .size = ARRAY_COUNT(sFlashFireBranchData), },
};

bool8 BankHasBranchAbility(u8 bank, u16 branch)
{
	u8 ability = sBranchTable[branch].ability;
	return (ABILITY(bank) == ability && SpeciesHasBranchAbility(GetProperAbilityPopUpSpecies(bank), ability, branch));
}

bool8 SpeciesHasBranchAbility(u16 species, u8 ability, u16 branch)
{
	if (sBranchTable[branch].ability != ability)
		return FALSE;

	if (ability < ARRAY_COUNT(sAbilityToBranchDataTable))
	{
		for(u8 i = 0; i < sAbilityToBranchDataTable[ability].size; ++i)
		{
			if (species == sAbilityToBranchDataTable[ability].data[i].species)
			{
				if (branch == sAbilityToBranchDataTable[ability].data[i].branch)	
					return TRUE;
				else
					return FALSE;
			}
		}
	}
	return FALSE;
}

u8 GetBankBlazeVariant(u8 bank)
{
	u8 ability = ABILITY(bank);
	if (ability != ABILITYVARIANT_BLAZE)
		return TYPE_NORMAL;

	return GetSpeciesBlazeVariant(GetProperAbilityPopUpSpecies(bank), ability);
}

u8 GetSpeciesBlazeVariant(u16 species, u8 ability)
{
	u8 size = ARRAY_COUNT(sBlazeVariantsData);
	if (ability != ABILITYVARIANT_BLAZE)
		return TYPE_NORMAL;

	for(u8 i = 0; i < size; ++i)
	{
		if(sBlazeVariantsData[i].species == species)
			return sBlazeVariantsData[i].type;
	}

	//return mon's actual type if not found in the specific variants table
	return gBaseStats[species].type1;
}

u8 GetBankNormalizeVariant(u8 bank)
{
	u8 ability = ABILITY(bank);
	if (ability != ABILITYVARIANT_NORMALIZE)
		return 0xFF; //because 0x0 (TYPE_NORMAL) is NORMALIZE rather than nothing

	return GetSpeciesNormalizeVariant(GetProperAbilityPopUpSpecies(bank), ability);
}

u8 GetSpeciesNormalizeVariant(u16 species, u8 ability)
{
	u8 size = ARRAY_COUNT(sNormalizeVariantsData);
	if (ability != ABILITYVARIANT_NORMALIZE)
		return 0xFF;

	for(u8 i = 0; i < size; ++i)
	{
		if(sNormalizeVariantsData[i].species == species)
			return sNormalizeVariantsData[i].type;
	}

	return gBaseStats[species].type1;
}

u8 GetBankTypePowerUpVariant(u8 bank)
{
	u8 ability = ABILITY(bank);
	if (ability != ABILITYVARIANT_TYPE_POWERUP)
		return 0xFF;

	return GetSpeciesTypePowerUpVariant(GetProperAbilityPopUpSpecies(bank), ability);
}

u8 GetSpeciesTypePowerUpVariant(u16 species, u8 ability)
{
	u8 size = ARRAY_COUNT(sTypePowerUpVariantsData);
	if (ability != ABILITYVARIANT_TYPE_POWERUP)
		return 0xFF;

	for(u8 i = 0; i < size; ++i)
	{
		if(sTypePowerUpVariantsData[i].species == species)
			return sTypePowerUpVariantsData[i].type;
	}
	return gBaseStats[species].type1;
}


u8 GetBankAuraVariant(u8 bank)
{
	u8 ability = ABILITY(bank);
	if (ability != ABILITYVARIANT_AURA)
		return 0xFF;

	return GetSpeciesAuraVariant(GetProperAbilityPopUpSpecies(bank), ability);
}

u8 GetSpeciesAuraVariant(u16 species, u8 ability)
{
	u8 size = ARRAY_COUNT(sAuraVariantsData);
	if (ability != ABILITYVARIANT_AURA)
		return 0xFF;

	for(u8 i = 0 ; i < size; ++i)
	{
		if(sAuraVariantsData[i].species == species)
			return sAuraVariantsData[i].type;
	}
	return gBaseStats[species].type1;
}

u8 GetAuraTypeOnField(void)
{
	for (u8 i = 0; i < gBattlersCount; i++)
	{
		if (ABILITY(i) == ABILITYVARIANT_AURA && BATTLER_ALIVE(i))
		{
			return GetBankAuraVariant(i);
		}
	}
	return 0xFF;
}


const u8* GetAbilityNameOverride(const u8 ability, const u16 species) 
{
	const u8* nameStr = NULL;
	u8 type;

	switch(ability)
	{
		case ABILITYVARIANT_AURA:
			type = GetSpeciesAuraVariant(species, ability);
			return sAuraVariantTable[type].name;
		case ABILITYVARIANT_TYPE_POWERUP:
			type = GetSpeciesTypePowerUpVariant(species, ability);
			return sTypePowerUpVariantTable[type].name;
		case ABILITYVARIANT_BLAZE:
			type = GetSpeciesBlazeVariant(species, ability);
			return sBlazeVariantTable[type].name;
		case ABILITYVARIANT_NORMALIZE:
			type = GetSpeciesNormalizeVariant(species, ability);
			return sNormalizeVariantTable[type].name;
	}

	//find branch name
	if(ability < ARRAY_COUNT(sAbilityToBranchDataTable))
	{
		for(u8 i = 0; i < sAbilityToBranchDataTable[ability].size; ++i)
		{
			if(species == sAbilityToBranchDataTable[ability].data[i].species)
			{
				nameStr = sBranchTable[sAbilityToBranchDataTable[ability].data[i].branch].name;
				break;
			}
		}
	}

	if(nameStr != NULL)
		return nameStr;

	//find clone ability name
	for(u8 i = 0; i < ARRAY_COUNT(sCloneNames); ++i)
    {
        if(ability == sCloneNames[i].originalAbility && species == sCloneNames[i].species)
        {
            nameStr = sCloneNames[i].replaceAbilityName;
            break;
        }
    }

	return nameStr;
}

const u8* GetAbilityName(const u8 ability, const u16 species)
{
	const u8* override = GetAbilityNameOverride(ability, species);
	if (override != NULL)
		return override;

	const u8* ptr = gAbilityNames[ability];

	if (ptr[3] == 0x8 || ptr[3] == 0x9) //Expanded Ability Names
		ptr = T1_READ_PTR(ptr);

	return ptr;
}

const u8* GetAbilityDescriptionOverride(const u8 ability, const u16 species) //Bypasses the 255 Ability limitation and implements new Abilities
{
	const u8* descStr = NULL;
	u8 type;

	switch(ability)
	{
		case ABILITYVARIANT_AURA:
			type = GetSpeciesAuraVariant(species, ability);
			return sAuraVariantTable[type].description;
		case ABILITYVARIANT_TYPE_POWERUP:
			type = GetSpeciesTypePowerUpVariant(species, ability);
			return sTypePowerUpVariantTable[type].description;
		case ABILITYVARIANT_BLAZE:
			type = GetSpeciesBlazeVariant(species, ability);
			return sBlazeVariantTable[type].description;
		case ABILITYVARIANT_NORMALIZE:
			type = GetSpeciesNormalizeVariant(species, ability);
			return sNormalizeVariantTable[type].description;
	}

	//find branch desc
	if (ability < ARRAY_COUNT(sAbilityToBranchDataTable))
	{
		for(u8 i = 0; i < sAbilityToBranchDataTable[ability].size; ++i)
		{
			if(species == sAbilityToBranchDataTable[ability].data[i].species)
			{
				descStr = sBranchTable[sAbilityToBranchDataTable[ability].data[i].branch].description;
				break;
			}
		}	
	}

	return descStr;
}

const u8* GetAbilityDescription(const u8 ability, unusedArg const u16 species)
{	
	const u8* override = GetAbilityDescriptionOverride(ability, species);
	if (override != NULL)
		return override;

	const u8* desc = gAbilityDescriptions[ability];
	return desc;
}

void CopyAbilityName(u8* dst, const u8 ability, const u16 species)
{
	StringCopy(dst, GetAbilityName(ability, species));
}

void CopyAbilityDescription(u8* dst, const u8 ability, const u16 species)
{
	StringCopy(dst, GetAbilityDescription(ability, species));
}

u16 GetProperAbilityPopUpSpecies(u8 bank)
{
	if (gNewBS->tookAbilityFrom[bank] != SPECIES_NONE)
		return gNewBS->tookAbilityFrom[bank];
	else
		return SPECIES(bank);
}

void SetProperAbilityPopUpSpecies(u8 bank)
{
	gAbilityPopUpSpecies = GetProperAbilityPopUpSpecies(bank);
}

void SetTookAbilityFrom(u8 taker, u8 takenFrom)
{
	if (gNewBS->tookAbilityFrom[takenFrom] != SPECIES_NONE)
		gNewBS->tookAbilityFrom[taker] = gNewBS->tookAbilityFrom[takenFrom]; //Pass along species
	else
		gNewBS->tookAbilityFrom[taker] = SPECIES(takenFrom);
}

void SwapTookAbilityFrom(u8 bank1, u8 bank2)
{
	u16 species1 = GetProperAbilityPopUpSpecies(bank1);
	u16 species2 = GetProperAbilityPopUpSpecies(bank2);

	gNewBS->tookAbilityFrom[bank1] = species2;
	gNewBS->tookAbilityFrom[bank2] = species1;
}

void ResetTookAbilityFrom(u8 bank)
{
	gNewBS->tookAbilityFrom[bank] = SPECIES_NONE;
}

bool8 IsTargetAbilityIgnored(u8 defAbility, u8 atkAbility, u16 move)
{
	return (IS_MOLD_BREAKER(atkAbility, move) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities)
	 || (IS_MYCELIUM_MIGHT(atkAbility, move) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities);
}

bool8 IsTargetAbilityIgnoredNoMove(u8 defAbility, u8 atkAbility)
{
	return (IsMoldBreakerAbility(atkAbility) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities)
	 || (IS_MYCELIUM_MIGHT(atkAbility, gCurrentMove) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities);
}

bool8 SpeciesHasTurboblaze(unusedArg u16 species)
{
	#if (defined SPECIES_RESHIRAM && defined SPECIES_KYUREM_WHITE)
	return species == SPECIES_RESHIRAM
		|| species == SPECIES_KYUREM_WHITE;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasTeravolt(unusedArg u16 species)
{
	#if (defined SPECIES_ZEKROM && defined SPECIES_KYUREM_BLACK)
	return species == SPECIES_ZEKROM
		|| species == SPECIES_KYUREM_BLACK;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasDrillBeak(unusedArg u16 species) //Custom Unbound Ability
{
	#if (defined SPECIES_SPEAROW && defined SPECIES_FEAROW)
	return species == SPECIES_SPEAROW || species == SPECIES_FEAROW;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasGrassDash(unusedArg u16 species) //Custom Unbound Ability
{
	#ifdef SPECIES_SUNFLORA
	return species == SPECIES_SUNFLORA;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasEvaporate(unusedArg u16 species) //Custom Unbound Ability
{
	#ifdef SPECIES_MAGCARGO
	return species == SPECIES_MAGCARGO;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasSlipperyTail(unusedArg u16 species) //Custom Unbound Ability
{
	#ifdef SPECIES_SEVIPER
	return species == SPECIES_SEVIPER;
	#else
	return FALSE;
	#endif
}

bool8 IsClearBodyAbility(u8 ability)
{
	return ability == ABILITY_CLEARBODY;
}

bool8 IsMoldBreakerAbility(u8 ability)
{
	return ability == ABILITY_MOLDBREAKER
		#ifdef ABILITY_TURBOBLAZE
		|| ability == ABILITY_TURBOBLAZE
		#endif
		#ifdef ABILITY_TERAVOLT
		|| ability == ABILITY_TERAVOLT
		#endif
		;
}

bool8 IsMoxieAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITYBRANCH_KO_STAT_BOOST:
		case ABILITY_SOULHEART:
		case ABILITY_BATTLEBOND:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsChoiceAbility(u8 ability)
{
	return ability == ABILITY_GORILLATACTICS;
}

bool8 IsHPAbsorptionAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITYBRANCH_TYPE_ABSORPTION:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsElectricAbsorptionAblity(u8 ability)
{
	switch (ability)
	{
		case ABILITYBRANCH_TYPE_ABSORPTION:
		case ABILITY_MOTORDRIVE:
		case ABILITY_LIGHTNINGROD:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsPlusMinusAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_PLUS:
		case ABILITY_MINUS:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsMultiscaleAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_MULTISCALE:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsPriorityBlockingAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_DAZZLING:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsUnnerveAbility(u8 ability, u16 species)
{
	return ability == ABILITY_UNNERVE
		 || SpeciesHasBranchAbility(species, ability, BRANCH_AS_ONE_GRIM)
		 || SpeciesHasBranchAbility(species, ability, BRANCH_AS_ONE_CHILLING);
}

bool8 UnnerveOnOpposingField(u8 bank)
{
	return ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_UNNERVE)
		|| AS_ONE_CHILLING_ON_OPPOSING_FIELD(bank)
		|| AS_ONE_GRIM_ON_OPPOSING_FIELD(bank);
}

bool8 AbilityIncreasesWildItemChance(u8 ability)
{
	return ability == ABILITY_COMPOUNDEYES || ability == ABILITY_SUPERLUCK;
}

bool8 AbilityBlocksIntimidate(u8 ability)
{
	return ability == ABILITY_INNERFOCUS
		|| ability == ABILITY_OWNTEMPO
		|| ability == ABILITY_OBLIVIOUS
		|| ability == ABILITY_SCRAPPY;
}

bool8 AbilityPreventsLoweringAtk(u8 ability)
{
	return ability == ABILITY_HYPERCUTTER
		|| ability == ABILITY_MIRRORARMOR
		|| IsClearBodyAbility(ability);
}

bool8 AbilityPreventsLoweringStat(u8 ability, u8 statId)
{
	switch (ability)
	{
		case ABILITY_HYPERCUTTER:
			return statId == STAT_STAGE_ATK;
		case ABILITY_BIGPECKS:
			return statId == STAT_STAGE_DEF;
		case ABILITY_KEENEYE:
			return statId == STAT_STAGE_ACC;
		default:
			return FALSE;
	}
}

bool8 AbilityRaisesOneStatWhenSomeStatIsLowered(u8 ability)
{
	return ability == ABILITY_DEFIANT
		|| ability == ABILITY_COMPETITIVE;
}

bool8 IsAffectedBySturdy(u8 defAbility, u8 bankDef)
{
	return defAbility == ABILITY_STURDY
		&& BATTLER_MAX_HP(bankDef);
}

bool8 IsAffectedByDisguse(unusedArg u8 defAbility, unusedArg u16 defSpecies, unusedArg u8 moveSplit)
{
	#ifdef SPECIES_MIMIKYU
	if (defAbility == ABILITY_DISGUISE && defSpecies == SPECIES_MIMIKYU)
		return TRUE;
	#endif
	#ifdef SPECIES_EISCUE
	if (defAbility == ABILITY_ICEFACE && defSpecies == SPECIES_EISCUE && moveSplit == SPLIT_PHYSICAL)
		return TRUE;
	#endif

	return FALSE;
}

bool8 IsAffectedByBadDreams(u8 bank)
{
	return BATTLER_ALIVE(bank)
		&& (gBattleMons[bank].status1 & STATUS_SLEEP
		 || ABILITY(FOE(bank)) == ABILITY_COMATOSE)
		&& ABILITY(bank) != ABILITY_MAGICGUARD;
}

bool8 IsTrappedByAbility(u8 bankDef, u16 branch)
{
	if (!CanBeTrapped(bankDef))
		return FALSE;

	switch (branch)
	{
		case BRANCH_SHADOW_TAG:
			return !BankHasBranchAbility(bankDef, BRANCH_SHADOW_TAG);
		case BRANCH_ARENA_TRAP:
			return CheckGrounding(bankDef) == GROUNDED;
		case BRANCH_MAGNET_PULL:
			return IsOfType(bankDef, TYPE_STEEL);
		default:
			return FALSE;
	}
}


bool8 BankHasEvaporate(u8 bank)
{
	return ABILITY(bank) == ABILITY_EVAPORATE
		&& SpeciesHasEvaporate(GetProperAbilityPopUpSpecies(bank));
}

bool8 BankOnFieldHasEvaporate(void)
{
	for (u32 i = 0; i < gBattlersCount; ++i)
	{
		u8 bank = gBanksByTurnOrder[i];

		if (BATTLER_ALIVE(bank)
		&& BankHasEvaporate(bank)
		&& AffectedByRain(bank))
			return bank + 1;
	}

	return FALSE;
}

bool8 IsBranchAbilityOnTheField(u8 branch)
{
	for (u8 i = 0; i < gBattlersCount; ++i)
	{
		u8 bank = gBanksByTurnOrder[i];

		if (BATTLER_ALIVE(bank) && BankHasBranchAbility(bank, branch))
			return bank + 1;
	}
	return FALSE;
}

u8 GetHighestStatForProtosynthesisQuarkDrive(u8 bank)
{
	u8 maxStatId = STAT_STAGE_ATK;

	//this is the order that those abilities check stats in SV
	u8 statCheckOrder[] = {STAT_STAGE_ATK, STAT_STAGE_DEF, STAT_STAGE_SPATK, STAT_STAGE_SPDEF, STAT_STAGE_SPEED};
    
    u16 stats[STAT_STAGE_SPDEF + 1];
    stats[STAT_STAGE_ATK] = gBattleMons[bank].attack;
    stats[STAT_STAGE_DEF] = gBattleMons[bank].defense;
    stats[STAT_STAGE_SPATK] = gBattleMons[bank].spAttack;
    stats[STAT_STAGE_SPDEF] = gBattleMons[bank].spDefense;
    stats[STAT_STAGE_SPEED] = gBattleMons[bank].speed;

    for(u8 i = 0; i < NELEMS(statCheckOrder); ++i)
    {
        if(stats[statCheckOrder[i]] > stats[maxStatId])
            maxStatId = statCheckOrder[i];
    }

    return maxStatId;
}

u8 GetHighestStatForProtosynthesisQuarkDriveMon(struct Pokemon* mon)
{
	u8 maxStatId = STAT_STAGE_ATK;

	//this is the order that those abilities check stats in SV
	u8 statCheckOrder[] = {STAT_STAGE_ATK, STAT_STAGE_DEF, STAT_STAGE_SPATK, STAT_STAGE_SPDEF, STAT_STAGE_SPEED};
    
    u16 stats[STAT_STAGE_SPDEF + 1];
    stats[STAT_STAGE_ATK] = mon->attack;
    stats[STAT_STAGE_DEF] = mon->defense;
    stats[STAT_STAGE_SPATK] = mon->spAttack;
    stats[STAT_STAGE_SPDEF] = mon->spDefense;
    stats[STAT_STAGE_SPEED] = mon->speed;

    for(u8 i = 0; i < NELEMS(statCheckOrder); ++i)
    {
        if(stats[statCheckOrder[i]] > stats[maxStatId])
            maxStatId = statCheckOrder[i];
    }

    return maxStatId;
}

bool8 BankProtosynthesisQuarkDriveActive(u8 bank)
{
	bool8 protosynthesisActive = (ABILITY(bank) == ABILITY_PROTOSYNTHESIS && WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY));
	bool8 quarkdriveActive = (ABILITY(bank) == ABILITY_QUARKDRIVE && gTerrainType == ELECTRIC_TERRAIN);

	return protosynthesisActive || quarkdriveActive;
}

bool8 MonProtosynthesisQuarkDriveActive(u8 side, struct Pokemon* mon)
{
	u8 ability = GetMonAbilityAfterTrace(mon, FOE(side));
	bool8 protosynthesisActive = (ability == ABILITY_PROTOSYNTHESIS && WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY));
	bool8 quarkdriveActive = (ability == ABILITY_QUARKDRIVE && gTerrainType == ELECTRIC_TERRAIN);

	return protosynthesisActive || quarkdriveActive;
}