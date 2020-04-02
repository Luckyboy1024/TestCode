#define _CRT_SECURE_NO_WARNINGS 1

#if 0

//
#include <stdio.h>
int main()
{
	return 0;
}
#endif


//
#include <stdio.h>
int main()
{
	return 0;
}

#if 0
//枚举求指定m位超级素数
#include <stdio.h>
#include <math.h>

int p(long k)					//设计素数检测函数
{
	int j, h, z = 0;
	if (2 == k)
	{
		z = 1;
	}
	if (k >= 3 && k % 2 == 1)
	{
		for (h = 0, j = 3; j <= sqrt(k); j += 2)
		{
			if (k%j == 0)
			{
				h = 1;
				break;
			}
		}
		if (h == 0)		//k为素数返回1，否则返回0
		{
			z = 1;
		}

	}
	return z;
}

int main()
{
	int i, m;
	long c, d, e, f, k, s, t;
	int p(long f);
	printf("请确定 m (m>1) :>_ ");
	scanf("%d", &m);
	for (c = 1, i = 1; i <= m - 1; i++)		//确定最小的m位数c
	{
		c = c * 10;
	}
	s = 0;
	for (f = c + 1; f <= 10 * c - 1; f = f + 2) //设置枚举循环，f为m位奇数
	{
		if (!(f % 10 == 3 || f % 10 == 7) || p(f) == 0)
			continue;
		for (t = 1, d = f / 10, i = 1; i <= m - 2; i++)
		{
			if (d % 10 == 0)			//如果包含0数字，标记 t=0
			{
				t = 0;
				break;
			}
			d = d / 10;
		}
		if (0 == t)
			continue;
		for (k = 10, i = 1; i <= m - 2; i++)	//枚举m-2次去位操作
		{
			k = k * 10;
			if (p(f%k) == 0)			//若其中任一数不是素数则退出循环
				break;
		}
		if (i > m - 2)			//统计并赋值
		{
			s++;
			e = f;
		}
	}
	printf("共%ld个%d位超级素数\n", s, m);
	printf("其中最大数为%ld\n", e);
	return 0;
}



//探索n位对称素数改进
#include <stdio.h>
#include <math.h >
int main()
{
	int g, i, j, k, n, p[7], q[7];
	long s;
	double e, f, m, max;
	printf("请输入奇数n (n1≤11) :>_ ");
	scanf("%d", &n);
	k = (n + 1) / 2;
	for (i = 1; i <= k; i++)
	{
		q[i] = 9;
	}
	for (i = k + 1; i <= 6; i++)
	{
		q[i] = 0;
	}
	s = 0;
	max = 0;
	for (p[6] = 0; p[6] <= q[6]; p[6]++)
	{
		for (p[5] = 0; p[5] <= q[5]; p[5]++)
		{
			for (p[4] = 0; p[4] <= q[4]; p[4]++)
			{
				for (p[3] = 0; p[3] <= q[3]; p[3]++)
				{
					for (p[2] = 0; p[2] <= q[2]; p[2]++)
					{
						for (p[1] = 0; p[1] <= q[1]; p[1]+=2)
						{
							if (5 == p[1])
								continue;		//个位数字限定不为5的奇数
							e = 0;
							m = 0;
							f = 10;
							for (j = 1; j <= k - 1; j++)
							{
								e = e * 10 + p[j];
								f = f * 10;
								m = m * 10 + p[k + 1 - j];
							}
							m = m * 10 + p[1];
							e = e*f + m;		//e为n位对称奇数
							for (g = 0, i = 3; i <= sqrt(e); i = i + 2)
							{
								if (0 == fmod(e, i))
								{
									g = 1;
									break;
								}
							}
							if (0 == g)		//g=0 时 e 为对称素数, s 统计
							{
								s++;
								if (max < e)
									max = e;	//比较最大对称素数
							}
						}
					}
				}
			}
		}
	}
	printf("\n%d位对称素数共有%ld个\n", n, s);
	if (s>0)
	{
		printf("其中最大的对称素数为: %.0f\n", max);
	}
	return 0;
}

