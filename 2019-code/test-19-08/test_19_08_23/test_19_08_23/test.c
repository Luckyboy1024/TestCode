#define _CRT_SECURE_NO_WARNINGS 1





#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bc()
{

}

void test()
{
	printf("###################\n");
	printf("##  base  1.0.1  ##\n");
	printf("##   Form: joy   ##\n");
	printf("###################\n");

	bc();

}

int main()
{
	test();
	return 0;
}

char a[] = {0};
char *p = a;
while ('\n' != getchar())
{
	scanf("%c", &(*(p + 1)));
}


double n1 = 0.0;
double n2 = 0.0;
char r;
scanf("%ld", &n1);
while (' ' == getchar());
while (<(r = getchar()));
while (' ' != (r = (char)getchar()));
while (' ' != (n2 = (double)getchar()));
//scanf("%lf%c%lf", &(double)n1, &r, &(double)n2);
if ('*' == r)
{
	printf("%lf", n1*n2);
	return;
}


#endif
