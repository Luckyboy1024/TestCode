#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#if 0
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};

int main()
{
	//下面输出的结果是什么？
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	return 0;
}
union Un
{
	int i;
	char c;
};

int main()
{
	union Un un;
	//下面输出的结果是什么？
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	return 0;
}
//#define offsetof(s,m) (size_t)&(((s*)0)->m)
#include <stdio.h>
#include <stddef.h>
struct Stu
{
	int i;
	short ch;
};

int main()
{
	printf("%d\n", (size_t)&(((struct Stu*)0)->ch));
	printf("%d\n", offsetof(struct Stu, ch));
 	return 0;
}

#pragma pack(4)//设置默认对齐数为4
//练习3
struct S3
{
	double d;        //8  8  8  0~7
	char c;          //1  8  1   8
	int i;           //4  8  4  12~15
	char ch[6];      //1  8  1  但数组有6个元素，偏移量16~21
};                 //0~21共22个字节，最大对齐数8
//#pragma pack()//取消设置的默认对齐数，还原为默认

struct S4
{
	char c1;        //1  8  1   1
	struct S3 s3;   //24 8  8   8~31 因为S3最大对齐数是8
	double d;       //8  8  8   32~39
};            //0~39共40个字节，最大对齐数24
#pragma pack()//取消设置的默认对齐数，还原为默认

int main()
{
	printf("%d\n", sizeof(struct S4));    //48
	return 0;
}

typedef struct Student
{
	char name[20];//名字
	int age;//年龄
	char sex[5];//性别
	char id[20];//学号
}STU;

STU stu1 = {};


#endif

