#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//模拟实现strcpy函数
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(src != NULL);
	assert(dest != NULL);
	//assert(strlen(dest) >= strlen(src));
	while (*dest++ = *src++);
	return ret;
}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";
//	char arr2[] = "hello";
//	char* arr3 = my_strcpy(arr1, arr2);//1 - 目标空间的首地址  2 - 源空间的首地址
//	//strcpy(arr1, arr2);
//	printf("arr1 = %s\n", arr1);
//	printf("arr3 = %s\n", arr3);
//}

////const功能解析
//int main()
//{
//	////1.正常情况下，num可以被修改
//	//int num = 10;
//	//num = 20;
//	//printf("num = %d", num);
//
//	////2.给num加上const之后，num不能修改
//	//const int num = 10;
//	////num = 20;//num不能被直接修改
//	////但是可以通过指向num的指针修改num的值
//	//int* p = &num;
//	//*p = 20;
//	//printf("num = %d", num);
//
//	////3.要求：num不能被直接修改，但也不能被通过其指针修改
//	////const int num = 10;
//	//int num = 10;
//	//const int* p = &num;
//	////*p = 20;//在指向num的指针前面加上const时，不能通过指针修改num
//	////在指针被const限定而num没有被限定时，可以直接修改num
//	////所以可以得到结论，const只限制当前的变量时常量，即使表示同一块内存，也可以通过其他未被const修饰的变量修改
//	//num = 20;
//	//printf("num = %d", num);
//	
//	//那么在一级指针被const修饰后，可以通过二级指针改num的值吗？
//	//通过实验，是可以的，
//	//再次证明被const修饰的变量，只能表示不能通过该变量修改对应地址上的值，而不表示该地址上的值不能被修改
//	const int num = 10;
//	const int* p = &num;
//	int** pp = &p;
//	**pp = 20;
//	printf("num = %d", num);
//	
//	//const的位置决定不同的意义
//	//const在 * 的前面（在int前和后都行，结果一样），表示指针指向的变量不能更改，
//	//const在 * 的后面，表示指针变量保存的地址不能更改
//
//	return 0;
//}

//模拟实现strlen函数
size_t my_strlen(const char* str)
{
	assert(str != NULL);
	char* pc = str;
	while (*pc++ != '\0');
	return pc - str - 1;
}

int main()
{
	char str[] = "hello world";
	int len = my_strlen(str);
	//int len = strlen(str);
	printf("len = %d", len);
	return 0;
}