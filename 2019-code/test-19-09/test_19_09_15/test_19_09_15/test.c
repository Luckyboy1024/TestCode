#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


#if 0
struct ListNode *NextK(ListNode* sl, int k)
{
	if (NULL == sl)
		return NULL;
	ListNode* s1, *s2;
	s1 = s2 = sl;
	while (--k && s2->next)
	{
		s2 = s2->next;
	}
	while (s2->next)
	{
		s1 = s1->next;
		s2 = s2->next;
	}
	if (NULL == s2->next)
		return NULL;
	return s1;
}
struct ListNode *NextK(ListNode* sl, int k)
{
	ListNode* s1, s2;
	s1 = s2 = sl->head;
	while (k-- && s2->next)
	{
		s2 = s2->next;
	}
	while (s2)
	{
		s1 = s1->next;
		s2 = s2->next;
	}
	return s1;
}
#endif