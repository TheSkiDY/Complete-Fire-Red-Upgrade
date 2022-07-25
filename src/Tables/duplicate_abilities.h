#pragma once

#include "../config.h"
#include "../../include/new/build_pokemon.h"
#include "../../include/pokemon.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/moves.h"

extern const u8 NAME_SHIELDS_DOWN[];
extern const u8 NAME_ZEN_MODE[];
extern const u8 NAME_ICE_FACE[];
extern const u8 NAME_STANCE_CHANGE[];
extern const u8 NAME_GULP_MISSILE[];
extern const u8 NAME_HUNGER_SWITCH[];
extern const u8 NAME_DISGUISE[];
extern const u8 NAME_SCHOOLING[];
extern const u8 NAME_BATTLE_BOND[];
extern const u8 NAME_POWER_CONSTRUCT[];

extern const u8 DESC_SHIELDSDOWN[];
extern const u8 DESC_ZENMODE[];
extern const u8 DESC_ICEFACE[];
extern const u8 DESC_STANCECHANGE[];
extern const u8 DESC_GULPMISSILE[];
extern const u8 DESC_HUNGERSWITCH[];
extern const u8 DESC_DISGUISE[];
extern const u8 DESC_SCHOOLING[];
extern const u8 DESC_BATTLEBOND[];
extern const u8 DESC_POWERCONSTRUCT[];

extern const u8 NAME_TANGLING_HAIR[];
extern const u8 NAME_GOOEY[];
extern const u8 NAME_AIR_LOCK[];
extern const u8 NAME_SHELL_ARMOR[];
extern const u8 NAME_CHILLING_NEIGH[];
extern const u8 NAME_DAZZLING[];
extern const u8 NAME_QUEENLY_MAJESTY[];
extern const u8 NAME_FULL_METAL_BODY[];
extern const u8 NAME_WIMP_OUT[];
extern const u8 NAME_TURBOBLAZE[];
extern const u8 NAME_TERAVOLT[];
extern const u8 NAME_SOLID_ROCK[];
extern const u8 NAME_PRISM_ARMOR[];
extern const u8 NAME_IRON_BARBS[];
extern const u8 NAME_LIBERO[];
extern const u8 NAME_MAGICIAN[];
extern const u8 NAME_PICKPOCKET[];
extern const u8 NAME_MULTISCALE[];
extern const u8 NAME_SHADOW_SHIELD[];
extern const u8 NAME_POWER_OF_ALCHEMY[];
extern const u8 NAME_PROPELLER_TAIL[];
extern const u8 NAME_CACOPHONY[];
extern const u8 NAME_DUPE_BLAZE[];
extern const u8 NAME_DUPE_TORRENT[];
extern const u8 NAME_DUPE_OVERGROW[];
extern const u8 NAME_DUPE_SWARM[];
extern const u8 NAME_VIRTUE[];
extern const u8 NAME_OVERCHARGE[];
extern const u8 NAME_SNOWFALL[];
extern const u8 NAME_BRAINSTORM[];
extern const u8 NAME_CYCLONE[];
extern const u8 NAME_BIOHAZARD[];
extern const u8 NAME_RAMPAGE[];
extern const u8 NAME_UPHEAVAL[];
extern const u8 NAME_BEDROCK[];
extern const u8 NAME_WRATH[];
extern const u8 NAME_HAUNTED[];
extern const u8 NAME_TEMPER[];
extern const u8 NAME_MYTHIC_RAGE[];
extern const u8 NAME_ENCHANT[];
extern const u8 NAME_NORMAL_AURA[];
extern const u8 NAME_FIGHTING_AURA[];
extern const u8 NAME_FLYING_AURA[];
extern const u8 NAME_POISON_AURA[];
extern const u8 NAME_GROUND_AURA[];
extern const u8 NAME_ROCK_AURA[];
extern const u8 NAME_BUG_AURA[];
extern const u8 NAME_GHOST_AURA[];
extern const u8 NAME_STEEL_AURA[];
extern const u8 NAME_FIRE_AURA[];
extern const u8 NAME_WATER_AURA[];
extern const u8 NAME_GRASS_AURA[];
extern const u8 NAME_ELECTRIC_AURA[];
extern const u8 NAME_PSYCHIC_AURA[];
extern const u8 NAME_ICE_AURA[];
extern const u8 NAME_DRAGON_AURA[];
extern const u8 NAME_DUPE_DARK_AURA[];
extern const u8 NAME_DUPE_FAIRY_AURA[];
extern const u8 NAME_DUPE_FLAME_BODY[];
extern const u8 NAME_DUPE_POISON_POINT[];
extern const u8 NAME_DUPE_STATIC[];
extern const u8 NAME_VOLT_BARRIER[];
extern const u8 NAME_GUARDING_SCALES[];
extern const u8 NAME_GLUEY_FIELD[];
extern const u8 NAME_OPPORTUNIST[];
extern const u8 NAME_ICY_SKIN[];
extern const u8 NAME_FACE_SHIELD[];
extern const u8 NAME_VALIANT_SHIELD[];
extern const u8 NAME_SPIKY_BODY[];
extern const u8 NAME_TIGHT_MASK[];
extern const u8 NAME_BRAINS_SYNERGY[];
extern const u8 NAME_INGROWN[];
extern const u8 NAME_TEMPESTUOUS_SEA[];
extern const u8 NAME_OVERTHINKING[];
extern const u8 NAME_GRIM_NEIGH[];
extern const u8 NAME_SCREECHING_BUZZ[];
extern const u8 NAME_COSMOFORCE[];
extern const u8 NAME_MYSTIC_SHELL[];
extern const u8 NAME_PLACEBO[];
extern const u8 NAME_ADEQUATE[];
extern const u8 NAME_VIOLENT_DRUMS[];
extern const u8 NAME_SOAKAGE[];
extern const u8 NAME_SONIC_FORCE[];
extern const u8 NAME_HONEY_ARMOR[];

