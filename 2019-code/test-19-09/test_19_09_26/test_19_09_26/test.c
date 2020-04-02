#define _CRT_SECURE_NO_WARNINGS 1

#if 0

//
#include <stdio.h>

int main()
{
	return 0;
}
#endif



#if 0

//递归求指定 m 位超级素数
#include <stdio.h>
#include <math.h>


int p(double k)              //设计素数检测函数
{
	int h, z = 0;
	double j;
	long t;
	z = 0;
	t = (int)pow(k, 0.5);
	for (h = 0, j = 3; j <= t; j += 2)
	{
		if (fmod(k, j) == 0)
		{
			h = 1;
			break;
		}
	}
	if (0 == h)
		z = 1;
	return z;
}
int main()
{
	int g, i, j, k, m, t, s;
	double d, f, a[20000], b[20000], e[20];
	int p(double f);
	printf("请确定 m (m>1) :>_ ");
	scanf("%d", &m);
	g = 2;
	s = 0;
	a[1] = 3;		//
	a[2] = 7;		//
	e[1] = 1;		//递归的初始条件
	for (k = 2; k <= m; k++)
	{
		e[k] = e[k - 1] * 10;
		t = 0;
		for (j = 1; j <= 9; j++)
		{
			for (i = 1; i <= g; i++)
			{
				f = j*e[k] + a[i];		//产生9*g个候选数f
				if (p(f) == 1)
				{
					t++;
					b[t] = f;
					if (k == m)
					{
						s++;
						d = f;			//统计并记录最大超级素数
					}
				}
			}
		}
		g = t;
		for (i = 1; i <= g; i++)
		{
			a[i] = b[i];		//g个k位b[i]赋值给a[i]
		}
	}
	printf("共%d个%d位超级素数\n", s, m);
	printf("其中最大数为%.0f\n", d);
	return 0;
}
#endif