#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <stdio.h>

int main()
{
	long i, m;
	double n, s, s1;
	printf("请输入正数 n (n>3) :>_ ");
	scanf("%lf", &n);
	m = 0;
	while (1)
	{
		m++;
		s = 0;
		for (i = m; i <= 2 * m; i++)
		{
			s = s + sqrt(i);		//对每一个 m 计算和 s
		}
		if (s >= n)
			break;
		else
		{
			s1 = s;		//为以下注明提供依据
		}
	}
	printf("不等式的解为 :>_ m >= %ld\n", m);
	printf("注：当 m = %ld 时，s = %.2f;当 m = %ld 时，s = %.2f\n", m - 1, s1, m, s);
	return 0;
}
#endif

#if 0
//简化求解平方根不等式
#include <stdio.h>
#include <math.h>
int main()
{
	long m;
	double n, s, s1;
	printf("请输入正数 n (n>3) :>_ ");
	scanf("%lf", &n);			//输入任意正数
	m = 1;
	s = 1.0 +sqrt(2);			//s(1)赋初值
	do{
		m++;
		s1 = s;			//用 s1 记录 s(m-1)
		s = s - sqrt(m - 1) + sqrt(2 * m - 1) + sqrt(2 * m);	//递推计算和 s
	} while (s < n);
	printf("不等式的解为： m >= %ld\n", m);
	printf("注：当 m = %ld 时，s = %.2f;当 m = %ld 时，s = %.2f\n", m - 1, s1, m, s);
	return 0;
}
#endif

#if 0
//求解调和级数不等式
#include <stdio.h>

int main()
{
	long c, d, m;
	double x, y, s;
	printf("请输入正数 x,y (2<x<y) :>_ ");
	scanf("%lf%lf", &x, &y);
	m = 0;
	s = 0;
	while (s <= x){				//循环求和探索 m 的下确界 c
		s = s + 1.0/(++m);
	}
	c = m;
	do{
		s = s + 1.0 / (++m);
	} while (s < y);		//循环求和探索 m 的上确界 d
	d = m - 1;
	printf("满足不等式的解为 :>_ %ld<=m<=%ld\n", c, d);
	return 0;
}

#endif


#if 0
//解不等式：d < 1+1/2-1/3+1/4+1/5-1/6+...±/n
#include <stdio.h>

int main()
{
	long n, k;
	double d, s;
	printf("请输入正数 d :>_ ");
	scanf("%lf", &d);
	printf("%lf < 1+1/2-1/3+1/4+1/5-1/6+...±/n 的解为 :>_ \n", d);
	n = 1;
	s = 0;
	while (1)
	{
		s = s + 1.0/n+1.0/(n+1)-1.0/(n+2);	//每三项一起求和
		if (s > d) break;
		n = n + 3;
	}
	printf("n >= %ld\n", n + 1);		//得 n 一个区间解
	for (s = 0, k = 1; k <= n; k++)
	{
		if (k % 3 > 0)
		{
			s = s + 1.0 / k;			//从头一项项求和
		}
		else
		{
			s = s - 1.0 / k;
		}
		if (s > d)
		{
			printf("n = %ld\n", k);
		}
	}
	return 0;
}

#endif


#if 0

//解不等式：d < 1+1/2-1/3+1/4+1/5-1/6+...±/n
#include <stdio.h>

int main()
{
	long n, k;
	double d, s;
	printf("请输入正数 d :>_ ");
	scanf("%lf", &d);
	printf("%lf < 1+1/2-1/3+1/4+1/5-1/6+...±/n 的解为 :>_ \n", d);
	n = 3;
	s = 3.0 / 2;
	while (1){
		s = s - 1.0 / n + 1.0 / (n + 1) + 1.0 / (n + 2);
		if (s > d)
			break;
		n = n + 3;
	}
	printf("n = %ld\n", n + 2);			//打印第一个离散解 n+2
	k = n + 2;
	while (1)
	{
		if ((s = s - 1.0 / (++k)) > d)	break;
		if ((s = s + 1.0 / (++k)) > d)	break;
		s = s + 1.0 / (++k);
		printf("n = %ld\n", k);		//打印离散解 k
	}
	printf("n >= %ld\n", k);		//打印区间解
	return 0;
}

