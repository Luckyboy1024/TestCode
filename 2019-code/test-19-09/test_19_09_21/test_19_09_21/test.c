#define _CRT_SECURE_NO_WARNINGS 1

//求长方体数组
#include <stdio.h>
#include <math.h>
int main()
{
	long a, b, d, k, x, y, z, w;
	printf("请输入区间[a,b]的上下限 a,b :>_ ");
	scanf("%ld%ld", &a, &b);
	k = 0;
	for (x = a; x <= sqrt(b*b / 3); x++)			//设置枚举三重循环
	{
		for (y = x; y <= sqrt((b*b - x*x) / 2); y++)
		{
			for (z = y; z <= sqrt(b*b - x*x - y*y); z++)
			{
				d = x*x + y*y + z*z;
				w = (int)sqrt(d);		//w 为 x,y,z 的平方和开平方
				if (w > b)
					break;
				if (d == w*w)		//满足条件时比较最值
				{
					k++;
					printf("%3d: %ld,%ld,%ld,%ld\n", k, x, y, z, w);	//输出最值
				}
			}
		}
	}
	if(k>0)
		printf("在指定区间[%ld,%ld]中共有以上%ld组长方体数\n", a, b, k);
	else
		printf("在指定范围内没有长方体数\n");
	return 0;
}

#if 0
//求指定区间内的倒立勾股数组
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, n;
	long x, y, z;
	printf("请输入区间[a,b]的上下限 a,b :>_ ");
	scanf("%d%d", &a, &b);
	printf("区间[%d,%d]中的倒立勾股数组有：\n", a, b);
	n = 0;
	for (z = a; z <= b - 2; z++)	//设置z,y,x循环枚举
	{
		for (y = z + 1; y <= b - 1; y++)
		{
			for (x = y + 1; x <= b; x++)
			{
				if (z*z*(x*x + y*y) == x*x*y*y)			//满足倒立勾股数组时输出
				{
					n++;
					printf("1/%ld^2+1/%ld^2 = 1/%ld^2\n", x, y, z);
				}
			}
		}
	}
	printf("共%d组倒立勾股数", n);
	return 0;
}

//求指定区间内的勾股数组
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, n;
	long x, y, z, d;
	printf("请输入区间[a,b]的上下限 a,b :>_ ");
	scanf("%d%d", &a, &b);
	printf("区间[%d,%d]中的勾股数组有：\n", a, b);
	n = 0;
	for (x = a; x <= b - 2; x++)
	{
		for (y = x + 1; y <= b - 1; y++)
		{
			d = x*x + y*y;	
			z = sqrt(d);		//z为x,y的平方和开平方
			if (z > d)
				break;
			if (d == z*z)		//满足勾股数条件时输出
			{
				n++;
				printf("%ld^2+%ld^2 = %ld^2\n", x, y, z);
			}
		}
	}
	printf("共%d组勾股数", n);
	return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
	int k, m, n, t, f[10];
	long a, b, c, d, w;
	printf("数字2,3,5,6,7,8,9的全排列中的平方数:\n");
	n = 0;
	b = (long)sqrt(2356789);
	c = (long)sqrt(9876532);
	for (a = b; a <= c; a++)
	{
		d = a*a;
		w = d;			//确保 d 为平方数
		for (k = 0; k <= 9; k++)
		{
			f[k] = 0;
		}
		while (w > 0)
		{
			m = w % 10;
			f[m]++;
			w = w / 10;
		}
		for (t = 0, k = 1; k <= 9; k++)
		{
			if (f[k] > 1)		//测试三个平方数是否有重复数字
				t = 1;
		}
		if (0 == t && 0 == f[0] + f[1] + f[4])			//测试平方数中没有数字0、1、4
		{
			n++;
			printf("%2d: ", n);
			printf("%ld = %ld^2\n", d, a);
		}
	}
	printf("共可组成以上%d个\n", n);
	return 0;
}
#endif