#define _CRT_SECURE_NO_WARNINGS 1


#include "Stack.h"




//��ʼ��
void InitStack(Stack *s)
{
	assert(s);
	s->data = NULL;
	s->end = s->top = 0;
}

//��ջ����
void ExpandStack(Stack *s)
{
	assert(s);
	DataType* tmp = (DataType*)malloc(sizeof(DataType));
	if (NULL == tmp)
	{
		printf("����ʧ��\n");
		return;
	}
	s->data = tmp;
	s->end++;
}

//��ջ
void StackPush(Stack* s, DataType x)
{
	assert(s);
	if (s->end == s->top)
	{
		ExpandStack(s);
	}
	s->data[s->top++] = x;
}

//��ջ
void StackPop(Stack* s)
{
	assert(s);
	if (s->top > 0)
		s->top--;
}

//��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
	assert(s);
	if (s->top > 0)
		return s->data[s->top-1];
}

//���ջ�Ĵ�С
size_t StackSize(Stack* s)
{
	assert(s);
	return s->top ;
}
//�ж��Ƿ�Ϊ��ջ
int EmptyStack(Stack *s)
{
	assert(s);
	if (s->top == s->end && s->data[s->top] == NULL)
	{
		return 1;			//�ǿ�ջ
	}
	else
	{
		return 0;		//ջ�ǿ�
	}
}
