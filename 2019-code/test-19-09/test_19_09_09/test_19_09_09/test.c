#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int x = 1, y = 012;
	printf("%d", y*x++);
	return 0;
}

int main()
{
	int j = 4;
	int i = j;
	for (; i <= 2 * j; i++)
	{
		switch (i/j)
		{
		case 0:
		case 1:
			printf("*");
			break;
		case 2:
			printf("#");
		}
	}
	return 0;
}

#if 0
int main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char *)&a;
	printf("%08x, %08x", i, *b);
	return 0;
}

int main()
{
	char a[] = "123456789", *p = a;
	int i = 0;
	while (*p)
	{
		if (i % 2 == 0)
		{
			*p = '!';
		}
		i++;
		p++;
	}
	puts(a);
	return 0;
}

int main()
{
	char str[] = "ABCDEFG";
	char *p1, *p2;
	p1 = "abcd"; p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);
	return 0;
}

int fun(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] == '\0' && s2[i] == '\0');
}

struct student
{
	int num;
	char name[32];
	float score;
}stu;

#include <stdio.h>
int main()
{
	int a = 2, *p1, **p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d, %d, %d\n", a, *p1, **p2);
	return 0;
}

	int main()
	{
		int k, j, s;
		for (k = 2; k < 6; k++, k++)
		{
			s = 1;
			for (j = k; j < 6; j++)
			{
				s += j;
			}
		}
		printf("%d\n", s);
		return 0;
	}

int arr[] = { 6, 7, 8, 9, 10 };
int *ptr = arr;
*(ptr++) += 123;
printf("%d, %d", *ptr, *(++ptr));

struct student
{
	char name[10];
	int age;
	char gender;
}std[3], *p = std;

scanf("%d", &(*p).age);
scanf("%c", &std[0].gender);
scanf("%c", &(p->gender));
scanf("%c", &std.name);
int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	printf("%d\n", (func()));
	return 0;
}

int f(int n)
{
	static int i = 1;
	if (n >= 5)
	{
		return n;
	}
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	printf("%d\n", f(1));
	return 0;
}

#include <stdio.h>
#define sum(a, b, c) a+b+c
int main()
{
	int i = 3;
	int j = 2;
	printf("%d\n", i*sum(i, (i+j), j));
	return 0;
}

#define MA(X, Y) (X*Y)
int i = 5;
i = MA(i, i + 1) - 7;


void fun(int x, int y, int *c, int *d)
{
	*c = x + y;
	*d = x - y;
}
int main()
{
	int a = 4, b = 3, c = 0, d = 0;
	fun(a, b, &c, &d);
	printf("%d %d\n", c, d);
	return 0;
}

int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
int main()
{
	int result = f(2, 4);
	printf("%d\n", result);
	return 0;
}

const int i = 0;
int *j = (int *)&i;
*j = 1;
printf("%d, %d", i, *j);

int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);
	return 0;
}

#include <stdio.h>
int fun(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}
int main()
{
	printf("%d\n", fun("goodbye!"));
	return 0;
}

int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	return 0;
}

#include <stdio.h>

int main()
{
	int i = 1;
	printf("%d, %d\n", sizeof(i++), i);
	return 0;
}
#include <stdio.h>
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}


int main()
{
	printf("%s\n", myString());
	return 0;
}

int main()
{
	char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s", p++);
		i++;
	}
	return 0;
}

char acX[] = "abc";
char acY[] = { 'a', 'b', 'c' };
char *scX = "abc";
char *scY = "abc";

int main()
{
	int a, x;
	for (a = 0, x = 0; a <= 1 && !x++; a++)
	{
		a++;
	}
	printf("%d %d", a, x);
	return 0;
}

#include <stdio.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);
	printf("%d, %x, %d\n", p1[-1], p2[0], p3[1]);
	return 0;
}

#include <stdio.h>
int main()
{
	const char *p = "hello,world";
	return 0;
}

