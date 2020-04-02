#define _CRT_SECURE_NO_WARNINGS 1


#if 0
//搜索 n 位兰德尔数
#include <stdio.h>
#include <math.h>
int main()
{
	int m, n, i;
	double f, k, s, t, y;
	printf("请输入位数 n (2<n<10):>_ ");
	scanf("%d", &n);
	m = 0;
	t = 1;
	for (i = 1; i <= n - 1; i++)
	{
		t = t * 10;
	}
	for (y = t + 1; y <= t * 10 - 1; y++)		//枚举 n 位整数
	{
		f = y;
		for (s = 0, i = 1; i <= n; i++)	//循环分离 y 的 n 个数字 k
		{
			k = fmod(f, 10);
			s += pow(k, n);
			f = floor(f / 10);				//求 y 的n个数字的n次幂之和s
		}
		if (y == s)				//检测是否满足条件
		{
			m++;
			printf(" %.0f", y);		//输出探索结果
		}
	}
	printf("\n %d 位兰德尔数共 %d 个\n", n, m);
	return 0;
}

//基于组合的求水仙花数程序
#include <stdio.h>
int main()
{
	int m, a, b, c;
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				m = a * 100 + b * 10 + c;
				if (m == a*a*a + b*b*b + c*c*c)
					printf(" %d", m);
			}
		}
	}
	return 0;
}

//基于分解的求水仙花数程序
#include <stdio.h>
int main()
{
	int m, a, b, c;
	for (m = 100; m <= 999; m++)
	{
		a = m / 100;		//把 m 分解为三个数字
		b = (m / 10) % 10;
		c = m % 10;
		if (m == a*a*a + b*b*b + c*c*c)		//检验是否满足条件
		{
			printf(" %d", m);
		}
	}
	return 0;
}

//探求完全数与p-完全数
#include <stdio.h>
#include <math.h>
int main()
{
	double a, a1, s, b, c, d, d1, k, t, t1, x, y, p[10], q[10], min;
	int j, m = 0;
	min = 1.0;
	printf("请输入区间 x,y :>_ ");
	scanf("%lf%lf", &x, &y);
	for (a = x; a <= y; a++)			//枚举区间内的所有整数a
	{
		s = 1;
		b = floor(sqrt(a));
		for (k = 2; k <= b; k++)		//试商寻求a的因数k
		{
			if (0 == fmod(a, k))
			{
				s = s + k + a / k;		//k与a/k是a的因数，求和
			}
		}
		if (a == b*b)			//如果a=b^2,去掉重复因数b
			s = s - b;
		t = s / a;
		d = floor(t);
		c = t - d;
		if(0==c)
		{
			m++;
			p[m] = a;
			q[m] = t;
		}
		else if (c > 0.5)
		{					//c 为因数比 t 最接近正整数d的差值
			c = 1 - c;
			d = d + 1;
		}
		if (t > 0.5 && c < min)
		{					//比较求因数比最接近整数
			min = c;
			a1 = a;
			t1 = t;
			d1 = d;
		}
	}
	if (m>0)		//逐一输出 p-完全数
	{
		for (j = 1; j <= m; j++)
		{
			printf("p(%.0f) = %.0f", p[j], q[j]);
		}
	}
	else
	{
		printf("%.0f的因数比%.4f最接近正整数%.0f\n", a1, t1, d1);
	}
	return 0;
}

//改进求指定区间内的完全数
#include <stdio.h>
#include <math.h>

int main()
{
	int k;
	long a, b, s, x, y;
	printf("求区间[x,y]中的完全数");
	printf("请输入整数 x,y: ");
	scanf("%ld,%ld", &x, &y);
	printf("[%ld,%ld]中的完全数有:\n", x, y);
	for (a = x; a <= y; a++)
	{
		s = 1;
		b = sqrt(a);
		for (k = 2; k <= b; k++)
		{
			if (a%k == 0)
				s = s + k + a / k;
		}
		if (a == b*b)
			s = s - b;
		if (a == s)
		{
			printf("%ld = 1", a);
			for (k = 2; k <= a / 2; k++)
			{
				if (a%k == 0)
					printf("+%d", k);
			}
			if (a % 2 == 1)
				printf("奇完全数");
			printf("\n");
		}
	}
	return 0;
}

//求指定区间内的完全数
#include <stdio.h>
int main()
{
	int k;
	long a, s, x, y;
	printf("请输入整数 x,y: ");
	scanf("%ld,%ld", &x, &y);
	printf("[%ld,%ld]中的完全数有: \n", x, y);
	for (a = x; a <= y; a++)
	{
		s = 1;
		for (k = 2; k <= a / 2; k++)	//试商寻求 a 的因数 k
		{
			if (a%k == 0)	
				s = s + k;		//k 是 a 的因数，赋值求和
		}
		if (a == s)				//从小到大打印因数和式
		{
			printf("%ld =1",a);
			for (k = 2; k <= a / 2; k++)
			{
				if (a%k == 0)
					printf("+%d", k);
			}
			if (a % 2 == 1)
				printf("找到奇完全数");
			printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
	long a, b, x, y, z, e1, e2, e3, d1, d2, d3, n = 0;
	printf("请输入区间[a,b]的上下限 a,b :>_ ");
	scanf("%ld%ld", &a, &b);
	for (x = a; x < sqrt(b*b / 2); x++)
	{
		for (y = x + 1; y <= sqrt(b*b - x*x); y++)
		{
			d1 = x*x + y*y;
			e1 = (long)sqrt(d1);
			if (d1 == e1*e1 && e1<b)
			{
				for (z = y + 1; z <= sqrt(b*b - x*x); z++)
				{
					d2 = x*x + z*z;
					e2 = (long)sqrt(d2);
					d3 = y*y + z*z;
					e3 = (long)sqrt(d3);
					if (d2 == e2*e2 && d3 == e3*e3 && e2 < b && e3 <= b)
					{
						n++;
						printf("NO.%ld:", n);			//输出长方体三棱长
						printf("%ld,%ld,%ld\n", x, y, z);
						printf("各面对角线长: ");
						printf("L(%ld,%ld) = %ld ", x, y, e1);		//注明三面对角线长
						printf("L(%ld,%ld) = %ld ", x, z, e2);
						printf("L(%ld,%ld) = %ld\n", y, z, e3);
						break;
					}
				}
			}
		}
	}
	return 0;
}
#endif