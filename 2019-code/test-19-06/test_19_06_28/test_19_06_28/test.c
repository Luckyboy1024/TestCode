#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#if 0
void CopyMp4(char* destPath, const char* srcPath)
{
	FILE *rf = fopen(srcPath, "rb");

	FILE *wf = fopen(destPath, "wb");
	char ch;
	assert(destPath);
	assert(srcPath);
	while (fread(&ch, sizeof(char), 1, rf) > 0)
	{
		fwrite(&ch, sizeof(char), 1, wf);
	}
	fclose(rf);
	fclose(wf);
	rf = NULL;
	wf = NULL;
}
int main()
{  
	char *srcPath = "D:\Classcode\Test_study\C_day_test\Picture_video\001txt";
	char *destPath = "F:\\";
	CopyMp4(destPath, srcPath);
	return 0;
}


//ÎÄ¼þ²Ù×÷
int main()
{
	char ch = NULL;
	int *pf = fopen("test.txt", "w");
	fgetc('b');
	fgetc('b');
	fgetc('b');
	while ((ch = fget(pf)) != EOF);
	printf("ch");
	fclose("test.txt");
	return 0;
}


int main()
{
	char arr1[] = "hello bit";
	char arr2[] = "hi bit";
	
	return 0;
}


#endif