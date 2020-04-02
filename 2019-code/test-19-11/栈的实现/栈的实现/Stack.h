#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


typedef struct node{
	int data;//此处我们暂且存储int型的数据
	struct node *pNext;//用于指向下一个结点
}NODE, *PNODE;

typedef struct stack{
	PNODE Top;//指向栈顶的指针
	PNODE Bottom;//指向栈底的指针
}STACK, *PSTACK;


void initStack(PSTACK pS);
void pushStack(PSTACK pS);
void popStack(PSTACK pS);
void traversalStack(PSTACK pS);


