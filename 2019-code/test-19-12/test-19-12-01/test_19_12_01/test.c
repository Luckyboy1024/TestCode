#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//二次三项式 ax^2 + bxy + cy^2 (a>0) 分解因式
#include <stdio.h>
#include <math.h>
int main()
{
	long a, b, c, e, p, u, v, fa[100], fc[100];
	int i, j, k, t;
	char g, h;
	printf("请输入整数 a,b,c (a>0) :>_ ");
	scanf("%ld%ld%ld", &a, &b, &c);
	g = h = '+';
	p = 1;
	if (b < 0)
		g = '-';
	if (c < 0)
		h = '-';
	printf("%ldx^2 %c %ldxy %c %ldy^2 ", a, g, abs(b), h, abs(c));
	v = abs(b);
	if (a < v)
		v = a;
	if (abs(c) < v)		//求 a, |b|, |c| 的最小值 v
		v = abs(c);
	for (u = v; u >= 2; u--)
	{
		if (0 == a%u && 0 == b%u && 0 == c%u)
		{
			a = a / u;
			b = b / u;
			c = c / u;
			p = u;				//判别并提取 a、b、c 的公因数u
		}
	}
	k = u = 0;
	e = (long)sqrt(a);
	while (u <= e)
	{
		u++;
		if (0 == a%u)
		{
			fa[++k] = u;
			fa[++k] = a / u;
		}
	}		//分解 k个a的因数
	if (a == e*e)
	{
		k--;
	}
	j = u = 0;
	e = (long)sqrt(abs(c));
	while (u <= e)
	{
		u++;
		if (0 == abs(c) % u)
		{
			fc[++j] = u;
			fc[++j] = abs(c) / u;
		}
	}		//分解j个c的因数
	if (abs(c) == e*e)
	{
		j--;
	}
	if (c > 0)
	{
		for (i = 1; i <= k; i++)
		{
			for (t = 1; t <= j; t++)
			{
				if (fa[i] * (c / fc[t]) + (a / fa[i])*fc[t] == abs(b))
				{
					printf("= ");			//输出分解的两个一次式
					if (p > 1)
						printf("%ld ", p);
					printf("(%ld %c %ldy)", fa[i], g, fc[t]);
					if (fa[i] * fa[i] == a && fc[t] * fc[t] == c)
						printf("^2\n");
					else
						printf("(%ld %c %ldy)\n", a / fa[i], g, c / fc[t]);
					return;
				}
			}
		}
	}
	if (c < 0)
	{
		for (i = 1; i <= k; i++)
		{
			for (t = 1; t <= j; t++)
			{
				if (fa[i] * (c / fc[t]) + (a / fa[i])*fc[t] == b)
				{
					printf("= ");			//输出分解的两个一次式
					if (p > 1)
						printf("%ld ", p);
					printf("(%ld + %ldy)", fa[i], fc[t]);
					printf("(%ld - %ldy)\n", a / fa[i], -c / fc[t]);
					return;
				}
			}
		}
	}
	printf("在整数范围内不能分解因式\n");
	return 0;
}

#endif


#if 0
// 积最大的整数分解
#include <stdio.h>
#include <math.h>
int main()
{
	int a, c, d, h, k, n, s;
	double t;
	printf("把 n 分解为若干个互不相同的正整数之和，使其积最大。\n");
	printf("请输入正整数 n (n>3) :>_");
	scanf("%d", &n);
	s = 0;
	h = 1;
	a = 1;
	while (s <= n)		//求和 s = 2+3+...+a 至s>n为止
	{
		a++;
		s = s + a;
	}
	if (s - n == a)		//n分解为2至a-1的连续序列
	{
		c = 2;
		d = a - 1;
	}
	else if (s - n == 2)	//n分解为3至a的连续序列
	{
		c = 3;
		d = a;
	}
	else if (s - n == 1)	//n分解为3至a+1(不含a)的连续序列
	{
		c = 3;
		d = a + 1;
		h = a;
	}
	else					//n分解为2至a(不含s-n)的连续序列
	{
		c = 2;
		d = a;
		h = s - n;
	}
	printf("	%d 分解为 :>_ %d -- %d", n, c, d);
	if (h > 0)
		printf("(不包括其中的数 %d)。\n", h);
	printf("其积最大为 :>_ ");
	t = 1;
	for (k = c; k <= d; k++)
	{
		t = t*k;				//从c至d求积
	}
	t = t / h;					//从积中除去空数 h
	printf("%.3e\n", t);
	return 0;
}


#endif

#if 0
//  基本求和设计
#include <stdio.h>

int main()
{
	long c, i, j, n, s;
	printf("请输入拆分数 n :>_ ");
	scanf("%ld", &n);
	c = 0;
	for (i = 1; i <= (n - 1) / 2; i++)		//设置循环 i 枚举求和起始项
	{
		s = 0;			
		for (j = 1; j <= (n + 1) / 2; j++)	//设置循环 j 枚举求和累加项
		{
			s = s + j;
			if (s >= n)
			{
				if (s == n)
				{
					c++;
					printf(" %d: %d+...+%d\n", c, i, j);		//统计并输出一个解
				}
				break;
			}
		}
	}
	printf("共有以上 %d 个解。\n", c);
	return 0;
}

#endif

#if 0
// 应用求和公式优化设计
#include <stdio.h>
#include <math.h>

