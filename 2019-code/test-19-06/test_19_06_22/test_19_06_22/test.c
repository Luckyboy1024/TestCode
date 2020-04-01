#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>




#if 0

struct Stu
{
	char name[20];		//名字
	int age;			//年龄
	char sex[5];		//性别		//由于输入的是汉字，这里要声明为数组[]
	char id[15];		//学号
};


int main()
{
	struct Stu s = { "张三", 20, "男" };		//注意：这里汉字用“”，‘’会报错
	printf("name: %s age: %d sex: %s\n", s.name, s.age, s.sex);
	//定义一个结构体类型的指针
	struct Stu* ps = &s;		//ps是个指针变量，ps指向s，把s的地址放在了ps里面
	printf("name: %s age: %d sex: %s\n", (*ps).name, (*ps).age, (*ps).sex);
	printf("name: %s age: %d sex: %s\n", ps->name, ps->age, ps->sex);	//ps
	return 0;
}

int main()
{
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(long long*));

	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));
	return 0;
}


int main()
{
	printf("换行符\\n");
	return 0;
}

int main()
{
	//定义一个char类型的指针变量
	
	char ch = "w";		//定义一个char型的变量
	char* pc = &ch;		//pc指向ch，pc为char类型的指针变量
	*pc = 'a';			//将ch的值改为a
	printf("%c\n", ch);
	return 0;
}


int main()
{
	int a = 10;
	int* p = &a;
	printf("%d\n", a);
	*p = 20;	//把20赋值给*p,	
	printf("%d\n", a);	//如果 a 的值变为20，那么证明*p就是a
	return 0;
}


#define SQUARE(X) X*X
int main()
{
	printf("%d\n", SQUARE(9));		//等同于printf("%d\n", 3*3); 替换得十分彻底
	return 0;
}


#define M 100		//注意，不加分号

int main()
{
	int a = M;
	printf("%d\n", a);
	return 0;
}


#endif