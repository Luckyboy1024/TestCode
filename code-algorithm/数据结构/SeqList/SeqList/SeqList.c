#include "SeqList.h"



//初始化
void SeqListInit(SeqList* sl)
{
	assert(sl);
	sl->_array = NULL;
	sl->_capacity = sl->_size = 0;
}

//销毁 释放空间
void SeqListDestory(SeqList* sl)
{
	if (sl->_array)
	{
		free(sl->_array);
		sl->_array = NULL;
		sl->_capacity = sl->_size = 0;
	}
}

//检查容量
void SeqListCheckCapacity(SeqList* sl)
{
	assert(sl);
	if (sl->_capacity == sl->_size)
	{
		size_t newCapacity = (0 == sl->_capacity ? 5 : 2 * sl->_capacity);
		//sl->_array = (DataType*)malloc(sl->_array);
		sl->_array = (DataType*)realloc(sl->_array, newCapacity*sizeof(DataType));
		assert(sl->_array);				//断言，申请失败，系统崩溃
		sl->_capacity = newCapacity;	//更新容量
	}
}


//尾插
void SeqListPushBack(SeqList* sl, DataType x)
{
	assert(sl);
	SeqListCheckCapacity(sl);
	sl->_array[sl->_size] = x;
	++sl->_size;
}

//头插
void SeqListPushFront(SeqList* sl, DataType x)
{

}

//任意位置插入
void SeqListInsert(SeqList* sl, size_t pos, DataType x)
{

}

//尾删
void SeqListPopBack(SeqList* sl)
{
	assert(sl);
	if (sl->_size > 0)
	{
		--sl->_size;
	}
}

//头删
void SeqListPopFront(SeqList* sl)
{

}

//删除当前 (pos) 位置数据
void SeqListErase(SeqList* sl, size_t pos)
{

}


//查找
size_t SeqListFind(SeqList* sl, DataType x);

//更改
size_t SeqListModify(SeqList* sl, size_t pos, DataType x);


//打印
void SeqListPrint(SeqList* sl)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_array[i]);
	}
}

//计算元素个数
size_t SeqListSize(SeqList* sl)
{

}


//返回当前位置的值
DataType SeqListAt(SeqList* sl, size_t pos)
{

}




