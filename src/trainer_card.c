#include "defines.h"
#include "../include/bg.h"
#include "../include/evolution_scene.h"
#include "../include/field_control_avatar.h"
#include "../include/field_player_avatar.h"
#include "../include/field_effect.h"
#include "../include/field_screen_effect.h"
#include "../include/field_weather.h"
#include "../include/fieldmap.h"
#include "../include/item_use.h"
#include "../include/item_menu.h"
#include "../include/menu.h"
#include "../include/metatile_behavior.h"
#include "../include/overworld.h"
#include "../include/party_menu.h"
#include "../include/pokemon_icon.h"
#include "../include/pokemon_storage_system.h"
#include "../include/random.h"
#include "../include/script.h"
#include "../include/sound.h"
#include "../include/start_menu.h"
#include "../include/string_util.h"
#include "../include/text.h"
#include "../include/wild_encounter.h"
#include "../include/window.h"
#include "../include/constants/abilities.h"
#include "../include/constants/flags.h"
#include "../include/constants/hold_effects.h"
#include "../include/constants/items.h"
#include "../include/constants/item_effects.h"
#include "../include/constants/moves.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/songs.h"

#include "../include/new/battle_strings.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/evolution.h"
#include "../include/new/exp.h"
#include "../include/new/follow_me.h"
#include "../include/new/form_change.h"
#include "../include/new/item.h"
#include "../include/new/overworld.h"
#include "../include/new/party_menu.h"
#include "../include/new/trainer_card.h"
#include "../include/new/util.h"

extern struct TrainerCard gTrainerCards[4];
extern struct TrainerCardData *sTrainerCardDataPtr;

extern const u8 gText_TrainerCardLevelCap[];

static const u8 sTrainerCardTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};
//static const u8 sTrainerCardStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 sTimeColonInvisibleTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT};
static const u8 sTrainerCardFontIds[] = {0, 2, 0};

static const u8 sTrainerCardTimeHoursXPositions[] = {0x65, 0x55};
static const u8 sTrainerCardTimeHoursYPositions[] = {0x77, 0x67};
static const u8 sTrainerCardTimeMinutesXPositions[] = {0x7C, 0x6C};
static const u8 sTrainerCardTimeMinutesYPositions[] = {0x58, 0x59};
static const u8 sTrainerCardFrontNameXPositions[] = {0x14, 0x10};
static const u8 sTrainerCardFrontNameYPositions[] = {0x1D, 0x21};
static const u8 *const sTimeColonTextColors[] = {sTrainerCardTextColors, sTimeColonInvisibleTextColors};

#define gText_TrainerCardPokedex (const u8*) 0x8419CEF
#define gText_TrainerCardNull (const u8*) 0x8419CF7

void PrintPokedexOnCard(void)
{
    u8 buffer[10];
    u8 x;
    u16 levelCap;

    if (FlagGet(FLAG_HARD_LEVEL_CAP))
    {
        levelCap = GetCurrentLevelCap();
    	ConvertIntToDecimalStringN(buffer, levelCap, 0, 3);
		x = -128 - 6 * StringLength(buffer);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 20, 72, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardLevelCap);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], x, 72, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 138, 72, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardNull);
    }
    else if (FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        ConvertIntToDecimalStringN(buffer, sTrainerCardDataPtr->trainerCard.rse.caughtMonsCount, 0, 3);
        x = -128 - 6 * StringLength(buffer);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 20, 72, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardPokedex);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], x, 72, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
        AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 138, 72, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardNull);
    }
}

#define gText_TrainerCardMoney (const u8*) 0x8419CE7
#define gText_TrainerCardYen (const u8*) 0x8419CED
void PrintMoneyOnCard(void)
{
    u8 buffer[12];
    u8* txtPtr;
    u8 x;

    txtPtr = StringCopy(buffer, gText_TrainerCardYen);
    ConvertIntToDecimalStringN(txtPtr, sTrainerCardDataPtr->trainerCard.rse.money, STR_CONV_MODE_LEFT_ALIGN, 8);
    x = -130 - 6 * StringLength(buffer);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 20, 56, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardMoney);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], x, 56, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);

}


#define gText_TrainerCardTime (const u8*) 0x8419CFD
#define gText_Colon2 (const u8*) 0x8419CF8
void PrintTimeOnCard(void)
{
    u16 hours;
    u16 minutes;
    u8 buffer[6];

    hours = gSaveBlock2->playTimeHours;
    minutes = gSaveBlock2->playTimeMinutes;
    if (sTrainerCardDataPtr->isLink)
    {
        hours = sTrainerCardDataPtr->trainerCard.rse.playTimeHours;
        minutes = sTrainerCardDataPtr->trainerCard.rse.playTimeMinutes;
    }

    if (hours > 999)
        hours = 999;

    if (minutes > 59)
        minutes = 59;

    FillWindowPixelRect(1, PIXEL_FILL(0), sTrainerCardTimeHoursXPositions[sTrainerCardDataPtr->cardType], sTrainerCardTimeMinutesYPositions[sTrainerCardDataPtr->cardType], 50, 12);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], 20, 88, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardTime);

    ConvertIntToDecimalStringN(buffer, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], sTrainerCardTimeHoursXPositions[sTrainerCardDataPtr->cardType],
        sTrainerCardTimeMinutesYPositions[sTrainerCardDataPtr->cardType], sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], sTrainerCardTimeHoursYPositions[sTrainerCardDataPtr->cardType],
        sTrainerCardTimeMinutesYPositions[sTrainerCardDataPtr->cardType], sTimeColonTextColors[sTrainerCardDataPtr->timeColonInvisible], TEXT_SPEED_FF, gText_Colon2);

    ConvertIntToDecimalStringN(buffer, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], sTrainerCardTimeMinutesXPositions[sTrainerCardDataPtr->cardType], sTrainerCardTimeMinutesYPositions[sTrainerCardDataPtr->cardType], sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
}


#define gText_TrainerCardName (const u8*) 0x8419CDA
void PrintNameOnCardFront(void)
{
    u8 buffer[2][32];
    u8* txtPtr;

    txtPtr = StringCopy(buffer[0], gText_TrainerCardName);
    txtPtr = buffer[1];
    StringCopy(txtPtr, sTrainerCardDataPtr->trainerCard.rse.playerName);
    ConvertInternationalString(txtPtr, sTrainerCardDataPtr->language);
    StringAppend(buffer[0], txtPtr);
    AddTextPrinterParameterized3(1, sTrainerCardFontIds[1], sTrainerCardFrontNameXPositions[sTrainerCardDataPtr->cardType], sTrainerCardFrontNameYPositions[sTrainerCardDataPtr->cardType], sTrainerCardTextColors, TEXT_SPEED_FF, buffer[0]);
}