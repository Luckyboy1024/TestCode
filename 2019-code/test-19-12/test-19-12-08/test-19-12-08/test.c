#define _CRT_SECURE_NO_WARNINGS 1

// 项目——九宫格

#include <stdio.h>
#include <stdint.h>

#define ROW 9
#define COL 9
#define _row (ROW / 3)	// 3*3 块 行
#define _col (COL / 3)	// 3*3 块 列


void print(uint32_t* arr, uint32_t row, uint32_t col)
{
	for (int i = 0; i < row; ++i)
	{
		if (0 == i % 3)
		{
			for (int j = 0; j < (col / 3); ++j)
			{
				printf("+-----------");
			}
			printf("+\n");
		}
		else
		{
			for (int j = 0; j < (col / 3); ++j)
			{
				printf("|- - - - - -");
			}
			printf("|\n");
		}
		for (int j = 0; j < col; ++j)
		{
			printf("|%2d ", *(arr + i*row + j));
		}
		printf("|\n");
	}
	for (int j = 0; j < (col / 3); ++j)
	{
		printf("+-----------");
	}
	printf("+\n");
}

void start()
{
	uint32_t arr[ROW][COL] = { 0 };
	uint32_t row = ROW;
	uint32_t col = COL;
	do
	{
		print(arr, row, col);
	} while (1);
}

int main()
{
	start();
	return 0;
}


#if 0


for (int i = 0; i < row; ++i)
{
	for (int j = 0; j < col; ++j)
	{
		printf("----");
	}
	printf("-\n");
	for (int j = 0; j < col; ++j)
	{
		printf("|%2d ", *(arr + i*row + j));
	}
	printf("|\n");
}
for (int j = 0; j < col; ++j)
{
	printf("----");
}
printf("-\n");

#endif
