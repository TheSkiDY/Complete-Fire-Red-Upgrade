#pragma once

#include "../global.h"
#include "../../src/config.h"

/**
 * \file item.h
 * \brief Contains functions relating to items and the bag.
 *		  Also helps with TM/HM expansion and the bag expansion.
 */

//Exported Functions
u16 SanitizeItemId(u16 itemId);
const u8* ItemId_GetName(u16 itemId);
u8 ItemId_GetHoldEffect(u16 itemId);
u8 ItemId_GetHoldEffectParam(u16 itemId);
u8 ItemId_GetMystery2Id(u16 itemId);
bool8 IsMegaStone(u16 item);
bool8 IsPrimalOrb(u16 item);
bool8 IsZCrystal(u16 item);
bool8 IsTypeZCrystal(u16 item, u8 moveType);
bool8 IsBerry(u16 item);
bool8 IsPinchBerryItemEffect(u8 itemEffect);
bool8 IsGem(u16 item);
bool8 IsHealthRecoveryItem(u16 item);
bool8 IsStatusRecoveryItem(u16 item);
bool8 IsPPRecoveryItem(u16 item);
bool8 IsStatBoostDrink(u16 item);
bool8 IsPPBoostDrink(u16 item);
bool8 IsExpModifierItem(u16 item);
bool8 IsAbilityModifierItem(u16 item);
bool8 IsStatBoostWing(u16 item);
bool8 IsShard(u16 item);
bool8 IsTMHM(u16 item);
u8 TMIdFromItemId(u16 itemId);
u8 BerryIdFromItemId(u16 item);
bool8 GetSetItemObtained(u16 item, u8 caseId);
u8 ReformatItemDescription(u16 item, u8* dest, u8 maxChars);

u32 CanMonLearnTMHM(struct Pokemon* mon, u8 tm);
bool8 CanMonLearnTutorMove(struct Pokemon* mon, u8 tutorId);
u16 GetExpandedTutorMove(u8 tutorId);
void CopyTMName(u8* dst, u16 itemId);
u8 CanMonLearnTMTutor(struct Pokemon* mon, u16 item, u8 tutor);

bool8 IsItemRegistered(u16 item);
bool8 CanRegisterNewItem(void);
void RegisterItem(u16 item);
void RemoveRegisteredItem(u16 item);
void CompactRegisteredItems(void);

u16 GetNumItemsInPocket(u8 pocket);
u16 GetCurrentPocketItemAmount(void);
bool8 DoesBagHaveBerry(void);
void SortBerriesOrTMHMs(struct BagPocket* bagPocket);
void SortItemsInBag(u8 pocket, u8 type);

u16 GetBestBallInBag(void);

//Hooked in Functions
u8 TryHandleExcuseForDracoMeteorTutor(struct Pokemon* mon);
u8 TryHandleExcuseForDracoMeteorTutorAlreadyKnow(void);
void CancelPartyMenuLearnTutor(u8 taskId);
u16 ItemIdToBattleMoveId(u16 item);
void LoadTMNameWithNo(u8* dst, u16 itemId);
void LoadTmHmNameInMart(u16 item);
void* LoadTmHmMartDescription(u16 item);
bool8 CheckIsHmMove(u16 move);
bool8 CheckTmHmInFront(u16 item);
u8 CheckDiscIsTmHm(struct Sprite* disc, u16 itemId);
u8 TmHMDiscPosition(unusedArg struct Sprite* disc, u8 tmId);
bool8 CheckReusableTMs(u16 item);
u8 CheckHmSymbol(u16 item);
bool8 CheckSellTmHm(u16 item);
void CheckTmPurchase(u16 item, u8 taskId);
bool8 CheckBuyableTm(u16 item, u8 taskId);
u16 CheckTmPrice(u16 item);
u8 CheckSingleBagTm(u16 item);
const void* FixTmHmDiscPalette(u8 type);

void CompactItemsInBagPocket(struct ItemSlot* itemSlots, u16 amount);
void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
void SetMemoryForBagStorage(void);
bool8 AllocateBagItemListBuffers(void);
bool8 AllocateBerryPouchListBuffers(void);
void BagListMenuGetItemNameColored(u8 *dest, u16 itemId);
void PokeDudeBackupBag(void);
void PokeDudeRestoreBag(void);
void PokeDudeBackupKeyItemsTMs(void);
void PokeDudeRestoreKeyItemsTMs(void);
void StoreBagItemCount(void);
bool8 TrySetupSortBag(u8 taskId);
void LoadBagSorterMenuOptions(void);
void PrintBagSortItemQuestion(u8 windowId);

//Exported Constants
enum
{
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG,
};

