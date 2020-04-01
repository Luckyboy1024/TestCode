#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


void * memmove(void * dst, const void * src, int count)
{
	void * ret = dst; 
	if (dst <= src || (char *)dst >= ((char *)src + count)) 
	{ 
		while (count--)
		{ 
			*(char *)dst = *(char *)src; 
			((char *)dst) ++; 
			((char *)src) ++; 
		} 
	} 
	else
	{ 
		dst = (char *)dst + count - 1; 
		src = (char *)src + count - 1; 
		while (count--) 
		{ 
			*(char *)dst = *(char *)src; 
			((char *)dst) --; 
			((char *)src) --; 
		} 
	} 
	return(ret); 
}

#if 0





void* MyMemcpy(void* dst, const void* src, int n)
{
	void* p = dst;
	assert(dst != NULL && src != NULL); 
	while (n--)
	{ 
		*(char *)dst = *(char *)src; 
		dst = (char *)dst + 1; 
		src = (char *)src + 1; 
	} 
	return p; 
}

int main()
{
	int arr1[] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6};
	MyMemcpy(arr1, arr2, 16);

	return 0;
}
char* MyStrchr(const char *dest, int n)
{
	char* p = dest; 
	assert(dest != NULL);
	while (*p != '\0')
	{
		if (*p == n)
		{
			return p;
		}
		p++;
	}
	return NULL;
}

int main()
{
	int i = 'r';
	char arr[] = "abrdertf";
	char *p = MyStrchr(arr, i);
	int n = p - arr + 1;
	if (p != NULL)
		printf("Result:\tfirst %c found at position %d\n\n", i, n);
	else
		printf("Result:\t%c not found\n" , i);
	return 0;
}

char* MyStrstr(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	const char* s1 = str1;
	const char* s2 = str2; 
	const  char *ret = str1;
	while (*ret != '\0')
	{
		s1 = ret;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		if (*s2 == '\0')
		{
			return ret;
		}
		ret++;
	}
	return NULL;
}

int main()
{
	char *str1 = "abcdef";
	char *str2 = "cde";
	char* p = MyStrstr(str1, str2);
	printf("%s\n", p);
	return 0;
}

int MyStrncmp(const char *str1, const char *str2, int n)
{
	assert(*str1 != NULL && *str2 != NULL);
	while (*str1 == *str2)
	{
		n--;
		if (n == 0)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


int main()
{
	char *str1 = "abcdef";
	char *str2 = "abedeg";
	int n = MyStrncmp(str1, str2, 2);
	printf("%d\n", n);
	return 0;
}

char* MyStrncat(char *dest, const char *src, int n)
{
	int i = 0;
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	for (i = 0; i < n; i++)
	{
		*dest++ = *src++;
	}
	return p;
}


int main()
{
	char dest[20] = "abcdefg ";
	char *src = "hello world";
	MyStrncat(dest, src, 2);
	printf("%s\n", dest);
	return 0;
}
char* MyStrncpy(char *dest, const char *src, int  n)
{
	int i = 0;
	char *p = dest;
	assert(dest != NULL && src != NULL);
	for (i = 0; i < n; i++)
	{
		*dest++ = *src++;
	}
	return p;
}

int main()
{
	char dest[20] = "abcdefg ";
	char *src = "hello world";
	MyStrncpy(dest, src, 2);
	printf("%s\n", dest);
	return 0;
}


char* MyStrcpy(char *dest, const char *src)
{
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (*dest++ = *src++);
	return p;
}

char* MyStrcat(char *dest, const char *src)
{
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++); 
	return p;
}

int MyStrcmp(const char *str1, const char *str2)
{
	assert(*str1 != NULL && *str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	while (*str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}
}



int main()
{
	char *str1 = "abcdef";
	char *str2 = "abcdeg";
	int n = MyStrcmp(str1, str2);
	printf("%d\n", n);
	return 0;
}



#endif