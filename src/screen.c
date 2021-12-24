#include "../include/screen.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;		// Defining screen width, height and depth (by depth it means both character and color info for one block)

void clearLine(uint8 from, uint8 to)
{
	uint16 i = sw * from * sd;
	string vidmem = (string) 0xb8000;
	for(i; i < (sw * (to + 1) * sd); i++)
	{
		vidmem[i] = 0x0;
	}
}

void updateCursor()
{
	unsigned int temp;
	temp = cursorY * sw + cursorX;
	
	outportb(0x3D4, 14);
	outportb(0x3D5, temp >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
}

void clearScreen()
{
	clearLine(0, sh - 1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}

void scrollUp(uint8 noOfLines)	// No of lines to scroll up
{
	string vidmem = (string) 0xb8000;
	uint16 i = 0;
	for(i; i < sw * (sh - 1) * sd; i++)
	{
		vidmem[i] = vidmem[i + sw * sd * noOfLines];
	}
	clearLine(sh - 1 - noOfLines, sh - 1);
	if(cursorY - noOfLines < 0)
	{
		cursorX = 0;
		cursorY = 0;
	}
	else
	{
		cursorY -= noOfLines;
	}
	updateCursor();
}

void newLineCheck()	// To simulate scrolling when we go down
{
	if(cursorY >= sh - 1)
	{
		scrollUp(1);
	}
}

void printCharacter(char ch)	// This prints a character on the screen
{
	string vidmem = (string) 0xb8000;
	
	switch(ch)
	{
		case 0x08:	// Backspace
			if(cursorX > 0)
			{
				cursorX--;
				vidmem[(cursorY * sw + cursorX)*sd] = 0x00;
			}
			break;
		
		case 0x09:	// Tab
			cursorX = (cursorX + 8) & ~(7);
			break;
		
		case '\r':	// Go to the beginning of the line
			cursorX = 0;
			break;
		
		case '\n':	// Go to the next line
			cursorY++;
			cursorX = 0;
			break;
		
		default:
			vidmem[(cursorY * sw + cursorX) * sd] = ch;
			vidmem[(cursorY * sw + cursorX) * sd + 1] = 0x0F;
			cursorX++;

	}
	
	if(cursorX >= sw)
	{
		cursorX = 0;
		cursorY++;
	}
	
	newLineCheck();
	updateCursor();
}

void print(string s)
{
	uint8 i = 0;
	uint8 len = strlength(s);
	
	for(i; i < len; i++)
	{
		printCharacter(s[i]);
	}
}
