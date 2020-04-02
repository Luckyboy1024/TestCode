#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{

}




#if 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("****************************\n");
	printf("***       1. play        ***\n");
	printf("***       0. exit        ***\n");
	printf("****************************\n");
}

void game()
{
	printf("猜数字\n");
	/*****  生成随机数 *****/
	int ret = 0;
	int guess = 0;
	ret = rand() % 100 + 1;
	//printf("ret = %d\n", ret);			//测试过程中查看随机数
	/******* 开始猜 *******/
	while (1)
	{
		printf("请猜数字:>_");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>_");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();		//玩游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>_");
		scanf("%s", password);
		if (0 == strcmp(password, "abcd"))	//字符串的比较用的是string compare---strcmp()函数
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误！\n");
		}
	}
	if (3 == i)
	{
		printf("三次密码输入错误，退出程序\n");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main()
{
	char arr1[] = "Hello world!!!";
	char arr2[] = "##############";
	int left = 0;
	//int right = sizeof(arr1) / sizeof(arr1[0]) - 1;		//错误：应该是-2，因为字符串结尾是\0
	int right = strlen(arr1) - 1;		//strlen求的是字符串长度
	printf("%s\n", arr2);
	//while循环实现
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	////for循环实现
	//for (left = 0, right = strlen(arr1) - 1;
	//	left <= right;
	//	left++, right--)
	//{
	//	Sleep(1000);
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s\n", arr2);
	//}
	//
	return 0;
}

#endif
