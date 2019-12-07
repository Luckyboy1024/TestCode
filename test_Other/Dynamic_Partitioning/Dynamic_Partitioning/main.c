#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10		//���з���������ֵ
#define _G	2		//���� G,���������ʣ�ಿ�ִ�С��С��G
#define _length	256	//�ڴ��С

int fun(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num,int need_len)
{
	int t = 0;
	for (int i = 0; i < DP_num; ++i)
	{
		if ((t = DP_list[i].Partition_size - need_len) >= 0)
		{
			if (t < _G)
			{
				//�ܱ�����ӦԪ�ؿ�״̬�ı�
				for (int j = 0; j < P_num; ++j)
				{
					if (P_list[j].init_addr == DP_list[i].init_addr)
					{
						P_list[j].state = 'F';
						break;
					}
				}
				//���з�����ȥ��һ��Ԫ��
				for (; i < DP_num; ++i)
				{
					DP_list[i] = DP_list[i + 1];
				}
				DP_num--;
			}
			else
			{
				//�ܷ���������һ��Ԫ�ز�ˢ��
				for (int j = 0; j < P_num; ++j)
				{
					if (P_list[j].init_addr == DP_list[i].init_addr)
					{
						P_list[P_num].init_addr = DP_list[i].init_addr;
						P_list[P_num].Partition_size = need_len;
						P_list[P_num].state = 'F';
						P_list[j].init_addr += need_len;
						P_list[j].Partition_size -= need_len;
						break;
					}
				}
				//���з�����ˢ��
				DP_list[i].init_addr += need_len;
				DP_list[i].Partition_size -= need_len;
			}
			return 1;
		}
	}
	return 0;
}

int fun_cir(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num, int need_len, int t, int i, int A)		//ѭ������Ӧ
{
	if ((t = DP_list[i].Partition_size - need_len) >= 0)
	{
		if (t < _G)
		{
			A = i - 1;
			//�ܱ�����ӦԪ�ؿ�״̬�ı�
			for (int j = 0; j < P_num; ++j)
			{
				if (P_list[j].init_addr == DP_list[i].init_addr)
				{
					P_list[j].state = 'F';
					break;
				}
			}
			//���з�����ȥ��һ��Ԫ��
			for (; i < DP_num; ++i)
			{
				DP_list[i] = DP_list[i + 1];
			}
			DP_num--;
		}
		else
		{
			A = i;
			//�ܷ���������һ��Ԫ�ز�ˢ��
			for (int j = 0; j < P_num; ++j)
			{
				if (P_list[j].init_addr == DP_list[i].init_addr)
				{
					P_list[P_num].init_addr = DP_list[i].init_addr;
					P_list[P_num].Partition_size = need_len;
					P_list[P_num].state = 'F';
					P_list[j].init_addr += need_len;
					P_list[j].Partition_size -= need_len;
					break;
				}
			}
			//���з�����ˢ��
			DP_list[i].init_addr += need_len;
			DP_list[i].Partition_size -= need_len;
		}
		return 1;
	}
	return 0;
}

