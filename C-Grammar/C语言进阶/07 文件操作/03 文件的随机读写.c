#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读文件
	int ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, -1, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}