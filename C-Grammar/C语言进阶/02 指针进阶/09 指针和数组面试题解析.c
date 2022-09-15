#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


////一维数组
//int main()
//{
//	//数组名只有在两种情况下表示，整个数组，其他情况都表示首元素地址：
//	//sizeof(数组名)：计算整个数组的大小，单位是字节
//	//&数组名：取出的是整个数组的地址
//	
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//4*4 = 16
//	printf("%d\n", sizeof(a + 0));//首元素地址，大小为4/8
//	printf("%d\n", sizeof(*a));//数组的第一个元素，大小为4
//	printf("%d\n", sizeof(a + 1));//数组的第二个元素地址，大小为4/8
//	printf("%d\n", sizeof(a[1]));//数组的第二个元素，大小为4
//
//	printf("%d\n", sizeof(&a));//整个数组的地址，4/8
//	printf("%d\n", sizeof(*&a));//整个数组大小16
//	printf("%d\n", sizeof(&a + 1));//跳过整个数组的下一个地址，4/8
//	printf("%d\n", sizeof(&a[0]));//首元素的地址 4/8
//	printf("%d\n", sizeof(&a[0] + 1));//第二个元素的地址 4/8
//	return 0;
//}


////字符数组
//int main()
//{
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	//printf("%d\n", sizeof(arr));//6：整个数组的大小
//	//printf("%d\n", sizeof(arr + 0));//4/8：首元素地址大小
//	//printf("%d\n", sizeof(*arr));//1：首元素的大小
//	//printf("%d\n", sizeof(arr[1]));//1：第一个元素的大小
//	//printf("%d\n", sizeof(&arr));//4/8：整个元素的地址的大小
//	//printf("%d\n", sizeof(&arr + 1));//4/8：跳过整个元素的下一个地址大小
//	//printf("%d\n", sizeof(&arr[0] + 1));//4/8：第二个元素的地址大小
//
//	//printf("%d\n", strlen(arr));//随机值
//	//printf("%d\n", strlen(arr + 0));//随机值
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	//printf("%d\n", strlen(&arr));//随机值
//	//printf("%d\n", strlen(&arr + 1));//随机值 - 6
//	//printf("%d\n", strlen(&arr[0] + 1));//随机值 - 1
//
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//7：整个数组的大小,含有'\0'
//	//printf("%d\n", sizeof(arr + 0));//4/8：首元素地址大小
//	//printf("%d\n", sizeof(*arr));//1：首元素的大小
//	//printf("%d\n", sizeof(arr[1]));//1：第一个元素的大小
//	//printf("%d\n", sizeof(&arr));//4/8：整个元素的地址的大小
//	//printf("%d\n", sizeof(&arr + 1));//4/8：跳过整个元素的下一个地址大小
//	//printf("%d\n", sizeof(&arr[0] + 1));//4/8：第二个元素的地址大小
//
//	//printf("%d\n", strlen(arr));//6
//	//printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	//printf("%d\n", strlen(&arr));//6
//	//printf("%d\n", strlen(&arr + 1));//随机值
//	//printf("%d\n", strlen(&arr[0] + 1));//5
//
//	char* p = "abcdef";
//	//printf("%d\n", sizeof(p));//4/8：字符串首元素地址的大小
//	//printf("%d\n", sizeof(p + 1));//4/8：字符串第二个元素地址的大小
//	//printf("%d\n", sizeof(*p));//1：字符串首元素的大小
//	//printf("%d\n", sizeof(p[0]));//1：字符串首元素的大小
//	//printf("%d\n", sizeof(&p));//4/8：二级指针的大小
//	//printf("%d\n", sizeof(&p + 1));//4/8：二级指针的大小
//	//printf("%d\n", sizeof(&p[0] + 1));//4/8：字符串第二个元素地址的大小
//
//	//printf("%d\n", strlen(p));//6
//	//printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	//printf("%d\n", strlen(&p));//随机值
//	//printf("%d\n", strlen(&p + 1));//随机值，与上个随机值没有关系，因为我们不知道 &p中有没有0
//	//printf("%d\n", strlen(&p[0] + 1));//5
//	return 0;
//}

