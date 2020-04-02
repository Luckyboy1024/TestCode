#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int get_max(int x, int  y)		//这个自定义函数要返回一个int类型的值--形参x,y中的较大值 
{
	//return x > y ? x : y;			//三目操作符
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	max = get_max(a, b);
	printf("max = %d", max);
	max = get_max(10, b);
	printf("max = %d", max);
	max = get_max(5 + 5, b);
	printf("max = %d", max);
	max = get_max(get_max(3, 10), b);
	printf("max = %d", max);
	return 0;
}


#if 0

void Swap(int* x, int* y)		//x,y指向a,b的地址
{
	int tmp = 0;
	tmp = *x;		//*x,*y：对x,y解引用，即得到了a,b的内容
	*x = *y;
	*y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("a = %d, b = %d\n", a, b);
	Swap(&a, &b);			//传递的是地址，&：取址符
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
void Swap(int x, int y)		//函数不需要返回，即返回void空，无返回，函数体内不需要return,
{
	//函数体内不需要return 0;
	//但想return直接跳出这个函数体时，可以直接：return;即可
	return;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("a = %d, b = %d\n", a, b);		//先看一眼a, b的值
	Swap(a, b);		//交换a,b
	printf("a = %d, b = %d\n", a, b);		//再看一眼a, b的值，验证是否实现a,b互换
	return 0;
}

int get_max(int x, int  y)		//这个自定义函数要返回一个int类型的值--形参x,y中的较大值 
{
	//return x > y ? x : y;			//三目操作符
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	max = get_max(a, b);
	printf("max = %d\n", max);
	return 0;
}

int main()
{
	int a = 10;
	int b = 20;
	int max = 0;				//定义一个变量，接收a,b两者的较大值
	max = get_max(a, b);		//把两个待求整数传进我们的自定义函数
	printf("max = %d\n", max);
	return 0;
}


int main()
{
	char arr[] = "hello boy";
	memset(arr, 'x', 5);
	printf("%s", arr);
	return 0;
}

int main()
{
	char dest[] = "hello";
	char src[] = "boy";		//src中存了四个字符：b,o,y,\0
	strcpy(dest, src);
	printf("%s\n", dest);
	return 0;
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[20] = "abcdefg";
	//把arr2的内容拷贝到arr1中去
	strcpy(arr1, arr2);
	printf("%s\n", arr1);		//如果可以实现，证明strcpy()可以起到拷贝字符串的使用
	return 0;
}

#endif