#define _CRT_SECURE_NO_WARNINGS 1

#if 0

�������ƣ�
�����ĸ���Ŀ��
����汾�ţ�
���򿪷�С�����
�����㷨�ṩ�ˣ�
��������ͼ�ṩ�ˣ�
��������д�ˣ�
�������Ա��
��Ŀ�����ˣ�

#endif


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


#define ROW 9
#define COL 9
#define Mine 2

#define re_row ROW+2
#define re_col COL+2

int test_choose();
void menu();
void game();

void show_board(char arr[re_row][re_col], int row, int col);
void show_died(char arr[re_row][re_col], int row, int col);				  //��ӡ��ǰ����
void Init_board(char board[re_row][re_col], int row, int col, char set);		//��ʼ��
void Set_mine(char board[re_row][re_col], int row, int col);					//������

char Count_nearby(char board[re_row][re_col], int row, int col, int x, int y);
void Nearby_Is_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col, int x, int y);
int First_tip(char board[re_row][re_col], char arr[re_row][re_col], int row, int col);
int Sweep_mine(char board[re_row][re_col], char arr[re_row][re_col], int row, int col);
int Game_end(char arr[re_row][re_col], char board[re_row][re_col], int row, int col);

int Tag_mine(char arr[re_row][re_col]);

void Tag_Color(char arr[re_row][re_col], int  x, int  y);