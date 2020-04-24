#define _CRT_SECURE_NO_WARNINGS 1

// 银行家算法
	
#include "test.h"

typedef int TypeData;

typedef struct BANKER{
	TypeData **Available;	// 可利用资源向量
	TypeData **Max;	// 最大需求矩阵
	TypeData **Allocation; // 分配矩阵
	TypeData **Need;	//需求矩阵
	//_Bool Finish;
}Banker;

// 三矩阵之间的关系：Need[i, j] = Max[i, j] - Allocation[i, j]



