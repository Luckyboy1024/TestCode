#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;	//����
}Heap;


//��ʼ��---����  ������
void HeapInit(Heap* hp, HPDataType* a, int n);

//��ʼ��  �յ�˳���
void HeapInit(Heap* hp);

//����
void HeapDestory(Heap* hp);
//push
void HeapPush(Heap* hp, HPDataType x);
//pop
void HeapPop(Heap* hp);
//���ضѶ�ָ��
HPDataType HeapTop(Heap* hp);
//�Ѵ�С
int HeapSize(Heap* hp);
//�ж�
int HeapEmpty(Heap* hp);

// ������
void HeapSort(int* a, int n);

void TestHeap();


void ShiftDown(HPDataType* a, int n, int root);	//n�������С��root�����±�
