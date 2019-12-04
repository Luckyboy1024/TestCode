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
	//int& ra = a; // 该语句编译时会出错，a为常量
	const int& ra = a;
	const int& b = 10;
	// int& b = 10; // 该语句编译时会出错，b为常量
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d;
}

int main()
{

	return 0;
}




void TestRef()
{
	int a = 10;
	// int& ra; // 该条语句编译时会出错
	int& ra = a;
	int& rra = a;
	printf("%p %p %p\n", &a, &ra, &rra);
}

void TestRef()
{
	int a = 10;
	int& ra = a;//<====定义引用类型
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
	v.erase(v.begin() + 5, v.end() - 3);	// 删除一个元素
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

	v.swap(v2);		// 交换 v 和 v2 两个容器的值（大小和数据全部交换）
//	v2.swap(v);		// 同上

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

v.swap(v2);		// 将 v2 中的数据与 v 中的数据交换

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

//	v.insert(v.begin() + 5, 6);		// 在 5 的位置插入一个 6
//	v.insert(v.begin() + 5, 3, 20);	// 在 5 的位置插入 3 个 20
//	v.insert(v.begin() + 5, v.begin(), v.end());	//在5的位置再插入一遍自己
//	int a[5] = { 10, 20, 30, 40, 50 };
//	v.insert(v.begin() + 5, a + 1, a + 3);	//在5的位置插入一段数据
	
//	v.erase(v.begin() + 5);		//删一个
	v.erase(v.begin() + 5, v.end() - 2);	//删除 5 ~ 尾部-3 位置的元素

	/*v.swap(v.begin(), v.end() - 1);*/
	
	for (auto & i : v)		// 打印
	{
		cout << i << ' ';
	}
}

#endif
