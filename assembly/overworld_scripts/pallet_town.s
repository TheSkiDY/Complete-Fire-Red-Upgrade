.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy
.global EventScript_PalletTown_RandomizerStop

EventScript_PalletTown_TechnologyGuy:
	lock
	faceplayer
	callasm InitMgba
	callasm InitPlayerSeed
	checkflag 0x200
	if 0x1 _goto EventScript_PalletTown_TechnologyGuy_Part2
	additem ITEM_RARE_CANDY 660
	additem ITEM_ABILITY_CAPSULE 20
	additem ITEM_ABILITY_PATCH 20
	additem ITEM_SWEET_HEART 600
	additem ITEM_POMEG_BERRY 800
	additem ITEM_POTION 20
	setvar 0x8004 0xF @erase party
	special 0x62
	setvar 0x8000 MOVE_MALIGNANTCHAIN
	setvar 0x8001 MOVE_SNOWSCAPE
	setvar 0x8002 MOVE_SUPERCELLSLAM
	setvar 0x8003 MOVE_PSYCHICNOISE
	givepokemon SPECIES_CHI_YU 50 0 0 0
	givepokemon SPECIES_CHIEN_PAO 50 0 0 0
	givepokemon SPECIES_TING_LU 50 0 0 0
	givepokemon SPECIES_WO_CHIEN 50 0 0 0
	givepokemon SPECIES_ARBOLIVA 50 0 0 0
	givepokemon SPECIES_GHOLDENGO 50 0 0 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x91F @bike turbo
	setflag 0x950 @hard level cap
	setflag 0x200 @tmp
	@setflag 0x820
	@setflag 0x821
	@setflag 0x822
	@setflag 0x823
	@setflag 0x824
	@setflag 0x825
	@setflag 0x826
	@setflag 0x827
	release
	end

EventScript_PalletTown_TechnologyGuy_Part2:
	setflag 0x90B @wild_custom_moves 
	setvar 0x8000 MOVE_WILLOWISP
	setvar 0x8001 MOVE_THUNDERWAVE
	setvar 0x8002 MOVE_POISONPOWDER
	setvar 0x8003 0x0
	setwildbattle SPECIES_DONDOZO 20
	dowildbattle
	release
	end
	@setwildbattle 0xFFFF 0x0 0x0
	@setwildbattle SPECIES_REGIDRAGO 11 ITEM_NONE
	@setwildbattle SPECIES_REGIELEKI 11 ITEM_NONE
	@special 0x138
	@waitstate
	@release
	@end
