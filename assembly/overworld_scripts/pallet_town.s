.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy
.global EventScript_PalletTown_RandomizerStop

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
		@setflag 0x976 @no fakemons
	additem ITEM_RARE_CANDY 1
	additem ITEM_MEGA_RING 1
	additem ITEM_ABILITY_CAPSULE 50
	additem ITEM_ABILITY_PATCH 50
	additem ITEM_NATURE_PILL_NAUGHTY 5
	additem ITEM_NATURE_PILL_BOLD 5
	additem ITEM_SHINY_BALL 20
	additem ITEM_ZINC 10
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_NECROZMA_DUSK_MANE 12 0 0 0 0
	givepokemon SPECIES_WYRDEER 4 0 0 0 0
	givepokemon SPECIES_BRIONNE 4 0 0 0 0
	givepokemon SPECIES_SNOVER 4 0 0 0 0
	givepokemon SPECIES_SANDSLASH_S 4 0 0 0 0
	givepokemon SPECIES_DELCATTY_S 4 0 0 0 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x940 @randomizer
		@setflag 0x974 @scale wild bosses
	setflag 0x972 @no evs
	setflag 0x973 @hard level cap
	setflag 0x975 @team preview
	setflag 0x91F @bike turbo
		@setflag 0x90E @trainer scale
	setvar 0x408C 0x1
		@setflag 0x200
	callasm 0x8727DCD
		@callasm DebugFunc
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
	@setflag 0x918
	trainerbattle3 0x3 0x1B4 0x0 0x8188B08
	callasm 0x8727DCD
	end

EventScript_PalletTown_RandomizerStop:
	msgbox gText_PalletTown_NotRandomized MSG_KEEPOPEN
	closeonkeypress
	applymovement PLAYER Movement_RandomizerStop_StepDown
	waitmovement 0x0
	release
	end

Movement_RandomizerStop_StepDown:
	.byte look_down, walk_down, end_m
