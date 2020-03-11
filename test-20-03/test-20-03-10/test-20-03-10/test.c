#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int IsPrime(int n)	// �� n ���ڵ�����
{
	int *p = (int *)malloc(sizeof(int)* n);
	int i = 0;
	int j = 0;
	assert(p != NULL);
	// �±�����жϵ�����
	// Ԫ��ֵ�� 0 ������������1 ����������
	for (i = 0; i < n; ++i)
	{
		p[i] = 1;		// ��ʼ����ȫ��Ϊ 1
	}
	for (i = 2; i < n; ++i)
	{
		p[i] = 1;
	}
	for (i = 2; i < n; ++i)
	{
		for (j = 2; j < i; ++j)
		{
			if (0 == i % j)
			{
				p[i] = 0;
			}
		}
	}
	for (i = 2; i < n; ++i)
	{
		if (1 == p[i])
		{
			printf("%d ", i);
		}
	}

	free(p);
	p = NULL;
}

int main()
{
	IsPrime(100);
	return 0;
}
