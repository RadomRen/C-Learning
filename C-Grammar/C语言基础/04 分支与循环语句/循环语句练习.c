#define _CRT_SECURE_NO_WARNINGS 1//��ֹscanf����һ��Ҫ���ڵ�һ��
#include <stdio.h>

//// ����n�Ľ׳�
//int main()
//{
//	//forѭ������
//	//int i = 0, n = 10, ret = 1;
//	//for (i = 1; i <= n; i++)
//	//{
//	//	ret *= i;
//	//}
//	//printf("%d", ret);
//
//	//whileѭ������
//	//int i = 1, n = 10, ret = 1;
//	//while (i <= n)
//	//{
//	//	ret *= i;
//	//	i++;
//	//}
//	//printf("%d\n", ret);
//
//	//do whileѭ������
//	//int i = 1, n = 10, ret = 1;
//	//do
//	//{
//	//	ret *= i;
//	//	i++;
//	//} while (i <= n);
//	//printf("%d\n", ret);
//
//	return 0;
//}

// ���� 1! + 2! + 3! + ... + 10!
//int main()
//{
//	int i = 1, j = 1, ret = 0, fact = 1;
//	for (i = 1; i <= 3; i++)
//	{
//		for (j = 1, fact = 1; j <= i; j++)
//		{
//			fact *= j;
//		}
//		ret += fact;
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//�����������в�ѯĳ����
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	printf("��������Ҫ���ҵ����飺");
//	scanf("%d", &n);
//	int idxBeg = 0, idxEnd = sizeof(arr) / sizeof(int) - 1;
//	int idxCurrent = (idxBeg + idxEnd) / 2;
//	while (arr[idxCurrent] != n && idxBeg != idxEnd)
//	{
//		if (arr[idxCurrent] > n)
//		{
//			idxEnd = idxCurrent - 1;
//		}
//		else
//		{
//			idxBeg = idxCurrent + 1;
//		}
//		idxCurrent = (idxBeg + idxEnd) / 2;
//	}
//	if (arr[idxCurrent] == n)
//	{
//		printf("%d��arr�У��±�Ϊ%d", n, idxCurrent);
//	}
//	else
//	{
//		printf("%d����arr��", n);
//	}
//	return 0;
//}

//��д���룬��ʾ����ַ��������ƶ������м���
//�Լ��ķ���
//int main()
//{
//	char arr[] = "welcome to bit!!!!!";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1	;
//	int i = 0, j = 0;
//	for (i = 0; i < (len + 1) / 2; i++)
//	{
//		for (j = 0; j < len; j++)
//		{
//			if (j > i && j < len - 1 - i)
//			{
//				printf("#");
//			}
//			else
//			{
//				printf("%c", arr[j]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//��ʦ�ķ���
//#include <string.h>
//#include <windows.h>//����sleep
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!";
//	char arr2[] = "###################";
//	int left = 0, right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//��ͣ1s
//		system("cls");//�����Ļ
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//}

//����ģ���¼�������λ���
//#include <string.h>
//int main()
//{
//	char psw[] = "rxk921224";
//	printf("���������룺\n");
//	char mypsw[20] = {0};
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", mypsw);
//		//if (input == psw)//�����ַ����ıȽϲ���ʹ��==��Ӧ��ʹ��strcmp����
//		if(strcmp(mypsw, psw) == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else if(i < 2)
//		{
//			printf("������󣬻���%d�λ��ᣬ���������룺\n", 3 - 1 - i);
//		}
//	}
//	if (i == 3)
//	{
//		printf("��¼ʧ�ܣ�����\n");
//	}
//	return 0;
//}

////��������Ϸ(1 - 100)
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("************************************\n");
//	printf("**********   1.������    ***********\n");
//	printf("**********   2.��  ��    ***********\n");
//	printf("************************************\n");
//}
//void game()
//{
//	int given = rand() % 100 + 1;
//	int num = 0;
//	do
//	{
//		printf("��������²��������1 - 100)��\n");
//		scanf("%d", &num);
//		if (num > given)
//		{
//			printf("��´���\n");
//		}
//		else if (num < given)
//		{
//			printf("���С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//	} while (1);
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do
//	{
//		menu();
//		printf("���������ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ");
//			break;
//		default:
//			printf("����������������룺");
//			break;
//		}
//		system("pause");
//		system("cls");
//	} while (input);
//}

//�ػ�����
#include "stdlib.h"
#include "string.h"
int main()
{
	system("shutdown -s -t 60");
	char input[20] = { 0 };
again:
	printf("��ע�⣬��ĵ��Խ���1�����ڹػ���������룺������������ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}