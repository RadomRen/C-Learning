#define _CRT_SECURE_NO_WARNINGS 1//防止scanf报错，一定要放在第一行
#include <stdio.h>

//// 计算n的阶乘
//int main()
//{
//	//for循环方法
//	//int i = 0, n = 10, ret = 1;
//	//for (i = 1; i <= n; i++)
//	//{
//	//	ret *= i;
//	//}
//	//printf("%d", ret);
//
//	//while循环方法
//	//int i = 1, n = 10, ret = 1;
//	//while (i <= n)
//	//{
//	//	ret *= i;
//	//	i++;
//	//}
//	//printf("%d\n", ret);
//
//	//do while循环方法
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

// 计算 1! + 2! + 3! + ... + 10!
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

//在有序数组中查询某个数
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	printf("请输入你要查找的数组：");
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
//		printf("%d在arr中，下标为%d", n, idxCurrent);
//	}
//	else
//	{
//		printf("%d不在arr中", n);
//	}
//	return 0;
//}

//编写代码，演示多个字符从两端移动，向中间汇聚
//自己的方法
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
//老师的方法
//#include <string.h>
//#include <windows.h>//包含sleep
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
//		Sleep(1000);//暂停1s
//		system("cls");//清空屏幕
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//}

//需求，模拟登录，有三次机会
//#include <string.h>
//int main()
//{
//	char psw[] = "rxk921224";
//	printf("请输入密码：\n");
//	char mypsw[20] = {0};
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", mypsw);
//		//if (input == psw)//两个字符串的比较不能使用==，应该使用strcmp函数
//		if(strcmp(mypsw, psw) == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else if(i < 2)
//		{
//			printf("密码错误，还有%d次机会，请重新输入：\n", 3 - 1 - i);
//		}
//	}
//	if (i == 3)
//	{
//		printf("登录失败！！！\n");
//	}
//	return 0;
//}

////猜数字游戏(1 - 100)
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("************************************\n");
//	printf("**********   1.猜数字    ***********\n");
//	printf("**********   2.退  出    ***********\n");
//	printf("************************************\n");
//}
//void game()
//{
//	int given = rand() % 100 + 1;
//	int num = 0;
//	do
//	{
//		printf("请输入你猜测的整数（1 - 100)：\n");
//		scanf("%d", &num);
//		if (num > given)
//		{
//			printf("你猜大了\n");
//		}
//		else if (num < given)
//		{
//			printf("你猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
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
//		printf("请输入你的选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("输入错误，请重新输入：");
//			break;
//		}
//		system("pause");
//		system("cls");
//	} while (input);
//}

//关机功能
#include "stdlib.h"
#include "string.h"
int main()
{
	system("shutdown -s -t 60");
	char input[20] = { 0 };
again:
	printf("请注意，你的电脑将在1分钟内关机，如果输入：“我是猪”，就取消关机\n");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}