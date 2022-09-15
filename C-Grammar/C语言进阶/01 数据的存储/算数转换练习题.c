#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//1.下面的代码输出结果是什么
//int main()
//{
//	int a = 0x11223344;
//	//00010001001000100011001101000100 小端存储
//	char* pc = (char*)&a;
//	//00000000 将 a 中的低8位替换成0
//	*pc = 0;
//	//a
//	//00010001001000100011001100000000
//	//0x11223300
//	printf("%x\n", a);
//	return 0;
//}

////2.下面的代码输出结果是什么
//int i;//全局变量,不初始化，默认为0
//int main()
//{
//	i--;//得到 i == -1
//	//sizeof操作符算出的结果是unsigned int,
//	//所以i在与之做比较时，会整型提升为 unsigned, -1就变为unsigned int 中最大的数，所以i > sizeof(i)
//	if (i > sizeof(i))//V  2^32 - 1 > 4 == ture
//	{
//		printf(">\n");//>
//	}
//	else//X
//	{
//		printf("<\n");
//	}
//	return 0;
//}

//3.编程题
//求Sn = a + aa + aaa + aaaa + aaaaa 的前五项之和，其中a是一个数字
//循环法
int Sn(int a, int n)
{
	int i = 0;
	int num = 0;
	int ret = 0;
	for (i = 0; i < n; i++)
	{
		num = num * 10 + a;
		ret += num;
	}
	return ret;
}

////递归法
//int Sum5(int a, int n)
//{
//	if (n != 1)
//	{
//		return Sum5(a, n - 1) + ;
//	}
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int sn = Sn(a, n);
//	printf("Sn = %d", sn);
//	return 0;
//}

//4.写一个函数打印arr数组的内容，不使用数组下标，使用指针，arr是一个整型一维数组
//void PrintArr(int* parr, size_t len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	size_t len = sizeof(arr) / sizeof(arr[0]);
//	PrintArr(arr, len);
//	return 0;
//}

//5.打印 0 ~ 100000 之间的所有的水仙花数
#include <math.h>

//计算i的位数n
int GetDigits(i)
{
	int cnt = 0;
	while (i)
	{
		i /= 10;
		cnt++;
	}
	return cnt;
}
//计算每一位的n次方之和
//递归算法
int Calc(int i, int n)
{
	if (i != 0)
	{
		return Calc(i / 10, n) + (int)pow(i % 10, n);
	}
	else
	{
		return 0;
	}
}
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//判断位数
		if (i == Calc(i, GetDigits(i)))
		{
			printf("%d ", i);
		}
	}
	return 0;
}