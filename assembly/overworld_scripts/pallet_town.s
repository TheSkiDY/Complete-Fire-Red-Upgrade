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
	checkflag 0x200
	if 0x1 _goto EventScript_PalletTown_TechnologyGuy_Part2
	additem ITEM_RARE_CANDY 60
	additem ITEM_ABILITY_CAPSULE 20
	additem ITEM_ABILITY_PATCH 20
	setvar 0x8004 0xF @erase party
	special 0x62
	givepokemon SPECIES_TRUBBISH 20 0 0 0
	givepokemon SPECIES_TAPU_KOKO 20 0 0 0
	givepokemon SPECIES_TAPU_LELE 20 0 0 0
	givepokemon SPECIES_TAPU_FINI 20 0 0 0
	givepokemon SPECIES_KYOGRE 20 ITEM_BLUE_ORB 0 0
	givepokemon SPECIES_GROUDON 20 ITEM_RED_ORB 0 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x91F @bike turbo
	setflag 0x200 @tmp
	release
	end

EventScript_PalletTown_TechnologyGuy_Part2:
	@setflag 0x90B @wild_custom_moves 
	@setvar 0x8000 MOVE_HEADBUTT
	@setvar 0x8001 MOVE_HARDEN
	@setvar 0x8002 0xFFFF
	@setvar 0x8003 0xFFFF
	setwildbattle SPECIES_ZACIAN_CROWNED 14
	dowildbattle
	release
	end
