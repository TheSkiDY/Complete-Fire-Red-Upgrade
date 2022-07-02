#include "../config.h"
#include "../../include/new/build_pokemon.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/moves.h"

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
        .species = SPECIES_RAYQUAZA,
        .currAbility = ABILITY_CLOUDNINE, 
        .replaceAbilityString = NAME_AIR_LOCK, 
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
};