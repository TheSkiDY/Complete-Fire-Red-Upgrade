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
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 100
	additem ITEM_MEGA_RING 1
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_SPINDA 60 0x0 0x0 0x0 0x0
	givepokemon SPECIES_CLAYDOL 60 0x0 0x0 0x0 0x0
	givepokemon SPECIES_SKARMORY 60 0x0 0x0 0x0 0x0
	givepokemon SPECIES_GROUDON 60 ITEM_RED_ORB 0x0 0x0 0x0
	givepokemon SPECIES_ALAKAZAM 60 0x0 0x0 0x0 0x0
	givepokemon SPECIES_HITMONTOP 46 0x0 0x0 0x0 0x0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x200
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
