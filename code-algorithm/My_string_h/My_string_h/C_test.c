#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void *Mymemmove(void *dest, const void *src, int count)
{
	void *ret = dest;
	if (dest < src)
	{
		while (count--){
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (count--){
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	memmove(arr1 + 2, arr1, 16);
	Mymemmove(arr2 + 2, arr2, 16);
	Mymemmove(arr3, arr3+2, 16);
	return 0;
}

#if 0
void *Mymemcpy(void *dest, const void *src, int count)
{
	char *p = (char*)dest;
	while (count--)
	{
		*p = *(char*)src;		//类型强转，char大小一个字节
		p++;
		((char*)src)++;
	}
	return dest;
}



int main()
{
	int arr1[20] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6 };
	char str1[10] = { 0 };
	char str2[] = "abcdef";
	memcpy(str1, str2, 4);
	memcpy(arr1, arr2, 16);		//memcpy 的num参数单位是字节
	return 0;
}

/* isupper example */
#include <stdio.h> 
#include <ctype.h> 
int main () 
{ 
	int i=0; 
	char str[]="Test String.\n"; 
	char c; 
	while (str[i]) 
	{ 
		c=str[i]; 
		if (isupper(c))
			c = tolower(c);
		putchar (c); 
		i++; 
	} 
	return 0; 
} 
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main() 
{

	printf("%s\n", strerror(0));
	printf("%s\n", strerror(1));
	printf("%s\n", strerror(2));
	return 0;
}
#endif 

#if 0
	char str[] = "NameEmail@163.com";
	char *ret = strtok(str, ".@");
	while (ret != NULL)
	{
		printf("%s\n", ret);
		ret = strtok(NULL, ".@");
	}
	printf("%s\n", strtok(str, "@."));
	printf("%s\n", strtok(NULL, "@."));
	printf("%s\n", strtok(NULL, "@."));
	
	char *str1 = "abbbcdef ";
	char *str2 = "bbc";
	const char *p = Mystrstr(str1, str2);
	//str1主串  str2子串
	printf("%s\n", p);
const char *Mystrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char *s1 = str1;	
	const char *s2 = str2;
	const char *start = s1;
	while (*s1 != '\0')
	{
		s1 = start;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			++s1;
			++s2;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		if (*s2 == '\0')
		{
			return start;
		}
		start++;
	}
} 
const char *Mystrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 != '\0')
	{
		const char *ret = str1;
		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
		{
			++str1;
			++str2;
		}
		if (*str1 == '\0')
		{
			return NULL;
		}
		if (*str2 == '\0')
		{
			return ret;
		}
		str1++;
	}
} 

	char *str1 = "abcdef";
	char *str2 = "abcdf";
	printf("%d\n", Mystrncmp(str1, str2, 5));
int Mystrncmp(const char *str1, const char *str2, int n)
{
	int diff = 0;
	int count = 0;
	assert(str1 && str2);
	//相同&&count<n ++
	while (count < n && (diff = *str1 - *str2) == 0 && *str1 != '\0')
	{
		++str1;
		++str2;
		++count;
	}
	//不相同

	return diff;
}



printf("%d\n", strncmp(str1, str2, 4));
	printf("%d\n", strncmp(str1, str2, 5));
	printf("%d\n", strncmp(str1, str2, 6));	


char str[5] = "abcd";
	char *src = "hello";
	Mystrncat(str, src, 2);
	printf("%s\n", str);
char *Mystrncat(char* dest, const char* src, int n)
{
	char *p = dest;
	int count = 0;
	assert(dest && src);
	while ('\0' != *dest)
	{
		++dest;
	}
	while (count < n)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return p;
}

char *Mystrncpy(char *dest, const char *src, int n)
{
	assert(dest && src);
	char *p = dest;
	while (n--)
	{
		*dest = *src;
		++dest;
		++src;
	}
	return p;
}

int Mystrcmp(const char *str1, const char *str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		++str1;
		++str2;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
char dest[20] = "afgg";
	Mystrncpy(dest,"sssssssss", 2);
	printf("%s\n", dest);
char dest[20] = { 0 };
	char *src = "hello";
	strncpy(dest, src, 2);
	printf("%s\n", dest);

	//如果相同，str1和str2同时++;  同时为\0两个字符串相同
while ('\0' != *str1 && '\0' != *str2)
{
	if (*str1 != *str2)
		break;
	else
		return 0;
	++str1;
	++str2;
}
//不相同，求出胜负
if (*str1 == '\0')
return -1;
if (*str2 == '\0')
return 1;
#endif