#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	return 0;
}

#if 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t id = fork();
	if(id < 0){
		perror("fork");
		return 1;
	}
	else if(id == 0){//child
		printf("I am child, pid : %d\n", getpid());
		sleep(10);
	}else{//parent
		printf("I am parent, pid: %d\n", getpid());
		sleep(3);
		exit(0);
	}
	return 0;
}

int main()
{
	pid_t id = fork();
	if (id < 0)
	{
		perror("fork"); return 1;
	}
	else if (id > 0)
	{
		//parent printf("parent[%d] is sleeping...\n", getpid());
		sleep(30);
	}
	else
	{
		printf("child[%d] is begin Z...\n", getpid());
		sleep(5); exit(EXIT_SUCCESS);
	}
	return 0;
}

#endif
