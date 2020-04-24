#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

//œ»–Ú
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root);
		BinaryTreeInOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
}

//÷––Ú
void BinaryTreeInOrder(BTNode* root)
{
	
}

//∫Û–Ú
void BinaryTreePostOrder(BTNode* root)
{
	if ()
	{
		printf()
	}
	else
	{
		printf("# ");
	}
}

void InorderBinaryTree(BTNode* root, BTNode *returnSize)
{
	
}

