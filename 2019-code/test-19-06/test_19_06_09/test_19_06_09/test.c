
#define _CRT_SECURE_NO_WARNINGS 1

#if 0


#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
	}

	return 0;
}

#include <stdio.h>

int main()
{
	int n = 15;
	int i = 0;
	printf("打印奇数位：\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("打印偶数位：\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	return 0;
}




#include <stdio.h>

int count_one_bits(unsigned int value)
{
	int n = 0;
	int i = 0;
	for (i = 31; i >= 0; i--)
	{
		if (((value >> i) & 1) == 1)
		{
			n++;
		}
	}
	return n;
}

int main()
{
	int num = 15;
	int sum = count_one_bits(num);
	printf("%d", sum);
	return 0;
}



#include <stdio.h>

void print_num(int num)
{
	if (num > 9)
	{
		print_num(num / 10);
	}
	printf("%d", num % 10);
}

int main()
{
	int n = 123154;
	print_num(n);
	return 0;
}



#include <stdio.h>

void Diff_bit(int a, int b, int* n)
{
	int c = a ^ b;
	while (c != 0)
	{
		(*n)++;
		c = c & (c - 1);
	}
}

int main()
{
	int n = 2299;
	int m = 1999;
	int z = 0;
	Diff_bit(n, m, &z);
	printf("%d", z);
	return 0;
}


#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(a == 1) + (e == 4) == 1)
						{
							if (a*b*c*d*e == 120)
							{
								printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}




#include <stdio.h>
char is_one(int a, int b, int c, int d, int e)
{
	char 
	return n;
}


int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					for (e = 0; e <= 1; e++)
					{
						if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
						{
							if (a + b + c + d + e == 1)
							{
								printf("%c是杀人凶手\n", is_one(a, b, c, d, e));
							}
						}
					}
				}
			}
		}
	}
	return 0;
}




#include <stdio.h>

int main()
{
	char killer = 'a';
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a')+(killer == 'c')+(killer == 'd')+(killer != 'd') == 3)
		{
			printf("%c\n", killer);
		}
	}
	return 0;
}


#endif
