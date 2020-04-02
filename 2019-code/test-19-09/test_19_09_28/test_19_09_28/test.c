#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define Data int


int main()
{
	
	return 0;
}

#if 0

typedef struct Code{
	int size;		//大小
	int status;		//标记
	Data* a;		//数据
}Code;


void DelCode(int size,Code* c)
{
	int end = size;
	while (end)
	{
		if (1 == c->status)
		{
			delete();
			printf("可以修改\n");
		}
		else 
		{
			++c->status;
			printf("不可修改\n");
		}
	}
}

#endif

#if 0	
int main()
{
	int* p = (int*)malloc(1024*1024*1024*4));
	assert(p != NULL);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
	}
	return 0;
}
#endif