#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#if 0
int main()
{
	char arr1[] = "hello";
	char arr2[] = "hello";
	char *str1 = "hello";
	char *str2 = "hello";
	if (arr1 == arr2)
	{
		printf("arr1 == arr2\n");
	}
	if (str1 == str2)
	{
		printf("str1 == str2\n");
	}
	if (arr1 == str2)
	{
		printf("arr1 == str2\n");
	}

	return 0;
}

int main()
{
	char *str = "hello";
	*str = 'p';
	return 0;
}
#endif