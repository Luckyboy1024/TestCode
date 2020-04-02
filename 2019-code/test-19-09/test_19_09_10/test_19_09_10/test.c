#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#define N 3
#define Y(n) ((N+1)*n)

#include <stdio.h>
int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
int main()
{
	printf("%d\n", fun(2019));
	return 0;
}

int Func(int a)
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
		k = Func(a++);
	}
	printf("%d\n", k);
	return 0;
}


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


char x[] = "abcd";
char y[] = { 'a', 'b', 'c', 'd' };

int main()
{
	int i, x, y;
	i = x = y = 0;
	do{
		++i;
		if (i % 2)
			x += i,
			i++;
		y += i++;
	} while (i <= 7);
	printf("%d %d %d", i, x, y);
	return 0;
}

int i = 6;
if (i <= 6)
{
	printf("hello\n");
}
else
{
	printf("bye-bye\n")
}

int i = 0;
long long t = sizeof(i++);
printf("%d", i);

int x = 0, y = 0, z = 0;
z = (x == 1) && (y = 2);
printf("%d\n", y);

void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}
void main()
{
	int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	foo(a);
	return 0;
}

unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
unsigned long *pulPtr;
pulPtr = pulArray;
*(pulPtr + 2) += 2;
printf("%d, %d\n", *pulPtr, *(pulPtr +2));

void main()
{
	char *szStr = "abcde";
	szStr += 2;
	printf("%lu\n", szStr);
	return;
}

int main()
{
	int i;
	char acNew[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (i = 0; i < 10; i++)
	{
		acNew[i] = '0';
	}
	printf("%d\n", strlen(acNew));
	return 0;
}

#endif

#if 0


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&arr + 1);
	printf("%d %d\n", *(arr + 1), *(ptr - 1));
	return 0;
}

int main()
{
	unsigned short sht = 0;
	sht--;
	printf("%d", sht);
	return 0;
}
#endif