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

extern const u8 gText_TanglingHair[];
extern const u8 gText_Gooey[];
extern const u8 gText_AirLock[];
extern const u8 gText_ShellArmor[];
extern const u8 gText_ChillingNeigh[];
extern const u8 gText_Dazzling[];
extern const u8 gText_QueenlyMajesty[];
extern const u8 gText_FullMetalBody[];
extern const u8 gText_WimpOut[];
extern const u8 gText_Turboblaze[];
extern const u8 gText_Teravolt[];
extern const u8 gText_SolidRock[];
extern const u8 gText_PrismArmor[];
extern const u8 gText_IronBarbs[];
extern const u8 gText_Libero[];
extern const u8 gText_Magician[];
extern const u8 gText_Pickpocket[];
extern const u8 gText_Multiscale[];
extern const u8 gText_ShadowShield[];
extern const u8 gText_PowerOfAlchemy[];
extern const u8 gText_PropellerTail[];
extern const u8 gText_Cacophony[];


void HandleDuplicateNames_SummaryScreen()
{
    struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
    u8 ability = GetMonAbility(mon);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

    switch(ability)
    {
        case ABILITY_STUN_TOUCH:
            switch(species)
            {
                case SPECIES_DIGLETT_A:
                case SPECIES_DUGTRIO_A:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_TanglingHair);
                    break;
                case SPECIES_GOOMY:
                case SPECIES_SLIGGOO:
                case SPECIES_GOODRA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Gooey);
                    break;
            }
            break;
        case ABILITY_CLOUDNINE:
            switch(species)
            {
                case SPECIES_RAYQUAZA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_AirLock);
                    break;
            }
            break;
        case ABILITY_BATTLEARMOR:
            switch(species)
            {
                case SPECIES_SLOWBRO_MEGA:
                case SPECIES_SHELLDER:
                case SPECIES_CLOYSTER:
                case SPECIES_KRABBY:
                case SPECIES_KINGLER:
                case SPECIES_LAPRAS:
                case SPECIES_OMANYTE:
                case SPECIES_OMASTAR:
                case SPECIES_CORPHISH:
                case SPECIES_CRAWDAUNT:
                case SPECIES_CLAMPERL:
                case SPECIES_DWEBBLE:
                case SPECIES_CRUSTLE:
                case SPECIES_ESCAVALIER:
                case SPECIES_SHELMET:
                case SPECIES_TURTONATOR:
                case SPECIES_CHEWTLE:
                case SPECIES_DREDNAW:
                case SPECIES_TORKOAL:
                case SPECIES_TURTWIG:
                case SPECIES_GROTLE:
                case SPECIES_TORTERRA:
                case SPECIES_OSHAWOTT:
                case SPECIES_DEWOTT:
                case SPECIES_SAMUROTT:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_ShellArmor);
                    break;
            }
            break;
        case ABILITY_MOXIE:
            switch(species)
            {
                case SPECIES_GLASTRIER:
                case SPECIES_CALYREX_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_ChillingNeigh);
                    break;   
            }
            break;
        case ABILITY_MAJESTIC:
            switch(species)
            {
                case SPECIES_BRUXISH:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Dazzling);
                    break;
                case SPECIES_TSAREENA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_QueenlyMajesty);
                    break;
            }
            break;
        case ABILITY_CLEARBODY:
            switch(species)
            {
                case SPECIES_SOLGALEO:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_FullMetalBody);
                    break;
            }
            break;
        case ABILITY_EMERGENCYEXIT:
            switch(species)
            {
                case SPECIES_WIMPOD:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_WimpOut);
                    break;   
            }
            break;
        case ABILITY_MOLDBREAKER:
            switch(species)
            {
                case SPECIES_KYUREM_WHITE:
                case SPECIES_RESHIRAM:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Turboblaze);
                    break;
                case SPECIES_ZEKROM:
                case SPECIES_KYUREM_BLACK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Teravolt);
                    break;
            }
            break;
        case ABILITY_FILTER:
            switch(species)
            {
                case SPECIES_CAMERUPT:
                case SPECIES_RHYPERIOR:
                case SPECIES_TIRTOUGA:
                case SPECIES_CARRACOSTA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_SolidRock);
                    break;
                case SPECIES_NECROZMA:
                case SPECIES_NECROZMA_DUSK_MANE:
                case SPECIES_NECROZMA_DAWN_WINGS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_PrismArmor);
                    break;
            }
            break;
        case ABILITY_ROUGHSKIN:
            switch(species)
            {
                case SPECIES_FERROSEED:
                case SPECIES_FERROTHORN:
                case SPECIES_TOGEDEMARU:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_IronBarbs);
                    break;
            }
            break;
        case ABILITY_PROTEAN:
            switch(species)
            {
                case SPECIES_SCORBUNNY:
                case SPECIES_RABOOT:
                case SPECIES_CINDERACE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Libero);
                    break;
            }
            break;
        case ABILITY_PLUNDER:
            switch(species)
            {
                case SPECIES_HOOPA:
                case SPECIES_HOOPA_UNBOUND:
                case SPECIES_FENNEKIN:
                case SPECIES_BRAIXEN:
                case SPECIES_DELPHOX:
                case SPECIES_KLEFKI:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Magician);
                    break;
                case SPECIES_SNEASEL: 
                case SPECIES_SEEDOT:
                case SPECIES_NUZLEAF:
                case SPECIES_SHIFTRY:
                case SPECIES_WEAVILE:
                case SPECIES_BINACLE:
                case SPECIES_BARBARACLE:
                case SPECIES_IMPIDIMP:
                case SPECIES_MORGREM:
                case SPECIES_GRIMMSNARL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Pickpocket);
                    break;
            }
            break;
        case ABILITY_MYTHICALSHIELD:
            switch(species)
            {
                case SPECIES_DRAGONITE:
                case SPECIES_LUGIA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Multiscale);
                    break;
                case SPECIES_LUNALA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_ShadowShield);
                    break;
            }
            break;
        case ABILITY_RECEIVER:
            switch(species)
            {
                case SPECIES_GRIMER_A:
                case SPECIES_MUK_A:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_PowerOfAlchemy);
                    break;
            }
            break;
        case ABILITY_STALWART:
            switch(species)
            {
                case SPECIES_ARROKUDA:
                case SPECIES_BARRASKEWDA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_PropellerTail);
                    break;
            }  
            break;
        case ABILITY_SOUNDPROOF:
            switch(species)
            {
                case SPECIES_WHISMUR:
                case SPECIES_LOUDRED:
                case SPECIES_EXPLOUD:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gText_Cacophony);
                    break;
            }
    }   
}

void PokeSum_PrintAbilityNameAndDesc(void)
{
	struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
	u8 abilityNameColorIndex;

    HandleDuplicateNames_SummaryScreen();

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