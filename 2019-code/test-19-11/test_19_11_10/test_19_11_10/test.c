#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <stdio.h>
void practice(int, int, int);    //调用函数声明
int i, n, probo(int, int, int);

void practice(int a, int bv, int cv) //模拟实施函数
{
	int b = 0, c = 0;
	printf("平分酒的分法 :>_ \n");
	printf("酒瓶%d 空杯%d 空杯%d\n", a, bv, cv);
	printf("%5d%5d%5d\n", a, b, c);
	while (!(a == i || b == i || c == i))
	{
		if (!(b))
		{
			a -= bv;
			b = bv;
		}
		else if (c == cv)
		{
			a += cv;
			c = 0;
		}
		else if (b > cv - c)
		{
			b -= (cv - c);
			c = cv;
		}
		else
		{
			c += b;
			b = 0;
		}
		printf("%5d%5d%5d\n", a, b, c);
	}
	printf(" 平分酒共分倒%d次。\n", n);
}

int probo(int a, int bv, int cv)		// 试验函数
{
	int n = 0, b = 0, c = 0;
	while (!(a == i || b == i || c == i))
	{
		if (!b)
		{
			if (a < bv)
			{
				n = -1;
				break;
			}
			else
			{
				a -= bv;
				b = bv;
			}
		}
		else if (c == cv)
		{
			a += cv;
			c = 0;
		}
		else if (b > cv - c)
		{
			b -= (cv - c);
			c = cv;
		}
		else
		{
			c += b;
			b = 0;
		}
		n++;
	}
	return n;
}

int main()
{
	int a, bv, cv, m1, m2;
	printf(" 请输入酒总量（偶数）:>_ ");
	scanf("%d", &a);
	printf(" 两空杯容量 bv,cv 分别为 :>_  ");
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
		n = m2;
		practice(a, cv, bv);
	}
	return 0;
}


#endif


#if 0
// 探求 4 位以内的相亲数对
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, m, s, t, s1;
	m = 0;
	for (i = 1; i <= 9999; i++)
	{
		s = 1;
		t = (int)sqrt(i);
		for (j = 2; j <= t; j++)
		{
			if (0 == i%j)
			{
				s = s + j + i / j;
			}
		}
		if (i == t*t)
		{
			s -= t;		// 求 i 的真因数之和 s
		}
		if (i < s)		// 规定 i<s,避免重复
		{
			s1 = 1;
			t = (int)sqrt(s);
			for (j = 2; j <= t; j++)
			{
				if (0 == s%j)
				{
					s1 = s1 + j + s / j;
				}
			}
			if (s == t*t)
			{
				s1 -= t;			// 求 s 的真因数之和 s1
			}
			if (s1 == i)			// 条件判别
			{
				m++;
				printf(" 相亲数对 %d :>_ %d,%d\n", m, i, s);
			}
		}
	}
	printf(" 4 位以内的相亲数对共以上 %d 组。\n", m);
	return 0;
}

#endif

#if 0
// 搜索 n 节相亲数环
#include <stdio.h>
#include <math.h>
int main()
{
	int c, k, n;
	long i, j, t, s[100];
	printf(" 搜索 n 节相亲数环，请输入 n :>_ ");
	scanf("%d", &n);
	i = 10;
	while (1)
	{
		i++;
		s[0] = i;
		s[n] = i + 1;		//初始化 s[0] != s[n]
		for (c = 0, k = 1; k <= n; k++)
		{
			s[k] = 1;
			t = (int)sqrt(s[k - 1]);
			for (j = 2; j <= t; j++)		// 求 s[k-1]的因数之和
			{
				if (0 == s[k - 1] % j)
				{
					s[k] = s[k] + j + s[k - 1] / j;
				}
			}
			if (s[k - 1] == t*t)
			{
				s[k] -= t;
			}
			for (j = 0; j <= k - 1; j++)
			{
				if (s[k] == s[j])
				{
					c = 1;
					break;
				}
			}
			if (1 == c)
			{
				break;
			}
		}
		if (s[0] == s[n])			//满足 n 环首尾相等，输出解
		{
			printf(" 搜索到 %d 节相亲数环 :>_ ", n);
			for (k = 0; k <= n - 1; k++)
			{
				printf(" %ld", s[k]);
			}
			printf("\n");
			return 0;
		}
		if (i > 1000000000)
		{
			printf(" 尚未搜索到 %d 节相亲数环！\n");
			return 0;
		}
	}
	return 0;
}
#endif

