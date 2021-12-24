#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

int cursorX, cursorY;
const uint8 sw, sh, sd;

void clearLine(uint8 from, uint8 to);

void updateCursor();
void clearScreen();
void scrollUp(uint8 noOfLines);

void newLineCheck();

void printCharacter(char ch);
void print(string s);

#endif
