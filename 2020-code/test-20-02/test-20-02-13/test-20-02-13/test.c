#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char* deleteword(char* path, char* src)
{
	char* p;
	char* q;
	char* t;
	p = path;
	t = path;
	q = src;
	while (*t != '\0'){
		while (*q != '\0')
		{
			if (*t == *q)
			{
				*p = *(t + 1);
				t++;
				break;
			}
			q++;
		}
		if ('\0' == *q)
		{
			*p = *t;
			t++;
			p++;
		}
		q = src;
	}
	*p = *t;
	return path;
}

int main()
{
	char path[100];
	char src[100];
	gets(path);
	gets(src);
	deleteword(path, src);
	return 0;
}
