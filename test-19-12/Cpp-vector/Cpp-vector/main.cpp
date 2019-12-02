#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;


#if 0
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // ��������ʱ�����aΪ����
	const int& ra = a;
	const int& b = 10;
	// int& b = 10; // ��������ʱ�����bΪ����
	double d = 12.34;
	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
	const int& rd = d;
}

int main()
{

	return 0;
}




void TestRef()
{
	int a = 10;
	// int& ra; // ����������ʱ�����
	int& ra = a;
	int& rra = a;
	printf("%p %p %p\n", &a, &ra, &rra);
}

void TestRef()
{
	int a = 10;
	int& ra = a;//<====������������
	printf("%d\n", a);
	printf("%d\n", ra);
}

int main()
{
	TestRef();
	return 0;
}
void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}


void main()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.erase(v.begin() + 5, v.end() - 3);	// ɾ��һ��Ԫ��
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	vector<int> v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i);
	}
	for (auto & i : v2)
	{
		cout << i << ' ';
	}
	cout << endl;

	v.swap(v2);		// ���� v �� v2 ����������ֵ����С������ȫ��������
//	v2.swap(v);		// ͬ��

	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (auto & i : v2)
	{
		cout << i << ' ';
	}
	cout << endl;
}

#endif


#if 0


/*	cout << endl;

for (auto & i : v2)
{
cout << i << ' ';
}

v.swap(v2);		// �� v2 �е������� v �е����ݽ���

for (auto & i : v)
{
cout << i << ' ';
}
cout << endl;

for (auto & i : v2)
{
cout << i << ' ';
}*/
cout << endl;

void main()
{
	vector<int> v;
	for (int i = 1; i < 10; ++i)
	{
		v.push_back(i);
	}

//	v.insert(v.begin() + 5, 6);		// �� 5 ��λ�ò���һ�� 6
//	v.insert(v.begin() + 5, 3, 20);	// �� 5 ��λ�ò��� 3 �� 20
//	v.insert(v.begin() + 5, v.begin(), v.end());	//��5��λ���ٲ���һ���Լ�
//	int a[5] = { 10, 20, 30, 40, 50 };
//	v.insert(v.begin() + 5, a + 1, a + 3);	//��5��λ�ò���һ������
	
//	v.erase(v.begin() + 5);		//ɾһ��
	v.erase(v.begin() + 5, v.end() - 2);	//ɾ�� 5 ~ β��-3 λ�õ�Ԫ��

	/*v.swap(v.begin(), v.end() - 1);*/
	
	for (auto & i : v)		// ��ӡ
	{
		cout << i << ' ';
	}
}

#endif
