#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_head = CreatNode(0);
	q->_tail = q->_head;
}

void QueuePush(Queue* q, Data_Q x)
{
	assert(q);
	q->_tail->_next = CreatNode(x);
	q->_tail = q->_tail->_next;
}

void QueuePop(Queue* q)
{
	QNode p = q->_head->_next;
	if (NULL != p)
	{
		q->_head->_next = p->_next;
		if (NULL == p->_next)
		{
			q->_tail = q->_head;
		}
		free(p);
	}
}

//
//int QueueSize(Queue* q);
//int QueueEmpty(Queue* q);
//
QNode CreatNode(Data_Q x)
{
	QNode NewNode = (QNode)malloc(sizeof(QueueNode));
//	NewNode->_data = x;
//	NewNode->_next = NULL;
	return NewNode;
}