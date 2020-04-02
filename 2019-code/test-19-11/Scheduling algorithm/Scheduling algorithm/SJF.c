#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void _SJF(int** arr, double** data, int n)
{
	data[0][0] = (double)arr[0][1];
	data[0][1] = fabs(data[0][0] - (double)arr[0][0]);
	data[0][2] = data[0][1] / (double)arr[0][1];
	int T[_NUM] = { 0 };		//设置访问标志位
	int num = n;
	int s = 0;		//当前进程进程号
	while (--num)
	{
		int p = 0;		//服务时间最短进程的进程号
		int tag = 0;		//是否存在标志
		double tmp = data[s][0];	//当前进程的完成时间
		int min_ST = INT_MAX;			//最短服务时间
		for (int i = 1; i < n; i++)
		{
			// 存在下一进程在当前进程完成前到达
			// 找出其中服务时间最短的进程
			if ((tmp >= (double)arr[i][0])
				&& (arr[i][1] < min_ST)
				&& T[i] != 1)
			{
				min_ST = arr[i][1];
				p = i;
				tag = 1;
			}
		}
		if (0 == tag)
		{
			// 不存在：
			int i = n;
			while ((T[n - i] == 1) && (--i));
			if (0 == i) continue;//return 0;
			data[i][0] = (double)arr[i][0] + (double)arr[i][1];
			data[i][1] = fabs(data[i][0] - (double)arr[i][0]);
			data[i][2] = data[i][1] / (double)arr[i][1];
		}
		else if (1 == tag)
		{
			T[p] = 1;
			data[p][0] = (double)data[s][0] + (double)arr[p][1];
			data[p][1] = fabs(data[p][0] - (double)arr[p][0]);
			data[p][2] = data[p][1] / (double)arr[p][1];
			s = p;
		}
	}
}