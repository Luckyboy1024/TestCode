#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;

class Base
{
public: 
	void f(int x); 
};

class Derived : public Base 
{ 
public: 
	void f(char *str); 
}; 

void Test(void) 
{ 
	Derived *pd = new Derived; 
	pd->f(10); // error 
} 

class Derived : public Base
{
public:
	void f(char *str);
	void f(int x) { Base::f(x); }
};

void output(int x)
{ 
	cout << " output int " << x << endl ; 
}

void output(int x, float y)
{ 
	cout << " output int " << x << " and float " << y << endl ; 
}

void main(void)
{
	int x = 1;
	float y = 0.5;
	//output(x);  	// error! ambiguous call 
	output(x,y);	// output int 1 and float 0.5 
} 

void Foo(int x, int y=0, int z=0); 
#if 0
class Base
{
public:
	void f(int x){ cout << "Base::f(int) " << x << endl; }
	void f(float x){ cout << "Base::f(float) " << x << endl; }
	virtual void g(void){ cout << "Base::g(void)" << endl; }
};

class Derived : public Base
{
public:
	virtual void g(void){ cout << "Derived::g(void)" << endl; }
};

void main(void)
{
	Derived  d; 
	Base *pb = &d; 
	pb->f(42);   	// Base::f(int) 42
	pb->f(3.14f);	// Base::f(float) 3.14 
	pb->g();   		// Derived::g(void) 
}


class Base 
{ 
public: 
	virtual void f(float x){ cout << "Base::f(float) " << x << endl; } 
	void g(float x){ cout << "Base::g(float) " << x << endl; } 
	void h(float x){ cout << "Base::h(float) " << x << endl; } 
}; 

class Derived : public Base
{
public: 
	virtual void f(float x){ cout << "Derived::f(float) " << x << endl; } 
	void g(int x){ cout << "Derived::g(int) " << x << endl; } 
	void h(float x){ cout << "Derived::h(float) " << x << endl; } 
};

void main(void) 
{ 
	Derived  d; 
	Base *pb = &d; 
	Derived *pd = &d; 
	// Good : behavior depends solely on type of the object 
	pb->f(3.14f); 	// Derived::f(float) 3.14  
	pd->f(3.14f); 	// Derived::f(float) 3.14 

	// Bad : behavior depends on type of the pointer 
	pb->g(3.14f); 	// Base::g(float) 3.14  
	pd->g(3.14f); 	// Derived::g(int) 3        (surprise!) 

	// Bad : behavior depends on type of the pointer 
	pb->h(3.14f); 	// Base::h(float) 3.14      (surprise!) 
	pd->h(3.14f); 	// Derived::h(float) 3.14  
}

void output(int x); // 函数声明 
void output(float x); // 函数声明 

void output(int x)
{
	cout << " output int " << x << endl;
}

void output(float x)
{
	cout << " output float " << x << endl;
}

void main(void)
{
	int   x = 1;
	float y = 1.0;
	output(x);  // output int 1 
	output(y);	// output float 1.0 
	output(1);	// output int 1 
	// output(0.5); 	// error! ambiguous call, 
	output(int(0.5));   // output int 0 
	output(float(0.5));	// output float 0.5 
}

#endif
