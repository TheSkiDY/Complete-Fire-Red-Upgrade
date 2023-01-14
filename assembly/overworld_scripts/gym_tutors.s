	.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_FirstBadgeTutor
.global EventScript_SecondBadgeTutor
.global EventScript_ThirdBadgeTutor
.global EventScript_FourthBadgeTutor
.global EventScript_FifthBadgeTutor
.global EventScript_SixthBadgeTutor
.global EventScript_SeventhBadgeTutor
.global EventScript_EighthBadgeTutor
.global EventScript_PkmnLeagueTutor

EventScript_FirstBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor1 MSG_NORMAL
	checkflag 0x829
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorFirstBadgeFirstPage

ES_TutorFirstBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName1
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName2
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName3
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName4
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName5
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName6
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor1Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor1Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor3Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor4Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor5Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor6Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFirstBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFirstBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName7
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName8
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName9
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName10
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName11
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor7Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor8Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor9Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor10Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor11Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFirstBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFirstBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFirstBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName12
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName13
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName14
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName15
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName16
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor12Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor13Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor14Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor15Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor16Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFirstBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_SecondBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor2 MSG_NORMAL
	checkflag 0x820
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorSecondBadgeFirstPage

ES_TutorSecondBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName17
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName18
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName19
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName20
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName21
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName22
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor17Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor18Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor19Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor20Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor21Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor22Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSecondBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSecondBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName23
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName24
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName25
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName26
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName27
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor23Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor24Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor25Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor26Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor27Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSecondBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSecondBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSecondBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName28
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName29
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName30
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName31
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName32
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor28Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor29Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor30Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor31Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor32Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSecondBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_ThirdBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor3 MSG_NORMAL
	checkflag 0x821
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorThirdBadgeFirstPage

ES_TutorThirdBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName33
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName34
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName35
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName36
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName37
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName38
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor33Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor34Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor35Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor36Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor37Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor38Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorThirdBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorThirdBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName39
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName40
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName41
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName42
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName43
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor39Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor40Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor41Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor42Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor43Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorThirdBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorThirdBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorThirdBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName44
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName45
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName46
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName47
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName48
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor44Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor45Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor46Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor47Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor48Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorThirdBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_FourthBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor4 MSG_NORMAL
	checkflag 0x822
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorFourthBadgeFirstPage

ES_TutorFourthBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName49
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName50
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName51
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName52
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName53
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName54
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor49Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor50Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor51Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor52Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor53Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor54Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFourthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFourthBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName55
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName56
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName57
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName58
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName59
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor55Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor56Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor57Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor58Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor59Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFourthBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFourthBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFourthBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName60
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName61
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName62
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName63
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName64
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor60Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor61Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor62Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor63Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor64Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFourthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_FifthBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor5 MSG_NORMAL
	checkflag 0x823
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorFifthBadgeFirstPage

ES_TutorFifthBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName65
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName66
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName67
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName68
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName69
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName70
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor65Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor66Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor67Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor68Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor69Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor70Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFifthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFifthBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName71
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName72
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName73
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName74
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName75
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor71Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor72Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor73Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor74Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor75Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFifthBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorFifthBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorFifthBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName76
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName77
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName78
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName79
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName80
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor76Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor77Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor78Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor79Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor80Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorFifthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_SixthBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor6 MSG_NORMAL
	checkflag 0x824
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorSixthBadgeFirstPage

ES_TutorSixthBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName81
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName82
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName83
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName84
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName85
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName86
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor81Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor82Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor83Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor84Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor85Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor86Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSixthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSixthBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName87
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName88
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName89
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName90
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName91
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor87Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor88Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor89Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor90Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor91Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSixthBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSixthBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSixthBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName92
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName93
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName94
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName95
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName96
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor92Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor93Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor94Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor95Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor96Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSixthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_SeventhBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor7 MSG_NORMAL
	checkflag 0x825
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorSeventhBadgeFirstPage

