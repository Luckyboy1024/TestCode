
// 队列实现：时间片轮转
// 时间片轮转算法

#include "test.h"

void pop_head(int *arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[len - 1] = 0;
}


void updata(int *arr, int len)
{
	int tmp = arr[0];
	for (int i = 1; i < len; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[len-1] = tmp;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int* AT, int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (AT[j - 1]>AT[j])
			{
				Swap(&AT[j - 1], &AT[j]);
				Swap(&a[j - 1], &a[j]);
			}
		}
	}
}

void _RR(int** arr, double** data, int n)
{
	int now = 0;
	int slot;			// 变量存放时间片
	int AT[_NUM];		// 到达时间
	int at[_NUM];		// 
	int ST[_NUM];		// 服务时间
	int st[_NUM];		// 剩余服务时间
	int TT[_NUM];		// 周转时间
	int FT[_NUM];		// 完成时间
	int a[_NUM] = { 0 };		// 到达时间：进程序列（进程号）
	int arri = 0;		// 到达队列中走到第几个进程
	int b[_NUM] = { -1 };		// 等待队列（进程号）
	int tail = 0;		// 等待对列队尾下标


	printf("输入时间片 :>_ ");
	scanf("%d", &slot);
	
	for (int i = 0; i < n; i++)
	{
		at[i] = AT[i] = arr[i][0];
		ST[i] = st[i] = arr[i][1];
		a[i] = i;
	}
	sort(at, a, n);
	
	// 到达队列中第一个进程进入等待队列
	b[0] = a[0];		//b[0]  =  a[arri];
	now = AT[b[0]];
	//下次从 a[1] 开始
	
	while ((tail > -1)&&(arri <= n))		//while(arri = n)
	{
		// 等待队列中第一个进程分一个时间片
		/*st[b[0]] -= slot;
		now += slot;
	*/
		// 检查此时是否有进程即将进入
		while(AT[a[arri+1]] > now || (arri == n))	//没有
		{
			if (!((st[b[0]] - slot) > 0))
			{
				now += st[b[0]];
				st[b[0]] = 0;
				data[b[0]][0] = (double)now;
				data[b[0]][1] = (double)fabs(now - ST[b[0]]);
				data[b[0]][2] = (double)(data[b[0]][1]) / (double)(ST[b[0]]);
				pop_head(b, tail+1);
				tail--;		
			}
			else
			{
				st[b[0]] -= slot;
				now += slot;
			}
			if (arri == n)
			{
				return 0;
			}
		}
		if (arri <= n)
		{
			b[++tail] = a[++arri];		//进入队尾
		}
		else
		{
			return 0;
		}
		if (-1 == tail)
		{
			return 0;
		}

		// 时间片结束，等待队列更新
		updata(b, tail+1);
	}



	printf("hehe");
	
//	data[i][1] = fabs(data[i][0] - (double)arr[i][0]);		// (FT,AT) ==>>  周转时间
//	data[i][2] = data[i][1] / (double)arr[i][1];			// (TT,ST) ==>>  带权周转时间
}





#if 0

typedef struct ProcessNode{		//进程节点
	double _AT;	//到达时间 AT
	double _ST; //服务时间 ST
	double _st; //剩余服务时间
	double _TT; //周转时间 TT
	double _FT; //完成时间 FT
}Process, *PNode;


typedef struct R_queue{
	struct R_queue *front;
	int** data;
	struct R_queue *next;
}RQ;

void push(RQ* head, int** data)
{

}

void pop()
{

}

RQ* _head()
{
	RQ head;
	head.data = 0;
	head.front = NULL;
	head.next = NULL;
	return &head;
}












#endif