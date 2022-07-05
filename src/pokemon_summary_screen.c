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
    u8 firstType = gBaseStats[species].type1;

    switch(ability)
    {
        case ABILITY_BLAZE_LIKE:
            StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gBlazeAbilityDescriptions[firstType]);
            return;
        case ABILITY_AURA_LIKE:
            StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAuraAbilityDescriptions[firstType]);
            return;
    }
}

void HandleDuplicateNames_SummaryScreen()
{
    struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
    u8 ability = GetMonAbility(mon);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 firstType = gBaseStats[species].type1;

    for(u8 i = 0; i < ARRAY_COUNT(sDuplicateAbilities); i++)
    {
        if(ability == sDuplicateAbilities[i].currAbility && species == sDuplicateAbilities[i].species)
        {
            StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, sDuplicateAbilities[i].replaceAbilityString);
            return;
        }
    }
    switch(ability)
    {
        case ABILITY_BLAZE_LIKE:
            StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gBlazeAbilityNames[firstType]);
            return;
        case ABILITY_AURA_LIKE:
            StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAuraAbilityNames[firstType]);
            return;
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