ES_TutorSeventhBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName97
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName98
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName99
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName100
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName101
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName102
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor97Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor98Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor99Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor100Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor101Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor102Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSixthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSeventhBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName103
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName104
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName105
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName106
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName107
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor103Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor104Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor105Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor106Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor107Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSeventhBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorSeventhBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorSeventhBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName108
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName109
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName110
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName111
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName112
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor108Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor109Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor110Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor111Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor112Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorSeventhBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_EighthBadgeTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor8 MSG_NORMAL
	checkflag 0x826
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorEighthBadgeFirstPage

ES_TutorEighthBadgeFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName113
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName114
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName115
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName116
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName117
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName118
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor113Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor114Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor115Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor116Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor117Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor118Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorEighthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorEighthBadgeSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName119
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName120
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName121
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName122
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName123
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor119Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor120Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor121Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor122Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor123Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorEighthBadgeThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorEighthBadgeFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorEighthBadgeThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName124
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName125
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName126
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName127
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName128
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor124Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor125Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor126Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor127Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor128Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorEighthBadgeSecondPage
	goto ES_BadgeTutorGoodbye
	end

EventScript_PkmnLeagueTutor:
	lock
	faceplayer
	msgbox gText_IntroTutor9 MSG_NORMAL
	checkflag 0x827
	if 0x0 _goto ES_BadgeTutorDenied
	goto ES_TutorPkmnLeagueFirstPage

ES_TutorPkmnLeagueFirstPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName129
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName130
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName131
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName132
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName133
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorMoveName134
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor129Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor130Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor131Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor132Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor133Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_Tutor134Selected
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorPkmnLeagueSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorPkmnLeagueSecondPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName135
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName136
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName137
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName138
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName139
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorNextPage
	special 0x25
	setvar 0x8006 0x6
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor135Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor136Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor137Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor138Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor139Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorPkmnLeagueThirdPage
	compare LASTRESULT 0x6
	if 0x1 _goto ES_TutorPkmnLeagueFirstPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorPkmnLeagueThirdPage:
	setvar 0x8006 0x0
	loadpointer 0x0 gText_TutorMoveName140
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_TutorMoveName141
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_TutorMoveName142
	special 0x25
	setvar 0x8006 0x3
	loadpointer 0x0 gText_TutorMoveName143
	special 0x25
	setvar 0x8006 0x4
	loadpointer 0x0 gText_TutorMoveName144
	special 0x25
	setvar 0x8006 0x5
	loadpointer 0x0 gText_TutorPreviousPage
	special 0x25
	preparemsg gText_TutorMoveSelect
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto ES_Tutor140Selected
	compare LASTRESULT 0x1
	if 0x1 _goto ES_Tutor141Selected
	compare LASTRESULT 0x2
	if 0x1 _goto ES_Tutor142Selected
	compare LASTRESULT 0x3
	if 0x1 _goto ES_Tutor143Selected
	compare LASTRESULT 0x4
	if 0x1 _goto ES_Tutor144Selected
	compare LASTRESULT 0x5
	if 0x1 _goto ES_TutorPkmnLeagueSecondPage
	goto ES_BadgeTutorGoodbye
	end

ES_TutorHandleLearning:
	msgbox gText_TutorAskForMon MSG_KEEPOPEN
	call 0x81C4F30
	compare LASTRESULT 0x0
	if 0x1 _goto ES_BadgeTutorGoodbye
	goto ES_BadgeTutorGoodbye

ES_BadgeTutorDenied:
	msgbox gText_TutorCantTeach MSG_NORMAL
	release
	end

ES_BadgeTutorGoodbye:
	release
	end

ES_Tutor1Selected:
	bufferattack 0x0 MOVE_HELPINGHAND
	setvar 0x8005 0x0
	goto ES_TutorHandleLearning

ES_Tutor2Selected:
	bufferattack 0x0 MOVE_METRONOME
	setvar 0x8005 0x1
	goto ES_TutorHandleLearning

ES_Tutor3Selected:
	bufferattack 0x0 MOVE_LASERFOCUS
	setvar 0x8005 0x2
	goto ES_TutorHandleLearning

