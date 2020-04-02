#define _CRT_SECURE_NO_WARNINGS 1





#if 0
void test(int *arr)
{}
int main()
{
	int arr[3][5] = {0};
	test((int *)arr);		//强制类型转换
}


int main()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };
	int arr3[3] = { 7, 8, 9 };
	int *p[4] = { arr1, arr2, arr3 };
	int(*pp[4])[3] = { &arr1, &arr2, &arr3 };
	return 0;
}

#include <stdio.h> 
void test(int** ptr)
{
	printf("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int*p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	return 0;
}

void test(char **p)
{
}
int main()
{
	char c = 'b';
	char*pc = &c;
	char**ppc = &pc;
	char* arr[10];
	test(&pc);
	test(ppc);
	test(arr);//Ok?
	return 0;
}
#include <stdio.h> 
void test()
{
	printf("hehe\n");
}
int main()
{
	printf("%p\n", test);
	printf("%p\n", &test);
	return 0;
}

void show(int(*arr)[3])
{
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arr[0] + i));
	}
	printf("\n");
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6 };
	show(arr);
	return 0;
}
#endif