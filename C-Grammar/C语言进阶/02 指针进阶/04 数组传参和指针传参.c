#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////一级指针传参
//void print(int* ptr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(ptr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//}

////二级指针传参
//void test(int** p2)
//{
//	**p2 = 20;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa是一级指针
//	int** ppa = &pa;//ppa是二级指针
//	test(ppa);//传二级指针
//	printf("%d", a);//20
//	test(&pa);//传一级指针的地址
//	int* arr[10] = { 0 };
//	test(arr);//arr首元素的地址指向的是一个指针，即二级指针
//	return 0;
//}