#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//1.�ַ�ָ��ʾ��

//int main()
//{
//	////ָ��ָ���ַ�
//	//char ch = 'q';
//	//char* pc = &ch;
//
//	//ָ��ָ���ַ���
//	//�������ǽ��ַ���������ĸ��ַ������ps��
//	char* ps = "hello world";
//	char arr[] = "hello world";
//  //ps = 'w';//psָ�����ַ����������޸�
//
//	printf("%c\n", *ps);//h
//	printf("%s\n", ps);//hello world
//	printf("%s\n", arr);//hello world
//	return 0;
//}

//int main()
//{
//    char str1[] = "hello bit.";
//    //�ַ������ڲ�ͬ���ַ������У�����������׵�ַ��ͬ
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    //��ͬ�ĳ����ַ���ֻ�ܴ洢һ�ݣ�����str3��str4����ͬ�ĵ�ַ
//    char* str4 = "hello bit.";
//
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}