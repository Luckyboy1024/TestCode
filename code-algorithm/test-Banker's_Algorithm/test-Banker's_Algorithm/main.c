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
		printf(" *	Banker's_Algorithm (C).<���м��㷨>/<.��ȫ���㷨>\n");
		printf(" *	�ļ����ƣ�	Test--Banker's_Algorithm\n");
		printf(" *	�� �� �ߣ�	Keyu Jiang\n");
		printf(" *	�������ڣ�	2019.12.27\n");
		printf(" *	��    ����	����һ�����㷨�� demo��������������Ĳ���������\n");
		printf(" *			�Լ����м��㷨�Ļ���ԭ��\n");
		printf(" *\n");
		printf(" *			��C ����ʵ�֡�����ϵͳ--���м��㷨����\n");
		printf(" *\n");
		printf(" * =================================================================================== */\n\n");
	}

	void Print_All(char** name)
	{
		int i = 0;
		int j = 0;
		printf("\n >>>### ��ǰ��Դ������� ======>>\n\n");
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
			for (j = 0; j < num_resource; ++j)	//��ӡ MAX
			{
				printf("%3d ", Max[i][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//��ӡ Allocation
			{
				printf("%3d ", Allocation[i][j]);
			}printf("  |  ");
			for (j = 0; j < num_resource; ++j)//��ӡ Need
			{
				printf("%3d ", Need[i][j]);
			}printf("  |  ");
			if (0 == i)
			{
				for (j = 0; j < num_resource; ++j)//��ӡ Avaliable
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
		printf("\n\n�����뵱ǰϵͳ��������Դ���� :>_ ");
		scanf("%d", &num_resource);
		for (int i = 0; i < num_resource; ++i){
			printf("\n��Դ %d �Ĵ��� :>_ ", i + 1);
			scanf("%s", name[i]);
			printf("         ���� :>_ ");
			scanf("%d", &num[i]);
		}
		printf("\n\n������������Դ����������ҵ��Ŀ :>_ ");
		scanf("%d", &num_course);
		printf("\n��������������( %d * %d ) >> [Max] :>_\n", num_course, num_resource);
		//����
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				scanf("%d", &Max[i][j]);
			}
		}
		printf("\n������Դ�������( %d * %d ) >> [Allocation] :>_\n", num_course, num_resource);
		//����
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				scanf("%d", &Allocation[i][j]);
			}
		}
		printf("\n�����ʱ�������( %d * %d ) >> [Need] :>_\n", num_course, num_resource);
		//���
		Calculate(&num);
		for (int i = 0; i < num_course; ++i){
			printf("	");
			for (int j = 0; j < num_resource; ++j){
				printf("%d ", Need[i][j]);
			}
		}
		printf("\n\n<<-------------------- ��ʱ�̵���Դ������� -------------------->>\n");
		//���
		Print_All(name);
	}

	int menu()
	{
		int input = 0;
		printf("\n\n**==============================================================**\n");
		printf("\t  1����Դ�����ʼ������\n");
		printf("\t  2����ȫ���㷨����ȫ�Լ�飩\n");
		printf("\t  3�����м��㷨��Ԥ������Դ��\n");
		printf("\t  4���鿴��Դ�������\n");
		printf("\t  0���˳�ϵͳ\n");
		printf("**==============================================================**\n");
		printf(">>> ����ѡ�� :>_ ");  scanf("%d", &input);
		return input;
	}

	void process()
	{
		char* name[M];		// ��Դ����
		for (int n = 0; n < M; ++n){
			name[n] = (char*)malloc(NameWord * sizeof(char));
			*(name[n]) = NULL;
		}
		int num[M] = { 10, 5, 7 };// ��Դ��Ŀ
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
				printf("<<-------------------- ����ѡ����ڣ������� -------------------->>\n");
			}
		}
	}

	int main()
	{
		process();
		return 0;
	}
