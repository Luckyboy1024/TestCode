#define _CRT_SECURE_NO_WARNINGS 1

#include "main.h"
#include "Process_scheduling.h"
#include "Queue.h"

void InitProcess(Process* p)
{
	p->time_reach = 0.0;
	p->time_serve = 0.0;
	p->data._FT = 0.0;
	p->data._QTT = 0.0;
	p->data._TT = 0.0;
}

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
	Process List[_NUM];			//��ת���С��ȴ�����
	int slot = 0;				//ʱ��Ƭ
	int time = 0;				//��ǰʱ��
	int a = 0;					// arr  �� a==n ʱ arr[a-1]���һ��Ԫ��
	int b = 0;					// List ����Ԫ�ظ���
	int tag = -1;
	printf("\n����ʱ��Ƭ :>_ ");
	scanf("%d", &slot);
	RT_BubbleSort(arr, n);
	
	time = arr[0].time_reach - slot;

	for (a = 0; a < n; ++a)
	{
		time += slot;
		// timeʱ�����½��̵���
		if (time >= arr[a].time_reach)
		{
			//����ȴ����ж�β
			RR_Push(List, arr, b);
			b++;
		}
		if (-1 == tag)
		{
			//do nothing;
		}
		else if (0 == tag)
		{
			// ��ͷԪ�طŶ�β
			RR_HeadPush(List, b);
		}
		else if (1 == tag)
		{
			// pop ��Ԫ��
			RR_Pop(List, b);
		}
		// �ȴ������п�
		if (!empty(List))	//��Ϊ��
		{
			// ��ͷִ��
			
			// 
			if (List[0].time_serve <= slot)
			{
				time += List[0].time_serve;
				List[0].data._FT = time;
				tag = 1;
			}
			else
			{
				List[0].time_serve -= slot;
				tag = 0;
			}
			break;
		}
		if (n == a)		// ��������
		{
			return 0;
		}

	}
	for (int i = 0; i < n; ++i)
	{
		arr[i].data._TT = arr[i].data._FT - arr[i].time_reach;
		arr[i].data._QTT = arr[i].data._TT / arr[i].time_serve;
	}
}


#if 0

//Queue* q;
//Process* a = NULL;

//	Queue* Q;
//	BubbleSort(arr, n);
//	QueuePush(Q, arr + 0);


#endif