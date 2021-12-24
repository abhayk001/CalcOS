#ifndef UTIL_H
#define UTIL_H

#include "types.h"
#include "screen.h"
#include "string.h"

void memory_copy(char* source, char* dest, int nbytes);
void memory_set(uint8* dest, uint8 val, uint32 len);
void int_to_ascii(int32 n, char str[]);
void int_to_string(int32 n, string s);
int32 string_to_int(string s);
float string_to_float(string s);
void float_to_string(float n, string s, uint16 precision);

#endif
