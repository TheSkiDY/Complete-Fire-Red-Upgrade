#include "defines.h"
#include "defines_battle.h"
#include "../include/battle.h"
#include "../include/string_util.h"
#include "../include/constants/abilities.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/species.h"

#include "../include/new/ability_tables.h"
#include "../include/new/ability_util.h"
#include "../include/new/battle_util.h"
#include "../include/new/move_tables.h"
#include "../include/new/species_tables.h"
#include "../include/new/util.h"


extern const u8 gAbilityNames[][ABILITY_NAME_LENGTH + 1];
extern const u8* gAbilityDescriptions[];
extern const u8 NAME_AIR_LOCK[];
extern const u8 NAME_VITAL_SPIRIT[];
extern const u8 NAME_WHITE_SMOKE[];
extern const u8 NAME_PURE_POWER[];
extern const u8 NAME_IRON_BARBS[];
extern const u8 NAME_SOLID_ROCK[];
extern const u8 NAME_TURBOBLAZE[];
extern const u8 NAME_TERAVOLT[];
extern const u8 NAME_CHILLING_NEIGH[];
extern const u8 NAME_LIBERO[];
extern const u8 NAME_TANGLING_HAIR[];
extern const u8 NAME_WIMP_OUT[];
extern const u8 NAME_QUEENLY_MAJESTY[];
extern const u8 NAME_POWER_OF_ALCHEMY[];
extern const u8 NAME_PROPELLER_TAIL[];

extern const u8 NAME_FULL_METAL_BODY[];
extern const u8 NAME_SPIKY_BODY[];
extern const u8 NAME_PRISM_ARMOR[];
extern const u8 NAME_GUARDING_SCALES[];
extern const u8 NAME_GRIM_NEIGH[];
extern const u8 NAME_MULTISCALE[];
extern const u8 NAME_SHADOW_SHIELD[];
extern const u8 NAME_MYSTIC_SHELL[];
extern const u8 NAME_GOOEY[];
extern const u8 NAME_BRAINS_SYNERGY[];
extern const u8 NAME_DAZZLING[];
extern const u8 NAME_SCREECHING_BUZZ[];
extern const u8 NAME_SONIC_FORCE[];
extern const u8 NAME_VIOLENT_DRUMS[];
extern const u8 NAME_VALIANT_SHIELD[];
extern const u8 NAME_SHELL_ARMOR[];
extern const u8 NAME_MAGICIAN[];
extern const u8 DESC_MAGICIAN[];
extern const u8 NAME_CACOPHONY[];
extern const u8 NAME_VOLT_BARRIER[];
extern const u8 NAME_GLUEY_FIELD[];
extern const u8 NAME_OPPORTUNIST[];
extern const u8 NAME_TIGHT_MASK[];
extern const u8 NAME_INGROWN[];
extern const u8 NAME_COSMOFORCE[];
extern const u8 NAME_ADEQUATE[];
extern const u8 NAME_SOAKAGE[];
extern const u8 NAME_INSTANT_FLASH[];
extern const u8 NAME_WILL_OF_FIRE[];
extern const u8 NAME_PLACEBO[];
extern const u8 NAME_ARMOR_TAIL[];

extern const u8 NAME_SHIELDS_DOWN[];
extern const u8 NAME_ZEN_MODE[];
extern const u8 NAME_ICE_FACE[];
extern const u8 NAME_STANCE_CHANGE[];
extern const u8 NAME_GULP_MISSILE[];
extern const u8 NAME_HUNGER_SWITCH[];
extern const u8 NAME_ROCKY_SHELTER[];
extern const u8 NAME_DISGUISE[];
extern const u8 NAME_SCHOOLING[];
extern const u8 NAME_BATTLE_BOND[];
extern const u8 NAME_POWER_CONSTRUCT[];
extern const u8 DESC_SHIELDS_DOWN[];
extern const u8 DESC_ZEN_MODE[];
extern const u8 DESC_ICE_FACE[];
extern const u8 DESC_STANCE_CHANGE[];
extern const u8 DESC_GULP_MISSILE[];
extern const u8 DESC_HUNGER_SWITCH[];
extern const u8 DESC_ROCKY_SHELTER[];
extern const u8 DESC_DISGUISE[];
extern const u8 DESC_SCHOOLING[];
extern const u8 DESC_BATTLE_BOND[];
extern const u8 DESC_POWER_CONSTRUCT[];

//Custom Abilities
extern const u8 NAME_TEMPESTUOUS_SEA[];
extern const u8 DESC_TEMPESTUOUS_SEA[];
extern const u8 NAME_SHADOW_BOOST[];
extern const u8 DESC_SHADOW_BOOST[];

extern const u8 NAME_VIRTUE[];
extern const u8 NAME_RAMPAGE[];
extern const u8 NAME_CYCLONE[];
extern const u8 NAME_BIOHAZARD[];
extern const u8 NAME_UPHEAVAL[];
extern const u8 NAME_BEDROCK[];
extern const u8 NAME_SWARM[];
extern const u8 NAME_HAUNTED[];
extern const u8 NAME_TEMPER[];
extern const u8 NAME_BLAZE[];
extern const u8 NAME_TORRENT[];
extern const u8 NAME_OVERGROW[];
extern const u8 NAME_OVERCHARGE[];
extern const u8 NAME_BRAINSTORM[];
extern const u8 NAME_SNOWFALL[];
extern const u8 NAME_MYTHIC_RAGE[];
extern const u8 NAME_WRATH[];
extern const u8 NAME_ENCHANT[];

extern const u8 DESC_VIRTUE[];
extern const u8 DESC_RAMPAGE[];
extern const u8 DESC_CYCLONE[];
extern const u8 DESC_BIOHAZARD[];
extern const u8 DESC_UPHEAVAL[];
extern const u8 DESC_BEDROCK[];
extern const u8 DESC_SWARM[];
extern const u8 DESC_HAUNTED[];
extern const u8 DESC_TEMPER[];
extern const u8 DESC_BLAZE[];
extern const u8 DESC_TORRENT[];
extern const u8 DESC_OVERGROW[];
extern const u8 DESC_OVERCHARGE[];
extern const u8 DESC_BRAINSTORM[];
extern const u8 DESC_SNOWFALL[];
extern const u8 DESC_MYTHIC_RAGE[];
extern const u8 DESC_WRATH[];
extern const u8 DESC_ENCHANT[];

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
extern const u8 NAME_DARK_AURA[];
extern const u8 NAME_FAIRY_AURA[];

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
extern const u8 DESC_DARK_AURA[];
extern const u8 DESC_FAIRY_AURA[];

extern const u8 NAME_WARFARE[];
extern const u8 NAME_AERILATE[];
extern const u8 NAME_TOXINATE[];
extern const u8 NAME_EARTHBOUND[];
extern const u8 NAME_CRAGITATE[];
extern const u8 NAME_INFECTATE[];
extern const u8 NAME_CHANNELING[];
extern const u8 NAME_FORTIFIED[];
extern const u8 NAME_EMPYREAL[];
extern const u8 NAME_HYDRATE[];
extern const u8 NAME_NATURALIZE[];
extern const u8 NAME_GALVANIZE[];
extern const u8 NAME_COGNITIVE[];
extern const u8 NAME_REFRIGERATE[];
extern const u8 NAME_WYVERNATE[];
extern const u8 NAME_ANTAGONIZE[];
extern const u8 NAME_PIXILATE[];

