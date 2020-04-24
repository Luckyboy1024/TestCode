#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef char DataType;

typedef struct BTNode
{
	DataType data;
	struct BTNode* root;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;


BTNode* CreatBTree(char* str, int* pi)
{
	
}

