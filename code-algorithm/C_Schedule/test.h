#define _CRT_SECURE_NO_WARNINGS 1

#define _NUM 100

#include <stdio.h>

// 平均带权周转时间：AQTT
// 平均周转时间：  ATT    Average turnover time


typedef struct Database
{
	int _FT;			// 完成时间 finish time
	int _TT;			// 周转时间 turnover time
	int _QTT;			// 带权周转时间
}Database;

typedef struct Process 		// 进程
{
	int num;
	char name[10];			// 进程名称
	int time_reach;			// 到达时间
	int time_serve;			// 服务时间
	Database data;
}Process;