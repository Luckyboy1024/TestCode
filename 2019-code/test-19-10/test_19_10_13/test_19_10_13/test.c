#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void test()
{

}

int main()
{
	test();
	return 0;
}

#if 0
#include <stdio.h>

int IsFibonacci(int n)
{
	int sum = 0;
	int s1 = 0;
	int s2 = 1;
	while (n>sum)
	{
		sum = s1 + s2;
		s1 = s2;
		s2 = sum;
	}
	if(n == sum)
		return 1;
	else
		return 0;
}

int Fibonacci_N(int N)
{
	int tep = 0;
	if(IsFibonacci(N)==1)
	{
		return tep;        //记录步数
	}
	else{
		while((0==IsFibonacci(N+tep))&&(0==IsFibonacci(N-tep)))
		{
			++tep;
		}
	}
	return tep;
}

int main()
{
	int N = 0;
	scanf("%d", &N);
	printf("%d", Fibonacci_N(N));
	return 0;
}
#endif

#if 0
void BTNode(btNode* bt)
{
	while (cur)
	{
		cur = bt->root   
	}
}

#include <stdio.h>
typedef int TyData;

void qianxuzhongxu(TyData *preorder, TyData *inorder){
	//前序遍历确定一个树的根
	//中序：找到根的位置；
	//		根据根的位置确定左右子树的区间
	TyData* index = preorder;
	TyData* root = inorder;
	TyData* inbegin = inorder;
	TyData* end = inorder;
	while (*preorder != *inorder){
		root++;
	}
	TyData* L_root, R_root;
}


struct TreeNode* _build(TyData *preorder, TyData *inorder, TyData *pindex, TyData *inbegin, TyData *inend)
{

}


#endif