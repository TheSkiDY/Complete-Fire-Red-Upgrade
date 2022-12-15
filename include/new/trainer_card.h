#ifndef GUARD_CONSTANTS_TRAINER_CARD_H
#define GUARD_CONSTANTS_TRAINER_CARD_H

#include "../global.h"

#define TRAINER_CARD_PROFILE_LENGTH  4
#define TRAINER_CARD_STICKER_TYPES   3

#define CARD_TYPE_FRLG     0
#define CARD_TYPE_RSE      1

#define MON_ICON_TINT_NORMAL  0
#define MON_ICON_TINT_BLACK   1
#define MON_ICON_TINT_PINK    2
#define MON_ICON_TINT_SEPIA   3

#define NUM_LINK_TRAINER_CARD_CLASSES 8

enum
{
    TRAINER_CARD_STRING_NAME = 0,
    TRAINER_CARD_STRING_HOF_TIME,
    TRAINER_CARD_STRING_LINK_RECORD,
    TRAINER_CARD_STRING_WIN_LOSS,
    TRAINER_CARD_STRING_LINK_WINS,
    TRAINER_CARD_STRING_LINK_LOSSES,
    TRAINER_CARD_STRING_TRADES,
    TRAINER_CARD_STRING_TRADE_COUNT,
    TRAINER_CARD_STRING_BERRY_CRUSH,
    TRAINER_CARD_STRING_BERRY_CRUSH_COUNT,
    TRAINER_CARD_STRING_UNION_ROOM,
    TRAINER_CARD_STRING_UNION_ROOM_NUM,
    TRAINER_CARD_STRING_COUNT,
};


struct TrainerCardRSE
{
    /*0x00*/ u8 gender;
    /*0x01*/ u8 stars;
    /*0x02*/ bool8 hasPokedex;
    /*0x03*/ bool8 caughtAllHoenn;
    /*0x04*/ bool8 hasAllPaintings;
    /*0x06*/ u16 hofDebutHours;
    /*0x08*/ u16 hofDebutMinutes;
    /*0x0A*/ u16 hofDebutSeconds;
    /*0x0C*/ u16 caughtMonsCount;
    /*0x0E*/ u16 trainerId;
    /*0x10*/ u16 playTimeHours;
    /*0x12*/ u16 playTimeMinutes;
    /*0x14*/ u16 linkBattleWins;
    /*0x16*/ u16 linkBattleLosses;
    /*0x18*/ u16 battleTowerWins;
    /*0x1A*/ u16 battleTowerStraightWins;
    /*0x1C*/ u16 contestsWithFriends;
    /*0x1E*/ u16 pokeblocksWithFriends;
    /*0x20*/ u16 pokemonTrades;
    /*0x24*/ u32 money;
    /*0x28*/ u16 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH];
    /*0x30*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
};

struct TrainerCard
{
    /*0x00*/ struct TrainerCardRSE rse;
    /*0x38*/ u8 version;
    /*0x3A*/ bool16 hasAllFrontierSymbols;
    /*0x3C*/ u32 berryCrushPoints;
    /*0x40*/ u32 unionRoomNum;
    /*0x44*/ u32 berriesPicked;
    /*0x48*/ u32 jumpsInRow;
    /*0x4C*/ bool8 shouldDrawStickers;
    /*0x4D*/ bool8 hasAllMons;
    /*0x4E*/ u8 monIconTint;
    /*0x4F*/ u8 facilityClass;
    /*0x50*/ u8 stickers[TRAINER_CARD_STICKER_TYPES];
    /*0x54*/ u16 monSpecies[PARTY_SIZE];
};

struct TrainerCardData
{
    u8 mainState;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    u8 flipDrawState;
    bool8 isLink;
    u8 timeColonBlinkTimer;
    bool8 timeColonInvisible;
    bool8 onBack;
    bool8 allowDMACopy;
    bool8 hasPokedex;
    bool8 hasHofResult;
    bool8 hasLinkResults;
    bool8 hasBattleTowerWins;
    bool8 var_E;
    bool8 var_F;
    bool8 hasTrades;
    bool8 hasBadge[8];
    u8 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH][13];
    u8 strings[TRAINER_CARD_STRING_COUNT][70];
    u8 var_395;
    u16 monIconPals[16 * PARTY_SIZE];
    s8 flipBlendY;
    u8 cardType;
    void (*callback2)(void);
    struct TrainerCard trainerCard;
    u16 frontTilemap[600];
    u16 backTilemap[600];
    u16 bgTilemap[600];
    u8 badgeTiles[0x80 * 8];
    u16 stickerTiles[0x100];
    u16 cardTiles[0x1180];
    u16 cardTilemapBuffer[0x1000];
    u16 bgTilemapBuffer[0x1000];
    u16 var_7BCC;
    bool8 timeColonNeedDraw;
    u8 language;
}; /* size = 0x7BD0 */

#endif // GUARD_CONSTANTS_TRAINER_CARD_H
