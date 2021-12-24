#include "../include/kb.h"

void readString(string buffstr)
{
	uint8 i = 0;
	uint8 reading = 1;
	
	while(reading)
	{
		if(inportb(0x64) & 0x1)	// Checking if a keyboard input has been made
		{
			switch(inportb(0x60))
			{
				case 2:
					printCharacter('1');
					buffstr[i] = '1';
					i++;
					break;
				
				case 3:
					printCharacter('2');
					buffstr[i] = '2';
					i++;
					break;
				
				case 4:
					printCharacter('3');
					buffstr[i] = '3';
					i++;
					break;
				
				case 5:
					printCharacter('4');
					buffstr[i] = '4';
					i++;
					break;
				
				case 6:
					printCharacter('5');
					buffstr[i] = '5';
					i++;
					break;
				
				case 7:
					printCharacter('6');
					buffstr[i] = '6';
					i++;
					break;
				
				case 8:
					printCharacter('7');
					buffstr[i] = '7';
					i++;
					break;
				
				case 9:
					printCharacter('8');
					buffstr[i] = '8';
					i++;
					break;
				
				case 10:
					printCharacter('9');
					buffstr[i] = '9';
					i++;
					break;
				
				case 11:
					printCharacter('0');
					buffstr[i] = '0';
					i++;
					break;
				
				case 12:
					printCharacter('-');
					buffstr[i] = '-';
					i++;
					break;
				
				case 13:
					printCharacter('=');
					buffstr[i] = '=';
					i++;
					break;
				
				case 14:	// Backspace
					printCharacter(0x08);
					i--;
					break;
				
				case 15: 	// Tab
					printCharacter(0x09);
					reading = 0;
					break;
				
				case 16:
					printCharacter('q');
					buffstr[i] = 'q';
					i++;
					break;
				
				case 17:
					printCharacter('w');
					buffstr[i] = 'w';
					i++;
					break;
				
				case 18:
					printCharacter('e');
					buffstr[i] = 'e';
					i++;
					break;
				
				case 19:
					printCharacter('r');
					buffstr[i] = 'r';
					i++;
					break;
				
				case 20:
					printCharacter('t');
					buffstr[i] = 't';
					i++;
					break;
				
				case 21:
					printCharacter('y');
					buffstr[i] = 'y';
					i++;
					break;
				
				case 22:
					printCharacter('u');
					buffstr[i] = 'u';
					i++;
					break;
				
				case 23:
					printCharacter('i');
					buffstr[i] = 'i';
					i++;
					break;
				
				case 24:
					printCharacter('o');
					buffstr[i] = 'o';
					i++;
					break;
				
				case 25:
					printCharacter('p');
					buffstr[i] = 'p';
					i++;
					break;
				
				case 26:
					printCharacter('[');
					buffstr[i] = '[';
					i++;
					break;
				
				case 27:
					printCharacter(']');
					buffstr[i] = ']';
					i++;
					break;
				
				case 28:	// Enter key
					printCharacter('\n');
					reading = 0;
					break;
				
				case 29:
					//Left Ctrl Key
					break;
				
				case 30:
					printCharacter('a');
					buffstr[i] = 'a';
					i++;
					break;
				
				case 31:
					printCharacter('s');
					buffstr[i] = 's';
					i++;
					break;
				
				case 32:
					printCharacter('d');
					buffstr[i] = 'd';
					i++;
					break;
				
				case 33:
					printCharacter('f');
					buffstr[i] = 'f';
					i++;
					break;
				
				case 34:
					printCharacter('g');
					buffstr[i] = 'g';
					i++;
					break;
				
				case 35:
					printCharacter('h');
					buffstr[i] = 'h';
					i++;
					break;
				
				case 36:
					printCharacter('j');
					buffstr[i] = 'j';
					i++;
					break;
				
				case 37:
					printCharacter('k');
					buffstr[i] = 'k';
					i++;
					break;
				
				case 38:
					printCharacter('l');
					buffstr[i] = 'l';
					i++;
					break;
				
				case 39:
					printCharacter(';');
					buffstr[i] = ';';
					i++;
					break;
				
				case 40:
					printCharacter('\'');
					buffstr[i] = '\'';
					i++;
					break;
				
				case 41:
					printCharacter('`');
					buffstr[i] = '`';
					i++;
					break;
				
				case 42:
					// Left Shift Key
					break;
				
				case 43:
					printCharacter('\\');
					buffstr[i] = '\\';
					i++;
					break;
				
				case 44:
					printCharacter('z');
					buffstr[i] = 'z';
					i++;
					break;
				
				case 45:
					printCharacter('x');
					buffstr[i] = 'x';
					i++;
					break;
				
				case 46:
					printCharacter('c');
					buffstr[i] = 'c';
					i++;
					break;
				
				case 47:
					printCharacter('v');
					buffstr[i] = 'v';
					i++;
					break;
				
				case 48:
					printCharacter('b');
					buffstr[i] = 'b';
					i++;
					break;
				
				case 49:
					printCharacter('n');
					buffstr[i] = 'n';
					i++;
					break;
				
				case 50:
					printCharacter('m');
					buffstr[i] = 'm';
					i++;
					break;
				
				case 51:
					printCharacter(',');
					buffstr[i] = ',';
					i++;
					break;
				
				case 52:
					printCharacter('.');
					buffstr[i] = '.';
					i++;
					break;
				
				case 53:
					printCharacter('/');
					buffstr[i] = '/';
					i++;
					break;
				
				case 54:
					// Right Shift Key
					break;
				
				case 55:
					// PrtScrn or * I don't know
					break;
				
				case 56:
					// Left Alt key
					break;
				
				case 57:
					printCharacter(' ');
					reading = 0;
					break;
				
				case 58:
					// Caps Lock Key
					break;
			}
		}
	}
	
	buffstr[i] = '\0';
}
