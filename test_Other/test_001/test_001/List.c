#define _CRT_SECURE_NO_WARNINGS 1


#include "List.h"

//初始化
void InitList(plist plist)
{
	assert(plist);
	plist->data = -1;
	plist->next = NULL;
}


//得到一个节点
static Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

//头插  plist 头结点的地址
void InsertHead(plist plist, int val)
{
	assert(plist);
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
}

//尾插  
void InsertTail(plist plist, int val)
{
	assert(plist);
	Node *p = plist;		//先从头结点开始
	Node *pGet = GetNode(val);
	while (NULL != p->next)
	{
		p = p->next;
	} 
	p->next = pGet;
}


//删除  正数第 k 个节点删除
void Delete(plist plist, int k)
{
	assert(plist);
	  
}


//打印
void Show(plist plist)
{
	assert(plist);
	Node* p = plist->next;
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

//找到倒数第 k 个指针  两个节点指针，p先走 q后走
Node *LastKNode(plist plist, int k)
{
	assert(plist);
	if (k < 0)
	{
		return NULL;
	}
	Node* p = plist;
	Node* q = plist;
	while (0 < k-1)
	{
		if (NULL != p->next)
		{
			p = p->next;
			k--;
		}
		else
		{
			return NULL;
		}
	}
	q->next = p->next;
	while (NULL != p->next)
	{
		p = p->next;
		q = q->next;
	}
	if (NULL == p->next)
	{
		return q;
	}
}

void LastNodeValue(plist plist, int k)
{
	Node *p;
	p = LastKNode(plist, k);
	printf("%d", p->data);
}


//头插法 逆置
void ReverseLink(plist plist)
{
	Node *pN = NULL;
	Node *p = plist->next;
	plist->next = NULL;
	while (NULL != p)
	{
		pN = p->next;			//先绑下一个节点的地址
		p->next = plist->next;	//
		plist->next = p;		//改变头结点->next
	}
}

//三指针  逆置
Node *ReverseLink_3p(plist plist)
{
	//prev  前驱；  pCur； pCurN 后继
	//rever_plist  新头结点
	Node *rever_plist = NULL;
	Node *prev = plist;
	Node *pCur = plist->next;
	Node *pCurN = pCur->next;
	plist->next = NULL;
	while (NULL != pCur)
	{
		pCurN = pCur->next;
		if (NULL == pCurN)
		{
			rever_plist = pCur;
		}
		pCur->next = prev;
		pCur = plist->next;

		plist->next = ;
		pCur->next = plist;
		plist = pCur;
		//走完  移动
		pCurN = pCurN->next;
		pCur = pCur->next;
		prev = prev->next;
	}

}





