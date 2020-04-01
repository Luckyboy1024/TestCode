#define _CRT_SECURE_NO_WARNINGS 1

#if 0


#include <stdio.h>
#define ROW 10

void YHSJ(int arr[][ROW], int row, int col)
{
	int i = 0; 
	int j = 0;
	arr[0][0] = 1;
	for (i = 1; i < ROW; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}

void Print(int arr[][ROW], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = ROW; j>i; j--)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a[ROW][ROW] = {0};
	YHSJ(a, ROW, ROW);
	Print(a, ROW, ROW);
	return 0;
}



#include <stdio.h>
#include <string.h>

reverse_string(char* string)
{
	int str = strlen(string);
	//int a = str / 2;
	char tmp = *string;
	*string = *(string + str-1);
	*(string + str-1) = tmp;
	/*while (string)
	reverse_string(string);*/
}

int main()
{
	char arr[] = "abcdefg";
	reverse_string(&arr);
	printf("%s", arr);
	return 0;
}


#include <stdio.h>
#include <math.h>

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int sum = 0;
	for (i = 0; i < 32; i++)
	{
		sum += ((value >> i) & 1)*pow((double)2, 31 - i);
	}
	return sum;
}

int main()
{
	unsigned int ret = reverse_bit(25);
	printf("%u\n", ret);
	return 0;
}


#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a - ((a - b) >> 1);  //()括号，运算符的优先级
	printf("%d", c);
	return 0;
}

#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
//	int sum = ((a&b) << 1) + (a ^ b);
//	printf("%d\n", sum);
	int avg = ((a&b)) + (a ^ b) >> 1;
	printf("%d\n", avg);
	return 0;

}


#include <stdio.h>

int MyStrlen(const char *str)
{
	int count = 0;
	//assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void reverseStr(char* str)
{
	char* left = str;
	char* right = str + MyStrlen(str) - 1;
	char* cur = str;
	reverse(left, right);
	while (*cur != '\0')
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		reverse(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
}

int main()
{
	char str[] = "i am a student";
	reverseStr(str);
	printf("%s\n", str);
	return 0;
}	

#include <stdio.h>
#include <string.h>

int MyStrlen(const char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse(char* left, char* right)
{
	char tmp = *left;
	*left = *right;
	*right = tmp;
	left++;
	right--;
	while (left >= right)
	{
		return 0;
	}
	reverse(left, right);
}
reverse_string(char* string)
{
	char* left = string;
	char* right = string + MyStrlen(string) - 1;
	reverse(left, right);
}

int main()
{
	char arr[] = "abcdefg";
	reverse_string(arr);
	printf("%s", arr);
	return 0;
}

#include <stdio.h>

int main()
{
	int arr[] = { 1, 3, 2, 5, 5, 1, 7, 9, 3, 2 };
	int x = 0;
	int y = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int sum = 0;
	int pos = 0;
	for (i = 0; i < len; i++)
	{
		sum = sum ^ arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if ((sum >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x = x ^ arr[i];
		}
		else
		{
			y = y ^ arr[i];
		}
	}
	printf("%d\n%d\n", x, y);
	return 0;
}


#include <stdio.h>

int MyStrlen(char* str)
{
	static int count = 0;
	count++;
	str++;
	while (*str == '\0')
	{
		return count;
	}
	MyStrlen(str);
}

int main()
{
	int len = MyStrlen("abcdefg");
	printf("%d\n", len);
	return 0;
}


#include <stdio.h>

int fac(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n - 1);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fac(n);
	printf("%d\n", ret);
	return 0;
}


#include <stdio.h>

int main()
{
	int n = 0;
	int ret = 1;
	scanf("%d", &n);
	while (n != 1)
	{
		ret = ret*n;
		n--;
	}
	printf("%d\n", ret);
	return 0;
}


#include <stdio.h>

void Print(int num)
{
	while (num == 0)
	{
		return 0;
	}
	printf("%d", num % 10);
	Print(num / 10);
}

int main()
{
	int num = 1234567;
	Print(num);
	return 0;
}

#endif
