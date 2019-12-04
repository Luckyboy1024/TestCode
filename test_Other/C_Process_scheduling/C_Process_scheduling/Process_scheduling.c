#define _CRT_SECURE_NO_WARNINGS 1

#include "Process_scheduling.h"
#include "Queue.h"

void Swap(Process* arr1, Process* arr2)
{
	Process tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

// �����̺�����
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

// ������ʱ������
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

// ������ʱ������
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
	int tag = 0;
	int i = 0;
	int j = 0;
	RT_BubbleSort(arr, n);
	arr[0].data._FT = arr[0].time_reach + arr[0].time_serve;
	arr[0].data._TT = arr[0].time_serve;
	arr[0].data._QTT = arr[0].data._TT / arr[0].time_serve;

	for (i = 1; i < n; i++)
	{
		// �ж���ǰһ�������֮ǰ,����Щ�����ѵ���
		for (j = i; (j < n) && (tag == 0); j++)
		{
			if (arr[j].time_reach > arr[j - 1].data._FT)
			{
				if (!(j > i+1))	//i==j��ʾһ����û�� i= j-1ֻ��һ����Ҳ���÷�������
				{
					break;
				}
				//�� i ~ j-1 ��Ľ��̰�����ʱ������
				ST_BubbleSort(&arr[i], j - i);
				break;
			}
		}
		// ���ʣ��ȫ�����̶��ѵ������Ǳ���tag��1
		if (j == n)
		{
			ST_BubbleSort(&arr[i], j - i);
			tag = 1;
		}

		// arr[i] ���Ǵ�ʱ����ʱ����̵Ľ���
		if (i == j)
		{
			arr[i].data._FT = arr[i].time_reach + arr[i].time_serve;
		}
		else
		{
			arr[i].data._FT = arr[i - 1].data._FT + arr[i].time_serve;
		}
		arr[i].data._TT = arr[i].data._FT - arr[i].time_reach;
		arr[i].data._QTT = arr[i].data._TT / arr[i].time_serve;
	}
}

void _RR(Process *arr, int n)
{
	int slot = 0;		//ʱ��Ƭ
	int time = 0;
	Queue* q;
	//Process* a = NULL;
	printf("\n����ʱ��Ƭ :>_ ");
	scanf("%d", &slot);
//	Queue* Q;
//	BubbleSort(arr, n);
//	QueuePush(Q, arr + 0);

}