extern const u8 DESC_WARFARE[];
extern const u8 DESC_AERILATE[];
extern const u8 DESC_TOXINATE[];
extern const u8 DESC_EARTHBOUND[];
extern const u8 DESC_CRAGITATE[];
extern const u8 DESC_INFECTATE[];
extern const u8 DESC_CHANNELING[];
extern const u8 DESC_FORTIFIED[];
extern const u8 DESC_EMPYREAL[];
extern const u8 DESC_HYDRATE[];
extern const u8 DESC_NATURALIZE[];
extern const u8 DESC_GALVANIZE[];
extern const u8 DESC_COGNITIVE[];
extern const u8 DESC_REFRIGERATE[];
extern const u8 DESC_WYVERNATE[];
extern const u8 DESC_ANTAGONIZE[];
extern const u8 DESC_PIXILATE[];

extern const u8 NAME_ELECTRIC_SURGE[];
extern const u8 NAME_GRASSY_SURGE[];
extern const u8 NAME_MISTY_SURGE[];
extern const u8 NAME_PSYCHIC_SURGE[];

extern const u8 DESC_ELECTRIC_SURGE[];
extern const u8 DESC_GRASSY_SURGE[];
extern const u8 DESC_MISTY_SURGE[];
extern const u8 DESC_PSYCHIC_SURGE[];

extern const u8 NAME_MODULATOR[];
extern const u8 NAME_WIZARDRY[];
extern const u8 NAME_MIRACULOUS[];
extern const u8 NAME_WORMHOLE[];
extern const u8 NAME_PLASMA_BURST[];

extern const u8 DESC_WIZARDRY[];
extern const u8 DESC_MODULATOR[];
extern const u8 DESC_MIRACULOUS[];
extern const u8 DESC_WORMHOLE[];
extern const u8 DESC_PLASMA_BURST[];

//Unbound Custom Abilities
extern const u8 NAME_NINE_LIVES[];
extern const u8 NAME_FOCUS_BELT[];
extern const u8 NAME_EVAPORATE[];
extern const u8 NAME_FIERY_NEIGH[];
extern const u8 NAME_SHOCKING_NEIGH[];
extern const u8 NAME_PRIDE[];
extern const u8 NAME_MULTIEYE[];
extern const u8 NAME_SUBTERFUGE[];
extern const u8 NAME_TANGLING_WOOL[];
extern const u8 NAME_BRAIN_BOND[];
extern const u8 NAME_GRASS_DASH[];
extern const u8 NAME_SLIPPERY_TAIL[];
extern const u8 NAME_DRILL_BEAK[];
extern const u8 NAME_COTTON_CLOUD[];
extern const u8 NAME_BELLOW[];
extern const u8 NAME_SOUND_WAVES[];
extern const u8 NAME_ICY_SKIN[];
extern const u8 NAME_DUSTY_SCALES[];
extern const u8 NAME_CRABBY_TACTICS[];
extern const u8 NAME_HONEY_ARMOR[];
extern const u8 NAME_FACE_SHIELD[];
extern const u8 NAME_ROYAL_ROAR[];
extern const u8 DESC_EVAPORATE[];
extern const u8 DESC_GRASS_DASH[];
extern const u8 DESC_SLIPPERY_TAIL[];
extern const u8 DESC_DRILL_BEAK[];

struct DuplicateAbility
{
    u16 species;
    u8 currAbility;
    const u8* replaceAbilityName;
};

static struct DuplicateAbility sDuplicateNames[] =
{
    //Cloud Nine -> Air Lock
    {
        .species = SPECIES_RAYQUAZA,
        .currAbility = ABILITY_CLOUDNINE,
        .replaceAbilityName = NAME_AIR_LOCK,
    },
    {
        .species = SPECIES_AERODACTYL,
        .currAbility = ABILITY_CLOUDNINE,
        .replaceAbilityName = NAME_AIR_LOCK,
    },
    {
        .species = SPECIES_DELIBIRD,
        .currAbility = ABILITY_CLOUDNINE,
        .replaceAbilityName = NAME_AIR_LOCK,
    },

    //Clear Body -> Full Metal Body
    {
        .species = SPECIES_SOLGALEO,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityName = NAME_FULL_METAL_BODY,
    },

    //Huge Power -> Pure Power
    // {
    //     .species = SPECIES_MEDITITE,
    //     .currAbility = ABILITY_HUGEPOWER,
    //     .replaceAbilityName = NAME_PURE_POWER,  
    // },
    // {
    //     .species = SPECIES_MEDICHAM,
    //     .currAbility = ABILITY_HUGEPOWER,
    //     .replaceAbilityName = NAME_PURE_POWER,
    // },
    // {
    //     .species = SPECIES_MEDICHAM_MEGA,
    //     .currAbility = ABILITY_HUGEPOWER,
    //     .replaceAbilityName = NAME_PURE_POWER,
    // },


    //Rough Skin -> Iron Barbs
    {
        .species = SPECIES_FERROSEED,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_FERROTHORN,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_TOGEDEMARU,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_IRON_BARBS,
    },

    //Rough Skin -> Spiky Body
    {
        .species = SPECIES_CACNEA,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_CACTURNE,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_ROSELIA,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_ROSERADE,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_MARACTUS,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_WYNAUT_S,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },
    {
        .species = SPECIES_WOBBUFFET_S,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityName = NAME_SPIKY_BODY,
    },

    //Filter -> Solid Rock
    {
        .species = SPECIES_CAMERUPT,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_RHYPERIOR,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_TIRTOUGA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_CARRACOSTA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_PUPITAR,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_LAPRAS_S,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_SOLID_ROCK,
    },

    //Filter -> Prism Armor
    {
        .species = SPECIES_NECROZMA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_NECROZMA_DUSK_MANE,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_NECROZMA_DAWN_WINGS,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_ELGYEM_S,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_BEHEEYEM_S,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_PRISM_ARMOR,
    },

    //Filter -> Guarding Scales
    {
        .species = SPECIES_EKANS,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_GUARDING_SCALES,
    },
    {
        .species = SPECIES_ARBOK,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityName = NAME_GUARDING_SCALES,
    },

    //Moxie -> Chilling Neigh
    {
        .species = SPECIES_GLASTRIER,
        .currAbility = ABILITY_MOXIE,
        .replaceAbilityName = NAME_CHILLING_NEIGH,
    },
    {
        .species = SPECIES_CALYREX_ICE,
        .currAbility = ABILITY_MOXIE,
        .replaceAbilityName = NAME_CHILLING_NEIGH,
    },

    //Confidence -> Grim Neigh
    {
        .species = SPECIES_SPECTRIER,
        .currAbility = ABILITY_CONFIDENCE,
        .replaceAbilityName = NAME_GRIM_NEIGH,
    },
    {
        .species = SPECIES_CALYREX_GHOST,
        .currAbility = ABILITY_CONFIDENCE,
        .replaceAbilityName = NAME_GRIM_NEIGH,
    },

    //Mythical Shield -> Multiscale
    {
        .species = SPECIES_DRAGONITE,
        .currAbility = ABILITY_MYTHICALSHIELD,
        .replaceAbilityName = NAME_MULTISCALE,
    },
    {
        .species = SPECIES_LUGIA,
        .currAbility = ABILITY_MYTHICALSHIELD,
        .replaceAbilityName = NAME_MULTISCALE,
    },

    //Mythical Shield -> Shadow Shield
    {
        .species = SPECIES_BEEDRILL_S,
        .currAbility = ABILITY_MYTHICALSHIELD,
        .replaceAbilityName = NAME_SHADOW_SHIELD,
    },
    {
        .species = SPECIES_LUNALA,
        .currAbility = ABILITY_MYTHICALSHIELD,
        .replaceAbilityName = NAME_SHADOW_SHIELD,
    },

    //Mythical Shield -> Mystic Shell
    {
        .species = SPECIES_CLAMPERL,
        .currAbility = ABILITY_MYTHICALSHIELD,
        .replaceAbilityName = NAME_MYSTIC_SHELL,
    },