ES_Tutor4Selected:
	bufferattack 0x0 MOVE_PSYCHUP
	setvar 0x8005 0x3
	goto ES_TutorHandleLearning

ES_Tutor5Selected:
	bufferattack 0x0 MOVE_HEALBELL
	setvar 0x8005 0x4
	goto ES_TutorHandleLearning

ES_Tutor6Selected:
	bufferattack 0x0 MOVE_BLOCK
	setvar 0x8005 0x5
	goto ES_TutorHandleLearning

ES_Tutor7Selected:
	bufferattack 0x0 MOVE_INFESTATION
	setvar 0x8005 0x6
	goto ES_TutorHandleLearning

ES_Tutor8Selected:
	bufferattack 0x0 MOVE_BUGBITE
	setvar 0x8005 0x7
	goto ES_TutorHandleLearning

ES_Tutor9Selected:
	bufferattack 0x0 MOVE_MAGNETRISE
	setvar 0x8005 0x8
	goto ES_TutorHandleLearning

ES_Tutor10Selected:
	bufferattack 0x0 MOVE_NIGHTSHADE
	setvar 0x8005 0x9
	goto ES_TutorHandleLearning

ES_Tutor11Selected:
	bufferattack 0x0 MOVE_FAKETEARS
	setvar 0x8005 0xa
	goto ES_TutorHandleLearning

ES_Tutor12Selected:
	bufferattack 0x0 MOVE_HONECLAWS
	setvar 0x8005 0xb
	goto ES_TutorHandleLearning

ES_Tutor13Selected:
	bufferattack 0x0 MOVE_SCARYFACE
	setvar 0x8005 0xc
	goto ES_TutorHandleLearning

ES_Tutor14Selected:
	bufferattack 0x0 MOVE_SNATCH
	setvar 0x8005 0xd
	goto ES_TutorHandleLearning

ES_Tutor15Selected:
	bufferattack 0x0 MOVE_MAGICALLEAF
	setvar 0x8005 0xe
	goto ES_TutorHandleLearning

ES_Tutor16Selected:
	bufferattack 0x0 MOVE_DISARMINGVOICE
	setvar 0x8005 0xf
	goto ES_TutorHandleLearning

ES_Tutor17Selected:
	bufferattack 0x0 MOVE_PLUCK
	setvar 0x8005 0x10
	goto ES_TutorHandleLearning

ES_Tutor18Selected:
	bufferattack 0x0 MOVE_AIRCUTTER
	setvar 0x8005 0x11
	goto ES_TutorHandleLearning

ES_Tutor19Selected:
	bufferattack 0x0 MOVE_BULLDOZE
	setvar 0x8005 0x12
	goto ES_TutorHandleLearning

ES_Tutor20Selected:
	bufferattack 0x0 MOVE_LOWSWEEP
	setvar 0x8005 0x13
	goto ES_TutorHandleLearning

ES_Tutor21Selected:
	bufferattack 0x0 MOVE_BRUTALSWING
	setvar 0x8005 0x14
	goto ES_TutorHandleLearning

ES_Tutor22Selected:
	bufferattack 0x0 MOVE_ACIDSPRAY
	setvar 0x8005 0x15
	goto ES_TutorHandleLearning

ES_Tutor23Selected:
	bufferattack 0x0 MOVE_TRAILBLAZE
	setvar 0x8005 0x16
	goto ES_TutorHandleLearning

ES_Tutor24Selected:
	bufferattack 0x0 MOVE_POUNCE
	setvar 0x8005 0x17
	goto ES_TutorHandleLearning

ES_Tutor25Selected:
	bufferattack 0x0 MOVE_INCINERATE
	setvar 0x8005 0x18
	goto ES_TutorHandleLearning

ES_Tutor26Selected:
	bufferattack 0x0 MOVE_BRINE
	setvar 0x8005 0x19
	goto ES_TutorHandleLearning

ES_Tutor27Selected:
	bufferattack 0x0 MOVE_ELECTROWEB
	setvar 0x8005 0x1a
	goto ES_TutorHandleLearning

