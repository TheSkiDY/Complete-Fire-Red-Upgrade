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
	faceplayer
	checkflag 0x940
	if 0x1 _goto TechnologyGuy_ShowGameplayOptionsScreen
	call TechnologyGuy_Debug
	@call TechnologyGuy_TechDemo
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
	additem ITEM_LOADED_DICE 1
	additem ITEM_ADAMANT_CRYSTAL 1
	additem ITEM_LUSTROUS_GLOBE 1
	additem ITEM_GRISEOUS_CORE 1
	additem ITEM_AUSPICIOUS_ARMOR 1
	additem ITEM_MALICIOUS_ARMOR 1
	additem ITEM_CYAN_NECTAR 1
	additem ITEM_PURPLE_NECTAR 1
	setvar 0x8004 0xF
	special 0x62
	givepokemon SPECIES_EXEGGCUTE 15 0 0 0 0
		@setvar 0x8000 MOVE_HYDROSTEAM
	givepokemon SPECIES_DIALGA 15 0 0 0 0
	givepokemon SPECIES_PALKIA 15 0 0 0 0
	givepokemon SPECIES_GIRATINA 15 0 0 0 0
	givepokemon SPECIES_ORICORIO_Y 15 0 0 0 0
	setvar 0x8000 MOVE_HYDROSTEAM
	setvar 0x8001 MOVE_SUNNYDAY
	setvar 0x8002 MOVE_ELECTRICTERRAIN
	setvar 0x8003 MOVE_PSYBLADE
	givepokemon SPECIES_MIRAIDON 15 0 0 1 0
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x820
	setflag 0x821
	setflag 0x822
	setflag 0x823
	setflag 0x824
	setflag 0x825
	setflag 0x826
	setflag 0x827
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x940 @randomizer
	setflag 0x974 @scale wild bosses
	setflag 0x972 @no evs
	@setflag 0x973 @hard level cap
	setflag 0x975 @team preview
	setflag 0x91F @bike turbo
	setflag 0x929 @turbo surf
	setflag 0x90D @wild scale
	@setflag 0x90E @trainer scale
	setflag 0x927 @keep consumables
	addmoney 800000
	setvar 0x408C 0x1
		@setflag 0x200
	return

TechnologyGuy_TechDemo:
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

TechnologyGuy_ShowGameplayOptionsScreen:
	goto TechnologyGuy_LoadFakemonOptionText
	end

TechnologyGuy_ShowGameplayOptionsScreen_Multichoice:
	multichoiceoption gText_RerandomizeOptionText 0x3
	preparemsg gText_GameplayOptionText
	waitmsg
	multichoice 0x0 0x0 0x22 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto TechnologyGuy_ChangeFakemon
	compare LASTRESULT 0x1
	if 0x1 _goto TechnologyGuy_ChangeRegional
	compare LASTRESULT 0x2
	if 0x1 _goto TechnologyGuy_ChangeLoadDexArea
	compare LASTRESULT 0x3
	if 0x1 _goto TechnologyGuy_Rerandomize
	goto TechnologyGuy_Quit
	end
	
TechnologyGuy_LoadFakemonOptionText:
	checkflag 0x976
	if 0x1 _goto TechnologyGuy_LoadOnFakemonOptionText
	goto TechnologyGuy_LoadOffFakemonOptionText
	end

TechnologyGuy_LoadOffFakemonOptionText:
	multichoiceoption gText_TurnOffFakemonOptionText 0x0
	goto TechnologyGuy_LoadRegionalsOptionText
	end

TechnologyGuy_LoadOnFakemonOptionText:
	multichoiceoption gText_TurnOnFakemonOptionText 0x0
	goto TechnologyGuy_LoadRegionalsOptionText
	end

TechnologyGuy_LoadRegionalsOptionText:
	checkflag 0x977
	if 0x1 _goto TechnologyGuy_LoadOnRegionalsOptionText
	goto TechnologyGuy_LoadOffRegionalsOptionText
	end

