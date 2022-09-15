#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.指针数组的示例

//该代码对指针数组的使用方式不推荐
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int* arr[3] = { &a, &b, &c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}

////推荐的使用方式是这样的
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 2,3,4,5,6 };
//	int c[] = { 3,4,5,6,7 };
//	int* arr[] = { a, b, c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		//求出每个数组的大小
//		//int len = sizeof(arr[i]) / sizeof(arr[i][0]);//这种方法不能实现，恒等于1，因为 sizeof(arr[i]) 只是对地址求大小，结果恒为4
//		//因此这种使用方法是能在arr中存放长度相同的数组，类似二维数组
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", arr[i][j]);
//			//或者这种方式
//			printf("%d ", *(arr[i] + j));
//		}
//		printf("\n");
//	}
//}