//搜索 n 位对称素数
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, g, i, j, n, s, h[10];
	long m, max, d, t;
	printf("请输入位数 n (n>1) :>_ ");
	scanf("%d", &n);
	s = 0;
	t = 1;
	a = n / 2;
	for (j = 1; j <= n - 1; j++)
	{
		t = t * 10;		//计算最小的 n 位整数 t
	}
	for (m = t + 1; m <= (10 * t - 1); m = m + 2)	//枚举所有的n位奇数
	{
		if (0 == m % 5)
			continue;
		d = m;
		b = 0;
		for (j = 0; j <= 9; j++)
		{
			h[j] = 0;
		}
		for (j = 1; j <= n; j++)
		{
			c = d % 10;
			h[j] = c;
			d = d / 10;
		}
		for (j = 1; j <= a; j++)
		{
			if (h[j] != h[n - j + 1])
			{
				b = 1;
				break;
			}
		}
		if (0 == b)		//b=0 时，m为对称数
		{
			for (g = 0, i = 2; i <= sqrt(m); i++)
			{
				if (0 == m%i)
				{
					g = 1;
					break;
				}
			}
			if (0 == g)	// g=0时 m为对称素数，s统计
			{
				s++;
				max = m;
			}
		}
	}
	printf("%d位对称素数共有%d个\n", n, s);
	if (s > 0)
	{
		printf("其中最大的对称素数为：%ld\n", max);
	}
	return 0;
}

//求梅森尼数：2^n-1 形的素数
#include <stdio.h>
#include <math.h>
int main()
{
	double t, m;
	int j, x, s, n;
	s = 0; 
	t = 2;
	for (n = 2; n <= 50; n++)
	{
		t = t * 2;
		m = t - 1;
		x = 0;							//累乘量t为2^n
		for (j = 3; j < sqrt(m) + 1; j += 2)	//试商法判别m是否为素数
		{
			if (0 == fmod(m, j))
			{
				x = 1;
				break;
			}
		}
		if (0 == x)			//输出所求得的素数
		{
			s = s + 1;
			printf("2^%d - 1 = %.0f\n", n, m);
		}
	}
	printf("指数n于[2,50]中梅森尼数共有%d个\n", s);
	return 0;
}

//筛法求指定区间上的素数
#include <stdio.h>
int main()
{
	long int c, d, e, g, i, j, k, n;
	static long int a[80000];
	printf("求区间 [c,d] 上的素数\n");
	printf("请输入 c,d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;
	}
	e = (d - c) / 2;
	i = 1;
	while (i <= sqrt(d))	//在 [c,d] 中筛选素数
	{
		i = i + 2;
		g = 2 * (c / (2 * i)) + 1;
		if (g*i > d)
			continue;
		if (1 == g)
			g = 3;
		j = i*g;
		while (j <= d)
		{
			if (j >= c)
			{
				a[(j - c) / 2] = -1;		//筛去标记-1
			}
			j = j + 2 * i;
		}
	}
	for (n = 0, k = 0; k <= e; k++)
	{
		if (a[k] != -1)			//输出所得素数
		{
			n++;
			printf("%d ", c + 2 * k);
			if (0 == n % 5)
			{
				printf("\n");
			}
		}
	}
	printf("\n共%ld个素数\n", n);
	return 0;
}

//试商法求指定区间上的素数
#include <stdio.h>
#include <math.h>

int main()
{
	long c, d, i, j, n, t;
	printf("求区间 [c,d] 上的素数\n");
	printf("请输入 c,d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c = c + 1;
	}
	n = 0;
	for (i = c; i <= d; i += 2)
	{
		for (t = 0, j = 3; j < sqrt(i); j += 2)
		{
			if (i%j == 0)		//实施试商
			{
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			printf("%ld ", i);
			n++;				//统计素数的个数
			if (0 == n % 10)
			{
				printf("\n");
			}
		}
	}
	printf("\n共%ld个素数\n", n);
	return 0;
}
#endif
