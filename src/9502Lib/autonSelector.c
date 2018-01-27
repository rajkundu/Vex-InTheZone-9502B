/**
 * @file autonSelector.c
 * @brief contains code related to LCD autonomous selector
 */
#include "9502Lib/autonSelector.h"

/**
 * Array of strings (char[])s for lcd to show names of autonomous routines -
 * each string should correspond to an autonomous routine/method
 */
char routineNames[][17] =
{
	"   Do Nothing   ",
	"Mobile Goal  (L)",
	"  TEST PROGRAM  "
};

/**
 * Variable that holds the number of the selected routine; used in a switch
 * statement in autonomous() function in auto.c to determine which routine
 * will be run
 */
unsigned char routineNum;

/**
 * Function that is run in the initialize portion of the match, before
 * autonomous; allows a user to choose the autonomous routine to run for the
 * match
 */
void autonSelector(void *parameter)
{
	unsigned char currentRoutineNum = 0;
	int numRoutines = sizeof(routineNames)/sizeof(routineNames[0]);
	char selectString[17] = "                ";

	// Turn on the LCD backlight, signifying that it needs input
	lcdSetBacklight(lcdPort, true);

	// While the robot is not in autonomous mode or is disabled...
	while(!(isAutonomous()))
	{
		//If on the first, leftmost routine...
		if(currentRoutineNum == 0)
		{
			//Hide the left arrow
			strcpy(selectString, "      Done     >");
		}
		//Otherwise, if on the last, rightmost routine...
		else if(currentRoutineNum == (numRoutines - 1))
		{
			//Hide the right arrow
			strcpy(selectString, "<     Done      ");
		}
		//Else, if on one of the middle routines...
		else
		{
			//Show both left and right arrows
			strcpy(selectString, "<     Done     >");
		}

		//Display current autonomous routine name on the top line
		lcdSetText(lcdPort, 1, routineNames[currentRoutineNum]);
		//Display "Select" on the bottom line
		lcdSetText(lcdPort, 2, selectString);

		//If the center LCD button is pressed...
		if(lcdReadButtons(lcdPort) == 2)
		{
			//Break loop, selecting current program
			break;
    	}
		//Otherwise, if (the left LCD button is pressed) and (the currently
		//displayed routine is not the first)...
		else if(lcdReadButtons(lcdPort) == 1 && (currentRoutineNum > 0))
		{
			//Wait for button release
			while(lcdReadButtons(lcdPort) == 1)
			{
				//Do nothing
				delay(1000.0 / lcdRefreshRate);
			}
			//Go to the routine to the left
			currentRoutineNum--;
		}
		//Otherwise, if (the right LCD button is pressed) and (the currently
		//displayed routine is not the last)...
		else if(lcdReadButtons(lcdPort) == 4 && (currentRoutineNum < \
		(numRoutines - 1)))
		{
			//Wait for button release
			while(lcdReadButtons(lcdPort) == 4)
			{
				//Do nothing
				delay(1000.0 / lcdRefreshRate);
			}
			//Go to the routine to the right
			currentRoutineNum++;
		}
		//Else, if no LCD buttons are pressed...
		else
		{
			//Do nothing
		}

		delay(1000.0 / lcdRefreshRate);
	}

	routineNum = currentRoutineNum;
	lcdSetText(lcdPort, 2, " ^  Selected  ^ ");
	lcdSetBacklight(lcdPort, false);
	taskDelete(NULL);
	return;
}