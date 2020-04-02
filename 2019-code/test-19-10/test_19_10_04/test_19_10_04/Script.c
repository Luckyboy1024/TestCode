#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

int *fillnumber(int a[_ROW][_COL][10], int number, int i, int j)
{
	for (int k = 0; k < _ROW; k++)
	{
		a[i][k][number]--;
		a[k][j][number]--;
	}
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
		{
			a[i / 3 * 3 + n][j / 3 * 3 + m][number]++;
		}
	}
	return a;
}

int *resetnumber(int a[_ROW][_COL][10], int number, int i, int j)
{
	for (int k = 0; k < 9; k++)
	{
		a[i][k][number]--;
		a[k][j][number]--;
	}
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
		{
			a[i / 3 * 3 + n][j / 3 * 3 + m][number]--;
		}
	}
	return a;
}

void search(int step, int a[_ROW][_COL], int g[_ROW][_COL][10])
{
	if (0 == step)
	{
		for (int i = 0; i < _ROW; i++)
		{
			for (int j = 0; j < _COL; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	for (int i = 0; i < _ROW; i++)
	{
		for (int j = 0; j < _COL; j++)
		{
			if (0 == a[i][j])
			{
				for (int number = 1; number < 10; number++)
				{
					if (0 == g[i][j][number])
					{
						fillnumber(g, number, i, j);
						a[i][j] = number;
						search(step - 1, a, g);
						a[i][j] = 0;
						resetnumber(g, number, i, j);
					}
				}
				return;
			}
		}
	}
}


void Script()
{
	int a[_ROW][_COL];
	int abool[_ROW][_COL][10];
	int step = 0;
	for (int i = 0; i < _ROW; i++)
	{
		for (int j = 0; j < _COL; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				abool[i][j][k] = 0;
			}
		}
	}
	printf("请输入 :>_\n");
	for (int i = 0; i < _ROW; i++)
	{
		printf("第 %d 行 :>_ ", i + 1);
		for (int j = 0; j < _COL; j++)
		{
			scanf("%d", &a[i][j]);
			if (0 == a[i][j])
			{
				step++;
			}
			else
			{
				fillnumber(abool, a[i][j], i, j);
			}
		}
		printf("检查输入....\n");
		Sleep(1000);
		printf("没有问题..\n");
	}
	search(step, a, abool);
}
