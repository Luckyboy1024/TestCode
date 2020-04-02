
#include "test.h"


void menu()
{
	printf("\n");
	printf("********************\n");
	printf("*  1. Play   Game  *\n");
	printf("*  2. Game Script  *\n");
	printf("*  0. Exit   Game  *\n");
	printf("********************\n");
	printf("\n");
}

void test()
{
	int input = 0;
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			Script();
			break;
		default:
			printf("error!\r\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}