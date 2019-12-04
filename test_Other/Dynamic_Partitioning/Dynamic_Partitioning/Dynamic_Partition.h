#define _CRT_SECURE_NO_WARNINGS 1

#include <stdint.h>
#include <stdio.h>

typedef struct PartitionList{
	int Partition_size;		//分区大小
	int init_addr;				//分区始址
	char state;						//分区状态
}Partition;

//typedef struct ChainNode{
//	;
//};
//
//typedef struct PartitionChain{		
//	Partition* front;		//前驱
//
//	Partition* back;		//后继
//};



void Print_List(Partition* arr, int size);

