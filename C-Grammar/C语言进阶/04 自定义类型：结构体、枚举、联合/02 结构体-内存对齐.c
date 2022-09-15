#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct S1
{
	char c1;
	int a;
	char c2;
};
struct S2
{
	char c1;
	int a;
	char c2;
	int b;
};
//int main() 
//{
//	struct S1 s1 = { 'q', 1, 'w' };
//	printf("sizeof(s1) = %d\n", sizeof(s1));//12
//	struct S2 s2 = { 'q', 1, 'w', 2 };
//	printf("sizeof(s2) = %d\n", sizeof(s2));//16
//	return 0;
//}