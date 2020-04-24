#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;	//容量
}Heap;


//初始化---数组  创建堆
void HeapInit(Heap* hp, HPDataType* a, int n);

//初始化  空的顺序表
void HeapInit(Heap* hp);

//销毁
void HeapDestory(Heap* hp);
//push
void HeapPush(Heap* hp, HPDataType x);
//pop
void HeapPop(Heap* hp);
//返回堆顶指针
HPDataType HeapTop(Heap* hp);
//堆大小
int HeapSize(Heap* hp);
//判断
int HeapEmpty(Heap* hp);

// 堆排序
void HeapSort(int* a, int n);

void TestHeap();


void ShiftDown(HPDataType* a, int n, int root);	//n是数组大小，root根的下标
