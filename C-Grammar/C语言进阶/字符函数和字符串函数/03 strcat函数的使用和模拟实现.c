#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcat函数的使用和模拟实现
char* my_strcat(char* str1, const char* str2)
{
	char* ret = str1;
	assert(str1 && str2);
	str1 += strlen(str1);
	while (*str1++ = *str2++);
	return ret;
}
//int main()
//{
//	char arr1[20] = "hello ";//world
//	char* arr2 = "world";
//	//strcat(arr1, arr2);
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}