#include "defines.h"
#include "../include/event_data.h"
#include "../include/menu.h"
#include "../include/pokemon_icon.h"
#include "../include/pokemon_storage_system.h"
#include "../include/pokemon_storage_system_internal.h"
#include "../include/pokemon_summary_screen.h"
#include "../include/string_util.h"
#include "../include/text.h"
#include "../include/window.h"
#include "../include/constants/flags.h"
#include "../include/constants/abilities.h"
#include "../include/constants/vars.h"

#include "../include/new/build_pokemon.h"
#include "../include/new/ability_battle_scripts.h"
#include "Tables/duplicate_abilities.h"
#include "../include/new/form_change.h"
#include "../include/new/frontier.h"
#include "../include/new/item.h"
#include "../include/new/pokemon_storage_system.h"


static const u8 sLevelNickTextColors[][3] =
{
    {0, 14, 10},
    {0, 8, 10},
    {0, 9, 8},
    {0, 5, 4},
    {0, 2, 3},
    {0, 11, 10},
};


void HandleDuplicateDescriptions_SummaryScreen()
{
    struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
    u8 ability = GetMonAbility(mon);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

    switch(ability)
    {
        case ABILITY_BLAZE_LIKE:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_VIRTUE);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_RAMPAGE);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_CYCLONE);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_BIOHAZARD);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_UPHEAVAL);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_BEDROCK);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_SWARM);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_HAUNTED);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_TEMPER);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_BLAZE);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_TORRENT);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_OVERGROW);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_OVERCHARGE);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_BRAINSTORM);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_SNOWFALL);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_MYTHIC_RAGE);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_WRATH);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_ENCHANT);
                    break;
            }
            break;
        case ABILITY_DARKAURA:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_NORMAL_AURA);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_FIGHTING_AURA);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_FLYING_AURA);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_POISON_AURA);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_GROUND_AURA);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_ROCK_AURA);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_BUG_AURA);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_GHOST_AURA);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_STEEL_AURA);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_FIRE_AURA);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_WATER_AURA);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_ELECTRIC_AURA);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_GRASS_AURA);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_PSYCHIC_AURA);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_ICE_AURA);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DRAGON_AURA);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_DARK_AURA);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, DESC_DUPE_FAIRY_AURA);
                    break;
            }
            break;
    }

}

void HandleDuplicateNames_SummaryScreen()
{
    struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
    u8 ability = GetMonAbility(mon);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

    for(u8 i = 0; i < ARRAY_COUNT(sDuplicateAbilities); i++)
    {
        if(ability == sDuplicateAbilities[i].currAbility && species == sDuplicateAbilities[i].species)
        {
            StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, sDuplicateAbilities[i].replaceAbilityString);
            break;
        }
    }

    switch(ability)
    {
        case ABILITY_DARKAURA:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_NORMAL_AURA);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_FIGHTING_AURA);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_FLYING_AURA);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_POISON_AURA);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_GROUND_AURA);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_ROCK_AURA);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_BUG_AURA);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_GHOST_AURA);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_STEEL_AURA);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_FIRE_AURA);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_WATER_AURA);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_ELECTRIC_AURA);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_GRASS_AURA);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_PSYCHIC_AURA);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_ICE_AURA);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DRAGON_AURA);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_DARK_AURA);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_FAIRY_AURA);
                    break;
            }
            break;
        case ABILITY_BLAZE_LIKE:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_VIRTUE);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_RAMPAGE);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_CYCLONE);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_BIOHAZARD);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_UPHEAVAL);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_BEDROCK);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_SWARM);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_HAUNTED);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_TEMPER);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_BLAZE);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_TORRENT);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_OVERCHARGE);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_DUPE_OVERGROW);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_BRAINSTORM);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_SNOWFALL);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_MYTHIC_RAGE);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_WRATH);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, NAME_ENCHANT);
                    break;
            }
            break;
    }   
}

void PokeSum_PrintAbilityNameAndDesc(void)
{
	struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
	u8 abilityNameColorIndex;

    HandleDuplicateNames_SummaryScreen();
    HandleDuplicateDescriptions_SummaryScreen();

    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[5], 0);

    if(mon->hiddenAbility == TRUE)
    	abilityNameColorIndex = 1;
    else
    	abilityNameColorIndex = 0;

    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[4], 2, 4, 2, sLevelNickTextColors[abilityNameColorIndex], TEXT_SPEED_FF, 
    	sMonSummaryScreen->summary.abilityNameStrBuf);

    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[5], 2, 4, 0, sLevelNickTextColors[0], TEXT_SPEED_FF,
		sMonSummaryScreen->summary.abilityDescStrBuf);

}