#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


void GetMemory(char *p, int num)
{
	p = (char *)malloc(sizeof(char)* num);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str, 100); // str 仍然为 NULL  
	strcpy(str, "hello"); // 运行错误 
}

void GetMemory2(char **p, int num)
{
	*p = (char *)malloc(sizeof(char)* num);
}

void Test2(void)
{
	char *str = NULL;
	GetMemory2(&str, 100);	//注意参数是 &str,而不是str
	strcpy(str, "hello");
	cout << str << endl;
	free(str);
}


char *GetMemory3(int num)
{
	char *p = (char *)malloc(sizeof(char)* num);
	return p;
}

void Test3(void)
{
	char *str = NULL;
	str = GetMemory3(100);
	strcpy(str, "hello");
	cout << str << endl;
	free(str);
}

char *GetString(void)
{

	char p[] = "hello world";

	return p; // 
}

char *GetString(void)
{
	char p[] = "hello world";
	return p; // 编译器将提出警告 
}


{
	char *str = NULL;
	str = GetString(); // str 
}
void Test4(void)
{
	char *str = NULL;
	str = GetString(); // str 的内容是垃圾 
	cout << str << endl;
}

char *GetString2(void)
{
	char *p = "hello world";
	return p;
}

void Test5(void)
{
	char *str = NULL;
	str = GetString2();
	cout << str << endl;
}

strcpy(p,

	char *p = (char *)malloc(100);

strcpy(p, “hello”);

free(p);
// p
);

free(p);
// p 所指的内存被释放，但是p所指的地址仍然不变 



…

if (p != NULL) // 


if (p != NULL) // 没有起到防错作用 

{

	strcpy(p,


	{

		strcpy(p, “world”); // 出错  
	}
}

char *p = (char *)malloc(100);
strcpy(p, “hello”);
free(p);     // p 所指的内存被释放，但是p所指的地址仍然不变 
…
if (p != NULL) // 没有起到防错作用 
{
	strcpy(p, “world”); // 出错  
}
lass A
{

public:

	void Func(void){
		cout <<

	}
	| }
}

#include <iostream>
using namespace std;

class A
{
public:
	void Func(void){ cout << “Func of class A” << endl; }
};
void Test(void)
{
	A *p;
	{
		A a;
		p = &a; // 注意  a 的生命期 
	}

	p->Func();	// p是“野指针” 
}

class Obj
{
public:
	Obj(void){ cout << “Initialization” << endl; }
	~Obj(void){ cout << “Destroy” << endl; }
	void	Initialize(void){ cout << “Initialization” << endl; }
	void    Destroy(void){ cout << “Destroy” << endl; }
};

void UseMallocFree(void)
{

	Obj  *a = (obj *)malloc(sizeof(obj)); // 申请动态内存 
	a->Initialize();	// 初始化 
	//… 
	a->Destroy();		// 清除工作 
	free(a);			// 释放内存 
}



{

	Obj  *a = new Obj; // 
	

}
void UseNewDelete(void)
{

	Obj  *a = new Obj;	// 申请动态内存并且初始化 
	//… 
	delete a;			// 清除并且释放内存 
}

{
	A  *a = new A;
	if (a == NULL)
	{

		return;

	}
}
void Func(void)
{
	A  *a = new A;
	if (a == NULL)
	{
		return;

	}
	…
}