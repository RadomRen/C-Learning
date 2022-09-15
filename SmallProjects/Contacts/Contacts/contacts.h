#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define	MAX_ADDR 30
#define INIT_CAPACITY 5
#define ADD_CAPACITY 3
#define DATA_PATH "contacts.txt"
#define NUM_PATH "num.txt"

//类型的定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contacts
{
	PeoInfo* pis;
	int nPeo;
	int capacity;
}Contacts;

//初始化通讯录
void initContacts(Contacts* pContacts);

//添加联系人
void addContacts(Contacts* pContacts);

//删除某个联系人
void delOnePeople(Contacts* pContacts);

//修改某个联系人信息
void modifyPeoInfo(Contacts* pContacts);

//查找某个联系人
void findPeoInfo(const Contacts* pContacts);

//对通讯录排序
void sortContacts(Contacts* pContacts);

//显示通讯录
void showContacts(const Contacts* pContacts);

//清空通讯录
void clearContacts(Contacts* pContacts);

