#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//整币兑零递推求解
#include <stdio.h>
int main()
{
	int p, i, j, n, m, k;
	static int x[12];
	static long int a[12][1001];
	long b, s;
	printf("请输入整币值 (单位数) :>_ ");		//输出处理数据
	scanf("%d", &n);
	printf("请输入零币种数 :>_ ");
	scanf("%d", &m);
	printf("(从小到大依次输入每种零币值)\n");
	for (i = 1; i <= m; i++)
	{
		printf(" 第 %d 种零币值 (单位数) :>_ ", i);
		scanf("%d", &x[i]);
	}
	for (i = 0; i <= n; i++)		//确定初始条件
	{
		if (0 == i%x[1])
		{
			a[1][i] = 1;
		}
		else
		{
			a[1][i] = 0;
		}
	}
	for (s = a[1][n], j = 2; j <= m; j++)		//递推计算 a(2,n), a(3,n),... 
	{
		for (i = x[j]; i <= n; i++)
		{
			p = i - x[j];
			b = 0;
			for (k = 1; k <= j; k++)
			{
				b += a[k][p];
			}
			a[j][i] = b;
		}
		s += a[j][n];			//累加a(1,n), a(2,n),...
	}
	printf("整币兑零种数为 :>_ %ld\n", s);		//输出兑零种数
	return 0;
}
#endif

#if 0
// 12个同学拔河分组
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int j, k, m, a[7], b[13];
	long t, s1, s = 0;
	t = time(0) % 1000;
	srand(t);			//随机数发生器初始化
	printf("已知 12 个同学的体重分别为 :>_\n");
	for (s = 0, k = 1; k <= 12; k++)		//输入12个整数
	{
		scanf("%d", &b[k]);
		s += b[k];
		//s += b[k] = rand() % 25 + 35;
		//printf(" %d", b[k]);
	}
	if (0 == s % 2)
	{
		printf("\n 以上12个整数总和为 %d\n", s);
		s1 = s / 2;
	}
	else
	{
		printf("和为奇数，无法平分!\n");
	}
	a[1] = 1;
	m = 0;
	for (a[2] = 2; a[2] <= 8; a[2]++)
	{
		for (a[3] = a[2]+1; a[3] <= 9; a[3]++)
		{
			for (a[4] = a[3]+1; a[4] <= 10; a[4]++)
			{
				for (a[5] = a[4]+1; a[5] <= 11; a[5]++)
				{
					for (a[6] = a[5] + 1; a[6] <= 12; a[6]++)
					{
						for (s = 0, k = 1; k <= 6; k++)
						{
							s = s + b[a[k]];
						}
						if (s == s1)				//满足均分条件时输出
						{
							m++;
							printf(" NO%d :>_ ", m);
							for (j = 1; j <= 6; j++)
							{
								printf("%d ", b[a[j]]);
							}
							printf("\n");
						}
					}
				}
			}
		}
	}
	if (m > 0)
	{
		printf(" 共有以上 %d 种分法。\n", m);
	}
	else
	{
		printf(" 无法实现二堆均分。\n");
	}
	return 0;
}

#endif

