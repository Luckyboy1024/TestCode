#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整
void ShiftDown(HPDataType* a, int n, int root)	//n是数组大小，root根的下标
{
	int parent = root;
	int child = 2 * parent + 1;	//左孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(a+child, a+parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break; 
		}
	}
}

//向上调整
void ShiftUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) >> 1;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(a + parent, a + child);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			break;
		}
	}

}


void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	for (int i = (n - 2) / 2; i >= 0; --i)
		ShiftDown(a, n, i);
	hp->_capacity = hp->_size = n;
}



//初始化---数组  创建堆
void HeapInit(Heap* hp, HPDataType* a, int n);

//初始化  空的顺序表
void HeapInit(Heap* hp);

//销毁
void HeapDestory(Heap* hp);
//push
void HeapPush(Heap* hp, HPDataType x);
//pop
void HeapPop(Heap* hp);
//返回堆顶指针
HPDataType HeapTop(Heap* hp);
//堆大小
int HeapSize(Heap* hp);
//判断
int HeapEmpty(Heap* hp);

// 堆排序
void HeapSort(int* a, int n);



//插入push
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_capacity == hp->_size)
	{
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC* sizeof(HPDataType));
	}

	hp->_a[hp->_size] = x;
	++hp->_size;
	ShiftUp(hp->_a, hp->_size, hp->_size-1);
}

//删除堆顶元素
void HeapPop(Heap* hp)
{
	//判空
	if (0 == HeapEmpty(hp))
	{
		Swap(hp->_a, hp->_a + hp->_size);
		//尾删
		--hp->_size;
		ShiftDown(hp->_a, hp->_size, 0);

	}
	else
	{
		return;
	}
}




void TestHeap()
{
	Heap *hp;
}

