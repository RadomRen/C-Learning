#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <assert.h>

//memcpy
//模拟实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* pd = (char*)dest;
//	const char* ps = (const char*)src;
//	while (num--)
//	{
//		*pd++ = *ps++;
//	}
//	return dest;
//	
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	int n = 3;
//	int sz = sizeof(arr2[0]);
//	//memcpy(arr2, arr1, n * sz);
//	my_memcpy(arr2, arr1, n * sz);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);//1 2 3 0 0 0 0 0 0 0
//	}
//	return 0;
//}

//memmove
////可以拷贝目标数组和源数组之间有内存重叠的情况
////模拟实现memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* ps = (char*)src;
//	char* pd = (char*)dest;
//	if (src < dest) {
//		while (num--)
//		{
//			*(pd + num) = *(ps + num);
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*pd++ = *ps++;
//		}
//	}
//	return dest;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//memmove(arr + 2, arr, 20);
//	my_memmove(arr + 2, arr, 20);
//	//my_memmove(arr, arr + 2, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);//1 2 1 2 3 4 5 8 9 10
//	}
//	return 0;
//}

//memset
int main()
{
	char arr[20] = { 0 };
	memset(arr, 65, 10);
	printf("%s", arr); //AAAAAAAAAA
}

//memcmp
//int main()
//{
//	float a = 0.75;
//	//0 01111110 10000000000000000000000
//	//00111111 01000000 00000000 00000000
//	//3F 40 00 00
//	float b = 0.25;
//	//0 01111101 00000000000000000000000
//	//00111110 10000000 00000000 00000000
//	//3E 80 00 00
//	float arr1[10] = { 1.0,2.0,3.0,4.0,5.0 };
//	//arr1[1]:2.0 == 1.0 * 2 ^ 1
//	//0 10000000 00000000000000000000000
//	//01000000 00000000 00000000 00000000
//	//40 00 00 00
//	float arr2[10] = { 1.0, 3.0 };
//	//arr2[1]:3.0 == 1.1 * 2 ^ 1
//	//0 10000000 10000000000000000000000
//	//01000000 01000000 00000000 00000000
//	//40 40 00 00
//	int ret = memcmp(arr1, arr2, 8);
//	printf("%d\n", ret);
//	return 0;
//}