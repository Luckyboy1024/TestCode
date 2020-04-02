#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

int main()
{
	int i = 0;
	return 0;
}



#if 0
void Move(int n, char p1, char p2)	//棋子 n，移动起始位置p1，最终位置p2
{
	static int count = 1;
	printf("第 %d 步%d : %c --> %c\n", count, n, p1, p2);
	count++;
}

//p1当前位置  p2过度位置  p3结束位置  
void Hanota(int n, char p1, char p2, char p3)
{
	if (n == 1)
	{
		Move(n, p1, p3);
		return;
	}
	
	//n >= 2;
	else
	{
		//(n-1)  A --> B
		Hanota(n - 1, p1, p3, p2);

		//n  A --> C
		Move(n, p1, p3);

		//(n-1) B --> C
		Hanota(n - 1, p2, p1, p3);
	}
}

int main()
{
	//char p1 = 'A';
	//char p2 = 'B';
	//char p2 = 'C';

	Hanota(1, 'A', 'B', 'C');
	printf("\n");
	Hanota(2, 'A', 'B', 'C');
	printf("\n");
	Hanota(3, 'A', 'B', 'C');
	printf("\n");
	Hanota(4, 'A', 'B', 'C');
	printf("\n");
	return 0;
}


int Jump_Floor(int n)
{
	static int totle = 1;
	//if(0 == n)
	//{
	//	return ;
	//}
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return totle += Jump_Floor(n - 1);
	}
}

int main()
{
	printf("%d\n", Jump_Floor(3));

	return 0;
}

int main()
{
	char *str = (char)malloc(char *);
	free(str);
	return 0;
}

#endif