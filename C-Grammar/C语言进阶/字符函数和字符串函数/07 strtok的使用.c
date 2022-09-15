#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* strtok(char* str, const char* sep);
//使用sep中的字符分割str字符串
//int main()
//{
//	char str[30] = "RadomRen@gmail.com hehe";
//	char tmp[30] = {0};
//	strcpy(tmp, str);
//	char* sep = "@. ";
//	char* ret = NULL;
//	for (ret = strtok(tmp, sep); ret != NULL; ret = strtok(NULL, sep))
//	{
//		printf("%s\n", ret);
//	}
//	printf("%s\n", str);
//	return 0;
//}