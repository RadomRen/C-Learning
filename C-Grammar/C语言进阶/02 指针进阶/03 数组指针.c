#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////数组指针
//int main()
//{
//	int a = 10;
//	//整型指针
//	int* pa = &a;
//
//	char ch = 'w';
//	//字符指针
//	char* pc = &ch;
//
//	int arr[10] = { 1,2,3,4,5 };
//	//数组名是一个指针，但是它是指向数组首元素的指针，不是数组指针
//	//arr;
//	int(*parr)[10] = &arr;//(*parr)表示parr是一个指针，[10]表示parr是一个指向含有10个元素的数组的指针
//
//	double* d[5];//指针数组
//	double* (*pd)[5] = &d;//指向指针数组的指针，是个数组指针
//
//	return 0;
//}

////&数组名 VS 数组名
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;//整型指针
//	int(*p2)[10] = &arr;//数组指针
//	printf("%p\n", arr);//0055FC7C
//	printf("%p\n", arr + 1);//0055FC80
//	printf("%p\n", &arr);//0055FC7Cz
//	printf("%p\n", &arr + 1);//0055FCA4
//	return 0;
//}

//数组指针的使用

////对一维数组不建议使用，不然会很尴尬(繁琐，多此一举）
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	//访问打印数组
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);
//		//或
//		printf("%d ", *((*pa) + i));
//	}
//	return 0;
//}

////推荐在访问二维数组时使用数组指针
////先看一般写法
//void print1(int arr[3][5], int h, int w)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < w; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int h, int w)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < w; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//一般写法
//	//print1(arr, 3, 5);
//	//数组名表示首元素地址，对于二维数组来说，首元素指的是第一个一维数组整体
//	print2(arr, 3, 5);
//	return 0;
//}