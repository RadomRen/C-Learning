#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1���ṹ�������
struct Stu
{
    char name[20];//����
    int age;//����
    char sex[5];//�Ա�
    char id[20];//ѧ��
}s1;//�ֺŲ��ܶ�
//s1Ϊȫ�ֱ���

//��������
//�����ṹ������
struct
{
    int a;
    char b;
    float c;
} s;

struct Point
{
    int x;
    int y;
}p1;//�������͵�ͬʱ�������p1
struct Point p2;//����ṹ�����p2 
struct Circle
{
    int r;
    struct Point center;
} c1;

//int main()
//{
//    //2���ṹ������Ķ���ͳ�ʼ��
//    struct Point p3 = { 10, 20 };
//    //�ṹ���а����ṹ��ĳ�ʼ��
//    struct Circle c2 = { 5, {1, 3} };
//    printf("r = %d  x = %d  y = %d", c2.r, c2.center.x, c2.center.x);
//    return 0;
//}