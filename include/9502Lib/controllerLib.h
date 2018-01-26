/**
 * @file controllerLib.h
 * @brief wrapper for PROS controller interface
 */

//Begin header guards
#ifndef _CONTROLLERLIB_H
#define _CONTROLLERLIB_H

//Deadzone/deadband on joystick input; threshold at & below which input is
//neglected and getJoy() function returns 0
#define deadZone 16

typedef enum {main = 1, partner = 2} controller;
typedef enum {rightX = 1, rightY = 2, leftY = 3, leftX = 4} joyChannel;
typedef enum {Btn5D, Btn5U, Btn6D, Btn6U, Btn7D, Btn7L, Btn7U, Btn7R, Btn8D,
  Btn8L, Btn8U, Btn8R} button;
typedef enum {U = 4, D = 1, L = 2, R = 8} buttonDirection;

/**
 * Wrapper function used for getting joystick channel value on controller
 *
 * @param controller either "main" (controller 1) or "partner" (controller 2)
 * as defined in the enum "controller" in corresponding .h file
 * @param channel any memeber of enum "joyChannel" in corresponding .h file i.e.
 * leftX, leftY, rightX, or rightY
 * @return returns value in [-127, 127] for joystick channel with a deadZone
 * (aka "dead band") active as defined in corresponding .h file
 */
signed char getJoy(controller controllerName, joyChannel channel);

/**
 * Wrapper function used for getting joystick button value on controller
 *
 * @param controller either "main" (controller 1) or "partner" (controller 2)
 * as defined in the enum "controller" in corresponding .h file
 * @param buttonName any member of enum "button" in corresponding .h file
 * @return returns true if button is pressed or false if button is not pressed
 */
bool btnDown(controller controllerName, button buttonName);

//End header guards
#endif
