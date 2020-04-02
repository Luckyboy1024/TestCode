#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>



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

int main()
{
	char* str1 = "hello";
	char* str2 = "boy";
	MyStrcat(str1, str2);
	return 0;
}
#if 0
int main()
{
	char *src = "boy";
	strcat(src, src);
	printf("%s\n", src);
 	return 0;
}

int main()
{
	char dest[10] = { 0 };
	char *src = "hello";
	int len = strlen(strcpy(dest, src));
	printf("%s\n", strcpy(dest, src));
	printf("%d\n", len);
	return 0;
}
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



#endif