int main()
{
	long c, k, m, n, t;
	printf(" 请输入拆分数 n :>_ ");
	scanf("%ld", &n);
	t = (long)sqrt(2 * n);
	c = 0;
	for (k = 2; k <= t; k++)
	{
		if ((2 * n) % k > 0 || (2 * n / k + 1 - k) % 2 > 0)
		{
			continue;		//检测 m 是否存在
		}
		m = (2 * n / k + 1 - k) / 2;
		c++;					//统计并输出一个解
		if (2 == k)
		{
			printf(" %d: %d+%d\n", c, m, m + 1);
		}
		else
		{
			printf(" %d: %d+...+%d\n", c, m, m + k - 1);
		}
	}
	printf("  共有以上 %d 个解。\n", c);			//输出解的个数c
	return 0;
}

#endif

#if 0

//把和数分解为若干个指定零数的和
#include <stdio.h>
#define MAXN 100
int a[MAXN], b[1000];
int t, n = 0;

void comb(int m, int k, int s)		//建立递归函数 comb(m,k,s)
{
	int i, j;
	for (i = m; i >= k; i--)
	{
		a[k] = i;
		if (k > 1)
		{
			comb(i - 1, k - 1, s);
		}
		else
		{
			for (t = 0, j = a[0]; j > 0; j--)
			{
				t = t + b[a[j]];
			}
			if (t == s)
			{
				n++;
				printf("%d=", s);		//满足条件时输出
				for (j = a[0]; j > 1; j--)
				{
					printf("%2d+", b[a[j]]);
				}
				printf("%2d\n", b[a[1]]);
			}
		}
	}
}

int main()
{
	int m, ss, i, h, k, wmin, wmax;
	printf("输入零数的个数: ");
	scanf("%d", &m);
	printf("依次由小到大输入零数 :>_ \n");
	for (i = 1; i <= m; i++)
	{
		printf(" b[%d]=", i);
		scanf("%d", &b[i]);
	}
	printf("输入和数为 :>_ ");
	scanf("%d", &ss);
	for (h = 0, i = 1; i <= m; i++)
	{
		h = h + b[i];
		if (h > ss)
		{
			wmax = i - 1;
			break;
		}
	}
	if (i > m)		//输入的零数组太小，程序返回
	{
		printf("输入的最大零数太小\n");
		return;
	}
	for (h = 0, i = 1; i <= m; i++)
	{
		h = h + b[m - i + 1];
		if (h > ss)
		{
			wmin = i - 1;
			break;
		}
	}
	for (k = wmin; k <= wmax; k++)
	{
		a[0] = k;
		comb(m, k, ss);
	}
	printf("共以上 %d 个拆分式\n", n);
	return 0;
}
#endif

#if 0
//整币兑零枚举设计
#include <stdio.h>

int main()
{
	int p1, p2, p3, p4, p5, p6, n;
	long m = 0;
	printf("请输入整币量 n :>_ ");
	scanf("%d", &n);
	printf("   1分 2分 5分 1角 2角 5角\n");
	for (p1 = 0;p1<=n;p1++)
	{
		for (p2 = 0;p2<=n/2;p2++)
		{
			for (p3 = 0;p3<=n/5;p3++)
			{
				for (p4 = 0;p4<=n/10;p4++)
				{
					for (p5 = 0;p5<=n/20;p5++)
					{
						for (p6 = 0;p6<=n/50;p6++)
						{
							if (n == p1 + 2 * p2 + 5 * p3 + 10 * p4 + 20 * p5 + 50 * p6)	//根据条件检验
							{
								m++;
								printf(" %4d%4d%4d", p1, p2, p3);
								printf("%4d%4d%4d\n", p4, p5, p6);
							}
						}
					}
				}
			}
		}
	}
	printf("   %d(1,2,5,10,20,50) = %ld\n", n, m);
	return 0;
}
#endif

#if 0
//精简循环设计
#include <stdio.h>
int main()
{
	int p1, p2, p3, p4, p5, p6, n;
	long m = 0;
	printf("请输入整币量 n :>_ ");
	scanf("%d", &n);
	for (p2 = 0; p2 <= n / 2; p2++)		//已省略了 p1 循环
	{
		for (p3 = 0; p3 <= n / 5; p3++)
		{
			for (p4 = 0; p4 <= n / 10; p4++)
			{
				for (p5 = 0; p5 <= n / 20; p5++)
				{
					for (p6 = 0; p6 <= n / 50; p6++)
					{
						p1 = n - (2 * p2 + 5 * p3 + 10 * p4 + 20 * p5 + 50 * p6);	//p1为一分币的个数
						if (p1 >= 0)
						{
							m++;			//用 m 统计兑换种数
						}
					}
				}
			}
		}
	}
	printf("   %d(1,2,5,10,20,50) = %ld\n", n, m);
	return 0;
}
#endif

#if 0
//进一步优化枚举设计
#include <stdio.h>
int main()
{
	int p1, p2, p3, p4, p5, p6, n;
	long m = 0;
	printf("请输入整币量 n :>_ ");
	scanf("%d", &n);
	for (p2 = 0; p2 <= n / 2; p2++)		//已省略了 p1 循环
	{
		for (p3 = 0; p3 <= (n - (2 * p2)) / 5; p3++)
		{
			for (p4 = 0; p4 <= (n - (2 * p2 + 5 * p3)) / 10; p4++)
			{
				for (p5 = 0; p5 <= (n - (2 * p2 + 5 * p3+10*p4)) / 20; p5++)
				{
					for (p6 = 0; p6 <= (n - (2 * p2 + 5 * p3 + 10 * p4+20*p5)) / 50; p6++)
					{
						p1 = n - (2 * p2 + 5 * p3 + 10 * p4 + 20 * p5 + 50 * p6);	//p1为一分币的个数
						if (p1 >= 0)
						{
							m++;			//用 m 统计兑换种数
						}
					}
				}
			}
		}
	}
	printf("   %d(1,2,5,10,20,50) = %ld\n", n, m);
	return 0;
}

#endif
