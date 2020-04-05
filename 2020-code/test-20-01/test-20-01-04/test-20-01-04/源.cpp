#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <limits.h>  
#include <malloc.h>      
#include <cstdlib>   
#include <string.h>
// 图的邻接表存储表示 
#define MAX_NAME 3					// 顶点字符串的最大长度+1 
#define MAX_VERTEX_NUM 20

typedef int InfoType;				// 存放网的权值 
typedef char VertexType[MAX_NAME];	// 字符串类型 

typedef struct ArcNode
{
	int adjvex;					// 该弧所指向的顶点的位置 
	struct ArcNode *nextarc;	// 指向下一条弧的指针 
	InfoType *info;				// 网的权值指针） 
}ArcNode;	// 表结点 

typedef struct VNode
{
	VertexType data;			// 顶点信息 
	ArcNode *firstarc;			// 第一个表结点的地址,指向第一条依附该顶点的弧的指针 
}VNode, AdjList[MAX_VERTEX_NUM];// 头结点 

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;	// 图的当前顶点数和弧数 
}ALGraph;

int ve[MAX_VERTEX_NUM]; // 全局变量

// 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1。 
int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(u, G.vertices[i].data) == 0)
			return i;
	}
	return -1;
}

int CreateGraph(ALGraph *G)
{
	int i, j, k;
	int w;	//权值
	ArcNode *p;
	VertexType va, vb;
	printf("请输入顶点和边的数目 :>\n");
	printf("  顶点数目 :>_ "); scanf("%d", &(*G).vexnum);
	printf("  边的数目 :>_ "); scanf("%d", &(*G).arcnum);
	printf("\n请输入各顶点代号 :>\n");
	for (i = 0; i < (*G).vexnum; ++i) 
	{
		printf("  顶点 V%d :>_ ", i);
		scanf("%s", &(*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;
	}
	printf("依次输入每条边的属性 :>\n");
	for (k = 0; k < (*G).arcnum; ++k)
	{
		printf("  第 %d 条边的[权值] :>_ ", k + 1); scanf("%d", &w);
		printf("  第 %d 条边的[弧头] :>_ ", k + 1); scanf("%s", &vb);
		printf("  第 %d 条边的[弧尾] :>_ ", k + 1); scanf("%s", &va);
		i = LocateVex(*G, va);
		j = LocateVex(*G, vb);//定位
		p = (ArcNode*)malloc(sizeof(ArcNode));//申请一个结点
		p->adjvex = j;
		p->info = (int*)malloc(sizeof(int));
		*(p->info) = w;//赋值
		p->nextarc = (*G).vertices[i].firstarc;//连接结点
		(*G).vertices[i].firstarc = p;
	}
	return 1;
}
void print(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("%d个顶点：\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		printf("%s ", G.vertices[i].data);
	printf("\n%d条弧(边):\n", G.arcnum);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%s→%s ", G.vertices[i].data,
				G.vertices[p->adjvex].data);
			printf(":%d ", *(p->info));
			p = p->nextarc;
		}
		printf("\n");
	}
}

//求顶点的入度
void findindegree(ALGraph G, int indegree[])
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
		indegree[i] = 0;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
		printf("\n");
	}
}
typedef int SElemType; // 栈类型
#define STACK_INIT_SIZE 10	// 存储空间初始分配量 
#define STACKINCREMENT 2	// 存储空间分配增量 
// 栈的顺序存储表示 P46 
typedef struct SqStack
{
	SElemType *base;	// 在栈构造之前和销毁之后，base的值为NULL 
	SElemType *top;		// 栈顶指针 
	int stacksize;		// 当前已分配的存储空间，以元素为单位 
}SqStack;	// 顺序栈
//	构造一个空栈S。
int InitStack(SqStack *S)
{
	// 为栈底分配一个指定大小的存储空间
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(0);		// 存储分配失败 
	(*S).top = (*S).base;	// 栈底与栈顶相同表示一个空栈
	(*S).stacksize = STACK_INIT_SIZE;
	return 1;
}
// 若栈S为空栈（栈顶与栈底相同的），则返回1，否则返回0。
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}
//	插入元素e为新的栈顶元素。
int Push(SqStack *S, SElemType e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)	// 栈满，追加存储空间 
	{
		(*S).base = (SElemType *)realloc((*S).base,
			((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			exit(0); // 存储分配失败 
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;

	return 1;
}

int Pop(SqStack *S, SElemType *e)
{
	if ((*S).top == (*S).base)
		return 0;
	*e = *--(*S).top;
	// 这个等式的++ * 优先级相同，但是它们的运算方式，是自右向左
	return 1;
}
int Topolog(ALGraph G, SqStack *T) {
	int j, k, count, indegree[MAX_VERTEX_NUM];
	SqStack S;
	ArcNode *p;
	findindegree(G, indegree);//求各顶点入度
	InitStack(&S);
	for (j = 0; j < G.vexnum; j++)
	if (!indegree[j])  Push(&S, j);//度为0入栈
	InitStack(T);
	count = 0;//对输出顶点记数
	for (j = 0; j < G.vexnum; ++j)
		ve[j] = 0;
	while (!StackEmpty(S)) {
		Pop(&S, &j);
		Push(T, j);
		++count;
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (--indegree[k] == 0)  Push(&S, k);
			if (ve[j] + *(p->info) > ve[k])
				ve[k] = ve[j] + *(p->info);//最早发生时间ve
		}
	}
	if (count < G.vexnum)
	{
		printf("此有向图有回路\n");
		return 0;
	}
	else return 1;
}
//关键活动
int activity(ALGraph G)
{
	int vl[MAX_VERTEX_NUM];
	SqStack T;
	int i, j, k, ee, el;
	ArcNode *p;
	char dut, tag;

	if (!Topolog(G, &T)) // 产生有向环 
		return 0;
	j = ve[0];
	for (i = 1; i < G.vexnum; i++) // j=Max(ve[]) 完成点的值 
	if (ve[i] > j)
		j = ve[i];
	for (i = 0; i < G.vexnum; i++) // 初始化顶点事件的最迟发生时间(最大值) 
		vl[i] = j; // 完成点的最早发生时间 
	while (!StackEmpty(T)) // 按拓扑逆序求各顶点的vl值 
	for (Pop(&T, &j), p = G.vertices[j].firstarc; p; p = p->nextarc)
	{
		k = p->adjvex;
		dut = *(p->info); // dut<j,k> 
		if (vl[k] - dut < vl[j])
			vl[j] = vl[k] - dut;//最迟发生时间
	}
	printf(" j  k  dut  ee  el  tag\n");
	for (j = 0; j < G.vexnum; ++j) // 求ee,el和关键活动 
	for (p = G.vertices[j].firstarc; p; p = p->nextarc)
	{
		k = p->adjvex;
		dut = *(p->info);
		ee = ve[j];
		el = vl[k] - dut;
		tag = (ee == el) ? '*' : ' ';
		// 输出关键活动
		printf("%2d %2d %3d %3d %3d    %c\n", j, k, dut, ee, el, tag);
	}
	printf("关键活动为:\n");
	for (j = 0; j < G.vexnum; ++j) // 同上 
	for (p = G.vertices[j].firstarc; p; p = p->nextarc)
	{
		k = p->adjvex;
		dut = *(p->info);
		if (ve[j] == vl[k] - dut)
			// 输出关键活动 
			printf("%s→%s\n", G.vertices[j].data, G.vertices[k].data);
	}
	return 1;
}

int main()
{
	ALGraph h;
	CreateGraph(&h);
	print(h);
	activity(h);
	return 0;
}

