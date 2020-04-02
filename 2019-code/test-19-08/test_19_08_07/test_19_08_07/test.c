#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int fun(int x)
{
	int n = 0;
	while (x)
	{
		n++;
		x = x & (x - 1);
	}
	return n;
}

int main()
{
	printf("%lu", fun(2019));
	return 0;
}

#if 0

int main()
{
	long n = 0;
	printf("%d", sizeof(n));
	return 0;
}

int main()
{
	char n = 0;
	printf("%d", sizeof(n));
	return 0;
}

#endif