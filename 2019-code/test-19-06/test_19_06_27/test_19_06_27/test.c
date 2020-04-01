#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



#if 0
int cmp1(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return (*(unsigned char *)a - *(unsigned char *)b);
}

int cmp2(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return strcmp((char *)*(int *)a, (char *)*(int *)b);
}

int cmp3(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return (*(unsigned int *)a - *(unsigned int *)b);;
}

int cmp4(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return (((*(double *)a - *(double *)b) > 0) ? 1 : -1);
}

void MySwap(void *p1, void *p2, int size)
{
	assert(p1);
	assert(p2);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void MyQsort(void *base, int count, int size, int(*cmp)(void *, void *))
{
	assert(base);
	assert(cmp);
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size)>0)
			{
				MySwap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}

}

int main()
{
	int i = 0;
	char c[10] = "adecaesdft";
	char *s[5] = { "abc", "dor", "bad", "cat", "fam" };
	int a[10] = { 1, 3, 4, 2, 5, 0, 7, 6 };
	MyQsort (c, 10, sizeof(char), cmp1);
	MyQsort (s, 5, sizeof(char *), cmp2);
	MyQsort (a, 10, sizeof(int), cmp3);
	MyQsort (b, 10, sizeof(double), cmp4);
	for (i = 0; i < 10; i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", s[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%lf ", b[i]);
	}
	printf("\n");
	return 0;
}

//
//int compare( const void *arg1, const void *arg2 )
//{
//	/* Compare all of both strings: */
//	return _stricmp( * ( char** ) arg1, * ( char** ) arg2 );
//}
//
//void main( int argc, char *argv )
//{
//	int i;
//	/* Eliminate argv[0] from sort: */
//	*argv = "a ab cd ef s ce";
//
//	argv++;
//	argc--;
//
//	/* Sort remaining args using Quicksort algorithm: */
//	qsort( (void *)argv, argc, sizeof( char * ), compare );
//
//	/* Output sorted list: */
//	for( i = 0; i < argc; ++i )
//		printf( "%s ", argv[i] );
//	printf( "\n" );
//}

int main()
{
	int total = 0;
	int money = 20;
	int empty = 0;
	total = money;
	empty = money;
	while (empty >= 2)
	{
		total = total + empty / 2; 
		empty = empty / 2 + empty % 2;
	}
	//if (empty == 1)
	//{
	//	total++;	//向老板借一个空瓶，两个空瓶换一瓶新的，喝完，把瓶子还给老板
	//}
	printf("%d\n", total);
	return 0;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 5, 3, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	int i = 0;
	int sum = 0;
	int pos = 0;
	for (i = 0; i < len; i++)
	{
		sum = sum ^ arr[i];
	}
	for(i = 0; i < 32; i++)
	{
		sum >> i;
		if (1 == (sum & 1))
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x = x ^ arr[i];
		}
		else
		{
			y = y ^ arr[i];
		}
	}
	printf("%d  %d", x, y);
	return 0;
}

#endif