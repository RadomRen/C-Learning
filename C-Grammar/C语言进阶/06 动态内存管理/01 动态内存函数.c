#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//malloc������free����
// 
//int main()
//{
//    //���迪��10�����͵Ŀռ� - 10 * sizeof(int)
//    //int arr[10];//ջ��
//    //��̬�ڴ濪��
//    int* p = (int*)malloc(10 * sizeof(int));
//    //��ʹ����Щ�ռ�֮ǰ��
//    if (p == NULL)
//    {
//        perror("main");//main: xxxxxxxx������Ϣ    
//    }
//    //ʹ��
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
//    //���տռ�
//    free(p);
//    p = NULL;//�Լ��ֶ���p��ΪNULL
//    return 0;
//}

//calloc����
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

