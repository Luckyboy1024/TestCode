#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// list ---> 
ADT List{
	InitList(&L);	//构造一个空的线性表 L
	DestroyList(&L);	//若线性表 L 已存在，销毁线性表 L
	ClearList(&L);		//若线性表 L 已存在，将表 L 重置为空表
	ListEmpty(L);		//线性表 L 已存在，若 L 为空表，则返回 TRUE，否则返回 FALSE
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
