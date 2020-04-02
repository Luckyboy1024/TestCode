#define _CRT_SECURE_NO_WARNINGS 1




#include <stdio.h>

int fun(int x, int a[][4])
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}

//111 1110 0011
//111 1110 


int main()
{
	printf("%x\n", 2048-2019);
	return 0;
}
#if 0

int main()
{
	int a, b, c, g, i, j, n, s, h[10];
	long m, max, d, t;
	printf("请输入位数 n (n>1): ");
	scanf("%d", &n);
	s = 0;
	t = 1;
	a = n / 2;
	for ()
	return 0;
}

class A
{…
	A(int x);  // A的构造函数
};
class B : public A
{…
	B(int x, int y);// B的构造函数
};
B::B(int x, int y)
	: A(x)		// 在初始化表里调用A的构造函数
{
	…
}

B::B(const A &a)
{
	m_a = a;
	…
}

class F 
{ 
public: 
	F(int x, int y);		// 构造函数 
private: 
	int m_x, m_y; 
	int m_i, m_j; 
}

F::F(int x, int y) 
{  
	m_x = x; 
	m_y = y; 
	m_i = 0;  
	m_j = 0; 
}
F::F(int x, int y) 
{  
	m_x = x; 
	m_y = y; 
	m_i = 0;  
	m_j = 0; 
} 

F::F(int x, int y) 
: m_x(x), m_y(y)  
{  
	m_i = 0;  
	m_j = 0; 
}

class A 
{
	… 
	A(void);			// 无参数构造函数 
	A(const A &other);	// 拷贝构造函数 
	A & operate = (const A &other); // 赋值函数 
}；
class B
{
public:
	B(const A &a); // B的构造函数 
private:
	A  m_a;// 成员对象 
};

class String

{
public:
	String(const char *str = NULL); // 普通构造函数 
	String(const String &other);	// 拷贝构造函数 
	~String(void);					// 析构函数 
	String & operate = (const String &other); // 赋值函数 
private:
	char *m_data;					// 用于保存字符串 
};

#endif