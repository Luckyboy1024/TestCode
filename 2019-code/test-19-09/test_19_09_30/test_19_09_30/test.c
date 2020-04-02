#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		size_t left = maxDepth(root->left);
		size_t right = maxDepth(root->right);
		return left > right ? (left + 1) : (right + 1);
	}
}





#if 0
#include <stdio.h>
void ProcessBar()
{
	int i = 0;
	char bar[51] = { '\0' };
	memset(bar, 0, sizeof(bar));
	const char *lable = "|/-\\";
	for (i = 0; i <= 50; i++)
	{
		printf("[%-50s][%d%%][%c]\r", bar, i, lable[i % 4]);
		bar[i] = '#';
		Sleep(80);
	}
	printf("\n");
}

int main()
{
	ProcessBar();

	return 0;
}

a=1
b="hello"
c='c'
d=3.14


echo $a
echo $b
echo $c
echo $d



int main()
{
	FILE *pf = fopen("test.txt", "r");		//读文件
	assert(pf);
	int ch = 0;			//fgetc()函数返回值为int型
	while ((ch = fgetc(pf))!=EOF)	//EOF文件结束标志符
	{
		printf("%c", ch); 
		//putchar(ch);	//打印
	}
	return 0;
}

int main()
{
	FILE *pf = fopen("test.txt", "r");		//读文件
	assert(pf);
	int ch = 0;
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	return 0;
}
#endif
#if 0
int main()
{
	FILE *pf = fopen("test.txt", "w");		//如果没有文件，会创建文件
	assert(pf);
	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif