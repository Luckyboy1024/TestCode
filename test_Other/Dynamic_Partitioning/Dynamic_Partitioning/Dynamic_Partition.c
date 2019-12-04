#define _CRT_SECURE_NO_WARNINGS 1

#include "Dynamic_Partition.h"


void Print_List(Partition* arr, int size)
{
	printf("--------------------------------\n");
	printf("|区号| 分区大小 | 分区始址 | 状态 |\n");
	printf("--------------------------------\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%5d |%5d | %5d | %s\n", i + 1, arr[i].Partition_size, arr[i].init_addr, arr[i].state);
	}
	printf("--------------------------------\n");
}

void f()
{
	int input = 0;
	do{
		printf("请选择 :>_ 1. 最适应  2. 循环最适应  3. 最佳适应  0.exit\n");
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
		else
		{
			return 0;
		}
	} while (input);
}



void choose()
{
	int input = 0;
	do{
		printf("请选择 :>_   1. 分配空间   2. 空间回收   0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			f();
		}
		else if (2 == input)
		{
			f2();
		}
		else
		{
			return 0;
		}
	} while (input);
}


