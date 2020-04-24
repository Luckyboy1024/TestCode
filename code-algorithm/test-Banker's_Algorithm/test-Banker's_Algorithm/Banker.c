#define _CRT_SECURE_NO_WARNINGS 1

#include "Banker.h"
#include "Safety.h"



void Banker_Algorithm(char** name)
{
	int i = 0;
	int m = 0;
	Print_All(name);
	Safe_Algorithm(name);
	while (1){
		printf("����Ҫ�������Դ�Ľ��̺� (���� 0 ����):>_ \n");
		scanf("%d", &m); m--;
		if (-1 == m){
			break;
		}
		printf("����ý���������ĸ�����Դ������  [");
		for (i = 0; i < num_resource; ++i)
		{
			printf("%4s", name[i]);
		}
		printf("] :>_ ");
		for (i = 0; i < num_resource; ++i)
		{
			scanf("%d", &Request[m][i]);
		}

		for (i = 0; i < num_resource; ++i)
		{
			if (Request[m][i] > Need[m][i])
			{
				printf("��������Դ���������̵�������������ʧ�ܣ��������䣡��\n");
				continue;
			}
			if (Request[m][i] > Available[i])
			{
				printf("��������Դ������ϵͳ��ǰ������Դ��������ʧ�ܣ��������䣡��\n");
				continue;
			}
		}
		for (i = 0; i < num_resource; i++)
		{
			Available[i] -= Request[m][i];
			Allocation[m][i] += Request[m][i];
			Need[m][i] -= Request[m][i];
		}
		if (Safe_Algorithm(name))
		{
			printf("ͬ���������\n");
		}
		else{
			printf("SORRY ������󱻾ܾ�\n");
			for (i = 0; i < num_resource; ++i)
			{
				Available[i] += Request[m][i];
				Allocation[m][i] -= Request[m][i];
				Need[m][i] += Request[m][i];
			}
		}
		for (i = 0; i < num_course; ++i)
		{
			Finish[i] = 0;
		}
	}
}