/**
 * @file customStrings.h
 * @brief custom functions and wrappers for text and strings
 */

#include <API.h>
#include <string.h>

/**
 * Wrapper for sprintf that makes a text string from a number
 * • Float precision is 2 decimals
 * 
 * @param destString the destination string (char[]) in which to store the text
 * @param number the number to convert to a text string
 * @return the pointer to the passed string — useful for nesting string
 * operations in function calls
 */
extern char* strnum(char *destString, float number);
/**
 * Pads a string with whitespace so that the string is centered
 * • Assumes 16 characters visible — for use on LCD screen
 * 
 * @param stringToCenter the string which will be centered
 * @return the pointer to the passed string — useful for nesting string
 * operations in function calls
 */
extern char* strcen(char *stringToCenter);
/**
 * Combination of strcpy() and strcat() which appends a second string to a first
 * 
 * @param mainString the string which will come first
 * @param textToAppend the string which will come after mainString
 * @return the pointer to the passed string — useful for nesting string
 * operations in function calls
 */
extern char* strapp(char *mainString, char *textToAppend);