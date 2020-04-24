#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>



// 分区分配
 // 设请求的分区大小：u.size

 // 设空闲的分区大小：m.size

 // 不可再分割的剩余分区大小：size

 // 如果 m.size - u.size <= size 将整个分区分配给请求者，否则剩余部分留在空闲分区链(表)中。

 // 将分区的首地址返回给调用者





// 分区回收
// 内存回收时的三种情况



