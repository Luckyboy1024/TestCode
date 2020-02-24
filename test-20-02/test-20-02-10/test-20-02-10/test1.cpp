#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a[2][3] = { 1, 2, 4, 5, 3, 6 };
	printf("%d\n", *(a[0] + 1));
	printf("%d\n", *(*a + 0) + 1);
	printf("%d\n", (*(a + 0))[1]);
	return 0;
}

#if 0
int func(int a)
{
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	}
	return b;
}
int main()
{
	int n = -1;
	n = func(1);
	return 0;
}

#define N 2
#define M N+1
#define NUM (M+1)*M/2
int main()
{
	printf("%d\n", NUM);
	return 0;
}

#endif