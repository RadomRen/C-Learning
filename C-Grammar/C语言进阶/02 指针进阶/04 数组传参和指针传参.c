#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////һ��ָ�봫��
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

////����ָ�봫��
//void test(int** p2)
//{
//	**p2 = 20;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa��һ��ָ��
//	int** ppa = &pa;//ppa�Ƕ���ָ��
//	test(ppa);//������ָ��
//	printf("%d", a);//20
//	test(&pa);//��һ��ָ��ĵ�ַ
//	int* arr[10] = { 0 };
//	test(arr);//arr��Ԫ�صĵ�ַָ�����һ��ָ�룬������ָ��
//	return 0;
//}