ES_Tutor28Selected:
	bufferattack 0x0 MOVE_ECHOEDVOICE
	setvar 0x8005 0x1b
	goto ES_TutorHandleLearning

ES_Tutor29Selected:
	bufferattack 0x0 MOVE_STRUGGLEBUG
	setvar 0x8005 0x1c
	goto ES_TutorHandleLearning

ES_Tutor30Selected:
	bufferattack 0x0 MOVE_ATTRACT
	setvar 0x8005 0x1d
	goto ES_TutorHandleLearning

ES_Tutor31Selected:
	bufferattack 0x0 MOVE_UPROAR
	setvar 0x8005 0x1e
	goto ES_TutorHandleLearning

ES_Tutor32Selected:
	bufferattack 0x0 MOVE_TRICK
	setvar 0x8005 0x1f
	goto ES_TutorHandleLearning

ES_Tutor33Selected:
	bufferattack 0x0 MOVE_FIREFANG
	setvar 0x8005 0x20
	goto ES_TutorHandleLearning

ES_Tutor34Selected:
	bufferattack 0x0 MOVE_ICEFANG
	setvar 0x8005 0x21
	goto ES_TutorHandleLearning

ES_Tutor35Selected:
	bufferattack 0x0 MOVE_THUNDERFANG
	setvar 0x8005 0x22
	goto ES_TutorHandleLearning

ES_Tutor36Selected:
	bufferattack 0x0 MOVE_DRAGONTAIL
	setvar 0x8005 0x23
	goto ES_TutorHandleLearning

ES_Tutor37Selected:
	bufferattack 0x0 MOVE_POISONTAIL
	setvar 0x8005 0x24
	goto ES_TutorHandleLearning

ES_Tutor38Selected:
	bufferattack 0x0 MOVE_DUALWINGBEAT
	setvar 0x8005 0x25
	goto ES_TutorHandleLearning

ES_Tutor39Selected:
	bufferattack 0x0 MOVE_BOUNCE
	setvar 0x8005 0x26
	goto ES_TutorHandleLearning

ES_Tutor40Selected:
	bufferattack 0x0 MOVE_RECYCLE
	setvar 0x8005 0x27
	goto ES_TutorHandleLearning

ES_Tutor41Selected:
	bufferattack 0x0 MOVE_SKILLSWAP
	setvar 0x8005 0x28
	goto ES_TutorHandleLearning

ES_Tutor42Selected:
	bufferattack 0x0 MOVE_MAGICCOAT
	setvar 0x8005 0x29
	goto ES_TutorHandleLearning

ES_Tutor43Selected:
	bufferattack 0x0 MOVE_AGILITY
	setvar 0x8005 0x2a
	goto ES_TutorHandleLearning

ES_Tutor44Selected:
	bufferattack 0x0 MOVE_SECRETPOWER
	setvar 0x8005 0x2b
	goto ES_TutorHandleLearning

ES_Tutor45Selected:
	bufferattack 0x0 MOVE_NATUREPOWER
	setvar 0x8005 0x2c
	goto ES_TutorHandleLearning

ES_Tutor46Selected:
	bufferattack 0x0 MOVE_WHIRLPOOL
	setvar 0x8005 0x2d
	goto ES_TutorHandleLearning

ES_Tutor47Selected:
	bufferattack 0x0 MOVE_DREAMEATER
	setvar 0x8005 0x2e
	goto ES_TutorHandleLearning

ES_Tutor48Selected:
	bufferattack 0x0 MOVE_SILVERWIND
	setvar 0x8005 0x2f
	goto ES_TutorHandleLearning

ES_Tutor49Selected:
	bufferattack 0x0 MOVE_BLAZEKICK
	setvar 0x8005 0x30
	goto ES_TutorHandleLearning

ES_Tutor50Selected:
	bufferattack 0x0 MOVE_MUDDYWATER
	setvar 0x8005 0x31
	goto ES_TutorHandleLearning

ES_Tutor51Selected:
	bufferattack 0x0 MOVE_ICICLESPEAR
	setvar 0x8005 0x32
	goto ES_TutorHandleLearning

