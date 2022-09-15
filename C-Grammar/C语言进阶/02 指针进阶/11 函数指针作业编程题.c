#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//题目名称：字符串左旋
//题目内容：实现一个函数，可以左旋字符串中的k个字符
//例如：ABCD左旋一个字符得到BCDA，ABCD左旋两个字符得到 CDAB

//void LeftRotate(char* str, int k)
//{
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *str;
//		char* move = str;
//		while (*(move + 1) != '\0')
//		{
//			*move = *(move + 1);
//			move++;
//		}
//		*move = tmp;
//	}
//}

//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void LeftRotate(char* str, int k)
//{
//	int length = strlen(str);
//	k %= length;
//	reverse(str, str + k - 1);
//	reverse(str + k, str + length - 1);
//	reverse(str, str + length - 1);
//}
//int main()
//{
//	char str[] = "ABCDEF";
//	int k = 2;
//	LeftRotate(str, k);
//	printf("%s\n", str);
//	return 0;
//}

//写一个函数，判断一个字符串是否是另一个字符串旋转之后的字符串
//例如：给定s1 = AABCD 和s2 = BCDAA，返回1
//给定 s1 = abcd 和 s2 = ACBD，返回0
//AABCD左旋两个字符得到BCDAA
//AABCD右旋两个字符得到CDAAB
int IsStringRotate(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	int sameCnt = 0;
	while (*str1 != '\0')
	{
		if (*str2 == '\0')
			str2 -= len2;
		if (*str1 == *str2)
		{
			sameCnt++;
			str1++;
			str2++;
		}
		else
		{
			sameCnt = 0;
			str2++;
		}
		if (sameCnt == len1)
			return 1;
	}
	return 0;
}

int main()
{
	int str1 = "ABCDEF";
	int str2 = "CDEFAB";
	int ret = IsStringRotate(str1, str2);
	if (ret == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}