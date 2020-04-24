#define _CRT_SECURE_NO_WARNINGS 1

short Add(short left, short right)
{
	return left + right;
}

int Add(short left, short right)
{
	return left + right;
}

//
//int Add(int a, int b);
//
//int main()
//{
//	Add(1, 2);
//	return 0;
//}

int Add(int a, int b);
double Add(double a, double b);

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
