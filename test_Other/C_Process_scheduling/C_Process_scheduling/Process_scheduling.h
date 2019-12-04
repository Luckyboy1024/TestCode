#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// 平均带权周转时间：AQTT
// 平均周转时间：  ATT    Average turnover time


typedef struct database
{
	double _FT;			// 完成时间 finish time
	double _TT;			// 周转时间 turnover time
	double _QTT;			// 带权周转时间
}Database;

typedef struct process 		// 进程
{
	double time_reach;			// 到达时间 AT
	double time_serve;			// 服务时间 ST
	int num;				// 输入时进程序号 0 1 2 
	char name[10];			// 进程名称
	Database data;
}Process;



// 函数声明



void BubbleSort(Process *arr, int n);
void Swap(Process* arr1, Process* arr2);
void InitProcess(Process* p);


void _FCFS(Process *arr, int n);
void _SJF(Process *arr, int n);
void _RR(Process *arr, int n);

void RR_HeadPush(Process* arr, int size);		//队头移到队尾
void RR_Push(Process* arr, Process*src, int size);		//插入队尾
void RR_Pop(Process* arr, int size);

