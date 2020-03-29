#define _CRT_SECURE_NO_WARNINGS 1


#include "safety.h"

typedef int Datatype;

#define Num_ziyuan (3);	// 资源数目

int available[3][3] = { 
	{ 1, 1, 1 }, 
	{ 1, 1, 1 }, 
	{ 1, 1, 1 } };

typedef struct Safety{
	Datatype Work[Num_ziyuan];	//
	_Bool Finish;
}Safety;


/*
Work[][]
Finish[]
*/


void init_Safety(Safety* arr)
{
	arr->Work
}


int test_safety()
{
	Safety arr[3];
	init
}