extern const u8 DESC_DUPE_BLAZE[];
extern const u8 DESC_DUPE_TORRENT[];
extern const u8 DESC_DUPE_SWARM[];
extern const u8 DESC_DUPE_OVERGROW[];
extern const u8 DESC_VIRTUE[];
extern const u8 DESC_OVERCHARGE[];
extern const u8 DESC_SNOWFALL[];
extern const u8 DESC_BRAINSTORM[];
extern const u8 DESC_CYCLONE[];
extern const u8 DESC_BIOHAZARD[];
extern const u8 DESC_RAMPAGE[];
extern const u8 DESC_UPHEAVAL[];
extern const u8 DESC_BEDROCK[];
extern const u8 DESC_WRATH[];
extern const u8 DESC_HAUNTED[];
extern const u8 DESC_TEMPER[];
extern const u8 DESC_MYTHIC_RAGE[];
extern const u8 DESC_ENCHANT[];
extern const u8 DESC_NORMAL_AURA[];
extern const u8 DESC_FIGHTING_AURA[];
extern const u8 DESC_FLYING_AURA[];
extern const u8 DESC_POISON_AURA[];
extern const u8 DESC_GROUND_AURA[];
extern const u8 DESC_ROCK_AURA[];
extern const u8 DESC_BUG_AURA[];
extern const u8 DESC_GHOST_AURA[];
extern const u8 DESC_STEEL_AURA[];
extern const u8 DESC_FIRE_AURA[];
extern const u8 DESC_WATER_AURA[];
extern const u8 DESC_GRASS_AURA[];
extern const u8 DESC_ELECTRIC_AURA[];
extern const u8 DESC_PSYCHIC_AURA[];
extern const u8 DESC_ICE_AURA[];
extern const u8 DESC_DRAGON_AURA[];
extern const u8 DESC_DUPE_DARK_AURA[];
extern const u8 DESC_DUPE_FAIRY_AURA[];
extern const u8 DESC_OVERTHINKING[];

extern const u8 NAME_WARFARE[];
extern const u8 NAME_DUPE_AERILATE[];
extern const u8 NAME_TOXINATE[];
extern const u8 NAME_EARTHBOUND[];
extern const u8 NAME_CRAGITATE[];
extern const u8 NAME_INFECTATE[];
extern const u8 NAME_CHANNELING[];
extern const u8 NAME_FORTIFIED[];
extern const u8 NAME_EMPYREAL[];
extern const u8 NAME_HYDRATE[];
extern const u8 NAME_NATURALIZE[];
extern const u8 NAME_DUPE_GALVANIZE[];
extern const u8 NAME_COGNITIVE[];
extern const u8 NAME_DUPE_REFRIGERATE[];
extern const u8 NAME_WYVERNATE[];
extern const u8 NAME_ANTAGONIZE[];
extern const u8 NAME_DUPE_PIXILATE[];

extern const u8 DESC_WARFARE[];
extern const u8 DESC_DUPE_AERILATE[];
extern const u8 DESC_TOXINATE[];
extern const u8 DESC_EARTHBOUND[];
extern const u8 DESC_CRAGITATE[];
extern const u8 DESC_INFECTATE[];
extern const u8 DESC_CHANNELING[];
extern const u8 DESC_FORTIFIED[];
extern const u8 DESC_EMPYREAL[];
extern const u8 DESC_HYDRATE[];
extern const u8 DESC_NATURALIZE[];
extern const u8 DESC_DUPE_GALVANIZE[];
extern const u8 DESC_COGNITIVE[];
extern const u8 DESC_DUPE_REFRIGERATE[];
extern const u8 DESC_WYVERNATE[];
extern const u8 DESC_ANTAGONIZE[];
extern const u8 DESC_DUPE_PIXILATE[];

extern const u8 NAME_DUPE_ELECTRIC_SURGE[];
extern const u8 NAME_DUPE_MISTY_SURGE[];
extern const u8 NAME_DUPE_PSYCHIC_SURGE[];
extern const u8 NAME_DUPE_GRASSY_SURGE[];
extern const u8 NAME_SHADOWY_SURGE[];
extern const u8 NAME_DRACO_SURGE[];

extern const u8 DESC_ELECTRIC_SURGE[];
extern const u8 DESC_MISTY_SURGE[];
extern const u8 DESC_PSYCHIC_SURGE[];
extern const u8 DESC_GRASSY_SURGE[];
extern const u8 DESC_SHADOWY_SURGE[];
extern const u8 DESC_DRACO_SURGE[];

extern const u8 NAME_DUPE_GALE_WINGS[];
extern const u8 NAME_SHADOW_BOOST[];
extern const u8 DESC_GALE_WINGS[];
extern const u8 DESC_SHADOW_BOOST[];

static const u8* gAteAbilityNames[] =
{
    [0] = 0,
    [TYPE_FIGHTING] = NAME_WARFARE,
    [TYPE_FLYING] = NAME_DUPE_AERILATE,
    [TYPE_POISON] = NAME_TOXINATE,
    [TYPE_GROUND] = NAME_EARTHBOUND,
    [TYPE_ROCK] = NAME_CRAGITATE,
    [TYPE_BUG] = NAME_INFECTATE,
    [TYPE_GHOST] = NAME_CHANNELING,
    [TYPE_STEEL] = NAME_FORTIFIED,
    [TYPE_FIRE] = NAME_EMPYREAL,
    [TYPE_WATER] = NAME_HYDRATE,
    [TYPE_GRASS] = NAME_NATURALIZE,
    [TYPE_ELECTRIC] = NAME_DUPE_GALVANIZE,
    [TYPE_PSYCHIC] = NAME_COGNITIVE,
    [TYPE_ICE] = NAME_DUPE_REFRIGERATE,
    [TYPE_DRAGON] = NAME_WYVERNATE,
    [TYPE_DARK] = NAME_ANTAGONIZE,
    [TYPE_FAIRY] = NAME_DUPE_PIXILATE,
};

