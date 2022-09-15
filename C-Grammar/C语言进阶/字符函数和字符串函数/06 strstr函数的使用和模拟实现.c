#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//strstr的使用和模拟实现
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	if (*str2 == '\0')
	{
		return str1;
	}
	const char* pc1 = str1;
	const char* pc2 = str2;
	const char* ret = str1;
	while (*ret != '\0')
	{
		pc1 = ret;
		pc2 = str2;
		while (*pc1 && *pc1 == *pc2)
		{
			pc1++;
			pc2++;
		}
		if (*pc2 == '\0')
			return (char*)ret;
		ret++;
	}
	return NULL;
}

//int main()
//{
//	char str1[] = "abcefabcdef";
//	char str2[] = "abcdef";
//	//char* ret = strstr(str1, str2);
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("str2不在str1中");
//	}
//	else
//	{
//		printf("找到str2：%s", ret);
//	}
//	return 0;
//}