    //Protean -> Libero
    {
        .species = SPECIES_SCORBUNNY,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityName = NAME_LIBERO,
    },
    {
        .species = SPECIES_RABOOT,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityName = NAME_LIBERO,
    },
    {
        .species = SPECIES_CINDERACE,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityName = NAME_LIBERO,
    },

    //Stun Touch -> Tangling Hair
    {
        .species = SPECIES_DIGLETT_A,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_DUGTRIO_A,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_POOCHYENA_S,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_MIGHTYENA_S,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_JUNGYENA,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_TANGLING_HAIR,
    },

    //Stun Touch -> Gooey
    {
        .species = SPECIES_GOOMY,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_GOOEY,
    },
    {
        .species = SPECIES_SLIGGOO,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_GOOEY,
    },
    {
        .species = SPECIES_GOODRA,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_GOOEY,
    },
    {
        .species = SPECIES_SLIGGOO_H,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_GOOEY,
    },
    {
        .species = SPECIES_GOODRA_H,
        .currAbility = ABILITY_STUNTOUCH,
        .replaceAbilityName = NAME_GOOEY,
    },

    //Parental Bond -> Brains Synergy
    {
        .species = SPECIES_GIRAFARIG,
        .currAbility = ABILITY_PARENTALBOND,
        .replaceAbilityName = NAME_BRAINS_SYNERGY,
    },


    //Emergency Exit -> Wimp Out
    {
        .species = SPECIES_WIMPOD,
        .currAbility = ABILITY_EMERGENCYEXIT,
        .replaceAbilityName = NAME_WIMP_OUT,
    },
    {
        .species = SPECIES_SURSKIT,
        .currAbility = ABILITY_EMERGENCYEXIT,
        .replaceAbilityName = NAME_WIMP_OUT,
    },
    
    //Majestic -> Dazzling
    {
        .species = SPECIES_BRUXISH,
        .currAbility = ABILITY_MAJESTIC,
        .replaceAbilityName = NAME_DAZZLING,
    },
    
    //Majestic -> Queenly Majesty
    {
        .species = SPECIES_TSAREENA,
        .currAbility = ABILITY_MAJESTIC,
        .replaceAbilityName = NAME_QUEENLY_MAJESTY,
    },
    {
        .species = SPECIES_TSAREENA_S,
        .currAbility = ABILITY_MAJESTIC,
        .replaceAbilityName = NAME_QUEENLY_MAJESTY,
    },
    {
        .species = SPECIES_FROSLASS_S,
        .currAbility = ABILITY_MAJESTIC,
        .replaceAbilityName = NAME_QUEENLY_MAJESTY,
    },
    {
        .species = SPECIES_SUNFLORA_S,
        .currAbility = ABILITY_MAJESTIC,
        .replaceAbilityName = NAME_QUEENLY_MAJESTY,
    },
    
    
    //Receiver -> Power of Alchemy
    {
        .species = SPECIES_GRIMER_A,
        .currAbility = ABILITY_RECEIVER,
        .replaceAbilityName = NAME_POWER_OF_ALCHEMY,
    },
    {
        .species = SPECIES_MUK_A,
        .currAbility = ABILITY_RECEIVER,
        .replaceAbilityName = NAME_POWER_OF_ALCHEMY,
    },

    //Stalwart -> Propeller Tail
    {
        .species = SPECIES_ARROKUDA,
        .currAbility = ABILITY_STALWART,
        .replaceAbilityName = NAME_PROPELLER_TAIL,
    },
    {
        .species = SPECIES_BARRASKEWDA,
        .currAbility = ABILITY_STALWART,
        .replaceAbilityName = NAME_PROPELLER_TAIL,
    },

    //Punk Rock -> Screeching Buzz
    {
        .species = SPECIES_YANMA,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_SCREECHING_BUZZ,
    },
    {
        .species = SPECIES_YANMEGA,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_SCREECHING_BUZZ,
    },
    {
        .species = SPECIES_VENOMOTH,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_SCREECHING_BUZZ,
    },

    //Punk Rock -> Sonic Force
    {
        .species = SPECIES_TAILLOW,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_SONIC_FORCE,
    },
    {
        .species = SPECIES_SWELLOW,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_SONIC_FORCE,
    },

    //Punk Rock -> Violent Drums
    {
        .species = SPECIES_GROOKEY,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_THWACKEY,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_RILLABOOM,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_VIOLENT_DRUMS,
    },
    {
        .species = SPECIES_RILLABOOM_GIGA,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityName = NAME_VIOLENT_DRUMS,
    },

    //Ice Scales -> Icy Skin
    {
        .species = SPECIES_GLACEON,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SANDSHREW_A,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SANDSLASH_A,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_JYNX,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_SKIDDO_S,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },
    {
        .species = SPECIES_GOGOAT_S,
        .currAbility = ABILITY_ICESCALES,
        .replaceAbilityName = NAME_ICY_SKIN,
    },

    //Dauntless Shield -> Face Shield
    {
        .species = SPECIES_SHIELDON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityName = NAME_FACE_SHIELD,
    },
    {
        .species = SPECIES_BASTIODON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityName = NAME_FACE_SHIELD,
    },

    //Dauntless Shield -> Valiant Shield
    {
        .species = SPECIES_CORVIKNIGHT,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityName = NAME_VALIANT_SHIELD,
    },
    {
        .species = SPECIES_TYPE_NULL,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityName = NAME_VALIANT_SHIELD,
    },
    {
        .species = SPECIES_SHELGON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityName = NAME_VALIANT_SHIELD,
    },
    
    //Battle Armor -> Shell Armor
    {
        .species = SPECIES_SQUIRTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_WARTORTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_BLASTOISE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SLOWBRO_MEGA,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SHELLDER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CLOYSTER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_KRABBY,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_KINGLER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_KINGLER_GIGA,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_LAPRAS,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_LAPRAS_GIGA,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_OMANYTE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_OMASTAR,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CORPHISH,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CRAWDAUNT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CLAMPERL,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_DWEBBLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CRUSTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_ESCAVALIER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SHELMET,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TURTONATOR,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CHEWTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_DREDNAW,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TORKOAL,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TURTWIG,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_GROTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TORTERRA,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_OSHAWOTT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_DEWOTT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SAMUROTT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SAMUROTT_H,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityName = NAME_SHELL_ARMOR,
    },


    //Soundproof -> Cacophony
    {
        .species = SPECIES_WHISMUR,
        .currAbility = ABILITY_SOUNDPROOF,
        .replaceAbilityName = NAME_CACOPHONY,
    },
    {
        .species = SPECIES_LOUDRED,
        .currAbility = ABILITY_SOUNDPROOF,
        .replaceAbilityName = NAME_CACOPHONY,
    },
    {
        .species = SPECIES_EXPLOUD,
        .currAbility = ABILITY_SOUNDPROOF,
        .replaceAbilityName = NAME_CACOPHONY,
    },
    {
        .species = SPECIES_KRICKETUNE,
        .currAbility = ABILITY_SOUNDPROOF,
        .replaceAbilityName = NAME_CACOPHONY,
    },
    {
        .species = SPECIES_KRICKETOT,
        .currAbility = ABILITY_SOUNDPROOF,
        .replaceAbilityName = NAME_CACOPHONY,
    },

    //Fur Coat -> Volt Barrier
    {
        .species = SPECIES_AMPHAROS,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_STUNFISK,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_RAICHU_A,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_FAN,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_MOW,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_FROST,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_HEAT,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },
    {
        .species = SPECIES_ROTOM_WASH,
        .currAbility = ABILITY_FURCOAT,
        .replaceAbilityName = NAME_VOLT_BARRIER,
    },

