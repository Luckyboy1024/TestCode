#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;		//有序
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}
void print_arr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	bubble_sort(arr, sz);		//冒泡排序
	print_arr(arr, sz);
	return 0;
}




#if 0 

int main()
{
	int arr[10] = {1,2,3,4,5};
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%d\n", *arr);
	//输出结果
	return 0;
}
void bubble_sort(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);//这样对吗？
	int i = 0;
	for (i = 0; i<sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j<sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	bubble_sort(arr);//是否可以正常排序？
	for (int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void print_arr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	bubble_sort(arr, sz);		//冒泡排序
	print_arr(arr, sz);
	return 0;
}


int main()
{
	int arr[3][4] = { 0 };
	//sizeof(arr)----计算整个数组的大小（占多少字节的内存）
	//sizeof(arr[0])-----计算数组每一行的大小（占多少字节的内存）
	//sizeof(arr[0][0])------计算数组每个元素的大小（占多少字节的内存）
	//sizeof(arr) / sizeof(arr[0])------计算数组行数
	//sizeof(arr[0]) / sizeof(arr[0][0])-------计算数组列数
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		//			printf("%p", arr[i]);		//打印每行首地址
		//			printf("%d", arr[i]);		//打印每行元素
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++)
		{
			printf("%d ", arr[i][j]);		//依次打印数组元素
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	int arr[3][4] = { 0 };
	int* p = &arr[0][0];
	for (int i = 0; i < 12; i++)
	{
		*(p + i) = i;;
	}
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}
int main()
{
	int arr[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	return 0;
}


int main()
{
	int arr[3][4] = { 0 };		//三行四列
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}
int main()
{
	int arr[][4] = { { 1, 2 }, { 3 }, { 4, 5 } };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}


int main()
{
	int arr1[2][3] = { 1, 2, 3, 4 };		//
	int arr2[2][3] = { (1,2),(3,4), 5};
	int arr3[3][3] = { { 1, 2 }, { 3, 4 }, 5 };
	
//	int arr4[3][3] = { { 1, 2 }, 3, { 4, 5 } };
	//这种初始化非法: 初始值太多
	
//	int arr5[][] = { 1, 2, 3, 4, 5 };
	//这种初始化非法: 缺少下标
	return 0;
}
//*(p + i) == *(arr + i) == arr[i] == *(i + arr) == i[arr] == p[i]

int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(i + arr));
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i[arr]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}
int main()
{
	int arr[10] = { 0 };		//创建数组，并对数组初始化，每个数组元素初始化为0
	int *p = arr;			//将数组地址（首元素的地址）赋给指针变量P

	for (int i = 0; i < 10; i++)
	{
		printf("&arr[%d] = %p   <======>    %p\n", i, &arr[i], p + i);		//依次打印出数组各元素的地址
	}

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