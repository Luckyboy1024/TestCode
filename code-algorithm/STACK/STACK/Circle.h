#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <molloc.h>
#include <assert.h>


typedef int Datatype;

typedef struct CircleQueue{
	Datatype *elem;
	int tag;
	int front;
	int rear;
}CircleQueue;


void InitCircle(CircleQueue* Q);		//初始化
void DestroyCircle(CircleQueue* Q);		//销毁
void CircleEmpty(CircleQueue Q);		//判空
void EnCircle(CircleQueue Q);			//入队
void DeCircle(CircleQueue Q);			//出队
void PrintCircle(CircleQueue Q)		//打印

