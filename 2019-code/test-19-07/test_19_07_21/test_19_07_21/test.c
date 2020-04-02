#define _CRT_SECURE_NO_WARNINGS 1



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void menu()
{
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t□******************************□\n");
	printf("\t\t\t\t\t□****                      ****□\n");
	printf("\t\t\t\t\t□****      1.  Play        ****□\n");
	printf("\t\t\t\t\t□****      0.  Exit        ****□\n");
	printf("\t\t\t\t\t□****                      ****□\n");
	printf("\t\t\t\t\t□******************************□\n");
	printf("\n");
	printf("\t\t\t\t\t请选择:>_ ");
}
void game()
{
	//生成随机数
	//时间戳
	int ret = 0;
	int guess = 0;
	srand((unsigned int)time(NULL));
	ret = rand() % 100 + 1;
	//printf("ret = %d\n", ret);
	//猜数字
	while (1)                //无限循环，直至猜对为止
	{
		printf("请猜数字:>_ ");
		scanf("%d", &guess);
		while ('\n' != getchar());        //输入限制
		if (guess > ret)
		{
			printf("猜大了\n\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n\n");
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t恭喜你，猜对了\n");
			Sleep(1000);
			system("cls");
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
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("<输入错误   请重新输入>\n\n");
			//getchar(input);
		}
	} while (input);
	system("pause");
	return 0;
}


#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
	return 0;
}

#endif