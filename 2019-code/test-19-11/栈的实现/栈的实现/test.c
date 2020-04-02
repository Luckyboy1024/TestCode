#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>
#include <malloc.h>

int main() {
	STACK S;
	initStack(&S);
	pushStack(&S);
	pushStack(&S);
	pushStack(&S);
	popStack(&S);
	traversalStack(&S);
	return 0;
}