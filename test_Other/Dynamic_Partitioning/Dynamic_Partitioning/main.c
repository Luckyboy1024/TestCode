#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10



void assign(Partition* arr, int size)
{
	int input = 0;
	do{
		printf("请选择 :>_ 1. 最适应  2. 循环最适应  3. 最佳适应  4. 最坏适应  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			//最适应算法
		}
		else if (2 == input)
		{
			//循环最适应
		}
		else if (3 == input)
		{
			//最佳适应算法
		}
		else if (4 == input)
		{
			//最坏适应算法
		}
		else
		{
			return 0;
		}
	} while (input);
}

void recycle(Partition* arr, int size)
{
	int pathaddr = 0;
	Print_List(arr, size);
	printf("输入所要回收分区的始址 :>_ ");
	scanf("%d", &pathaddr);
}


void choose(Partition* arr, int size)
{
	int input = 0;
	do{
		printf("请选择 :>_   1. 分配空间   2. 空间回收   0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			assign(arr, size);
		}
		else if (2 == input)
		{
			recycle(arr, size);
		}
		else
		{
			return 0;
		}
	} while (input);
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
		printf("\t分区大小 :>_ "); scanf("%d", &P_list[i-1].Partition_size);
		printf("\t分区始址 :>_ "); scanf("%d", &P_list[i-1].init_addr);
	}
	Print_List(P_list, P_num);
	choose(P_list, P_num);
	Print_List(P_list, P_num);


}

int main()
{
	start();
	return 0;
}

