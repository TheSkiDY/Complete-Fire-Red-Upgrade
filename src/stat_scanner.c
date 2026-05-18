#include "../include/bg.h"
#include "../include/field_effect.h"
#include "../include/field_weather.h"
#include "../include/global.h"
#include "../include/gpu_regs.h"
#include "../include/main.h"
#include "../include/malloc.h"
#include "../include/menu.h"
#include "../include/mgba.h"
#include "../include/new_menu_helpers.h"
#include "../include/overworld.h"
#include "../include/palette.h"
#include "../include/party_menu.h"
#include "../include/pokemon.h"
#include "../include/random.h"
#include "../include/scanline_effect.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/string_util.h"
#include "../include/task.h"
#include "../include/text.h"
#include "../include/text_window.h"
#include "../include/wild_encounter.h"
#include "../include/window.h"

#include "../include/new/ability_util.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/build_pokemon_2.h"
#include "../include/new/damage_calc.h"
#include "../include/new/dns.h"
#include "../include/new/exp.h"
#include "../include/new/form_change.h"
#include "../include/new/ram_locs.h"
#include "../include/new/stat_scanner.h"
#include "../include/new/util.h"

#include "../include/new/Vanilla_functions.h"
#include "../include/constants/pokemon.h"
#include "../include/constants/songs.h"
#include "../include/constants/species.h"

//based on Greenphx's Custom-EV-IV-Display-Screen

extern u8 gTypeNames[][7];

static const struct BgTemplate sStatScannerBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 22,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    }, 
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 19,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    }
};

#define WIN0_WIDTH   29
#define WIN0_HEIGHT  2

#define WIN1_WIDTH   17
#define WIN1_HEIGHT  11
#define WIN1_BASEBLOCK  (WIN0_WIDTH * WIN0_HEIGHT)

#define WIN2_WIDTH   29
#define WIN2_HEIGHT  5
#define WIN2_BASEBLOCK (WIN1_WIDTH * WIN1_HEIGHT + WIN1_BASEBLOCK)

#define MON_SPRITE_X    18
#define MON_SPRITE_Y     5

#define HP_POS_Y 4
#define ATK_POS_Y HP_POS_Y + 14
#define DEF_POS_Y ATK_POS_Y + 14
#define SPATK_POS_Y DEF_POS_Y + 14
#define SPDEF_POS_Y SPATK_POS_Y + 14
#define SPD_POS_Y SPDEF_POS_Y + 14

#define BS_POS_X 53
#define EV_POS_X BS_POS_X + 26
#define IV_POS_X EV_POS_X + 26

static const struct WindowTemplate sStatScannerWinTemplates[] = {
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = WIN0_WIDTH,
        .height = WIN0_HEIGHT,
        .paletteNum = 15,
        .baseBlock = 0
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 4,
        .width = WIN1_WIDTH,
        .height = WIN1_HEIGHT,
        .paletteNum = 15,
        .baseBlock = WIN1_BASEBLOCK
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = WIN2_WIDTH,
        .height = WIN2_HEIGHT,
        .paletteNum = 15,
        .baseBlock = WIN2_BASEBLOCK
    }, 
    DUMMY_WIN_TEMPLATE
};

struct StatScannerData
{
    u8 state;
    u8 gfxStep;
    u8 callbackStep;
    u8 currentMon;
    u8 spriteTaskId;
    u8 EVs[NUM_STATS];
    u8 IVs[NUM_STATS];
    u8 baseStats[NUM_STATS];
    u16 totalStatsEV;
    u16 totalStatsIV;
    u16 totalStatsBS;
    u16 tilemapBuffer[0x400];
};

extern struct StatScannerData* gStatScannerData;

const u8 sColorBlackText[3]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
const u8 sColorGreyText[3]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREY, TEXT_COLOR_DARK_GREY};
const u8 sColorBlueText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREY};
const u8 sColorRedText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GREY};

const u8 *const sNatureColors[] = 
{
    sColorRedText,      // 1
    sColorBlackText,    // 0
    sColorBlueText,     // -1
};

