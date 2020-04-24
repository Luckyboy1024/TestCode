#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "base.h"
//LinkList.h
//链式表的基本函数实现

//----------链表的存储结构表示------------
typedef struct LNode{//节点类型
	ElemType  data;//这里表示了每一项，其指数和系数
	struct LNode *next;
}*Link, *Position;
typedef struct{//链表类型
	Link head, tail;//分别指向线性链表中的头结点和最后一个结点
	int len;//指示线性链表中数据元素的个数
}LinkList;//每一项组成一个列表


Status InitList(LinkList *L);
Status MakeNode(Link *p, ElemType e);
void FreeNode(Link *p);
Status InsFirst(LinkList *L, Link h, Link s);
Position GetHead(LinkList L);
Status SetCurElem(Link p, ElemType e);
Status LocateElemP(LinkList L, ElemType e, Position *q, int(*compare)(ElemType, ElemType));
Position NextPos(Link p);
ElemType GetCurElem(Link p);
Status DelFirst(LinkList *L, Link h, Link *q);
Status ListEmpty(LinkList L);
Status Append(LinkList *L, Link s);
Status ListTraverse(LinkList L, void(*visit)(ElemType));

void visit(ElemType e);

#endif	//__LINKLIST_H__
