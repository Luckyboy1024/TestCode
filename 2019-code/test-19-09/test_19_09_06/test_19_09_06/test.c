#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);
	printf("&arr= %p\n", &arr);
	printf("arr+1 = %p\n", arr + 1);
	printf("&arr+1= %p\n", &arr + 1);
	return 0;
}

#if 0

#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr);
	return 0;
}

#endif