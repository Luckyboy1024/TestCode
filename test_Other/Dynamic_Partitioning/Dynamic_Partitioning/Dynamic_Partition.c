#define _CRT_SECURE_NO_WARNINGS 1

#include "Dynamic_Partition.h"


void Print_List(Partition* arr, int size)
{
	printf("--------------------------------\n");
	printf("|����| ������С | ����ʼַ | ״̬ |\n");
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
		printf("��ѡ�� :>_ 1. ����Ӧ  2. ѭ������Ӧ  3. �����Ӧ  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
					//����Ӧ�㷨
		}
		else if (2 == input)
		{
					//ѭ������Ӧ
		}
		else if (3 == input)
		{
					//�����Ӧ�㷨
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
		printf("��ѡ�� :>_   1. ����ռ�   2. �ռ����   0.exit\n");
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