    //Arena Trap -> Gluey Field
    {
        .species = SPECIES_GRIMER,
        .currAbility = ABILITY_ARENATRAP,
        .replaceAbilityName = NAME_GLUEY_FIELD,
    },
    {
        .species = SPECIES_MUK,
        .currAbility = ABILITY_ARENATRAP,
        .replaceAbilityName = NAME_GLUEY_FIELD,
    },

    //Beast Boost -> Opportunist
    {
        .species = SPECIES_SPINDA,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_VESPIQUEN,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY_SANDY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_BURMY_TRASH,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM_SANDY,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_WORMADAM_TRASH,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_TYNAMO,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_EELEKTRIK,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_EELEKTROSS,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },
    {
        .species = SPECIES_VESPIKING,
        .currAbility = ABILITY_BEASTBOOST,
        .replaceAbilityName = NAME_OPPORTUNIST,
    },

    //Fluffy -> Honey Armor
    {
        .species = SPECIES_VESPIQUEN,
        .currAbility = ABILITY_FLUFFY,
        .replaceAbilityName = NAME_HONEY_ARMOR,
    },
    {
        .species = SPECIES_GRIMER_S,
        .currAbility = ABILITY_FLUFFY,
        .replaceAbilityName = NAME_HONEY_ARMOR,
    },
    {
        .species = SPECIES_MUK_S,
        .currAbility = ABILITY_FLUFFY,
        .replaceAbilityName = NAME_HONEY_ARMOR,
    },

    //Overcoat -> Tight Mask
    {
        .species = SPECIES_CUBONE,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityName = NAME_TIGHT_MASK,
    },
    {
        .species = SPECIES_MAROWAK,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityName = NAME_TIGHT_MASK,
    },
    {
        .species = SPECIES_MAROWAK_A,
        .currAbility = ABILITY_OVERCOAT,
        .replaceAbilityName = NAME_TIGHT_MASK,
    },

    //Suction Cups -> Ingrown
    {
        .species = SPECIES_PHANTUMP,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },
    {
        .species = SPECIES_TREVENANT,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },
    {
        .species = SPECIES_EXEGGUTOR_A,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },
    {
        .species = SPECIES_TURTWIG,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },
    {
        .species = SPECIES_GROTLE,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },
    {
        .species = SPECIES_TORTERRA,
        .currAbility = ABILITY_SUCTIONCUPS,
        .replaceAbilityName = NAME_INGROWN,
    },

    //Neuroforce -> Cosmoforce
    {
        .species = SPECIES_LUNATONE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_SOLROCK,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_STARYU,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_STARMIE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_ATTACK,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_DEFENSE,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    {
        .species = SPECIES_DEOXYS_SPEED,
        .currAbility = ABILITY_NEUROFORCE,
        .replaceAbilityName = NAME_COSMOFORCE,
    },
    
    //Download -> Adequate
    {
        .species = SPECIES_EMOLGA,
        .currAbility = ABILITY_DOWNLOAD,
        .replaceAbilityName = NAME_ADEQUATE,
    },
    
    //Water Compaction -> Soakage
    {
        .species = SPECIES_CHESPIN,
        .currAbility = ABILITY_WATERCOMPACTION,
        .replaceAbilityName = NAME_SOAKAGE,
    },
    {
        .species = SPECIES_QUILLADIN,
        .currAbility = ABILITY_WATERCOMPACTION,
        .replaceAbilityName = NAME_SOAKAGE,
    },
    
    //Quick Draw -> Instant Flash
    {
        .species = SPECIES_LANTURN_MEGA,
        .currAbility = ABILITY_QUICKDRAW,
        .replaceAbilityName = NAME_INSTANT_FLASH,
    },

    //Tough Claws -> Will of Fire
    {
        .species = SPECIES_BASIBLAZE,
        .currAbility = ABILITY_TOUGHCLAWS,
        .replaceAbilityName = NAME_WILL_OF_FIRE,
    },

    //Focused Warrior -> Placebo
    {
        .species = SPECIES_VULPIX_A,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityName = NAME_PLACEBO,
    },
    {
        .species = SPECIES_NINETALES_A,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityName = NAME_PLACEBO,
    },
    {
        .species = SPECIES_STUNFISK,
        .currAbility = ABILITY_FOCUSEDWARRIOR,
        .replaceAbilityName = NAME_PLACEBO,
    },

};

static const u8* sBlazeLikeNames[] =
{
    [TYPE_NORMAL] = NAME_VIRTUE,
    [TYPE_FIGHTING] = NAME_RAMPAGE,
    [TYPE_FLYING] = NAME_CYCLONE,
    [TYPE_POISON] = NAME_BIOHAZARD,
    [TYPE_GROUND] = NAME_UPHEAVAL,
    [TYPE_ROCK] = NAME_BEDROCK,
    [TYPE_BUG] = NAME_SWARM,
    [TYPE_GHOST] = NAME_HAUNTED,
    [TYPE_STEEL] = NAME_TEMPER,
    [TYPE_FIRE] = NAME_BLAZE,
    [TYPE_WATER] = NAME_TORRENT,
    [TYPE_GRASS] = NAME_OVERGROW,
    [TYPE_ELECTRIC] = NAME_OVERCHARGE,
    [TYPE_PSYCHIC] = NAME_BRAINSTORM,
    [TYPE_ICE] = NAME_SNOWFALL,
    [TYPE_DRAGON] = NAME_MYTHIC_RAGE,
    [TYPE_DARK] = NAME_WRATH,
    [TYPE_FAIRY] = NAME_ENCHANT,
};

static const u8* sBlazeLikeDescriptions[] =
{
    [TYPE_NORMAL] = DESC_VIRTUE,
    [TYPE_FIGHTING] = DESC_RAMPAGE,
    [TYPE_FLYING] = DESC_CYCLONE,
    [TYPE_POISON] = DESC_BIOHAZARD,
    [TYPE_GROUND] = DESC_UPHEAVAL,
    [TYPE_ROCK] = DESC_BEDROCK,
    [TYPE_BUG] = DESC_SWARM,
    [TYPE_GHOST] = DESC_HAUNTED,
    [TYPE_STEEL] = DESC_TEMPER,
    [TYPE_FIRE] = DESC_BLAZE,
    [TYPE_WATER] = DESC_TORRENT,
    [TYPE_GRASS] = DESC_OVERGROW,
    [TYPE_ELECTRIC] = DESC_OVERCHARGE,
    [TYPE_PSYCHIC] = DESC_BRAINSTORM,
    [TYPE_ICE] = DESC_SNOWFALL,
    [TYPE_DRAGON] = DESC_MYTHIC_RAGE,
    [TYPE_DARK] = DESC_WRATH,
    [TYPE_FAIRY] = DESC_ENCHANT,
};

static const u8* sAuraNames[] = 
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
    [TYPE_DARK] = NAME_DARK_AURA,
    [TYPE_FAIRY] = NAME_FAIRY_AURA,
};

static const u8* sAuraDescriptions[] = 
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
    [TYPE_DARK] = DESC_DARK_AURA,
    [TYPE_FAIRY] = DESC_FAIRY_AURA,
};

