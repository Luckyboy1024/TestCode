#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//29尺长 7 刻度探索
#include <stdio.h>

int main()
{
	int c, d, j, k, s, t, u, a[9], b[37];
	printf(" 7 刻度分29尺长为8段，段长序列为：\n");
	s = 29;
	a[0] = 0;
	a[1] = 1;
	a[8] = s;
	c = 0;
	for (a[2] = 2; a[2] <= s - 6; a[2]++)
	{
		for (a[3] = a[2] + 1; a[3] <= s - 5; a[3]++)
		{
			for (a[4] = a[3] + 1; a[4] <= s - 4; a[4]++)
			{
				for (a[5] = a[4] + 1; a[5] <= s - 3; a[5]++)
				{
					for (a[6] = a[5] + 1; a[6] <= s - 2; a[6]++)
					{
						for (a[7] = a[6] + 1; a[7] <= s - 1; a[7]++)
						{
							for (t = 0, k = 0; k <= 7; k++)
							{
								for (j = k + 1; j <= 8; j++)
								{
									t++;
									b[t] = a[j] - a[k];		//序列部分和赋值给b数组
								}
							}
							for (u = 0, d = 1; d <= s; d++)
							{
								for (k = 1; k <= 36; k++)
								{
									if (d == b[k])
									{
										u += 1;
										k = 36;			//检验 b 数组取 1~s 有多少个
									}
								}
							}
							if (u == s)		//b数组包括 1~s 所有整数
							{
								if ((a[7] != s - 1) || (a[7] == s - 1) && (a[2] <= s - a[6]))
								{
									c++;
									printf("  NO%d :>_ ", c);		//输出解的段长序列
									for (k = 1; k <= 7; k++)
									{
										printf("%2d, ", a[k] - a[k - 1]);
									}
									printf("%2d \n", s - a[7]);
								}
							}
						}
					}
				}
			}
		}
	}
	if (c > 0)
	{
		printf("共有以上%d个解。\n", c);		//输出解的个数
	}
	return 0;
}

#endif

#if 0
// 寻求尺长 s,n 条刻度分布回溯探索
#include <stdio.h>

int main()
{
	int d, i, j, k, t, u, s, m, n, a[30], b[300];
	printf("  尺长 s，寻求 n 条刻度分布，请确定 s,n :>_ ");
	scanf("%d%d", &s, &n);
	a[0] = 0;
	a[1] = 1;
	a[n + 1] = s;
	m = (n + 2)*(n + 1) / 2;
	i = 2;
	a[i] = 2;
	while (1)
	{
		if (i < n)
		{
			i++;
			a[i] = a[i - 1] + 1;
			continue;
		}
		else
		{
			for (t = 0, k = 0; k <= n; k++)
			{
				for (j = k + 1; j <= n + 1; j++)
				{
					t++;
					b[t] = a[j] - a[k];		//序列部分和赋值给 b 数组
				}
			}
			for (u = 0, d = 1; d <= s; d++)
			{
				for (k = 1; k <= m; k++)
				{
					if (b[k] == d)
					{
						u += 1;
						k = m;		// 检验 b 数组取 1~s 有多少个
					}
				}
			}
			if (u == s)				// b 数组值包括 1~s 所有整数
			{
				if ((a[n] != s - 1) || (a[n] == s - 1) && (a[2] <= s - a[n - 1]))
				{
					printf("┌");
					for (k = 1; k <= s - 1; k++)
					{
						printf("—");
					}
					printf("-┐\n");
					printf("│ ");
					for (k = 1; k <= n + 1; k++)		//输出尺的数字标注
					{
						for (j = 1; j <= a[k] - a[k - 1] - 1; j++)
						{
							printf("  ");
						}
						if (k < n + 1)
						{
							printf("%2d", a[k]);
						}
						else
						{
							printf("│\n");
						}
					}
					printf("└");			//输出尺的下边和刻度
					for (k = 1; k <= n + 1; k++)
					{
						for (j = 1; j <= a[k] - a[k - 1]-1 ; j++)
						{
							printf("—");
						}
						if (k < n + 1)
						{
							printf("-┴");
						}
						else
						{
							printf("-┘\n");
						}
					}
					printf("  直尺%d段的段长序列为 :>_ ", n + 1);		// 输出段长序列
					for (k = 1; k <= n; k++)
					{
						printf("%2d, ", a[k] - a[k - 1]);
					}
					printf("%2d\n", s - a[n]);
				}
			}
		}
		while (a[i] == s - (n + 1) + i && i > 1)
		{
			i--;			//调整或回溯
		}
		if (i > 1)
		{
			a[i]++;
		}
		else
		{
			break;
		}
	}
	return 0;
}

#endif


