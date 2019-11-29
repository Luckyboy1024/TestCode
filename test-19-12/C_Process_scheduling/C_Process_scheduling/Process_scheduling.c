#define _CRT_SECURE_NO_WARNINGS 1

#include "Process_scheduling.h"

void Swap(Process* arr1, Process* arr2)
{
	Process tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

// 按进程号排序
void PN_BubbleSort(Process *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n - i; ++j)
		{
			if (arr[j - 1].num > arr[j].num)
				Swap(&(arr[j - 1]), &(arr[j]));
		}
	}
}

// 按服务时间排序
void ST_BubbleSort(Process *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n - i; ++j)
		{
			if (arr[j - 1].time_serve > arr[j].time_serve)
				Swap(&arr[j - 1], &arr[j]);
		}
	}
}

// 按到达时间排序
void RT_BubbleSort(Process *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n - i; ++j)
		{
			if (arr[j - 1].time_reach > arr[j].time_reach)
					Swap(&arr[j - 1], &arr[j]);
		}
	}
}

void _FCFS(Process *arr, int n)
{
	RT_BubbleSort(arr, n);
	arr[0].data._FT = arr[0].time_reach + arr[0].time_serve;
	arr[0].data._TT = arr[0].time_serve;
	arr[0].data._QTT = arr[0].data._TT / arr[0].time_serve;

	for (int i = 1; i < n; i++)
	{
		if (arr[i].time_reach > arr[i - 1].data._FT)
		{
			arr[i].data._FT = arr[i].time_reach + arr[i].time_serve;
		}
		else
		{
			arr[i].data._FT = arr[i-1].data._FT + arr[i].time_serve;
		}
		arr[i].data._TT = arr[i].data._FT - arr[i].time_reach;
		arr[i].data._QTT = arr[i].data._TT / arr[i].time_serve;
	}
}

void _SJF(Process *arr, int n)
{

}

void _RR(Process *arr, int n)
{
//	Queue* Q;
//	BubbleSort(arr, n);
//	QueuePush(Q, arr + 0);

}