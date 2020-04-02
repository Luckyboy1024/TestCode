#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __TEST_H__
#define __TEST_H__


#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define DataType int

typedef struct List{
	DataType _a;
	struct List* _next;
}List;

typedef struct ListNode{
	List* node;
	DataType _size;
	DataType _cap;
}ListNode;


#endif