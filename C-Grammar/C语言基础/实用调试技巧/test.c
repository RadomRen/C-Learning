#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//ģ��ʵ��strcpy����
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(src != NULL);
	assert(dest != NULL);
	//assert(strlen(dest) >= strlen(src));
	while (*dest++ = *src++);
	return ret;
}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";
//	char arr2[] = "hello";
//	char* arr3 = my_strcpy(arr1, arr2);//1 - Ŀ��ռ���׵�ַ  2 - Դ�ռ���׵�ַ
//	//strcpy(arr1, arr2);
//	printf("arr1 = %s\n", arr1);
//	printf("arr3 = %s\n", arr3);
//}

////const���ܽ���
//int main()
//{
//	////1.��������£�num���Ա��޸�
//	//int num = 10;
//	//num = 20;
//	//printf("num = %d", num);
//
//	////2.��num����const֮��num�����޸�
//	//const int num = 10;
//	////num = 20;//num���ܱ�ֱ���޸�
//	////���ǿ���ͨ��ָ��num��ָ���޸�num��ֵ
//	//int* p = &num;
//	//*p = 20;
//	//printf("num = %d", num);
//
//	////3.Ҫ��num���ܱ�ֱ���޸ģ���Ҳ���ܱ�ͨ����ָ���޸�
//	////const int num = 10;
//	//int num = 10;
//	//const int* p = &num;
//	////*p = 20;//��ָ��num��ָ��ǰ�����constʱ������ͨ��ָ���޸�num
//	////��ָ�뱻const�޶���numû�б��޶�ʱ������ֱ���޸�num
//	////���Կ��Եõ����ۣ�constֻ���Ƶ�ǰ�ı���ʱ��������ʹ��ʾͬһ���ڴ棬Ҳ����ͨ������δ��const���εı����޸�
//	//num = 20;
//	//printf("num = %d", num);
//	
//	//��ô��һ��ָ�뱻const���κ󣬿���ͨ������ָ���num��ֵ��
//	//ͨ��ʵ�飬�ǿ��Եģ�
//	//�ٴ�֤����const���εı�����ֻ�ܱ�ʾ����ͨ���ñ����޸Ķ�Ӧ��ַ�ϵ�ֵ��������ʾ�õ�ַ�ϵ�ֵ���ܱ��޸�
//	const int num = 10;
//	const int* p = &num;
//	int** pp = &p;
//	**pp = 20;
//	printf("num = %d", num);
//	
//	//const��λ�þ�����ͬ������
//	//const�� * ��ǰ�棨��intǰ�ͺ��У����һ��������ʾָ��ָ��ı������ܸ��ģ�
//	//const�� * �ĺ��棬��ʾָ���������ĵ�ַ���ܸ���
//
//	return 0;
//}

//ģ��ʵ��strlen����
size_t my_strlen(const char* str)
{
	assert(str != NULL);
	char* pc = str;
	while (*pc++ != '\0');
	return pc - str - 1;
}

int main()
{
	char str[] = "hello world";
	int len = my_strlen(str);
	//int len = strlen(str);
	printf("len = %d", len);
	return 0;
}