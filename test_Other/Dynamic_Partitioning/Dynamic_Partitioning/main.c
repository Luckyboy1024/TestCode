#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdint.h>
#include "Dynamic_Partition.h"

#define _NUM 10		//空闲分区个数最值
#define _G	2		//参数 G,分区分配后剩余部分大小不小于G
#define _length	256	//内存大小

int fun(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num,int need_len)
{
	int t = 0;
	for (int i = 0; i < DP_num; ++i)
	{
		if ((t = DP_list[i].Partition_size - need_len) >= 0)
		{
			if (t < _G)
			{
				//总表中相应元素块状态改变
				for (int j = 0; j < P_num; ++j)
				{
					if (P_list[j].init_addr == DP_list[i].init_addr)
					{
						P_list[j].state = 'F';
						break;
					}
				}
				//空闲分区表去除一个元素
				for (; i < DP_num; ++i)
				{
					DP_list[i] = DP_list[i + 1];
				}
				DP_num--;
			}
			else
			{
				//总分区表增加一个元素并刷新
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
				//空闲分区表刷新
				DP_list[i].init_addr += need_len;
				DP_list[i].Partition_size -= need_len;
			}
			return 1;
		}
	}
	return 0;
}

int fun_cir(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num, int need_len, int t, int i, int A)		//循环最适应
{
	if ((t = DP_list[i].Partition_size - need_len) >= 0)
	{
		if (t < _G)
		{
			A = i - 1;
			//总表中相应元素块状态改变
			for (int j = 0; j < P_num; ++j)
			{
				if (P_list[j].init_addr == DP_list[i].init_addr)
				{
					P_list[j].state = 'F';
					break;
				}
			}
			//空闲分区表去除一个元素
			for (; i < DP_num; ++i)
			{
				DP_list[i] = DP_list[i + 1];
			}
			DP_num--;
		}
		else
		{
			A = i;
			//总分区表增加一个元素并刷新
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
			//空闲分区表刷新
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
		printf("请选择 :>_ 1. 最适应  2. 循环最适应  3. 最佳适应  4. 最坏适应  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			//最适应算法
			do{
				printf("请输入你需求申请的空间大小：");
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
					printf("***************没有合适空间****************\n");
				}
			} while (need_len);
		}
		else if (2 == input)
		{
			Sort_Addr(DP_list, DP_num);
			int A = 0;		//DP_list 中上一次找到的下标；下一次直接在A+1的位置开始找
			//循环最适应
			do{
				printf("请输入你需求申请的空间大小：");
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
			//最佳适应算法
			do{
				printf("请输入你需求申请的空间大小：");
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
					printf("***************没有合适空间****************\n");
				}
			} while (need_len);
		}
		else if (4 == input)
		{
			//最坏适应算法
			do{
				printf("请输入你需求申请的空间大小：");
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
					printf("***************没有合适空间****************\n");
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
	printf("输入所要回收分区的始址 :>_ ");
	scanf("%d", &pathaddr);

}


void choose(Partition* DP_list, Partition* P_list, uint64_t DP_num, uint64_t P_num)
{
	int input = 0;
	do{
		printf("请选择 :>_   1. 分配空间   2. 空间回收  3. 打印此时动态分配表  0.exit\n");
		scanf("%d", &input);
		if (1 == input)
		{
			assign(DP_list, P_list, DP_num, P_num);			//分配空间
		}
		else if (2 == input)
		{
			recycle(DP_list, P_list, DP_num, P_num);			//回收空间
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
	Partition P_list[_NUM];		//动态分区表
	Partition DP_list[_NUM];	//空闲分区表
	
	uint64_t P_num = 3;			//现有分区个数
	uint64_t DP_num = 0;		//空闲分区个数
	int flag = 1;
	printf("输入空闲分区表 :>>\n\n");
	printf("输入空闲分区个数 :>_ ");
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
			printf("分区号 :>_ %d\n", i);
			printf("\t分区大小 :>_ "); scanf("%d", &DP_list[i - 1].Partition_size);
			printf("\t分区始址 :>_ "); scanf("%d", &DP_list[i - 1].init_addr);
		}
		Sort_Addr(DP_list, DP_num);
		for (int j = 0; j < DP_num; )
		{
			if (DP_list[j].init_addr > addr)
			{
				P_list[P_num].init_addr = addr;
				P_list[P_num].Partition_size = DP_list[j].init_addr;
				P_list[P_num].state = 'F';			// 非空闲分区（已分配）
				addr += DP_list[j].init_addr;
				P_num++;
			}
			else if (DP_list[j].init_addr == addr)
			{
				P_list[P_num].init_addr = DP_list[j].init_addr;
				P_list[P_num].Partition_size = DP_list[j].Partition_size;
				P_list[P_num].state = 'T';			// 空闲分区（未分配）
				addr += DP_list[j].Partition_size;
				P_num++;
				j++;
			}
			else
			{
				printf("input error!!! 数据错误 input again!\n");
				flag++;
				break;
			}
		}
		if (addr >= _length)	//输入空闲分区的最后一片分区越界
		{
			printf("input error!!! 存在越界 input again!\n");
			flag++;
		}
		else if (addr == _length - 1)
		{
			// 最后一个空闲区正好在内存最末
		}
		else
		{
			P_list[P_num].init_addr = addr;
			P_list[P_num].Partition_size = _length - addr;
			P_list[P_num].state = 'F';			// 非空闲分区（已分配）
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

