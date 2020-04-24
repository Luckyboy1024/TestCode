#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



#if 0

char FindOnceChar(char *str)
{
	char find = '0';
	char *p = str;
	int arr[256] = { 0 };
	//±éÀú
	while ('\0' != *p)
	{
		arr[*str]++;
		str++;
	}
	//
	p = str;
	while (('\0' != *p) && (1 != arr[*str]))
	{
		str++;
	}
	if (1 == arr[*str])
	{
		find = *p;
	}
	else
	{
		printf("can't find it");
	}
	return find;
}

int main()
{
	char arr[] = {"abacddef"};
	FindOnceChar(arr);
	return 0;
}


//int 
int MaxArray(int *p, int len)
{
	int max = 0x80000000;
	for (int i = 0; i < len; i++)
	{
		if (*(p + i) >max)
		{
			max = *(p + i);
		}
		else
		{
			//do nothing;
		}
	}
}

int main()
{
	int arr[] = { -1, 2, 3, 4, -2, -10, 10, 7 };

	return 0;
}


#endif