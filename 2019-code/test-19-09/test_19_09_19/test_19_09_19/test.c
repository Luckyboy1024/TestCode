#define _CRT_SECURE_NO_WARNINGS 1




#if 0

#include <stdio.h>
#include <math.h>

int main()
{
	int k, m, n, i, x, b[10];
	long t, t1, t2, y, d, f;
	printf("把 1,2,……,9 这9个数字选m个\n");
	printf("组合成没有重复数字的平方数\n");
	printf("请输入平方数的位数 m :>_ ");
	scanf("%d", &m);
	n = 0;
	t = 1;
	for (y = 1; y < m - 1; y++)
	{
		t = t * 10;
	}
	t1 = (long)sqrt(t);
	t2 = (long)sqrt(10 * t);
	for (y = t1 + 1; y < t2; y++)
	{
		f = y*y;				//数 f 为 m 位平方数
		d = f;
		for (x = 0, i = 1; i <= m; i++)
		{
			k = f % 10;
			f = f / 10;
			if (0 == k || (++b[k]>1))
			{
				x = 1;
				break;			//含数字 0 或者重复数字则记 x=1
			}
		}
		if (0 == x)
		{
			n++;
			printf("%ld = %d^2", d, y);
			if (n % 3 == 0)
				printf("\n");
		}
	}
	printf("\n共%d个\n", n);
	return 0;
}


#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, w, m, x, y;
	long c, d;
	int k, n, s = 0;
	printf("请输入正整数 n (3<n<16):>_ ");
	scanf("%d", &n);
	for (m = 1, k = 2; k <= n; k++)
	{
		m *= 10;
	}
	c = (long)pow(m, 0.5);
	d = (long)pow(10 * m - 1, 0.5);
	for (b = c + 1; b <= d; b++)
	{
		a = b*b;
		w = 1;									//a为 n 位平方数
		for (k = 1; k <= n - 1; k++)
		{
			w *= 10;
			x = floor(a / w);
			y = fmod(a, w);						//n位平方数 a 分为前后两段 x,y
			if (b == x + y && y > 0)			//分段和条件检验
			{
				s++;
				printf("%.0f = (%.0f+%.0f)^2\n", a, x, y);
			}
		}
	}
	if (s > 0)
	{
		printf("共%d个%d位2段和平方数\n", s, n);
	}
	else
	{
		printf("没有%d位2段和平方数\n", n);
	}
	return 0;
}



#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, m, w, x, y;
	int k, n;
	long c, d;
	printf("请输入偶数 n (n≤14):>_ ");
	scanf("%d", &n);
	if (n % 2 > 0)
	{
		printf("请输入偶数");
		return 0;
	}
	printf("%d位卡普雷卡数有:>_ ", n);
	for (w = 1, k = 2; k <= n; k++)
		m *= 10;
	for (w = 1, k = 1; k <= n / 2; k++)
		w *= 10;
	c = (long)pow(m, 0.5);
	d = (long)pow(10 * m - 1, 0.5);	//求出枚举 b 循环的起点和终点
	for (b = c + 1; b <= d; b++)
	{
		a = b*b;
		x = floor(a / w);
		y = fmod(a, w);				//n 位平方数 a 分为前后数 x,y
		if(b = x+y && y>=w/10)		//分段和条件检验
			printf("%.0f=(%.0f+%.0f)^2\n", a, x, y);
	}
	return 0;
}


#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, x, y;
	printf("4 位卡普雷卡数有:>_ ");
	c = (int)sqrt(1000);
	for (b = c + 1; b < 99; b++)	//枚举 2 位数 b
	{
		a = b*b;
		x = a / 100;
		y = a % 100;				// a 分为前后两个 2 位数
		if (y >= 10 && x + y == b)		//分段和条件检验
			printf("%d ", a);
	}
	printf("\n");
	return 0;
}




//求 n 个正整数的最大公约数和最小公倍数
#include <stdio.h>

int main()
{
	int k, n;
	long a, b, c, m[100];
	printf("输入正整数个数 n :>_ ");
	scanf("%d", &n);
	printf("请依次输入 %d 个正整数:>_ ", n);
	for (k = 0; k < n; k++)
	{
		printf("\n请输入第 %d 个正整数", k + 1);
		scanf("%d", &m[k]);		//输入原始数据
	}
	b = m[0];
	for (k = 1; k < n; k++)		//循环计算 n-1 次
	{
		a = m[k];
		if(a < b)
		{
			c = a;
			a = b;
			b = c;				//交换 a,b 确保 a>b		
		}
		for (c = b; c >= 1; c--)
		{
			if (0 == a%c && 0 == b%c)	//计算最大公约数
				break;
		}
		if (1 == c)		//如果求得最大公约数为 1,退出循环
			break;
		b = c;
	}
	//输出最大公约数结果
	printf("(%ld", m[0]);
	for (k = 1; k < n; k++)
	{
		printf(",%ld", m[k]);
	}
	printf(") = %ld\n", c);
	b = m[0];
	for(k= 1; k < n; k++)	//循环计算 n-1 次
	{
		a = m[k];
		if (a < b)
		{
			c = a;
			a = b;
			b = c;
		}
		for (c = a; c <= a*b; c = c + a)
		{
			if (0 == c%b)
				break;					//按定义计算最小公倍数 c
		}
		b = c;
	}
	//输出最小公倍数结果
	printf("(%ld", m[0]);
	for (k = 1; k < n; k++)
	{
		printf(",%ld", m[k]);
	}
	printf(") = %ld\n", c);
	return 0;
}
//求a,b的最大公约数与最小公倍数常规求解
#include <stdio.h>

int main()
{
	long a, b, c;
	printf("请输入正整数 a,b :>_ ");
	scanf("%ld%ld", &a, &b);
	if (a < b)
	{
		c = a;
		a = b;
		b = c;			//交换 a,b 确保 a>b 
	}
	for (c = b; c >= 1; c--)
	{
		if (a%c == 0 && b%c == 0)
			break;
	}
	printf("(%ld, %ld) = %ld\n", a, b, c);
	printf("(%ld, %ld) = %ld\n", a, b, a*b / c);
	return 0;
}

//求a,b的最大公约数与最小公倍数经典求解
#include <stdio.h>

int main()
{
	long a, b, c, r, a1, b1;
	printf("请输入正整数 a,b :>_ ");
	scanf("%ld%ld", &a, &b);
	if (a < b)
	{
		c = a;
		a = b;
		b = c;			//交换 a,b 确保 a>b 
	}
	a1 = a;
	b1 = b;
	r = a%b;
	while (0 != r)		//辗转相除
	{
		a = b;
		b = r;
		r = a%b;
	}
	printf("(%ld, %ld) = %ld\n", a1, b1, b);			//输出求解结果
	printf("(%ld, %ld) = %ld\n", a1, b1, a1*b1 / b);
	return 0;
}

#endif