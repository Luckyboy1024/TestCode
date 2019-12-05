#define _CRT_SECURE_NO_WARNINGS 1

#include <stdint.h>
#include <stdio.h>

typedef struct Partition{
	int Partition_size;		//������С
	int init_addr;				//����ʼַ
	char state;						//����״̬
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

