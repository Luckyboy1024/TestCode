#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

#define False 0
#define True 1

#define M 50		//最大资源数
#define N 20		//最大作业数
#define NameWord 8	//资源名称大小

typedef int Datatype;

Datatype Available[M];
Datatype Max[N][M];
Datatype Allocation[N][M];
Datatype Need[N][M];
Datatype Request[N][M];
Datatype Finish[N];
Datatype p[N];
Datatype WORK[N][M];

int num_resource;	//资源数目
int num_course;		//作业数目

void Calculate(int* num);
void Statement();
void Print_All(char** name);
void Init(char** name, int num[M]);
int menu();
void process();



#if 0

#define _CRT_SECURE_NO_WARNINGS 1

void print_menu()
{
	printf("*----------------------------------------------------------*\n");
	printf("| PCB |  MAX   |   Allocation  |    Need  |    Avaliable  |*\n");
	printf("*----------------------------------------------------------*\n");

}

void Menu()
{
	printf("/* =================================================================================== */\n");
	printf(" *	Banker's_Algorithm (C).<银行家算法>/<.安全性算法>\n");
	printf(" *	文件名称：	Test--Banker's_Algorithm\n");
	printf(" *	创 建 者：	Keyu Jiang\n");
	printf(" *	创建日期：	2019.12.27\n");
	printf(" *	描    述：	这是一个的算法的 demo，用于体会死锁的产生及避免\n");
	printf(" *			以及银行家算法的基本原理。\n");
	printf(" *\n");
	printf(" *			《C 语言实现“操作系统--银行家算法”》\n");
	printf(" *\n");
	printf(" * =================================================================================== */\n");

	printf("\n+---------------------------------------------+");
	printf("\n     1.矩阵初始化    ");
	printf("\n     2.安全性算法    ");
	printf("\n     3.银行家算法    ");
	printf("\n     4.查看当前      ");
	printf("\n     0.退出系统      ");
	printf("\n+----------------------------------------------+\n\n");
}



#endif
