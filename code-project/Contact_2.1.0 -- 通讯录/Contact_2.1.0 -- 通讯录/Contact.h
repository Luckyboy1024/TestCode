#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20    //������Ϣ�Ĵ�С��������20���ַ�
#define MAX_SEX 4      //�Ա���Ϣ�Ĵ�С��������4���ַ�
#define MAX_TELE 20    //�绰��Ϣ�Ĵ�С��������20���ַ�
#define MAX_ADDR 20    //��ַ��Ϣ�Ĵ�С��������20���ַ�

#define DEFAULT_SIZE 2	//��ʼ����Ϊ 30

enum Option      // ö�ٳ���
{
	_EXIT, //�˳�
	_ADD,  //���
	_SEARCH,//����
	_DEL,  //ɾ��
	_SHOW, //��ʾ
	_CLEAR, //���
	_SORT,  //����
	_DESTROY//�ݻ�
};
typedef struct PersonInfo  //������Ϣ
{
	char _name[MAX_NAME];      //����
	short _age;                //����
	char _tele[MAX_TELE];      //�绰
	char _addr[MAX_ADDR];      //סַ
	char _sex[MAX_SEX];        //�Ա�
}PersonInfo;
//�ṹ ���� ͨѶ¼
typedef struct Contacts
{
	PersonInfo *per;
	int usedSize;    //��ʹ�õĸ���
	int capticty;	//����
}Contacts;
void InitContacts(Contacts *pCon);      // ��ʼ��ͨѶ¼
void AddContacts(Contacts *pCon);    //  ���һ���˵�ͨѶ¼
int SearchContacts(Contacts *pCon);     // ������������ͨѶ¼���ҵ��������±ꣻ�Ҳ���������-1
void DelContacts(Contacts *pCon);    //  ɾ��
void ShowContacts(Contacts *pCon);      // ��ʾ
void ClearContacts(Contacts *pCon);     // ���
void DestroyContacts(Contacts *pCon);     // �ݻ�

#endif //__CONTACT_H__
