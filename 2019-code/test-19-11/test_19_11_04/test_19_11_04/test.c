#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//求 n 的阶乘 n!
#include <stdio.h>

int main()
{
	int k, n;
	long t;
	printf("请输入 n (n<13) :>_ ");
	scanf("%d", &n);
	t = 1;
	for (k = 1; k <= n; k++)
	{
		t = t * k;		//循环变量 k 累乘到 t,体现阶乘运算规律
	}
	printf("%d! = %ld\n", n, t);	// ! --> 阶乘符号
	return 0;
}
#endif 

#if 0

#include <stdio.h>


long fac(int n)
{
	long f = 0;
	if (1 == n)		//初始条件
	{
		f = 1;
	}
	else
	{				//递归关系
		f = n * fac(n - 1);
	}
	return f;
}

int main()
{
	int n;
	long y;
	printf("请输入 n (n<13) :>_ ");
	scanf("%d", &n);
	if (n > 12)
	{
		printf("输入的 n 超出上限 12，请重新输入\n");
		return 0;
	}
	y = fac(n);
	printf("%d! = %ld\n", n, y);
	return 0;
}

#endif

#if 0

#include <stdio.h>

long jc(int x)		// 定义阶乘函数 jc(x)=x!
{
	int i;
	long p = 1;
	for (i = 1; i <= x; i++)
	{
		p *= i;
	}
	return p;
}

int main()
{
	int a, b, c, m, n;
	printf("三位阶乘和数有 :>_ ");
	for (a = 1; a <= 9; a++)			// a,b,c 分别为百位，十位，个位数字
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				m = a * 100 + b * 10 + c;
				n = jc(a) + jc(b) + jc(c);		//阶乘和条件判别
				if (m == n)
				{
					printf("%d\n", m);
				}
			}
		}
	}
		return 0;
}

#endif

#if 0

#include <stdio.h>

long jc(int x)		// 定义阶乘函数 jc(x)=x!
{
	int i;
	long p = 1;
	for (i = 1; i <= x; i++)
	{
		p *= i;
	}
	return p;
}

int main()
{
	int a, b, c, d, e, f, g;
	long m1, m2, m3, m4, m5, m6, n1, n2, n3, n4, n5, n6;
	printf("所有阶乘和数有 :>_ ");
	for (a = 1; a <= 9; a++)
	{
		if (a == jc(a))					// 1 位数 a 满足条件则输出 
		{
			printf("%d ", a);
		}
		for (b = 0; b <= 9; b++)
		{
			m1 = 10 * a + b;
			n1 = jc(a) + jc(b);
			if (m1 == n1)				// 判别 2 位数 m1
			{
				printf("%ld ", m1);
			}
			for (c = 0; c <= 9; c++)
			{
				m2 = 10 * m1 + c;
				n2 = n1 + jc(c);
				if (m2 == n2)			// 判别 3 位数 m2
				{
					printf("%ld ", m2);
				}
				for (d = 0; d <= 9; d++)
				{
					m3 = 10 * m2 + d;
					n3 = n2 + jc(d);
					if (m3 == n3)		// 判别 4 位数 m3
					{
						printf("%ld ", m3);
					}
					for (e = 0; e <= 9; e++)
					{
						m4 = 10 * m3 + e;
						n4 = n3 + jc(e);
						if (m4 == n4)	// 判别 5 位数 m4
						{
							printf("%ld ", m4);
						}
						for (f = 0; f <= 9; f++)
						{
							m5 = 10 * m4 + f;
							n5 = n4 + jc(f);
							if (m5 == n5)// 判别 6 位数 m5
							{
								printf("%ld ", m5);
							}
							for (g = 0; g <= 9; g++)
							{
								m6 = 10 * m5 + g;
								n6 = n5 + jc(g);
								if (m6 == n6)// 判别 7 位数 m6
								{
									printf("%ld ", m6);
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
#endif

#if 0
// 阶梯电费计算
#include <stdio.h>

int main()
{	
	double x, y;
	printf("请输入月用电量（度）:>_ ");
	scanf("%lf", &x);
	if (x <= 240)	// 分三档计算电费
	{
		y = x*0.49;
	}
	else if (x <= 400)
	{
		y = 240 * 0.49 + (x - 240)*0.54;
	}
	else
	{
		y = 240 * 0.49 + (400 - 240) * 0.54 + (x - 400) * 0.79;
	}
	printf("应缴纳电费 (元) :>_ %9.2f\n", y);
	return 0;
}

#endif

#if 0
// 阶梯电费计算函数
#include <stdio.h>

double f(double x)
{
	double y;
	if (x <= 240)	// 参数 x 为月用电量
	{
		y = x*0.49;
	}
	else if (x <= 400)
	{
		y = 240 * 0.49 + (x - 240)*0.54;
	}
	else
	{
		y = 240 * 0.49 + (400 - 240) * 0.54 + (x - 400) * 0.79;
	}
	return y;
}

int main()
{
	double x;
	printf("请输入月用电量（度）:>_ ");
	scanf("%lf", &x);
	printf("应缴纳电费 (元) :>_ %9.2f\n", f(x));
	return 0;
}
#endif


#if 0
// 个人所得税计算
#include <stdio.h>

double s(double x)
{
	double y, c, d = 0.0;
	d = 0.0;		// 附加减除税费 d 清零，必要时可修改
	c = 3500.0 + d;	// 起征点为 3500
	if (x <= c)		// 参数 x 为月收入值
	{
		y = 0;
	}
	else if (x - c <= 1500)	// 计算第 1 级
	{
		y = (x - c)*0.03;
	}
	else if (x - c <= 4500)	// 计算第 2 级
	{
		y = s(c + 1500) + (x - c - 1500)*0.10;	// 调用自身函数 s()
	}
	else if (x - c <= 9000)	// 计算第 3 级
	{
		y = s(c + 4500) + (x - c - 4500)*0.20;
	}
	else if (x - c <= 35000)	// 计算第 4 级
	{
		y = s(c + 9000) + (x - c - 9000)*0.25;
	}
	else if (x - c <= 55000)	// 计算第 5 级
	{
		y = s(c + 35000) + (x - c - 35000)*0.30;
	}
	else if (x - c <= 80000)	// 计算第 6 级
	{
		y = s(c + 55000) + (x - c - 55000)*0.35;
	}
	else						// 计算第 7 级
	{
		y = s(c + 80000) + (x - c - 80000)*0.45;
	}
	return y;		// 返回所得税值额 y
}

int main()
{
	double x;
	printf("请输入月收入金额 :>_ ");
	scanf("%lf", &x);
	printf("应缴个人所得税 :>_ %9.2f\n", s(x));
	return 0;
}

#endif
