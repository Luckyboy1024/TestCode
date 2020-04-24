#define _CRT_SECURE_NO_WARNINGS 1


// 极差过关游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, k, m, n, r, s, u, v, tim;
	int b[30], p[30], q1[30], q2[30], t[30], min, max;
	tim = time(0) % 1000;
	srand(tim);
	printf("极差游戏过 4 关：1 简单；2 容易；3 较难；4 难。\n");
	v = 0;
	for (m = 1; m <= 4; m++)
	{
		printf("过第%d关", m);
		r = 3 * m - 1; 
		n = r + 3 + m / 3;
		min = 10000;
		max = 0;
		printf("请在以下%d个数字组成的整数中插入%d个 + 号：\n", n, r);
		for (k = 1; k <= n; k++)
		{
			b[k] = rand() % 9 + 1;
			printf("%d", b[k]);
		}
		printf("请游戏者计算其最大和与最小和之差，并输入极差：");
		i = 1;
		t[1] = 1;
		t[0] = 0;
		t[r + 1] = n;
		while (1)
		{
			if (i == r)
			{
				s = 0;
				for (k = 1; k <= r + 1; k++)
				{
					p[k] = 0;
					for (j = t[k - 1] + 1; j <= t[k]; j++)
					{
						p[k] = p[k] * 10 + b[j];
					}
					s = s + p[k];
				}
				if (s > max)
				{
					max = s;
					for (k = 1; k <= r + 1; k++)
					{
						q1[k] = p[k];
					}
				}
				if (s < min)
				{
					min = s;
					for (k = 1; k <= r + 1; k++)
					{
						q2[k] = p[k];
					}
				}
			}
			else
			{
				i++;
				t[i] = t[i - 1] + 1;
				continue;
			}
			while (n - r + i - 1 == t[i])
			{
				i--;
			}
			if (i > 0)
			{
				t[i]++;
			}
			else break;
		}
		scanf("%d", &u);
		if (max - min == u)
		{
			v++;
			printf("速算正确，过关！");
		}
		else
		{
			printf("错！最大和式为：");
			for (k = 1; k <= r; k++)
			{
				printf("%d+", q1[k]);
			}
			printf("%d=%d\n", q1[r + 1], max);
			printf("最小和式为：");
			for (k = 1; k <= r; k++)
			{
				printf("%d+", q2[k]);
			}
			printf("%d=%d\n", q2[r + 1], min);
			printf("极差 4 关已通过%d关, 退出重来！\n", v);
			return 0;
		}
	}
	printf("恭喜你，4关已全部通过！");
	return 0;
}

#if 0


// 加减得 1 的精简循环设计
#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, d, t, x, y;
	printf("请输入整数 a,b :>_ ");
	scanf("%lf%lf", &a, &b);
	c = (a > b ? b : a);
	for (t = 2; t <= c; t++)
	{
		if (0 == fmod(a, t) && 0 == fmod(b, t))	// a,b存在大于1的公因数t
		{
			printf("不可能得到 1。\n");
			return 0;
		}
	}
	x = 0;
	while (x < 10000000)
	{
		x++;
		d = x*a;
		if (0 == fmod((d - 1), b))
		{
			y = floor((d - 1) / b); 
			t = 1; 
			break;
		}
		if (0 == fmod((d + 1), b))
		{
			y = floor((d + 1) / b); 
			t = 2; 
			break;
		}
	}
	if (x >= 10000000)
	{
		printf("未找到得1运算！\n");
		return 0;
	}
	if (1 == t)
	{
		printf("%.0f个%.0f中为+, %.0f个%.0f前为-,\n", x, a, y, b);
		printf("至少%.0f次运算得1。\n", x + y - 1);
	}
	if (2 == t)
	{
		printf("%.0f个%.0f中为+, %.0f个%.0f前为-,\n", y, b, x, a);
		printf("至少%.0f次运算得1。\n", x + y - 1);
	}
	return 0;
}


// 加减得 1 的基本设计
#include <stdio.h>

int main()
{
	long a, b, c, d, n, t, x, y;
	printf("请输入整数 a,b :>_ ");
	scanf("%ld%ld", &a, &b);
	c = (a > b ? b : a);
	for (t = 2; t <= c; t++)
	{
		if (a%t == 0 && b%t == 0)		//a、b存在大于 1 的公因数 t
		{
			printf("不可能得到 1\n");
			return 0;
		}
	}
	n = 0;
	while (n < 10000000)
	{
		n++;
		for (x = 1; x <= n; x++)
		{
			y = n + 1 - x;
			d = x*a - y*b;
			if (1 == d || -1 == d)
			{
				if (1 == d)
				{
					printf("%ld个%ld中为+，%ld个%ld前为-，", x, a, y, b);
					printf("至少%ld次运算得 1。\n", n);
				}
				if (-1 == d)
				{
					printf("%ld个%ld中为+，%ld个%ld前为-，", y, b, x, a);
					printf("至少%ld次运算得 1。\n", n);
				}
				return 0;
			}
		}
	}
	if (n >= 10000000)
	{
		printf("未找到得 1 运算！\n");
	}
	return 0;
}


//数字魔术
#include <stdio.h>

int main()
{
	int a, b, c, m, n, t;
	printf("请想好一个三位数 n = abc, 只要算出\n");
	printf("另 5 个三位数：abc、bac、bca、cab、cba 之和 m\n");
	printf("即可推算出 n。\n\n");
	printf("请输入五个数之和 m :>_ ");
	scanf("%d", &m);
	t = 0;
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				n = 122 * a + 212 * b + 221 * c;	//由 a、b、c 计算 n
				if (m == n)
				{
					printf("我猜你想的数是：%d\n", a * 100 + b * 10 + c);
					t = 1;
				}
			}
		}
	}
	if (t == 0)
	{
		printf("你给出的和算错了！\n");
	}
	return 0;
}





#include <stdio.h>

int main()
{
	long x, y, m, t;
	printf("请输入人数 m :>_ ");
	scanf("%ld", &m);
	x = m / 20;
	t = m - 20 * m;
	y = t / 3;
	t = m - 20 * x - 3 * y;
	printf("喝 %ld 瓶汽水，至少需要 %.2f 元。\n", m, (13 * x + 2 * y)*1.40 + t);
	return 0;
}
#endif