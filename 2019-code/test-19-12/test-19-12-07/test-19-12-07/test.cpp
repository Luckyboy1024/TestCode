#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <queue>
#include <cstdint>
using namespace std;

#define _G 2;		//参数 G

typedef struct ListNode{

}LN;


void input()
{
	uint64_t input_menu = 0;
	uint64_t input_choose = 0;
	cout << "*****************************" << endl;
	cout << "**  动态分区内存分配与回收 **" << endl;
	cout << "*****************************" << endl;
	do{
		cout << " 1. 内存分配" << endl;
		cout << " 2. 内存回收" << endl;
		cout << " 0. 退出程序" << endl;
		cout << "input :>_ ";
		cin >> input_menu;
		if (0 == input_menu)
		{
			// 退出;
		}
		else if (1 == input_menu)
		{
			do{
				cout << " 1. 首次适应算法" << endl;
				cout << " 2. 循环首次适应" << endl;
				cout << " 3. 最佳适应算法" << endl;
				cout << " 4. 最坏适应算法" << endl;
				cout << " 5. 查看动态分区" << endl;
				cout << " 0. 返回上一菜单" << endl;
				cout << "input :>_ ";
				cin >> input_choose;
				if (0 == input_choose)
				{
					// 返回上一菜单;
				}
				else if (1 == input_choose)
				{

				}
				else if (2 == input_choose)
				{

				}
				else if (3 == input_choose)
				{

				}
				else if (4 == input_choose)
				{

				}
				else if (5 == input_choose)
				{
					Print();
				}
			} while (input_choose);
		}
		else if (2 == input_menu)
		{

		}
	} while (input_menu);

}

void start()
{
	input();
}

int main()
{
	start();
	return 0;
}