ES_Tutor52Selected:
	bufferattack 0x0 MOVE_SMACKDOWN
	setvar 0x8005 0x33
	goto ES_TutorHandleLearning

ES_Tutor53Selected:
	bufferattack 0x0 MOVE_SKYDROP
	setvar 0x8005 0x34
	goto ES_TutorHandleLearning

ES_Tutor54Selected:
	bufferattack 0x0 MOVE_BREAKINGSWIPE
	setvar 0x8005 0x35
	goto ES_TutorHandleLearning

ES_Tutor55Selected:
	bufferattack 0x0 MOVE_VACUUMWAVE
	setvar 0x8005 0x36
	goto ES_TutorHandleLearning

ES_Tutor56Selected:
	bufferattack 0x0 MOVE_TRIATTACK
	setvar 0x8005 0x37
	goto ES_TutorHandleLearning

ES_Tutor57Selected:
	bufferattack 0x0 MOVE_GRASSKNOT
	setvar 0x8005 0x38
	goto ES_TutorHandleLearning

ES_Tutor58Selected:
	bufferattack 0x0 MOVE_LOWKICK
	setvar 0x8005 0x39
	goto ES_TutorHandleLearning

ES_Tutor59Selected:
	bufferattack 0x0 MOVE_HEATCRASH
	setvar 0x8005 0x3a
	goto ES_TutorHandleLearning

ES_Tutor60Selected:
	bufferattack 0x0 MOVE_TAILWIND
	setvar 0x8005 0x3b
	goto ES_TutorHandleLearning

ES_Tutor61Selected:
	bufferattack 0x0 MOVE_ROLEPLAY
	setvar 0x8005 0x3c
	goto ES_TutorHandleLearning

ES_Tutor62Selected:
	bufferattack 0x0 MOVE_ENDURE
	setvar 0x8005 0x3d
	goto ES_TutorHandleLearning

ES_Tutor63Selected:
	bufferattack 0x0 MOVE_NATURALGIFT
	setvar 0x8005 0x3e
	goto ES_TutorHandleLearning

ES_Tutor64Selected:
	bufferattack 0x0 MOVE_CORROSIVEGAS
	setvar 0x8005 0x3f
	goto ES_TutorHandleLearning

ES_Tutor65Selected:
	bufferattack 0x0 MOVE_FIREPUNCH
	setvar 0x8005 0x40
	goto ES_TutorHandleLearning

ES_Tutor66Selected:
	bufferattack 0x0 MOVE_ICEPUNCH
	setvar 0x8005 0x41
	goto ES_TutorHandleLearning

ES_Tutor67Selected:
	bufferattack 0x0 MOVE_THUNDERPUNCH
	setvar 0x8005 0x42
	goto ES_TutorHandleLearning

ES_Tutor68Selected:
	bufferattack 0x0 MOVE_ROCKBLAST
	setvar 0x8005 0x43
	goto ES_TutorHandleLearning

ES_Tutor69Selected:
	bufferattack 0x0 MOVE_TRIPLEAXEL
	setvar 0x8005 0x44
	goto ES_TutorHandleLearning

ES_Tutor70Selected:
	bufferattack 0x0 MOVE_SMARTSTRIKE
	setvar 0x8005 0x45
	goto ES_TutorHandleLearning

ES_Tutor71Selected:
	bufferattack 0x0 MOVE_CRUNCH
	setvar 0x8005 0x46
	goto ES_TutorHandleLearning

ES_Tutor72Selected:
	bufferattack 0x0 MOVE_SKITTERSMACK
	setvar 0x8005 0x47
	goto ES_TutorHandleLearning

ES_Tutor73Selected:
	bufferattack 0x0 MOVE_DUALCHOP
	setvar 0x8005 0x48
	goto ES_TutorHandleLearning

ES_Tutor74Selected:
	bufferattack 0x0 MOVE_GYROBALL
	setvar 0x8005 0x49
	goto ES_TutorHandleLearning

