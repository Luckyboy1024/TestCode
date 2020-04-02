#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



#if 0

int main()
{
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%d, %u\n",!c, sizeof(-!c));
	return 0;
}

int main()
{
	int j = 0;
	int i = 0;
	int tmp = 0;
	int a[3] = { 0 };
	printf("enter:>_");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3 - j - 1; i++)
		if (a[i] > a[i + 1])
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
	}
	for (i = 0; i < 3; i++)
		printf("%d ", a[i]);
	return 0;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	return 0;
}
#endif