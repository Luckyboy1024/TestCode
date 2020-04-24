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



//初始化
void InitStack(Stack *s);

//给栈增容
void ExpandStack(Stack *s);

//入栈
void StackPush(Stack* s, DataType x);

//出栈
void StackPop(Stack* s);
//获取栈顶元素
DataType StackTop(Stack* s);
//求得栈的大小
size_t StackSize(Stack* s);
//判断是否为空栈
int EmptyStack(Stack *s);
