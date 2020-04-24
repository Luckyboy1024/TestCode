

#include "window.h"

//开始
void Window()
{
	printf("+---------------------------+\n");
	printf("+							+\n");
	printf("+	1. 查成语						+\n");			//查询成语
	printf("+	2. 接龙游戏						+\n");			//接龙游戏
	printf("+	0. 退出						+\n");				//退出
	printf("+							+\n");
	printf("+---------------------------+\n");
}

//开始游戏
void GameBegain()
{
	printf("+--------------------------+\n");
	printf("|                          |\n");
	printf("|      1. New  Game        |\n");		//自己输入一个成语
	printf("|      2. LOAD Game        |\n");		//Read File  读取存档中的成语
	printf("|  	   			           |\n");
	printf("|                          |\n");
	printf("+--------------------------+\n");
}

//在线PLAY
void PlayWindows_one()
{
	printf("+--------------------------+\n");
	printf("|                          |\n");
	printf("|    .                       |\n");
	printf("|    . 输入你的成语                       |\n");
	printf("|                          |\n");
	printf("|                          |\n");
	printf("+--------------------------+\n");
}

//单机PLAY
void PlayWindows_two()
{
	printf("+--------------------------+\n");
	printf("|                          |\n");
	printf("|    1. 读档                      |\n");
	printf("|                          |\n");
	printf("|                          |\n");
	printf("|                          |\n");
	printf("+--------------------------+\n");
}



void OverWindows()
{
	printf("+--------------------------+\n");
	printf("|                          |\n");
	printf("|    . 存档  ||  删档                      |\n");
	printf("|    . 再见                       |\n");
	printf("|    . 版本声明                      |\n");
	printf("|                          |\n");
	printf("+--------------------------+\n");
}

