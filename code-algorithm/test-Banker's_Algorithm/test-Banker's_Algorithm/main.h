#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

#define False 0
#define True 1

#define M 50		//�����Դ��
#define N 20		//�����ҵ��
#define NameWord 8	//��Դ���ƴ�С

typedef int Datatype;

Datatype Available[M];
Datatype Max[N][M];
Datatype Allocation[N][M];
Datatype Need[N][M];
Datatype Request[N][M];
Datatype Finish[N];
Datatype p[N];
Datatype WORK[N][M];

int num_resource;	//��Դ��Ŀ
int num_course;		//��ҵ��Ŀ

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
	printf(" *	Banker's_Algorithm (C).<���м��㷨>/<.��ȫ���㷨>\n");
	printf(" *	�ļ����ƣ�	Test--Banker's_Algorithm\n");
	printf(" *	�� �� �ߣ�	Keyu Jiang\n");
	printf(" *	�������ڣ�	2019.12.27\n");
	printf(" *	��    ����	����һ�����㷨�� demo��������������Ĳ���������\n");
	printf(" *			�Լ����м��㷨�Ļ���ԭ��\n");
	printf(" *\n");
	printf(" *			��C ����ʵ�֡�����ϵͳ--���м��㷨����\n");
	printf(" *\n");
	printf(" * =================================================================================== */\n");

	printf("\n+---------------------------------------------+");
	printf("\n     1.�����ʼ��    ");
	printf("\n     2.��ȫ���㷨    ");
	printf("\n     3.���м��㷨    ");
	printf("\n     4.�鿴��ǰ      ");
	printf("\n     0.�˳�ϵͳ      ");
	printf("\n+----------------------------------------------+\n\n");
}



#endif
