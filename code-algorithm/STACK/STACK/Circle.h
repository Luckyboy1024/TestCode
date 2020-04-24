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


void InitCircle(CircleQueue* Q);		//��ʼ��
void DestroyCircle(CircleQueue* Q);		//����
void CircleEmpty(CircleQueue Q);		//�п�
void EnCircle(CircleQueue Q);			//���
void DeCircle(CircleQueue Q);			//����
void PrintCircle(CircleQueue Q)		//��ӡ