#if 0
// 双和 3 元 2 组探索
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, d, e, f, x, n;
	printf("请输入整数 n :>_ ");
	scanf("%d", &n);
	x = 0;
	for (a = 1; a <= (n - 3) / 3; a++)		// 设置枚举循环
	{
		for (b = a + 1; b <= (n - a - 1) / 2; b++)
		{
			for (d = a + 1; d <= (n - 3) / 3; d++)
			{
				for (e = d + 1; e <= (n - d - 1) / 2; e++)
				{
					c = n - a - b;
					f = n - d - e;		// 确保两组和等于 n
					if (a*b*c*(e*f + f*d + d*e) != d*e*f*(b*c + c*a + a*b))
					{
						continue;			//排除倒数和不相等
					}
					x++;					//统计并输出双和 3 元 2 组
					printf(" %d :>_ (%3d,%3d,%3d), ", x, a, b, c);
					printf(" (%3d,%3d,%3d); \n", d, e, f);
				}
			}
		}
	}
	if (x > 0)
		printf(" 共以上 %d 组解！\n", x);
	else
		printf(" 无解！\n");
	return 0;
}

#endif

#if 0
// 和积 3 元 3 组探索
#include <stdio.h>

int main()
{
	int a, b, c, d, e, f, g, h, i, j, x, n;
	long t;
	printf(" 请输入整数 n :>_ ");
	scanf("%d", &n);
	x = 0;
	for (a = 1; a <= (n - 3) / 3; a++)		// 设置枚举循环
	{
		for (b = a + 1; b <= (n - a - 1) / 2; b++)
		{
			for (d = a + 1; d <= (n - 3) / 3; d++)
			{
				for (e = d + 1; e <= (n - d - 1) / 2; e++)
				{
					for (g = d + 1; g <= (n - 3) / 3; g++)
					{
						for (h = g + 1; h < (n - g - 1) / 2; h++)
						{
							c = n - a - b;
							f = n - d - e;
							i = n - g - h;				// 确保3组和等于 n
							t = a*b*c;
							if (d*e*f == t && g * h* i == t)		//排除积不相等
							{
								x++;								//统计并输出解
								printf(" %d :>_ (%3d,%3d,%3d), ", x, a, b, c);
								printf(" (%3d,%3d,%3d); \n", d, e, f);
								printf(" %3d,%3d,%3d: (%ld)\n", g, h, i, t);
							}
						}
					}
				}
			}
		}
	}
	if (x > 0)
	{
		printf(" 共以上 %d 组解！\n", x);
	}
	else
	{
		printf(" 无解！\n");
	}
	return 0;
}

#endif

#if 0
// 和为 s 的等幂和 3 元组
#include <stdio.h>
#include <math.h>
int main()
{
	int n, s, s2, b[7];
	printf(" 请输入正整数 s :>_ ");
	scanf("%d", &s);
	n = 0;
	for (b[1] = 1; b[1] <= (s - 3) / 3; b[1]++)		//设置枚举循环
	{
		for (b[2] = b[1] + 1; b[2] <= (s - b[1] - 1) / 2; b[2]++)
		{
			for (b[4] = b[1] + 1; b[4] <= (s - 3) / 3; b[4]++)
			{
				for (b[5] = b[4] + 1; b[5] <= (s - b[4] - 1) / 2; b[5]++)
				{
					b[3] = s - b[1] - b[2];
					b[6] = s - b[4] - b[5];		// 确保和等于 s
					s2 = b[1] * b[1] + b[2] * b[2] + b[3] * b[3];
					if (b[4] * b[4] + b[5] * b[5] + b[6] * b[6] != s2)
					{
						continue;		// 排除平方和不相等
					}
					n++;
					printf("%3d :>_ (%2d,%2d,%2d) ", n, b[1], b[2], b[3]);
					printf("(%2d,%2d,%2d) s2 = %ld\n", b[4], b[5], b[6], s2);
				}
			}
		}
	}
	if (0 == n)
	{
		printf(" 无解！\n");
	}
	return 0;
}


#endif

#if 1
//探索等幂和 n (n<=6) 元组
#include <stdio.h>
int main()
{
	int a1, b1, b2, n, k, m1, m, i, j, t, x, z;
	int a[20], b[20], c[20], d[20], fa[20], fb[20];
	long s1, s2, tt1[20], tt2[20], s[20];
	printf(" 输出每组数的个数 n (2<n<7) :>_ ");
	scanf("%d", &n);
	return 0;
}

#endif