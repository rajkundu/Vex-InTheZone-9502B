/**
 * @file autonSelector.h
 * @brief contains code related to LCD autonomous selector
 */

//Begin header guard
#ifndef _AUTONSELECTOR_H
#define _AUTONSELECTOR_H

#include "main.h"

/**
 * Array of strings (char[])s for lcd to show names of autonomous routines -
 * each string should correspond to an autonomous routine/method
 */
extern char routineNames[][17];

/**
 * Variable that holds the number of the selected routine; used in a switch
 * statement in autonomous() function in auto.c to determine which routine
 * will be run
 */
extern unsigned char routineNum;

/**
 * Function that is run in the initialize portion of the match, before
 * autonomous; allows a user to choose the autonomous routine to run for the
 * match
 */
extern void autonSelector(void *parameter);

//End header guard
#endif
