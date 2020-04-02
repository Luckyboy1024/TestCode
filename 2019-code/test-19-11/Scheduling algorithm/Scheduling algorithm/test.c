

#include "test.h"

double average(double** data, int n, int col)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += data[i][col];
	}
	return (sum / n);
}

void print_input(int** arr, int row, int col)
{
	printf("           |   AT   |   ST\n");		// AT表示到达时间，ST表示服务时间
	for (int i = 0; i < row; i++)
	{
		printf("----------------------------------\n");
		printf("process_%2d ", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf("| %4d   ", arr[i][j]);
		}
		printf("\n");
	}
}

void print_data(double** data, int row, int col)
{
	printf("           |   FT   |   TT   |   QTT\n");		// FT：完成时间，TT：周转时间，QTT：带权周转时间
	for (int i = 0; i < row; i++)
	{
		printf("-----------------------------------------\n");
		printf("process_%2d ", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf("|  %-2.3f ", data[i][j]);
		}
		printf("\n");
	}
}

void process_Scheduling(int** _arr, int n)
{
	double** data;
	data = (double **)malloc(n*sizeof(double*)) ;	//存放完成时间，周转时间，带权周转时间
	for (int i = 0; i < n; i++)
	{
		data[i] = (double *)malloc(3 * sizeof(double));
	}
	int input = 0;			//所选算法序号
	while (1)
	{
		printf("选择算法 :>_\n");
		printf("  | 1. FCFS | 2. SJF | 3. RR | 0. exit |\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			_FCFS(_arr, data, n, 2);
			break;
		case 2:
			_SJF(_arr, data, n, 2);
			break;
		case 3:
			_RR(_arr, data, n, 2);
			break;
		default:
			free(data);
			return 0;
		}
		print_data(data, n, 3);
		printf("  平均周转时间 ATT :>_ %.3f\n", average(data, n, 1));
		printf("  平均带权周转时间 ATT :>_ %.3f\n", average(data, n, 2));
		printf("--------------Over-------------");
	}
	free(data);
}

#if 1


int main()
{
	int n = 0;				//进程数
	printf("输入进程数目 :>_ ");
	scanf("%d", &n);
	int** arr;
	arr = (int **)malloc(n*sizeof(int*)) ;	//存放输入的进程到达 & 服务时间
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(2 * sizeof(int));
	}
	printf("分别输入各进程的到达时间和服务时间 :\n");
	for (int i = 0; i < n; i++)
	{
		printf("第 %d 个进程\n", i+1);
//		printf("\t进程名称 :>_"); scanf("%s", &(p->name));
		printf("\t到达时间 :>_"); scanf("%d", &arr[i][0]);
		printf("\t服务时间 :>_"); scanf("%d", &arr[i][1]);
	}
	print_input(arr, n, 2);
	printf("\n");
	process_Scheduling(arr, n);
	free(arr);
	return 0;
}

#endif
#if 0

void Init_process(Process p)
{
	p = (Process*)malloc();
	p.name = "null";
	p.time_reach = 0;
	p.time_serve = 0;
}

#endif