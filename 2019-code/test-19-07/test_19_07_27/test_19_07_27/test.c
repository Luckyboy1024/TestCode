#define _CRT_SECURE_NO_WARNINGS 1


#include <math.h>
#include <stdio.h>

int main()
{
	int day = 0;
	return day;
}


#if 0
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

//筛法求指定区间上的素数

int main()
{
	long int c, d, e, g, i, j, k, n;
	static long int a[80000];
	printf("求区间 [c, d] 上的素数:\n");
	printf("请输入 c, d (c>2):");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;
	}
	e = (d - c) / 2;
	i = 1;
	while (i <= sqrt(d))
	{
		i += 2;
		g = 2*(c/(2*i))+1;
		if (g*i > d)
			continue;
		if (1 == g)
		{
			g = 3;
		}
		j = i*g;
		while (j <= d)
		{
			if (j >= c)
			{
				a[(j - c) / 2] = -1;
			}
			j = 2 * i + j;
		}
	}
	for (n = 0, k = 0; k <= e; k++)
	{
		if (a[k] != -1)
		{
			n++;
			printf("%ld ", c + 2 * k);
			if (0 == n % 12)
			{
				printf("\n");
			}
		}
	}
	printf("\n共 %ld 个素数\n", n);
	return 0;
}

int main()
{
	long c, d, i, j, n, t;
	printf("   求区间 [c, d] 上的素数：\n");
	printf("   请输入 c, d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;
	}
	n = 0;
	for (i = c; i <= d; i+=2)
	{
		for (t = 0, j = 3; j <= sqrt(i); j += 2)
		{
			if (0 == i % j)
			{
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			printf("   %ld", i);
			n++;
			if (0 == n % 10)
			{
				printf("\n");
			}
		}
	}
	printf("\n   共 %ld 个素数", n);
	return 0;
}
int main()
{
	int count = 0;
	for (int i = 101; i <= 200; i+=2)
	{
		int j = 0;
		//条件语句中的等号去掉，对逻辑结构有何影响
		for (j = 2; j <= sqrt(i); j++)
		{
			if (0 == i % j)
				break;
		}
		if (j > sqrt(i))			//注意这里为什么不是 >=
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
int main()
{
	int count = 0;
	for (int i = 100; i <= 200; i++)
	{
		int j = 0;
		//条件语句中的等号去掉，对逻辑结构有何影响
		for (j = 2; j <= sqrt(i); j++)
		{
			if (0 == i % j)
				break;
		}
		if (j > sqrt(i))			//注意这里为什么不是 >=
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
int main()
{
	int count = 0;
	for (int i = 100; i <= 200; i++)
	{
		int j = 0;
		//条件语句中的等号去掉，对逻辑结构有何影响
		for (j = 2; j <= i / 2; j++)
		{
			if (0 == i % j)
				break;
		}
		if (j > i / 2)			//注意这里为什么不是 >=
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		//printf("%d", i);
		//判断 i 是否为素数
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (0 == i % j)
				break;
		}
		if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}

#endif