extern const u8 gText_StatScannerHeaders[];
extern const u8 gText_Slash[];
extern const u8 gText_PsFiller[];
extern const u8 gText_AttackFiller[];
extern const u8 gText_DefenseFiller[];
extern const u8 gText_SpAttackFiller[];
extern const u8 gText_SpDefenseFiller[];
extern const u8 gText_SpeedFiller[];
extern const u8 gText_Space1[];
extern const u8 gText_Space2[];
extern const u8 gText_EndLine[];
extern const u8 gText_UnknownStats[];
extern const u8 gText_Total[];
extern const u8 gText_HappinesVal[];
extern const u8 gText_ItsEgg[];
extern const u8 gText_LessThan[];
extern const u8 gText_EggSteps[];

extern const s8 sNatureStatTable[][5];
void Task_StatScannerInit(u8 taskId);

void StatScanner_BackgroundInit()
{
	ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

void CB2_StatScannerInit()
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	UpdatePaletteFade();
}

void CB2_StatScanner()
{
	gStatScannerData = AllocZeroed(sizeof(*gStatScannerData));
	gStatScannerData->state = 0;
	gStatScannerData->gfxStep = 0;
	gStatScannerData->callbackStep = 0;
	gStatScannerData->currentMon = 0;
	StatScanner_BackgroundInit();
	CreateTask(Task_StatScannerInit, 0);
	SetMainCallback2(CB2_StatScannerInit);
}

