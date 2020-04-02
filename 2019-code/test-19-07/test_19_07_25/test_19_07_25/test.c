#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define INTPRE int *

int main()
{
	INTPRE p1, p2;
	return 0
}





#if 0

int main()
{
	int a = 10;
	int b = 20;
	const int* p1 = &a;
	int const *p2 = &a;
//	int* const p3 = &a;
	p2 = &b;
	*p2 = 99;
	return 0;
}
int main()
{
	int a = 10;
	int b = 20;
	int* p = &a;
	p = &b;
	*p = 99;
	return 0;
}


#endif