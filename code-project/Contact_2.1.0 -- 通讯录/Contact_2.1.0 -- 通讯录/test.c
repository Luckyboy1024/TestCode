#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
void menu()
{
	printf("---------------------\n");
	printf("  1.   add           \n");  //1.添加联系人信息到通讯录
	printf("  2.   search        \n");  //2.查找指定联系人信息
	printf("  3.   del           \n");  //3.删除指定联系人信息
	printf("  4.   show          \n");  //4.显示所有联系人信息
	printf("  5.   clear         \n");  //5.清空所有联系人
	printf("  6.   sort          \n");  //6.以名字排序所有联系人
	printf("  7.   destroy       \n");	//7.对动态内存进行一个释放
	printf("  0.   exit          \n");
	printf("---------------------\n");
}
void start()
{
	int input = 0;             //接收输出
	Contacts contacts;         //定义通讯录contacts
	InitContacts(&contacts);   //初始化通讯录
	do
	{
		menu();
		printf("请输入你的操作 :>_ ");
		scanf("%d", &input);
		switch (input)
		{
		case _EXIT: //退出
			break;
		case _ADD:  //添加
			AddContacts(&contacts); // 添加一个人到通讯录
			break;
		case _SEARCH://查找
			SearchContacts(&contacts); //  按姓名查找通讯录，找到：返回下标；找不到：返回 - 1
			break;
		case _DEL:  //删除
			DelContacts(&contacts);// 删除
			break;
		case _SHOW: //显示
			ShowContacts(&contacts);
			break;
		case _CLEAR: //清空
			ClearContacts(&contacts);
			break;
		case _SORT:  //排序
			break;
		case _DESTROY:  //摧毁
			DestroyContacts(&contacts);
			break;
		}
	} while (input);
}
int main()
{
	start();
	return 0;
}
