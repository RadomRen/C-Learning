#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"

//通讯录
//1、通讯录中能存放1000个人的信息
//   每个人的信息：
//		 姓名，性别，年龄，电话，地址
//2、增加联系人
//3、删除指定的联系人
//4、修改指定的联系人
//5、查找指定联系人的信息
//6、对通讯录联系人进行排序

//三个文件：
//contacts.h  --  类型定义，函数声明
//contacts.c  --  函数的实现
//test.c  --  测试通讯录的模块

//菜单
void menu()
{
	printf("*************************************************\n");
	printf("*************   1. 增 加 联 系 人   *************\n");
	printf("*************   2. 删 除 联 系 人   *************\n");
	printf("*************   3. 修 改 联 系 人   *************\n");
	printf("*************   4. 查 找 联 系 人   *************\n");
	printf("*************   5. 通 讯 录 排 序   *************\n");
	printf("*************   6. 显示全部联系人   *************\n");
	printf("*************   7. 清 空 通 讯 录   *************\n");
	printf("*************   0. 退 出 通 讯 录   *************\n");
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
	//初始化通讯录
	initContacts(&contacts);
	do
	{
		menu();
		printf("请输入您的选择：>");
		scanf("%d", &select);
		switch (select)
		{
		case ADD:
			//添加联系人
			addContacts(&contacts);
			break;
		case DEL:
			//删除某个联系人
			delOnePeople(&contacts);
			break;
		case MOD:
			//修改某个联系人信息
			modifyPeoInfo(&contacts);
			break;
		case FIND:
			//查找某个联系人
			findPeoInfo(&contacts);
			break;
		case SORT:
			//对通讯录排序
			sortContacts(&contacts);
			break;
		case SHOWALL:
			//显示通讯录
			showContacts(&contacts);
			break;
		case CLEAR:
			//清空通讯录
			clearContacts(&contacts);
			break;
		case EXIT:
			printf("通讯录已退出\n");
			free(contacts.pis);
			break;
		default:
			printf("您的选择有误，请重新选择\n");
			break;
		}
		system("pause");
		system("cls");
	} while (select);
	return 0;
}