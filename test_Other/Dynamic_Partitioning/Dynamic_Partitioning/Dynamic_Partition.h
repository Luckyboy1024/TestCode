#define _CRT_SECURE_NO_WARNINGS 1

#include <stdint.h>
#include <stdio.h>

typedef struct PartitionList{
	int Partition_size;		//������С
	int init_addr;				//����ʼַ
	char state;						//����״̬
}Partition;

//typedef struct ChainNode{
//	;
//};
//
//typedef struct PartitionChain{		
//	Partition* front;		//ǰ��
//
//	Partition* back;		//���
//};



void Print_List(Partition* arr, int size);

