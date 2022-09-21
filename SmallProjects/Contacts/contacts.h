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

//���͵Ķ���
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

//��ʼ��ͨѶ¼
void initContacts(Contacts* pContacts);

//�����ϵ��
void addContacts(Contacts* pContacts);

//ɾ��ĳ����ϵ��
void delOnePeople(Contacts* pContacts);

//�޸�ĳ����ϵ����Ϣ
void modifyPeoInfo(Contacts* pContacts);

//����ĳ����ϵ��
void findPeoInfo(const Contacts* pContacts);

//��ͨѶ¼����
void sortContacts(Contacts* pContacts);

//��ʾͨѶ¼
void showContacts(const Contacts* pContacts);

//���ͨѶ¼
void clearContacts(Contacts* pContacts);