enum ItemObtainFlags
{
    FLAG_GET_OBTAINED,
    FLAG_SET_OBTAINED,
};

#define REGISTERED_ITEM_COUNT 6
#define NUM_TMSHMS NUM_TMS + NUM_HMS	// never change this

#define gTMHMMoves ((const u16*) *((u32*) 0x8125A8C))
#define gTutorMoves ((const u16*) *((u32*) 0x8120BE4))

enum ItemType //Sorted in this order
{
	ITEM_TYPE_MAX_REPEL,
	ITEM_TYPE_SUPER_REPEL,
	ITEM_TYPE_REPEL,
	ITEM_TYPE_FIELD_USE,

	//Health Recovery
	ITEM_TYPE_FULL_RESTORE,
	ITEM_TYPE_MAX_POTION,
	ITEM_TYPE_HYPER_POTION,
	ITEM_TYPE_SUPER_POTION,
	ITEM_TYPE_POTION,
	ITEM_TYPE_REVIVE,
	ITEM_TYPE_MOOMOO_MILK,
	ITEM_TYPE_LEMONADE,
	ITEM_TYPE_SODA_POP,
	ITEM_TYPE_FRESH_WATER,
	ITEM_TYPE_HERB_HEAL,

	//Status Recovery
	ITEM_TYPE_FULL_HEAL,
	ITEM_TYPE_FOOD_STATUS_RECOVERY,
	ITEM_TYPE_STATUS_RECOVERY,
	ITEM_TYPE_PP_RECOVERY,
	
	//Battle Items
	ITEM_TYPE_X_ATTACK,
	ITEM_TYPE_X_DEFENSE,
	ITEM_TYPE_X_SP_ATTACK,
	ITEM_TYPE_X_SP_DEFENSE,
	ITEM_TYPE_X_SPEED,
	ITEM_TYPE_X_ACCURACY,
	ITEM_TYPE_OTHER_STAT_BATTLE_ITEM,
	ITEM_TYPE_OTHER_BATTLE_ITEM,
	
	//Stat Boost Drink
	ITEM_TYPE_ABILITY_GIGANTAMAX_MODIFIER,
	ITEM_TYPE_LEVEL_MODIFIER,
	ITEM_TYPE_PP_UP,
	ITEM_TYPE_PP_MAX,
	ITEM_TYPE_HP_UP,
	ITEM_TYPE_PROTEIN,
	ITEM_TYPE_IRON,
	ITEM_TYPE_CALCIUM,
	ITEM_TYPE_ZINC,
	ITEM_TYPE_CARBOS,
	
	//Stat Boost Wings
	ITEM_TYPE_HP_WING,
	ITEM_TYPE_ATTACK_WING,
	ITEM_TYPE_DEFENSE_WING,
	ITEM_TYPE_SPATK_WING,
	ITEM_TYPE_SPDEF_WING,
	ITEM_TYPE_SPEED_WING,

	//Other
	ITEM_TYPE_FLUTE,
	ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	ITEM_TYPE_HELD_ITEM,
	ITEM_TYPE_INCENSE,
	ITEM_TYPE_GEM,
	ITEM_TYPE_PLATE,
	ITEM_TYPE_MEGA_STONE,
	ITEM_TYPE_PRIMAL_ORB,
	ITEM_TYPE_Z_CRYSTAL,
	ITEM_TYPE_EVOLUTION_STONE,
	ITEM_TYPE_EVOLUTION_ITEM,
	ITEM_TYPE_NECTAR,
	ITEM_TYPE_SELLABLE,
	ITEM_TYPE_RELIC,
	ITEM_TYPE_SHARD,
	ITEM_TYPE_FOSSIL,
	ITEM_TYPE_MEMORY,
	ITEM_TYPE_DRIVE,
	ITEM_TYPE_MAIL,
};

struct RewardItem
{
    u8 minAmount;
    u8 maxAmount;
    const u8* itemText;
};

