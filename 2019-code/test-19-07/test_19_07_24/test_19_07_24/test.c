#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* str[3] = { "abc", "def", "gh" };		//指针数组
	int arr[4] = { 1, 2, 3, 4 };
	int* p = arr;			//指针
	int (*q)[4] = &arr;		//数组指针
	return 0;
}

#if 0
int main()
{
	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[4] = { 2, 3, 4, 5 };
	int arr3[4] = { 3, 4, 5, 6 };
	int* arr[3] = { arr1, arr2, arr3 };
	//如何依次打印
	int len = sizeof(arr) / sizeof(arr[0]);
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", *(*(arr + i) + j));
			//printf("%d ", *(arr[i] + j));
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	char* str[3] = { "hi", "dear", "boy" };
	//如何把这些字符串都打印出来？
	int i = 0;
	for (i = 0; i < 3; i++)
	{ 
		printf("%s\n", *(str + i));
	}
	return 0;
}

int arr1[4];
char arr2[5];

int main()
{
	int a = 10;
	int *pa = &a;
	int **ppa = &pa;
	return 0;
}
int main()
{
	int a = 10;
	int b = 20;
	int *p = &a;
	int *q = &b;
	printf("%d\n", p - q);
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int *p = arr + 1;
	char *q =(char *) arr + 5;
	printf("%d\n", q - p);
	return 0;
}


int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("arr    ==  %x\n", arr);
	printf("&arr   ==  %x\n", &arr);
	printf("&arr+1 ==  %x\n", &arr+1);
	printf("arr+1  ==  %x\n", arr+1);
	return 0;
}
void Show(int *p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//printf("%d ", p[i]);	// [] 自带解引用，相当于*(p + i)
		printf("%d ", *(p + i));
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	Show(p, sz);
	return 0;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i<sz; i++)
	{
		printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p + i);
	}
	return 0;
}

int main()
{
	int i=0;
	int j=0;
	getchar(j);
	scanf("%d",&j);//
	for(i=0;i<j;i++)
	{
		int k=0;
		for(k=0;k<j-i-1;k++)
			printf(" ");
		for(k=0;k<2*i+1;k++)
			printf("*");
		printf("\n");
	}

	for(i=0;i<=j-1;i++)
	{
		int k=0;
		for(k=0;k<=i;k++)
			printf(" ");
		for(k=0;k<2*(j-1-i)-1;k++)
			printf("*");
		printf("\n");
	}
	return 0;
}
int main()
{
	int n = 0x12345678;           //十六进制，四个字节
	char *pc = (char *)&n;        //一个字节
	return 0;
}

int main()
{
	int n = 0x11223344;           //十六进制，四个字节
	char *pc = (char *)&n;        //一个字节
	int *pi = &n;
	*pc = 0;   //重点在调试的过程中观察内存的变化。
	*pi = 0;   //重点在调试的过程中观察内存的变化。
	return 0;
}

int main()
{
	int n = 0x12345678;		//十六进制，四个字节12 34 56 78
	char *pc = (char *)&n;
	//printf("%d\n", *pc);	//%d整型（十进制）打印，结果为120
	printf("%x\n", *pc);
	return 0;
}
#endif