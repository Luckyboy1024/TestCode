#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#if 0

void* Mymemmove(void* dest, const void* src, int count)
{
	//assert();
	void* ret = src;
//	char* p = dest < src ? dest : src;
	if (dest < src)
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			((char *)dest)++;
			((char *)src)++;
		}
	}
	else 
	{
		char *p = dest;
		char *l = src;
		while (*p != '\0')
		{
			while (*l != '\0')
			{
				l++;
			}
			p++;
		}
		while (count--)
		{
			*(char *)p = *(char *)l;
			((char *)dest)--;
			((char *)src)--;
		}
	}
	return ret;
}


int main()
{
	char arr[10] = { 1,2,3,4,5,6 };

	return 0;
}

int is_left_move()
{

}

int main()
{
	char arr = "abcd";
	char str = "bcda";
	int n = is_left_move(arr, str);
	return 0;
}

void Swap(const char* left, const char* right)
{
	char* le = left;
	char* ri = right;
	while (le < ri)
	{
		char tmp = *le;
		*le = *ri;
		*ri = tmp;
		le++;
		ri--;
	}
}

void left_move(const char *str, int k)
{
	char* p = str;
	char* n = str;				//n指向首
	char* l = str + k - 1;			//l指向中间
	while (*(p + 1) != '\0')
	{
		p++;				//p指向末尾
	}
	Swap(n, l);
	Swap(l + 1, p);
	Swap(n, p);
}

int is_left_move(char* str, const char* p)
{
	int n = 1;
	while (*p != '\0')
	{
		n++;
	}
	while (n)
	{
		left_move(*str, 1);
		while (*p != '\0')
		{
			if (*str == *p)
			{
				while (*str != '\0')
				{
					str++;
					p++;
				}
				return 1;
			}
		}
		n--;
	}
	return 0;
}

int main()
{
	char str1[] = "abcdefg";
	char str2[] = "cdefgab";
	int n = is_left_move(str1, str2);
	printf("return %d\n", n);
	return 0;
}

#endif