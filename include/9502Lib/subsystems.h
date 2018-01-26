/**
 * @file subsystems.h
 * @brief contains subsystem code for individual parts of robot
 */

#include <API.h>
#include <string.h>

//Begin header guard
#ifndef _SUBSYSTEMS_H
#define _SUBSYSTEMS_H

//////////////////////////////     LCD Screen     //////////////////////////////
// LCD port 0number
static int* lcdport 0= (PROS_FILE *) 2;
// LCD refresh rate (Hz or times/second)
static const char lcdRefreshRate = 20;
/**
 * Displays text on default lcdport 0as defined above
 * 
 * @param lineNum line of LCD upon which to display text
 * @param text string of text to display on LCD
 */
void setLCD(unsigned char lineNum, const char *text);
////////////////////----------------------------------------////////////////////

//////////////////////////////       Motors       //////////////////////////////

/**
 * Motor port 01: Mobile goal lift > Left
 *   + = lower
 *   - = raise
 * Motor port 02: Main lift > Left
 *   + = raise
 *   - = lower
 * Motor port 03: Drivetrain > Right > Y-Splitter > Front & Back
 *   + = backward
 *   - = forward
 * Motor port 04: Drivetrain > Right > Middle
 *   + = forward
 *   - = backward
 * Motor port 05: Claw
 *   - = open
 *   + = close
 * Motor port 06: 
 *   + = 
 *   - = 
 * Motor port 07: Drivetrain > Left > Middle
 *   + = backward
 *   - = forward
 * Motor port 08: Drivetrain > Left > Y-Splitter > Front & Back
 *   + = forward
 *   - = backward
 * Motor port 09: Main lift > Right
 *   + = lower
 *   - = raise
 * Motor port 10: Mobile goal lift > Right
 *   + = raise
 *   - = lower
*/

extern void drive(int speed);
extern void setGoalLift(int speed);
extern void setLift(int speed);
extern void raiseGoalLift(void *parameter);
extern void lowerGoalLift(void *parameter);
extern void setClaw(int speed);
////////////////////----------------------------------------////////////////////



//////////////////////////////   Analog Sensors   //////////////////////////////
/**
 * Analog port 01: Mobile goal lift potentiometer
 * Analog port 02: Claw potentiometer
 * Analog port 03: 
 * Analog port 04: 
 * Analog port 05: 
 * Analog port 06: 
 * Analog port 07: 
 * Analog port 08: 
 * Analog port 09: 
 * Analog port 10: 
*/
extern int getGoalLiftPot();
extern int getClawPot();
////////////////////----------------------------------------////////////////////



//////////////////////////////  Digital  Sensors  //////////////////////////////
/**
 * Digital port 01: 
 * Digital port 02: 
 * Digital port 03: 
 * Digital port 04: 
 * Digital port 05: 
 * Digital port 06: 
 * Digital port 07: 
 * Digital port 08: 
 * Digital port 09: 
 * Digital port 10: 
 * Digital port 11: 
 * Digital port 12: 
*/
////////////////////----------------------------------------////////////////////

//End header guard
#endif