static const u8* sAteNames[] =
{
    [TYPE_NORMAL] = NULL,
    [TYPE_FIGHTING] = NAME_WARFARE,
    [TYPE_FLYING] = NAME_AERILATE,
    [TYPE_POISON] = NAME_TOXINATE,
    [TYPE_GROUND] = NAME_EARTHBOUND,
    [TYPE_ROCK] = NAME_CRAGITATE,
    [TYPE_BUG] = NAME_INFECTATE,
    [TYPE_GHOST] = NAME_CHANNELING,
    [TYPE_STEEL] = NAME_FORTIFIED,
    [TYPE_FIRE] = NAME_EMPYREAL,
    [TYPE_WATER] = NAME_HYDRATE,
    [TYPE_GRASS] = NAME_NATURALIZE,
    [TYPE_ELECTRIC] = NAME_GALVANIZE,
    [TYPE_PSYCHIC] = NAME_COGNITIVE,
    [TYPE_ICE] = NAME_REFRIGERATE,
    [TYPE_DRAGON] = NAME_WYVERNATE,
    [TYPE_DARK] = NAME_ANTAGONIZE,
    [TYPE_FAIRY] = NAME_PIXILATE,
};

static const u8* sAteDescriptions[] =
{
    [TYPE_NORMAL] = NULL,
    [TYPE_FIGHTING] = DESC_WARFARE,
    [TYPE_FLYING] = DESC_AERILATE,
    [TYPE_POISON] = DESC_TOXINATE,
    [TYPE_GROUND] = DESC_EARTHBOUND,
    [TYPE_ROCK] = DESC_CRAGITATE,
    [TYPE_BUG] = DESC_INFECTATE,
    [TYPE_GHOST] = DESC_CHANNELING,
    [TYPE_STEEL] = DESC_FORTIFIED,
    [TYPE_FIRE] = DESC_EMPYREAL,
    [TYPE_WATER] = DESC_HYDRATE,
    [TYPE_GRASS] = DESC_NATURALIZE,
    [TYPE_ELECTRIC] = DESC_GALVANIZE,
    [TYPE_PSYCHIC] = DESC_COGNITIVE,
    [TYPE_ICE] = DESC_REFRIGERATE,
    [TYPE_DRAGON] = DESC_WYVERNATE,
    [TYPE_DARK] = DESC_ANTAGONIZE,
    [TYPE_FAIRY] = DESC_PIXILATE,
};

static const u8* sTerrainSurgeNames[] = 
{
    [NO_TERRAIN] = NULL,
    [ELECTRIC_TERRAIN] = NAME_ELECTRIC_SURGE,
    [GRASSY_TERRAIN] = NAME_GRASSY_SURGE,
    [MISTY_TERRAIN] = NAME_MISTY_SURGE,
    [PSYCHIC_TERRAIN] = NAME_PSYCHIC_SURGE,
};

static const u8* sTerrainSurgeDescriptions[] = 
{
    [NO_TERRAIN] = NULL,
    [ELECTRIC_TERRAIN] = DESC_ELECTRIC_SURGE,
    [GRASSY_TERRAIN] = DESC_GRASSY_SURGE,
    [MISTY_TERRAIN] = DESC_MISTY_SURGE,
    [PSYCHIC_TERRAIN] = DESC_PSYCHIC_SURGE,
};