void assign(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num)
{
	int input = 0;
	do{
		int need_len = 0;
		printf("��ѡ�� :>_ 1. ����Ӧ  2. ѭ������Ӧ  3. �����Ӧ  4. ���Ӧ  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			//����Ӧ�㷨
			do{
				printf("����������������Ŀռ��С��");
				scanf("%d", &need_len);
				Sort_Addr(DP_list, DP_num);
				Sort_Addr(P_list, P_num);
				if (1 == fun(DP_list, P_list, DP_num, P_num, need_len))
				{
					Sort_Addr(P_list, P_num);
					Print_List(P_list, P_num);
				}
				else
				{
					printf("***************û�к��ʿռ�****************\n");
				}
			} while (need_len);
		}
		else if (2 == input)
		{
			Sort_Addr(DP_list, DP_num);
			int A = 0;		//DP_list ����һ���ҵ����±ꣻ��һ��ֱ����A+1��λ�ÿ�ʼ��
			//ѭ������Ӧ
			do{
				printf("����������������Ŀռ��С��");
				scanf("%d", &need_len);
				Sort_Addr(P_list, P_num);
				int t = 0;
				int i = 0;
				for (i = A; i < DP_num; ++i)
				{
					if (fun_cir(DP_list, P_list, DP_num, P_num, need_len, t, i, A) == 1)
					{
						break;
					}
				}
				if (i == DP_num)
				{
					for (int j = 0; j < A; ++j)
					{
						fun_cir(DP_list, P_list, DP_num, P_num, need_len, t, j, A);
					}
				}
			} while (need_len);
		}
		else if (3 == input)
		{
			//�����Ӧ�㷨
			do{
				printf("����������������Ŀռ��С��");
				scanf("%d", &need_len);
				Sort_Size(DP_list, DP_num);
				Sort_Size(P_list, P_num);
				if (1 == fun(DP_list, P_list, DP_num, P_num, need_len))
				{
					Sort_Addr(P_list, P_num);
					Print_List(P_list, P_num);
				}
				else
				{
					printf("***************û�к��ʿռ�****************\n");
				}
			} while (need_len);
		}
		else if (4 == input)
		{
			//���Ӧ�㷨
			do{
				printf("����������������Ŀռ��С��");
				scanf("%d", &need_len);
				R_Sort_Size(DP_list, DP_num);
				R_Sort_Size(P_list, P_num);
				if (1 == fun(DP_list, P_list, DP_num, P_num, need_len))
				{
					Sort_Addr(P_list, P_num);
					Print_List(P_list, P_num);
				}
				else
				{
					printf("***************û�к��ʿռ�****************\n");
				}
			} while (need_len);
		}
		else
		{
			return 0;
		}
	} while (input);
}

void recycle(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num)
{
	int pathaddr = 0;
	Print_List(P_list, P_num);
	printf("������Ҫ���շ�����ʼַ :>_ ");
	scanf("%d", &pathaddr);

}


void choose(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num)
{
	int input = 0;
	do{
		printf("��ѡ�� :>_   1. ����ռ�   2. �ռ����  3. ��ӡ��ʱ��̬�����  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			assign(DP_list, P_list, DP_num, P_num);			//����ռ�
		}
		else if (2 == input)
		{
			recycle(DP_list, P_list, DP_num, P_num);			//���տռ�
		}
		else if (3 == input)
		{
			Print_List(P_list, P_num);
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
	
	uint64_t P_num = 3;			//���з�������
	uint64_t DP_num = 0;		//���з�������
	int flag = 1;
	printf("������з����� :>>\n\n");
	printf("������з������� :>_ ");
	scanf("%d", &DP_num);
	P_ListInit(P_list, P_num);
	P_ListInit(DP_list, DP_num);
	Print_List(P_list, P_num);
	while (flag--)
	{
		P_num = 0;
		int addr = 0;
		for (int i = 1; i <= DP_num; ++i)
		{
			printf("������ :>_ %d\n", i);
			printf("\t������С :>_ "); scanf("%d", &DP_list[i - 1].Partition_size);
			printf("\t����ʼַ :>_ "); scanf("%d", &DP_list[i - 1].init_addr);
		}
		Sort_Addr(DP_list, DP_num);
		for (int j = 0; j < DP_num; )
		{
			if (DP_list[j].init_addr > addr)
			{
				P_list[P_num].init_addr = addr;
				P_list[P_num].Partition_size = DP_list[j].init_addr;
				P_list[P_num].state = 'F';			// �ǿ��з������ѷ��䣩
				addr += DP_list[j].init_addr;
				P_num++;
			}
			else if (DP_list[j].init_addr == addr)
			{
				P_list[P_num].init_addr = DP_list[j].init_addr;
				P_list[P_num].Partition_size = DP_list[j].Partition_size;
				P_list[P_num].state = 'T';			// ���з�����δ���䣩
				addr += DP_list[j].Partition_size;
				P_num++;
				j++;
			}
			else
			{
				printf("input error!!! ���ݴ��� input again!\n");
				flag++;
				break;
			}
		}
		if (addr >= _length)	//������з��������һƬ����Խ��
		{
			printf("input error!!! ����Խ�� input again!\n");
			flag++;
		}
		else if (addr == _length - 1)
		{
			// ���һ���������������ڴ���ĩ
		}
		else
		{
			P_list[P_num].init_addr = addr;
			P_list[P_num].Partition_size = _length - addr;
			P_list[P_num].state = 'F';			// �ǿ��з������ѷ��䣩
			P_num++;
		}
	}

	Print_List(P_list, P_num);
	choose(DP_list, P_list, DP_num, P_num);
	Print_List(P_list, P_num);


}

int main()
{
	start();
	return 0;
}

