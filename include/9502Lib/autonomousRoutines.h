/**
 * @file autonomousRoutines.h
 * @brief contains autonomous routine functions
 */

#include <API.h>

static void mobileGoalRight()
{
    //Grab preload cone
    setClaw(127);
    delay(500);
    setClaw(24);

    //Raise lift
    setLift(127);
    while(getLiftPot() < 3500)
    {
        delay(10);
    }
    setLift(0);
    
    //Pause
    delay(500);

    //Drive forward, get mobile goal
    drive(96, 0);
    delay(1750);
    //Lift mobile goal up onto robot
    setGoalLift(127);
    while(getGoalLiftPot() > 2000)
    {
        delay(10);
    }
    setGoalLift(0);
    drive(0, 0);
    
    //Pause
    delay(500);

    //Drive backward
    for(int i = 0; i < 65; i++)
    {
        drive(-i, 0);
        delay(25);
    }
    delay(500);
    drive(0, 0);
}
static void testProgram()
{
}