ES_Tutor75Selected:
	bufferattack 0x0 MOVE_ELECTROBALL
	setvar 0x8005 0x4a
	goto ES_TutorHandleLearning

ES_Tutor76Selected:
	bufferattack 0x0 MOVE_IRONTAIL
	setvar 0x8005 0x4b
	goto ES_TutorHandleLearning

ES_Tutor77Selected:
	bufferattack 0x0 MOVE_STOMPINGTANTRUM
	setvar 0x8005 0x4c
	goto ES_TutorHandleLearning

ES_Tutor78Selected:
	bufferattack 0x0 MOVE_REVERSAL
	setvar 0x8005 0x4d
	goto ES_TutorHandleLearning

ES_Tutor79Selected:
	bufferattack 0x0 MOVE_TERABLAST
	setvar 0x8005 0x4e
	goto ES_TutorHandleLearning

ES_Tutor80Selected:
	bufferattack 0x0 MOVE_STOREDPOWER
	setvar 0x8005 0x4f
	goto ES_TutorHandleLearning

ES_Tutor81Selected:
	bufferattack 0x0 MOVE_BRAVEBIRD
	setvar 0x8005 0x50
	goto ES_TutorHandleLearning

ES_Tutor82Selected:
	bufferattack 0x0 MOVE_SKYATTACK
	setvar 0x8005 0x51
	goto ES_TutorHandleLearning

ES_Tutor83Selected:
	bufferattack 0x0 MOVE_DRILLRUN
	setvar 0x8005 0x52
	goto ES_TutorHandleLearning

ES_Tutor84Selected:
	bufferattack 0x0 MOVE_BURNINGJEALOUSY
	setvar 0x8005 0x53
	goto ES_TutorHandleLearning

ES_Tutor85Selected:
	bufferattack 0x0 MOVE_MYSTICALFIRE
	setvar 0x8005 0x54
	goto ES_TutorHandleLearning

ES_Tutor86Selected:
	bufferattack 0x0 MOVE_HEATWAVE
	setvar 0x8005 0x55
	goto ES_TutorHandleLearning

ES_Tutor87Selected:
	bufferattack 0x0 MOVE_LIQUIDATION
	setvar 0x8005 0x56
	goto ES_TutorHandleLearning

ES_Tutor88Selected:
	bufferattack 0x0 MOVE_LASHOUT
	setvar 0x8005 0x57
	goto ES_TutorHandleLearning

ES_Tutor89Selected:
	bufferattack 0x0 MOVE_RETALIATE
	setvar 0x8005 0x58
	goto ES_TutorHandleLearning

ES_Tutor90Selected:
	bufferattack 0x0 MOVE_LEAFBLADE
	setvar 0x8005 0x59
	goto ES_TutorHandleLearning

ES_Tutor91Selected:
	bufferattack 0x0 MOVE_PSYCHICFANGS
	setvar 0x8005 0x5a
	goto ES_TutorHandleLearning

ES_Tutor92Selected:
	bufferattack 0x0 MOVE_HYPERBEAM
	setvar 0x8005 0x5b
	goto ES_TutorHandleLearning

ES_Tutor93Selected:
	bufferattack 0x0 MOVE_GIGAIMPACT
	setvar 0x8005 0x5c
	goto ES_TutorHandleLearning

ES_Tutor94Selected:
	bufferattack 0x0 MOVE_SLUDGEWAVE
	setvar 0x8005 0x5d
	goto ES_TutorHandleLearning

ES_Tutor95Selected:
	bufferattack 0x0 MOVE_CROSSPOISON
	setvar 0x8005 0x5e
	goto ES_TutorHandleLearning

ES_Tutor96Selected:
	bufferattack 0x0 MOVE_XSCISSOR
	setvar 0x8005 0x5f
	goto ES_TutorHandleLearning

ES_Tutor97Selected:
	bufferattack 0x0 MOVE_GRASSPLEDGE
	setvar 0x8005 0x60
	goto ES_TutorHandleLearning

