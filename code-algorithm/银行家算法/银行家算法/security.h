#define _CRT_SECURE_NO_WARNINGS 1

// 安全性检测算法

#include "test.h"

typedef int TypeData;
#define true (!0)
#define fause (0)

typedef struct Security{
	TypeData **Available;	// 可利用资源向量
	TypeData **Max;	// 最大需求矩阵
	TypeData **Allocation; // 分配矩阵
	TypeData **Need;	//需求矩阵
	int Finish;
}Security;




