#define _CRT_SECURE_NO_WARNINGS 1

// String的普通构造函数 
String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
	}
}

// String的析构函数 

String::~String(void)
{
	delete[] m_data;
	// 由于m_data是内部数据类型，也可以写成  delete m_data; 
}

String  a(“hello”);
String  b(“world”);
String  c = a;		// 调用了拷贝构造函数，最好写成 c(a); 
	c = b;			// 调用了赋值函数  

	本例中第三个语句的风格较差，宜改写成String c(a) 以区别于第四个语句。
}


// 拷贝构造函数
String::String(const String &other)
{
	// 允许操作other的私有成员m_data
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	strcpy(m_data, other.m_data);
}

// 赋值函数
String & String::operate = (const String &other)
{
	// (1) 检查自赋值 
	if (this == &other)
		return *this;
	// (2) 释放原有的内存资源 
	delete[] m_data;

	// （3）分配新的内存资源，并复制内容 
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	strcpy(m_data, other.m_data);
	// （4）返回本对象的引用 
	return *this;
}

class A
{
	…
private:
	A(const A &a);	// 私有的拷贝构造函数
	A & operate = (const A &a); // 私有的赋值函数
};

如果有人试图编写如下程序：

A b(a);		// 调用了私有的拷贝构造函数
b = a;		// 调用了私有的赋值函数  

}


{
public:

	virtual ~Base() { cout << "~Base" << endl; }
};

class Derived : public Base
{
public:

	virtual ~Derived() { cout << "~Derived" << endl; }
};

#include <iostream.h> 
class Base
{
public:
	virtual ~Base() { cout << "~Base" << endl; }
};
class Derived : public Base
{
public:
	virtual ~Derived() { cout << "~Derived" << endl; }
};
void main(void)
{
	Base * pB = new Derived;  // upcast 
	delete pB;
}


class Base
{
public:
	…
	Base & operate = (const Base &other); // 类Base的赋值函数 
private:
	int  m_i, m_j, m_k;
};

class Derived : public Base
{
public:
	…
	Derived & operate = (const Derived &other);// 类Derived的赋值函数 
private:
	int  m_x, m_y, m_z;
};


Derived & Derived::operate = (const Derived &other)
{
	//（1）检查自赋值
	if (this == &other)
		return *this;

	//（2）对基类的数据成员重新赋值 
	Base::operate = (other);	// 因为不能直接操作私有数据成员 

	//（3）对派生类的数据成员赋值 
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;

	//（4）返回本对象的引用 
return *this;

}
