#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//试商设计求指定区间内最多有多少个连续合数
#include <stdio.h>
#include <math.h>
int main()
{
	long c, d, i, j, f, t, f1, i1, max;
	printf("请输入 c,d (2<c<d) :>_ ");
	scanf("%ld%ld", &c, &d);
	f = c;
	max = 0;
	if (0 != c % 2)
	{
		for (t = 0, j = 3; j <= sqrt(c); j += 2)		//试商判别下限c是否为素数
		{
			if (0 == c%j)
			{
				t = 1;
				break;
			}
		}
	}
	if (0 == c % 2 || 1 == t)
		f = c - 1;				//令c-1为素数并赋值给f
	if (0 == c % 2)
		c++;
	for (i = c; i <= d; i += 2)
	{
		t = 0;
		for (j = 3; j <= sqrt(i); j += 2)		//试商判别素数
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (d - i < 2 && t == 1)
		{
			t = 0;
			i = d + 1;			//令d+1为素数并赋值给 i
		}
		if (0 == t)
		{
			if (i - f >max)
			{
				max = i - f;
				f1 = f + 1;
				i1 = i - 1;
			}
			f = i;			//f 为 i 的前一个素数
		}
	}
	printf("最多连续合数的个数为 :>_ %ld\n", max - 1);
	printf("连续合数区间为 :>_ [%ld,%ld]\n", f1, i1);
	return 0;
}

#endif


#if 0
//筛法求指定区间内最多有多少个连续合数
#include <stdio.h>
#include <math.h>

int main()
{
	long c, d, cs, ds,ct, dt, f, g, i, j, k, m, max, a[11000];
	int e, u, x, y;
	printf("请输入 c,d (2<c<d) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (d - c <= 20000)
	{
		cs = c;
		ds = d;
		x = 0;
	}
	else
	{
		x = (d - c) / 20000;
		cs = c;
		ds = d - 20000 * x;
	}
	f = cs;
	max = 0;
	for (y = 1; y <= x + 1; y++)		//把 [c,d] 分x+1个子区间筛选素数
	{
		if (0 == cs % 2)
			cs++;
		for (i = 0; i <= 10999; i++)
			a[i] = 0;
		e = (ds - cs) / 2;
		i = 1;
		while (i <= sqrt(ds))
		{
			i = i + 2;
			g = 2 * sqrt(cs / (2 * i)) + 1;
			if (g * i > ds)
				continue;
			if (1 == g)
				g = 3;
			j = i *g;
			while (j <= ds)
			{
				if (j >= cs)
					a[(j - cs) / 2] = -1;		//赋值筛去标记-1
				j = j + 2 * i;
			}
		}
		for (u = 1, k = 0; k <= e; k++)
		{
			if (a[k] != -1)
			{
				m = cs + 2 * k;		//m即筛选所得素数
				if (m - f > max)		//寻求两相邻素数间距的最大值
				{
					max = m - f;
					ct = f + 1;
					dt = cs + 2 * k - 1;
				}
				f = m;
			}
		}
		cs = ds + 1;
		ds = ds + 20000;		//cs与ds增长后继续探求
	}
	printf("最多连续合数的个数为 :>_ %ld\n", max - 1);
	printf("连续合数区间为 :>_ [%ld,%ld]\n", ct, dt);
	return 0;
}

#endif


#if 0
//求最小的连续 n 个合数
#include <stdio.h>
#include <math.h>

int main()
{
	long c, d, f, m, j;
	int t, n;
	printf("求最小的 n 个连续合数。\n");
	printf("请输入 n (n<200) :>_ ");
	scanf("%d", &n);
	c = 3;
	d = c + 10000;
	f = 3;
	while (1)
	{
		for (m = c; m <= d; m += 2)
		{
			for (t = 0, j = 3; j <= sqrt(m); j += 2)
			{
				if (0 == m % j)		//实施试商
				{
					t = 1;
					break;
				}
			}
			if (t == 0 && m - f > n)		//满足条件进行输出
			{
				printf("最小的 %d 个连续合数区间为 :>_ ", n);
				printf("[%ld,%ld]。\n", f + 1, f + n);
				return;
			}
			if (0 == t)
				f = m;				//每求出一个素数 m 后赋值给 f
		}
		if (m > d)
		{
			c = d + 2;
			d = c + 10000;			//每一轮试商后改变c和d转下一轮
		}
	}
	return 0;
}

#endif

#if 0
//探求第 n 个合数世纪
#include <stdio.h>
#include <math.h>
int main()
{
	long a, b, k;
	int m, n, s, x;
	printf("探求第 n 个合数世纪，请输入 n :>_ ");
	scanf("%d", &n);
	a = 1;
	m = 0;
	while (1)
	{
		a++;
		s = 0;			//检验 a 世纪
		for (b = a * 100 - 99; b <= a * 100 - 1; b += 2)	//枚举a世纪奇数年号b
		{
			x = 0;
			for (k = 3; k <= sqrt(b); k += 2)
			{
				if (0 == b%k)
				{
					x = 1;
					break;
				}
			}
			if (0 == x) break;	//跳出循环进行下世纪的探求
			s = s + x;			//年号b为合数时，x=1,s增1
		}
		if (50 == s) m++;
		if (n == m) break;
	}
	printf("第 %d 个合数世纪为 %ld 世纪！\n", n, a);
	printf("该世纪的年号 %ld -- %ld 全为合数\n", a * 100 - 99, a * 100);
	return 0;
}

#endif

#if 0
//质因数分解乘积形式
#include <stdio.h>
#include <math.h>
int main()
{
	long int b, i, k, m, n;
	printf("请输入 m,n :>_ ");
	scanf("%ld%ld", &m, &n);
	for (i = m; i <= n; i++)		// i 为待分解的整数
	{
		printf("  %ld = ", i);
		b = i;
		k = 2;					//k为试商因数
		while (k <= sqrt(i))
		{
			if (0 == b%k)
			{
				b = b / k;
				if (b > 1)
				{
					printf("%ld * ", k);
					continue;		//k为质因数，返回再试
				}
				if (1 == b)
				{
					printf("ld\n", k);
				}
			}
			k++;
		}
		if (b > 1 && b < i)
		{
			printf("%ld\n", b);		//判别并输出大于 i 平方根的因数
		}
		if (b == i)				//b=i，表示i无质因数
		{
			printf("(素数!)\n");
		}
	}
	return 0;
}
#endif

#if 0
// 双精度质因数分解指数形式
#include <stdio.h>
#include <math.h>

int main()
{
	double b, i, k, m, n;
	int j;
	printf("请输入 m,n :>_ ");
	scanf("%lf%lf", &m, &n);
	for (i = m; i <= n; i++)
	{
		printf(" %.0f = ", i);
		b = i;
		k = 2;
		j = 0;
		while (k <= pow(i, 0.5))	//k为试商因数
		{
			if (0 == fmod(b, k))	//k为质因数，返回再试
			{
				b = floor(b / k);
				j++;
				continue;
			}
			if (j >= 1)
			{
				printf("%.0f", k);
				if (j > 1)
				{
					printf(" %d", j);		//打印指数形式
				}
				if (b > 1)
				{
					printf(" * ");
				}
			}
			k++;
			j = 0;
		}
		if (b > 1 && b < i)
		{
			printf("%.0f", b);		//输出大于i平方根的因数
		}
		if (i == b)
		{
			printf("(素数!)");		//b=i，表示i无质因数
		}
		printf("\n");
	}
	return 0;
}

#endif