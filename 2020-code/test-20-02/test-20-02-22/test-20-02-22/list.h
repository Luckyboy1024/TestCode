#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// list ---> 
ADT List{
	InitList(&L);	//����һ���յ����Ա� L
	DestroyList(&L);	//�����Ա� L �Ѵ��ڣ��������Ա� L
	ClearList(&L);		//�����Ա� L �Ѵ��ڣ����� L ����Ϊ�ձ�
	ListEmpty(L);		//���Ա� L �Ѵ��ڣ��� L Ϊ�ձ��򷵻� TRUE�����򷵻� FALSE
	ListLength(L);		//
	GetElem(L, i, &e);
	LocateElem(L, e, compare());
	PriorElem(L, cur, e, &pre.e);
	NextElem(L, cur, e, &next.e);
	ListInsert(&L, i, e);
	ListDelete(&L, i, &e);
	ListTraverse(L, visit());
}ADT List


void InitList();
