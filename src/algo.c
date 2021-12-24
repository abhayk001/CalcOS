#include "../include/algo.h"

void add()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the first number: ");
	readString(s1);
	a = string_to_float(s1);
	print("\nEnter the second number: ");
	readString(s2);
	b = string_to_float(s2);
	result = a + b;
	float_to_string(result, res_str, PRECISION);
	print("\nSum is: ");
	print(res_str);
}

void subtract()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the first number: ");
	readString(s1);
	a = string_to_float(s1);
	print("\nEnter the second number: ");
	readString(s2);
	b = string_to_float(s2);
	result = a - b;
	float_to_string(result, res_str, PRECISION);
	print("\nDifference is: ");
	print(res_str);
}

void multiply()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the first number: ");
	readString(s1);
	a = string_to_float(s1);
	print("\nEnter the second number: ");
	readString(s2);
	b = string_to_float(s2);
	result = a * b;
	float_to_string(result, res_str, PRECISION);
	print("\nProduct is: ");
	print(res_str);
}

void divide()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the first number: ");
	readString(s1);
	a = string_to_float(s1);
	print("\nEnter the second number: ");
	readString(s2);
	b = string_to_float(s2);
	if(b == 0)
		print("\nDivision by zero is undefined");
	else
	{
		result = a / b;
		float_to_string(result, res_str, PRECISION);
		print("\nQuotient is: ");
		print(res_str);
	}
}

float abs(float x)
{
	if(x < 0)
		x = -x;
	return x;
}

float sqrt(float n)
{
    float x = 10;
    float x1;
    while(1)
    {
        x1 = x / 2 + n / (2 * x);
        if(x1 > x)
        {
            if(x1 - x < 0.00001)
                break;
        }
        else
        {
            if(x - x1 < 0.00001)
                break;
        }
        x = x1;
    }
    return x1;
}

float pow(float x, int n)
{
	int i;
	float result = 1;
	for(i = 0; i < n; i++)
		result *= x;
	return result;
}

float power(float x, float n)
{
	return exponent(n * ln(x));
}

float log(float value, float base)
{
	float a = ln(value);
	float b = ln(base);
	float result = a / b;
	return result;
}

void anyBaseLog()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the value: ");
	readString(s1);
	a = string_to_float(s1);
	if(a <= 0)
		print("\nLog is not defined for values <= 0");
	else
	{
		print("\nEnter the base: ");
		readString(s2);
		b = string_to_float(s2);
		if(b <= 0 || b == 1)
			print("\nLog is not defined when base is <= 0 or when it is 1");
		else
		{
			result = log(a, b);
			float_to_string(result, res_str, PRECISION);
			print("\nLog is: ");
			print(res_str);
		}
	}
}

float ln(float x)
{
    if(x >= 1 && x < sqrt(10))
    {
        float y = (x - 1) / (x + 1);
        float res = 2*(y + pow(y, 3) / 3 + pow(y, 5) / 5 + pow(y, 7) / 7 + pow(y, 9) / 9 + pow(y, 11) / 11);
        return res;
    }
    else
    {
        int p = 0;
        while(x >= 10)
        {
		x /= 10;
		p++;
        }
        while(x < 1)
        {
        	x *= 10;
        	p--;
        }
        return 2*ln(sqrt(x)) + 2.302585 * p;
    }
}

float exponent(float n)
{
	if(n < 0)
		return 1 / exponent(-n);
	else
	{
		int x = (int)n;
		float r = n - (float)x;
		if(r > 0.5)
		{
		x++;
		r = r - 1;
		}
		else if(r < -0.5)
		{
		x--;
		r = 1 + r;
		}

		float p1 = pow(2.7182818, x);
		float p2 = 1 + r + pow(r, 2) / 2 + pow(r, 3) / 6 + pow(r, 4) / 24 + pow(r, 5) / 120 + pow(r, 6) / 720 + pow(r, 7) / 5040;
		float result = p1 * p2;
		return result;
	}
}

float cos_func(float x)
{
	float result;
	if(x < 0)
	{
		return cos_func(-x);
	}
	if (x>(2*3.1415))
	{
		return cos_func(x - (2*3.1415));
	}

	if ((x >(1.5)*3.1415) && (x<=((2.0)*3.1415) ))
	{
		result = -cos_func(x-(3.1415));
	    	return result;
	}
	if ((x >=3.1415 / 2) && (x <=((1.5)*3.1415) ))
	{
		return -cos_func(3.1415 - x);
	}
	if ((x < (3.1415/2) && x > (3.1415/4)))
	{
		x = (3.1415/2) - x;   
		result= x - (pow(x,3)/6) + (pow(x,5)/120);
		return result;
	}
	if (x < (3.1415/4))
	{
		result= 1 - (pow(x,2)/2 ) + (pow(x,4)/24) - (pow(x,6)/720);
		return result;
	}
}

