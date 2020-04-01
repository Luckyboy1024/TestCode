#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>

int main()
{

	return 0;
}

#if 0
void find(int arr[3][3], int *px, int *py, int key)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return;
		}
		else if (arr[x][y] > key)
		{
			y--;
		}
		else if (arr[x][y] < key)
		{
			x++;
		}
	}
	*px = -1;
	*py = -1;
}
int main()
{
	int arr[3][3] = 
	{ 1, 2, 3,
	2, 3, 4,
	3, 4, 5 }; 
	int x = 3;
	int y = 3;
	find(arr, &x, &y, 3);
	printf("%d,%d\n", x, y);
	return 0;
}

int is_left_move(char *arr, const char *p)
{
	if (strlen(arr) != strlen(p))
	{

	}
	strncat(arr, arr, strlen(arr));
	if (strstr(arr,p)!=NULL)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char str1[30] = "abcdef";
	char *str2 = "cdefab";
	int n = is_left_move(str1, str2);
	printf("%d\n", n);
	return 0;
}


int binsearch(int x, int v[], int n)		//x为数组大小,n为要查找的数
{
	int left = 0;		//左下标
	int right = x - 1;	//计算数组元素个数-1，即为最后一个元素的下标
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//我们一般用这个方法取中间值
		if (n < v[mid])
		{
			right = mid - 1;
		}
		else if (n > v[mid])
		{
			left = mid + 1;
		}
		else if (n = v[mid])
		{
			return mid+1;
		}
	}
	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int x = sizeof(arr) / sizeof(arr[0]) - 1;
	int n = 7;
	if (0 == binsearch(x, arr, n))
	{
		printf("找不到\n");
	}
	else
	{
		printf("find it:>_ 第%d个\n", binsearch(x, arr, n));
	}
	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int find = 7;

	int left = 0;		//左下标
	int right = sizeof(arr) / sizeof(arr[0])-1;	//计算数组元素个数-1，即为最后一个元素的下标
	//int mid = (left + right) / 2;		//这种取中间值的方法，可能会溢出
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//我们一般用这个方法取中间值
		if (find < arr[mid])
		{
			right = mid - 1;
		}
		else if (find > arr[mid])
		{
			left = mid + 1;
		}
		else if (find = arr[mid])
		{
			printf("find it:>_ 第%d个\n", mid + 1);
			return 0;
		}
	}
	printf("找不到\n");
	return 0;
}
int main()
{
	int i = 0;
	int n = 0;
	int p = 0;
	int ret = 1;
	int sum = 0;
	scanf("%d", &p);
	for (n = 1; n <= p; n++)
	{
		ret *= n; 
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}

int main()
{
	int i = 0;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 10);

	return 0;
}

int main()
{
	int a = 0;
	int b = a = 0;	//把0赋值给a,表达式（a = 0）返回值即为a的值0，再赋值给b,
	2 + 3;		//这也是一个表达式，最终返回5
	return 0;
}


int main()
{
	int i = 0;
	int k = 0;
	int count = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
	{
		k++;
		count++;
	}
	printf("%d",  count);
	return 0;
}
int main()
{
	int x = 0;
	int y = 0;
	for (x = 0, y = 0; y < 5, x < 2; ++x, y++)
	{
		printf("heihei\n");
	}
	
	return 0;
}

int main()

{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
		printf("hehe\n");
		arr[i] = 0;
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