static const u8* gAteAbilityDescriptions[] =
{
    [0] = 0,
    [TYPE_FIGHTING] = DESC_WARFARE,
    [TYPE_FLYING] = DESC_DUPE_AERILATE,
    [TYPE_POISON] = DESC_TOXINATE,
    [TYPE_GROUND] = DESC_EARTHBOUND,
    [TYPE_ROCK] = DESC_CRAGITATE,
    [TYPE_BUG] = DESC_INFECTATE,
    [TYPE_GHOST] = DESC_CHANNELING,
    [TYPE_STEEL] = DESC_FORTIFIED,
    [TYPE_FIRE] = DESC_EMPYREAL,
    [TYPE_WATER] = DESC_HYDRATE,
    [TYPE_GRASS] = DESC_NATURALIZE,
    [TYPE_ELECTRIC] = DESC_DUPE_GALVANIZE,
    [TYPE_PSYCHIC] = DESC_COGNITIVE,
    [TYPE_ICE] = DESC_DUPE_REFRIGERATE,
    [TYPE_DRAGON] = DESC_WYVERNATE,
    [TYPE_DARK] = DESC_ANTAGONIZE,
    [TYPE_FAIRY] = DESC_DUPE_PIXILATE,
};

static const u8* gBlazeAbilityNames[] =
{
    [TYPE_NORMAL] = NAME_VIRTUE,
    [TYPE_FIGHTING] = NAME_RAMPAGE,
    [TYPE_FLYING] = NAME_CYCLONE,
    [TYPE_POISON] = NAME_BIOHAZARD,
    [TYPE_GROUND] = NAME_UPHEAVAL,
    [TYPE_ROCK] = NAME_BEDROCK,
    [TYPE_BUG] = NAME_DUPE_SWARM,
    [TYPE_GHOST] = NAME_HAUNTED,
    [TYPE_STEEL] = NAME_TEMPER,
    [TYPE_FIRE] = NAME_DUPE_BLAZE,
    [TYPE_WATER] = NAME_DUPE_TORRENT,
    [TYPE_GRASS] = NAME_DUPE_OVERGROW,
    [TYPE_ELECTRIC] = NAME_OVERCHARGE,
    [TYPE_PSYCHIC] = NAME_BRAINSTORM,
    [TYPE_ICE] = NAME_SNOWFALL,
    [TYPE_DRAGON] = NAME_MYTHIC_RAGE,
    [TYPE_DARK] = NAME_WRATH,
    [TYPE_FAIRY] = NAME_ENCHANT,
};

static const u8* gBlazeAbilityDescriptions[] =
{
    [TYPE_NORMAL] = DESC_VIRTUE,
    [TYPE_FIGHTING] = DESC_RAMPAGE,
    [TYPE_FLYING] = DESC_CYCLONE,
    [TYPE_POISON] = DESC_BIOHAZARD,
    [TYPE_GROUND] = DESC_UPHEAVAL,
    [TYPE_ROCK] = DESC_BEDROCK,
    [TYPE_BUG] = DESC_DUPE_SWARM,
    [TYPE_GHOST] = DESC_HAUNTED,
    [TYPE_STEEL] = DESC_TEMPER,
    [TYPE_FIRE] = DESC_DUPE_BLAZE,
    [TYPE_WATER] = DESC_DUPE_TORRENT,
    [TYPE_GRASS] = DESC_DUPE_OVERGROW,
    [TYPE_ELECTRIC] = DESC_OVERCHARGE,
    [TYPE_PSYCHIC] = DESC_BRAINSTORM,
    [TYPE_ICE] = DESC_SNOWFALL,
    [TYPE_DRAGON] = DESC_MYTHIC_RAGE,
    [TYPE_DARK] = DESC_WRATH,
    [TYPE_FAIRY] = DESC_ENCHANT,
};

static const u8* gAuraAbilityNames[] =
{
    [TYPE_NORMAL] = NAME_NORMAL_AURA,
    [TYPE_FIGHTING] = NAME_FIGHTING_AURA,
    [TYPE_FLYING] = NAME_FLYING_AURA,
    [TYPE_POISON] = NAME_POISON_AURA,
    [TYPE_GROUND] = NAME_GROUND_AURA,
    [TYPE_ROCK] = NAME_ROCK_AURA,
    [TYPE_BUG] = NAME_BUG_AURA,
    [TYPE_GHOST] = NAME_GHOST_AURA,
    [TYPE_STEEL] = NAME_STEEL_AURA,
    [TYPE_FIRE] = NAME_FIRE_AURA,
    [TYPE_WATER] = NAME_WATER_AURA,
    [TYPE_GRASS] = NAME_GRASS_AURA,
    [TYPE_ELECTRIC] = NAME_ELECTRIC_AURA,
    [TYPE_PSYCHIC] = NAME_PSYCHIC_AURA,
    [TYPE_ICE] = NAME_ICE_AURA,
    [TYPE_DRAGON] = NAME_DRAGON_AURA,
    [TYPE_DARK] = NAME_DUPE_DARK_AURA,
    [TYPE_FAIRY] = NAME_DUPE_FAIRY_AURA,
};

