#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


void Init_Seqlist(Seqlist *list)
{
	list->data = (Elemtype*)malloc(sizeof(Elemtype)*SEQ_INIT_SIZE);
	if (NULL == list->data)
		exit(1);
	list->maxsize = SEQ_INIT_SIZE;
	list->cursize = 0;
}

void Dest_Seqlist(Seqlist *list)
{

}

bool Insert_Seqlist(Seqlist *list, int pos, Elemtype val)
{
	if (NULL == list) exit(1);
	if (pos<0 || pos > list->cursize) return false;
	if (list->cursize - list->maxsize < 1)
	{
		list->maxsize *= SEQ_INC_SIZE;
	}
	return true;
}

bool Insert_pushfont(Seqlist *list, Elemtype val)
{
	if (pos < 0 || pos > list->cursize) return false;
	for (int i = list->cursize; i > 0; --i)
	{
		list->data[i] = list->data[i - 1];
	}
	list->data[1] = val;
	list->cursize += 1;
	return true;
}


bool Insert_back(Seqlist *list, Elemtype val)
{
	if (pos < 0 || pos > list->cursize) return false;
	list->data[list->cursize] = val;
	list->cursize += 1;
	return true;
}

int FindValue(Seqlist *list, Elemtype val)
{
	if (NULL == list) exit(1);
	//assert(list);
	int i = 0;
	while (list->data[i] != val || i< list->cursize)
		i++;
	if (i == list->cursize)
		return -1;
	return i;
}


bool Erase_pos(Seqlist *list, int pos)
{
	if (pos < 0 || pos >= list->cursize) return false;
	for (int i = pos; i < list->cursize-1; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->cursize -= 1;
	free(list->data[list->cursize]);
	return true;
}

bool Remove(Seqlist *list, Elemtype val)
{
	//int find = 0;
	//while (find = FindValue(list, val))
	//{
	//	Erase_pos(list, find)
	//}
	//return true;
	return Erase_pos(list, FindValue(list, val));
}

bool Remove_all(Seqlist *list, Elemtype val)
{
	Elemtype *p = list->data;
	Elemtype *q = list->data;
	int i = 0;
	while (i < list->cursize)
	{
		if (val != *p)
		{
			++p;
			++q;
		}
		else
		{
			q++;
		}
	}
	return true;
}