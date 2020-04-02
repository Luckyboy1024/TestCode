#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


#if 0

int main()
{
	//arr[10],10个元素的数组，下标0~9
	int arr[10] = { 0 };		//数组的不完全初始化
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);	//计算数组元素个数
	for (i = 0; i < 10; i++)		//下标从0开始
	{
		arr[i] = i;		//对数组的内容依次赋值
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);	//输出数组的内容
	}
	return 0;
}


int main()
{
	char arr0[] = "abc";
	char arr1[] = { 'a', 'b', 'c', 0 };
	printf("%d\n", strlen(arr0));
	printf("%d\n", strlen(arr1));
	return 0;
}

int main()
{
	char arr0[] = "abc";
	char arr1[3] = { 'a', 'b', 'c' };
	char arr2[] = { 'a', 'b', 'c' };
	printf("%s\n", arr0);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	return 0;
}
int main()
{
	//int a = 0;
	//printf("%d\n", sizeof(a));		//4字节
	//printf("%d\n", sizeof(int));		//4字节

	int arr[10];
	printf("%d\n", sizeof(arr[0]));		//4字节
	printf("%d\n", sizeof(arr));		//40字节
	printf("%d\n", sizeof(int[10]));		//40字节
	return 0;
}

int main()
{
	int arr1[10];
	int arr2[4 + 6];
	char arr3[7];
	//数组的元素个数可以变
	//数组的元素类型可以变
	//数组名也可以变
	return 0;
}

type_t   arr_name[const_n];
//type_t 是指数组的元素类型
//const_n 是一个常量表达式，用来指定数组的大小
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;		//n==1或n==2时，返回1
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}


int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d", ret);
	return 0;
}

int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d", ret);
	return 0;
}
int fac(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n - 1);
	}
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fac(n);
	printf("%d", ret);
	return 0;
}

int My_strlen(char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + My_strlen(str + 1);
	}
}
int main()
{
	int len = My_strlen("abcd");
	printf("len = %d\n", len);
	return 0;
}


void test(int n)
 {
	if (n < 10000)
	{
		test(n + 1);
	}
}

int main()
{
	test(1);
	return 0;
}


void Print(int n)
{
	if (n < 10)
		printf("%d", n);
	else
	{
		printf("%d", n % 10);
		Print(n / 10);
	}
}

int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	Print(n);
	return 0;
}

//void Print(int n)
//{
//	if (n < 10)
//	{
//		printf("%d", n);
//	}
//	else
//	{
//		Print(n / 10);
//		n /= 10;
//		while (n != 0)
//		{
//			printf("%d", n % 10);
//		}
//	}
//}
void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d", n % 10);
}

int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	Print(n);
	return 0;
}

int main()
{
	printf("hehe\n");
	main();
	return 0;
}
程序名称：
属于哪个项目：
程序版本号：
程序开发小组组别：
程序算法提供人：
程序流程图提供人：
程序代码编写人：
程序测试员：
项目负责人：

#endif