union X
{
	int x;
	char y[4];
}a;
a.x = 0x11223344;		//16进制
x
void Func(char str_arg[2])
{
	int m = sizeof(str_arg);
	int n = strlen(str_arg);
	printf("%d\n", m);
	printf("%d\n", n);
}
int main()
{
	char str[] = "Hello";
	Func(str);
	return 0;
}

int main()
{
	unsigned long ulA = 0x11000000;
	printf("%x\n", *(unsigned char *)&ulA);
	return 0;
}

char *pcColor = "blue1";
char acColor[] = "blue1";

#include <stdio.h>

int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:
			s += 4;
		case 1:
			s += 1;
		case 2:
			s += 2;
		case 3:
			s += 3;
		}
	}
	printf("%d\n", s);
	return 0;
}


char s[] = "\\123456\123456\t";
printf("%d\n", strlen(s));

int x = 0;
switch (++x)
{
case 0:
	++x;
case 1:
	++x;
case 2:
	++x;
}

int a = 13, b = 94;
printf("%d\n", MOD(b, a + 4));
#include <stdio.h>
int main()
{
	int i = 0; 
	int j = 0;
	if ((++i > 0) || (++j > 0))
	{
		printf("i = %d; j = %d\n", i, j);
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int a = 1;
void test()
{
	int a = 2;
	a += 1;
}
int main()
{
	test();
	printf("%d\n", a);
	return 0;
}


for (m = 0, n = -1; n = 0; m++, n++)
{
	n++;
}


int x = 3;
void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d ", x);
	return;
}

int main()
{
	int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}
	return 0;
}



int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return (a);
}

int main()
{
	int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf(" %d\n", k);
	return 0;
}


int fun(int a, int b)
{
	if (a > b)
		return (a + b);
	else
		return (a - b);
}
int main()
{
	int x = 3, y = 8, z = 6, r;
	r = fun(fun(x, y), 2 * z);
	printf("%d\n", r);
	return 0;
}

unsigned long g_ulGlobal = 0;
void GlobalInit(unsigned long ulArg)
{
	ulArg = 0x01;
	return;
}

void Test()
{
	GlobalInit(g_ulGlobal);
	printf("%lu", g_ulGlobal);
	return;
}


#define CIR(r) r*r
void main()
{
	int a = 1;
	int b = 2;
	int t;
	t = CIR(a + b);
	printf("%d\n", t);
	return;
}


int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}
int main()
{
	printf("fun(2019) = %d\n", fun(2019));
	return 0;
}


int a = 4, b = 3, *P, *q, *w;
p = &a;
q = &b;
w = q;
q = NULL;

int main()
{
	char arr[2][4];
	strcpy((char*)arr, "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';
	printf("%s\n", arr);
	return 0;
}
int Change(int *pX)
{
	int y = 8;
	y = y - *pX;
	pX = &y;
	return 0;
}
int main()
{
	int xx = 3;
	int *pY = &xx;
	Change(pY);
	printf("%d\n", *pY);
	return 0;
}



int a[10];
int *pa;
pa = a;
#pragma pack(4) /*编译选项，表示 4 字节对齐*/

int main()
{
	struct tagTest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char d;
		long a;
	};
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;
	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;
}
#pragma pack()


#include <stdio.h>

enum ENUM_A
{
	X1,
	Y1, 
	Z1 = 5, 
	A1, 
	B1
};
enum ENUM_A enumA = Y1;
enum ENUM_A enumB = B1;


int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}

void main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d, ", k);
	k = fun(j, m);
	printf("%d\n", k);
	return;
}




int main()
{
	int i = 1, sum = 0;
	while (i < 10)
	{
		sum = sum + 1;
		i++;
	}
	printf("i=%d, sum=%d", i, sum);
	return 0;
}

#define F(X, Y) ((X)+(Y))
int main()
{
	int a = 3, b = 4;
	printf("%d\n", F(a++, b++));
}

char a[20];
char *p1 = (char *)a;
char *p2 = (char *)(a + 5);
int n = p2 - p1;
#endif