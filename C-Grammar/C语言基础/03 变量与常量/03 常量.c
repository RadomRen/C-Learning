#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MAX 10

enum Sex
{
    //����ö�����͵ı�����δ������ȡֵ
    MALE,
    FEMALE,
    SECRET
};

int main()
{
	int arr[MAX] = { 0 };
    //ö�ٳ���
    enum Sex s = MALE;
    printf("%d\n", s);
    printf("%d\n", MALE);
    printf("%d\n", FEMALE);
    printf("%d\n", SECRET);

	return 0;
}