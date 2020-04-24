#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct Stack{
	DataType *data;
	int end;
	int top;

}Stack;



//��ʼ��
void InitStack(Stack *s);

//��ջ����
void ExpandStack(Stack *s);

//��ջ
void StackPush(Stack* s, DataType x);

//��ջ
void StackPop(Stack* s);
//��ȡջ��Ԫ��
DataType StackTop(Stack* s);
//���ջ�Ĵ�С
size_t StackSize(Stack* s);
//�ж��Ƿ�Ϊ��ջ
int EmptyStack(Stack *s);
