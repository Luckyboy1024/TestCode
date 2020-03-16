#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

// 加载
void LoadContacts(Contacts *pCon)
{
	FILE *pf = fopen("Contacts.bat", "rb");
	assert(pf != NULL);
	PersonInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PersonInfo), 1, pf) > 0)
	{
		CheckFull(pCon);
		pCon->per[pCon->usedSize] = tmp;
		pCon->usedSize++;
	}
	if (fclose(pf))
	{
		perror("close file");
	}
	pf = NULL;
}


void InitContacts(Contacts *pCon)
{
	//通讯录初始化: 数组，usedsize
	assert(pCon);
	//pCon->usedsize = 0;
	////这里memset()如果pCon->per的容量已确定即定义时直接定义为数组，才可以
	//memset(pCon->per, 0,  sizeof(pCon->per));    //string.h 对数组初始化
	pCon->capticty = DEFAULT_SIZE;
	pCon->usedSize = 0;
	pCon->per = (PersonInfo  *)malloc(sizeof(PersonInfo)*pCon->capticty);      // stdlib.h
	assert(pCon->per != NULL);
	memset(pCon->per, 0, sizeof(PersonInfo)*pCon->capticty);
	//加载
	LoadContacts(pCon);
}
//判断通讯录是否为满，返回值 0 ：表示增容失败；1 ：表示增容成功
// 注：static 修饰的函数或变量，其作用域仅在当前 .c 文件内
static int CheckFull(Contacts *pCon)
{
	if (pCon->usedSize == pCon->capticty)  //通讯录满了
	{
		// 二倍的扩容 realloc()
		PersonInfo *ptr = (PersonInfo  *)realloc(pCon->per, pCon->capticty *  sizeof(PersonInfo)* 2);
		if (ptr != NULL)
		{
			pCon->per = ptr;
			pCon->capticty *= 2;
			printf("Capacity of  success!!!\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
// 添加一个人到通讯录
void AddContacts(Contacts *pCon)
{
	// 往哪里放：数组 下标
	// 添加内容：姓名、年龄、……
	int ret = CheckFull(pCon);
	if (0 == ret)//增容失败
	{
		printf("Sorry, Contacts is full,  and Capacity of failure\n");
		return;
	}
	else
	{
		printf("请输入姓名 :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._name);
		printf("请输入年龄 :>_ ");
		scanf("%d", &(pCon->per[pCon->usedSize]._age));
		printf("请输入性别 :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._sex);
		printf("请输入电话 :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._tele);
		printf("请输入住址 :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._addr);
		++pCon->usedSize;
		printf("Adding successfully\n");
	}
}
// 根据姓名查找通讯录，找到：返回下标；找不到：返回-1
int SearchContacts(Contacts *pCon)
{
	char name[MAX_NAME] = { 0 };
	if (0 == pCon->usedSize)
	{
		printf("sorry, Contacts is   empty\n");   //通讯录为空
		return -1;
	}
	printf("请输入联系人姓名 :>_ ");
	scanf("%s", name);
	for (int i = 0; i < pCon->usedSize; i++)
	{
		if (0 == strcmp(pCon->per[i]._name, name))    //   字符串的比较
		{
			return i;
		}
	}
	return -1;
}
void DelContacts(Contacts *pCon)
{
	int index = SearchContacts(pCon);//   代码复用
	if (-1 == index)
	{
		printf("No such person\n");
		return;
	}
	else
	{
		for (int i = index; i < pCon->usedSize - 1; i++)
		{
			pCon->per[i] = pCon->per[i + 1];
		}
		pCon->usedSize--;
		printf("Deleted successfully\n");
	}
}
// 显示
void ShowContacts(Contacts *pCon)
{
	printf("%-20s %-10s %-10s %-11s   %-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	if (0 == pCon->usedSize)
	{
		printf("sorry, Contacts is   empty\n");   //通讯录为空
	}
	else
	{
		for (int i = 0; i < pCon->usedSize; i++)
		{
			printf("%-20s", pCon->per[i]._name);   // 姓名
			printf("%-10s", pCon->per[i]._sex);    // 性别
			printf("%-10d", pCon->per[i]._age);    // 年龄
			printf("%-11s", pCon->per[i]._tele);   // 电话
			printf("%-15s", pCon->per[i]._addr);   // 地址
			printf("\n");
		}
	}
}
// 清空
void ClearContacts(Contacts *pCon)
{
	pCon->usedSize = 0;
}

// 保存
void SaveContact(Contacts *pCon)
{
	// 文件写。fwrite
	FILE *pf = fopen("Contacts.bat", "wb");
	assert(pf != NULL);
	for (int i = 0; i < pCon->usedSize; i++)
	{
		fwrite(pCon->per + i, sizeof(PersonInfo), 1, pf);
	}
	if (fclose(pf))
	{
		perror("close file");
	}
	pf = NULL;
}

// 摧毁
void DestroyContacts(Contacts *pCon)
{
	SaveContact(pCon);
	assert(pCon != NULL);
	free(pCon->per);
	pCon->per = NULL;
	pCon->capticty = 0;
	pCon->usedSize = 0;
}
