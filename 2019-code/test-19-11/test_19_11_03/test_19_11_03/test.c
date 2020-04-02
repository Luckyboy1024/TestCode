#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 求奇因数代数和
#include <stdio.h>

int main()
{
	int d, m, n;
	long s;
	printf("请输入整数 n :>_ ");
	scanf("%d", &n);
	s = 0;			// 和 s 置零
	for (m = 1; m <= n; m++)
	{
		if (m % 2 > 0)				//奇数 m 累加到 s
		{
			s = s + m;
		}
		else
		{
			d = m;
			while (0 == d % 2)		// 去除偶数 m 的偶因数
			{
				d = d / 2;
			}
			s = s - d;
		}
	}
	printf("s(%d) = %ld\n", n, s);		//输出和 s
	return 0;
}

#include <stdio.h>

int main()
{
	int a, b, d, j, n;
	double t, s;
	printf("请输入整数 d,n :>_ ");
	scanf("%d%d", &d, &n);
	a = d;
	b = 1;
	while (a > 0)
	{				//根据 d 计算 b,为递推 t 做准备
		b = b * 10;
		a = a / 10;
	}
	t = s = 0;		// t,s 清零
	for (j = 1; j <= n; j++)
	{
		t = t / b + (double)d / b;		// t 为第 j 项小数
		s += t;							// 求和 s
	}
	printf("s(%d,%d) = %.8f\n", d, n, s);		// 输出和 s
	return 0;
}

#include <stdio.h>

int main()
{
	int d, n;
	double s;
	printf("请输入整数 d,n :>_ ");
	scanf("%d%d", &d, &n);
	s = (n - 0.111111111)*d / 9;		// 求和 s
	printf("s(%d,%d) = %.8f\n", d, n, s);	//输出和 s
	return 0;
}

#include <stdio.h>

int main()
{
	int d, j, n;
	double t, s;
	printf("请输入整数 d,n :>_ ");
	scanf("%d%d", &d, &n);
	t = s = 0;		// t,s 清零
	for (j = 1; j <= n; j++)
	{
		t = t / 10 + (double)d / 10;	// t 为第 j 项小数
		s += t;							// 求和 s
	}
	printf("s(%d,%d) = %.8f\n", d, n, s);	//输出和 s
	return 0;

}
#endif


#include <stdio.h>

int main()
{
	double t, s, v, p;
	int i, n;
	printf("请输入格数 n :>_ ");
	scanf("%d", &n);		//输入格数 n
	t = s = 1;
	for (i = 2; i <= n; i++)
	{
		t = t * 2;		// t 为第 i 格的麦粒数
		s = s + t;		// s 求所有格的麦粒和
	}
	v = s / 2.4e7;		// 1 吨小麦约为 2.4e7 粒 
	p = v / 2.48e9;		// 世界粮食年总产量约为 2.48e9 吨
	if (n <= 40)
	{
		printf("总麦粒数为 :>_ %.0f\n", s);
	}
	else
	{
		printf("总麦粒数约为 :>_ %.3e\n", s);
	}
	printf("小麦重量约为 :>_ %.0f 吨\n", v);
	printf("约相当于世界粮食年总产量的 %.0f 倍\n", p);
	return 0;
}

