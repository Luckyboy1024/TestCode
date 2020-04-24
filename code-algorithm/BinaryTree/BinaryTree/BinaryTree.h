#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define BTNode int

typedef struct BT{
	BTNode* _left;
	BTNode* _right;
	BTNode _val;
};

//÷––Ú
void BinaryTreeInOrder(BTNode* root);


//∫Û–Ú
void BinaryTreePostOrder(BTNode* root);

