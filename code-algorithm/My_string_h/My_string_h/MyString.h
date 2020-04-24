
#ifndef __STRING_H__
#define __STRING_H__

#include "head.h"

unsigned int MyStrlen(const char *str);
char *MyStrcpy(char* dest, const char* src);
char *MyStrcat(char* dest, const char* src);
int MyStrcmp(const char *str1, const char *str2);
char *MyStrncpy(char* dest, const char* src, int n);
char *MyStrncat(char* dest, const char* src, int n);
int MyStrncmp(const char *str1, const char *str2, int n);


const char *MyStrstr(const char* str1, const char* str2);

void *MyMemcpy(void *dest, const void *src, int count);
void *MyMemmove(void *dest, const void *src, int count);


#endif //__STRING_H__