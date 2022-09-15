#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////柔性数组
//struct S
//{
//	int n;
//	int arr[];//柔性数组
//};

////柔性数组的使用
//int main()
//{
//	//期望arr的大小为10个整型
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	if(ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//增加柔性数组的大小
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 10; i < 20; i++)
//	{
//		ps->arr[i] = i;
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//相同功能的其他实现
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		return 1;
	}
	ps->n = 10;
	ps->arr = (int*)malloc(10 * sizeof(int));
	if (ps->arr == NULL)
	{
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	int* ptr = (int*)realloc(ps->arr, 20 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	//使用结构体S

	//释放动态内存
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}