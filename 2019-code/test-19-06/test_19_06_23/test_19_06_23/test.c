#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>



#if 0
int main()
{
	int i = 0;
//	for (初始化; 判断部分; 调整部分)
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}

int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
			continue;
		putchar(ch);
	}
	return 0;
}


//代码什么意思？
//代码1
#include <stdio.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
//代码2
#include <stdio.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
			continue;
		putchar(ch);
	}
	return 0;
}


int main()
{
	int i = 1;
	while (i++<=10)
	{
		if (5 == i)
			continue;
		printf("%d  ", i);
	}
	return 0;
}


#include <stdio.h>
int main()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;            //3=2+1
	case 2:
		n++;             //2=1+1
	case 3:
		switch (n)      //此时n==2   m==3 
		{//switch允许嵌套使用
		case 1:
			n++;        //这条语句不被执行
		case 2:
			m++;        //m==4
			n++;        //n==3
			break;
		}
	case 4:
		m++;                //m==5
		break;              //break跳出
	default:
		break;
	}
	printf("m = %d, n = %d\n", m, n);      //5  3
 	return 0;
}



int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}
	return 0;
}

int main()
{
	int day = 0;
	scanf("%d", &day);
	if (1 == day)
	{
		printf("星期一\n");
	}
	else if (2 == day)
	{
		printf("星期二\n");
	}
	else if (3 == day)
	{
		printf("星期三\n");
	}
	else if (4 == day)
	{
		printf("星期四\n");
	}
	else if (5 == day)
	{
		printf("星期五\n");
	}
	else if (6 == day)
	{
		printf("星期六\n");
	}
	else if (7 == day)
	{
		printf("星期日\n");
	}
	return 0;
}




int main()
{
	int i = 0;
	for (i = 0; i <= 100; i+=2)
	{
		if (1 == i % 2)
		{
			printf("%d ", i);
		}
	}
	return 0;
}


int main()
{
	int a = 3;
	if (a = 10)
	{
		printf("hehe\n");
	}
	return 0;
}

//代码1
if (condition)
	return x;
return y;

//代码2
if (condition)
{
	return x;
}
else


int main()
{
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
		printf("haha\n");
	return 0;
}


int main()
{
	int a = 3;
	int age = 0;
	scanf("%d", &age);
	if (age < 18)
	{
		printf("少年\n");
	}
	else if (18 <= age && age <= 30)
	{
		printf("青年\n");
	}
	else if (30 < age && age < 50)
	{
		printf("中年\n");
	}
	else if (50 <= age && age < 80)
	{
		printf("老年\n");
	}
	else
	{
		printf("老不死\n");
	}
		return 0;
}


int main()
{
	printf("hehe");
	1 + 2;
	return 0;
}

#endif