#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//实现计算器 （回调函数的使用）
//菜单
void menu()
{
	printf("***********************************\n");
	printf("********  1.Add   2.Sub  **********\n");
	printf("********  3.Mul   4.Div  **********\n");
	printf("********      0.exit     **********\n");
	printf("***********************************\n");
}
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
int Calc(int(*pf)(int, int))
{
	int x = 0, y = 0;
	printf("请输入两个整数：>");
	scanf("%d%d", &x, &y);
	return pf(x, y);
}
//int main()
//{
//	menu();
//	int input = 0;
//	do
//	{
//		printf("请输入您的选择：>");
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			ret = Calc(Add);
//			printf("ret = %d\n", ret);
//			break;
//		case 2:
//			ret = Calc(Sub);
//			printf("ret = %d\n", ret);
//			break;
//		case 3:
//			ret = Calc(Mul);
//			printf("ret = %d\n", ret);
//			break;
//		case 4:
//			ret = Calc(Div);
//			printf("ret = %d\n", ret);
//			break;
//		case 0:
//			printf("退出程序");
//			break;
//		default:
//			printf("选择错误，请重新输入");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//使用冒泡排序实现内置函数 qsort
//void qsort(void* base,//数组首元素地址
//			size_t num, //数组的元素个数
//			size_t size,//数组的每个元素所占的空间大小（单位：字节）
//			int (*compar)(const void*, const void*));
//			回调函数，比较两个元素的大小，参数为两个 void 类型的指针，返回值为int类型
//			返回值大于0表示第一个数 > 第二个数，
//			等于0，表示第一个数 == 第二个数
//			小于0，表示第一个数 < 第二个数
#include <stdlib.h>
int cmpInt(const int* e1, const int* e2)
{
	return *e1 - *e2;
}

void printArr(const int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test1()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmpInt);
	printArr(arr, sz);
}
struct Stu
{
	char name[10];
	int age;
};
int cmp_by_name(const struct Stu* s1, const struct Stu* s2)
{
	return strcmp(s1->name, s2->name);
}
int cmp_by_age(const struct Stu* s1, const struct Stu* s2)
{
	return s1->age - s2->age;
}
void test2()
{
	struct Stu s[3] = {
		{"zhangsan", 30},
		{"lisi", 35},
		{"wangwu", 25}
	};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_by_name);
	qsort(s, sz, sizeof(s[0]), cmp_by_age);
}

//下面开始按照qsort的功能自己实现冒泡排序
void Swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void BubbleSort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void test3()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz, sizeof(arr[0]), cmpInt);
	printArr(arr, sz);
}

void test4()
{
	struct Stu s[3] = {
		{"zhangsan", 30},
		{"lisi", 35},
		{"wangwu", 25}
	};
	int sz = sizeof(s) / sizeof(s[0]);
	BubbleSort(s, sz, sizeof(s[0]), cmp_by_name);
	BubbleSort(s, sz, sizeof(s[0]), cmp_by_age);
}

//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	//test4();
//}