static const u8* gAuraAbilityDescriptions[] =
{
    [TYPE_NORMAL] = DESC_NORMAL_AURA,
    [TYPE_FIGHTING] = DESC_FIGHTING_AURA,
    [TYPE_FLYING] = DESC_FLYING_AURA,
    [TYPE_POISON] = DESC_POISON_AURA,
    [TYPE_GROUND] = DESC_GROUND_AURA,
    [TYPE_ROCK] = DESC_ROCK_AURA,
    [TYPE_BUG] = DESC_BUG_AURA,
    [TYPE_GHOST] = DESC_GHOST_AURA,
    [TYPE_STEEL] = DESC_STEEL_AURA,
    [TYPE_FIRE] = DESC_FIRE_AURA,
    [TYPE_WATER] = DESC_WATER_AURA,
    [TYPE_GRASS] = DESC_GRASS_AURA,
    [TYPE_ELECTRIC] = DESC_ELECTRIC_AURA,
    [TYPE_PSYCHIC] = DESC_PSYCHIC_AURA,
    [TYPE_ICE] = DESC_ICE_AURA,
    [TYPE_DRAGON] = DESC_DRAGON_AURA,
    [TYPE_DARK] = DESC_DUPE_DARK_AURA,
    [TYPE_FAIRY] = DESC_DUPE_FAIRY_AURA,
};

static const u8* gSurgeAbilityNames[] = 
{
    [0] = 0,
    [ELECTRIC_TERRAIN] = NAME_DUPE_ELECTRIC_SURGE,
    [MISTY_TERRAIN] = NAME_DUPE_MISTY_SURGE,
    [PSYCHIC_TERRAIN] = NAME_DUPE_PSYCHIC_SURGE,
    [GRASSY_TERRAIN] = NAME_DUPE_GRASSY_SURGE,
    [SHADOW_TERRAIN] = NAME_SHADOWY_SURGE,
    [DRACO_TERRAIN] = NAME_DRACO_SURGE,
};

static const u8* gSurgeAbilityDescriptions[] = 
{
    [0] = 0,
    [ELECTRIC_TERRAIN] = DESC_ELECTRIC_SURGE,
    [MISTY_TERRAIN] = DESC_MISTY_SURGE,
    [PSYCHIC_TERRAIN] = DESC_PSYCHIC_SURGE,
    [GRASSY_TERRAIN] = DESC_GRASSY_SURGE,
    [SHADOW_TERRAIN] = DESC_SHADOWY_SURGE,
    [DRACO_TERRAIN] = DESC_DRACO_SURGE,
};

static const u8* gPriorityAbilityNames[] = 
{
    [0] = 0,
    [TYPE_FLYING] = NAME_DUPE_GALE_WINGS,
    [TYPE_GHOST] = NAME_SHADOW_BOOST,
};

static const u8* gPriorityAbilityDescriptions[] = 
{
    [0] = 0,
    [TYPE_FLYING] = DESC_GALE_WINGS,
    [TYPE_GHOST] = DESC_SHADOW_BOOST,
};

