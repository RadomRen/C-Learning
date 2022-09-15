#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//杨氏矩阵
//题目内容
//有一个数字矩阵，矩阵的每行从左到右的递增的，矩阵从上到下是递增的
//编写程序在这样的矩阵中查找某个数字是否存在
//要求：时间复杂度小于O（N）
int find_num(int arr[3][3], int* px, int* py, int k)
{
	int row = 0;
	int col = *py - 1;
	while (row < *px && col >= 0)
	{
		int tmp = arr[row][col];
		if (k > tmp)
			row++;
		else if (k < tmp)
			col--;
		else
		{
			*px = row;
			*py = col;
			return 1;
		}

	}
	return 0;
}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	int x = 3, y = 3;
//	int ret = find_num(arr, &x, &y, k);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//		printf("位置在 %d %d\n", x, y);
//	}
//	else
//	{
//		printf("未找到\n");
//	}
//	return 0;
//}