#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//fputc�������ַ�д�ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//д�ļ�
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fput�����������Ļ
//int main()
//{
//	fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);
//	return 0;
//}

////fgetc���ļ��а��ַ���������
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//���ļ�
//	int ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fgetc�Ӽ��̶�������
//int main()
//{
//	int ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//
//	return 0;
//}
//
////fputs���ļ���д�ַ���
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//д�ļ�
//	fputs("abcdefg\n", pf);
//	fputs("qwertyu\n", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fgets���ļ������ַ���
////�����и������ַ���������'\0'
//int main()
//{
//	char arr[10] = { 0 };
//	//���ļ�
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//���ļ�
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	char arr[10];
//	int num;
//	float sc;
//};
////fscanf��ʽ��д�ļ�
//int main()
//{
//	struct S s = { "abcdef", 10, 5.5f };
//	//�Ը�ʽ�������ݽ���д�ļ�
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//д�ļ�
//	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fscanf��ʽ�����ļ�
//int main()
//{
//	struct S s = {0};
//	//�Ը�ʽ�������ݽ���д�ļ�
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//���ļ�
//	fscanf(pf, "%s %d %f", s.arr, &(s.num), &(s.sc));
//	//��ӡ
//	printf("%s %d %f", s.arr, s.num, s.sc);
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�����ƵĶ�д
//struct S
//{
//	char arr[10];
//	int num;
//	float sc;
//};
////������д�ļ�
//int main()
//{
//	struct S s = { "abcdef", 10, 5.5f };
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//������д�ļ�
//	fwrite(&s, sizeof(struct S), 1, pf);
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////�����ƶ��ļ�
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�����ƶ��ļ�
//	fread(&s, sizeof(struct S), 1, pf);
//	//��ӡ
//	printf("%s %d %f", s.arr, s.num, s.sc);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////sprintf ����ʽ��������ת��Ϊ�ַ���
////sscanf  ���ַ�������ת��Ϊ��ʽ������
//struct S
//{
//	char arr[10];
//	int num;
//	float f;
//};
//int main()
//{
//	struct S s = { "abcdef", 10, 5.5f };
//	struct S tmp = { 0 };
//	char arr[100] = { 0 };
//	//sprintf ����ʽ��������ת��Ϊ�ַ���
//	sprintf(arr, "%s %d %f", s.arr, s.num, s.f);
//	printf("%s\n", arr);
//	//sscanf  ���ַ�������ת��Ϊ��ʽ������(�ṹ�壩
//	sscanf(arr, "%s %d %f", tmp.arr, &(tmp.num), &(tmp.f));
//	printf("%s %d %f\n", tmp.arr, tmp.num, tmp.f);
//	return 0;
//}