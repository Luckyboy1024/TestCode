#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "main.h"
int m;		//作业
int n;		//资源


int test()
{
	int i, j, mi;
	printf("请输入进程数目 :>_\n");
	scanf("%d", &m);
	printf("请输入资源数目 :>_\n");
	scanf("%d", &n);
	printf("输入每个进程对资源的最大需求量，按照%d*%d矩阵输入\n", m, n);
	for (i = 0; i < m; i++){
		for (j = 0; j < n; ++j){
			scanf("%d%d", &Max[i][j]);
			printf("输入每个进程资源的目前占有量，按照%d*%d矩阵输入\n", m, n);
		}
	}
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0){
				printf("你输入的第 %d 个进程所拥有的第 %d 个资源错误，请重新输入 :>_\n", i + 1, j + 1);
				--j;
				continue;
			}
		}
	}
	printf("请输入系统剩余资源量 :>_\n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &Available[i]);
		Safe();
		while (1){
			printf("输入要申请的资源的进程号 :>_ (第一个进程号为 0，第二个进程号为 1，以此类推)\n");
			scanf("%d", &mi);
			printf("输入进程所请求的各个资源的数量\n");
			for (i = 0; i < n; ++i)
			{
				if (Request[mi][i] > Need[mi][i])
				{
					printf("所请求资源数超过进程的需求量\n");
					return 0;
				}
				if (Request[mi][i] > Available[i])
				{
					printf("所请求资源数超过系统所有的资源数\n");
					return 0;
				}
			}
			for (i = 0; i < n; i++)
			{
				Available[i] -= Request[mi][i];
				Allocation[mi][i] += Request[mi][i];
				Need[mi][i] -= Request[mi][i];
			}
			if (Safe())
			{
				printf("同意分配请求\n");
			}
			else{
				printf("SORRY 你的请求被拒绝\n");
				for (i = 0; i < n; ++i)
				{
					Available[i] += Request[mi][i];
					Allocation[mi][i] -= Request[mi][i];
					Need[mi][i] += Request[mi][i];
				}
			}
			for (i = 0; i < m; ++i)
			{
				Finish[i] = 0;
			}

			char Flag;
			printf("是否再次请求分配？y/n");
			while (1){
				scanf("%d", &Flag);
				if (Flag == 'n')
					break;
				else if (Flag == 'y')
					break;
				else
					printf("*******error*******");
			}
		}
	}
}


#endif