const u8* GetAbilityNameOverride(const u8 ability, const u16 species) //Bypasses the 255 Ability limitation and implements clone Abilities
{
	switch (ability)
	{
		case ABILITY_INSOMNIA:
			if(IsVitalSpiritAbility(ability, species))
				return NAME_VITAL_SPIRIT;
			break;
		case ABILITY_CLEARBODY:
			if(IsWhiteSmokeAbility(ability, species))
				return NAME_WHITE_SMOKE;
			break;
		case ABILITY_MOLDBREAKER:
			if(SpeciesHasTurboblaze(species))
				return NAME_TURBOBLAZE;
			else if(SpeciesHasTeravolt(species))
				return NAME_TERAVOLT;
			break;
		case ABILITY_PICKPOCKET:
			if(SpeciesHasMagician(species))
				return NAME_MAGICIAN;
			break;
		case ABILITY_GALEWINGS:
			if (SpeciesHasTempestuousSea(species))
				return NAME_TEMPESTUOUS_SEA;
            else if (SpeciesHasShadowBoost(species))
                return NAME_SHADOW_BOOST;
			break;
        case ABILITY_LIQUIDVOICE:
            if (SpeciesHasModulator(species))
                return NAME_MODULATOR;
            break;
        case ABILITY_CLOCKWORK:
            if (SpeciesHasWizardry(species))
                return NAME_WIZARDRY;
            else if (SpeciesHasMiraculous(species))
                return NAME_MIRACULOUS;
            else if (SpeciesHasWormhole(species))
                return NAME_WORMHOLE;
            else if (SpeciesHasPlasmaBurst(species))
                return NAME_PLASMA_BURST;
            break;
		case ABILITY_FORM_CHANGE:
			return GetAbilityNameOverrideForFormChange(ability, species);
        case ABILITY_BLAZE_LIKE:
            return GetBlazeLikeNameFromSpecies(species);
        case ABILITY_AURA:
            return GetAuraNameFromSpecies(species);
        case ABILITY_ATE:
            return GetAteNameFromSpecies(species);
        case ABILITY_TERRAIN_SURGE:
            return GetSurgeNameFromSpecies(species);
	}

	for(u16 i = 0; i < ARRAY_COUNT(sDuplicateNames); ++i)
	{
		if(ability == sDuplicateNames[i].currAbility && species == sDuplicateNames[i].species)
		{
			return sDuplicateNames[i].replaceAbilityName;
		}
	}

	return NULL;
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
	switch (ability)
	{
		case ABILITY_STORMDRAIN:
			if (SpeciesHasEvaporate(species))
				return DESC_EVAPORATE;
			break;
		case ABILITY_MERCILESS:
			if (SpeciesHasDrillBeak(species))
				return DESC_DRILL_BEAK;
			break;
		case ABILITY_PICKPOCKET:
			if (SpeciesHasMagician(species))
				return DESC_MAGICIAN;
			break;
		case ABILITY_GALEWINGS:
			if (SpeciesHasTempestuousSea(species))
				return DESC_TEMPESTUOUS_SEA;
            else if (SpeciesHasShadowBoost(species))
                return DESC_SHADOW_BOOST;
			break;
        case ABILITY_LIQUIDVOICE:
            if (SpeciesHasModulator(species))
                return DESC_MODULATOR;
            break;
        case ABILITY_CLOCKWORK:
            if (SpeciesHasWizardry(species))
                return DESC_WIZARDRY;
            else if (SpeciesHasMiraculous(species))
                return DESC_MIRACULOUS;
            else if (SpeciesHasWormhole(species))
                return DESC_WORMHOLE;
            else if (SpeciesHasPlasmaBurst(species))
                return DESC_PLASMA_BURST;
            break;
		case ABILITY_FORM_CHANGE:
			return GetAbilityDescriptionOverrideForFormChange(ability, species);
        case ABILITY_BLAZE_LIKE:
            return GetBlazeLikeDescriptionFromSpecies(species);
        case ABILITY_AURA:
            return GetAuraDescriptionFromSpecies(species);
        case ABILITY_ATE:
            return GetAteDescriptionFromSpecies(species);
        case ABILITY_TERRAIN_SURGE:
            return GetSurgeDescriptionFromSpecies(species);
	}

	return NULL;
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

bool8 IsTargetAbilityIgnored(u8 defAbility, u8 atkAbility, u16 move, u16 defSpecies)
{
	return IS_MOLD_BREAKER(atkAbility, move) && IsAbilityIgnoredByMoldBreaker(defAbility, defSpecies);
}

bool8 IsTargetAbilityIgnoredNoMove(u8 defAbility, u8 atkAbility, u16 defSpecies)
{
	return IsMoldBreakerAbility(atkAbility) && IsAbilityIgnoredByMoldBreaker(defAbility, defSpecies);
}

bool8 SpeciesHasTurboblaze(unusedArg u16 species)
{
	return gSpecialSpeciesFlags[species].hasTurboblaze;
}

bool8 SpeciesHasTeravolt(unusedArg u16 species)
{
	return gSpecialSpeciesFlags[species].hasTeravolt;
}

bool8 SpeciesHasDrillBeak(unusedArg u16 species) //Custom Unbound Ability
{
    #ifdef UNBOUND
	#if (defined SPECIES_SPEAROW && defined SPECIES_FEAROW)
	return species == SPECIES_SPEAROW || species == SPECIES_FEAROW;
	#else
	return FALSE;
	#endif
    #else
    return FALSE;
    #endif
}

bool8 SpeciesHasGrassDash(unusedArg u16 species) //Custom Unbound Ability
{
    #ifdef UNBOUND
	#ifdef SPECIES_SUNFLORA
	return species == SPECIES_SUNFLORA;
	#else
	return FALSE;
	#endif
    #else
    return FALSE;
    #endif
}

bool8 SpeciesHasEvaporate(unusedArg u16 species) //Custom Unbound Ability
{
    #ifdef UNBOUND
	#ifdef SPECIES_MAGCARGO
	return species == SPECIES_MAGCARGO;
	#else
	return FALSE;
	#endif
    #else
    return FALSE;
    #endif
}

bool8 SpeciesHasSlipperyTail(unusedArg u16 species) //Custom Unbound Ability
{
    #ifdef UNBOUND
	#ifdef SPECIES_SEVIPER
	return species == SPECIES_SEVIPER;
	#else
	return FALSE;
	#endif
    #else
    return FALSE;
    #endif
}

bool8 IsClearBodyAbility(u8 ability)
{
	return ability == ABILITY_CLEARBODY
		#ifdef ABILITY_FULLMETALBODY
		|| ability == ABILITY_FULLMETALBODY
		#endif
		#ifdef ABILITY_WHITESMOKE
		|| ability == ABILITY_WHITESMOKE
		#endif
		;
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
		case ABILITY_MOXIE:
		case ABILITY_CONFIDENCE:
		#ifdef ABILITY_GRIMNEIGH
		case ABILITY_GRIMNEIGH:
		#endif
		#ifdef ABILITY_CHILLINGNEIGH
		case ABILITY_CHILLINGNEIGH:
		#endif
		#ifdef ABILITY_ASONE_GRIM
		case ABILITY_ASONE_GRIM:
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		case ABILITY_ASONE_CHILLING:
		#endif
		case ABILITY_BEASTBOOST:
		case ABILITY_SOULHEART:
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
		case ABILITY_WATERABSORB:
		case ABILITY_VOLTABSORB:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsElectricAbsorptionAblity(u8 ability)
{
	switch (ability)
	{
		case ABILITY_VOLTABSORB:
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
		case ABILITY_MYTHICALSHIELD:
		#ifdef ABILITY_SHADOWSHIELD
		case ABILITY_SHADOWSHIELD:
		#endif
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsPriorityBlockingAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_MAJESTIC:

		#ifdef ABILITY_DAZZLING
		case ABILITY_DAZZLING:
		#endif
		#ifdef ABILITY_QUEENLYMAJESTY
		case ABILITY_QUEENLYMAJESTY:
		#endif
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsUnnerveAbility(u8 ability)
{
	return ability == ABILITY_UNNERVE
		#ifdef ABILITY_ASONE_GRIM
		|| ability == ABILITY_ASONE_GRIM
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		|| ability == ABILITY_ASONE_CHILLING
		#endif
		;
}

bool8 UnnerveOnOpposingField(u8 bank)
{
	return ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_UNNERVE)
		#ifdef ABILITY_ASONE_GRIM
		|| ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_ASONE_GRIM)
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		|| ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_ASONE_CHILLING)
		#endif
		;
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

bool8 AbilityPreventsLoweringSpeed(u8 ability)
{
    return AbilityPreventsLoweringStat(ability, STAT_STAGE_SPEED)
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
        case ABILITY_LIMBER:
            return statId == STAT_STAGE_SPEED;
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
	if ((defAbility == ABILITY_FORM_CHANGE && SpeciesHasDisguise(defSpecies)) && defSpecies == SPECIES_MIMIKYU)
		return TRUE;
	#endif
	#ifdef SPECIES_EISCUE
	if ((defAbility == ABILITY_FORM_CHANGE && SpeciesHasIceFace(defSpecies)) && defSpecies == SPECIES_EISCUE && moveSplit == SPLIT_PHYSICAL)
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

bool8 IsTrappedByAbility(u8 bankDef, u8 trapAbility)
{
	if (!CanBeTrapped(bankDef))
		return FALSE;

	switch (trapAbility)
	{
		case ABILITY_SHADOWTAG:
			return ABILITY(bankDef) != ABILITY_SHADOWTAG; //Shadow Tag's not affected by Shadow Tag
		case ABILITY_ARENATRAP:
			return CheckGrounding(bankDef) == GROUNDED;
		case ABILITY_MAGNETPULL:
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

bool8 IsWhiteSmokeAbility(u8 ability, u16 species)
{
	if (ability != ABILITY_CLEARBODY)
		return FALSE;

	return gSpecialSpeciesFlags[species].hasWhiteSmoke;
}

bool8 IsVitalSpiritAbility(u8 ability, u16 species)
{
	if (ability != ABILITY_INSOMNIA)
		return FALSE;

	return gSpecialSpeciesFlags[species].hasVitalSpirit;
}

bool8 SpeciesHasMagician(u16 species)
{
	return gSpecialSpeciesFlags[species].hasMagician;
}

bool8 SpeciesHasTempestuousSea(u16 species)
{
	return gSpecialSpeciesFlags[species].hasTempestuousSea;
}

bool8 SpeciesHasShadowBoost(u16 species)
{
    return gSpecialSpeciesFlags[species].hasShadowBoost;
}

bool8 SpeciesHasStanceChange(u16 species)
{
	return gSpecialSpeciesFlags[species].hasStanceChange;
}

bool8 SpeciesHasShieldsDown(u16 species)
{
	return gSpecialSpeciesFlags[species].hasShieldsDown;
}

bool8 SpeciesHasDisguise(u16 species)
{
	return gSpecialSpeciesFlags[species].hasDisguise;
}

bool8 SpeciesHasIceFace(u16 species)
{
	return gSpecialSpeciesFlags[species].hasIceFace;
}

bool8 SpeciesHasHungerSwitch(u16 species)
{
	return gSpecialSpeciesFlags[species].hasHungerSwitch;
}

bool8 SpeciesHasZenMode(u16 species)
{
	return gSpecialSpeciesFlags[species].hasZenMode;
}

bool8 SpeciesHasGulpMissile(u16 species)
{
	return gSpecialSpeciesFlags[species].hasGulpMissile;
}

bool8 SpeciesHasRockyShelter(u16 species)
{
	return gSpecialSpeciesFlags[species].hasRockyShelter;
}

bool8 SpeciesHasSchooling(u16 species)
{
	return gSpecialSpeciesFlags[species].hasSchooling;
}

bool8 SpeciesHasBattleBond(u16 species)
{
	return gSpecialSpeciesFlags[species].hasBattleBond;
}

bool8 SpeciesHasPowerConstruct(u16 species)
{
	return gSpecialSpeciesFlags[species].hasPowerConstruct;
}

const u8* GetAbilityNameOverrideForFormChange(const u8 ability, const u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return gAbilityNames[ability];

	if(SpeciesHasShieldsDown(species))
		return NAME_SHIELDS_DOWN;
	else if(SpeciesHasStanceChange(species))
		return NAME_STANCE_CHANGE;
	else if(SpeciesHasDisguise(species))
		return NAME_DISGUISE;
	else if(SpeciesHasIceFace(species))
		return NAME_ICE_FACE;
	else if(SpeciesHasHungerSwitch(species))
		return NAME_HUNGER_SWITCH;
	else if(SpeciesHasZenMode(species))
		return NAME_ZEN_MODE;
	else if(SpeciesHasGulpMissile(species))
		return NAME_GULP_MISSILE;
	else if(SpeciesHasRockyShelter(species))
		return NAME_ROCKY_SHELTER;
	else if(SpeciesHasSchooling(species))
		return NAME_SCHOOLING;
	else if(SpeciesHasBattleBond(species))
		return NAME_BATTLE_BOND;
	else if(SpeciesHasPowerConstruct(species))
		return NAME_POWER_CONSTRUCT;
	else
		return gAbilityNames[ability];
}

const u8* GetAbilityDescriptionOverrideForFormChange(const u8 ability, const u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return gAbilityDescriptions[ability];

	if(SpeciesHasShieldsDown(species))
		return DESC_SHIELDS_DOWN;
	else if(SpeciesHasStanceChange(species))
		return DESC_STANCE_CHANGE;
	else if(SpeciesHasDisguise(species))
		return DESC_DISGUISE;
	else if(SpeciesHasIceFace(species))
		return DESC_ICE_FACE;
	else if(SpeciesHasHungerSwitch(species))
		return DESC_HUNGER_SWITCH;
	else if(SpeciesHasZenMode(species))
		return DESC_ZEN_MODE;
	else if(SpeciesHasGulpMissile(species))
		return DESC_GULP_MISSILE;
	else if(SpeciesHasRockyShelter(species))
		return DESC_ROCKY_SHELTER;
	else if(SpeciesHasSchooling(species))
		return DESC_SCHOOLING;
	else if(SpeciesHasBattleBond(species))
		return DESC_BATTLE_BOND;
	else if(SpeciesHasPowerConstruct(species))
		return DESC_POWER_CONSTRUCT;
	else
		return gAbilityDescriptions[ability];
}

bool8 IsFormChangeAbilityIgnoredByMoldBreaker(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasDisguise(species) ||
		SpeciesHasIceFace(species);
}

bool8 IsAbilityIgnoredByMoldBreaker(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gMoldBreakerIgnoredAbilities || IsFormChangeAbilityIgnoredByMoldBreaker(ability, species);
}

bool8 IsOriginalFormChangeAbilityBannedInRandomizer(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species);
}

bool8 IsOriginalAbilityBannedInRandomizer(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRandomizerBannedOriginalAbilities || IsOriginalFormChangeAbilityBannedInRandomizer(ability, species);
}

bool8 IsNewFormChangeAbilityBannedInRandomizer(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsNewAbilityBannedInRandomizer(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRandomizerBannedNewAbilities || IsNewFormChangeAbilityBannedInRandomizer(ability, species);
}

bool8 IsFormChangeAbilityRolePlayBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasGulpMissile(species);	
}

bool8 IsAbilityRolePlayBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRolePlayBannedAbilities || IsFormChangeAbilityRolePlayBanned(ability, species);
}

bool8 IsFormChangeAbilityRolePlayAttackerBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityRolePlayAttackerBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gRolePlayAttackerBannedAbilities || IsFormChangeAbilityRolePlayAttackerBanned(ability, species);
}

bool8 IsFormChangeAbilitySkillSwapBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilitySkillSwapBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gSkillSwapBannedAbilities || IsFormChangeAbilitySkillSwapBanned(ability, species);
}

bool8 IsFormChangeAbilityWorrySeedBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityWorrySeedBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gWorrySeedBannedAbilities || IsFormChangeAbilityWorrySeedBanned(ability, species);
}

