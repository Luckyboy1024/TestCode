#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>　　　　　//C99新增的头文件，支持原生的布尔类型
bool skip()
{
	scanf("%*[^0-9]");
	return true;
}
int main()
{
	int n;
	while (skip() && scanf("%d", &n) != EOF)
	{
		printf("%d\n", n);
	}
	return 0;
}
