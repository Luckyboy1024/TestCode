#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

int main()
{
	return 0;
}

#if 0

// 指针…
int len = strlen(a);
char *p = (char *)malloc(sizeof(char)*(len+1));
strcpy(p, a);		//不要用 p = a;
if(0 == strcmp(p, a))	//不要用 if (p == a)
…

// 数组…
char a[] = "hello";
char b[10];
strcpy(b, a);		//不能用  b = a;
if(0 == strcpy(b, a))	//不能用 if(b == a)
…

// 数组… 
char a[] = "hello"; 
char b[10]; 
strcpy(b, a);  // 不能用 b = a; 
if(strcmp(b, a) == 0) // 不能用    if (b == a) 
…

int main()
{
	long int money = 0;
	scanf("%d", &money);
	printf("平均每月产生利息 %lf \n", (money * 10000 * 0.03) / 12);
	printf("平均每天产生利息 %lf \n", (money * 10000 * 0.03) / 365);
	return 0;
}

char a[] = “hello”; 
a[0] = ‘X’; 
cout << a << endl; 
char *p = “world”;     // 注意p指向常量字符串 
p[0] = ‘X’;            // 编译器不能发现该错误 
cout << p << endl;

//搜索 n 位兰德尔数
#include <stdio.h>
#include <math.h>

int main()
{
	int m, n, i;
	double f, k, s, t, y;
	printf(" 请输入位数 n (2<n<10) :>_ ");
	scanf("%d", &n);
	m = 0;
	t = 1;
	for (i = 1; i <= n - 1; i++)
	{
		t = t * 10;
	}
	for (y = t; y <= t * 10 - 1; y++)		//枚举 n 位整数
	{
		f = y;
		for (s = 0, i = 1; i <= n; i++)		//循环分离 y 的 n 个数字 k 
		{
			k = fmod(f, 10);
			s += pow(k, n);
			f = floor(f / 10);		//求 y 的 n 个数字的 n 次幂之和 s
		}
		if (y == s)					//检测是否满足条件
		{
			m++;
			printf(" %.0f ", y);		//输出探索结果
		}
	}
	printf("\n %d 位兰德尔数共 %d 个\n", n, m);
	return 0;
}

int main()
{
	int i = 0;
	if (i == 0)
	{
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#define M 13361
FILE *fp;
int main()
{
	char cy[M][10];
	char a[8];
	//char b[2];
	char c[2];
	int i, j;
	int find;
	int flag = 0;
	if ((fp = fopen("idom.txt", "r")) == NULL)
	{
		printf("cannot open file\n");
		return 0;
	}

	for (i = 0; i<M; i++)
	{
		fscanf(fp, "%s", cy[i]);
	}
	while (1)
	{

		printf("请输入开头的成语：（若输入“退出”，则退出游戏）\n");
		scanf("%s", &a);
		find = 0;
		if (strcmp(a, "退出") == 0)
			break;
		for (i = 0; i<M; i++)
		{
			if (strncmp(a, cy[i], strlen(a)) == 0)
			{
				find = 1;
				break;
			}
		}
		if (find == 0)
			printf("输入的不是成语，请重新输入或退出\n");
		else
		{
			//b[0]=a[6];
			//	b[1]=a[7];
			for (i = 0; i<M; i++)
			{
				if (cy[i][0] == a[6] && cy[i][1] == a[7])

				{
					flag = 1;
					printf("%s\n", cy[i]);
					//c[0]=cy[i][6];
					//c[1]=cy[i][7];
					break;
				}
				if (flag == 0 && i == (M - 1))
				{
					printf("你赢了！真棒！\n");
					break;
				}
				//	continue;

			}
		}
	}
	return 0;
}

#endif