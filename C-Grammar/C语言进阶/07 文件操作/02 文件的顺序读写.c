#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//fputc函数按字符写文件
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//写文件
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fput函数输出到屏幕
//int main()
//{
//	fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);
//	return 0;
//}

////fgetc从文件中按字符读入数据
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//读文件
//	int ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fgetc从键盘读入数据
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
////fputs向文件中写字符串
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//写文件
//	fputs("abcdefg\n", pf);
//	fputs("qwertyu\n", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fgets从文件读入字符串
////参数中给定的字符个数包含'\0'
//int main()
//{
//	char arr[10] = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//读文件
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//
//	//关闭文件
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
////fscanf格式化写文件
//int main()
//{
//	struct S s = { "abcdef", 10, 5.5f };
//	//对格式化的数据进行写文件
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//写文件
//	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////fscanf格式化读文件
//int main()
//{
//	struct S s = {0};
//	//对格式化的数据进行写文件
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	//读文件
//	fscanf(pf, "%s %d %f", s.arr, &(s.num), &(s.sc));
//	//打印
//	printf("%s %d %f", s.arr, s.num, s.sc);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//二进制的读写
//struct S
//{
//	char arr[10];
//	int num;
//	float sc;
//};
////二进制写文件
//int main()
//{
//	struct S s = { "abcdef", 10, 5.5f };
//	FILE* pf = fopen("test.bat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////二进制读文件
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.bat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制读文件
//	fread(&s, sizeof(struct S), 1, pf);
//	//打印
//	printf("%s %d %f", s.arr, s.num, s.sc);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////sprintf 将格式化的数据转换为字符串
////sscanf  将字符串数据转换为格式化数据
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
//	//sprintf 将格式化的数据转换为字符串
//	sprintf(arr, "%s %d %f", s.arr, s.num, s.f);
//	printf("%s\n", arr);
//	//sscanf  将字符串数据转换为格式化数据(结构体）
//	sscanf(arr, "%s %d %f", tmp.arr, &(tmp.num), &(tmp.f));
//	printf("%s %d %f\n", tmp.arr, tmp.num, tmp.f);
//	return 0;
//}