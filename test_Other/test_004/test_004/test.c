#define _CRT_SECURE_NO_WARNINGS 1

/*********** 头文件 **************************/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/**************************************
函数名称：	menu
函数功能：	打印菜单栏
**************************************/
void menu()
{
	system("cls");					//清屏
	printf("\t###############\n");
	printf("\t##  1. PLAY  ##\n");	//输入1：开始游戏
	printf("\t##  0. EXIT  ##\n");	//输入0：退出程序
	printf("\t###############\n");
	printf("\n请选择:>_ ");
}

/**************************************
函数名称：	game
函数功能：	测试游戏
**************************************/
void game()
{
	int ret = 0;							//存放生成的随机数
	int n = 0;								//存放输入数字
	ret = rand() % 100 + 1;					//产生随机数
	//printf("ret = %d\n", ret);

	while (1)			//无限循环，直到猜对为止
	{
		printf("请猜数字:>_ ");
		scanf("%d", &n);
		while ('\n' != getchar());			//输入限制
		if (n > ret)
		{
			printf("猜大了\n\n");
		}
		else if (n < ret)
		{
			printf("猜小了\n\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			Sleep(1000);			//让窗口暂停一秒  需引用头文件 <Windows.h>
			break;
		}
	}
}

/****************************************
函数名称：	main
函数功能：	程序入口
****************************************/
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));		//产生 随机数生成器
	do{
		menu();
		scanf("%d", &input);				//接收输入选项 1/0
		switch (input)
		{
		case 0:						//input == 0  退出游戏
			printf("退出游戏\n");
			break;
		case 1:						//input == 1  开始游戏
			game();
			break;
		default:					//否则
			printf("  <输入错误   请重新输入>\n\n");		
		}
	} while (input);		//do-while循环，当input为0，即菜单选项为0时跳出循环
	
	return 0;					//程序结束
}
