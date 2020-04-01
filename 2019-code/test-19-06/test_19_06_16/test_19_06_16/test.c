#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main()
{
	return 0;
}




char* MyStrncat(char* dest, char* src, int n)
{
	int i = 0;
	while (*dest++ != '\0');
	while (i < n)
	{
		if (*src++ != '\0')
		{
			*dest++ = *src;
		}
		i++;
	}
}

int main()
{
	char *dest = "hello";
	char *src = "abcd";
	int n = MyStrncat(dest, src, 2);
	return 0;
}


#include <stdio.h>
#include <string.h>
#include <assert.h>

int MyStrncmp(const char* str1, const char* str2, int n)
{
	int diff = 0;
	int count = 0;
	assert(str1 != NULL && str2 != NULL);
	while (count < n && ((diff = *str1 - *str2) == 0 ) && *str1 != '\0')
	{
		str1++;
		str2++;
		count++;
	}
	
	
	/*while (*str1 != '\0')
	{
		while(*str2 != '\0')
		{
			if (*str1 - *str2 > 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			*str1++;
			*str2++;
		}
		return 1;
	}
	return -1;*/
}

int main()
{
	char* str1 = "abcdef";
	char* str2 = "abef";
	int n = MyStrncmp(str1, str2, 2);
	printf("%d", n);
	return 0;
}


#include <stdio.h>
#include <assert.h>
#include <string.h>

char *Mystrstr(const char* str1, const char* str)
{
	char* ret = NULL;
	char* p = NULL;
	assert(str1 != NULL && str1 != NULL);
	do
	{
		str1++;
		str++;
	} while (*str1 != *str && *str1 != '\0');
	while (*str1 != '\0')
	{
		while (*str1 != '\0' && *str != '\0' && *str1 != '\0')
		{

		}
	}
	*p = *str1;
	do
	{
	} while (*p != '\0');
	str1++;
	str++;

	return *p;
}

int main()
{
	char* str1 = "abc";
	char* str = "bc";
	Mystrstr(str, );
	return 0;
}


#include <stdio.h>
#include <stdlib.h>   //for system()

int main()
{
	system("@color 0a");	//黑色背景 淡绿色文字
	printf("Hello World!\n");
	system("@color 0f");	//黑色背景 亮白色文字
	printf("Hello World!\n");
	system("@color 04");	//黑色背景 红色文字
	printf("Hello World!\n");

	return 0;
}



#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("Hello World!\n");	//此时输出的是默认属性的文字

	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);	//获取控制台句柄
	SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);	//设置文字属性：绿色
	printf("Hello World!\n");	//此时输出的是绿色的文字

	SetConsoleTextAttribute(hdl, FOREGROUND_RED);	//设置文字属性：红色
	printf("Hello World!\n");	//此时输出的是红色的文字

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE);	//设置文字属性：蓝色
	printf("Hello World!\n");	//此时输出的是蓝色的文字

	SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);	//设置文字属性：高亮
	printf("Hello World!\n");	//此时输出的是高亮的文字

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	//设置文字属性：蓝色、高亮
	printf("Hello World!\n");	//此时输出的是亮色、加亮的文字

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	//设置文字属性：白色
	printf("Hello World!\n");	//此时输出的是白色的文字   也就是说这三种颜色属性可以叠加

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);	//设置文字属性：白色、高亮
	printf("Hello World!\n");	//此时输出的是白色、加亮的文字

	CloseHandle(hdl);	//要记得关闭Handle，释放 Handle 资源
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	printf("Hello World!\n");	//此时输出的是默认属性的文字
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);	//获得控制台句柄

	SetConsoleTextAttribute(hdl, BACKGROUND_RED);	//设置文字属性：控制台背景色，红色底色
	printf("Hello World!\n");	//此时输出红色的底色，只是文字的底色，不是控制台的背景色
	SetConsoleTextAttribute(hdl, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	//设置文字属性：绿色，底色：白色，
	printf("Hello World!\n");	//此时输出红色的底色，只是文字的底色不是控制台的背景色


	system("pause");
	return 0;
}

#endif

#include <stdio.h>
#include <stdlib.h>   //for system()
int main()
{
	system("color 5E"); //@color表示 设置控制台前景色和背景色，后跟参数
	printf("Hello World!\n");
	return 0;
}