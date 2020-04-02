#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <string.h>

int main()
{
	int a[3][4] = { 0 };                   //二维数组  3行4列
	printf("%d\n", sizeof(a));            //
	printf("%d\n", sizeof(a[0][0]));      //
	printf("%d\n", sizeof(a[0]));         //
	printf("%d\n", sizeof(a[0] + 1));       //
	printf("%d\n", sizeof(*(a[0] + 1)));    //
	printf("%d\n", sizeof(a + 1));          //
	printf("%d\n", sizeof(*(a + 1)));       //
	printf("%d\n", sizeof(&a[0] + 1));      //
	printf("%d\n", sizeof(*(&a[0] + 1)));   //
	printf("%d\n", sizeof(*a));           //
	printf("%d\n", sizeof(a[3]));         //
	return 0;
}


#if 0
int main()
{
	//指针接收一个字符串
	char *p = "abcdef";
	printf("%d\n", sizeof(p));          //
	printf("%d\n", sizeof(p+1));        //
	printf("%d\n", sizeof(*p));         //
	printf("%d\n", sizeof(p[0]));       //
	printf("%d\n", sizeof(&p));         //
	printf("%d\n", sizeof(&p+1));       //
	printf("%d\n", sizeof(&p[0]+1));    //
	printf("%d\n", strlen(p));          //
	printf("%d\n", strlen(p+1));        //
	printf("%d\n", strlen(*p));         //
	printf("%d\n", strlen(p[0]));       //
	printf("%d\n", strlen(&p));         //
	printf("%d\n", strlen(&p+1));       //
	printf("%d\n", strlen(&p[0]+1));    //
	return 0;
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));        //
	printf("%d\n", sizeof(arr+0));      //
	printf("%d\n", sizeof(*arr));       //
	printf("%d\n", sizeof(arr[1]));     //
	printf("%d\n", sizeof(&arr));       //
	printf("%d\n", sizeof(&arr+1));     //
	printf("%d\n", sizeof(&arr[0]+1));  //
	printf("%d\n", strlen(arr));        //
	printf("%d\n", strlen(arr+0));      //
//	printf("%d\n", strlen(*arr));       //
	printf("%d\n", strlen(arr[1]));     //
	printf("%d\n", strlen(&arr));       //
	printf("%d\n", strlen(&arr+1));     //
	printf("%d\n", strlen(&arr[0]+1));  //

	//char arr[] = "abcdef";              
	//printf("%d\n", sizeof(arr));        //
	//printf("%d\n", sizeof(arr+0));      //
	//printf("%d\n", sizeof(*arr));       //
	//printf("%d\n", sizeof(arr[1]));     //
	//printf("%d\n", sizeof(&arr));       //
	//printf("%d\n", sizeof(&arr+1));     //
	//printf("%d\n", sizeof(&arr[0]+1));  //
	//printf("%d\n", strlen(arr));        //
	//printf("%d\n", strlen(arr+0));      //
	//printf("%d\n", strlen(*arr));       //
	//printf("%d\n", strlen(arr[1]));     //
	//printf("%d\n", strlen(&arr));       //
	//printf("%d\n", strlen(&arr+1));     //
	//printf("%d\n", strlen(&arr[0]+1));  //

	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));          //
	//printf("%d\n", sizeof(p+1));        //
	//printf("%d\n", sizeof(*p));         //
	//printf("%d\n", sizeof(p[0]));       //
	//printf("%d\n", sizeof(&p));         //
	//printf("%d\n", sizeof(&p+1));       //
	//printf("%d\n", sizeof(&p[0]+1));    //
	//printf("%d\n", strlen(p));          //
	//printf("%d\n", strlen(p+1));        //
	//printf("%d\n", strlen(*p));         //
	//printf("%d\n", strlen(p[0]));       //
	//printf("%d\n", strlen(&p));         //
	//printf("%d\n", strlen(&p+1));       //
	//printf("%d\n", strlen(&p[0]+1));    //
	return 0;
}
int main()
{
	//一维数组 
	int a[] = {1,2,3,4}; 
	printf("%d\n",sizeof(a)); 
	printf("%d\n",sizeof(a+0)); 
	printf("%d\n",sizeof(*a)); 
	printf("%d\n",sizeof(a+1)); 
	printf("%d\n",sizeof(a[1])); 
	printf("%d\n",sizeof(&a)); 
	printf("%d\n",sizeof(*&a)); 
	printf("%d\n",sizeof(&a+1)); 
	printf("%d\n",sizeof(&a[0])); 
	printf("%d\n",sizeof(&a[0]+1));
}

int int_cmp(const void * p1, const void * p2) 
{ 

	return (*( int *)p1 > *(int *) p2); 
} 

void _swap(void *p1, void * p2, int size) 
{ 
	int i = 0; 
	for (i = 0; i< size; i++)
	{ 
		char tmp = *((char *)p1 + i); 
		*(( char *)p1 + i) = *((char *) p2 + i); 
		*(( char *)p2 + i) = tmp; 
	} 
} 

void bubble(void *base, int count , int size, int(*cmp )(void *, void *)) 
{ 
	int i = 0; 
	int j = 0; 
	for (i = 0; i< count - 1; i++) 
	{ 
		for (j = 0; j<count-i-1; j++) 
		{ 
			if (cmp ((char *) base + j*size , (char *)base + (j + 1)*size) > 0) 
			{ 
				_swap(( char *)base + j*size, (char *)base + (j + 1)*size, size); 
			} 
		} 
	} 
} 
int main() 
{ 
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 }; 
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"}; 
	int i = 0; 
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp); 
	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++) 
	{ 
		printf( "%d ", arr[i]); 
	} 
	printf("\n"); 
	return 0; 
} 

#include <stdio.h>
//qosrt函数的使用者得实现一个比较函数
int int_cmp(const void * p1, const void * p2)
{
	return (*( int *)p1 > *(int *) p2);
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf( "%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
void qsort(
	void *base, 
	size_t num, 
	size_t width, 
	int(__cdecl *compare)(const void *elem1, const void *elem2)
	);

#include<stdio.h>

void test(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	//函数指针pfun 
	void(*pfun)(const char*) = test;
	//函数指针的数组pfunArr 
	void(*pfunArr[5])(const char* str);
	pfunArr[0] = test;
	//指向函数指针数组pfunArr的指针ppfunArr 
	void(*(*ppfunArr)[10])(const char*) = &pfunArr;
	return 0;
}\

#endif