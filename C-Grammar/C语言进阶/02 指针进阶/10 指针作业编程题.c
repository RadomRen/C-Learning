#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//���Ͼ���
//��Ŀ����
//��һ�����־��󣬾����ÿ�д����ҵĵ����ģ�������ϵ����ǵ�����
//��д�����������ľ����в���ĳ�������Ƿ����
//Ҫ��ʱ�临�Ӷ�С��O��N��
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
//		printf("�ҵ���\n");
//		printf("λ���� %d %d\n", x, y);
//	}
//	else
//	{
//		printf("δ�ҵ�\n");
//	}
//	return 0;
//}