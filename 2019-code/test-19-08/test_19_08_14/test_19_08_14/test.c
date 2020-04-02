#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <stdio.h>
int main()
{
	char ch = -1;
	printf("%d\n", ch);
	return 0;
}

#endif
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <Windows.h>
//
//#define MAX 20480
//#define N 200
//
//void Window()
//{
//	printf("\n\n");
//	printf("#####################\n");
//	printf("##   1. 在线查找   ##\n");
//	printf("##   2. 成语接龙   ##\n");
//	printf("##   0. 退出程序   ##\n");
//	printf("#####################\n");
//	printf("Enter OptionNum:>_");
//}
//
//void GameOption()
//{
//	printf("\n\n");
//	printf("#####################\n");
//	printf("##   1. 本地游戏   ##\n");
//	printf("##   2. 在线游戏   ##\n");
//	printf("##   0. 返回菜单   ##\n");
//	printf("#####################\n");
//	printf("Enter OptionNum:>_");
//}
//
//void search()
//{
//	ShellExecute(NULL, "open", "https://hanyu.baidu.com", NULL, NULL, SW_HIDE);
//}
//
////检查成语是否合法
//int Inspect(char string[MAX], char **word)
//{
//	int flag = 0;
//	for (i = 0; i < N; i++)
//	{
//		if (!(strcmp(string, word[i])))
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (0 == flag)
//	{
//		printf("input error, isn't a  idiom!\n");
//	}
//	return flag;
//}
//
//void GameLoad()
//{
//	FILE *fp;
//	int i = 0;
//	char str1[MAX] = "0";
//	char str2[MAX] = "0";
//	char **word = (char **)malloc(N *  sizeof(char *));
//	fp = fopen("idom.txt", "r");
//	if (NULL == fp)
//	{
//		printf("Can't open file\n");
//		return 0;
//	}
//	else
//	{
//		for (i = 0; i < N; i++)
//		{
//			word[i] = (char  *)malloc(MAX*sizeof(char));
//			fscanf(fp, "%s", word[i]);
//		}
//	}
//	for (i = 0; !feof(fp); i++)
//	{
//		fscanf(fp, "%s", word[i]);
//	}
//
//	printf("please input your  idiom:>_\n");
//	scanf("%s", str1);
//
//	if(1 == Inspect(str1, word))
//
//
//	free(word[i]);
//	free(word);
//}
//
//void GameOnline()
//{
//	printf("还没做，玩？XPC");
//}
//
//void game()
//{
//	int input = 0;
//	do{
//		GameOption();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		case 1:
//			GameLoad();
//			break;
//		case 2:
//			GameOnline();
//			break;
//		default:
//			printf("input error!\n");
//		}
//	} while (input);
//}
//
//void Input(char input)
//{
//	switch (input)
//	{
//	case '0':
//		printf("BYE-BYE\n");
//		Sleep(999);
//		break;
//	case '1':
//		search();
//		break;
//	case '2':
//		game();
//		break;
//	default:
//		printf("enter error!!!\n");
//		printf("\nEnter again:>_");
//		break;
//	}
//}
//
//int main()
//{
//	char input = '0';
//	char ch = '0';
//	do{
//		Window();
//		while ('\n' != (ch = getchar()))
//		{
//			input = ch; 
//		}
//		Input(input);
//	} while (input-'0');
//	return 0;
//}



#if 0


while (1)
{
	printf("请输入开头的成语：（若输入“退出”，则退出游戏）\n");
	scanf("%s", &a);
	find = 0;
	if (strcmp(a, "退出") == 0)
		break;
	for (i = 0; i<M; i++)
	{
		if (strncmp(a, cy[i], strlen(a)) == 0)
		{
			find = 1;
			break;
		}
	}
	if (find == 0)
		printf("输入的不是成语，请重新输入或退出\n");
	else
	{
		//b[0]=a[6];
		// b[1]=a[7];
		for (i = 0; i<M; i++)
		{
			if (cy[i][0] == a[6] && cy[i][1] == a[7])
			{
				flag = 1;
				printf("%s\n", cy[i]);
				//c[0]=cy[i][6];
				//c[1]=cy[i][7];
				break;
			}
			if (flag == 0 && i == (M - 1))
			{
				printf("你赢了！真棒！\n");
				break;
			}
			// continue;
		}
	}
}



if (0 == (input - '0'))
{
	printf("\aBYE-BYE\n");
	Sleep(999);
	break;
}
else if (1 == (input - '0'))
{
	ShellExecute(NULL, "open", "https://hanyu.baidu.com", NULL, NULL, SW_HIDE);
	break;
}
else if (2 == (input - '0'))
{
	game();
}
else
{
	printf("enter error!!!\n");
	printf("\nEnter again:>_");
}








http://chengyu.t086.com/list/A_1.html
https://www.baidu.com/s?tn=baidu&rsv_idx=1&wd=%E5%9B%9B%E5%AD%97%E6%88%90%E8%AF%AD%E5%A4%A7%E5%85%A8%E9%9B%86&rsv_crq=6&bs=%E6%88%90%E8%AF%AD%E8%AF%8D%E5%BA%93
http://chengyu.teachercn.com/***/
#endif



