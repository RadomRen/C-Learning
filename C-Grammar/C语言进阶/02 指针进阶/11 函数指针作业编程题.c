#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//��Ŀ���ƣ��ַ�������
//��Ŀ���ݣ�ʵ��һ�����������������ַ����е�k���ַ�
//���磺ABCD����һ���ַ��õ�BCDA��ABCD���������ַ��õ� CDAB

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

//дһ���������ж�һ���ַ����Ƿ�����һ���ַ�����ת֮����ַ���
//���磺����s1 = AABCD ��s2 = BCDAA������1
//���� s1 = abcd �� s2 = ACBD������0
//AABCD���������ַ��õ�BCDAA
//AABCD���������ַ��õ�CDAAB
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