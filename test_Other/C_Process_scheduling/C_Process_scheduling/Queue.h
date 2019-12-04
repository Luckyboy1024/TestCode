#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Data_Q;

typedef struct QueueNode{
	Data_Q* _data;
	struct QueueNode* _next;
}QueueNode, * QNode;

typedef struct Queue{
	QNode _head;		// 队头指针
	QNode _tail;		// 队尾指针
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, Data_Q x);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);


#endif //__QUEUE_H__


#endif