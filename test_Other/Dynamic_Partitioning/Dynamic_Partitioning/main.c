#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10


void P_ListInit(Partition* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i].init_addr = 0;			// ʼַΪ 0
		arr[i].Partition_size = 0;		// ��СΪ 0
		arr[i].state = 'T';				// �ѷ���
	}
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
		printf("\t������С :>_ "); scanf("%d", &P_list[i-1]);
		printf("\t����ʼַ :>_ "); scanf("%d", &P_list[i-1]);
	}
	

}

int main()
{
	start();
	return 0;
}

