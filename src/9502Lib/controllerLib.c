/**
 * @file controllerLib.c
 * @brief wrapper for PROS controller interface
 */

#include <API.h>
#include "9502Lib/controllerLib.h"

signed char getJoy(controller controllerName, joyChannel channel)
{
  //Retrieve joystick value
  int joyVal = joystickGetAnalog(controllerName, channel);
  //Deadzone
  if(abs(joyVal) > deadZone)
  {
    return joyVal;
  }
  else
  {
    return 0;
  }
}

bool btnDown(controller controllerName, button buttonName)
{
  int buttonGroupNum = 0;
  int buttonDirection = 0;
  switch(buttonName)
  {
    case Btn5D:
    {
      buttonGroupNum = 5;
      buttonDirection = 1;
      break;
    }
    case Btn5U:
    {
      buttonGroupNum = 5;
      buttonDirection = 4;
      break;
    }
    case Btn6D:
    {
      buttonGroupNum = 6;
      buttonDirection = 1;
      break;
    }
    case Btn6U:
    {
      buttonGroupNum = 6;
      buttonDirection = 4;
      break;
    }
    case Btn7D:
    {
      buttonGroupNum = 7;
      buttonDirection = 1;
      break;
    }
    case Btn7L:
    {
      buttonGroupNum = 7;
      buttonDirection = 2;
      break;
    }
    case Btn7U:
    {
      buttonGroupNum = 7;
      buttonDirection = 4;
      break;
    }
    case Btn7R:
    {
      buttonGroupNum = 7;
      buttonDirection = 8;
      break;
    }
    case Btn8D:
    {
      buttonGroupNum = 8;
      buttonDirection = 1;
      break;
    }
    case Btn8L:
    {
      buttonGroupNum = 8;
      buttonDirection = 2;
      break;
    }
    case Btn8U:
    {
      buttonGroupNum = 8;
      buttonDirection = 4;
      break;
    }
    case Btn8R:
    {
      buttonGroupNum = 8;
      buttonDirection = 8;
      break;
    }
    default:
    {
      break;
    }
  }
  return (joystickGetDigital(controllerName, buttonGroupNum, buttonDirection) \
    == 1);
}
