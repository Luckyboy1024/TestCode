#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

int main()
{
	Node head;
	InitList(&head);

	InsertHead(&head, 1);
	InsertTail(&head, 2);
	InsertTail(&head, 3);
	InsertTail(&head, 4);
	InsertTail(&head, 5);
	InsertTail(&head, 6);
	InsertTail(&head, 7);

	LastNodeValue(&head, 3);
	
	Show(&head);
	return 0;
}