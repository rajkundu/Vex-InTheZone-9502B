/**
 * @file subsystems.c
 * @brief contains subsystem code for individual parts of robot
 */

#include <API.h>
#include "9502Lib/subsystems.h"

//////////////////////////////     LCD Screen     //////////////////////////////
void setLCD(unsigned char lineNum, const char *text)
{
    lcdSetText(lcdPort, lineNum, text);
    return;
}
////////////////////----------------------------------------////////////////////



//////////////////////////////       Motors       //////////////////////////////
void drive(int y, int r)
{
    motorSet(8, y + r);
    motorSet(7, -(y - r));
    motorSet(3, -y + r);
    motorSet(4, y - r);
}
void setGoalLift(int speed)
{
    motorSet(1, -speed);
    motorSet(10, speed);
}
void setLift(int speed)
{
    motorSet(2, speed);
    motorSet(9, -speed);
}
void raiseGoalLift(void *parameter)
{
    while(getGoalLiftPot() > 2400)
    {
        setGoalLift(127);
    }
    taskDelete(NULL);
    return;
}
void lowerGoalLift(void *parameter)
{
    while(getGoalLiftPot() < 2750)
    {
        setGoalLift(-127);
    }
    taskDelete(NULL);
    return;
}
void setClaw(int speed)
{
    motorSet(5, -speed);
}
////////////////////----------------------------------------////////////////////



//////////////////////////////   Analog Sensors   //////////////////////////////
int getGoalLiftPot()
{
    return analogRead(1);
}
int getClawPot()
{
    return analogRead(2);
}
int getLiftPot()
{
    return analogRead(3);
}
////////////////////----------------------------------------////////////////////



//////////////////////////////  Digital  Sensors  //////////////////////////////
////////////////////----------------------------------------////////////////////