#define _CRT_SECURE_NO_WARNINGS 1

	#include "main.h"
	#include "Safety.h"
	#include "Banker.h"

	num_resource = 3;
	num_course = 5;
	Max[N][M] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 },  { 4, 3, 3 } };
	Allocation[N][M] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };

	void Calculate(int* num)
	{
		for (int j = 0; j < num_resource; ++j)
		{
			int sum = 0;
			for (int i = 0; i < num_course; ++i)
			{
				Need[i][j] = Max[i][j] - Allocation[i][j];
				sum += Allocation[i][j];
			}
			Available[j] = num[j] - sum;
		}
	}

	void Statement()
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
		printf(" * =================================================================================== */\n\n");
	}

	void Print_All(char** name)
	{
		int i = 0;
		int j = 0;
		printf("\n >>>### 当前资源分配情况 ======>>\n\n");
		printf("*-----------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n| #  Re |  MAX       "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Allocation"); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Need      "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Avaliable "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|\n*   #   *---------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n| PCB # | ");
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < num_resource; ++j)
			{
				printf("%4s", name[j]);
			}printf("   | ");
		}
		printf("\n*-----------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n");
		for (i = 0; i < num_course; ++i)
		{
			printf("|  %3d  |  ", i + 1);
			for (j = 0; j < num_resource; ++j)	//打印 MAX
			{
				printf("%3d ", Max[i][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//打印 Allocation
			{
				printf("%3d ", Allocation[i][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//打印 Need
			{
				printf("%3d ", Need[i][j]);
			}printf("  |  ");
			if (0 == i)
			{
				for (j = 0; j < num_resource; ++j)//打印 Avaliable
				{
					printf("%3d ", Available[j]);
				}
				printf("  |\n");
			}
			else
			{
				for (int t = 0; t < num_resource; ++t) printf("    ");
				printf("  |\n");
			}
		}
		printf("*-----------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n");
	}

	void Init(char** name, int num[M])
	{
		printf("\n\n请输入当前系统待请求资源种类 :>_ ");
		scanf("%d", &num_resource);
		for (int i = 0; i < num_resource; ++i){
			printf("\n资源 %d 的代号 :>_ ", i + 1);
			scanf("%s", name[i]);
			printf("         数量 :>_ ");
			scanf("%d", &num[i]);
		}
		printf("\n\n请输入需向资源提出请求的作业数目 :>_ ");
		scanf("%d", &num_course);
		printf("\n输入最大需求矩阵( %d * %d ) >> [Max] :>_\n", num_course, num_resource);
		//输入
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				scanf("%d", &Max[i][j]);
			}
		}
		printf("\n输入资源分配矩阵( %d * %d ) >> [Allocation] :>_\n", num_course, num_resource);
		//输入
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				scanf("%d", &Allocation[i][j]);
			}
		}
		printf("\n输出此时需求矩阵( %d * %d ) >> [Need] :>_\n", num_course, num_resource);
		//输出
		Calculate(&num);
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				printf("%d ", Need[i][j]);
			}
		}
		printf("\n\n<<-------------------- 此时刻的资源分配情况 -------------------->>\n");
		//输出
		Print_All(name);
	}

	int menu()
	{
		int input = 0;
		printf("\n\n**==============================================================**\n");
		printf("\t  1、资源分配初始化输入\n");
		printf("\t  2、安全性算法（安全性检查）\n");
		printf("\t  3、银行家算法（预分配资源）\n");
		printf("\t  4、查看资源分配情况\n");
		printf("\t  0、退出系统\n");
		printf("**==============================================================**\n");
		printf(">>> 输入选项 :>_ ");  scanf("%d", &input);
		return input;
	}

	void process()
	{
		char* name[M];		// 资源代号
		for (int n = 0; n < M; ++n){
			name[n] = (char*)malloc(NameWord * sizeof(char));
			*(name[n]) = NULL;
		}
		int num[M] = { 10, 5, 7 };// 资源数目
		Calculate(&num);

		int input_menu = 0;
		Statement();

		while (input_menu = menu()){
			if (1 == input_menu){
				Init(name, &num);
			}
			else if (2 == input_menu){
				Safe_Algorithm(name);
			}
			else if (3 == input_menu){
				Banker_Algorithm(name);
			}
			else if (4 == input_menu){
				Print_All(name);
			}
			else{
				printf("<<-------------------- 输入选项不存在，请重输 -------------------->>\n");
			}
		}
	}

	int main()
	{
		process();
		return 0;
	}
