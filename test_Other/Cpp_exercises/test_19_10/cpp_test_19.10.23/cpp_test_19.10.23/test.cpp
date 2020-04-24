#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

float add(float a, int b)
{
	return a + (float)b;
}

//float add(float a, float b)
//{
//	return a + (float)b;
//}

float add(int a, float b)
{
	return a + (float)b;
}

void main()
{
	add(1.0, 2);
	add(1.0, 3.0);
	add(1, 2.0);

}