bool8 IsFormChangeAbilityGastroAcidBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityGastroAcidBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gGastroAcidBannedAbilities || IsFormChangeAbilityGastroAcidBanned(ability, species);
}

bool8 IsFormChangeAbilityEntrainmentAttackerBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityEntrainmentAttackerBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gEntrainmentBannedAbilitiesAttacker || IsFormChangeAbilityEntrainmentAttackerBanned(ability, species);
}

bool8 IsFormChangeAbilityEntrainmentTargetBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityEntrainmentTargetBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gEntrainmentBannedAbilitiesTarget || IsFormChangeAbilityEntrainmentTargetBanned(ability, species);
}

bool8 IsFormChangeAbilitySimpleBeamBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilitySimpleBeamBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gSimpleBeamBannedAbilities || IsFormChangeAbilitySimpleBeamBanned(ability, species);
}

bool8 IsFormChangeAbilityReceiverBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityReceiverBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gReceiverBannedAbilities || IsFormChangeAbilityReceiverBanned(ability, species);
}

bool8 IsFormChangeAbilityTraceBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasZenMode(species) ||
		SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasGulpMissile(species);
}

bool8 IsAbilityTraceBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gTraceBannedAbilities || IsFormChangeAbilityTraceBanned(ability, species);
}

bool8 IsFormChangeAbilityNeutralizingGasBanned(u8 ability, u16 species)
{
	if(ability != ABILITY_FORM_CHANGE)
		return FALSE;

	return SpeciesHasStanceChange(species) ||
		SpeciesHasSchooling(species) ||
		SpeciesHasShieldsDown(species) ||
		SpeciesHasDisguise(species) ||
		SpeciesHasBattleBond(species) ||
		SpeciesHasPowerConstruct(species) ||
		SpeciesHasIceFace(species) ||
		SpeciesHasHungerSwitch(species) ||
		SpeciesHasRockyShelter(species) ||
		SpeciesHasGulpMissile(species);	
}

bool8 IsAbilityNeutralizingGasBanned(u8 ability, u16 species)
{
	return gSpecialAbilityFlags[ability].gNeutralizingGasBannedAbilities || IsFormChangeAbilityNeutralizingGasBanned(ability, species);
}

u8 GetTypeOfBlazeLikeAbilityFromSpecies(u16 species)
{
    if(gSpecialSpeciesFlags[species].hasVirtue)
        return TYPE_NORMAL;
    else if(gSpecialSpeciesFlags[species].hasRampage)
        return TYPE_FIGHTING;
    else if(gSpecialSpeciesFlags[species].hasCyclone)
        return TYPE_FLYING;
    else if(gSpecialSpeciesFlags[species].hasBiohazard)
        return TYPE_POISON;
    else if(gSpecialSpeciesFlags[species].hasUpheaval)
        return TYPE_GROUND;
    else if(gSpecialSpeciesFlags[species].hasBedrock)
        return TYPE_ROCK;
    else if(gSpecialSpeciesFlags[species].hasSwarm)
        return TYPE_BUG;
    else if(gSpecialSpeciesFlags[species].hasHaunted)
        return TYPE_GHOST;
    else if(gSpecialSpeciesFlags[species].hasTemper)
        return TYPE_STEEL;
    else if(gSpecialSpeciesFlags[species].hasBlaze)
        return TYPE_FIRE;
    else if(gSpecialSpeciesFlags[species].hasTorrent)
        return TYPE_WATER;
    else if(gSpecialSpeciesFlags[species].hasOvergrow)
        return TYPE_GRASS;
    else if(gSpecialSpeciesFlags[species].hasOvercharge)
        return TYPE_ELECTRIC;
    else if(gSpecialSpeciesFlags[species].hasBrainstorm)
        return TYPE_PSYCHIC;
    else if(gSpecialSpeciesFlags[species].hasSnowfall)
        return TYPE_ICE;
    else if(gSpecialSpeciesFlags[species].hasMythicRage)
        return TYPE_DRAGON;
    else if(gSpecialSpeciesFlags[species].hasWrath)
        return TYPE_DARK;
    else if(gSpecialSpeciesFlags[species].hasEnchant)
        return TYPE_FAIRY;
    else
        return gBaseStats[species].type1;
}

