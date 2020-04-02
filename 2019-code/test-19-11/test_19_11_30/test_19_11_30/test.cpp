#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;




int main()
{

	return 0;
}

#if 0
int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
}

int main()
{
	int a = 10;
	int& ra = a;
	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;
	return 0;
}
#endif