#define _CRT_SECURE_NO_WARNINGS 1




#if 0
#include <iostream.h>
void output(int x); // 函数声明 
void output(float x); // 函数声明 

void output(int x)
{
	cout << "";
}



{ 
	cout << " output int " << x << endl ; 
} 

void output( float x) 
{ 

	cout << " output float " << x << endl ; 
} 

void main(void) 
{ 

	int   x = 1; 

	float y = 1.0; 

	output(x);  

	// output int 1 

	output(y);  

	// output float 1 

	output(1);  

	// output int 1 
	// output(0.5); 

	// error! ambiguous call, 


	void output( int x) 
	{ 

		cout << " output int " << x << endl ; 
	} 

	void output( float x) 
	{ 

		cout << " output float " << x << endl ; 
	} 

	void main(void) 
	{ 

		int   x = 1;

		float y = 1.0;

		output(x);

		// output int 1 

		output(y);

		// output float 1 

		output(1);

		// output int 1 
		// output(0.5); 

		// error! ambiguous call, 因为自动类型转换 

		output(int(0.5)); // output int 0 

		output(float(0.5));
		// output float 0.5 
	}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	return 0;
}

#include <iostream>
using namespace std;
void Func(void)
{
	A  *a = new A;
	if (a == NULL)
	{
		cout << “Memory Exhausted” << endl;
		exit(1);
	}
	…
}

void main(void)
{
	float *p = NULL;
	while (TRUE)
	{
		p = new float[1000000];
		cout << “eat memory” << endl;
		if (p == NULL)
			exit(1);
	}
}

class Obj
{
public:
	Obj(void);  	// 无参数的构造函数 
	Obj(int x); 	// 带一个参数的构造函数  
	…
}
void Test(void)
{
	Obj  *a = new Obj;
	Obj  *b = new Obj(1); // 初值为1 
	…
		delete a;
	delete b;
}

#endif