#define _CRT_SECURE_NO_WARNINGS 1

#include <stdint.h>
#include <stdio.h>

typedef struct Partition{
	int Partition_size;		//分区大小
	int init_addr;				//分区始址
	char state;						//分区状态
}Partition;

typedef struct PartitionNode{
	Partition* Node;
	struct PartitionNode* next;
}LNode;

typedef struct List{
	LNode* head;
	LNode* tail;
}List;

void Print_List(Partition* arr, int size);
void P_ListInit(Partition* arr, int size);

