#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "main.h"
int m;		//��ҵ
int n;		//��Դ


int test()
{
	int i, j, mi;
	printf("�����������Ŀ :>_\n");
	scanf("%d", &m);
	printf("��������Դ��Ŀ :>_\n");
	scanf("%d", &n);
	printf("����ÿ�����̶���Դ�����������������%d*%d��������\n", m, n);
	for (i = 0; i < m; i++){
		for (j = 0; j < n; ++j){
			scanf("%d%d", &Max[i][j]);
			printf("����ÿ��������Դ��Ŀǰռ����������%d*%d��������\n", m, n);
		}
	}
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0){
				printf("������ĵ� %d ��������ӵ�еĵ� %d ����Դ�������������� :>_\n", i + 1, j + 1);
				--j;
				continue;
			}
		}
	}
	printf("������ϵͳʣ����Դ�� :>_\n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &Available[i]);
		Safe();
		while (1){
			printf("����Ҫ�������Դ�Ľ��̺� :>_ (��һ�����̺�Ϊ 0���ڶ������̺�Ϊ 1���Դ�����)\n");
			scanf("%d", &mi);
			printf("�������������ĸ�����Դ������\n");
			for (i = 0; i < n; ++i)
			{
				if (Request[mi][i] > Need[mi][i])
				{
					printf("��������Դ���������̵�������\n");
					return 0;
				}
				if (Request[mi][i] > Available[i])
				{
					printf("��������Դ������ϵͳ���е���Դ��\n");
					return 0;
				}
			}
			for (i = 0; i < n; i++)
			{
				Available[i] -= Request[mi][i];
				Allocation[mi][i] += Request[mi][i];
				Need[mi][i] -= Request[mi][i];
			}
			if (Safe())
			{
				printf("ͬ���������\n");
			}
			else{
				printf("SORRY ������󱻾ܾ�\n");
				for (i = 0; i < n; ++i)
				{
					Available[i] += Request[mi][i];
					Allocation[mi][i] -= Request[mi][i];
					Need[mi][i] += Request[mi][i];
				}
			}
			for (i = 0; i < m; ++i)
			{
				Finish[i] = 0;
			}

			char Flag;
			printf("�Ƿ��ٴ�������䣿y/n");
			while (1){
				scanf("%d", &Flag);
				if (Flag == 'n')
					break;
				else if (Flag == 'y')
					break;
				else
					printf("*******error*******");
			}
		}
	}
}


#endif