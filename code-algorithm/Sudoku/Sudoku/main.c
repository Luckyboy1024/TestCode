#define _CRT_SECURE_NO_WARNINGS 1

#include "main.h"

void test()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%d ", _sudoku[i][j]);
		}
		printf("\n");
	}
}

#if 0
int main()
{
	test();
	return 0;
}
#endif