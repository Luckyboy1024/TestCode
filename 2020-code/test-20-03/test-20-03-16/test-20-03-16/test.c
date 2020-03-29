#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#define __DEBUG__
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
#ifdef __DEBUG__
		printf("%d  ", arr[i]);		//为了观察数组是否赋值成功。
#endif //__DEBUG__
	}
	return 0;
}

#if 0


#define MALLOC(num, type) \
	(type *)malloc(num * sizeof(type))

int main()
{
	int * p = MALLOC(10, int);
	return 0;
}

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x++, y++);
	printf("x = %d, y = %d, z = %d", x, y, z);		// 输出的结果是什么？
	return 0;
}

#define Bit(x) bit##x
int main()
{
	int Bit(1) = 1, Bit(2) = 2, Bit(3) = 3;
	printf("bit1 = %d\n", bit1);
	printf("bit2 = %d\n", bit2);
	printf("bit3 = %d\n", bit3);
	return 0;
}

#define CAT(X, Y) X##Y

int main()
{
	int bit1 = 10;
	int bit2 = 20;
	printf("%d\n", CAT(bit, 1));
	printf("%d\n", CAT(bit, 2));
	return 0;
}

#define PRINTF(value) printf("the value of "#value" is %d\n", value);

int main()
{
	int a = 10;
	int b = 20;
	PRINTF(a);
	PRINTF(b);
	return 0;
}

#define ADD_TO_SUM(num, value) \
	sum##num += value;


int main()
{
	ADD_TO_SUM(5, 10);	// 作用是：给 sum5 增加 10
	return 0;
}

int i = 10;
#define PRINT(FORMAT, VALUE) \
	printf("the value of " #VALUE "is "FORMAT"\n", VALUE);

int main()
{
	PRINT("%d", i+3 );		// 产生什么效果？
	PRINT("%d", i + 3);		// 产生什么效果？
	return 0;
}

#define PRINT(FORMAT, VALUE) \
	printf("the value is "FORMAT"\n", VALUE);

int main()
{
	PRINT("%d", 10);
	return 0;
}

int main()
{
	char* p = "hello ""boy\n";
	printf("hello", " boy\n");
	printf("%s", p);
	return 0;
}

#endif

