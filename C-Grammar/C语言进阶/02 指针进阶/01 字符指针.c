#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//1.字符指针示例

//int main()
//{
//	////指针指向字符
//	//char ch = 'q';
//	//char* pc = &ch;
//
//	//指针指向字符串
//	//本质上是将字符串的首字母地址保存在ps中
//	char* ps = "hello world";
//	char arr[] = "hello world";
//  //ps = 'w';//ps指向常量字符串，不能修改
//
//	printf("%c\n", *ps);//h
//	printf("%s\n", ps);//hello world
//	printf("%s\n", arr);//hello world
//	return 0;
//}

//int main()
//{
//    char str1[] = "hello bit.";
//    //字符串存在不同的字符数组中，两个数组的首地址不同
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    //相同的常量字符串只能存储一份，所以str3和str4是相同的地址
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