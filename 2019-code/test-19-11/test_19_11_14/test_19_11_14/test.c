#define _CRT_SECURE_NO_WARNINGS 1


#if 0

//探索等幂和 n (n<=6) 元组
#include <stdio.h>
int main()
{
	int a1, b1, b2, n, k, m1, m, i, j, t, x, z;
	int a[20], b[20], c[20], d[20], fa[20], fb[20];
	long s1, s2, tt1[20], tt2[20], s[20];
	printf(" 输出每组数的个数 n (2<n<7)  :>_ ");
	scanf("%d", &n);
	for (a1 = 1; a1 < 19; a1++)
	{
		c[1] = a1;
		a[1] = a1;
		for (b1 = a1 + 1; b1 <= 22; b1++)
		{
			d[1] = b1;
			b[1] = b1;
			for (b2 = b1 + 1; b2 <= 25; b2++)	//取初值a(1)+a(2)=b(1)+b(2)
			{
				d[2] = b2;
				b[2] = b2;
				c[2] = d[1] + d[2] - c[1];
				a[2] = c[2];
			
			for (k = 2; k <= n - 1; k++)
			{
				m1 = a[k] + 1;
				if (b[k] > a[k])
				{
					m1 = b[k] + 1;
				}
				for (m = m1; m <= 3 * m1; m++)			//m在约定的循环中取值
				{
					for (i = 1; i <= k; i++)
					{
						a[i] = c[i];
						b[i] = d[i];
					}
					if (0 == k % 2)						//k为偶数按式（2）赋值
					{
						for (i = 1; i <= k; i++)
						{
							a[k + i] = m - b[i];
							b[k + i] = m - a[i];
						}
					}
					else							//k为奇数按式（1）赋值
					{
						for (i = 1; i <= k; i++)
						{
							a[k + i] = m - a[i];
							b[k + i] = m - b[i];
						}
					}
					t = 0;
					for (i = 1; i <= 2 * k; i++)
					{
						for (j = 1; j <= 2 * k; j++)
						{
							if (a[i] == b[j] && a[i] > 0)	//比较两数组，相同的非零项赋0
							{
								a[i] = 0;
								b[j] = 0;
								t = t + 1;
								break;
							}
						}
					}
					if (t != k - 1)
						continue;
					for (i = 1; i <= 2 * k - 1; i++)		//两数组分别由小到大排序
					{
						for (j = 1; j <= 2 * k; j++)
						{
							if (a[i] > a[j])
							{
								x = a[i];
								a[i] = a[j];
								a[j] = x;
							}
							if (b[i] > b[j])
							{
								x = b[i];
								b[i] = b[j];
								b[j] = x;
							}
						}
					}
					for (i = 1; i <= k + 1; i++)
					{
						a[i] = a[i + t];
						b[i] = b[i + t];		//重新赋值，去除两数组中的零项
					}
					for (i = 1; i <= k; i++)
					{
						if (z = 0, a[i] == a[i + 1] || b[i] == b[i + 1])		//同数组中有相同项返回
						{
							z = 1;
							break;
						}
					}
					if (z == 1)
						continue;
					for (i = 1; i <= k + 1; i++)
					{
						c[i] = a[i];
						d[i] = b[i];
					}
					m = 3 * m1;
				}

			}
			if (k != n)
				continue;
			for (i = 1; i <= n; i++)
			{
				tt1[i] = 1;
				tt2[i] = 1;
			}
			for (i = 1; i <= n; i++)
			{
				fa[i] = a[i];
				fb[i] = b[i];
			}
			for (k = 1; k <= n - 1; k++)
			{
				for (s1 = 0, s2 = 0, i = 1; i <= n; i++)		//验证两组各方幂和是否相等
				{
					tt1[i] = tt1[i] * fa[i];
					tt2[i] = tt2[i] * fb[i];
					s1 = s1 + tt1[i];
					s2 = s2 + tt2[i];
				}
				z = 0;
				if (s1 != s2)
				{
					z = 1;
					break;
				}
				s[k] = s1;
			}
			if (1 == z)
				continue;
			printf("\n 第 1 组 %d 个数为: ", n);
			for (i = 1; i <= n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n 第 2 组 %d 个数为: ", n);
			for (i = 1; i <= n; i++)
			{
				printf("%d ", b[i]);
			}
			for (k = 1; k <= n - 1; k++)
			{
				printf("\n %d 次方和都是: %ld", k, s[k]);
				printf("\n");
				if (0 == z)
					break;
			}
			if (0 == z)
				break;
		}
		if (0 == z)
			break;
	}

	return 0;
}

#endif

#if 1

#endif