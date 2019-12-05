#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10



void assign(Partition* arr, int size)
{
	int input = 0;
	do{
		printf("��ѡ�� :>_ 1. ����Ӧ  2. ѭ������Ӧ  3. �����Ӧ  4. ���Ӧ  0.exit\n");
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
		else if (4 == input)
		{
			//���Ӧ�㷨
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
	printf("������Ҫ���շ�����ʼַ :>_ ");
	scanf("%d", &pathaddr);
}


void choose(Partition* arr, int size)
{
	int input = 0;
	do{
		printf("��ѡ�� :>_   1. ����ռ�   2. �ռ����   0.exit\n");
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
	Partition P_list[_NUM];		//��̬������
	Partition DP_list[_NUM];	//���з�����
	
	uint64_t P_num = 0;			//���з�������
	uint64_t DP_num = 0;		//���з�������

	printf("������з����� :>>\n\n");
	printf("������з������� :>_ ");
	scanf("%d", &P_num);
	P_ListInit(P_list, P_num);
	Print_List(P_list, P_num);
	for (int i = 1; i <= P_num; ++i)
	{
		printf("������ :>_ %d\n", i);
		printf("\t������С :>_ "); scanf("%d", &P_list[i-1].Partition_size);
		printf("\t����ʼַ :>_ "); scanf("%d", &P_list[i-1].init_addr);
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

