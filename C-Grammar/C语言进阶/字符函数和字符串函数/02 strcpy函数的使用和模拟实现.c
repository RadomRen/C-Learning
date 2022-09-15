#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcpy函数的使用和模拟实现
char* my_strcpy(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1++ = *str2++);
	return ret;
}

//int main()
//{
//	char str1[20] = { 0 };
//	//str1 = "hello";//err
//	//strcpy(str1, "hello");
//	my_strcpy(str1, "hello");
//	printf("%s\n", str1);
//	return 0;
//}