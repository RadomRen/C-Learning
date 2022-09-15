#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
////1.写一个函数，可以逆序一个字符串的内容
//void Invert(char* str)
//{
//	assert(str != NULL);
//	int sz = strlen(str);
//	char* start = str;
//	char* end = str + sz - 1;
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//int main()
//{
//	char str[] = "hello world";
//	Invert(str);
//	printf("%s", str);
//}

////2.用 * 号打印菱形
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < 2 * n - 1; i++)
//	{
//		int j = 0;
//		if (i < n)
//		{
//			for (j = 0; j < n + i; j++)
//			{
//				if (j < n - i - 1)
//				{
//					printf(" ");
//				}
//				else
//				{
//					printf("*");
//				}
//			}
//		}
//		else
//		{
//			for (j = 0; j < 3 * n - i - 2; j++)
//			{
//				if (j < i - n + 1)
//				{
//					printf(" ");
//				}
//				else
//				{
//					printf("*");
//				}
//			}
//		}
//		printf("\n");
//	}
//}

////3.喝汽水问题：1瓶汽水1元，2个空瓶可以1瓶汽水，给20元，可以喝多少瓶汽水
//int main()
//{
//	int rmb = 0;
//	scanf("%d", &rmb);
//	//手中剩余空瓶
//	int n = 0;
//	//喝了几瓶
//	int cnt = rmb;
//	n = cnt;//20
//	while (n >= 2)
//	{
//		cnt += n / 2;//20 + 10 + 5 + 2 + 1 + 1
//		n = n / 2 + n % 2;
//	}
//	printf("可以喝到 %d 瓶水", cnt);
//}

//4.调整整数数组，使得基数全部位于偶数前面
//自己的算法：一次遍历，交换的次数多
//void ReSort(int* arr, int sz)
//{
//	int* i = arr, *j = arr;
//	int* end = arr + sz;
//	while (j < end)
//	{
//		if (*j % 2 != 0)
//		{
//			if (i != j)
//			{
//				int tmp = *j;
//				*j = *i;
//				*i = tmp;
//			}
//			i++;
//			j++;
//		}
//		else
//		{
//			j++;
//		}
//	}
//}

//老师的代码：一次遍历，交换的次数少
void ReSort(int* arr, int sz)
{
	int* left = arr;
	int* right = arr + sz - 1;
	while (left < right)
	{
		while (left < right && *left % 2 == 1)
		{
			left++;
		}
		while (left < right && *right % 2 == 0)
		{
			right--;
		}
		int tmp = *left;
		*left = *right;
		*right = tmp;
	}
}
int main()
{
	int arr[] = { 1,3,2,4,5,7,6,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ReSort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}