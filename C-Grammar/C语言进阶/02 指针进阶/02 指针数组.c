#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.ָ�������ʾ��

//�ô����ָ�������ʹ�÷�ʽ���Ƽ�
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

////�Ƽ���ʹ�÷�ʽ��������
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 2,3,4,5,6 };
//	int c[] = { 3,4,5,6,7 };
//	int* arr[] = { a, b, c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		//���ÿ������Ĵ�С
//		//int len = sizeof(arr[i]) / sizeof(arr[i][0]);//���ַ�������ʵ�֣������1����Ϊ sizeof(arr[i]) ֻ�ǶԵ�ַ���С�������Ϊ4
//		//�������ʹ�÷���������arr�д�ų�����ͬ�����飬���ƶ�ά����
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", arr[i][j]);
//			//�������ַ�ʽ
//			printf("%d ", *(arr[i] + j));
//		}
//		printf("\n");
//	}
//}