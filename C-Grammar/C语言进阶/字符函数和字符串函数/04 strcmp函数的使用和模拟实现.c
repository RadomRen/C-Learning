#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcmp函数的使用和模拟实现
int my_strcmp(char* str1, char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

//int main()
//{
//	char* str1 = "abcd";
//	char* str2 = "abcf";
//	//int ret = strcmp(str1, str2);
//	int ret = my_strcmp(str1, str2);
//	if (ret > 0)
//	{
//		printf(">\n");
//	}
//	else if (ret == 0)
//	{
//		printf("==\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}