#include "../include/screen.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/shell.h"
kmain()
{
	isr_install();
	clearScreen();
	print("Hello there!\nHow are you doing?\nWelcome to CalOS!");
	print("\nEnter your command\n");
	launch_shell();
}
