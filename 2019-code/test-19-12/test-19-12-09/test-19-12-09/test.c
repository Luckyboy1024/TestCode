#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	if (!(status & 0x7f))
	{
		printf("%d\n", (status >> 8) & 0xff);
	}
	return 0;
}

#if 0


#endif