void StatScanner_Oam()
{
	LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void StatScanner_ResetBGPos(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static void StatScanner_ResetGpu(void)
{
    void *vram = (void *)VRAM;
    DmaClearLarge16(3, vram, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

void StatScanner_VBlankHandler(void)
{
    StatScanner_ResetGpu();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sStatScannerBgTemplates, 2);
    StatScanner_ResetBGPos();
    InitWindows(sStatScannerWinTemplates);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetBgTilemapBuffer(1, gStatScannerData->tilemapBuffer);
    ShowBg(0);
    ShowBg(1);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
}

u8 StatScanner_LoadGfx(void)
{
    switch (gStatScannerData->gfxStep)
    {
    case 0:
        ResetTempTileDataBuffers();
        break;
    case 1:
        DecompressAndCopyTileDataToVram(1, BG_Stat_ScannerTiles, 0, 0, 0);
        break;
    case 2:
        if (!(FreeTempTileDataBuffersIfPossible() == 1))
        {
            break;
        }
        return 0;
    case 3:
        LoadCompressedPalette(BG_Stat_ScannerPal, 0x0, 0x20);
        LoadPalette(stdpal_get(0), 0xF0, 0x20);
        break;
    default:
        return 1;
    }
    gStatScannerData->gfxStep++;
    return 0;
}

void Task_StatScannerScriptShowMonPic(u8 taskId)
{
    struct Task * task = &gTasks[taskId];

    task->data[3]++;
    if (task->data[3] > 0x7FF0)
        task->data[3] = 0xFF;

    switch (task->data[0])
    {
    case 0:
        task->data[0]++;
        break;
    case 1:
        if (task->data[3] < 10)
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        else if (task->data[3] < 18)
        {
            gSprites[task->data[2]].pos1.y += 1;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 24)
        {
            gSprites[task->data[2]].pos1.y += 2;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 28)
        {
            gSprites[task->data[2]].pos1.y += 3;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 30)
        {
            gSprites[task->data[2]].pos1.y -= 3;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 32)
        {
            gSprites[task->data[2]].pos1.y -= 2;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 36)
        {
            gSprites[task->data[2]].pos1.y -= 1;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 40)
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        else if (task->data[3] < 44)
        {
            gSprites[task->data[2]].pos1.y += 1;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 46)
        {
            gSprites[task->data[2]].pos1.y += 2;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        else if (task->data[3] < 48)
        {
            gSprites[task->data[2]].pos1.y += 3;
            gSprites[task->data[2]].pos1.x -= 1 * 1;
        }
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->data[2]], task->data[2]);
        task->data[0]++;
        break;
    case 3:
        DestroyTask(taskId);
        break;
    }
}

void StatScanner_ShowPokemonSprite(u16 species, u32 otId, u32 personality, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreateMonSprite_FieldMove(species, otId, personality, 8 * x + 40, 8 * y + 40, FALSE);
    gStatScannerData->spriteTaskId = CreateTask(Task_StatScannerScriptShowMonPic, 80);

    gSprites[spriteId].hFlip = 0;

    //Esta línea ajusta el sprite del pokémon 2 píxeles a la izquierda,
    //mejora la posición del sprite en el background por defecto.
    gSprites[spriteId].pos1.x -= 2;

    gSprites[spriteId].pos1.y -= 32;
    gSprites[spriteId].pos1.x += 48;

    gTasks[gStatScannerData->spriteTaskId].data[0] = 0;
    gTasks[gStatScannerData->spriteTaskId].data[1] = species;
    gTasks[gStatScannerData->spriteTaskId].data[2] = spriteId;
    gTasks[gStatScannerData->spriteTaskId].data[3] = 0;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 0;
}

void StatScanner_HidePokemonSprite(u8 taskId)
{
    struct Task * task = &gTasks[taskId];
    task->data[0]++;
}

void StatScanner_ShowSprite(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 isEgg = GetMonData(mon, MON_DATA_IS_EGG, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);

    if (!isEgg)
    {
        StatScanner_ShowPokemonSprite(species, otId, personality, MON_SPRITE_X, MON_SPRITE_Y);
        PlayCry_Script(species, 0);
    }
    else
    {
        StatScanner_ShowPokemonSprite(SPECIES_EGG, 0, 0x8000, MON_SPRITE_X, MON_SPRITE_Y);
    }
}

void StatScanner_PrintHeader(struct Pokemon *mon)
{
    u8 temp = 0;

    temp = gStatScannerData->currentMon + 1;                              
    ConvertIntToDecimalStringN(gStringVar4, temp, STR_CONV_MODE_LEFT_ALIGN, 1);
    StringAppend(gStringVar4, gText_Slash);             
    temp = gPlayerPartyCount;                           
    ConvertIntToDecimalStringN(gStringVar1, temp, STR_CONV_MODE_LEFT_ALIGN, 1);
    StringAppend(gStringVar4, gStringVar1);             
    AddTextPrinterParameterized3(0, 0x2, 0x12, 0x4, sColorGreyText, 0, gStringVar4);

    StringCopy(gStringVar1, gText_StatScannerHeaderBS);              
    StringCopy(gStringVar2, gText_StatScannerHeaderEV);              
    StringCopy(gStringVar3, gText_StatScannerHeaderIV);              

    AddTextPrinterParameterized3(0, 0x2, 0x41, 0x5, sColorBlackText, 0, gStringVar1);
    AddTextPrinterParameterized3(0, 0x2, 0x5B, 0x5, sColorBlackText, 0, gStringVar2);
    AddTextPrinterParameterized3(0, 0x2, 0x71, 0x5, sColorBlackText, 0, gStringVar3);
    
    GetMonNickname(mon, gStringVar4);                   
    AddTextPrinterParameterized3(0, 0x2, 0x94, 0x2, sColorBlackText, 0, gStringVar4);
}

void PrintStat(u8 nature, u8 stat)
{
    u8 colorIndex;
    if (stat == STAT_HP)
        colorIndex = 1;
    else
        colorIndex = 1 + sNatureStatTable[nature][stat - 1];

    ConvertIntToDecimalStringN(gStringVar1, gStatScannerData->baseStats[stat], STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gStatScannerData->EVs[stat], STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gStatScannerData->IVs[stat], STR_CONV_MODE_RIGHT_ALIGN, 2);

    switch (stat)
    {
        case STAT_HP:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, HP_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, HP_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, HP_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        case STAT_ATK:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, ATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, ATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, ATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        case STAT_DEF:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, DEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, DEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, DEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        case STAT_SPATK:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, SPATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, SPATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, SPATK_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        case STAT_SPDEF:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, SPDEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, SPDEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, SPDEF_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        case STAT_SPEED:
            AddTextPrinterParameterized3(1, 2, BS_POS_X, SPD_POS_Y, sNatureColors[colorIndex], 0, gStringVar1);
            AddTextPrinterParameterized3(1, 2, EV_POS_X, SPD_POS_Y, sNatureColors[colorIndex], 0, gStringVar2);
            AddTextPrinterParameterized3(1, 2, IV_POS_X, SPD_POS_Y, sNatureColors[colorIndex], 0, gStringVar3);
            break;
        default:
            break;
    }

}

void StatScanner_PrintNumericalStats(u8 nature, u8 isEgg)
{
    if (!isEgg)
    {
        PrintStat(nature, STAT_HP);
        PrintStat(nature, STAT_ATK);
        PrintStat(nature, STAT_DEF);
        PrintStat(nature, STAT_SPATK);
        PrintStat(nature, STAT_SPDEF);
        PrintStat(nature, STAT_SPEED);
    }
    else
    {
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x4, sColorBlackText, 0, gText_UnknownStats);
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x12, sColorBlackText, 0, gText_UnknownStats);
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x20, sColorBlackText, 0, gText_UnknownStats);
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x2E, sColorBlackText, 0, gText_UnknownStats);
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x3C, sColorBlackText, 0, gText_UnknownStats);
        AddTextPrinterParameterized3(1, 0x2, 0x33, 0x4A, sColorBlackText, 0, gText_UnknownStats);
    }
}

