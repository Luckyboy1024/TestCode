#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define SEQ_INIT_SIZE 10
#define SEQ_INC_SIZE 2

typedef int Elemtype;	//typedef 将一切合法的变量名转化为类型

typedef struct
{
	Elemtype *data;
	int maxsize;
	int cursize;
}Seqlist;

void Init_Seqlist(Seqlist *list);
void Dest_Seqlist(Seqlist *list);

bool Insert_Seqlist(Seqlist *list, int pos, Elemtype val);

void Insert_pushfont(Seqlist *list, int pos, Elemtype val)

#endif  //__SQRTLIST_H__
