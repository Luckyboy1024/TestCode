#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

//函数声明
int Add(int x, int y);

int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("c = %d\n", c);
	return 0;
}
//函数定义
int Add(int x, int y)
{
	return (x + y);
}

#if 0

int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	//结果是啥？
	return 0;
}

int main()
{
	char arr[20] = "hello";
	int ret = 0;
	ret = strlen(arr);
	printf("%d\n", ret);
	ret = strlen(strcat(arr, "boy"));//这里介绍一下strlen函数 
	printf("%d\n", ret);
	return 0;
}

void new_line()
{
	printf("hehe\n");
}
void three_line()
{
	int i = 0;
	for(i=0; i<3; i++)
	{
		new_line();
	}
}
int main()
{
	three_line();
	return 0;
}



void Add(int* p)
{
	(*p)++;
}

int main()
{
	int num = 0;
	Add(&num);		//注意：&num，形参与实参的区别
	Add(&num); 
	Add(&num); 
	Add(&num); 
	printf("num = %d\n", num);
	return 0;
}



int binary_search(int* arr, int k, int sz)		//找不到返回-1（不能是返回0，存在0下标元素），找到返回下标，
{
	//找出中间元素下标
	int left = 0;
	int right = sz - 1;
	while (left <= right)		//循环结束条件：left > right
	{
		int mid = left + (right - left) / 2;
		if (k < arr[mid])
		{
			right = mid - 1;
			printf("");
		}
		else if (k > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, key, sz);
	if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，是下标为 %d 的元素", ret);
	}
	return 0;
}

void test()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
		if (5 == i)
		{
			return;		//return (void);
		}
	}
	printf("test:hehe\n");
}
int main()
{
	test();
	return 0;
}


int main()
{
	FILE* pf = fopen("", "r");
	assert(pf);

	return 0;
}


程序名称：
属于哪个项目：
程序版本号：
程序开发小组组别：
程序算法提供人：
程序流程图提供人：
程序代码编写人：
程序测试员：
项目负责人：

#endif