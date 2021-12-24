#include "../include/string.h"

uint16 strlength(string ch)
{
	uint16 i = 0;
	while(ch[i])
	{
		i++;
	}
	return i;
}

uint8 stringEqual(string s1, string s2)
{
	uint8 result = 1;
	uint8 len = strlength(s1);
	
	if(strlength(s2) != len)
		result = 0;
	
	else
	{
		uint8 i = 0;
		
		for(i; i < len; i++)
		{
			if(s1[i] != s2[i])
			{
				result = 0;
				break;
			}
		}
	}
	
	return result;
}
