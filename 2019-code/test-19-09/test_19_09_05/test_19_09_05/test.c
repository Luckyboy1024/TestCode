#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char a; int b; float c; double d;
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	return 0;
}


#if 0
int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;


int main()
{



	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
	char* str1 = "caocao";
	char* str2 = "liubei";
	char* str3 = "sunquan";
	char* arr2[3] = { str1, str2, str3 };
	return 0;
}


int main()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };
	int arr3[4] = { 7, 8, 9 };
	//int* p[3] = { arr1, arr2, arr3 };
	//printf("%d\n", *(p[0] + 1));
	//printf("%d\n", *(p[1] + 2));
	int(*p)[3] = &arr1;			
	return 0;
}

#endif
