#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
void Print(char c, int a)
{
	cout << c << " " << a << endl;
}

void Print(int a, char c)
{
	cout << c << " " << a << endl;
}

void main()
{
	Print(10, 'a');
	Print('a', 10);
}

int add(int a, int b)
{
	return a + b;
}
int add(int a, int b, int c)
{
	return a + b + c;
}

void main()
{
	add(1, 2, 3);
	add(1, 2);
}

int add(int a, int b)
{
	return a + b;
}
float add(float a, float b)
{
	return a + b;
}

void main()
{
	add(1, 2);
	//add(1.0, 2.0);		//error
	float a = 1.0, b = 2.0;
	add(a, b);
}


void test()
{

}

void main()
{
	test();
}



//ȱʡ������
//����ʹ��ʱ��
void fun(int a = 100, int b = 0)
{
	cout << a << " " << b << endl;
}
void fun2(int a, int b = 0)
{
	cout << a << " " << b << endl;
}

void test()
{
	fun();
	fun(1, 2);
	fun(100);
	//fun(, 100);	//error
	fun2(100);
}
void test()
{
	int a = 0;
	double b = 0.0;
	cin >> a >> b;
	cout << a << " " << b << endl;
}
void testIO()
{
	////  C ���������
	//printf("hello world\n");
	//int a = 10;
	//printf("%d\n", a);
	
	//C++����ĳ�Աͬ���������ռ� std
	int a = 10;
	std::cout << a;
	std::cout << "\n";		//��ӡ����
	double b = 4.2;
	std::cout << b;
	std::cout << "\n";
	std::cin >> a;		//�ӿ���̨����һ������a
	std::cout << a;
	std::cout << "\n";		//��ӡ����
}


namespace N1{		//�����ռ�
	int a;			//�����ռ��µı���
	int b;
	int add(int a, int b)
	{
		return a + b;
	}
}

//�����ռ��Ƕ��
namespace N2{		//�����ռ�
	int a;			//�����ռ��µı���
	int b;
	int add(int a, int b)
	{
		return a + b;
	}
	namespace N3{
		int a;
		int b;
		int sub(int a, int b)
		{
			return a - b;
		}
	}
}

//�����ռ�ķֶζ���
namespace N4{
	int a;
	int sub(int a, int b)
	{
		return a - b;
	}
}

namespace N4{
	int b;
	int sub(int a, int b)
	{
		return a - b;
	}
}

//�����ռ��г�Ա�ķ��ʷ�ʽ
//�� �����ռ����� + :: + ������		����ð��::�����������޶���

void test(){
	N1::a = 10;
	N1::add(10, 5);

	N2::N3::b = 20;
}

//�� �ں����⣬using �����ռ����� + :: + ������
using N1::a;
using N1::add;
void test2()
{
	a = 20;
	add(100, 200);
}

//�� using namespace + �����ռ�����     �������ռ�չ��
using namespace N1;
void test2()
{
	a = 20;
	add(100, 200);
}
#endif