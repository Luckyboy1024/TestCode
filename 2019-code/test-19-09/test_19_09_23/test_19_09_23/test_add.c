#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>

int main()
{
	int d, g, i, j, k, m, n, r, a[3000][30], b[3000][30];
	printf("请输入逐位整除数的位数 n :");
	scanf("%d", &n);
	g = 9;			//递推基础：1位时赋初值
	for (j = 1; j <= g; j++)
	{
		a[j][1] = j;
	}
	for (k = 2; k <= n; k++)	//递推位数k从2开始递增
	{
		m = 0;
		for (i = 1; i <= g; i++)		//枚举g个k-1位逐位整除数
		{
			for (j = 0; j <= 9; j++)		//k位数的个位数字为j
			{
				a[i][k] = j;
				for (r = 0, d = 1; d <= k; d++)		//检测k位数除k的余数r
				{
					r = r * 10 + a[i][d];
					r = r%k;
				}
				if (0 == r)
				{
					m++;
					for (d = 1; d <= k; d++)
					{
						b[m][d] = a[i][d];		//满足条件的k位数赋值给b数组
					}
				}
			}
		}
		g = m;		//递推得g个k位逐位整除数
		for (i = 1; i <= g; i++)
		{
			for (d = 1; d <= k; d++)
			{
				a[i][d] = b[i][d];		//g个b数组向a数组赋值，准备下步递推
			}
		}
	}
	if (g>0)		//输出n位的个数及每一个数
	{
		printf("%d位逐位整除数共%4d个: \n", n, g);
		for (i = 1; i <= g; i++)
		{
			printf(" %d:", i);
			for (d = 1; d <= n; d++)
			{
				printf("%d", a[i][d]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("无解\n");
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int i, j, n, r, t, s, a[100];
	printf("逐位整除数 n 位，请确定 n :>_ ");
	scanf("%d", &n);
	printf("所求%d位逐位整除数:>_\n", n);
	for (j = 1; j <= 100; j++)
	{
		a[j] = 0;
	}
	t = 0;
	s = 0;
	i = 1;
	a[1] = 1;
	while (a[1] <= 9)
	{
		if (t == 0 && i < n)
			i++;
		for (r = 0, j = 1; j <= i; j++)		//检测i时是否整除i
		{
			r = r * 10 + a[j];
			r = r%i;
		}
		if (r != 0)
		{
			a[i] = a[i] + 1;
			t = 1;		//余数r != 0时，a[i]增1，t=1
			while (a[i]>9 && i>1)
			{
				a[i] = 0;
				i--;		//回溯
				a[i] = a[i] + 1;
			}
		}
		else t = 0;		//余数 r=0 时，t=0
		if (t == 0 && i == n)
		{
			s++;
			printf("%d :", s);
			for (j = 1; j <= n; j++)
			{
				printf("%d", a[j]);
			}
			printf("\n");
			a[i] = a[i] + 1;
		}
	}
	if (s == 0)
		printf("没有找到！\n");
	else 
		printf("共以上%d个解\n", s);
	return 0;
}

#include <stdio.h>

for (r = 0, j = 1; j <= i; j++)
{
	r = r * 10 + a[j];
	r = r%i;
}

if (v == 0 && a[k] != 0)   //输出k位守形数结果
{
	printf("%d结尾的%2d位守形数：", a[1], k);
	for (j = k; j >= 1; j--)
	{
		printf("%d", a[j]);
	}
	printf("\n");
}

int main()
{
	int n, d, k, j, i, t, m, w, z, u, v, a[500], b[500], c[500];
	printf("请输入整数n :>_ ");
	scanf("%d", &n);
	for (d = 1; d <= 9; d++)
	{
		for (k = 1; k <= 499; k++)
		{
			a[k] = 0;
			b[k] = 0;
			c[k] = 0;
		}
		a[1] = d;				//给守形数个位数赋值
		for (k = 2; k <= n; k++)
		{
			for (j = 0; j <= 9; j++)
			{
				a[k] = j;
				v = 0;			//探索守形数的第k位a(k)选数字 j
				for (i = 1; i <= k; i++)
				{
					c[i] = 0;
				}
				for (i = 1; i <= k; i++)
				{
					for (z = 0, t = 1; t <= k; t++)
					{
						u = a[i] * a[t] + z;
						z = u / 10;
						b[i + t - 1] = u % 10;		//计算中间结果存于b数组
					}
					for (w = 0, m = i; m <= k; m++)
					{
						u = c[m] + b[m] + w;	//计算平方存于c数组
						w = u / 10;
						c[m] = u % 10;
					}
				}
				for (i = 1; i <= k; i++)
				{
					if (a[i] != c[i])
						v = 1;				//出现不同数字时继续，a[k]选下一个数字
				}
				if (0 == v)
					break;
			}
		}
		if(0 == v && a[n] != 0)
		{
			printf("%d结尾的%d位守形数 : ", a[1], n);
			for (k = n; k >= 1; k--)
			{
				printf("%d ", a[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
int main()
{
	long a, b, c, k, m, s, x, y;
	printf("请输入区间上下限整数 x,y :>_ ");
	scanf("%ld%ld", &x, &y);
	m = 0;
	for (a = x; a <= y; a++)
	{
		s = a*a;		//计算 a 的平方数 s
		b = 1;
		k = a;
		while (k > 0){
			b = b * 10;
			k = k / 10;
		}
		c = s%b;		//c为a的平方数s的尾部
		if (a == c)
		{
			++m;
			printf("%ld^2 = %ld\n", a, s);
		}
	}
	printf("区间[%ld,%ld]中，共以上%ld个守形数\n", x, y, m);
	return 0;
}
#endif