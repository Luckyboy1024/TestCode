	#define _CRT_SECURE_NO_WARNINGS 1


	#include "Safety.h"



	void Print_Safe(char** name)
	{
		int i = 0;
		int j = 0;
		printf("\n >>>### 安全性检查 ======>>\n\n");
		printf("*--------------------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n| #  Re |  Work      "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Need      "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Allocation"); for (i = num_resource; i > 2; --i)printf("    ");
		printf("|  Work + Al "); for (i = num_resource; i > 2; --i)printf("    ");
		printf("| Finish "); 
		printf("|\n*   #   *---------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*        *\n| PCB # | ");
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < num_resource; ++j)
			{
				printf("%4s", name[j]);
			}printf("   | ");
		}
		printf("       |\n*--------------------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n");
		for (i = 0; i < num_course; ++i)
		{
			printf("|  %3d  |  ", i + 1);
			for (j = 0; j < num_resource; ++j)	//打印 Work
			{
				printf("%3d ", WORK[i][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//打印 Need
			{
				printf("%3d ", Need[p[i]][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//打印 Allocation
			{
				printf("%3d ", Allocation[p[i]][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//打印 Work + Allocation
			{
				printf("%3d ", WORK[i][j] + Allocation[p[i]][j]);
			}printf("  |  ");
			//打印 Finish
			if (1 == Finish[i])
			{
				printf("true ");
			}
			else{
				printf("false");
			}
			printf(" |  \n");
		}
		printf("*--------------------------------------------------------------------");
		for (i = num_resource; i > 2; --i)printf("----------------");
		printf("*\n");
	}



	int Safe_Algorithm(char** name)
	{
		int a = 0;
		int i = 0;
		Datatype Work[M];
		for (i = 0; i < num_resource; ++i)
		{
			Work[i] = Available[i];
		}
		for (i = 0; i < num_course; ++i)
		{
			Finish[i] = False;
		}
		for (i = 0; i < num_course; ++i)
		{
			if (True == Finish[i]){
				continue;
			}
			int j;
			for (j = 0; j < num_resource; ++j)
			{
				if (Need[i][j] > Work[j]){
					break;
				}
			}
			if (j == num_resource)
			{
				Finish[i] = True;
				printf("找到作业 ( PCB : %d ) 满足 :>\n", i + 1);
				printf("    Finish[%d] = false; Need[%d] <= Work\n", i, i);
				for (int k = 0; k < num_resource; ++k)
				{
					WORK[a][k] = Work[k];
					Work[k] += Allocation[i][k];
				}
				p[a++] = i;
				i = -1;
			}
			else continue;
		}
		if (a == num_course)
		{
			printf("\n>>> 系统是安全的；系统的安全序列是  :>_\n	");
			for (int i = 0; i < a; ++i)
			{
				printf("%d", p[i] + 1);
				if (i != a - 1){
					printf(" ==> ");
				}
			}
			Print_Safe(name);
			printf("\n");
			return 1;
		}
		else
		{
			printf("\n>>> 寻找安全序列失败..........\n");
			return 0;
		}
	}
