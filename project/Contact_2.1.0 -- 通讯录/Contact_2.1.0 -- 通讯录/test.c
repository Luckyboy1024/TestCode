#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
void menu()
{
	printf("---------------------\n");
	printf("  1.   add           \n");  //1.�����ϵ����Ϣ��ͨѶ¼
	printf("  2.   search        \n");  //2.����ָ����ϵ����Ϣ
	printf("  3.   del           \n");  //3.ɾ��ָ����ϵ����Ϣ
	printf("  4.   show          \n");  //4.��ʾ������ϵ����Ϣ
	printf("  5.   clear         \n");  //5.���������ϵ��
	printf("  6.   sort          \n");  //6.����������������ϵ��
	printf("  7.   destroy       \n");	//7.�Զ�̬�ڴ����һ���ͷ�
	printf("  0.   exit          \n");
	printf("---------------------\n");
}
void start()
{
	int input = 0;             //�������
	Contacts contacts;         //����ͨѶ¼contacts
	InitContacts(&contacts);   //��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��������Ĳ��� :>_ ");
		scanf("%d", &input);
		switch (input)
		{
		case _EXIT: //�˳�
			break;
		case _ADD:  //���
			AddContacts(&contacts); // ���һ���˵�ͨѶ¼
			break;
		case _SEARCH://����
			SearchContacts(&contacts); //  ����������ͨѶ¼���ҵ��������±ꣻ�Ҳ��������� - 1
			break;
		case _DEL:  //ɾ��
			DelContacts(&contacts);// ɾ��
			break;
		case _SHOW: //��ʾ
			ShowContacts(&contacts);
			break;
		case _CLEAR: //���
			ClearContacts(&contacts);
			break;
		case _SORT:  //����
			break;
		case _DESTROY:  //�ݻ�
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
