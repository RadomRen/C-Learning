#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen������ʹ�ú�ʵ��
//�汾1���������汾
//int my_strlen(const char* str)
//{
//	assert(str);
//	int cnt = 0;//������
//	while (*str++ != '\0')
//		cnt++;
//	return cnt;
//}

//�汾2���ݹ�
//int my_strlen(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return my_strlen(++str) + 1;
//}

//�汾3��ָ�� - ָ��
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

//strlen �����ķ���ֵ���޷�����size_t == unsigned int
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