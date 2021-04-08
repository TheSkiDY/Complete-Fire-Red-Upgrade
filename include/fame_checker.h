#ifndef GUARD_FAME_CHECKER_H
#define GUARD_FAME_CHECKER_H

#include "main.h"

#define FAMECHECKER_OAK          0
#define FAMECHECKER_DAISY        1
#define FAMECHECKER_BROCK        2
#define FAMECHECKER_MISTY        3
#define FAMECHECKER_LTSURGE      4
#define FAMECHECKER_ERIKA        5
#define FAMECHECKER_KOGA         6
#define FAMECHECKER_SABRINA      7
#define FAMECHECKER_BLAINE       8
#define FAMECHECKER_LORELEI      9
#define FAMECHECKER_BRUNO       10
#define FAMECHECKER_AGATHA      11
#define FAMECHECKER_LANCE       12
#define FAMECHECKER_BILL        13
#define FAMECHECKER_MRFUJI      14
#define FAMECHECKER_GIOVANNI    15
#define NUM_FAMECHECKER_PERSONS 16

#define FCPICKSTATE_NO_DRAW    0
#define FCPICKSTATE_SILHOUETTE 1
#define FCPICKSTATE_COLORED    2

enum {
    FCWINDOWID_LIST,
    FCWINDOWID_UIHELP,
    FCWINDOWID_MSGBOX,
    FCWINDOWID_ICONDESC
};

extern struct ListMenuTemplate gFameChecker_ListMenuTemplate;
extern u8 gIconDescriptionBoxIsOpen;

/*
void ResetFameChecker(void);
void FullyUnlockFameChecker(void);
void UseFameChecker(MainCallback savedCallback);
void SetFlavorTextFlagFromSpecialVars(void);
void UpdatePickStateFromSpecialVar8005(void);
*/
#endif //GUARD_FAME_CHECKER_H
