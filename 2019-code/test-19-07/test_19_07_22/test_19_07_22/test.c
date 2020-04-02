#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0x11223344;
	char *pc = (char *)&n;
	int *pi = &n;
	*pc = 0;   //重点在调试的过程中观察内存的变化。
	*pi = 0;   //重点在调试的过程中观察内存的变化。
	return 0;
}

#if 0 
//演示实例
int main()
{
	int n = 10;
	char *pc = (char*)&n;
	int *pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc+1);
	printf("%p\n", pi);
	printf("%p\n", pi+1);
	return  0;
}
int main()
{
	//int a = 10;
	//int* p = &a;
	int *pp = 10;
	return 0;
}
int main()
{
	return 0;
}
int main()
{
	int num = 10;
	int *pp = &num;
	*pp = 100;
	return 0;
}


#endif