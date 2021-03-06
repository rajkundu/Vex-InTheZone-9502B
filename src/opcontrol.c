/**
 * @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any
 * functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "9502Lib/controllerLib.h"

//Refresh rate (in Hz) for driver mode
unsigned char refreshRate = 20;

/*
 * Runs the user operator control code. This function will be started in its own
 * task with the default priority and stack size whenever the robot is enabled
 * via the Field Management System or the VEX Competition Switch in the operator
 * control mode. If the robot is disabled or communications is lost, the
 * operator control task will be stopped by the kernel. Re-enabling the robot
 * will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the
 * VEX Cortex will run the operator control task. Be warned that this will also
 * occur if the VEX Cortex is tethered directly to a computer via the USB A to A
 * cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is
 * available and the scheduler is operational. However, proper use of delay() or
 * taskDelayUntil() is highly recommended to give other tasks (including system
 * tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop,
 * even if empty.
 */

void operatorControl()
{
	lcdClear(lcdPort);
	lcdSetBacklight(lcdPort, true);
    lcdSetText(lcdPort, 1, " Driver Control ");
	lcdSetText(lcdPort, 2, "      Mode      ");

	char debugString[17];
	int clawSpeed;
	int liftSpeed;
	int y = 0;
	int r = 0;

	while(true)
	{
		//Drivetrain
		y = getJoy(main, leftY);
		r = btnDown(main, Btn5U) ? -64 : (btnDown(main, Btn6U) ? 64 : 0);
		drive(y, r);
		
		//Goal lift
		setGoalLift(getJoy(main, rightY));
		if(btnDown(main, Btn8U))
		{
			while(btnDown(main, Btn8U))
			{
				//Wait for button release
			}
			taskCreate(raiseGoalLift, TASK_DEFAULT_STACK_SIZE, NULL, \
			TASK_PRIORITY_DEFAULT);
		}
		else if(btnDown(main, Btn8D))
		{
			while(btnDown(main, Btn8D))
			{
				//Wait for button release
			}
			taskCreate(lowerGoalLift, TASK_DEFAULT_STACK_SIZE, NULL, \
			TASK_PRIORITY_DEFAULT);
		}

		//Lift
		liftSpeed = getJoy(partner, rightY);
		if(((getLiftPot() > 3850)&&(liftSpeed > 0))|| \
		((getLiftPot() < 2050)&&(liftSpeed < 0)))
		{
			liftSpeed = 0;
		}
		setLift(liftSpeed);
		
		//Claw
		clawSpeed = btnDown(partner, Btn5U) ? -127 : \
		(btnDown(partner, Btn6U) ? 127 : 24);
		setClaw(clawSpeed);

		//Debugging
		setLCD(1, strnum(debugString, (getLiftPot())));
		setLCD(2, strnum(debugString, (getLiftPot() / 50.0)));

		delay(1000.0 / refreshRate);
	}
}
