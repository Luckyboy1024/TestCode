#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>

int main()
{
	FILE* fp;
	char fname[50];		//文件名长度在此约定不大于50，包含拓展名
	int i, j, x, y, k, s, w, t, a[12][12];
	printf("\n input file name :>_ ");
	gets(fname);
	if (NULL == (fp = fopen(fname, "r")))
	{
		printf("The file was not opened\n");
		return;
	}
	x = 11;
	y = 11;
	for (i = 0; i <= y; ++i)
	{
		printf("\n    ");
		for (j = 0; j <= x; ++j)
		{
			fscanf(fp, "%d", &a[i][j]);		//从文件读数据到二维a数组
			printf("%d ", a[i][j]);
		}
	}
	for (i = 0; i <= x; ++i)
	{
		if (0 == a[0][i])
			a[0][i] = 2;	//把边上的0转换为2
		if (0 == a[y][i])
			a[y][i] = 2;
	}
	for (i = 1; i < y; i++)
	{
		if (0 == a[i][0])
			a[i][0] = 2;
		if (0 == a[i][x])
			a[i][x] = 2;
	}
	t = x * y;
	for (k = 1; k < t; k++)
	{
		w = 0;
		for (i = 1; i < y; i++)
		{
			for (j = 1; j < x; j++)
			{
				if (((2 == a[i][j - 1]) || (2 == a[i][j + 1]) || (2 == a[i - 1][j]) || (2 == a[i + 1][j])) && (0 == a[i][j]))
				{
					a[i][j] = 2;
					w = 1;			//若0的上下左右之一为2，则0转换为2
				}
			}
		}
		if (0 == w) break;
	}
	s = 0;
	printf("\n");
	for (i = 0; i <= y; i++)
	{
		printf("\n");
		for (j = 0; j <= x; j++)
		{
			if (0 == a[i][j])
			{
				s += 1;			//统计曲线内“0”点数
			}
			printf("%d ", a[i][j]);		//输出处理后的地图
		}
	}
	printf("\ns = %d\n", s);
	fclose(fp);
	return 0;
}

#endif

