/**
 * @file customStrings.c
 * @brief custom functions and wrappers for text and strings
 */

#include "9502Lib/customStrings.h"

char* strcen(char *stringToCenter)
{
    char tempString[17] = "                ";
    int numSpaces = 8 - strlen(stringToCenter)/2;
    for(int i = 0; i < strlen(stringToCenter); i++)
    {
        tempString[i + numSpaces] = stringToCenter[i];
    }
    strcpy(stringToCenter, tempString);
    return stringToCenter;
}
char* strapp(char *mainString, char *textToAppend)
{
	strcpy(mainString, strcat(mainString, textToAppend));
    return mainString;
}
char* strnum(char *destString, float number)
{
    char stringFromInt[17];
    sprintf(stringFromInt, "%.2f", number);
    strcpy(destString, stringFromInt);
    return destString;
}