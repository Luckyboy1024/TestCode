#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"
#include "Queue.h"

void Swap(Process* arr1, Process* arr2)
{
	Process* tmp = arr1;
	arr1 = arr2; 
	arr2 = tmp;
}
void BubbleSort(Process *arr, int n)
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
	BubbleSort(arr, n);
}

void _SJF(Process *arr, int n)
{

}

void _RR(Process *arr, int n)
{
	Queue* Q;
	BubbleSort(arr, n);
	QueuePush(Q, arr + 0);

}

int menu(Process *arr, int n)
{
	int input = 0;
	printf("\n  |  1.FCFS  |  2.SJF  |  3.RR  |  0.exit  |   choose :>_ ");
	scanf("%d", &input);
	if (0 == input)
	{
		return 0;
	}
	else if (1==input)
	{
		_FCFS(arr, n);
		return 1;
	}
	else if (2 == input)
	{
		_SJF(arr, n);
		return 1;
	}
	else if (3 == input)
	{
		_RR(arr, n);
		return 1;
	}
	return 0;
}

void _input(int n, Process* arr)
{
	for (int i = 0; i < n; ++i)
	{
		printf("第 %d 个进程\n", i + 1);
		printf("\t进  程  名   :>_ "); scanf("%s", &arr[i].name);
		printf("\t进程到达时间 :>_ "); scanf("%d", &arr[i].time_reach);
		printf("\t进程服务时间 :>_ "); scanf("%d", &arr[i].time_serve);
		arr[i].num = i;
	}
}

void _print(Process* arr, int n)
{
	printf(" PName  ATime  STime  FTime  TTime  QTTime\n");
	for (int i = 0; i < n; ++i)
	{
		printf("  %-4s  %5d  %5d  %5d  %5d  %5d\n", arr[i].name, 
			arr[i].time_reach, arr[i].time_serve,
			arr[i].data._FT, arr[i].data._TT, arr[i].data._QTT);
	}
}

int main()
{
	Process arr[_NUM];
	int input = 0;
	printf("进程数目 :>_ ");
	scanf("%d", &input);
	_input(input, arr);
	_print(arr, input);
	while (menu(arr, input));
	return 0;
}


