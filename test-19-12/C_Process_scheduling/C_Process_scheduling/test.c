#define _CRT_SECURE_NO_WARNINGS 1

#include "Process_scheduling.h"
#include "Queue.h"
#include "main.h"

void _print(Process* arr, int n)
{
	double ATT = 0;
	double AQTT = 0;
	printf("\n PName    ATime    STime    FTime    TTime   QTTime\n");
	for (int i = 0; i < n; ++i)
	{
		printf("   %-4s %7.2lf  %7.2lf  %7.2lf  %7.2lf  %7.2lf\n", arr[i].name,
			arr[i].time_reach, arr[i].time_serve,
			arr[i].data._FT, arr[i].data._TT, arr[i].data._QTT);
		ATT += arr[i].data._TT;
		AQTT += arr[i].data._QTT;
	}
	printf("\n平均周转时间 ATT :>_ %5.2f\n", (ATT / n));
	printf("平均带权周转时间 AQTT :>_ %5.2f\n", (AQTT / n));
}


int menu(Process *arr, int n)
{
	int input = 0;
	printf("\n  |  1.FCFS  |  2.SJF  |  3.RR  |  0.exit  |   choose :>_ ");
	scanf("%d", &input);
	if (0 == input)
	{
		return 0;
	}
	else if (1 == input)
	{
		_FCFS(arr, n);
		_print(arr, n);
		return 1;
	}
	else if (2 == input)
	{
		_SJF(arr, n);
		_print(arr, n);
		return 1;
	}
	else if (3 == input)
	{
		_RR(arr, n);
		_print(arr, n);
		return 1;
	}
	return 0;
}

void _input(int n, Process* arr)
{
	for (int i = 0; i < n; ++i)
	{
		printf("第 %d 个进程\n", i + 1);
		printf("\t进  程  名   :>_ "); scanf("%s", &arr[i].name);
		printf("\t进程到达时间 :>_ "); scanf("%lf", &arr[i].time_reach);
		printf("\t进程服务时间 :>_ "); scanf("%lf", &arr[i].time_serve);
		arr[i].num = i;
		arr[i].data._FT = 0.0;
		arr[i].data._TT = 0.0;
		arr[i].data._QTT = 0.0;
	}
}

void start()
{
	Process arr[_NUM];
	int input = 0;
	printf("进程数目 :>_ ");
	scanf("%d", &input);
	_input(input, arr);
	_print(arr, input);
	while (menu(arr, input));
}