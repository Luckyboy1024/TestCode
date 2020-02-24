#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



void test1()
{
	int a;
	a = 'A' + 1.6;
}

void test2()
{
	float a[3] = { 0 };
	printf("%p,%p,%p\n", &a[0], &a[1], &a[2]);
}

//int main()
//{
//	test();
//	return 0;
//}

#if 0
int main()
{
	int x = 10;
	int y = 10;
	int k = 3;
	int z = 3;
	k *= x + y;
	z  = z * x + y;
	return 0;
}
#endif