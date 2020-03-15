#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
void InitContacts(Contacts *pCon)
{
	//ͨѶ¼��ʼ��: ���飬usedsize
	assert(pCon);
	pCon->usedsize = 0;
	memset(pCon->per, 0, sizeof(pCon->per));    //string.h �������ʼ��
	//����memset()���pCon->per��������ȷ��������ʱֱ�Ӷ���Ϊ���飬�ſ���
}
// ���һ���˵�ͨѶ¼
void AddContacts(Contacts *pCon)
{
	// ������ţ����� �±�
	// ������ݣ����������䡢����
	if (MAX_NUMPERSON == pCon->usedsize)
	{
		printf("sorry, Contacts is  full\n"); //ͨѶ¼����
		return;
	}
	printf("���������� :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._name);
	printf("���������� :>_ ");
	scanf("%d", &(pCon->per[pCon->usedsize]._age));
	printf("�������Ա� :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._sex);
	printf("������绰 :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._tele);
	printf("������סַ :>_ ");
	scanf("%s", pCon->per[pCon->usedsize]._addr);
	++pCon->usedsize;
	printf("Adding successfully\n");
}
// ������������ͨѶ¼���ҵ��������±ꣻ�Ҳ���������-1
int SearchContacts(Contacts *pCon)
{
	char name[MAX_NAME] = { 0 };
	if (0 == pCon->usedsize)
	{
		printf("sorry, Contacts is  empty\n");   //ͨѶ¼Ϊ��
		return -1;
	}
	printf("��������ϵ������ :>_ ");
	scanf("%s", name);
	for (int i = 0; i < pCon->usedsize; i++)
	{
		if (0 == strcmp(pCon->per[i]._name, name))    //  �ַ����ıȽ�
		{
			return i;
		}
	}
	return -1;
}
void DelContacts(Contacts *pCon)
{
	int index = SearchContacts(pCon);//  ���븴��
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

// ��ʾ��ӡ
void PrintShowContacts(Contacts *pCon, int i)
{
	printf("%-20s", pCon->per[i]._name);   // ����
	printf("%-10s", pCon->per[i]._sex);    // �Ա�
	printf("%-10d", pCon->per[i]._age);    // ����
	printf("%-11s", pCon->per[i]._tele);   // �绰
	printf("%-15s", pCon->per[i]._addr);   // ��ַ
	printf("\n");
}

// ��ʾ
void ShowContacts(Contacts *pCon)
{
	printf("%-20s %-10s %-10s %-11s  %-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	if (0 == pCon->usedsize)
	{
		printf("sorry, Contacts is  empty\n");   //ͨѶ¼Ϊ��
	}
	else
	{
		for (int i = 0; i < pCon->usedsize; i++)
		{
			PrintShowContacts(pCon, i);
		}
	}
}
// ���
void ClearContacts(Contacts *pCon)
{
	pCon->usedsize = 0;
}
