#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
void InitContacts(Contacts *pCon)
{
	//通讯录初始化: 数组，usedsize
	assert(pCon);
	pCon->usedsize = 0;
	memset(pCon->per, 0, sizeof(pCon->per));    //string.h 对数组初始化
	//这里memset()如果pCon->per的容量已确定即定义时直接定义为数组，才可以
}
// 添加一个人到通讯录
void AddContacts(Contacts *pCon)
{
	// 往哪里放：数组 下标
	// 添加内容：姓名、年龄、……
	if (MAX_NUMPERSON == pCon->usedsize)
	{
		printf("sorry, Contacts is  full\n"); //通讯录满了
		return;
	}
	printf("请输入姓名 :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._name);
	printf("请输入年龄 :>_ ");
	scanf("%d", &(pCon->per[pCon->usedsize]._age));
	printf("请输入性别 :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._sex);
	printf("请输入电话 :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._tele);
	printf("请输入住址 :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._addr);
	++pCon->usedsize;
	printf("Adding successfully\n");
}
// 根据姓名查找通讯录，找到：返回下标；找不到：返回-1
int SearchContacts(Contacts *pCon)
{
	char name[MAX_NAME] = { 0 };
	if (0 == pCon->usedsize)
	{
		printf("sorry, Contacts is  empty\n");   //通讯录为空
		return -1;
	}
	printf("请输入联系人姓名 :>_ ");
	scanf("%s", name);
	for (int i = 0; i < pCon->usedsize; i++)
	{
		if (0 == strcmp(pCon->per[i]._name, name))    //  字符串的比较
		{
			return i;
		}
	}
	return -1;
}
void DelContacts(Contacts *pCon)
{
	int index = SearchContacts(pCon);//  代码复用
	if (-1 == index)
	{
		printf("No such person\n");
		return;
	}
	else
	{
		for (int i = index; i < pCon->usedsize - 1; i++)
		{
			pCon->per[i] = pCon->per[i + 1];
		}
		pCon->usedsize--;
		printf("Deleted successfully\n");
	}
}

// 显示打印
void PrintShowContacts(Contacts *pCon, int i)
{
	printf("%-20s", pCon->per[i]._name);   // 姓名
	printf("%-10s", pCon->per[i]._sex);    // 性别
	printf("%-10d", pCon->per[i]._age);    // 年龄
	printf("%-11s", pCon->per[i]._tele);   // 电话
	printf("%-15s", pCon->per[i]._addr);   // 地址
	printf("\n");
}

// 显示
void ShowContacts(Contacts *pCon)
{
	printf("%-20s %-10s %-10s %-11s  %-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	if (0 == pCon->usedsize)
	{
		printf("sorry, Contacts is  empty\n");   //通讯录为空
	}
	else
	{
		for (int i = 0; i < pCon->usedsize; i++)
		{
			PrintShowContacts(pCon, i);
		}
	}
}
// 清空
void ClearContacts(Contacts *pCon)
{
	pCon->usedsize = 0;
}
