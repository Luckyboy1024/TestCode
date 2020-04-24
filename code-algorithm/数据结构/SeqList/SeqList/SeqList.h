#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>


typedef int DataType;

/*
#define N 100	//顺序表起始大小，动态数组
typedef struct SeqList{ DataType _array[N]; }SeqList;
*/

typedef struct SeqList
{
	DataType* _array;
	size_t _size;			//实际存放的元素个数
	size_t _capacity;		//开辟空间的大小
}SeqList;

void SeqListInit(SeqList* sl);			//初始化
void SeqListDestory(SeqList* sl);		//销毁 释放空间
void SeqListCheckCapacity(SeqList* sl);	//检查容量

//增加 插入
void SeqListPushBack(SeqList* sl, DataType x);		//尾插
void SeqListPushFront(SeqList* sl, DataType x);		//头插
void SeqListInsert(SeqList* sl, size_t pos, DataType x);		//任意位置（pos前面）插入

//删除
void SeqListPopBack(SeqList* sl);					//尾删
void SeqListPopFront(SeqList* sl);					//头删
void SeqListErase(SeqList* sl, size_t pos);			//删除当前 (pos) 位置数据

//查找
size_t SeqListFind(SeqList* sl, DataType x);		

//更改
size_t SeqListModify(SeqList* sl, size_t pos, DataType x);

//打印
void SeqListPrint(SeqList* sl);

//计算元素个数
size_t SeqListSize(SeqList* sl);

//返回当前位置的值
DataType SeqListAt(SeqList* sl, size_t pos);

#endif  //__SEQLIST_H__