#define _CRT_SECURE_NO_WARNINGS 1

#include "Circle.h"


void InitCircle(CircleQueue* Q)		//��ʼ��
{
	Q->elem = (CircleQueue*)malloc(sizeof(CircleQueue));
	Q->front = Q->rear = Q->tag = 0;
}


void DestroyCircle(CircleQueue* Q)		//����
{
	free(Q->elem);
	Q->front = Q->rear = 0;
	Q->tag = 0;
}
void CircleEmpty(CircleQueue Q)		//�п�
{
	return Q.tag == 0 ? 1 : 0;
}
void EnCircle(CircleQueue Q, Datatype x)			//���
{
	Q.tag++;

}
void DeCircle(CircleQueue Q)			//����
{

}
void PrintCircle(CircleQueue Q)		//��ӡ
{

}