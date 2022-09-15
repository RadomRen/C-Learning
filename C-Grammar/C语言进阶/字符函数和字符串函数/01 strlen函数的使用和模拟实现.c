#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen函数的使用和实现
//版本1：计数器版本
//int my_strlen(const char* str)
//{
//	assert(str);
//	int cnt = 0;//计数器
//	while (*str++ != '\0')
//		cnt++;
//	return cnt;
//}

//版本2：递归
//int my_strlen(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return my_strlen(++str) + 1;
//}

//版本3：指针 - 指针
int my_strlen(const char* str)
{
	assert(str);
	char* pc = str;
	while (*++pc != '\0');
	return pc - str;
}

//int main()
//{
//	char arr[] = "abc";
//	//int len = strlen(arr);
//	int len = my_strlen(arr);
//	printf("%d\n", len);//3
//	return 0;
//}

//strlen 函数的返回值是无符号数size_t == unsigned int
//int main()
//{
//	if (strlen("abc") > strlen("abcdef"))
//	{
//		printf(">\n");//V
//	}
//	else
//	{
//		pritnf("<=\n");
//	}
//}