#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __LIST_H__			//防止.h文件重名
#define __LIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *plist;

//初始化
void InitList(plist plist);
//头插
void InsertHead(plist plist, int val);
//尾插
void InsertTail(plist plist, int val);
//打印
void Show(plist plist);

//从任意位置插入
//删除
void Delete(plist plist, int val);

//查找

//找到倒数第 k 个指针  两个节点指针，p先走 q后走
Node *Last_K_Node(plist plist, int k);
void LastNodeValue(plist plist, int k);

//头插法 逆置
void ReverseLink(plist plist);



#endif  //__LIST_H__
