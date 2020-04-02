#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>                                                                         
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.:h>
#include <sys/stat.h>
int main()
{
	umask(0);   // 设置文件的创建权限掩码
	int fd = open("./test.txt", O_RDWR | O_CREAT, 777);
	if (fd < 0)	
	{
		perror("open error");
		return -1;
	}
	char *ptr = "我想你了~~~~\n";
	int ret = write(fd, ptr, strlen(ptr));
	if (ret < 0){
		perror("write error");
		return -1;
	}
	printf("write len: %d\n", ret);

	//在读取数据之前将文件的读写位置跳转到文件的起始位置
	lseek(fd, 0, SEEK_SET);
	char buf[1024] = { 0 };
	ret = read(fd, buf, sizeof(buf)-1);
    if (ret < 0){    //读取数据出错
        perror("read error");
        return -1;
	}
	else if (0 == ret)  //读取数据到达文件末尾
    {
		printf("at end of file\n");
		return -1;
	}
    else{
		printf("read buf : [%s] - [%d]\n", buf, ret);
	}
    close(fd);  // 关闭文件，释放资源
    return 0;
}
