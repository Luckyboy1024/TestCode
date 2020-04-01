
#define _CRT_SECURE_NO_WARNINGS 1

#if 0



#include <stdio.h>
#include <string.h>


int My_strlen(const char* string)
{
	int count = 0;

	return count;
}

int main()
{
	char* str = "abcdefg123";		//123Õ¼3¸ö×Ö·û
	int len = strlen(str);
	printf("%d\n", len);
	return 0;
}

#endif
#include <stdio.h>
#define ROW 9
#define COL 9
#define Mine 10

#define re_row ROW+2
#define re_col COL+2


//void show_board(char arr[re_row][re_col], int row, int col)				//´òÓ¡ÆåÅÌ

int main()
{
	char arr[11][re_col] = { 0 };
	int row = re_row;
	int col = re_col;
	int i = 0;
	int j = 0;
	//system("cls");
	printf("¡ö");
	for (j = 1; j < row + 1; j++)
	{
		printf("  %-2d", j);
	}
	printf("  ¡ö\n");

	for (i = 0; i < row + 1; i++)
	{
		printf("  ");
		for (j = 0; j < col + 1; j++)
		{
			printf("*");
			if (j < col)
			{
				printf("---");
			}
		}
		printf("\n");
		if (i < row)
		{
			printf("%-2d", i + 1);
			for (j = 0; j < col + 1; j++)
			{
				printf("|");
				if (j < col)
				{
					printf(" %c ", arr[i][j]);
				}
			}
			printf("%2d", i + 1);
			printf("\n");
		}
	}
	printf("¡ö");
	for (j = 1; j < row + 1; j++)
	{
		printf("  %-2d", j);
	}
	printf("  ¡ö\n");
	return 0;
}