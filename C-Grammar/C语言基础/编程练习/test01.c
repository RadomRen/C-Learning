#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//��ϰ1��дһ����������һ���������������ж��ٸ�1

////�ô�����ڸ����ǲ���ģ����Խ�������Ϊunsigned int n
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

////�����Ҫ֪��һ�������Ķ����Ʋ�������һλ���Ƿ���1ֻ�谴λ��1�ͺ��ˣ�����˼·��д�����´���
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
////�µĽⷨ
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

//��ϰ2�� дһ���������ж�һ�������ǲ���2��n�η�
//ֻ���жϸ����������ǲ���ֻ��һ��1������ͨ��(k&(k-1)) == 0�ж�
int IsExp2(int n)
{
	// & �����ȼ��� == Ҫ�ͣ�����Ҫ������
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
//	printf("������һ��������>");
//	scanf("%d", &n);
//	if (IsExp2(n) == 1)
//	{
//		printf("%d��2��n�η�\n", n);
//	}
//	else
//	{
//		printf("%d����2��n�η�", n);
//	}
//	return 0;
//}

//��ϰ3�� ���������������в�ͬλ�ĸ���
//1.�Ƚ��������������õ��Ľ����������1�ĸ���
int DiffNumber(int n1, int n2)
{
	return NumOf1(n1 ^ n2);
}

//int main()
//{
//	int n1 = 1999;
//	int n2 = 2299;
//	printf("����������������>");
//	scanf("%d%d", &n1, &n2);
//	printf("%d��%d�������в�ͬλ�ĸ����У�%d", n1, n2, DiffNumber(n1, n2));
//	return 0;
//}

//��ϰ4����ȡ����n�������е�����λ��ż��λ������ӡ������������
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
//	printf("ż��λ��\n");
//	for (i = 31; i > 0; i -= 2)
//	{
//		printf("%d ", n >> i & 1);
//	}
//	printf("\n");
//	printf("����λ��\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf(" %d", n >> i & 1);
//	}
//	return 0;
//}


//��ϰ5������������ʱ����������������
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

//��ϰ6��������������С������

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

//��ϰ6����һ�仰�ĵ��ʵ��ã���㲻���á����� I like beijing. ������������  beijing. like I
//�㷨��ƣ�
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
	//�����������
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
