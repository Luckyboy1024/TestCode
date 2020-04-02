#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
#include <string>
using namespace std;

void main()
{
	char str[255], _str[255], print[255];
	cin >> str;
	char* p = str;
	char* q = p;
	char* s = _str;
	int n, size = 0;
	while(!(('0' <= *p ) && (*p <= '9')))
	{
		p++;
		q++;
	}
	while (*p != '\0')
	{
		if (('0' <= *p) && (*p <= '9'))
		{
			while (('0' <= *p) && (*p <= '9'))
			{
				*s = *q;
				s++;
				q++;
				n++;
			}
			p = q + 1;
			if (n > size)
			{
				char* s1 = print;char* s2 = _str;
				while ('\0' != *s2)
				{
					*s1 = *s2;
					s1++;
					s2++;
				}
			}
			n = 0;
			s = _str;
		}
	}
	cout << print << endl;
}
#endif