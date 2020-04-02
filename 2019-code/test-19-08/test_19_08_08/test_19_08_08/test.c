#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

#ifdef _DRING_
int main()
{
	return 0;
}
#endif

int main()
{
	float a = 12.5f;
	printf("%lf", a);
	return 0;
}

#if 0
int main()
{ 

	int n = 9; 

	float *pFloat = (float *)&n; 

	printf("n的值为：%d\n",n); 

	printf("*pFloat的值为：%f\n",*pFloat); 


	*pFloat = 9.0; 

	printf("num的值为：%d\n",n); 

	printf("*pFloat的值为：%f\n",*pFloat);
	return 0; 
}
unsigned char i = 0; 
int main() 
{ 
	for(i = 0;i<=255;i++) 
	{ 
		printf("hello world\n"); 
	} 
	return 0; 
}
int main()
{ 
	char a[1000]; 
	int i; 
	for(i=0; i<1000; i++) 
	{ 
		a[i] = -1-i; 
	} 
	printf("%d",strlen(a)); 
	return 0; 
}
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{ 
		printf("%u\n",i); 
		Sleep(100);
	}
	return 0;
}
int main()
{
	int i = -20;
	//原码：10000000000000000000000000010100
	//反码：11111111111111111111111111101011
	//补码：11111111111111111111111111101100
	unsigned  int  j = 10;
	//原码：00000000000000000000000000001010		//补码还是它本身


	printf("%d\n", i + j);
	//按照补码的形式进行运算，最后格式化成为有符号整数  int
	//    11111111111111111111111111101100
	//  + 00000000000000000000000000001010
	//  = 11111111111111111111111111110110  -- 补码
	//转化为原码：10000000000000000000000000001010  --> -10
	return 0;
}
int main()
{ 
	char a = 128;		//区别在这里：-128 改为了 128
	printf("%u\n",a); 
	return 0; 
}
int main() 
{ 
	char a = -128; 
	printf("%u\n",a); 
	return 0; 
} 

int main()
{
	char a= -1;
	signed char b=-1;
	unsigned char c=-1;
	printf("a=%d,b=%d,c=%d",a,b,c);
	return 0;
}
int main()
{
	char a = -128;
	//原码：10000000000000000000000010000000
	//反码：11111111111111111111111101111111，符号位不变，其他位取反
	//补码：11111111111111111111111110000000，反码 + 1，数据以补码的形式存储在内存中
	// 8位：10000000
	//32位：11111111111111111111111110000000

	printf("%u\n", a);		//打印它的补码
	//11111111111111111111111110000000 转化为10进制数为 ‭4294967168‬

	printf("%d\n", a);		//打印它的原码
	return 0;
}
int main()
{
	int a = 20;
	int b = -10;
	return 0;
}
int a = 20;
int b = -10;

int main()
{
	char i = 0;
	for (i = 0; i < 129; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}


int main()
{
	double n = 0;
	printf("%d", sizeof(n));
	return 0;
}

#endif
