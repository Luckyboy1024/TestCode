#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



#if 0
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[j + 1])
			{
				Swap(a + j, a + j + 1);
			}
		}
	}
}

void Swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ShiftDown(int *a, int n, int root)
{
	int left = 2 * root;
	int right = 2 * root + 1;
	if (a[root] < a[left] || a[root] < a[right])
	{
		Swap(&(a[left]> a[right] ? a[left] : a[right]), &a[root]);
	}
}

void HeapSort(int *a, int n)
{

}
#endif