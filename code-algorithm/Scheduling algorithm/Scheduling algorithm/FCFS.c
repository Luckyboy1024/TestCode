#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void _FCFS(int** arr, double** data, int n)
{
	data[0][0] = (double)arr[0][1];
	data[0][1] = fabs(data[0][0] - (double)arr[0][0]);
	data[0][2] = data[0][1] / (double)arr[0][1];
	for (int i = 1; i < n; i++)
	{
		if (data[i - 1][0] >= arr[i][1])
		{
			data[i][0] = data[i - 1][0] + (double)arr[i][1];
		}
		else
		{
			data[i][0] = (double)arr[i][0] + (double)arr[i][1];
		}
		data[i][1] = fabs(data[i][0] - (double)arr[i][0]);
		data[i][2] = data[i][1] / (double)arr[i][1];
	}
}