#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __PIPE_H__
#define __PIPE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#endif // __PIPE_H__
int main()
{
	int fds[2];
	char buf[100];
	int len;

	if (-1 == pipe(fds))
	{
		perror("make pipe"), exit(1);
	}
	while (fgets(buf, 100, stdin))
	{
		len = strlen(buf);
		// write into pipe
		if (write(fds[1], buf, len) != len)
		{
			perror("write to pipe");
			break;
		}
		memset(buf, 0x00, sizeof(buf));

		//read from pipe
		if (-1 == (len = read(fds[0], buf, 100)))
		{
			perror("read from pipe");
			break;
		}

		//write into stdout
		if (write(1, buf, len) != len)
		{
			perror("write to stdout");
			break;
		}
	}
	return 0;
}
