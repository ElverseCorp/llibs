#ifndef LLIBS_FRAMEWORK_MAIN_H_
#define LLIBS_FRAMEWORK_MAIN_H_

/**************************************************************************//**
 * @file     main.h
 * @brief    Project L - Llibs, cross-platform framework / main.h
 * @version  V0.0.1
 * @date     24. Feb 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Standard main function type */
typedef li32 lm;

/* Standard main protorype */
extern lm lmain(lu32 argc, lc8* argv[]);

typedef enum {
    L_EXIT_SUCCESS = 0x00,
    L_EXIT_FAILURE = 0x01,
    // other codes...
} lerr_exit;

extern void lexit(lerr_exit status);

#endif // LLIBS_FRAMEWORK_MAIN_H_