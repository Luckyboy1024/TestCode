#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>



#if 0
int main()
{
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		int j = 0;
		for(j=1; j<=i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}

int main()
{
	return 0;
}

int main()
{
	char i = 0;
	for (i = 0; i < 130; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	return 0; 
}
struct
{
	char name[20];
	int age;
}animal;

struct Stu stu[2] = { { "" }, {} };
struct Node
{
	int data;
	struct Node* next;
};

//类型重命名
typedef struct Node
{
	int data;
	struct Node* next;
}Node;  //别名可以叫自己本身

typedef struct Node
{
	int data;
	struct Node* next;
}Node,* pNode;		//这里的逗号不能省略 




typedef struct Stu
{
	char name[20];//名字
	int age;//年龄
	char sex[5];//性别
	char id[20];//学号
}Stu;//分号不能丢

int main()
{
	int arr[10];
	arr = { 0, 1, 2, 3, 4 };
	Stu student = { "caocao", 18, '男', "1245" };	//注意单引号与双引号
	//student = { "liubei", 19, "nan", "1243155415" };	//error：语法错误
	return 0;
}
typedef int* INT_PTR;

int main()
{
	int a = 10;
	int b = 20;
	const INT_PTR p1 = &a;
	p1 = &b;
	*p1 = 99;
	return 0;
}

#define INT_PTR int*
typedef int* INT_PTRR;

int main()
{
	int a = 10;
	int b = 20;
	const INT_PTR p1 = &a;
	p1 = &b;
	*p1 = 99;
	return 0;
}
typedef int ARR[10];
int main()
{
	ARR arr = { 1, 2, 3, 4, 5, 6, 7 };
	return 0;
}
typedef int(*PARR)[4];
typedef int* PARR2[4];
typedef int(*pFun)(int, int);


typedef int* INT_PTR;
int main()
{
	int a = 10;
	int b = 20;
	INT_PTR p1, p2;
	p1 = &a;
	p2 = &b;
	return 0;
}
#define INT_PTR int*			//宏替换 

int main()
{
	int a = 10;
	int b = 20;
	INT_PTR p1, p2;

	p1 = &a;		//这两行代码是否会报错
	p2 = &b;
	return 0;
}

#endif