#if 0
//2n 个同学拔河分组
#define N 50
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
	int n, m, a[N], c[N], b[2 * N], i, j, k, t;
	long s2, s3, s = 0;
	double d, s1, min = 1000;
	t = time(0) % 1000;
	srand(t);			//随机数发生器初始化
	printf("请输入 n :>_ ");
	scanf("%d", &n);
	printf("已知 %d 个同学的体重分别为 :>_\n", 2*n);
	for (s = 0, i = 1; i <= 2 * n; i++)		//产生 2n 个随机整数
	{
		s += b[i] = rand() % 25 + 30;		//s 为 2n 个整数的和
		printf(" %d", b[i]);
	}
	printf("\n 以上 %d 个整数总和为 %d\n", 2 * n, s);
	s1 = (double)s / 2;			// s1 为 s 的一半，可能非整数
	i = 1;
	a[1] = 1;
	m = 0;
	while (0 == s % 2)
	{
		if (i == n)
		{
			for (s2 = 0, j = 1; j <= n; j++)		//s2为探索过程中n个数据之和
			{
				s2 += b[a[j]];
			}
			if (s1 == (double)s2)		//满足均分条件时输出
			{
				m++;
				if (m <= 3)
				{
					printf(" NO%d :>_ ", m);
					for (j = 1; j <= n; j++)
					{
						printf("%d ", b[a[j]]);
					}
					printf("\n");
				}
			}
		}
		else
		{
			i++;
			a[i] = a[i - 1] + 1;
			continue;
		}
		while (a[i] == n + i)
		{
			i--;
		}
		if (i > 1)
		{
			a[i]++;
		}
		else
			break;
	}
	if (m > 0)
	{
		printf("\n 共有以上 %d 种分法。\n", m);
		return 0;
	}
	else
	{
		printf(" 无法实现二组重量均分!\n");

		i = 1;
		a[1] = 1;
		m = 0;
		while (1)
		{
			if (i == n)
			{
				for (s2 = 0, j = 1; j <= n; j++)
				{
					s2 += b[a[j]];
				}
				d = fabs((double)s2 - s1);
				if (d < min)		//d与min比较求取最小值
				{
					min = d;
					s3 = s2;
					for (k = 1; k <= n; k++)
					{
						c[k] = a[k];
					}
				}
			}
			else
			{
				i++;
				a[i] = a[i - 1] + 1;
				continue;
			}
			while (a[i] == n + i)		//调整或回溯
			{
				i--;
			}
			if (i > 1)
			{
				a[i]++;
			}
			else
			{
				break;
			}
		}
		printf(" 用以下分组可使得两组重量相差最小为 %.0f :>_\n", 2 * min);
		for (j = 1; j <= n; j++)
		{
			printf(" %d", b[c[j]]);
		}
		printf("\n 该组重量为 %ld; 余下为第2组，重量为 %ld。\n", s3, s - s3);
	}
	return 0;
}


while (!(a == i || b == i || c == i))
{
	if (!b)			//从A瓶倒满B杯
	{
		a -= bv;
		b = bv;
	}
	else if (c == cv)
	{
		a += cv;
		c = 0;		//从C杯倒回A瓶
	}
	else if (b > cv - c)
	{
		b -= (cv - c);
		c = cv;		//从B倒满C杯
	}
	else
	{
		c += b;
		b = 0;
	}
	printf("%5d%5d%5d\n", a, b, c);
}
#endif

#if 0
// 泊松分酒模拟操作
#include <stdio.h>
void practice(int, int, int);		//调用函数声明
int i, n, probo(int, int, int);

void practice(int a, int bv, int cv)	//模拟实施函数
{
	int b = 0, c = 0;
	printf("平分酒的分法 :>_ \n");
	printf("酒瓶%d 空杯%d 空杯%d\n", a, bv, cv);
	printf("%5d%5d%5d", a, b, c);
}

int main()
{
	int a, bv, cv, m1, m2;
	printf(" 请输入酒总量（偶数）:>_ ");
	scanf("%d", &a);
	printf(" 两空杯容量 bv,cv 分别为 :>_ ");
	scanf("%d%d", &bv, &cv);
	i = a / 2;
	if (bv + cv < i)
	{
		printf(" 空杯容量太小，无法平分!\n");
		return 0;
	}
	m1 = probo(a, bv, cv);
	m2 = probo(a, cv, bv);
	if (m1 < 0 && m2 < 0)
	{
		printf(" 无法平分!\n");
		return 0;
	}
	if (m1 > 0 && (m2 < 0 || m1 <= m2))
	{
		n = m1;
		practice(a, bv, cv);
	}
	else
	{
		practice(a, cv, bv);
	}
	return 0;
}


#endif