#define _CRT_SECURE_NO_WARNINGS 1//��ֹscanf����һ��Ҫ���ڵ�һ��
#include <stdio.h>

extern int val;
int main02()
{
	int a = 0, b = 0, sum = 0;
	scanf("%d%d", &a, &b);
	sum = a + b;
	printf("%d + %d = %d\n", a, b, sum);
	printf("%d", val);
	return 0;
}