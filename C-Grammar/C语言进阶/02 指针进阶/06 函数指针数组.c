#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//使用函数指针数组完成加减乘除计算器
//菜单
//void menu()
//{
//	printf("***********************************\n");
//	printf("********  1.Add   2.Sub  **********\n");
//	printf("********  3.Mul   4.Div  **********\n");
//	printf("********      0.exit     **********\n");
//	printf("***********************************\n");
//}
//int Add(int a, int b)
//{
//	return a + b;
//}
//int Sub(int a, int b)
//{
//	return a - b;
//}
//int Mul(int a, int b)
//{
//	return a * b;
//}
//int Div(int a, int b)
//{
//	return a / b;
//}

//int main()
//{
//	menu();
//	int input = 0;
//	int (*pfArr[5])(int, int) = { NULL, Add, Sub, Mul, Div };
//	do
//	{
//		int x = 0, y = 0;
//		printf("请输入您的选择：>");
//		scanf("%d", &input);
//		if (input > 0 && input < 5)
//		{
//			printf("请输入两个整数：>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("ret = %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序");
//			break;
//		}
//		else
//		{
//			printf("选择错误，请重新选择");
//		}
//	} while (input);
//	return 0;
//}