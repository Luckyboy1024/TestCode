#define _CRT_SECURE_NO_WARNINGS 1

// 空闲分区表
// 每个分区占一个表目，包含分区序号、分区始址、分区大小

typedef struct FPT{
	int _NUM;		// 表目
	int _num;		// 分区号
	struct FPT* _add;// 分区始址
	int _size;		// 分区大小
}FPT;


