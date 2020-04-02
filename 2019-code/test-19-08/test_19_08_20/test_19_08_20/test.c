#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>


#if 0 
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 5;
	printf("%d\n", b);
	return 0;
}
//测试结果：250
#endif

#if 0
int main()
{
	char a = 0xA5;				//a 取消无符号类型
	unsigned char b = ~a >> 5;
	printf("%d\n", b);
	return 0;
}
//测试结果：2

#endif

#if 0
int main()
{
	unsigned char a = 0xA5;
	char b = ~a >> 5;			//b 取消无符号类型
	printf("%d\n", b);
	return 0;
}
//测试结果：-6

#endif

#if 0

int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~(a >> 5);		//改变运算顺序
	printf("%d\n", b);
	return 0;
}
//测试结果：250
//1010 0101  ~~  0xA5
//0000 0000 0000 0000 0000 0000 1010 0101	~~ 整型提升
//1111 1111 1111 1111 1111 1111 0101 1010	~~ 按位取反

#endif

#if 1

int main()
{
	char a = 3;
	printf("%d\n", sizeof(!a));
	printf("%d\n", a);
	return 0;
}

#endif

#if 0

char *DeleteRepeateChar(char *str1, char *str2)
{
	char* s = str2;
	char* t = str1;
	char* p = str1;
	char* q = str1;
	int arr[256] = { 0 };
	while ('\0' != *s)
	{
		arr[*str2] = 1;
		s++;
	}
	while ('\0' != *p)
	{
		if(1 != arr[*t])
		{
			*q = *p;
			q++;
			//*q++ = *p;
		}
		p++;
	}
	return str1;
}


int main()
{
	char *arr1 = "Welcome to cvte";
	char *arr2 = "come";
	char *str = DeleteRepeateChar(arr1, arr2);
	printf("%s", str);
	return 0;
}

#endif