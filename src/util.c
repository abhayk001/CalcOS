#include "../include/util.h"

void memory_copy(char* source, char* dest, int nbytes)
{
	int i;
	for(i = 0; i < nbytes; i++)
	{
		*(dest + i) = *(source + i);
	}
}

void memory_set(uint8 *dest, uint8 val, uint32 len)
{
	uint8 *temp = (uint8 *) dest;
	for( ; len != 0; len--)
		*temp++ = val;
}

void int_to_ascii(int32 n, char str[])
{
	int32 i, sign;
	if((sign = n) < 0)
		n = -n;
	i = 0;
	do
	{
		str[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	
	if(sign < 0)
		str[i++] = '-';
	str[i] = '\0';
}

void int_to_string(int32 n, string s)
{
	int_to_ascii(n, s);
	//Doing string reverse now
	int32 len = strlength(s);
	int32 i = 0;
	int32 j = len - 1;
	while(i < (len/2 + len%2))
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

int32 string_to_int(string s)
{
	int32 n = 0;
	int32 p = 1;
	int32 strlen = strlength(s);
	int32 i;
	for(i = strlen - 1; i >= 0; i--)
	{
		n += ((int32) (s[i] - '0')) * p;
		p *= 10;
	}
	return n;
}

float string_to_float(string s)
{
	int32 i = 0, j = 0, k = 0;
	float n;
	int32 int_part, float_part, sign;
	sign = 1;
	char s_decimal[10];
	char s_int[20];
	uint8 point_passed = 0;
	if(s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(s[i] != '\0')
	{
		if(s[i] == '.')
		{
			point_passed = 1;
			i++;
			continue;
		}
		if(point_passed == 1)
		{
			s_decimal[k] = s[i];
			k++;
		}
		else
		{
			s_int[j] = s[i];
			j++;
		}
		i++;
	}
	s_decimal[k] = '\0';
	s_int[j] = '\0';
	int_part = string_to_int(s_int);
	float_part = string_to_int(s_decimal);
	float fl_part = (float)float_part;
	while(k > 0)
	{
		fl_part /= 10.0f;
		k--;
	}
	n = (float)int_part + fl_part;
	n = sign * n;
	return n;
}

void float_to_string(float n, string s, uint16 precision)
{
	int32 int_part = (int32) n;
	float float_part = n - (float) int_part;
	if(float_part < 0)
		float_part = -float_part;
	uint16 i;
	for(i = 0; i < precision; i++)
	{
		float_part *= 10.0f;
	}
	int32 fl_part = (int32) float_part;
	char s_int[20];
	char s_float[10];
	int_to_string(int_part, s_int);
	int_to_string((int32)float_part, s_float);
	i = 0;
	int32 k = 0;
	if(n < 0)
	{
		s[k] = '-';
		k++;
		i++;
	}
	if(s_int[i] == '\0')
	{
		s[k] = '0';
		k++;
	}
	while(s_int[i] != '\0')
	{
		s[k] = s_int[i];
		k++;
		i++;
	}
	s[k] = '.';
	k++;
	i = 0;
	uint16 len = strlength(s_float);
	for(i = 0; i < precision - len; i++)
	{
		s[k] = '0';
		k++;
	}
	i = 0;
	while(s_float[i] != '\0')
	{
		s[k] = s_float[i];
		k++;
		i++;
	}
	s[k] = '\0';
}
