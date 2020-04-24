#define _CRT_SECURE_NO_WARNINGS 1

//Polynomial.h
//一元多项式基本操作头文件



#include "LinkList.h"

typedef LinkList polynomial;


Status Remove_Polyn(LinkList *L, Link q);
int cmp(term a, term b);
void CreatPolyn(polynomial &p, int m);
void DestroyPolyn(polynomial &p);
int PolynLength(polynomial p);
void PrintPolyn(polynomial p);
void AddPolyn(polynomial &Pa, polynomial &Pb);
