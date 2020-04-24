#define _CRT_SECURE_NO_WARNINGS 1


#if 0
// 求指定区间上的孪生素数对
#include <stdio.h>
#include <math.h>

int main()
{
	long int c, d, i, j, f = 0;
	int t, n = 0;
	printf("求区间[c,d]上的孪生素数对\n");
	printf("请输入 c，d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;			//确保起点c为奇数
	}
	for (i = c; i <= d; i += 2)
	{
		for (t = 0, j = 3; j <= sqrt(i); j += 2)		//试商判别素数
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (0 == t)		//t为0表明i为素数
		{
			if (2 == i - f)
			{
				printf(" (%ld,%ld)", f, i);
				n++;
			}
			f = i;			//素数 i 存储到 f，为后一判别做准备
		}
	}
	printf("\n[%ld,%ld]上共 %d 对孪生素数。\n", c, d, n);
	return 0;
}


#endif


#if 0

#include <stdio.h>
#include <math.h>

int main()
{
	long int c, d, i, j;
	int t, m, n = 0;
	static long a[5000];
	printf("请输入 c,d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;		//确保起点 c 为奇数
	}
	for (m = 0, i = c; i <= d; i += 2)
	{
		for (t = 0, j = 3; j <= sqrt(i); j += 2)	//试商法判别素数
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			a[++m] = i;		// i 为素数给 a 数组赋值
		}
	}
	for (i = 1; i < m; i++)
	{
		if (a[i + 1] - a[i] == 2)		//相邻素数相差为2即输出
		{
			printf(" (%ld,%ld)", a[i], a[i + 1]);
			n++;
		}
	}
	printf("\n[%ld,%ld]上共 %d 对孪生素数。\n", c, d, n);
	return 0;
}

#endif


#if 0

//搜索 n 位逆序素数对
#include <stdio.h>
#include <math.h>
int main()
{
	long f, i, j, k, m, r, s, t, p[50000];
	int c, d, g, n;
	printf("请输入位数 n (n>1) :>_ ");
	scanf("%d", &n);
	k = s = 0;
	t = 1;
	for (j = 1; j <= n - 1; j++)
	{
		t = t * 10;			//计算最小的 n 位整数 t
	}
	for (m = t + 1; m <= (10 * t - 1); m = m + 2)	//枚举所有的n位奇数
	{
		if (0 == m % 5) continue;
		for (g = 0, i = 2; i <= sqrt(m); i++)
		{
			if (0 == m%i)
			{
				g = 1;
				break;
			}
		}
		if (0 == g)
		{
			k++;
			p[k] = m;
		}
	}
	for (j = 1; j <= k - 1; j++)
	{
		f = p[j];
		c = f % 10;
		d = f / t;
		if (c < d) continue;		//素数的逆序数比本身小的不考虑
		for (r = 0, i = 1; i <= n; i++)
		{
			c = f % 10;
			r = r * 10 + c;
			f = f / 10;		//r为d的逆序数
		}
		if (r < p[j])
		{
			continue;		//素数的逆序数比本身小的不考虑
		}
		for (i = j + 1; i <= k; i++)
		{
			if (r == p[i])		//逆序数r是比本身大的素数则输出
			{
				s++;
				printf("(%ld):%ld,%ld ", s, p[j], r);
				if (0 == s % 5)
					printf("\n");
			}
		}
	}
	printf("\n %d 位逆序素数对共有 %d 对。\n", n, s);
	return 0;
}



#endif


#if 1

#include 

#endif
