#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("+---------------------+\n");
	printf("+-     1.  play      -+\n");
	printf("+-     0.  exit      -+\n");
	printf("+---------------------+\n");
	printf("please input your choose:>_ ");
}


void game()
{
	char re_board[re_row][re_col] = { 0 };			//����һ�����飬���������Ϣ
	char print_board[re_row][re_col] = { 0 };		//����һ���������ڴ�ӡ

	//��ʼ��
	Init_board(re_board, re_row, re_col, '0');		//����Ԫ��ȫ��ʼ��Ϊ0�����������Ȧ	
	Init_board(print_board, re_row, re_col, '#');	//����Ԫ��ȫ��ʼ��Ϊ#

	//������
	Set_mine(re_board, ROW, COL);
	//re_board[3][3] = '1';
	//print_board[3][3] = '*';
	//show_board(re_board, ROW, COL);
	show_board(print_board, ROW, COL);

	//�Ų���
	//��һ������
	if (1 == First_tip(re_board, print_board, ROW, COL))
	{
		return 0;
	}
	Sweep_mine(re_board, print_board, re_row, re_col);
}

int test_choose()
{
	int input = 0;
	scanf("%d", &input);
	while ('\n' != getchar());
	switch (input)
	{
	case 1:
		system("cls");
		game();
		break;
	case 0:
		printf("�˳�����\n");
		return input;
	default:
		printf("\ninput error!	Enter again\n\n");
		break;
	}
	return 1;
}


int main()
{
	do
	{
		system("cls");
		menu();
		srand((unsigned int)time(NULL));
	} while (test_choose() != 0);
	return 0;
}




