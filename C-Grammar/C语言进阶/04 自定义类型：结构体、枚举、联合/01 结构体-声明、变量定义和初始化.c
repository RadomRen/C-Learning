#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1、结构体的声明
struct Stu
{
    char name[20];//名字
    int age;//年龄
    char sex[5];//性别
    char id[20];//学号
}s1;//分号不能丢
//s1为全局变量

//特殊声明
//匿名结构体类型
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
}p1;//声明类型的同时定义变量p1
struct Point p2;//定义结构体变量p2 
struct Circle
{
    int r;
    struct Point center;
} c1;

//int main()
//{
//    //2、结构体变量的定义和初始化
//    struct Point p3 = { 10, 20 };
//    //结构体中包含结构体的初始化
//    struct Circle c2 = { 5, {1, 3} };
//    printf("r = %d  x = %d  y = %d", c2.r, c2.center.x, c2.center.x);
//    return 0;
//}