////二维数组
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48：整个数组的大小
//	printf("%d\n", sizeof(a[0][0]));//4：第一行第一列元素的大小
//	printf("%d\n", sizeof(a[0]));//16：第一行数组的大小
//	printf("%d\n", sizeof(a[0] + 1));//4：第一行第二列元素的地址的大小
//	printf("%d\n", sizeof(*(a[0] + 1)));//4：第一行第二列元素（int）的大小
//	printf("%d\n", sizeof(a + 1));//4：第二行的地址的大小
//	printf("%d\n", sizeof(*(a + 1)));//16：第二行整体的大小
//	printf("%d\n", sizeof(&a[0] + 1));//4：第二行地址的大小
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16：第二行数组整体的大小
//	printf("%d\n", sizeof(*a));//16：第一行整体的大小
//	//表达式有两种属性：
//	//	值属性：
//	//	类型属性：
//	//sizeof(a[3])只根据（）内部的类型判断内存大小，而不计算（）内部的值，所以实际上是不会访问a[3]内部是几，也就不存在访问越界
//	printf("%d\n", sizeof(a[3])); //16：二维数组整体之后4个int的大小
//}

//指针笔试题
// 笔试题1
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//表示数组a之后的第一个位置的地址，并且类型为int*
//	printf("%d,%d", *(a + 1), *(ptr - 1));//2, 5
//	return 0;
//}

//笔试题2
////由于还没有学习结构体，这里告知结构体的大小为20个字节
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设 p 的值为0x100000。如下表达式的值分别是多少？
////已知：结构体Test类型的变量大小为20个字节
//int main()
//{
//	printf("%p\n", p + 0x1);//0x100014
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//	return 0;
//}


//笔试题3
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);//将首元素地址强制转换成int，进行int相加，实际值加1，
//	//而再次转换成int*之后，其实相当于将首元素地址向后移动一个字节
//
//	//根据小端存储，和int* 指针读取4个字节的原理，可以知道*ptr2读到的内存数据分布为00 00 00 20，
//	//再根据小端存储，将数据还原为0x20 00 00 00
//	printf("%x,%x", ptr1[-1], *ptr2);//0x4, 0x20000000
//	return 0;
//}


//笔试题4
//int main()
//{
//	int a[3][2] = { (0, 1), (2,3), (4,5) };//{{1, 3},{5, 0},{0, 0}}
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);//1
//	return 0;
//}


//笔试题5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	//画图理解，可以得到 &p[4][2] - &a[4][2] = -4
//	//按照地址打印和按照整型打印，结果是不同的：
//	//按照地址是直接取补码，按照整型，则得到原码
//	printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0xFFFFFFFC, -4
//	return 0;
//}

//笔试题6
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);//ptr1表示跳过整个数组后第一个位置的地址
//	int* ptr2 = (int*)(*(aa + 1));//ptr2表示第2行第一个元素的地址 (*(aa + 1)) == aa[1],第二行的数组名，本质是第二行首元素地址
//	printf("%d, %d", *(ptr1 - 1), *(ptr2 - 1));//10, 5
//	return 0;
//}


//笔试题7
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;//第一个元素的地址，即字符串"work"的地址，字符串本身就是一个字符类型的地址，所以是二级指针
//	pa++;//pa++相当于a++,即为第二个元素的地址
//	printf("%s\n", *pa);//at
//	return 0;
//}


////笔试题8
//int main()
//{
//	char* c[] = { "ENTER","NEW", "POINT", "FIRST" };
//	char** cp[] = { c + 3,c + 2, c + 1, c };
//	char*** cpp = cp;
//	//cpp是数组cp的首元素地址，也就是c+3的地址，++cpp表示c+2的地址
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}