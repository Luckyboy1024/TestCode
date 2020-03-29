#define _CRT_SECURE_NO_WARNINGS 1

#include "Dynamic_Partition.h"

void Sort_Addr(Partition* arr, int size)
{
	for (int j = 0; j < size; ++j)
	{
		for (int i = 1; i < size - j; ++i)
		{
			if (arr[i].init_addr < arr[i - 1].init_addr)
			{
				Partition tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
			}
		}
	}
}


void R_Sort_Size(Partition* arr, int size)		// 按分区大小排序 反向
{
	for (int j = 0; j < size; ++j)
	{
		for (int i = 1; i < size - j; ++i)
		{
			if (arr[i].Partition_size < arr[i - 1].Partition_size)
			{
				Partition tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
			}
		}
	}
}

void Sort_Size(Partition* arr, int size)		// 按分区大小排序
{
	for (int j = 0; j < size; ++j)
	{
		for (int i = 1; i < size - j; ++i)
		{
			if (arr[i].Partition_size < arr[i - 1].Partition_size)
			{
				Partition tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
			}
		}
	}
}

void Print_List(Partition* arr, int size)
{
	printf("+-----------------------------------------------+\n");
	printf("|区号| 分区大小 | 分区始址 | 状 态 |  分区区间  | \n");
	printf("+-----------------------------------------------+\n");
	for (int i = 0; i < size; ++i)
	{
		printf("|%2d  |", i+1);
		printf("%7d   |", arr[i].Partition_size);
		printf("%7d   |", arr[i].init_addr);
		printf("%4c   |", arr[i].state);
		printf(" %-3d -- %3d |\n", arr[i].init_addr, arr[i].init_addr + arr[i].Partition_size-1);
	}
	printf("+-----------------------------------------------+\n");
}


void P_ListInit(Partition* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i].init_addr = 0;			// 始址为 0
		arr[i].Partition_size = 1;		// 大小为 0
		arr[i].state = 'T';				// 已分配
	}
}