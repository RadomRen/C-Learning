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
	//���ļ�
	int ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, -1, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}