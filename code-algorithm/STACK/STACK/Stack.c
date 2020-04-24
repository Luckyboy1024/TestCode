#define _CRT_SECURE_NO_WARNINGS 1


#include "Stack.h"




//初始化
void InitStack(Stack *s)
{
	assert(s);
	s->data = NULL;
	s->end = s->top = 0;
}

//给栈增容
void ExpandStack(Stack *s)
{
	assert(s);
	DataType* tmp = (DataType*)malloc(sizeof(DataType));
	if (NULL == tmp)
	{
		printf("扩容失败\n");
		return;
	}
	s->data = tmp;
	s->end++;
}

//入栈
void StackPush(Stack* s, DataType x)
{
	assert(s);
	if (s->end == s->top)
	{
		ExpandStack(s);
	}
	s->data[s->top++] = x;
}

//出栈
void StackPop(Stack* s)
{
	assert(s);
	if (s->top > 0)
		s->top--;
}

//获取栈顶元素
DataType StackTop(Stack* s)
{
	assert(s);
	if (s->top > 0)
		return s->data[s->top-1];
}

//求得栈的大小
size_t StackSize(Stack* s)
{
	assert(s);
	return s->top ;
}
//判断是否为空栈
int EmptyStack(Stack *s)
{
	assert(s);
	if (s->top == s->end && s->data[s->top] == NULL)
	{
		return 1;			//是空栈
	}
	else
	{
		return 0;		//栈非空
	}
}