float sin_func(float x)
{
	float result;
	if (x>(2*3.1415))
	{
		return sin_func(x - (2*3.1415));
	}
	
	if(x < 0)
	{
		result = -sin_func(-x);
		return result;
	}

	if ((x >(1.5)*3.1415) && (x<=((2.0)*3.1415) ))
	{
		result = sin_func(x-(3.1415));
		return (-result);
	}


	if ((x >3.1415) && (x <=((1.5)*3.1415) ))
	{
		result = sin_func(x-(3.1415));
		return (-result);
	}

	if ((x >= (3.1415/2)) && (x<=(3.1415) ))
	{
		result = sin_func(x-(3.1415));
		return result;
	}



	if ((x < (3.1415/2) && x > (3.1415/4)))
	{
		result = cos_func((3.1415/2) -x);
		return result;
	}


	if (x < (3.1415/4) && x >= 0)
	{
		result= x - (pow(x,3)/6) + (pow(x,5)/120);
		return result;
	} 
}

float tan_func(float x)
{
    float result;
    result = (sin_func(x)/cos_func(x));
    return result;
}

float invtan(float x)
{
    float result;
    if (x < 0)
    {
    	result = 0.00 - invtan(abs(x));
    	return result;
    }
    if (x > 1)
    {
	    result = (3.1415/2.0) - invtan(1/x) ;    
	    return result;
    }
    if ( (x < 1) && (x > 0.2679) )
    {
	result= (3.1415/6.0) + invtan((1.732 *(x) - 1)/(1.732 + x));
    	return result;
    }
    else
    {
    	result= x- (pow(x,3)/3) + (pow(x,5)/5);
    	return result;
    }
}

float invsin(float x)
{
    float result;
    result = invtan(x/sqrt(1- pow(x,2))); 
    return result;
}
    
float invcos(float x)
{
    float result;
    result = invtan(sqrt(1-pow(x,2))/x);
    if(result < 0)
    	result = 3.1415 + result;
    return result;
}   

void cos()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	result = cos_func(a);
	float_to_string(result, res_str, PRECISION);
	print("\nCosine is: ");
	print(res_str);
}

void sin()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	result = sin_func(a);
	float_to_string(result, res_str, PRECISION);
	print("\nSine is: ");
	print(res_str);
}

void tan()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	result = tan_func(a);
	float_to_string(result, res_str, PRECISION);
	print("\nTan is: ");
	print(res_str);
}

void exp()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	result = exponent(a);
	float_to_string(result, res_str, PRECISION);
	print("\nExponent is: ");
	print(res_str);
}

void squareRoot()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	if(a < 0)
		print("\nReal square root is not defined for negative numbers");
	else
	{
		result = sqrt(a);
		float_to_string(result, res_str, PRECISION);
		print("\nSquare root is: ");
		print(res_str);
	}
}

void naturalLog()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	if(a <= 0)
		print("\nlog is only defined for strictly positive numbers");
	else
	{
		result = ln(a);
		float_to_string(result, res_str, PRECISION);
		print("\nNatural log is: ");
		print(res_str);
	}
}

void arctan()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	result = invtan(a);
	float_to_string(result, res_str, PRECISION);
	print("\nInverse tan is: ");
	print(res_str);
}

void arcsin()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	if(a > 1 || a < -1)
		print("\nInvalid input for arcsin. The input should be between -1 and 1");
	else
	{
		result = invsin(a);
		float_to_string(result, res_str, PRECISION);
		print("\nInverse sine is: ");
		print(res_str);
	}
}

void arccos()
{
	float a, result;
	char s1[20];
	char res_str[20];
	print("\nEnter the number: ");
	readString(s1);
	a = string_to_float(s1);
	if(a > 1 || a < -1)
		print("\nInvalid input for arccos. The input should be between -1 and 1");
	else
	{
		result = invcos(a);
		float_to_string(result, res_str, PRECISION);
		print("\nInverse cosine is: ");
		print(res_str);
	}
}

void powerFunction()
{
	float a, b, result;
	char s1[20];
	char s2[20];
	char res_str[20];
	print("\nEnter the base: ");
	readString(s1);
	a = string_to_float(s1);
	if(a < 0)
		print("\nNegative base is not allowed");
	else
	{
		print("\nEnter the power: ");
		readString(s2);
		b = string_to_float(s2);
		result = power(a, b);
		float_to_string(result, res_str, PRECISION);
		print("\nPower is: ");
		print(res_str);
	}
}
