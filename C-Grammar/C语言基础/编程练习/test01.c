#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//练习1：写一个函数，求一个整数二进制中有多少个1

////该代码对于负数是不灵的，可以将参数改为unsigned int n
//int NumOf1(int n)
//{
//	int cnt = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			cnt++;
//		}
//		n /= 2;
//	}
//	return cnt;
//}

////如果想要知道一个整数的二进制补码的最后一位数是否是1只需按位与1就好了，按此思路，写出如下代码
//int NumOf1(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i) & 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
////新的解法
int NumOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
//int main()
//{
//	int n = -1;
//	int ret = NumOf1(n);
//	printf("ret = %d", ret);
//	return 0;
//}

//练习2： 写一个函数，判断一个数字是不是2的n次方
//只需判断该数二进制是不是只有一个1，可以通过(k&(k-1)) == 0判断
int IsExp2(int n)
{
	// & 的优先级比 == 要低，所以要加括号
	if (n >= 0 && (n & (n - 1)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//int main()
//{
//	int n = 0;
//	printf("请输入一个整数：>");
//	scanf("%d", &n);
//	if (IsExp2(n) == 1)
//	{
//		printf("%d是2的n次方\n", n);
//	}
//	else
//	{
//		printf("%d不是2的n次方", n);
//	}
//	return 0;
//}

//练习3： 求两个数二进制中不同位的个数
//1.先将两个数异或，再求得到的结果二进制中1的个数
int DiffNumber(int n1, int n2)
{
	return NumOf1(n1 ^ n2);
}

//int main()
//{
//	int n1 = 1999;
//	int n2 = 2299;
//	printf("请输入两个整数：>");
//	scanf("%d%d", &n1, &n2);
//	printf("%d和%d二进制中不同位的个数有：%d", n1, n2, DiffNumber(n1, n2));
//	return 0;
//}

//练习4：获取整数n二进制中的奇数位和偶数位，并打印出二进制序列
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 31; i >= 0; i--)
//	{
//		printf("%d", n >> i & 1);
//	}
//	printf("\n");
//	printf("偶数位：\n");
//	for (i = 31; i > 0; i -= 2)
//	{
//		printf("%d ", n >> i & 1);
//	}
//	printf("\n");
//	printf("奇数位：\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf(" %d", n >> i & 1);
//	}
//	return 0;
//}


//练习5：不允许创建临时变量，交换两个数
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d\n", a);
//	printf("%d\n", b);
//}

//练习6：求两个数的最小公倍数

//int MinComTimes(int a, int b)
//{
//	int tmpA = a;
//	int tmpB = b;
//	int tmp = 0;
//	while (tmp = tmpA % tmpB)
//	{
//		tmpA = tmpB;
//		tmpB = tmp;
//	}
//	return a * b / tmpB;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int ret = MinComTimes(a, b);
//	printf("%d", ret);
//	return 0;
//}

//练习6：将一句话的单词倒置，标点不倒置。比如 I like beijing. 经过函数后变成  beijing. like I
//算法设计：
//1  -  .gnijieb ekil I
//2  -  beijing. like I
void InvertStr(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main()
{
	char str[] = "I like beijing.";
	//倒置这个句子
	InvertStr(str, str + strlen(str) - 1);
	char* start = str;
	
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end)
		{
			end++;
		}
		InvertStr(start, end - 1);
		if (*end)
			start = end + 1;
		else
			start = end;
	}
	printf("%s", str);
	return 0;
}
