#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10


void P_ListInit(Partition* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i].init_addr = 0;			// 始址为 0
		arr[i].Partition_size = 0;		// 大小为 0
		arr[i].state = 'T';				// 已分配
	}
}

void start()
{
	Partition P_list[_NUM];		//动态分区表
	Partition DP_list[_NUM];	//空闲分区表
	
	uint64_t P_num = 0;			//现有分区个数
	uint64_t DP_num = 0;		//空闲分区个数

	printf("输入空闲分区表 :>>\n\n");
	printf("输入空闲分区个数 :>_ ");
	scanf("%d", &P_num);
	P_ListInit(P_list, P_num);
	Print_List(P_list, P_num);
	for (int i = 1; i <= P_num; ++i)
	{
		printf("分区号 :>_ %d\n", i);
		printf("\t分区大小 :>_ "); scanf("%d", &P_list[i-1]);
		printf("\t分区始址 :>_ "); scanf("%d", &P_list[i-1]);
	}
	

}

int main()
{
	start();
	return 0;
}

