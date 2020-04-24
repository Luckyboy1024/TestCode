
/*********************  base2.0 *******************************/
//计时
//计次
//#提示
//##可修改

/*********************  流程图 ********************************/
//用户输入成语
//遍历成语库是否包含此成语，不包含-->打印提示
//若是，电脑接出一个成语（随机）
//再由用户接成语
//循环往复
//直到库中没有“答案”
//玩家赢
//回答出错，玩家败 --> 提示输入  或  三次机会重新输入

/***********************************************************/
#include "game.h"



//建立动态数组，存取整个成语库
void IdiomsBank()
{
	char str1[MAX] = "0";
	char str2[MAX] = "0";
	char **word;
	word = (char **)malloc(N * sizeof(char *)); 
}

//检查成语是否合法
void Inspect(char **word)
{
	FILE *fp;
	int i = 0;						//循环变量
	fp = fopen("文件保存路径.txt", "r");
	if (NULL == fp)
	{
		printf("File open fail\n");
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			word[i] = (char *)malloc(MAX*sizeof(char));
			fscanf(fp, "%s", word[i]);
		}
	}
	for (i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%s", word[i]);
	}
	while (1 == Y)
	{
		printf("please input your idiom:>_\n");
		scanf("%s", str1);
		for (i = 0; i < N; i++)
		{
			if (!(strcmp(str1, word[i])))
			{
				flag = 1;
				break;
			}
		}
		if (0 == flag)
		{
			printf("input error, isn't a idiom!\n");
			return 0;
		}
		strcpy(str2, str1);
		while (1)
		{
			flag = 0;
			flag1 = 0;
			for (i = 0; i < N; i++)
			{
				if ((str2[6] == word[i][0]) && (str2[7] == word[i][1]) && (word[i][10] != '*'));
				{
					flag1 = 1;
					printf("%s\n", word[i]);
					strcpy(str2, word[i]);
					word[i][10] = '*';
					break;
				}
			}
			if (0 == flag1)
			{
				printf("玩家赢");
				return 1;
			}

			printf("please input your idiom:>_\n");
			scanf("%s", str1);
			for (i = 0; i < N; i++)
			{
				if (!(strcmp(str1, word[i])))
				{
					flag = 1;
					break;
				}
			}
			if (0 == flag)
			{
				printf("input error, isn't a idiom!\n");
				return 0;
			}
			if ((str1[0] != str2[6]) || (str1[1] != str2[7]))
			{
				printf("你输了");
				return 0;
			}
			else
			{
				strcpy(str2, str1);
			}
		}
	}
	free(word[i]);
	free(word);
	//return 0;
}


int main()
{
	
	int i = 0;
	int flag = 0;
	int t = 1;
	int Y = 1;
	int flag1 = 0;
	int n = MAX;
	int j = 0;
	n = (int)sizeof(n);
	printf("%d", n);
	return 0;
}