extern const u8 gRewardText_LumBerry[];
extern const u8 gRewardText_SitrusBerry[];
extern const u8 gRewardText_AguavBerry[];
extern const u8 gRewardText_FigyBerry[];
extern const u8 gRewardText_IapapaBerry[];
extern const u8 gRewardText_MagoBerry[];
extern const u8 gRewardText_WikiBerry[];
extern const u8 gRewardText_ChilanBerry[];
extern const u8 gRewardText_ChopleBerry[];
extern const u8 gRewardText_CobaBerry[];
extern const u8 gRewardText_KebiaBerry[];
extern const u8 gRewardText_ShucaBerry[];
extern const u8 gRewardText_ChartiBerry[];
extern const u8 gRewardText_TangaBerry[];
extern const u8 gRewardText_KasibBerry[];
extern const u8 gRewardText_BabiriBerry[];
extern const u8 gRewardText_OccaBerry[];
extern const u8 gRewardText_PasshoBerry[];
extern const u8 gRewardText_RindoBerry[];
extern const u8 gRewardText_WacanBerry[];
extern const u8 gRewardText_PayapaBerry[];
extern const u8 gRewardText_YacheBerry[];
extern const u8 gRewardText_HabanBerry[];
extern const u8 gRewardText_ColburBerry[];
extern const u8 gRewardText_RoseliBerry[];
extern const u8 gRewardText_LiechiBerry[];
extern const u8 gRewardText_GanlonBerry[];
extern const u8 gRewardText_SalacBerry[];
extern const u8 gRewardText_PetayaBerry[];
extern const u8 gRewardText_ApicotBerry[];
extern const u8 gRewardText_LansatBerry[];
extern const u8 gRewardText_StarfBerry[];
extern const u8 gRewardText_CustapBerry[];
extern const u8 gRewardText_JabocaBerry[];
extern const u8 gRewardText_RowapBerry[];
extern const u8 gRewardText_KeeBerry[];
extern const u8 gRewardText_MarangaBerry[];
extern const u8 gRewardText_MicleBerry[];
extern const u8 gRewardText_LeppaBerry[];
extern const u8 gRewardText_NormalShard[];
extern const u8 gRewardText_FightingShard[];
extern const u8 gRewardText_FlyingShard[];
extern const u8 gRewardText_PoisonShard[];
extern const u8 gRewardText_GroundShard[];
extern const u8 gRewardText_RockShard[];
extern const u8 gRewardText_BugShard[];
extern const u8 gRewardText_GhostShard[];
extern const u8 gRewardText_SteelShard[];
extern const u8 gRewardText_FireShard[];
extern const u8 gRewardText_WaterShard[];
extern const u8 gRewardText_GrassShard[];
extern const u8 gRewardText_ElectricShard[];
extern const u8 gRewardText_PsychicShard[];
extern const u8 gRewardText_IceShard[];
extern const u8 gRewardText_DragonShard[];
extern const u8 gRewardText_DarkShard[];
extern const u8 gRewardText_FairyShard[];
extern const u8 gRewardText_HealthWing[];
extern const u8 gRewardText_MuscleWing[];
extern const u8 gRewardText_ResistWing[];
extern const u8 gRewardText_GeniusWing[];
extern const u8 gRewardText_CleverWing[];
extern const u8 gRewardText_SwiftWing[];
extern const u8 gRewardText_AbilityCapsule[];
extern const u8 gRewardText_AbilityPatch[];
extern const u8 gRewardText_WhiteHerb[];
extern const u8 gRewardText_MentalHerb[];
extern const u8 gRewardText_PowerHerb[];
extern const u8 gRewardText_MirrorHerb[];
extern const u8 gRewardText_NormalGem[];
extern const u8 gRewardText_FightingGem[];
extern const u8 gRewardText_FlyingGem[];
extern const u8 gRewardText_PoisonGem[];
extern const u8 gRewardText_GroundGem[];
extern const u8 gRewardText_RockGem[];
extern const u8 gRewardText_BugGem[];
extern const u8 gRewardText_GhostGem[];
extern const u8 gRewardText_SteelGem[];
extern const u8 gRewardText_FireGem[];
extern const u8 gRewardText_WaterGem[];
extern const u8 gRewardText_GrassGem[];
extern const u8 gRewardText_ElectricGem[];
extern const u8 gRewardText_PsychicGem[];
extern const u8 gRewardText_IceGem[];
extern const u8 gRewardText_DragonGem[];
extern const u8 gRewardText_DarkGem[];
extern const u8 gRewardText_FairyGem[];
extern const u8 gRewardText_ElectricSeed[];
extern const u8 gRewardText_GrassySeed[];
extern const u8 gRewardText_MistySeed[];
extern const u8 gRewardText_PsychicSeed[];
extern const u8 gRewardText_AbsorbBulb[];
extern const u8 gRewardText_AdrenalineOrb[];
extern const u8 gRewardText_BlunderPolicy[];
extern const u8 gRewardText_CellBattery[];
extern const u8 gRewardText_EjectButton[];
extern const u8 gRewardText_EjectPack[];
extern const u8 gRewardText_LuminousMoss[];
extern const u8 gRewardText_RoomService[];
extern const u8 gRewardText_Snowball[];
extern const u8 gRewardText_ThroatSpray[];
extern const u8 gRewardText_FocusSash[];
extern const u8 gRewardText_AirBalloon[];
extern const u8 gRewardText_RedCard[];
extern const u8 gRewardText_WeaknessPolicy[];
extern const u8 gRewardText_BoosterEnergy[];
extern const u8 gRewardText_FullIncense[];
extern const u8 gRewardText_LaxIncense[];
extern const u8 gRewardText_LuckIncense[];
extern const u8 gRewardText_OddIncense[];
extern const u8 gRewardText_PureIncense[];
extern const u8 gRewardText_RockIncense[];
extern const u8 gRewardText_RoseIncense[];
extern const u8 gRewardText_SeaIncense[];
extern const u8 gRewardText_WaveIncense[];
extern const u8 gRewardText_SilkScarf[];
extern const u8 gRewardText_BlackBelt[];
extern const u8 gRewardText_SharpBeak[];
extern const u8 gRewardText_PoisonBarb[];
extern const u8 gRewardText_SoftSand[];
extern const u8 gRewardText_HardStone[];
extern const u8 gRewardText_SilverPowder[];
extern const u8 gRewardText_SpellTag[];
extern const u8 gRewardText_MetalCoat[];
extern const u8 gRewardText_Charcoal[];
extern const u8 gRewardText_MysticWater[];
extern const u8 gRewardText_MiracleSeed[];
extern const u8 gRewardText_Magnet[];
extern const u8 gRewardText_TwistedSpoon[];
extern const u8 gRewardText_NeverMeltIce[];
extern const u8 gRewardText_DragonFang[];
extern const u8 gRewardText_BlackGlasses[];
extern const u8 gRewardText_FairyFeather[];
extern const u8 gRewardText_ChoiceBand[];
extern const u8 gRewardText_ChoiceScarf[];
extern const u8 gRewardText_ChoiceSpecs[];
extern const u8 gRewardText_DampRock[];
extern const u8 gRewardText_HeatRock[];
extern const u8 gRewardText_IcyRock[];
extern const u8 gRewardText_SmoothRock[];
extern const u8 gRewardText_AbilityShield[];
extern const u8 gRewardText_BindingBand[];
extern const u8 gRewardText_DestinyKnot[];
extern const u8 gRewardText_FloatStone[];
extern const u8 gRewardText_FocusBand[];
extern const u8 gRewardText_GripClaw[];
extern const u8 gRewardText_IronBall[];
extern const u8 gRewardText_LaggingTail[];
extern const u8 gRewardText_LightClay[];
extern const u8 gRewardText_RingTarget[];
extern const u8 gRewardText_ShedShell[];
extern const u8 gRewardText_StickyBarb[];
extern const u8 gRewardText_TerrainExtender[];
extern const u8 gRewardText_WideLens[];
extern const u8 gRewardText_ZoomLens[];
extern const u8 gRewardText_AmuletCoin[];
extern const u8 gRewardText_BigRoot[];
extern const u8 gRewardText_BlackSludge[];
extern const u8 gRewardText_CovertCloak[];
extern const u8 gRewardText_ExpertBelt[];
extern const u8 gRewardText_Metronome[];
extern const u8 gRewardText_MuscleBand[];
extern const u8 gRewardText_ProtectivePads[];
extern const u8 gRewardText_PunchingGlove[];
extern const u8 gRewardText_QuickClaw[];
extern const u8 gRewardText_SafetyGoggles[];
extern const u8 gRewardText_ScopeLens[];
extern const u8 gRewardText_UtilityUmbrella[];
extern const u8 gRewardText_WiseGlasses[];
extern const u8 gRewardText_AssaultVest[];
extern const u8 gRewardText_BrightPowder[];
extern const u8 gRewardText_ClearAmulet[];
extern const u8 gRewardText_Eviolite[];
extern const u8 gRewardText_HeavyDutyBoots[];
extern const u8 gRewardText_KingsRock[];
extern const u8 gRewardText_Leftovers[];
extern const u8 gRewardText_LifeOrb[];
extern const u8 gRewardText_LoadedDice[];
extern const u8 gRewardText_RockyHelmet[];
extern const u8 gRewardText_ShellBell[];
extern const u8 gRewardText_BottleCap[];
extern const u8 gRewardText_GoldBottleCap[];
extern const u8 gRewardText_AdamantMint[];
extern const u8 gRewardText_BoldMint[];
extern const u8 gRewardText_BraveMint[];
extern const u8 gRewardText_CalmMint[];
extern const u8 gRewardText_CarefulMint[];
extern const u8 gRewardText_GentleMint[];
extern const u8 gRewardText_HastyMint[];
extern const u8 gRewardText_ImpishMint[];
extern const u8 gRewardText_JollyMint[];
extern const u8 gRewardText_LaxMint[];
extern const u8 gRewardText_LonelyMint[];
extern const u8 gRewardText_MildMint[];
extern const u8 gRewardText_ModestMint[];
extern const u8 gRewardText_NaiveMint[];
extern const u8 gRewardText_NaughtyMint[];
extern const u8 gRewardText_QuietMint[];
extern const u8 gRewardText_RashMint[];
extern const u8 gRewardText_RelaxedMint[];
extern const u8 gRewardText_SassyMint[];
extern const u8 gRewardText_SeriousMint[];
extern const u8 gRewardText_TimidMint[];
extern const u8 gRewardText_TinyMushroom[];
extern const u8 gRewardText_BigMushroom[];
extern const u8 gRewardText_BalmMushroom[];
extern const u8 gRewardText_Pearl[];
extern const u8 gRewardText_BigPearl[];
extern const u8 gRewardText_Stardust[];
extern const u8 gRewardText_StarPiece[];
extern const u8 gRewardText_Nugget[];
extern const u8 gRewardText_RareBone[];
extern const u8 gRewardText_PearlString[];
extern const u8 gRewardText_CometShard[];
extern const u8 gRewardText_BigNugget[];
extern const u8 gRewardText_RelicCopper[];
extern const u8 gRewardText_RelicSilver[];
extern const u8 gRewardText_RelicGold[];
extern const u8 gRewardText_RelicVase[];
extern const u8 gRewardText_RelicBand[];
extern const u8 gRewardText_RelicStatue[];
extern const u8 gRewardText_RelicCrown[];
extern const u8 gRewardText_Calcium[];
extern const u8 gRewardText_Carbos[];
extern const u8 gRewardText_HpUp[];
extern const u8 gRewardText_Iron[];
extern const u8 gRewardText_PpMax[];
extern const u8 gRewardText_Protein[];
extern const u8 gRewardText_Zinc[];
extern const u8 gRewardText_TM01[];
extern const u8 gRewardText_TM02[];
extern const u8 gRewardText_TM03[];
extern const u8 gRewardText_TM04[];
extern const u8 gRewardText_TM05[];
extern const u8 gRewardText_TM06[];
extern const u8 gRewardText_TM07[];
extern const u8 gRewardText_TM08[];
extern const u8 gRewardText_TM09[];
extern const u8 gRewardText_TM10[];
extern const u8 gRewardText_TM11[];
extern const u8 gRewardText_TM12[];
extern const u8 gRewardText_TM13[];
extern const u8 gRewardText_TM14[];
extern const u8 gRewardText_TM15[];
extern const u8 gRewardText_TM16[];
extern const u8 gRewardText_TM17[];
extern const u8 gRewardText_TM18[];
extern const u8 gRewardText_TM19[];
extern const u8 gRewardText_TM20[];
extern const u8 gRewardText_TM21[];
extern const u8 gRewardText_TM22[];
extern const u8 gRewardText_TM23[];
extern const u8 gRewardText_TM24[];
extern const u8 gRewardText_TM25[];
extern const u8 gRewardText_TM26[];
extern const u8 gRewardText_TM27[];
extern const u8 gRewardText_TM28[];
extern const u8 gRewardText_TM29[];
extern const u8 gRewardText_TM30[];
extern const u8 gRewardText_TM31[];
extern const u8 gRewardText_TM32[];
extern const u8 gRewardText_TM33[];
extern const u8 gRewardText_TM34[];
extern const u8 gRewardText_TM35[];
extern const u8 gRewardText_TM36[];
extern const u8 gRewardText_TM37[];
extern const u8 gRewardText_TM38[];
extern const u8 gRewardText_TM39[];
extern const u8 gRewardText_TM40[];
extern const u8 gRewardText_TM41[];
extern const u8 gRewardText_TM42[];
extern const u8 gRewardText_TM43[];
extern const u8 gRewardText_TM44[];
extern const u8 gRewardText_TM45[];
extern const u8 gRewardText_TM46[];
extern const u8 gRewardText_TM47[];
extern const u8 gRewardText_TM48[];
extern const u8 gRewardText_TM49[];
extern const u8 gRewardText_TM50[];
extern const u8 gRewardText_TM51[];
extern const u8 gRewardText_TM52[];
extern const u8 gRewardText_TM53[];
extern const u8 gRewardText_TM54[];
extern const u8 gRewardText_TM55[];
extern const u8 gRewardText_TM56[];
extern const u8 gRewardText_TM57[];
extern const u8 gRewardText_TM58[];
extern const u8 gRewardText_TM59[];
extern const u8 gRewardText_TM60[];
extern const u8 gRewardText_TM61[];
extern const u8 gRewardText_TM62[];
extern const u8 gRewardText_TM63[];
extern const u8 gRewardText_TM64[];
extern const u8 gRewardText_TM65[];
extern const u8 gRewardText_TM66[];
extern const u8 gRewardText_TM67[];
extern const u8 gRewardText_TM68[];
extern const u8 gRewardText_TM69[];
extern const u8 gRewardText_TM70[];
extern const u8 gRewardText_TM71[];
extern const u8 gRewardText_TM72[];
extern const u8 gRewardText_TM73[];
extern const u8 gRewardText_TM74[];
extern const u8 gRewardText_TM75[];
extern const u8 gRewardText_TM76[];
extern const u8 gRewardText_TM77[];
extern const u8 gRewardText_TM78[];
extern const u8 gRewardText_TM79[];
extern const u8 gRewardText_TM80[];
extern const u8 gRewardText_TM81[];
extern const u8 gRewardText_TM82[];
extern const u8 gRewardText_TM83[];
extern const u8 gRewardText_TM84[];
extern const u8 gRewardText_TM85[];
extern const u8 gRewardText_TM86[];
extern const u8 gRewardText_TM87[];
extern const u8 gRewardText_TM88[];
extern const u8 gRewardText_TM89[];
extern const u8 gRewardText_TM90[];
extern const u8 gRewardText_TM91[];
extern const u8 gRewardText_TM92[];
extern const u8 gRewardText_TM93[];
extern const u8 gRewardText_TM94[];
extern const u8 gRewardText_TM95[];
extern const u8 gRewardText_TM96[];
extern const u8 gRewardText_TM97[];
extern const u8 gRewardText_TM98[];
extern const u8 gRewardText_TM99[];
extern const u8 gRewardText_TM100[];
extern const u8 gRewardText_TM101[];
extern const u8 gRewardText_TM102[];
extern const u8 gRewardText_TM103[];
extern const u8 gRewardText_TM104[];
extern const u8 gRewardText_TM105[];
extern const u8 gRewardText_TM106[];
extern const u8 gRewardText_TM107[];
extern const u8 gRewardText_TM108[];
extern const u8 gRewardText_TM109[];
extern const u8 gRewardText_TM110[];
extern const u8 gRewardText_TM111[];
extern const u8 gRewardText_TM112[];
extern const u8 gRewardText_TM113[];
extern const u8 gRewardText_TM114[];
extern const u8 gRewardText_TM115[];
extern const u8 gRewardText_TM116[];
extern const u8 gRewardText_TM117[];
extern const u8 gRewardText_TM118[];
extern const u8 gRewardText_TM119[];
extern const u8 gRewardText_TM120[];
extern const u8 gRewardText_BasicCrate[];
extern const u8 gRewardText_ReinforcedCrate[];
extern const u8 gRewardText_LinkCable[];
extern const u8 gRewardText_Protector[];
extern const u8 gRewardText_Electirizer[];
extern const u8 gRewardText_Magmarizer[];
extern const u8 gRewardText_DubiousDisc[];
extern const u8 gRewardText_ReaperCloth[];
extern const u8 gRewardText_SunStone[];
extern const u8 gRewardText_MoonStone[];
extern const u8 gRewardText_FireStone[];
extern const u8 gRewardText_ThunderStone[];
extern const u8 gRewardText_WaterStone[];
extern const u8 gRewardText_LeafStone[];
extern const u8 gRewardText_ShinyStone[];
extern const u8 gRewardText_DuskStone[];
extern const u8 gRewardText_DawnStone[];
extern const u8 gRewardText_IceStone[];
extern const u8 gRewardText_RazorClaw[];
extern const u8 gRewardText_RazorFang[];
extern const u8 gRewardText_PrismScale[];
extern const u8 gRewardText_Sachet[];
extern const u8 gRewardText_WhippedDream[];
extern const u8 gRewardText_DragonScale[];
extern const u8 gRewardText_UpGrade[];
extern const u8 gRewardText_StrawberrySweet[];
extern const u8 gRewardText_BerrySweet[];
extern const u8 gRewardText_LoveSweet[];
extern const u8 gRewardText_CloverSweet[];
extern const u8 gRewardText_FlowerSweet[];
extern const u8 gRewardText_RibbonSweet[];
extern const u8 gRewardText_StarSweet[];
extern const u8 gRewardText_SweetApple[];
extern const u8 gRewardText_TartApple[];
extern const u8 gRewardText_CrackedPot[];
extern const u8 gRewardText_ChippedPot[];
extern const u8 gRewardText_GalaricaCuff[];
extern const u8 gRewardText_GalaricaWreath[];
extern const u8 gRewardText_Gracidea[];
extern const u8 gRewardText_DnaSplicers[];
extern const u8 gRewardText_RevealGlass[];
extern const u8 gRewardText_PrisonBottle[];
extern const u8 gRewardText_NSolarizer[];
extern const u8 gRewardText_NLunarizer[];
extern const u8 gRewardText_RedNectar[];
extern const u8 gRewardText_YellowNectar[];
extern const u8 gRewardText_PinkNectar[];
extern const u8 gRewardText_PurpleNectar[];
extern const u8 gRewardText_Venusaurite[];
extern const u8 gRewardText_CharizarditeX[];
extern const u8 gRewardText_CharizarditeY[];
extern const u8 gRewardText_Blastoisinite[];
extern const u8 gRewardText_Beedrillite[];
extern const u8 gRewardText_Pidgeotite[];
extern const u8 gRewardText_Alakazite[];
extern const u8 gRewardText_Slowbronite[];
extern const u8 gRewardText_Gengarite[];
extern const u8 gRewardText_Kangaskhanite[];
extern const u8 gRewardText_Pinsirite[];
extern const u8 gRewardText_Gyaradosite[];
extern const u8 gRewardText_Aerodactylite[];
extern const u8 gRewardText_MewtwoniteX[];
extern const u8 gRewardText_MewtwoniteY[];
extern const u8 gRewardText_Ampharosite[];
extern const u8 gRewardText_Steelixite[];
extern const u8 gRewardText_Scizorite[];
extern const u8 gRewardText_Heracronite[];
extern const u8 gRewardText_Houndoominite[];
extern const u8 gRewardText_Tyranitarite[];
extern const u8 gRewardText_Sceptilite[];
extern const u8 gRewardText_Blazikenite[];
extern const u8 gRewardText_Swampertite[];
extern const u8 gRewardText_Gardevoirite[];
extern const u8 gRewardText_Sablenite[];
extern const u8 gRewardText_Mawilite[];
extern const u8 gRewardText_Aggronite[];
extern const u8 gRewardText_Medichamite[];
extern const u8 gRewardText_Manectite[];
extern const u8 gRewardText_Sharpedonite[];
extern const u8 gRewardText_Cameruptite[];
extern const u8 gRewardText_Altarianite[];
extern const u8 gRewardText_Banettite[];
extern const u8 gRewardText_Absolite[];
extern const u8 gRewardText_Glalitite[];
extern const u8 gRewardText_Salamencite[];
extern const u8 gRewardText_Metagrossite[];
extern const u8 gRewardText_Latiasite[];
extern const u8 gRewardText_Latiosite[];
extern const u8 gRewardText_Lopunnite[];
extern const u8 gRewardText_Garchompite[];
extern const u8 gRewardText_Lucarionite[];
extern const u8 gRewardText_Abomasite[];
extern const u8 gRewardText_Galladite[];
extern const u8 gRewardText_Audinite[];
extern const u8 gRewardText_Diancite[];
extern const u8 gRewardText_AuspiciousArmor[];
extern const u8 gRewardText_MaliciousArmor[];
extern const u8 gRewardText_BlackAugurite[];
extern const u8 gRewardText_LeadersCrest[];
extern const u8 gRewardText_MasterpieceTeacup[];
extern const u8 gRewardText_UnremarkableTeacup[];
extern const u8 gRewardText_MetalAlloy[];
extern const u8 gRewardText_PeatBlock[];
extern const u8 gRewardText_ScrollOfDarkness[];
extern const u8 gRewardText_ScrollOfWaters[];
extern const u8 gRewardText_SyrupyApple[];
extern const u8 gRewardText_AbsoliteZ[];
extern const u8 gRewardText_Barbaracite[];
extern const u8 gRewardText_Baxcalibrite[];
extern const u8 gRewardText_Chandelurite[];
extern const u8 gRewardText_Chesnaughtite[];
extern const u8 gRewardText_Chimechite[];
extern const u8 gRewardText_Clefablite[];
extern const u8 gRewardText_Crabominite[];
extern const u8 gRewardText_Darkranite[];
extern const u8 gRewardText_Delphoxite[];
extern const u8 gRewardText_Dragalgite[];
extern const u8 gRewardText_Dragoninite[];
extern const u8 gRewardText_Drampanite[];
extern const u8 gRewardText_Eelektrossite[];
extern const u8 gRewardText_Emboarite[];
extern const u8 gRewardText_Excadrite[];
extern const u8 gRewardText_Falinksite[];
extern const u8 gRewardText_Feraligite[];
extern const u8 gRewardText_Floettite[];
extern const u8 gRewardText_Froslassite[];
extern const u8 gRewardText_GarchompiteZ[];
extern const u8 gRewardText_Glimmoranite[];
extern const u8 gRewardText_Golisopite[];
extern const u8 gRewardText_Golurkite[];
extern const u8 gRewardText_Greninjite[];
extern const u8 gRewardText_Hawluchanite[];
extern const u8 gRewardText_Heatranite[];
extern const u8 gRewardText_LucarioniteZ[];
extern const u8 gRewardText_Magearnite[];
extern const u8 gRewardText_Malamarite[];
extern const u8 gRewardText_Meganiumite[];
extern const u8 gRewardText_Meowsticite[];
extern const u8 gRewardText_Pyroarite[];
extern const u8 gRewardText_RaichuniteX[];
extern const u8 gRewardText_RaichuniteY[];
extern const u8 gRewardText_Scolipite[];
extern const u8 gRewardText_Scovillainite[];
extern const u8 gRewardText_Scraftinite[];
extern const u8 gRewardText_Skarmorite[];
extern const u8 gRewardText_Staraptite[];
extern const u8 gRewardText_Starminite[];
extern const u8 gRewardText_Tatsugirinite[];
extern const u8 gRewardText_Victreebelite[];
extern const u8 gRewardText_Zeraorite[];
extern const u8 gRewardText_Zygardite[];
extern const u8 gRewardText_SoulDew[];
extern const u8 gRewardText_DeepSeaTooth[];
extern const u8 gRewardText_DeepSeaScale[];
extern const u8 gRewardText_LightBall[];
extern const u8 gRewardText_LuckyPunch[];
extern const u8 gRewardText_MetalPowder[];
extern const u8 gRewardText_ThickClub[];
extern const u8 gRewardText_Leek[];
extern const u8 gRewardText_RedOrb[];
extern const u8 gRewardText_BlueOrb[];
extern const u8 gRewardText_RustedSword[];
extern const u8 gRewardText_RustedShield[];
extern const u8 gRewardText_AdamantOrb[];
extern const u8 gRewardText_LustrousOrb[];
extern const u8 gRewardText_GriseousOrb[];
extern const u8 gRewardText_FistPlate[];
extern const u8 gRewardText_SkyPlate[];
extern const u8 gRewardText_ToxicPlate[];
extern const u8 gRewardText_EarthPlate[];
extern const u8 gRewardText_StonePlate[];
extern const u8 gRewardText_InsectPlate[];
extern const u8 gRewardText_SpookyPlate[];
extern const u8 gRewardText_IronPlate[];
extern const u8 gRewardText_FlamePlate[];
extern const u8 gRewardText_SplashPlate[];
extern const u8 gRewardText_MeadowPlate[];
extern const u8 gRewardText_ZapPlate[];
extern const u8 gRewardText_MindPlate[];
extern const u8 gRewardText_IciclePlate[];
extern const u8 gRewardText_DracoPlate[];
extern const u8 gRewardText_DreadPlate[];
extern const u8 gRewardText_PixiePlate[];
extern const u8 gRewardText_FightingMemory[];
extern const u8 gRewardText_FlyingMemory[];
extern const u8 gRewardText_PoisonMemory[];
extern const u8 gRewardText_GroundMemory[];
extern const u8 gRewardText_RockMemory[];
extern const u8 gRewardText_BugMemory[];
extern const u8 gRewardText_GhostMemory[];
extern const u8 gRewardText_SteelMemory[];
extern const u8 gRewardText_FireMemory[];
extern const u8 gRewardText_WaterMemory[];
extern const u8 gRewardText_GrassMemory[];
extern const u8 gRewardText_ElectricMemory[];
extern const u8 gRewardText_PsychicMemory[];
extern const u8 gRewardText_IceMemory[];
extern const u8 gRewardText_DragonMemory[];
extern const u8 gRewardText_DarkMemory[];
extern const u8 gRewardText_FairyMemory[];
extern const u8 gRewardText_BurnDrive[];
extern const u8 gRewardText_DouseDrive[];
extern const u8 gRewardText_ShockDrive[];
extern const u8 gRewardText_ChillDrive[];
extern const u8 gRewardText_QuickPowder[];
extern const u8 gRewardText_CornerstoneMask[];
extern const u8 gRewardText_HearthflameMask[];
extern const u8 gRewardText_WellspringMask[];
extern const u8 gRewardText_AdamantCrystal[];
extern const u8 gRewardText_GriseousCore[];
extern const u8 gRewardText_LustrousGlobe[];