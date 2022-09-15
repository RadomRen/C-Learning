#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//ʵ�ּ����� ���ص�������ʹ�ã�
//�˵�
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
	printf("����������������>");
	scanf("%d%d", &x, &y);
	return pf(x, y);
}
//int main()
//{
//	menu();
//	int input = 0;
//	do
//	{
//		printf("����������ѡ��>");
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
//			printf("�˳�����");
//			break;
//		default:
//			printf("ѡ���������������");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//ʹ��ð������ʵ�����ú��� qsort
//void qsort(void* base,//������Ԫ�ص�ַ
//			size_t num, //�����Ԫ�ظ���
//			size_t size,//�����ÿ��Ԫ����ռ�Ŀռ��С����λ���ֽڣ�
//			int (*compar)(const void*, const void*));
//			�ص��������Ƚ�����Ԫ�صĴ�С������Ϊ���� void ���͵�ָ�룬����ֵΪint����
//			����ֵ����0��ʾ��һ���� > �ڶ�������
//			����0����ʾ��һ���� == �ڶ�����
//			С��0����ʾ��һ���� < �ڶ�����
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

//���濪ʼ����qsort�Ĺ����Լ�ʵ��ð������
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