#define _CRT_SECURE_NO_WARNINGS 1

#include "Process_scheduling.h"

void RR_HeadPush(Process* arr, int size)		//��ͷ�Ƶ���β
{
	Process tmp = arr[0];
	for (int i = 1; i < size; ++i)
	{
		arr[i - 1] = arr[i];
	}
	arr[size - 1] = tmp;
}

void RR_Push(Process* arr, Process*src, int size)		//�����β
{
	arr[size] = *src;
}

void RR_Pop(Process* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		arr[i - 1] = arr[i];
	}
	InitProcess(&arr[size - 1]);
}