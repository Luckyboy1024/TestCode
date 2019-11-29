#define _CRT_SECURE_NO_WARNINGS 1

#include "main.h"

// ƽ����Ȩ��תʱ�䣺AQTT
// ƽ����תʱ�䣺  ATT    Average turnover time

typedef struct Database
{
	double _FT;			// ���ʱ�� finish time
	double _TT;			// ��תʱ�� turnover time
	double _QTT;			// ��Ȩ��תʱ��
}Database;

typedef struct Process 		// ����
{
	double time_reach;			// ����ʱ�� AT
	double time_serve;			// ����ʱ�� ST
	int num;				// ����ʱ������� 0 1 2 
	char name[10];			// ��������
	Database data;
}Process;



// ��������

void BubbleSort(Process *arr, int n);
void Swap(Process* arr1, Process* arr2);


void _FCFS(Process *arr, int n);
void _SJF(Process *arr, int n);
void _RR(Process *arr, int n);