#endif

#if 1

//大奖赛现场统分处理程序
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, n, m, u, sh[40], ph[20];
	double a, b, c, max, min, uf, sf[40], pf[20], z[40], f[40][20];
	printf("请输入选手个数 (1<n<40) :>_ ");
	scanf("%d", &n);
	printf("请输入评委个数 (2<m<20) :>_ ");
	scanf("%d", &m);
	for (j = 1; j <= m; j++)
	{
		ph[j] = j;
	}
	for (i = 1; i <= n; i++)		//现场为选手评分，统分
	{
		printf("\n第 %d 个上场选手编号为 :>_ ", i);
		scanf("%d", &sh[i]);		//输入第 i 个上场选手的编号
		sf[i] = 0;
		max = 0;
		min = 100;
		for (j = 1; j <= m; j++)
		{
			printf("第 %d 个评委评分为 :>_ ", j);
			scanf("%lf", &f[i][j]);	//输入第 j 个评委为第 i 个选手的评分
			sf[i] += f[i][j];
			if (max < f[i][j])
			{
				max = f[i][j];		//统计最高分和最低分
			}
			if (min > f[i][j])
			{
				min = f[i][j];		//统计最高分和最低分
			}
		}
		printf("\n去掉一个最高分 :>_ %.3f", max);
		printf("\n去掉一个最低分 :>_ %.3f", min);
		sf[i] = (sf[i] - max - min) / (m - 2);	//第 i 个选手的最终得分
		a = max - sf[i];
		b = sf[i] - min;
		z[i] = (a > b )? a : b;
		printf("\n编号为 %d 号选手", sh[i]);
		printf("  最后得分为 :>_ %.3f", sf[i]);		//宣布第 i 个选手的得分
	}
	for (c = 0, i = 1; i <= n; i++)
	{
		c += z[i] * z[i];
	}
	c = sqrt(c / n);
	for (j = 1; j <= m; j++)		//给评委评分
	{
		pf[j] = 0;
		for (i = 1; i <= n; i++)
		{
			pf[j] += (f[i][j] - sf[i])*(f[i][j] - sf[i]);
		}
		pf[j] = 10.0 - sqrt(pf[j] / n) / c * 5;
		printf("\n第 %d 号评委得分为 :>_ %.3f", j, pf[j]);
	}
	for (i = 1; i <= n-1; i++)		//选手得分从高到低排序
	{
		for (j = i + 1; j <= n; j++)
		{
			if (sf[i] < sf[j])
			{
				uf = sf[i];
				sf[i] = sf[j];
				sf[j] = uf;
				u = sh[i];
				sh[i] = sh[j];
				sh[j] = u;
			}
		}
	}
	printf("\n参赛选手得分名次表");
	printf("\n选手编号    得分   名次");
	for (i = 1; i <= n; i++)
	{
		printf("\n %d  %.3f  %d", sh[i], sf[i], i);
	}
	printf("\n");
	for (j = 1; j <= m - 1; j++)
	{
		for (i = j + 1; i <= m; i++)
		{
			if (pf[j] < pf[i])
			{
				uf = pf[j];
				pf[j] = pf[i];
				pf[i] = uf;
				u = ph[j];
				ph[j] = ph[i];
				ph[i] = u;
			}
		}
	}
	printf("\n  评委得分名次表");
	printf("\n评委编号  得分  名次");
	for (j = 1; j <= m; j++)
	{
		printf("\n %d  %.3f  %d", ph[j], pf[j], j);
	}
	printf("\n\n竞赛现场统分结束，谢谢！\n");
	return 0;
}

#endif