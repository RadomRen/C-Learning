#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//1.����Ĵ�����������ʲô
//int main()
//{
//	int a = 0x11223344;
//	//00010001001000100011001101000100 С�˴洢
//	char* pc = (char*)&a;
//	//00000000 �� a �еĵ�8λ�滻��0
//	*pc = 0;
//	//a
//	//00010001001000100011001100000000
//	//0x11223300
//	printf("%x\n", a);
//	return 0;
//}

////2.����Ĵ�����������ʲô
//int i;//ȫ�ֱ���,����ʼ����Ĭ��Ϊ0
//int main()
//{
//	i--;//�õ� i == -1
//	//sizeof����������Ľ����unsigned int,
//	//����i����֮���Ƚ�ʱ������������Ϊ unsigned, -1�ͱ�Ϊunsigned int ��������������i > sizeof(i)
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

//3.�����
//��Sn = a + aa + aaa + aaaa + aaaaa ��ǰ����֮�ͣ�����a��һ������
//ѭ����
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

////�ݹ鷨
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

//4.дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�룬arr��һ������һά����
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

//5.��ӡ 0 ~ 100000 ֮������е�ˮ�ɻ���
#include <math.h>

//����i��λ��n
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
//����ÿһλ��n�η�֮��
//�ݹ��㷨
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
		//�ж�λ��
		if (i == Calc(i, GetDigits(i)))
		{
			printf("%d ", i);
		}
	}
	return 0;
}