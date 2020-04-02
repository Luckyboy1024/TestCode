#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>

void test()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{

	}
}

int main()
{
	return 0;
}


#if 0


int main()
{
	printf("Hello World!\n");   //此时输出的是默认属性的文字
	HANDLE hdl =  GetStdHandle(STD_OUTPUT_HANDLE);   //获取控制台句柄

	SetConsoleTextAttribute(hdl,  FOREGROUND_GREEN);   //设置文字属性：绿色
	printf("Hello World!\n");   //此时输出的是绿色的文字

	SetConsoleTextAttribute(hdl,  FOREGROUND_RED);  //设置文字属性：红色
	printf("Hello World!\n");   //此时输出的是红色的文字

	SetConsoleTextAttribute(hdl,  FOREGROUND_BLUE); //设置文字属性：蓝色
	printf("Hello World!\n");   //此时输出的是蓝色的文字

	SetConsoleTextAttribute(hdl,  FOREGROUND_INTENSITY);   //设置文字属性：高亮
	printf("Hello World!\n");   //此时输出的是高亮的文字

	SetConsoleTextAttribute(hdl,  FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
	//设置文字属性：蓝色、高亮
	printf("Hello World!\n");   //此时输出的是亮色、加亮的文字

	SetConsoleTextAttribute(hdl,  FOREGROUND_BLUE | FOREGROUND_GREEN |  FOREGROUND_RED);  //设置文字属性：白色
	printf("Hello World!\n");   //此时输出的是白色的文字   也就是说这三种颜色属性可以叠加

	SetConsoleTextAttribute(hdl,  FOREGROUND_BLUE | FOREGROUND_GREEN |  FOREGROUND_RED | FOREGROUND_INTENSITY);   //设置文字属性：白色、高亮
	printf("Hello World!\n");   //此时输出的是白色、加亮的文字

	CloseHandle(hdl); //要记得关闭Handle，释放 Handle 资源
	return 0;
}
int main()
{
	FILE *pf = fopen("C:\\Users\\ASUS\\Desktop\\打字练习.txt", "r");
	assert(pf) ;
	system("Color f0");
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c", ch);
	}
	Sleep(4000);
	system("cls");
	printf("hehe");
	system("pause");


	fclose(pf);
	pf = NULL; 
	return 0;
}


#include <stdio.h>

//判断是否为闰年,是，则为1，否，则为0
int is_leap_year(int y)			//用y来接收year
{
	//return (((0 == y % 4) && (0 != y % 100)) || (0 == y % 400))		//简单写法，可以直接一句代码代替
	if (((0 == y % 4) && (0 != y % 100)) || (0 == y % 400))
	{
		return 1;	
	}
	else
	{
		return 0;
	}
}

int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (1 == is_leap_year(year))
		{
			printf("%d ", year);
		}
	}
	return 0;
}

#include <stdio.h>
#include <math.h>	//sqre()求算术平方根的函数

//返回1，是素数；否则，不是素数
int is_prime(int n)	//返回值类型是int整型，参数n
{
	int j = 0;
	for (j = 2; j <= sqrt(n); j++)
	{
		if (0 == n%j)
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (1 == is_prime(i))		//is_prime()函数判断 i 是否为素数
		{
			printf("%d ", i);
		}
	}
	return 0;
}

#endif