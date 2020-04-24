#define _CRT_SECURE_NO_WARNINGS 1

#include "MyString.h"

//模拟实现 strlen() 函数
unsigned int MyStrlen(const char *str)
{
	assert(str != NULL);
	unsigned int count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

//模拟实现 strcpy() 函数
char *MyStrcpy(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char *p = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return p;
}

//char *MyStrcpy(char* dest, const char* src)
//{
//	assert(dest != NULL && src != NULL);
//	char *p = dest;
//	while (*dest++ = *src++);
//	return p;
//}

//模拟实现 strcat 函数
char *MyStrcat(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);
	char *p = dest;
	while (*dest != '\0')
	{
		++dest;
	}
	while (*dest++ = *src++);
	return p;
}


//模拟实现 strcmp 函数
int MyStrcmp(const char *str1, const char *str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		++str1;
		++str2;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}

//模拟实现 strncpy 函数
char *MyStrncpy(char *dest, const char *src, int n)
{
	assert(dest && src);
	char *p = dest;
	while (n--)
	{
		*dest = *src;
		++dest;
		++src;
	}
	return p;
}

//模拟实现 strncat 函数
char *MyStrncat(char* dest, const char* src, int n)
{
	char *p = dest;
	int count = 0;
	assert(dest && src);
	while ('\0' != *dest)
	{
		++dest;
	}
	while (count < n)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return p;
}

//模拟实现 strncmp 函数
int MyStrncmp(const char *str1, const char *str2, int n)
{
	int diff = 0;
	int count = 0;
	assert(str1 && str2);
	while (count < n && (diff = *str1 - *str2) == 0 && *str1 != '\0')
	{
		++str1;
		++str2;
		++count;
	}
	return diff;
}

//暴力算法实现 strstr 函数
const char *MyStrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char *s1 = str1;
	const char *s2 = str2;
	const char *start = s1;
	while (*s1 != '\0')
	{
		s1 = start;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			++s1;
			++s2;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		if (*s2 == '\0')
		{
			return start;
		}
		start++;
	}
}

//模拟实现 memcpy 函数
void *MyMemcpy(void *dest, const void *src, int count)
{
	assert(dest && src);
	char *p = (char*)dest;
	while (count--)
	{
		*p = *(char*)src;		//类型强转，char大小一个字节
		p++;
		((char*)src)++;
	}
	return dest;
}

//模拟实现 memmove 函数
void *MyMemmove(void *dest, const void *src, int count)
{
	assert(dest && src);
	void *ret = dest;
	if (dest < src)
	{
		while (count--){
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (count--){
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
