#define _CRT_SECURE_NO_WARNINGS 1

#include "Circle.h"


void InitCircle(CircleQueue* Q)		//初始化
{
	Q->elem = (CircleQueue*)malloc(sizeof(CircleQueue));
	Q->front = Q->rear = Q->tag = 0;
}


void DestroyCircle(CircleQueue* Q)		//销毁
{
	free(Q->elem);
	Q->front = Q->rear = 0;
	Q->tag = 0;
}
void CircleEmpty(CircleQueue Q)		//判空
{
	return Q.tag == 0 ? 1 : 0;
}
void EnCircle(CircleQueue Q, Datatype x)			//入队
{
	Q.tag++;

}
void DeCircle(CircleQueue Q)			//出队
{

}
void PrintCircle(CircleQueue Q)		//打印
{

}