ES_Tutor98Selected:
	bufferattack 0x0 MOVE_WATERPLEDGE
	setvar 0x8005 0x61
	goto ES_TutorHandleLearning

ES_Tutor99Selected:
	bufferattack 0x0 MOVE_FIREPLEDGE
	setvar 0x8005 0x62
	goto ES_TutorHandleLearning

ES_Tutor100Selected:
	bufferattack 0x0 MOVE_SCORCHINGSANDS
	setvar 0x8005 0x63
	goto ES_TutorHandleLearning

ES_Tutor101Selected:
	bufferattack 0x0 MOVE_POLLENPUFF
	setvar 0x8005 0x64
	goto ES_TutorHandleLearning

ES_Tutor102Selected:
	bufferattack 0x0 MOVE_EXTRASENSORY
	setvar 0x8005 0x65
	goto ES_TutorHandleLearning

ES_Tutor103Selected:
	bufferattack 0x0 MOVE_HIGHHORSEPOWER
	setvar 0x8005 0x66
	goto ES_TutorHandleLearning

ES_Tutor104Selected:
	bufferattack 0x0 MOVE_TAILSLAP
	setvar 0x8005 0x67
	goto ES_TutorHandleLearning

ES_Tutor105Selected:
	bufferattack 0x0 MOVE_POLTERGEIST
	setvar 0x8005 0x68
	goto ES_TutorHandleLearning

ES_Tutor106Selected:
	bufferattack 0x0 MOVE_GRASSYGLIDE
	setvar 0x8005 0x69
	goto ES_TutorHandleLearning

ES_Tutor107Selected:
	bufferattack 0x0 MOVE_POWERWHIP
	setvar 0x8005 0x6a
	goto ES_TutorHandleLearning

ES_Tutor108Selected:
	bufferattack 0x0 MOVE_FOULPLAY
	setvar 0x8005 0x6b
	goto ES_TutorHandleLearning

ES_Tutor109Selected:
	bufferattack 0x0 MOVE_DARKESTLARIAT
	setvar 0x8005 0x6c
	goto ES_TutorHandleLearning

ES_Tutor110Selected:
	bufferattack 0x0 MOVE_BODYPRESS
	setvar 0x8005 0x6d
	goto ES_TutorHandleLearning

ES_Tutor111Selected:
	bufferattack 0x0 MOVE_ENDEAVOR
	setvar 0x8005 0x6e
	goto ES_TutorHandleLearning

ES_Tutor112Selected:
	bufferattack 0x0 MOVE_ENCORE
	setvar 0x8005 0x6f
	goto ES_TutorHandleLearning

ES_Tutor113Selected:
	bufferattack 0x0 MOVE_SWORDSDANCE
	setvar 0x8005 0x70
	goto ES_TutorHandleLearning

ES_Tutor114Selected:
	bufferattack 0x0 MOVE_NASTYPLOT
	setvar 0x8005 0x71
	goto ES_TutorHandleLearning

ES_Tutor115Selected:
	bufferattack 0x0 MOVE_FIREBLAST
	setvar 0x8005 0x72
	goto ES_TutorHandleLearning

ES_Tutor116Selected:
	bufferattack 0x0 MOVE_HYDROPUMP
	setvar 0x8005 0x73
	goto ES_TutorHandleLearning

ES_Tutor117Selected:
	bufferattack 0x0 MOVE_LEAFSTORM
	setvar 0x8005 0x74
	goto ES_TutorHandleLearning

ES_Tutor118Selected:
	bufferattack 0x0 MOVE_THUNDER
	setvar 0x8005 0x75
	goto ES_TutorHandleLearning

ES_Tutor119Selected:
	bufferattack 0x0 MOVE_BLIZZARD
	setvar 0x8005 0x76
	goto ES_TutorHandleLearning

ES_Tutor120Selected:
	bufferattack 0x0 MOVE_HURRICANE
	setvar 0x8005 0x77
	goto ES_TutorHandleLearning

ES_Tutor121Selected:
	bufferattack 0x0 MOVE_DRAINPUNCH
	setvar 0x8005 0x78
	goto ES_TutorHandleLearning

