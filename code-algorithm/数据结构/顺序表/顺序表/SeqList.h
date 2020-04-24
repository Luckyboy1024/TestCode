#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>

typedef struct SeqList
{
	size_t _arrary;
	size_t _size;
	struct SeqList *p;
}SeqList;

//初始化顺序表
void InitSeqList(SeqList *s, size_t x);

//销毁顺序表

//清空顺序表

//增删改查

//头插
//尾插
//插入

//头删
//尾删
//删除





#endif  /__SEQLIST_H__

#if 0

// 顺序表的静态存储
#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType array[N]; // 定长数组
	size_t size;        // 有效数据的个数     
}SeqList;


// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capicity;   // 容量空间的大小
}SeqList;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capicity;   // 容量空间的大小
}SeqList;

// 基本增删查改接口
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl);

#endif
