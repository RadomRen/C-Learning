#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MAX 10

enum Sex
{
    //这种枚举类型的变量的未来可能取值
    MALE,
    FEMALE,
    SECRET
};

int main()
{
	int arr[MAX] = { 0 };
    //枚举常量
    enum Sex s = MALE;
    printf("%d\n", s);
    printf("%d\n", MALE);
    printf("%d\n", FEMALE);
    printf("%d\n", SECRET);

	return 0;
}