ES_Tutor122Selected:
	bufferattack 0x0 MOVE_SUPERPOWER
	setvar 0x8005 0x79
	goto ES_TutorHandleLearning

ES_Tutor123Selected:
	bufferattack 0x0 MOVE_HEAVYSLAM
	setvar 0x8005 0x7a
	goto ES_TutorHandleLearning

ES_Tutor124Selected:
	bufferattack 0x0 MOVE_MEGAHORN
	setvar 0x8005 0x7b
	goto ES_TutorHandleLearning

ES_Tutor125Selected:
	bufferattack 0x0 MOVE_STONEEDGE
	setvar 0x8005 0x7c
	goto ES_TutorHandleLearning

ES_Tutor126Selected:
	bufferattack 0x0 MOVE_SUPERFANG
	setvar 0x8005 0x7d
	goto ES_TutorHandleLearning

ES_Tutor127Selected:
	bufferattack 0x0 MOVE_PAINSPLIT
	setvar 0x8005 0x7e
	goto ES_TutorHandleLearning

ES_Tutor128Selected:
	bufferattack 0x0 MOVE_SUBSTITUTE
	setvar 0x8005 0x7f
	goto ES_TutorHandleLearning

ES_Tutor129Selected:
	bufferattack 0x0 MOVE_FRENZYPLANT
	setvar 0x8005 0x80
	goto ES_TutorHandleLearning

ES_Tutor130Selected:
	bufferattack 0x0 MOVE_BLASTBURN
	setvar 0x8005 0x81
	goto ES_TutorHandleLearning

ES_Tutor131Selected:
	bufferattack 0x0 MOVE_HYDROCANNON
	setvar 0x8005 0x82
	goto ES_TutorHandleLearning

ES_Tutor132Selected:
	bufferattack 0x0 MOVE_DRACOMETEOR
	setvar 0x8005 0x83
	goto ES_TutorHandleLearning

ES_Tutor133Selected:
	bufferattack 0x0 MOVE_CLOSECOMBAT
	setvar 0x8005 0x84
	goto ES_TutorHandleLearning

ES_Tutor134Selected:
	bufferattack 0x0 MOVE_EXPANDINGFORCE
	setvar 0x8005 0x85
	goto ES_TutorHandleLearning

ES_Tutor135Selected:
	bufferattack 0x0 MOVE_MISTYEXPLOSION
	setvar 0x8005 0x86
	goto ES_TutorHandleLearning

ES_Tutor136Selected:
	bufferattack 0x0 MOVE_RISINGVOLTAGE
	setvar 0x8005 0x87
	goto ES_TutorHandleLearning

ES_Tutor137Selected:
	bufferattack 0x0 MOVE_STEELROLLER
	setvar 0x8005 0x88
	goto ES_TutorHandleLearning

ES_Tutor138Selected:
	bufferattack 0x0 MOVE_DOUBLETEAM
	setvar 0x8005 0x89
	goto ES_TutorHandleLearning

ES_Tutor139Selected:
	bufferattack 0x0 MOVE_DRAGONDANCE
	setvar 0x8005 0x8a
	goto ES_TutorHandleLearning

ES_Tutor140Selected:
	bufferattack 0x0 MOVE_GRAVITY
	setvar 0x8005 0x8b
	goto ES_TutorHandleLearning

ES_Tutor141Selected:
	bufferattack 0x0 MOVE_MAGICROOM
	setvar 0x8005 0x8c
	goto ES_TutorHandleLearning

ES_Tutor142Selected:
	bufferattack 0x0 MOVE_WONDERROOM
	setvar 0x8005 0x8d
	goto ES_TutorHandleLearning

ES_Tutor143Selected:
	bufferattack 0x0 MOVE_POWERUPPUNCH
	setvar 0x8005 0x8e
	goto ES_TutorHandleLearning

ES_Tutor144Selected:
	bufferattack 0x0 MOVE_LASTRESORT
	setvar 0x8005 0x8f
	goto ES_TutorHandleLearning