static u8 GetDigits(u16 num)
{
    if (num < 10)
        return 1;
    else if (num < 100)
        return 2;
    else if (num < 1000)
        return 3;
    else if (num < 10000)
        return 4;
    else
        return 5;
}

static void StatScanner_PrintFooter(struct Pokemon* mon)
{
    u16 temp = 0;
    u8 isEgg    = GetMonData(mon, MON_DATA_IS_EGG, NULL);
    u8 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    u8 type = CalcMonHiddenPowerType(mon);

    if(!isEgg)
    {
        //hp type
        StringCopy(gStringVar4, gText_HiddenPowerType);
        StringAppend(gStringVar4, (u8*)&(gTypeNames[type]));
        AddTextPrinterParameterized3(2, 2, 12, 6, sColorBlackText, 0, gStringVar4);

        //happiness
        StringCopy(gStringVar4, gText_HappinesVal);
        ConvertIntToDecimalStringN(gStringVar2, friendship, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(gStringVar4, gStringVar2);
        AddTextPrinterParameterized3(2, 2, 12, 20, sColorBlackText, 0, gStringVar4);
        
        
    }
    else
    {
        StringCopy(gStringVar4, gText_LessThan);
        temp = (friendship + 1) * 0xFF;
        ConvertIntToDecimalStringN(gStringVar2, temp, STR_CONV_MODE_LEFT_ALIGN, GetDigits(temp));
        StringAppend(gStringVar4, gStringVar2);
        StringAppend(gStringVar4, gText_EggSteps);
        AddTextPrinterParameterized3(2, 2, 2, 5, sColorBlackText, 0, gStringVar4);
    }
}


void StatScanner_PrintText(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 nature   = GetNature(mon);
    u8 isEgg    = GetMonData(mon, MON_DATA_IS_EGG, NULL);

    gStatScannerData->totalStatsEV = 0;
    gStatScannerData->totalStatsIV = 0;
    gStatScannerData->totalStatsBS = 0;

    gStatScannerData->baseStats[STAT_HP] = gBaseStats[species].baseHP;
    gStatScannerData->EVs[STAT_HP] = GetMonData(mon, MON_DATA_HP_EV, NULL);
    gStatScannerData->IVs[STAT_HP] = GetMonData(mon, MON_DATA_HP_IV, NULL);

    gStatScannerData->baseStats[STAT_ATK] = gBaseStats[species].baseAttack;
    gStatScannerData->EVs[STAT_ATK] = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    gStatScannerData->IVs[STAT_ATK] = GetMonData(mon, MON_DATA_ATK_IV, NULL);

    gStatScannerData->baseStats[STAT_DEF] = gBaseStats[species].baseDefense;
    gStatScannerData->EVs[STAT_DEF] = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    gStatScannerData->IVs[STAT_DEF] = GetMonData(mon, MON_DATA_DEF_IV, NULL);

    gStatScannerData->baseStats[STAT_SPATK] = gBaseStats[species].baseSpAttack;
    gStatScannerData->EVs[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    gStatScannerData->IVs[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    
    gStatScannerData->baseStats[STAT_SPDEF] = gBaseStats[species].baseSpDefense;
    gStatScannerData->EVs[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    gStatScannerData->IVs[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    
    gStatScannerData->baseStats[STAT_SPEED] = gBaseStats[species].baseSpeed;
    gStatScannerData->EVs[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    gStatScannerData->IVs[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED_IV, NULL);

    for (int i = 0; i < NUM_STATS; i++)
    {
        gStatScannerData->totalStatsEV += gStatScannerData->EVs[i];
        gStatScannerData->totalStatsIV += gStatScannerData->IVs[i];
        gStatScannerData->totalStatsBS += gStatScannerData->baseStats[i];
    }

    FillWindowPixelBuffer(0, 0);
    FillWindowPixelBuffer(1, 0);
    FillWindowPixelBuffer(2, 0);

    StatScanner_PrintHeader(mon);
    StatScanner_PrintNumericalStats(nature, isEgg);
    StatScanner_PrintFooter(mon);

    PutWindowTilemap(0);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
}

void Task_StatScannerReturnToOverworld(u8 taskId)
{
    if (gPaletteFade->active)
        return;

    DestroyTask(taskId);
    FreeAllWindowBuffers();
    Free(gStatScannerData);
    SetMainCallback2(CB2_ReturnToFieldFromDiploma);
}

void Task_StatScannerWaitForExit(u8 taskId)
{
    switch (gStatScannerData->state)
    {
        case 0:
            gStatScannerData->state++;
            break;
        case 1:
            if (JOY_REPT(DPAD_DOWN) && gPlayerPartyCount > 1)
            {
                //PlaySE(SE_SELECT);
                if (gStatScannerData->currentMon == (gPlayerPartyCount - 1))
                    gStatScannerData->currentMon = 0;
                else
                    gStatScannerData->currentMon++;
                StatScanner_HidePokemonSprite(gStatScannerData->spriteTaskId);
                StatScanner_ShowSprite(&gPlayerParty[gStatScannerData->currentMon]);
                StatScanner_PrintText(&gPlayerParty[gStatScannerData->currentMon]);
            }
            if (JOY_REPT(DPAD_UP) && gPlayerPartyCount > 1)
            {
                //PlaySE(SE_SELECT);
                if (gStatScannerData->currentMon == 0)
                    gStatScannerData->currentMon = (gPlayerPartyCount - 1);
                else
                    gStatScannerData->currentMon--;
                StatScanner_HidePokemonSprite(gStatScannerData->spriteTaskId);
                StatScanner_ShowSprite(&gPlayerParty[gStatScannerData->currentMon]);
                StatScanner_PrintText(&gPlayerParty[gStatScannerData->currentMon]);
            }
            if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_RG_CARD1);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gStatScannerData->state++;
            }
            break;
        case 2:
            if (!IsCryPlaying())
                Task_StatScannerReturnToOverworld(taskId);
            break;
    }
}

void Task_StatScannerInit(u8 taskId)
{
	switch(gStatScannerData->callbackStep)
	{
		case 0:
			SetVBlankCallback(NULL);
			break;
		case 1:
			StatScanner_VBlankHandler();
			break;
		case 2:
			if(!StatScanner_LoadGfx())
				return;
			break;
		case 3:
			CopyToBgTilemapBuffer(1, BG_Stat_ScannerMap, 0, 0);
			break;
		case 4:
			SetGpuReg(REG_OFFSET_BG1HOFS, 0);
			break;
		case 5:
			StatScanner_ShowSprite(&gPlayerParty[gStatScannerData->currentMon]);
            StatScanner_PrintText(&gPlayerParty[gStatScannerData->currentMon]);
            break;
        case 6:
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            break;
        case 7:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            break;
        case 8:
            SetVBlankCallback(StatScanner_Oam);
            break;
        default:
            if(gPaletteFade->active)
            {
                break;
            }
            gTasks[taskId].func = Task_StatScannerWaitForExit;
	}
    gStatScannerData->callbackStep++;
}

