#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////����ָ��
//int main()
//{
//	int a = 10;
//	//����ָ��
//	int* pa = &a;
//
//	char ch = 'w';
//	//�ַ�ָ��
//	char* pc = &ch;
//
//	int arr[10] = { 1,2,3,4,5 };
//	//��������һ��ָ�룬��������ָ��������Ԫ�ص�ָ�룬��������ָ��
//	//arr;
//	int(*parr)[10] = &arr;//(*parr)��ʾparr��һ��ָ�룬[10]��ʾparr��һ��ָ����10��Ԫ�ص������ָ��
//
//	double* d[5];//ָ������
//	double* (*pd)[5] = &d;//ָ��ָ�������ָ�룬�Ǹ�����ָ��
//
//	return 0;
//}

////&������ VS ������
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;//����ָ��
//	int(*p2)[10] = &arr;//����ָ��
//	printf("%p\n", arr);//0055FC7C
//	printf("%p\n", arr + 1);//0055FC80
//	printf("%p\n", &arr);//0055FC7Cz
//	printf("%p\n", &arr + 1);//0055FCA4
//	return 0;
//}

//����ָ���ʹ��

////��һά���鲻����ʹ�ã���Ȼ�������(���������һ�٣�
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	//���ʴ�ӡ����
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);
//		//��
//		printf("%d ", *((*pa) + i));
//	}
//	return 0;
//}

////�Ƽ��ڷ��ʶ�ά����ʱʹ������ָ��
////�ȿ�һ��д��
//void print1(int arr[3][5], int h, int w)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < w; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int h, int w)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < w; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//һ��д��
//	//print1(arr, 3, 5);
//	//��������ʾ��Ԫ�ص�ַ�����ڶ�ά������˵����Ԫ��ָ���ǵ�һ��һά��������
//	print2(arr, 3, 5);
//	return 0;
//}