#define _CRT_SECURE_NO_WARNINGS 1

// 空闲分区链
// 在每一个分区的起始部分设置用于控制分区的信息、向前指针，在分区尾部设置一个向后指针，形成双向链表。

typedef struct FPC{
	struct FPC* _front;		// 向前指针
	int data_size;			// 空间大小
	struct FPC* _back;		// 向后指针
}FPC;