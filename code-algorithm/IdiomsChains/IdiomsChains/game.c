
/*********************  base2.0 *******************************/
//��ʱ
//�ƴ�
//#��ʾ
//##���޸�

/*********************  ����ͼ ********************************/
//�û��������
//����������Ƿ�����˳��������-->��ӡ��ʾ
//���ǣ����Խӳ�һ����������
//�����û��ӳ���
//ѭ������
//ֱ������û�С��𰸡�
//���Ӯ
//�ش������Ұ� --> ��ʾ����  ��  ���λ�����������

/***********************************************************/
#include "game.h"



//������̬���飬��ȡ���������
void IdiomsBank()
{
	char str1[MAX] = "0";
	char str2[MAX] = "0";
	char **word;
	word = (char **)malloc(N * sizeof(char *)); 
}

//�������Ƿ�Ϸ�
void Inspect(char **word)
{
	FILE *fp;
	int i = 0;						//ѭ������
	fp = fopen("�ļ�����·��.txt", "r");
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
				printf("���Ӯ");
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
				printf("������");
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
