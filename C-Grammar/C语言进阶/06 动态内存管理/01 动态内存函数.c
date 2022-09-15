#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//malloc函数和free函数
// 
//int main()
//{
//    //假设开辟10个整型的空间 - 10 * sizeof(int)
//    //int arr[10];//栈区
//    //动态内存开辟
//    int* p = (int*)malloc(10 * sizeof(int));
//    //在使用这些空间之前：
//    if (p == NULL)
//    {
//        perror("main");//main: xxxxxxxx错误信息    
//    }
//    //使用
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        *(p + i) = i;
//        //p[i] = i
//    }
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    //回收空间
//    free(p);
//    p = NULL;//自己手动将p置为NULL
//    return 0;
//}

//calloc函数
// 
//int main()
//{
//    int* p1 = (int*)malloc(40);
//    if (p1 == NULL)
//        return 1;
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d\n", *(p1 + i));
//    }
//    free(p1);
//    p1 = NULL;
//
//    int* p2 = (int*)calloc(10, sizeof(int));
//    if (p2 == NULL)
//        return 1;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d\n", *(p2 + i));
//    }
//    free(p2);
//    p2 = NULL;
//}

