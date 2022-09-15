#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

////strncpy
//int main()
//{
//	char str1[20] = "hello ";
//	char str2[] = "qwer";
//	//strncpy(str1, str2, 2);//qwllo
//	strncpy(str1, str2, 6);//qwer
//	printf("%s\n", str1);
//	return 0;
//}

////strncat
//int main()
//{
//	char str1[20] = "hello ";
//	char str2[] = "qwer";
//	//strncat(str1, str2, 2);//hello qw
//	strncat(str1, str2, 6);//hello qwer
//	printf("%s\n", str1);
//	return 0;
//}



////strncmp
//int main()
//{
//	char str1[20] = "abcde";
//	char str2[] = "abce";
//	int ret = strncmp(str1, str2, 3);
//	if (ret > 0)
//	{
//		printf("str1 > str2\n");
//	}
//	else if (ret == 0)
//	{
//		printf("str1 == str2\n");
//	}
//	else
//	{
//		printf("str1 < str2\n");
//	}
//	return 0;
//}