TechnologyGuy_LoadOffRegionalsOptionText:
	multichoiceoption gText_TurnOffRegionalsOptionText 0x1
	goto TechnologyGuy_LoadDexAreaOptionText
	end

TechnologyGuy_LoadOnRegionalsOptionText:
	multichoiceoption gText_TurnOnRegionalsOptionText 0x1
	goto TechnologyGuy_LoadDexAreaOptionText
	end

TechnologyGuy_LoadDexAreaOptionText:
	checkflag 0x978
	if 0x1 _goto TechnologyGuy_LoadOffDexAreaOptionText
	goto TechnologyGuy_LoadOnDexAreaOptionText
	end

TechnologyGuy_LoadOffDexAreaOptionText:
	multichoiceoption gText_TurnOffDexAreaOptionText 0x2
	goto TechnologyGuy_ShowGameplayOptionsScreen_Multichoice

TechnologyGuy_LoadOnDexAreaOptionText:
	multichoiceoption gText_TurnOnDexAreaOptionText 0x2
	goto TechnologyGuy_ShowGameplayOptionsScreen_Multichoice
	end

TechnologyGuy_ChangeFakemon:
	checkflag 0x976
	if 0x1 _goto TechnologyGuy_TurnOnFakemon
	goto TechnologyGuy_TurnOffFakemon
	end

TechnologyGuy_TurnOnFakemon:
	clearflag 0x976
	msgbox gText_TechnologyGuy_EnableFakemons MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_TurnOffFakemon:
	setflag 0x976
	msgbox gText_TechnologyGuy_DisableFakemons MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_ChangeRegional:
	checkflag 0x977
	if 0x1 _goto TechnologyGuy_TurnOnRegional
	goto TechnologyGuy_TurnOffRegional
	end

TechnologyGuy_TurnOnRegional:
	clearflag 0x977
	msgbox gText_TechnologyGuy_EnableRegionals MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_TurnOffRegional:
	setflag 0x977
	msgbox gText_TechnologyGuy_DisableRegionals MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_ChangeLoadDexArea:
	checkflag 0x978
	if 0x1 _goto TechnologyGuy_TurnOffDexArea
	goto TechnologyGuy_TurnOnDexArea
	end

TechnologyGuy_TurnOffDexArea:
	clearflag 0x978
	msgbox gText_TechnologyGuy_DisableDexArea MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_TurnOnDexArea:
	setflag 0x978
	msgbox gText_TechnologyGuy_EnableDexArea MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_Rerandomize:
	callasm BufferRandomizerSeed
	setvar 0x8006 0x0
	loadpointer 0x0 gText_RerandomizeOption1
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_RerandomizeOption2
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_RerandomizeCancel
	special 0x25
	preparemsg gText_RerandomizeOptionSelect
	waitmsg
	multichoice 0x20 0x6 0x21 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto TechnologyGuy_RerandomizeSet
	compare LASTRESULT 0x1
	if 0x1 _goto TechnologyGuy_RerandomizeRandom
	goto TechnologyGuy_Quit
	end

TechnologyGuy_RerandomizeSet:
	setvar 0x8000 0x4
	special 0x12C
	waitstate
	callasm AssignSetSeed
	callasm BufferRandomizerSeed
	msgbox gText_TechnologyGuy_Rerandomized MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_RerandomizeRandom:
	callasm AssignNewRandomSeed
	callasm BufferRandomizerSeed
	msgbox gText_TechnologyGuy_Rerandomized MSG_NORMAL
	goto TechnologyGuy_Quit
	end

TechnologyGuy_Quit:
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
	mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE PlayerHome_InitScripts
	.byte MAP_SCRIPT_TERMIN

PlayerHome_InitScript1:
	callasm AssignNewRandomSeed
	compare 0x4056 0x0
	if 0x1 _call 0x8168CBA
	end

PlayerHome_InitScripts:
	levelscript 0x4056, 0, PlayerHome_InitScript2
    .byte MAP_SCRIPT_TERMIN

PlayerHome_InitScript2:
	spriteface 0xFF 0x2
	setvar 0x4056 0x1
	end
