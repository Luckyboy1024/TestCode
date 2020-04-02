#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int Partion(int arr[], int left, int right)
{
	int tmp = 0;
	tmp = arr[left]; 
	while (left < right)
	{
		while ((left < right) && (arr[right] > tmp))
		{
			right--;
		}
		if (left == right)
		{
			arr[left] = tmp;
			break;
		}
		else if (arr[right] <= tmp)
		{
			//去右边找
		}
		while ((left < right) && (arr[left] < tmp))
		{
			left++;
		}
		if (left == right)
		{
			arr[left] = tmp;
			break;
		}
		else
		{
			//去做边找
		}
	}
	return left;
}

int main()
{

}




#if 0

int main()
{
	int n = 0;
	int a[100] = { 0 };
	int b[100] = { 0 };
	int i = 0;
	printf("a:>_");
	while (('\n' - '0') != (a[i] = (getchar() - '0'))){ i++; }
	printf("b:>_");
	while (('\n' - '0') != (b[i] = (getchar() - '0'))){ i++; }
	
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将字符串中的空格转换为%20
#define Space 2

void Re_Spacing(char str[], int len)
{
	char *q = str + len + 2 * Space;
	char *p = str + len;
	while ((p - str >= 0) && (p - q < 0))
	{
		if (' ' != *p)
		{
			strcpy(q, p);
			p--;
			q--;
		}
		else if (' ' == *p)
		{
			*q = '0';
			*(q - 1) = '2';
			*(q - 2) = '%';
			q -= 3;
			p--;
		}
	}
	while ((p - str >= 0) && (0 == p - q))
	{
		strcpy(q, p);
		p--;
		q--;
	}
}

int main()
{
	char arr[] = "hello dear boy";
	int len = strlen(arr);
	Re_Spacing(arr, len);
	return 0;
}
extern “C”
{
	void foo(int x, int y);
	{
		void foo(int x, int y);
		⋯  // 其它函数
	}
}

extern “C”
{
	#include “myheader.h”
	⋯  // 其它C头文件
}


#define N 3

void Func2(int arr[][N])
{
	int row = 0;
	int col = N/2;
	int i = 2;
	arr[row][col] = 1;
	for (i = 2; i <= N * N; i++)
	{
		row = (row - 1 + N) % N;
		col = (col + 1) % N;
		if(0 == arr[row][col])
		{
			arr[row][col] = i;
		}
		else
		{
			row = (row + 1 + N) % N;
			arr[row][col] = i;
		}
	}
	for (i = 0; i < N * N; i++)
	{
		if (0 == i%N)
		{
			printf("\n");
		}
		printf("%-2d ", *(*(arr)+i));
	}
}

int main()
{
	int arr[N][N] = { 0 };
	Func2(arr);

		return 0;
}

	#include <stdio.h>
	#include <stdlib.h>

	#include <assert.h>

	void Find_val(int* arr, int row, int col, int num)
	{
		assert(arr);
		int *str = arr;
		int i = 0;
		int j = col - 1;
		while ((i < row) && (j>=0))
		{
			if (*(arr + col*i + j) < num)
			{
				i++;	
			}
			else if (*(arr + col*i + j) > num)
			{
				j--;
			}
			else if (num == *(arr + col*i + j))
			{
				printf("find it:>_ arr[%d][%d]\n", i, j);
				return;
			}
			else
			{
				//do nothing
			}
		}
		printf("sorry can't find it\n");
	}

	int main()
	{
		int arr[4][4] = {
			1, 2, 8, 9,
			2, 4, 9, 12,
			4, 7, 10, 13,
			6, 8, 11, 15,
		};
		int row = sizeof(arr) / sizeof(arr[0]);
		int col = sizeof(arr[0]) / sizeof(arr[0][0]);

		Find_val(arr, row, col, 7);
		return 0;
	}


int main()
{
	return 0;
}


#endif