const u8* GetBlazeLikeNameFromSpecies(u16 species)
{
    return sBlazeLikeNames[GetTypeOfBlazeLikeAbilityFromSpecies(species)];
}

const u8* GetBlazeLikeDescriptionFromSpecies(u16 species)
{
    return sBlazeLikeDescriptions[GetTypeOfBlazeLikeAbilityFromSpecies(species)];
}

u8 GetAuraTypeFromSpecies(u16 species)
{
    if(gSpecialSpeciesFlags[species].hasNormalAura)
        return TYPE_NORMAL;
    else if(gSpecialSpeciesFlags[species].hasFightingAura)
        return TYPE_FIGHTING;
    else if(gSpecialSpeciesFlags[species].hasFlyingAura)
        return TYPE_FLYING;
    else if(gSpecialSpeciesFlags[species].hasPoisonAura)
        return TYPE_POISON;
    else if(gSpecialSpeciesFlags[species].hasGroundAura)
        return TYPE_GROUND;
    else if(gSpecialSpeciesFlags[species].hasRockAura)
        return TYPE_ROCK;
    else if(gSpecialSpeciesFlags[species].hasBugAura)
        return TYPE_BUG;
    else if(gSpecialSpeciesFlags[species].hasGhostAura)
        return TYPE_GHOST;
    else if(gSpecialSpeciesFlags[species].hasSteelAura)
        return TYPE_STEEL;
    else if(gSpecialSpeciesFlags[species].hasFireAura)
        return TYPE_FIRE;
    else if(gSpecialSpeciesFlags[species].hasWaterAura)
        return TYPE_WATER;
    else if(gSpecialSpeciesFlags[species].hasGrassAura)
        return TYPE_GRASS;
    else if(gSpecialSpeciesFlags[species].hasElectricAura)
        return TYPE_ELECTRIC;
    else if(gSpecialSpeciesFlags[species].hasPsychicAura)
        return TYPE_PSYCHIC;
    else if(gSpecialSpeciesFlags[species].hasIceAura)
        return TYPE_ICE;
    else if(gSpecialSpeciesFlags[species].hasDragonAura)
        return TYPE_DRAGON;
    else if(gSpecialSpeciesFlags[species].hasDarkAura)
        return TYPE_DARK;
    else if(gSpecialSpeciesFlags[species].hasFairyAura)
        return TYPE_FAIRY;
    else
        return gBaseStats[species].type1;
}

const u8* GetAuraNameFromSpecies(u16 species)
{
    return sAuraNames[GetAuraTypeFromSpecies(species)];
}

const u8* GetAuraDescriptionFromSpecies(u16 species)
{
    return sAuraDescriptions[GetAuraTypeFromSpecies(species)];
}

u16 GetCurrentAuraSpecies(u8 bankAtk, u8 bankDef)
{
    u16 species = SPECIES_NONE;

    for (u8 i = 0; i < gBattlersCount; i++)
    {
        if (ABILITY(i) == ABILITY_AURA && BATTLER_ALIVE(i))
        {
            return GetProperAbilityPopUpSpecies(i);
        }
    }

    if(ABILITY(bankAtk) == ABILITY_AURA)
        species = GetProperAbilityPopUpSpecies(bankAtk);
    else if(ABILITY(bankDef) == ABILITY_AURA)
        species = GetProperAbilityPopUpSpecies(bankDef);

    return species;

}

u8 GetAteTypeFromSpecies(u16 species)
{
    if(gSpecialSpeciesFlags[species].hasWarfare)
        return TYPE_FIGHTING;
    else if(gSpecialSpeciesFlags[species].hasAerilate)
        return TYPE_FLYING;
    else if(gSpecialSpeciesFlags[species].hasToxinate)
        return TYPE_POISON;
    else if(gSpecialSpeciesFlags[species].hasEarthbound)
        return TYPE_GROUND;
    else if(gSpecialSpeciesFlags[species].hasCragitate)
        return TYPE_ROCK;
    else if(gSpecialSpeciesFlags[species].hasInfectate)
        return TYPE_BUG;
    else if(gSpecialSpeciesFlags[species].hasChanneling)
        return TYPE_GHOST;
    else if(gSpecialSpeciesFlags[species].hasFortified)
        return TYPE_STEEL;
    else if(gSpecialSpeciesFlags[species].hasEmpyreal)
        return TYPE_FIRE;
    else if(gSpecialSpeciesFlags[species].hasHydrate)
        return TYPE_WATER;
    else if(gSpecialSpeciesFlags[species].hasNaturalize)
        return TYPE_GRASS;
    else if(gSpecialSpeciesFlags[species].hasGalvanize)
        return TYPE_ELECTRIC;
    else if(gSpecialSpeciesFlags[species].hasCognitive)
        return TYPE_PSYCHIC;
    else if(gSpecialSpeciesFlags[species].hasRefrigerate)
        return TYPE_ICE;
    else if(gSpecialSpeciesFlags[species].hasWyvernate)
        return TYPE_DRAGON;
    else if(gSpecialSpeciesFlags[species].hasAntagonize)
        return TYPE_DARK;
    else if(gSpecialSpeciesFlags[species].hasPixilate)
        return TYPE_FAIRY;
    else
        return gBaseStats[species].type1;
}

const u8* GetAteNameFromSpecies(u16 species)
{
    return sAteNames[GetAteTypeFromSpecies(species)];
}

const u8* GetAteDescriptionFromSpecies(u16 species)
{
    return sAteDescriptions[GetAteTypeFromSpecies(species)];
}

u8 GetSurgeTerrainFromSpecies(u16 species)
{
    if(gSpecialSpeciesFlags[species].hasElectricSurge || IsSpeciesOfType(species, TYPE_ELECTRIC))
        return ELECTRIC_TERRAIN;
    else if(gSpecialSpeciesFlags[species].hasGrassySurge || IsSpeciesOfType(species, TYPE_GRASS))
        return GRASSY_TERRAIN;
    else if(gSpecialSpeciesFlags[species].hasMistySurge || IsSpeciesOfType(species, TYPE_FAIRY))
        return MISTY_TERRAIN;
    else if(gSpecialSpeciesFlags[species].hasPsychicSurge || IsSpeciesOfType(species, TYPE_PSYCHIC))
        return PSYCHIC_TERRAIN;
    else
    {
        //probably relevant only in ability randomizer
        u32 mod = (u32)species * (u32)gSaveBlock2->playerTrainerId;
        u8 terrain = mod % 4;

        return ELECTRIC_TERRAIN + terrain;
    }
}

const u8* GetSurgeNameFromSpecies(u16 species)
{
    return sTerrainSurgeNames[GetSurgeTerrainFromSpecies(species)];
}

const u8* GetSurgeDescriptionFromSpecies(u16 species)
{
    return sTerrainSurgeDescriptions[GetSurgeTerrainFromSpecies(species)];
}

bool8 SpeciesHasModulator(u16 species)
{
    return gSpecialSpeciesFlags[species].hasModulator;
}

bool8 SpeciesHasWizardry(u16 species)
{
    return gSpecialSpeciesFlags[species].hasWizardry;
}

bool8 SpeciesHasMiraculous(u16 species)
{
    return gSpecialSpeciesFlags[species].hasMiraculous;
}

bool8 SpeciesHasWormhole(u16 species)
{
    return gSpecialSpeciesFlags[species].hasWormhole;
}

bool8 SpeciesHasPlasmaBurst(u16 species)
{
    return gSpecialSpeciesFlags[species].hasPlasmaBurst;
}