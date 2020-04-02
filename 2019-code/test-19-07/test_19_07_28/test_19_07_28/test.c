#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>

#include <stdio.h>

int *f1(void)
{
	int x = 10;
	return (&x);
}

int *f2(void)
{
	int *ptr;
	*ptr = 10;
	return ptr;
}
int main()
{
	int a = 0;
	return 0;
}


#if 0
int main()
{
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		ret *= i;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}

int main()
{
	int *p = NULL;

	//debug情况下断言失败，下面程序将不会被执行
	assert(p != NULL);
	//release版本下，断言会失效，可以利用if()判断
	//一般情况下，我们会结合使用assert()和if()，使得在release情况也能手动报错
	if (p == NULL)
	{
		//printf("p == NULL\n");
		return;
	}
	return 0;
}

#endif