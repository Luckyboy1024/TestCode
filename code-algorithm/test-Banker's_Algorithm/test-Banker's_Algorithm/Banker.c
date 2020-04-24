#define _CRT_SECURE_NO_WARNINGS 1

#include "Banker.h"
#include "Safety.h"



void Banker_Algorithm(char** name)
{
	int i = 0;
	int m = 0;
	Print_All(name);
	Safe_Algorithm(name);
	while (1){
		printf("输入要申请的资源的进程号 (输入 0 返回):>_ \n");
		scanf("%d", &m); m--;
		if (-1 == m){
			break;
		}
		printf("输入该进程所请求的各个资源的数量  [");
		for (i = 0; i < num_resource; ++i)
		{
			printf("%4s", name[i]);
		}
		printf("] :>_ ");
		for (i = 0; i < num_resource; ++i)
		{
			scanf("%d", &Request[m][i]);
		}

		for (i = 0; i < num_resource; ++i)
		{
			if (Request[m][i] > Need[m][i])
			{
				printf("所请求资源数超过进程的需求量，请求失败！！请重输！！\n");
				continue;
			}
			if (Request[m][i] > Available[i])
			{
				printf("所请求资源数超过系统当前空闲资源数，请求失败！！请重输！！\n");
				continue;
			}
		}
		for (i = 0; i < num_resource; i++)
		{
			Available[i] -= Request[m][i];
			Allocation[m][i] += Request[m][i];
			Need[m][i] -= Request[m][i];
		}
		if (Safe_Algorithm(name))
		{
			printf("同意分配请求\n");
		}
		else{
			printf("SORRY 你的请求被拒绝\n");
			for (i = 0; i < num_resource; ++i)
			{
				Available[i] += Request[m][i];
				Allocation[m][i] -= Request[m][i];
				Need[m][i] += Request[m][i];
			}
		}
		for (i = 0; i < num_course; ++i)
		{
			Finish[i] = 0;
		}
	}
}