#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"



void * __cdecl memcpy(
	void * dst,
	const void * src,
	size_t count
	)
{
	void * ret = dst;

	/*
	* copy from lower addresses to higher addresses
	*/
	while (count--) {
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}

	return(ret);
}

int main()
{
	char str1[] = "aaaaaaaa";
	char str2 = "bbbbbbfg";
	memcpy(str2+2, str2, 16);
	return 0;
}


#if 0

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
	char* l = str + k - 1;		//l指向中间
 	while (*(p+1) != '\0')
	{
		p++;					//p指向末尾
	} 
	Swap(n, l);
	Swap(l+1, p);
	Swap(n, p);
}

int main()
{
	char str[] = "abcdefg";
	left_move(str, 2);
	printf("%s\n", str);
	return 0;
}



void is_Find(int arr[3][3], int* px, int* py, int key)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y > 0)
	{
	}
	while ()
	{

	}
}


int main()
{
	//int arr[2][3] = { { 1, 3, 4 }, { 2, 4, 5 } };
	int arr[3][3] = { { 1, 3, 4 }, { 2, 4, 5 }, { 4, 5, 6 } };
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int find = 1;
	/*int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);
	*/
	int *row = arr[0];
	int *col = arr;
	
	is_Find(arr, *row, *col, find);
	//printf("%d  %d", row, col);
	return 0;
}



void Function(int *left, int *right)
{
	while ((*left & 1) == 1)
	{
		left++;
	}

	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		Function(left, right);
	}
}

void show(int *arr, int len)
{
	while (len--)
	{
		printf("%d ", arr[len]);
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 12, 23, 5, 67, 51, 64 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Function(arr, arr + len - 1);
	show(arr, len);
	return 0;
}

int Find_it(char *arr, int row, int col, int sz)
{
	while (sz--)
	{
		if (arr[][] == find)
		{
			printf("Find it");
			break;
		}
	}
}

int main()
{
	int arr[3][3] = { { 1, 3, 4 }, { 2, 4, 5 }, { 4, 5, 6 } };
//	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
//	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int find = 1;
	int sz = sizeof(arr) / sizeof(arr[0][0]);
	
	return 0;
}

void yuoxuan(char *str, int n)
{
	int len = 0;
	char *crs = str;
	char *p ;
	while (*(crs+1) != '\0')
	{
		len++;
		*crs++;
	}
	p = crs;
	while ((n--)%len)
	{
		int l = len;
		char temp = *crs;
		while (l--)
		{
			*crs = *(crs - 1);
			*crs--;
		}
		*crs = temp;
		//*(p + 1) = '\0';
		crs = p;
	}
}

int main()
{
	int i = 13;

	char str[10] = "abcdef";

	yuoxuan(str,i);
	printf("%s\n", str);
	return 0;
}

void zuoxuan(char *str, int n)
{
	while (n--)
	{
		char *crs = str;
		char temp = *str;
		while (*(crs+1) != '\0')
		{
			*crs = *(crs + 1);
			*crs++;
		}
		*crs = temp;
	}
}

int main()
{
	int i = 1;
	char str[10] = "abcdef";
	
	zuoxuan(str,i);
	printf("%s\n", str);
	return 0;
}



char *MyStrcpy(char* dest, const char* src)
{
	char *p = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return p;
}

int main()
{
	char str[20] = "abcs";
	char str1 = "abcd";
	MyStrcpy(str, str1);
	return 0;
}

int Add()
{

}

int Max()
{

}

int main()
{
	int x = 0;
	int y = 0;
	int(*p[2])(int x, int y) = { Add, Max };
	return 0;
}

int bijiao(char *str1, char *str2)
{
	if ()
		return 0;
	if ()
		return 1;
}

int main()
{
	char s1 = "aabcd";
	char s2 = "bcdaa";
	zuoxuan(s1);

	if(bijiao(str1, str2) == 1)
		;
	if (bijiao(str1, str2) == 0)
		;
	return 0;
}

int main()
{
	char str[10] = "abcdef";
	//str[1] = "h";	//双引号会出现问题--h会一次性占用bc的位置，打印出乱码;
	str[1] = 'h'; //等同于 *(str + 1) = 'h';
	printf("%s\n", str); //ahcdef ?  NO !
	return 0;
}


int main()
{
	char *str = "abcdef";
	*(str + 1) = "h";
	printf("%s\n", str); //ahcdef ?  NO !
	return 0;
}


int main()
{
	char *str = "abcdef";
	char *str2 = "ab";
	strcpy(str, str2);
	printf("%s\n", str);
	return 0;
}




int main()
{
	char str[10] = "abcds";
	char *str2 = "hello boy";
	//strcpy(str, str2);
	MyStrcpy(str, str2);
	printf("%s\n", str);
	return 0;
}

int main()
{
	int a = 10;
	assert(a != 10);	//断言 a 等于10
	return 0;
}

#endif
