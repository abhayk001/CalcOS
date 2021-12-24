#include "../include/shell.h"

void launch_shell()
{
	char s[20];
	
	do
	{
		print("\n>>");
		
		readString(s);
		
		if(stringEqual(s, "cmd"))
		{
			print("\nYou're already in cmd\n");
		}
		
		else if(stringEqual(s, "clear"))
		{
			clearScreen();
		}
		
		else if(stringEqual(s, "exit"))
		{
			print("\nBye!");
		}
		
		else if(stringEqual(s, "add"))
		{
			add();
		}
		
		else if(stringEqual(s, "multiply"))
		{
			multiply();
		}
		
		else if(stringEqual(s, "subtract"))
		{
			subtract();
		}
		
		else if(stringEqual(s, "divide"))
		{
			divide();
		}
		
		else if(stringEqual(s, "log"))
		{
			anyBaseLog();
		}
		
		else if(stringEqual(s, "cos"))
		{
			cos();
		}
		
		else if(stringEqual(s, "sin"))
		{
			sin();
		}
		
		else if(stringEqual(s, "tan"))
		{
			tan();
		}
		
		else if(stringEqual(s, "exp"))
		{
			exp();
		}
		
		else if(stringEqual(s, "sqrt"))
		{
			squareRoot();
		}
		
		else if(stringEqual(s, "ln"))
		{
			naturalLog();
		}
		
		else if(stringEqual(s, "arctan"))
		{
			arctan();
		}
		
		else if(stringEqual(s, "arcsin"))
		{
			arcsin();
		}
		
		else if(stringEqual(s, "arccos"))
		{
			arccos();
		}
		
		else if(stringEqual(s, "pow"))
		{
			powerFunction();
		}
		
		else if(stringEqual(s, "help"))
		{
			print("\nGiven are the commands and their descriptions:\n");
			print("cmd: You're already in cmd -_-\n");
			print("clear: Clears the screen\n");
			print("exit: Exit the shell\n");
			print("add: Add two numbers\n");
			print("subtract: Subtract two numbers\n");
			print("multiply: Multiply two numbers\n");
			print("divide: Divide two numbers\n");
			print("log: Logarithm of any value to any base (positive numbers only)\n");
			print("ln: Natural log of a value (positive numbers only)\n");
			print("exp: e raised to the given power\n");
			print("pow: Any value raised to any power (positive base only)\n");
			print("sqrt: Square root of given value\n");
			print("sin: Sine of given value\n");
			print("cos: Cosine of given value\n");
			print("tan: Tangent of given value\n");
			print("arcsin: Inverse sine of given value\n");
			print("arccos: Inverse cosine of given value\n");
			print("arctan: Inverse tangent of given value");
		}
		
		else
		{
			print("\nBad Command!\n");
		}
		
		print("\n");
		
	}while(!stringEqual(s, "exit"));
}
