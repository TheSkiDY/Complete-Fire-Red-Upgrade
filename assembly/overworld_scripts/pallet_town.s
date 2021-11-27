.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy

EventScript_PalletTown_TechnologyGuy:
	checkflag 0x200
	if 0x1 _goto TechnologyGuy_Battle
	lock 
	loadpointer 0x0 gText_TechnologyGuyName
	setvar 0x8000 0x1
	setvar 0x8001 0xB
	setvar 0x8002 0x8
	setvar 0x8003 0x2
	callasm 0x8727CF9
	faceplayer
	setflag 0x971
	setvar 0x50A0 14
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 100
	additem ITEM_ABILITY_PATCH 1
	additem ITEM_DREAM_BALL 3
	additem ITEM_SHINY_BALL 4
	additem ITEM_MEGA_RING 1
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_RABBLIT 10 0x0 0x0 0x0 0x0
	givepokemon SPECIES_CHEWTLE 10 0x0 0x0 0x0 0x0
	givepokemon SPECIES_DARMANITAN_G 10 0x0 0x0 0x0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x82F
	callasm 0x8727DCD
	end

TechnologyGuy_Battle:
	lock 
	loadpointer 0x0 gText_TechnologyGuyName
	setvar 0x8000 0x1
	setvar 0x8001 0xB
	setvar 0x8002 0x8
	setvar 0x8003 0x2
	callasm 0x8727CF9
	faceplayer
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x918
	trainerbattle3 0x3 0x1B4 0x0 0x8188B08
	callasm 0x8727DCD
	end
