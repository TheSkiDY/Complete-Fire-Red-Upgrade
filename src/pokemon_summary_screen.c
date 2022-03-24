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
        case ABILITY_BLAZE:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Virtue);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Rampage);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Cyclone);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Biohazard);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Upheaval);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Bedrock);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Swarm);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Haunted);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Temper);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Blaze);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Torrent);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Overgrow);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Overcharged);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Brainstorm);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Snowfall);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_MythicRage);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Wrath);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Enchant);
                    break;
            }
            break;
        case ABILITY_DARKAURA:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_NormalAura);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_FightingAura);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_FlyingAura);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_PoisonAura);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_GroundAura);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_RockAura);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_BugAura);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_GhostAura);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_SteelAura);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_FireAura);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_WaterAura);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_ElectricAura);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_GrassAura);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_PsychicAura);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_IceAura);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_DragonAura);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_DarkAura);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_FairyAura);
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

    switch(ability)
    {
        case ABILITY_STUN_TOUCH:
            switch(species)
            {
                case SPECIES_DIGLETT_A:
                case SPECIES_DUGTRIO_A:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_TanglingHair);
                    break;
                case SPECIES_GOOMY:
                case SPECIES_SLIGGOO:
                case SPECIES_SLIGGOO_H:
                case SPECIES_GOODRA:
                case SPECIES_GOODRA_H:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Gooey);
                    break;
            }
            break;
        case ABILITY_DARKAURA:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_NormalAura);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_FightingAura);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_FlyingAura);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_PoisonAura);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_GroundAura);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_RockAura);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_BugAura);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_GhostAura);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_SteelAura);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_FireAura);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_WaterAura);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_ElectricAura);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_GrassAura);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_PsychicAura);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_IceAura);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_DragonAura);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_DarkAura);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_FairyAura);
                    break;
            }
            break;
        case ABILITY_BLAZE:
            switch(gBaseStats[species].type1)
            {
                case TYPE_NORMAL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Virtue);
                    break;
                case TYPE_FIGHTING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Rampage);
                    break;
                case TYPE_FLYING:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Cyclone);
                    break;
                case TYPE_POISON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Biohazard);
                    break;
                case TYPE_GROUND:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Upheaval);
                    break;
                case TYPE_ROCK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Bedrock);
                    break;
                case TYPE_BUG:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Swarm);
                    break;
                case TYPE_GHOST:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Haunted);
                    break;
                case TYPE_STEEL:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Temper);
                    break;
                case TYPE_FIRE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Blaze);
                    break;
                case TYPE_WATER:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Torrent);
                    break;
                case TYPE_ELECTRIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Overcharged);
                    break;
                case TYPE_GRASS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Overgrow);
                    break;
                case TYPE_PSYCHIC:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Brainstorm);
                    break;
                case TYPE_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Snowfall);
                    break;
                 case TYPE_DRAGON:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_MythicRage);
                    break;
                 case TYPE_DARK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Wrath);
                    break;
                 case TYPE_FAIRY:
                    StringCopy(sMonSummaryScreen->summary.abilityDescStrBuf, gAbilityDesc_Enchant);
                    break;
            }
            break;
        case ABILITY_CLOUDNINE:
            switch(species)
            {
                case SPECIES_RAYQUAZA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_AirLock);
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
                case SPECIES_SAMUROTT_H:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_ShellArmor);
                    break;
            }
            break;
        case ABILITY_MOXIE:
            switch(species)
            {
                case SPECIES_GLASTRIER:
                case SPECIES_CALYREX_ICE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_ChillingNeigh);
                    break;   
            }
            break;
        case ABILITY_MAJESTIC:
            switch(species)
            {
                case SPECIES_BRUXISH:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Dazzling);
                    break;
                case SPECIES_TSAREENA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_QueenlyMajesty);
                    break;
            }
            break;
        case ABILITY_CLEARBODY:
            switch(species)
            {
                case SPECIES_SOLGALEO:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_FullMetalBody);
                    break;
            }
            break;
        case ABILITY_EMERGENCYEXIT:
            switch(species)
            {
                case SPECIES_WIMPOD:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_WimpOut);
                    break;   
            }
            break;
        case ABILITY_MOLDBREAKER:
            switch(species)
            {
                case SPECIES_KYUREM_WHITE:
                case SPECIES_RESHIRAM:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Turboblaze);
                    break;
                case SPECIES_ZEKROM:
                case SPECIES_KYUREM_BLACK:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Teravolt);
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
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_SolidRock);
                    break;
                case SPECIES_NECROZMA:
                case SPECIES_NECROZMA_DUSK_MANE:
                case SPECIES_NECROZMA_DAWN_WINGS:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_PrismArmor);
                    break;
            }
            break;
        case ABILITY_ROUGHSKIN:
            switch(species)
            {
                case SPECIES_FERROSEED:
                case SPECIES_FERROTHORN:
                case SPECIES_TOGEDEMARU:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_IronBarbs);
                    break;
            }
            break;
        case ABILITY_PROTEAN:
            switch(species)
            {
                case SPECIES_SCORBUNNY:
                case SPECIES_RABOOT:
                case SPECIES_CINDERACE:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Libero);
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
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Magician);
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
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Pickpocket);
                    break;
            }
            break;
        case ABILITY_MYTHICALSHIELD:
            switch(species)
            {
                case SPECIES_DRAGONITE:
                case SPECIES_LUGIA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Multiscale);
                    break;
                case SPECIES_LUNALA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_ShadowShield);
                    break;
            }
            break;
        case ABILITY_RECEIVER:
            switch(species)
            {
                case SPECIES_GRIMER_A:
                case SPECIES_MUK_A:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_PowerOfAlchemy);
                    break;
            }
            break;
        case ABILITY_STALWART:
            switch(species)
            {
                case SPECIES_ARROKUDA:
                case SPECIES_BARRASKEWDA:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_PropellerTail);
                    break;
            }  
            break;
        case ABILITY_SOUNDPROOF:
            switch(species)
            {
                case SPECIES_WHISMUR:
                case SPECIES_LOUDRED:
                case SPECIES_EXPLOUD:
                    StringCopy(sMonSummaryScreen->summary.abilityNameStrBuf, gAbilityName_Cacophony);
                    break;
            }
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