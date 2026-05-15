#include "defines.h"
#include "../include/battle.h"
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
#include "../include/new/ability_util.h"
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

static const u8 sNatureTextColors[][3] = 
{
    {0, 7, 10}, //Blue
    {0, 14, 10},
    {0, 1, 10}, //Red
};

void PokeSum_PrintAbilityNameAndDesc(void)
{
	struct Pokemon* mon = &(sMonSummaryScreen->currentMon);
	u8 abilityNameColorIndex;

    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[5], 0);

    if(mon->hiddenAbility == TRUE)
    	abilityNameColorIndex = 1;
    else
    	abilityNameColorIndex = 0;

    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[4], 2, 4, 2, sLevelNickTextColors[abilityNameColorIndex], TEXT_SPEED_FF, 
    	sMonSummaryScreen->summary.abilityNameStrBuf);

    AddTextPrinterParameterized4(sMonSummaryScreen->windowIds[5], 2, 4, 0, 0, -2, sLevelNickTextColors[0], TEXT_SPEED_FF,
        sMonSummaryScreen->summary.abilityDescStrBuf);

}

extern const s8 sNatureStatTable[][5];

#define RANKING_E_MINUS 0
#define RANKING_E 1
#define RANKING_E_PLUS 2
#define RANKING_D_MINUS 3
#define RANKING_D 4
#define RANKING_D_PLUS 5
#define RANKING_C_MINUS 6
#define RANKING_C 7
#define RANKING_C_PLUS 8
#define RANKING_B_MINUS 9
#define RANKING_B 10
#define RANKING_B_PLUS 11
#define RANKING_A_MINUS 12
#define RANKING_A 13
#define RANKING_A_PLUS 14
#define RANKING_S 15

extern const u8 IV_RankingsTiles[];
extern const u8 IV_RankingsPal[];

static const u8 sIVRankingsCoords[][2] = 
{
    [RANKING_E_MINUS] = {0, 0},
    [RANKING_E] = {16, 0},
    [RANKING_E_PLUS] = {32, 0},
    [RANKING_D_MINUS] = {48, 0},
    [RANKING_D] = {64, 0},
    [RANKING_D_PLUS] = {80, 0},
    [RANKING_C_MINUS] = {96, 0},
    [RANKING_C] = {112, 0},
    [RANKING_C_PLUS] = {0, 8},
    [RANKING_B_MINUS] = {16, 8},
    [RANKING_B] = {32, 8},
    [RANKING_B_PLUS] = {48, 8},
    [RANKING_A_MINUS] = {64, 8},
    [RANKING_A] = {80, 8},
    [RANKING_A_PLUS] = {96, 8},
    [RANKING_S] = {112, 8},
};

static const u8 sIVRankingTable[] = 
{
    [0 ... 2] = RANKING_E_MINUS,
    [3 ... 4] = RANKING_E,
    [5 ... 6] = RANKING_E_PLUS,
    [7 ... 8] = RANKING_D_MINUS,
    [9 ... 10] = RANKING_D,
    [11 ... 12] = RANKING_D_PLUS,
    [13 ... 14] = RANKING_C_MINUS,
    [15 ... 16] = RANKING_C,
    [17 ... 18] = RANKING_C_PLUS,
    [19 ... 20] = RANKING_B_MINUS,
    [21 ... 22] = RANKING_B,
    [23 ... 24] = RANKING_B_PLUS,
    [25 ... 26] = RANKING_A_MINUS,
    [27 ... 28] = RANKING_A,
    [29 ... 30] = RANKING_A_PLUS,
    [31] = RANKING_S,
};

#define IV_RANKINGS_SHEET_WIDTH 128
#define IV_RANKINGS_SHEET_HEIGHT 16
#define IV_RANKING_WIDTH 16
#define IV_RANKING_HEIGHT 8

void PrintSkillsPage(void)
{
    u8 hpIv, atkIv, defIv, spAtkIv, spDefIv, speedIv;
    const s8* natureModifier = sNatureStatTable[GetNature(&sMonSummaryScreen->currentMon)];

    hpIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_IV, NULL);
    atkIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_IV, NULL);
    defIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_IV, NULL);
    spAtkIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_IV, NULL);
    spDefIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_IV, NULL);
    speedIv = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_IV, NULL);

    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 40 + sMonSkillsPrinterXpos->curHpStr, 0, sLevelNickTextColors[0], TEXT_SPEED_FF, sMonSummaryScreen->summary.curHpStrBuf);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 66 + sMonSkillsPrinterXpos->atkStr, 20, sNatureTextColors[1 + natureModifier[STAT_ATK-1]], TEXT_SPEED_FF, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_ATK]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 66 + sMonSkillsPrinterXpos->defStr, 32, sNatureTextColors[1 + natureModifier[STAT_DEF-1]], TEXT_SPEED_FF, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_DEF]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 66 + sMonSkillsPrinterXpos->spAStr, 44, sNatureTextColors[1 + natureModifier[STAT_SPATK-1]], TEXT_SPEED_FF, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPA]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 66 + sMonSkillsPrinterXpos->spDStr, 56, sNatureTextColors[1 + natureModifier[STAT_SPDEF-1]], TEXT_SPEED_FF, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPD]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 66 + sMonSkillsPrinterXpos->speStr, 68, sNatureTextColors[1 + natureModifier[STAT_SPD-1]], TEXT_SPEED_FF, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPE]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 0 + sMonSkillsPrinterXpos->expStr, 92, sLevelNickTextColors[0], TEXT_SPEED_FF, sMonSummaryScreen->summary.expPointsStrBuf);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[3], 2, 55 + sMonSkillsPrinterXpos->toNextLevel, 92, sLevelNickTextColors[0], TEXT_SPEED_FF, sMonSummaryScreen->summary.expToNextLevelStrBuf);

    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[hpIv]][0], sIVRankingsCoords[sIVRankingTable[hpIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 2, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[atkIv]][0], sIVRankingsCoords[sIVRankingTable[atkIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 22, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[defIv]][0], sIVRankingsCoords[sIVRankingTable[defIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 34, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[spAtkIv]][0], sIVRankingsCoords[sIVRankingTable[spAtkIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 46, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[spDefIv]][0], sIVRankingsCoords[sIVRankingTable[spDefIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 58, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
    BlitBitmapRectToWindow(sMonSummaryScreen->windowIds[3], IV_RankingsTiles, sIVRankingsCoords[sIVRankingTable[speedIv]][0], sIVRankingsCoords[sIVRankingTable[speedIv]][1], IV_RANKINGS_SHEET_WIDTH, IV_RANKINGS_SHEET_HEIGHT, 42, 70, IV_RANKING_WIDTH, IV_RANKING_HEIGHT);
}