static struct TerrainBasedAbility sSurgeAbilities[] = 
{
    //electric terrain
    {
        .species = SPECIES_TAPU_KOKO,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = ELECTRIC_TERRAIN,
    },
    {
        .species = SPECIES_PINCURCHIN,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = ELECTRIC_TERRAIN,
    },
    {
        .species = SPECIES_ZERAORA,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = ELECTRIC_TERRAIN,
    },
    //misty terrain
    {
        .species = SPECIES_TAPU_FINI,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = MISTY_TERRAIN,
    },
    {
        .species = SPECIES_WEEZING_G,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = MISTY_TERRAIN,
    },
    {
        .species = SPECIES_SYLVEON,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = MISTY_TERRAIN,
    },
    //psychic terrain
    {
        .species = SPECIES_TAPU_LELE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = PSYCHIC_TERRAIN,
    },
    {
        .species = SPECIES_ESPEON,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = PSYCHIC_TERRAIN,
    },
    {
        .species = SPECIES_INDEEDEE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = PSYCHIC_TERRAIN,
    },
    {
        .species = SPECIES_INDEEDEE_FEMALE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = PSYCHIC_TERRAIN,
    },
    //grassy terrain
    {
        .species = SPECIES_TAPU_BULU,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_PANSAGE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_SIMISAGE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_GROOKEY,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_THWACKEY,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_RILLABOOM,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    {
        .species = SPECIES_RILLABOOM_GIGA,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = GRASSY_TERRAIN,
    },
    //shadow terrain
    {

    },
    //draco terrain
    {
        .species = SPECIES_KYUREM,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = DRACO_TERRAIN,
    },
    {
        .species = SPECIES_KYUREM_BLACK,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = DRACO_TERRAIN,
    },
    {
        .species = SPECIES_KYUREM_WHITE,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = DRACO_TERRAIN,
    },
    {
        .species = SPECIES_LATIOS,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = DRACO_TERRAIN,
    },
    {
        .species = SPECIES_LATIAS,
        .currAbility = ABILITY_TERRAIN_SURGE,
        .terrain = DRACO_TERRAIN,
    },
};

static struct TypeBasedAbility sPriorityAbilities[] = 
{
    {
        .species = SPECIES_HOOTHOOT,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_NOCTOWL,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_FLETCHLING,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_FLETCHINDER,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_TALONFLAME,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_HOOTHOOT,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_DECIDUEYE,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_HONEDGE,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_DOUBLADE,
        .currAbility = ABILITY_GALEWINGS,
        .type = TYPE_GHOST,
    },
};

static struct TypeBasedAbility sAteAbilities[] = 
{
    //Fighting
    {
        .species = SPECIES_FARFETCHD_G,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIGHTING,
    },
    {
        .species = SPECIES_SIRFETCHD,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIGHTING,
    },
    {
        .species = SPECIES_FALINKS,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIGHTING,
    },
    //Flying
    {
        .species = SPECIES_SALAMENCE_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FLYING,
    },
    {
        .species = SPECIES_PINSIR_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FLYING,
    },
    //Poison
    {
        .species = SPECIES_STUNKY,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_POISON,
    },
    {
        .species = SPECIES_SKUNTANK,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_POISON,
    },
    {
        .species = SPECIES_CROAGUNK,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_POISON,
    },
    {
        .species = SPECIES_TOXICROAK,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_POISON,
    },
    //Ground
    {
        .species = SPECIES_CUBONE,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GROUND,
    },
    {
        .species = SPECIES_MAROWAK,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GROUND,
    },
    {
        .species = SPECIES_VIBRAVA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GROUND,
    },
    {
        .species = SPECIES_FLYGON,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GROUND,
    },
    {
        .species = SPECIES_DONPHAN,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GROUND,
    },
    //Rock
    {
        .species = SPECIES_STONJOURNER,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ROCK,
    },
    {
        .species = SPECIES_ANORITH,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ROCK,
    },
    {
        .species = SPECIES_ARMALDO,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ROCK,
    },
    {
        .species = SPECIES_TYRANITAR_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ROCK,
    },
    //Bug
    {
        .species = SPECIES_BUTTERFREE,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_PARAS,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_PARASECT,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_SEWADDLE,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_SWADLOON,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_LEAVANNY,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    {
        .species = SPECIES_MOTHIM,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_BUG,
    },
    //Ghost
    {
        .species = SPECIES_GASTLY,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_HAUNTER,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_GENGAR,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_SHUPPET,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GHOST,
    },
    {
        .species = SPECIES_BANETTE,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GHOST,
    },
    //Steel
    {
        .species = SPECIES_FORRETRESS,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_STEEL,
    },
    {
        .species = SPECIES_FERROSEED,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_STEEL,
    },
    {
        .species = SPECIES_FERROTHORN,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_STEEL,
    },
    {
        .species = SPECIES_PAWNIARD,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_STEEL,
    },
    {
        .species = SPECIES_BISHARP,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_STEEL,
    },
    //Fire
    {
        .species = SPECIES_FLETCHLING,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIRE,
    },
    {
        .species = SPECIES_FLETCHINDER,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIRE,
    },
    {
        .species = SPECIES_TALONFLAME,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FIRE,
    },
    //Water
    {
        .species = SPECIES_PHIONE,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_WATER,
    },
    {
        .species = SPECIES_MANAPHY,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_WATER,
    },
    {
        .species = SPECIES_CLAUNCHER,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_WATER,
    },
    {
        .species = SPECIES_CLAWITZER,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_WATER,
    },
    //Grass
    {
        .species = SPECIES_LILEEP,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    {
        .species = SPECIES_CRADILY,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    {
        .species = SPECIES_ROWLET,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    {
        .species = SPECIES_DARTRIX,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    {
        .species = SPECIES_SKIDDO,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    {
        .species = SPECIES_GOGOAT,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_GRASS,
    },
    //Electric
    {
        .species = SPECIES_GEODUDE_A,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ELECTRIC,
    },
    {
        .species = SPECIES_GRAVELER_A,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ELECTRIC,
    },
    {
        .species = SPECIES_GOLEM_A,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ELECTRIC,
    },
    //Psychic
    {
        .species = SPECIES_MEWTWO,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_PSYCHIC,
    },
    {
        .species = SPECIES_SPOINK,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_PSYCHIC,
    },
    {
        .species = SPECIES_GRUMPIG,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_PSYCHIC,
    },
    {
        .species = SPECIES_CHINGLING,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_PSYCHIC,
    },
    {
        .species = SPECIES_CHIMECHO,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_PSYCHIC,
    },
    //Ice
    {
        .species = SPECIES_GLALIE_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ICE,
    },
    {
        .species = SPECIES_AMAURA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ICE,
    },
    {
        .species = SPECIES_AURORUS,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_ICE,
    },
    //Dragon
    {
        .species = SPECIES_RAYQUAZA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_DRAGON,
    },
    {
        .species = SPECIES_NOIBAT,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_DRAGON,
    },
    {
        .species = SPECIES_NOIVERN,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_DRAGON,
    },
    //Dark
    {
        0
    },
    //Fairy
    {
        .species = SPECIES_GARDEVOIR_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FAIRY,
    },
    {
        .species = SPECIES_ALTARIA_MEGA,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FAIRY,
    },
    {
        .species = SPECIES_SYLVEON,
        .currAbility = ABILITY_ATE_LIKE,
        .type = TYPE_FAIRY,
    },

};

static struct DuplicateAbility sDuplicateDescriptions[] =
{
     {
        .species = SPECIES_DARMANITAN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ZENMODE,
    },
    {
        .species = SPECIES_DARMANITANZEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ZENMODE,
    },
    {
        .species = SPECIES_DARMANITAN_G,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ZENMODE,
    },
    {
        .species = SPECIES_DARMANITAN_G_ZEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ZENMODE,
    },
    {
        .species = SPECIES_AEGISLASH,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_STANCECHANGE,
    },
    {
        .species = SPECIES_AEGISLASH_BLADE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_STANCECHANGE,
    },
    {
        .species = SPECIES_WISHIWASHI,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SCHOOLING,
    },
    {
        .species = SPECIES_WISHIWASHI_S,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SCHOOLING,
    },
    {
        .species = SPECIES_MINIOR_SHIELD,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_RED,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_BLUE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_ORANGE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_YELLOW,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_INDIGO,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_GREEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MINIOR_VIOLET,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_SHIELDSDOWN,
    },
    {
        .species = SPECIES_MIMIKYU,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_DISGUISE,
    },
    {
        .species = SPECIES_MIMIKYU_BUSTED,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_DISGUISE,
    },
    {
        .species = SPECIES_GRENINJA,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_BATTLEBOND,
    },
    {
        .species = SPECIES_ASHGRENINJA,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_BATTLEBOND,
    },
    {
        .species = SPECIES_ZYGARDE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_POWERCONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE_10,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_POWERCONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE_COMPLETE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_POWERCONSTRUCT,
    },
    {
        .species = SPECIES_EISCUE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ICEFACE,
    },
    {
        .species = SPECIES_EISCUE_NOICE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_ICEFACE,
    },
    {
        .species = SPECIES_MORPEKO,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_HUNGERSWITCH,
    },
    {
        .species = SPECIES_MORPEKO_HANGRY,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_HUNGERSWITCH,
    },
    {
        .species = SPECIES_CRAMORANT,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_GULPMISSILE,
    },
    {
        .species = SPECIES_CRAMORANT_GULPING,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_GULPMISSILE,
    },
    {
        .species = SPECIES_CRAMORANT_GORGING,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = DESC_GULPMISSILE,
    },
};

static struct DuplicateAbility sDuplicateAbilities[] =
{
    {
        .species = SPECIES_DIGLETT_A,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_TANGLING_HAIR, 
    },
    {
        .species = SPECIES_DUGTRIO_A,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_TANGLING_HAIR, 
    },
    {
        .species = SPECIES_GOOMY,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_GOOEY, 
    },
    {
        .species = SPECIES_SLIGGOO,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_GOOEY, 
    },
    {
        .species = SPECIES_GOODRA,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_GOOEY, 
    },
    {
        .species = SPECIES_SLIGGOO_H,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_GOOEY, 
    },
    {
        .species = SPECIES_GOODRA_H,
        .currAbility = ABILITY_STUN_TOUCH, 
        .replaceAbilityString = NAME_GOOEY, 
    },
    {
        .species = SPECIES_AERODACTYL,
        .currAbility = ABILITY_CLOUDNINE, 
        .replaceAbilityString = NAME_AIR_LOCK, 
    },
    {
        .species = SPECIES_DELIBIRD,
        .currAbility = ABILITY_CLOUDNINE, 
        .replaceAbilityString = NAME_AIR_LOCK, 
    },
    {
        .species = SPECIES_RAYQUAZA,
        .currAbility = ABILITY_CLOUDNINE, 
        .replaceAbilityString = NAME_AIR_LOCK, 
    },
    {
        .species = SPECIES_SQUIRTLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_WARTORTLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_BLASTOISE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_SLOWBRO_MEGA,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_SHELLDER,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CLOYSTER,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_KRABBY,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_KINGLER,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_LAPRAS,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_OMANYTE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_OMASTAR,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CORPHISH,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CRAWDAUNT,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CLAMPERL,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_DWEBBLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CRUSTLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_ESCAVALIER,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_SHELMET,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_TURTONATOR,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_CHEWTLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_DREDNAW,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_TORKOAL,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_TURTWIG,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_GROTLE,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_TORTERRA,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_OSHAWOTT,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_DEWOTT,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_SAMUROTT,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_SAMUROTT_H,
        .currAbility = ABILITY_BATTLEARMOR, 
        .replaceAbilityString = NAME_SHELL_ARMOR, 
    },
    {
        .species = SPECIES_GLASTRIER,
        .currAbility = ABILITY_MOXIE, 
        .replaceAbilityString = NAME_CHILLING_NEIGH, 
    },
    {
        .species = SPECIES_CALYREX_ICE,
        .currAbility = ABILITY_MOXIE, 
        .replaceAbilityString = NAME_CHILLING_NEIGH, 
    },
    {
        .species = SPECIES_BRUXISH,
        .currAbility = ABILITY_MAJESTIC, 
        .replaceAbilityString = NAME_DAZZLING, 
    },
    {
        .species = SPECIES_TSAREENA,
        .currAbility = ABILITY_MAJESTIC, 
        .replaceAbilityString = NAME_QUEENLY_MAJESTY, 
    },
    {
        .species = SPECIES_SOLGALEO,
        .currAbility = ABILITY_CLEARBODY, 
        .replaceAbilityString = NAME_FULL_METAL_BODY, 
    },
    {
        .species = SPECIES_WIMPOD,
        .currAbility = ABILITY_EMERGENCYEXIT, 
        .replaceAbilityString = NAME_WIMP_OUT, 
    },
    {
        .species = SPECIES_SURSKIT,
        .currAbility = ABILITY_EMERGENCYEXIT,
        .replaceAbilityString = NAME_WIMP_OUT,
    },
    {
        .species = SPECIES_KYUREM_WHITE,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TURBOBLAZE, 
    },
    {
        .species = SPECIES_RESHIRAM,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TURBOBLAZE, 
    },
    {
        .species = SPECIES_FENNEKIN,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TURBOBLAZE, 
    },
    {
        .species = SPECIES_BRAIXEN,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TURBOBLAZE, 
    },
    {
        .species = SPECIES_KYUREM_BLACK,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TERAVOLT, 
    },
    {
        .species = SPECIES_ZEKROM,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TERAVOLT, 
    },
    {
        .species = SPECIES_GRUBBIN,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TERAVOLT, 
    },
    {
        .species = SPECIES_CHARJABUG,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TERAVOLT, 
    },
    {
        .species = SPECIES_VIKAVOLT,
        .currAbility = ABILITY_MOLDBREAKER, 
        .replaceAbilityString = NAME_TERAVOLT, 
    },
    {
        .species = SPECIES_CAMERUPT,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_SOLID_ROCK, 
    },
    {
        .species = SPECIES_RHYPERIOR,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_SOLID_ROCK, 
    },
    {
        .species = SPECIES_TIRTOUGA,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_SOLID_ROCK, 
    },
    {
        .species = SPECIES_CARRACOSTA,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_SOLID_ROCK, 
    },
    {
        .species = SPECIES_PUPITAR,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_SOLID_ROCK, 
    },
    {
        .species = SPECIES_NECROZMA,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_PRISM_ARMOR, 
    },
    {
        .species = SPECIES_NECROZMA_DUSK_MANE,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_PRISM_ARMOR, 
    },
    {
        .species = SPECIES_NECROZMA_DAWN_WINGS,
        .currAbility = ABILITY_FILTER, 
        .replaceAbilityString = NAME_PRISM_ARMOR, 
    },
    {
        .species = SPECIES_EKANS,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_GUARDING_SCALES,
    },
    {
        .species = SPECIES_ARBOK,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_GUARDING_SCALES,
    },
    {
        .species = SPECIES_FERROSEED,
        .currAbility = ABILITY_ROUGHSKIN, 
        .replaceAbilityString = NAME_IRON_BARBS, 
    },
    {
        .species = SPECIES_FERROTHORN,
        .currAbility = ABILITY_ROUGHSKIN, 
        .replaceAbilityString = NAME_IRON_BARBS, 
    },
    {
        .species = SPECIES_TOGEDEMARU,
        .currAbility = ABILITY_ROUGHSKIN, 
        .replaceAbilityString = NAME_IRON_BARBS, 
    },
    {
        .species = SPECIES_SCORBUNNY,
        .currAbility = ABILITY_PROTEAN, 
        .replaceAbilityString = NAME_LIBERO, 
    },
    {
        .species = SPECIES_RABOOT,
        .currAbility = ABILITY_PROTEAN, 
        .replaceAbilityString = NAME_LIBERO, 
    },
    {
        .species = SPECIES_CINDERACE,
        .currAbility = ABILITY_PROTEAN, 
        .replaceAbilityString = NAME_LIBERO, 
    },
    {
        .species = SPECIES_HOOPA,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_HOOPA_UNBOUND,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_FENNEKIN,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_BRAIXEN,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_DELPHOX,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_KLEFKI,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_MAGICIAN, 
    },
    {
        .species = SPECIES_SNEASEL,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_SEEDOT,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_NUZLEAF,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_SHIFTRY,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_WEAVILE,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_BINACLE,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_BARBARACLE,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_IMPIDIMP,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_MORGREM,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_GRIMMSNARL,
        .currAbility = ABILITY_PLUNDER, 
        .replaceAbilityString = NAME_PICKPOCKET, 
    },
    {
        .species = SPECIES_DRAGONITE,
        .currAbility = ABILITY_MYTHICALSHIELD, 
        .replaceAbilityString = NAME_MULTISCALE, 
    },
    {
        .species = SPECIES_LUGIA,
        .currAbility = ABILITY_MYTHICALSHIELD, 
        .replaceAbilityString = NAME_MULTISCALE, 
    },
    {
        .species = SPECIES_LUNALA,
        .currAbility = ABILITY_MYTHICALSHIELD, 
        .replaceAbilityString = NAME_SHADOW_SHIELD, 
    },
    {
        .species = SPECIES_CLAMPERL,
        .currAbility = ABILITY_MYTHICALSHIELD, 
        .replaceAbilityString = NAME_MYSTIC_SHELL, 
    },
    {
        .species = SPECIES_GRIMER_A,
        .currAbility = ABILITY_RECEIVER, 
        .replaceAbilityString = NAME_POWER_OF_ALCHEMY, 
    },
    {
        .species = SPECIES_MUK_A,
        .currAbility = ABILITY_RECEIVER, 
        .replaceAbilityString = NAME_POWER_OF_ALCHEMY, 
    },
    {
        .species = SPECIES_ARROKUDA,
        .currAbility = ABILITY_STALWART, 
        .replaceAbilityString = NAME_PROPELLER_TAIL, 
    },
    {
        .species = SPECIES_BARRASKEWDA,
        .currAbility = ABILITY_STALWART, 
        .replaceAbilityString = NAME_PROPELLER_TAIL, 
    },
    {
        .species = SPECIES_WHISMUR,
        .currAbility = ABILITY_SOUNDPROOF, 
        .replaceAbilityString = NAME_CACOPHONY, 
    },
    {
        .species = SPECIES_LOUDRED,
        .currAbility = ABILITY_SOUNDPROOF, 
        .replaceAbilityString = NAME_CACOPHONY, 
    },
    {
        .species = SPECIES_EXPLOUD,
        .currAbility = ABILITY_SOUNDPROOF, 
        .replaceAbilityString = NAME_CACOPHONY, 
    },
    {
        .species = SPECIES_KRICKETUNE,
        .currAbility = ABILITY_SOUNDPROOF, 
        .replaceAbilityString = NAME_CACOPHONY, 
    },
    {
        .species = SPECIES_KRICKETOT,
        .currAbility = ABILITY_SOUNDPROOF, 
        .replaceAbilityString = NAME_CACOPHONY, 
    },
    {
        .species = SPECIES_AMPHAROS,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_STUNFISK,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_RAICHU_A,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_FAN,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_MOW,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_HEAT,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_FROST,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_WASH,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityString = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_GRIMER,
        .currAbility = ABILITY_ARENATRAP,
        .replaceAbilityString = NAME_GLUEY_FIELD,
    },
    {
        .species = SPECIES_MUK,
        .currAbility = ABILITY_ARENATRAP,
        .replaceAbilityString = NAME_GLUEY_FIELD,
    },
    {
        .species = SPECIES_SPINDA,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_VESPIQUEN,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY_SANDY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY_TRASH,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM_SANDY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM_TRASH,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_TYNAMO,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_EELEKTRIK,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_EELEKTROSS,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityString = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_GLACEON,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityString = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SANDSHREW_A,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityString = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SANDSLASH_A,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityString = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_JYNX,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityString = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SHIELDON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FACE_SHIELD,
    },
    {
        .species = SPECIES_BASTIODON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FACE_SHIELD,
    },
    {
        .species = SPECIES_CORVIKNIGHT,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_VALIANT_SHIELD,
    },
    {
        .species = SPECIES_TYPE_NULL,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_VALIANT_SHIELD,
    },
    {
        .species = SPECIES_SHELGON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_VALIANT_SHIELD,
    },
    {
        .species = SPECIES_VESPIQUEN,
        .currAbility = ABILITY_FLUFFY,
        .replaceAbilityString = NAME_HONEY_ARMOR,
    },
    {
        .species = SPECIES_CACNEA,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_CACTURNE,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_ROSELIA,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_ROSERADE,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_MARACTUS,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_CUBONE,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityString = NAME_TIGHT_MASK,
    },
    {
        .species = SPECIES_MAROWAK,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityString = NAME_TIGHT_MASK,
    },
    {
        .species = SPECIES_MAROWAK_A,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityString = NAME_TIGHT_MASK,
    },
    {
        .species = SPECIES_GIRAFARIG,
        .currAbility = ABILITY_PARENTALBOND,
        .replaceAbilityString = NAME_BRAINS_SYNERGY,
    },
    {
        .species = SPECIES_PHANTUMP,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_TREVENANT,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_EXEGGUTOR_A,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_TURTWIG,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_GROTLE,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_TORTERRA,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityString = NAME_INGROWN,
    },
    {
        .species = SPECIES_DUCKLETT,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_SWANNA,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_SOBBLE,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_DRIZZILE,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_INTELEON,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_INTELEON_GIGA,
        .currAbility = ABILITY_SPEEDBOOST,
        .replaceAbilityString = NAME_TEMPESTUOUS_SEA,
    },
    {
        .species = SPECIES_SPECTRIER,
        .currAbility = ABILITY_CONFIDENCE,
        .replaceAbilityString = NAME_GRIM_NEIGH,
    },
    { 
        .species = SPECIES_YANMA,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_SCREECHING_BUZZ,
    },
    {
        .species = SPECIES_YANMEGA,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_SCREECHING_BUZZ,
    },
    {
        .species = SPECIES_VENOMOTH,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_SCREECHING_BUZZ,
    },
    {
        .species = SPECIES_TAILLOW,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_SONIC_FORCE,
    },
    {
        .species = SPECIES_SWELLOW,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_SONIC_FORCE,
    },
    {
        .species = SPECIES_GROOKEY,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_THWACKEY,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_RILLABOOM,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_LUNATONE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_SOLROCK,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_STARYU,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_STARMIE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_ATTACK,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_DEFENSE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_SPEED,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityString = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DARMANITAN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ZEN_MODE,
    },
    {
        .species = SPECIES_DARMANITANZEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ZEN_MODE,
    },
    {
        .species = SPECIES_DARMANITAN_G,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ZEN_MODE,
    },
    {
        .species = SPECIES_DARMANITAN_G_ZEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ZEN_MODE,
    },
    {
        .species = SPECIES_AEGISLASH,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_STANCE_CHANGE,
    },
    {
        .species = SPECIES_AEGISLASH_BLADE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_STANCE_CHANGE,
    },
    {
        .species = SPECIES_WISHIWASHI,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SCHOOLING,
    },
    {
        .species = SPECIES_WISHIWASHI_S,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SCHOOLING,
    },
    {
        .species = SPECIES_MINIOR_SHIELD,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_RED,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_BLUE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_ORANGE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_YELLOW,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_INDIGO,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_GREEN,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MINIOR_VIOLET,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_SHIELDS_DOWN,
    },
    {
        .species = SPECIES_MIMIKYU,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_DISGUISE,
    },
    {
        .species = SPECIES_MIMIKYU_BUSTED,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_DISGUISE,
    },
    {
        .species = SPECIES_GRENINJA,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_BATTLE_BOND,
    },
    {
        .species = SPECIES_ASHGRENINJA,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_BATTLE_BOND,
    },
    {
        .species = SPECIES_ZYGARDE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_POWER_CONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE_10,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_POWER_CONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE_COMPLETE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_POWER_CONSTRUCT,
    },
    {
        .species = SPECIES_EISCUE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ICE_FACE,
    },
    {
        .species = SPECIES_EISCUE_NOICE,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_ICE_FACE,
    },
    {
        .species = SPECIES_MORPEKO,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_HUNGER_SWITCH,
    },
    {
        .species = SPECIES_MORPEKO_HANGRY,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_HUNGER_SWITCH,
    },
    {
        .species = SPECIES_CRAMORANT,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_GULP_MISSILE,
    },
    {
        .species = SPECIES_CRAMORANT_GULPING,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_GULP_MISSILE,
    },
    {
        .species = SPECIES_CRAMORANT_GORGING,
        .currAbility = ABILITY_FORM_CHANGE_SIGNATURE,
        .replaceAbilityString = NAME_GULP_MISSILE,
    },
    {
        .species = SPECIES_STUNFISK_G,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityString = NAME_PLACEBO,
    },
    {
        .species = SPECIES_VULPIX_A,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityString = NAME_PLACEBO,
    },
    {
        .species = SPECIES_NINETALES_A,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityString = NAME_PLACEBO,
    },
    {
        .species = SPECIES_EMOLGA,
        .currAbility = ABILITY_DOWNLOAD,
        .replaceAbilityString = NAME_ADEQUATE,
    },
    {
        .species = SPECIES_CHESPIN,
        .currAbility = ABILITY_WATERCOMPACTION,
        .replaceAbilityString = NAME_SOAKAGE,
    },
    {
        .species = SPECIES_QUILLADIN,
        .currAbility = ABILITY_WATERCOMPACTION,
        .replaceAbilityString = NAME_SOAKAGE,
    },
};