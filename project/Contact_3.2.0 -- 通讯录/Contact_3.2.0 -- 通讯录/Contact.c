#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
void InitContacts(Contacts *pCon)
{
	//ͨѶ¼��ʼ��: ���飬usedsize
	assert(pCon);
	//pCon->usedsize = 0;
	////����memset()���pCon->per��������ȷ��������ʱֱ�Ӷ���Ϊ���飬�ſ���
	//memset(pCon->per, 0,  sizeof(pCon->per));    //string.h �������ʼ��
	pCon->capticty = DEFAULT_SIZE;
	pCon->usedSize = 0;
	pCon->per = (PersonInfo  *)malloc(sizeof(PersonInfo)*pCon->capticty);      // stdlib.h
	assert(pCon->per != NULL);
	memset(pCon->per, 0, sizeof(PersonInfo)*pCon->capticty);
}
//�ж�ͨѶ¼�Ƿ�Ϊ��������ֵ 0 ����ʾ����ʧ�ܣ�1 ����ʾ���ݳɹ�
// ע��static ���εĺ��������������������ڵ�ǰ .c �ļ���
static int CheckFull(Contacts *pCon)
{
	if (pCon->usedSize == pCon->capticty)  //ͨѶ¼����
	{
		// ���������� realloc()
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
// ���һ���˵�ͨѶ¼
void AddContacts(Contacts *pCon)
{
	// ������ţ����� �±�
	// ������ݣ����������䡢����
	int ret = CheckFull(pCon);
	if (0 == ret)//����ʧ��
	{
		printf("Sorry, Contacts is full,  and Capacity of failure\n");
		return;
	}
	else
	{
		printf("���������� :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._name);
		printf("���������� :>_ ");
		scanf("%d", &(pCon->per[pCon->usedSize]._age));
		printf("�������Ա� :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._sex);
		printf("������绰 :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._tele);
		printf("������סַ :>_ ");
		scanf("%s", pCon->per[pCon->usedSize]._addr);
		++pCon->usedSize;
		printf("Adding successfully\n");
	}
}
// ������������ͨѶ¼���ҵ��������±ꣻ�Ҳ���������-1
int SearchContacts(Contacts *pCon)
{
	char name[MAX_NAME] = { 0 };
	if (0 == pCon->usedSize)
	{
		printf("sorry, Contacts is   empty\n");   //ͨѶ¼Ϊ��
		return -1;
	}
	printf("��������ϵ������ :>_ ");
	scanf("%s", name);
	for (int i = 0; i < pCon->usedSize; i++)
	{
		if (0 == strcmp(pCon->per[i]._name, name))    //   �ַ����ıȽ�
		{
			return i;
		}
	}
	return -1;
}
void DelContacts(Contacts *pCon)
{
	int index = SearchContacts(pCon);//   ���븴��
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
// ��ʾ
void ShowContacts(Contacts *pCon)
{
	printf("%-20s %-10s %-10s %-11s   %-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	if (0 == pCon->usedSize)
	{
		printf("sorry, Contacts is   empty\n");   //ͨѶ¼Ϊ��
	}
	else
	{
		for (int i = 0; i < pCon->usedSize; i++)
		{
			printf("%-20s", pCon->per[i]._name);   // ����
			printf("%-10s", pCon->per[i]._sex);    // �Ա�
			printf("%-10d", pCon->per[i]._age);    // ����
			printf("%-11s", pCon->per[i]._tele);   // �绰
			printf("%-15s", pCon->per[i]._addr);   // ��ַ
			printf("\n");
		}
	}
}
// ���
void ClearContacts(Contacts *pCon)
{
	pCon->usedSize = 0;
}
// �ݻ�
void DestroyContacts(Contacts *pCon)
{
	assert(pCon != NULL);
	free(pCon->per);
	pCon->per = NULL;
	pCon->capticty = 0;
	pCon->usedSize = 0;
}
