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
	@setflag 0x940 @randomizer
	@setflag 0x971 @lvl cap
	@setvar 0x50A0 70
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_RARE_CANDY 400
	additem ITEM_ABILITY_CAPSULE 50
	additem ITEM_ABILITY_PATCH 50
	additem 0x140 1
	additem 0x183 1
	setflag 0x91E @dexnav
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_AVALUGG_H 10 0 0 0 0
	givepokemon SPECIES_RESHIRAM 10 0 0 0 0
	givepokemon SPECIES_SLIGGOO_H 10 0 0 0 0
	givepokemon SPECIES_KLANG 2 0 0 0 0
	givepokemon SPECIES_ARTICUNO_G 10 0 0 0 0
	givepokemon SPECIES_SWANNA 10 0 0 0 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	@setflag 0x82F @running shoes
	@setflag 0x91F @bike turbo
	@setflag 0x940 @randomizer
	@setflag 0x90E @trainer scale
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
