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
	system("@color 0a");	//��ɫ���� ����ɫ����
	printf("Hello World!\n");
	system("@color 0f");	//��ɫ���� ����ɫ����
	printf("Hello World!\n");
	system("@color 04");	//��ɫ���� ��ɫ����
	printf("Hello World!\n");

	return 0;
}



#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("Hello World!\n");	//��ʱ�������Ĭ�����Ե�����

	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ����̨���
	SetConsoleTextAttribute(hdl, FOREGROUND_GREEN);	//�����������ԣ���ɫ
	printf("Hello World!\n");	//��ʱ���������ɫ������

	SetConsoleTextAttribute(hdl, FOREGROUND_RED);	//�����������ԣ���ɫ
	printf("Hello World!\n");	//��ʱ������Ǻ�ɫ������

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE);	//�����������ԣ���ɫ
	printf("Hello World!\n");	//��ʱ���������ɫ������

	SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY);	//�����������ԣ�����
	printf("Hello World!\n");	//��ʱ������Ǹ���������

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	//�����������ԣ���ɫ������
	printf("Hello World!\n");	//��ʱ���������ɫ������������

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	//�����������ԣ���ɫ
	printf("Hello World!\n");	//��ʱ������ǰ�ɫ������   Ҳ����˵��������ɫ���Կ��Ե���

	SetConsoleTextAttribute(hdl, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);	//�����������ԣ���ɫ������
	printf("Hello World!\n");	//��ʱ������ǰ�ɫ������������

	CloseHandle(hdl);	//Ҫ�ǵùر�Handle���ͷ� Handle ��Դ
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	printf("Hello World!\n");	//��ʱ�������Ĭ�����Ե�����
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);	//��ÿ���̨���

	SetConsoleTextAttribute(hdl, BACKGROUND_RED);	//�����������ԣ�����̨����ɫ����ɫ��ɫ
	printf("Hello World!\n");	//��ʱ�����ɫ�ĵ�ɫ��ֻ�����ֵĵ�ɫ�����ǿ���̨�ı���ɫ
	SetConsoleTextAttribute(hdl, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	//�����������ԣ���ɫ����ɫ����ɫ��
	printf("Hello World!\n");	//��ʱ�����ɫ�ĵ�ɫ��ֻ�����ֵĵ�ɫ���ǿ���̨�ı���ɫ


	system("pause");
	return 0;
}

#endif

#include <stdio.h>
#include <stdlib.h>   //for system()
int main()
{
	system("color 5E"); //@color��ʾ ���ÿ���̨ǰ��ɫ�ͱ���ɫ���������
	printf("Hello World!\n");
	return 0;
}