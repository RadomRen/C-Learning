#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"

//ͨѶ¼
//1��ͨѶ¼���ܴ��1000���˵���Ϣ
//   ÿ���˵���Ϣ��
//		 �������Ա����䣬�绰����ַ
//2��������ϵ��
//3��ɾ��ָ������ϵ��
//4���޸�ָ������ϵ��
//5������ָ����ϵ�˵���Ϣ
//6����ͨѶ¼��ϵ�˽�������

//�����ļ���
//contacts.h  --  ���Ͷ��壬��������
//contacts.c  --  ������ʵ��
//test.c  --  ����ͨѶ¼��ģ��

//�˵�
void menu()
{
	printf("*************************************************\n");
	printf("*************   1. �� �� �� ϵ ��   *************\n");
	printf("*************   2. ɾ �� �� ϵ ��   *************\n");
	printf("*************   3. �� �� �� ϵ ��   *************\n");
	printf("*************   4. �� �� �� ϵ ��   *************\n");
	printf("*************   5. ͨ Ѷ ¼ �� ��   *************\n");
	printf("*************   6. ��ʾȫ����ϵ��   *************\n");
	printf("*************   7. �� �� ͨ Ѷ ¼   *************\n");
	printf("*************   0. �� �� ͨ Ѷ ¼   *************\n");
	printf("*************************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	MOD,
	FIND,
	SORT,
	SHOWALL,
	CLEAR
};

int main()
{
	int select = 0;
	Contacts contacts;
	//��ʼ��ͨѶ¼
	initContacts(&contacts);
	do
	{
		menu();
		printf("����������ѡ��>");
		scanf("%d", &select);
		switch (select)
		{
		case ADD:
			//�����ϵ��
			addContacts(&contacts);
			break;
		case DEL:
			//ɾ��ĳ����ϵ��
			delOnePeople(&contacts);
			break;
		case MOD:
			//�޸�ĳ����ϵ����Ϣ
			modifyPeoInfo(&contacts);
			break;
		case FIND:
			//����ĳ����ϵ��
			findPeoInfo(&contacts);
			break;
		case SORT:
			//��ͨѶ¼����
			sortContacts(&contacts);
			break;
		case SHOWALL:
			//��ʾͨѶ¼
			showContacts(&contacts);
			break;
		case CLEAR:
			//���ͨѶ¼
			clearContacts(&contacts);
			break;
		case EXIT:
			printf("ͨѶ¼���˳�\n");
			free(contacts.pis);
			break;
		default:
			printf("����ѡ������������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	} while (select);
	return 0;
}