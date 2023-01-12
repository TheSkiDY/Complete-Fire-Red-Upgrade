.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy
.global EventScript_PalletTown_RandomizerStop
.global gPlayerSpawnScripts

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

EventScript_PalletTown_TechnologyGuy:
	lock 
	loadpointer 0x0 gText_TechnologyGuyName
	setvar 0x8000 0x1
	setvar 0x8001 0xB
	setvar 0x8002 0x8
	setvar 0x8003 0x2
	callasm 0x8727CF9
	faceplayer
	checkflag 0x940
	if 0x1 _goto TechnologyGuy_FurtherQuestions
	@call TechnologyGuy_Debug
	call TechnologyGuy_TechDemo
	callasm 0x8727DCD
	callasm DebugFunc
	release
	end

TechnologyGuy_Debug:
		@checkflag 0x200
		@if 0x1 _goto TechnologyGuy_Battle
		@setflag 0x976 @no fakemons
	additem ITEM_RARE_CANDY 1
	additem ITEM_ABILITY_CAPSULE 20
	additem ITEM_ABILITY_PATCH 20
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_NECROZMA_DUSK_MANE 12 0 0 0 0
	givepokemon SPECIES_SLOWKING_G 5 0 0 0 0
	givepokemon SPECIES_GHOLDENGO 60 0 0 0 0
	givepokemon SPECIES_GLIMMORA 5 0 0 0 0
	givepokemon SPECIES_CYCLIZAR 33 0 0 0 0
	setvar 0x8000 MOVE_DISCHARGE
	setvar 0x8001 MOVE_AGILITY
	setvar 0x8002 MOVE_DRAGONBREATH
	setvar 0x8002 MOVE_SNAPTRAP
	givepokemon SPECIES_MIRAIDON 35 0 0 1 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x940 @randomizer
	setflag 0x974 @scale wild bosses
	setflag 0x972 @no evs
	setflag 0x973 @hard level cap
	setflag 0x975 @team preview
	setflag 0x91F @bike turbo
	setflag 0x929 @turbo surf
	setflag 0x90D @wild scale
	setflag 0x90E @trainer scale
	setflag 0x927 @keep consumables
	addmoney 800000
	setvar 0x408C 0x1
		@setflag 0x200
	return

TechnologyGuy_TechDemo:
	lock 
	loadpointer 0x0 gText_TechnologyGuyName
	setvar 0x8000 0x1
	setvar 0x8001 0xB
	setvar 0x8002 0x8
	setvar 0x8003 0x2
	callasm 0x8727CF9
	faceplayer
	additem ITEM_RARE_CANDY 1
	additem ITEM_ABILITY_CAPSULE 20
	additem ITEM_ABILITY_PATCH 20
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x940 @randomizer
	setflag 0x974 @scale wild bosses
	setflag 0x972 @no evs
	setflag 0x973 @hard level cap
	setflag 0x975 @team preview
	setflag 0x91F @bike turbo
	setflag 0x929 @turbo surf
	setflag 0x90D @wild scale
	setflag 0x90E @trainer scale
	setflag 0x927 @keep consumables
	addmoney 800000
	setvar 0x408C 0x1
	return

TechnologyGuy_FurtherQuestions:
	msgbox gText_TechnologyGuy_DisableFakemonsQuestion MSG_YESNO
	compare LASTRESULT YES
	if 0x1 _goto TechnologyGuy_DisableFakemons
	clearflag 0x976
	msgbox gText_TechnologyGuy_EnableFakemons MSG_NORMAL
	goto TechnologyGuy_DisableRegionalsQuestion
	end

TechnologyGuy_DisableRegionalsQuestion:
	msgbox gText_TechnologyGuy_DisableRegionalsQuestion MSG_YESNO
	compare LASTRESULT YES
	if 0x1 _goto TechnologyGuy_DisableRegionals
	clearflag 0x977
	msgbox gText_TechnologyGuy_EnableRegionals MSG_NORMAL
	goto TechnologyGuy_Rerandomize
	end

TechnologyGuy_DisableFakemons:
	setflag 0x976 @no fakemons
	msgbox gText_TechnologyGuy_DisableFakemons MSG_NORMAL
	goto TechnologyGuy_DisableRegionalsQuestion
	end

TechnologyGuy_DisableRegionals:
	setflag 0x977 @no regionals
	msgbox gText_TechnologyGuy_DisableRegionals MSG_NORMAL
	goto TechnologyGuy_Rerandomize
	end

TechnologyGuy_Rerandomize:
	goto TechnologyGuy_Quit
	end

TechnologyGuy_Quit:
	callasm 0x8727DCD
	release
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

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

EventScript_PalletTown_RandomizerStop:
	msgbox gText_PalletTown_NotRandomized MSG_KEEPOPEN
	closeonkeypress
	applymovement PLAYER Movement_RandomizerStop_StepDown
	waitmovement 0x0
	release
	end

Movement_RandomizerStop_StepDown:
	.byte look_down, walk_down, end_m

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gPlayerSpawnScripts:
	mapscript MAP_SCRIPT_ON_TRANSITION PlayerHome_InitScript1
	mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE PlayerHome_InitScript2
	.byte MAP_SCRIPT_TERMIN

PlayerHome_InitScript1:
	compare 0x4056 0x0
	if 0x1 _call 0x8168CBA
	end

PlayerHome_InitScript2:
	spriteface 0xFF 0x2
	setvar 0x4056 0x1
	end
