#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//初始化通讯录
void initContacts(Contacts* pContacts)
{
	FILE* fpData = NULL;
	FILE* fpNum = NULL;
	if (!(fpData = fopen(DATA_PATH, "r")) || !(fpNum = fopen(NUM_PATH, "r")))
	{
		printf("通讯录不存在，请添加通讯录……\n");
		//通讯录中联系人的数量
		pContacts->nPeo = 0;
		pContacts->pis = (PeoInfo*)calloc(INIT_CAPACITY, sizeof(PeoInfo));
		if (pContacts->pis == NULL)
		{
			perror("InitContacts");
		}
		pContacts->capacity = INIT_CAPACITY;
		return;
	}
	fscanf(fpNum, "%d", &pContacts->nPeo);
	if (pContacts->nPeo == 0)
	{
		pContacts->capacity = INIT_CAPACITY;
		pContacts->pis = (PeoInfo*)calloc(pContacts->capacity, sizeof(PeoInfo));
		if (pContacts->pis == NULL)
		{
			perror("InitContacts");
		}
		return;
	}
	pContacts->capacity = pContacts->nPeo + ADD_CAPACITY;
	pContacts->pis = (PeoInfo*)calloc(pContacts->capacity, sizeof(PeoInfo));
	if (pContacts->pis == NULL)
	{
		perror("InitContacts");
	}
	int num = fread(pContacts->pis, sizeof(PeoInfo), pContacts->nPeo, fpData);
	if (num < pContacts->nPeo)
	{
		printf("读取本地数据缺失，按读取到的数据为准\n");
		pContacts->nPeo = num;
	}

	fclose(fpData);
	fclose(fpNum);
}

void updateContacts(Contacts* pContacts)
{
	FILE* fpData = NULL;
	FILE* fpNum = NULL;
	if (!(fpData = fopen(DATA_PATH, "w")) || !(fpNum = fopen(NUM_PATH, "w")))
	{
		puts("文件打开失败……\n");
		return;
	}
	fwrite(pContacts->pis, sizeof(PeoInfo), pContacts->nPeo, fpData);
	fprintf(fpNum, "%d", pContacts->nPeo);
	printf("通讯录更新成功！\n");
	fclose(fpData);
	fclose(fpNum);
}

//添加一个联系人
//返回值：1 -- 添加成功   0 -- 添加失败
int addOne(Contacts* pContacts)
{
	if (pContacts->nPeo == pContacts->capacity)
	{
		pContacts->capacity += ADD_CAPACITY;
		PeoInfo* ptr = realloc(pContacts->pis, pContacts->capacity * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pContacts->pis = ptr;
		}
		else
		{
			perror("AddContacts");
		}
	}
	struct PeoInfo pi = { 0 };
	printf("请输入姓名：>");
	scanf("%s", pi.name);

	printf("请输入性别：>");
	scanf("%s", pi.sex);

	printf("请输入年龄：>");
	scanf("%d", &pi.age);

	printf("请输入电话号码：>");
	scanf("%s", pi.tele);

	printf("请输入住址：>");
	scanf("%s", pi.addr);

	pContacts->pis[pContacts->nPeo] = pi;
	pContacts->nPeo++;
	return 1;
}

//添加联系人
void addContacts(Contacts* pContacts)
{
	if (pContacts->nPeo == pContacts->capacity)
	{
		pContacts->capacity += ADD_CAPACITY;
		realloc(pContacts->pis, pContacts->capacity * sizeof(PeoInfo));
	}
	printf("请输入添加联系人的数量：>");
	int numAdd = 0;
	scanf("%d", &numAdd);
	int i = 0;
	for (i = 0; (i < numAdd); i++)
	{
		printf("--------请添加第%d个联系人--------\n", i + 1);
		if (!addOne(pContacts))
		{
			break;
		}
	}
	//更新通讯录
	updateContacts(pContacts);
}

//查找某个联系人的下标
static int findPeoInfoIdx(const Contacts* pContacts, char* name)
{
	int i = 0;
	for (i = 0; i < pContacts->nPeo; i++)
	{
		if (!strcmp(pContacts->pis[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//删除某个联系人
void delOnePeople(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入你要删除的联系人姓名：>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("你输入的联系人不存在！\n");
		return;
	}
	printf("查找到如下联系人：\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "住址");
	PeoInfo* pi = &(pContacts->pis[idx]);
	printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	printf("确定要删除吗？\n1 -- 删除\n0 -- 返回\n");
	int input = 0;
	while (1)
	{
		scanf("%d", &input);
		if (!input)
		{
			return;
		}
		else if (input == 1)
		{
			break;
		}
		else
		{
			printf("输入有误，请重新输入\n");
		}
	}
	int j = 0;
	for (j = idx; j < pContacts->nPeo - 1; j++)
	{
		pContacts->pis[j] = pContacts->pis[j + 1];
	}
	pContacts->nPeo--;
	printf("  %s  删除成功！\n", name);
	updateContacts(pContacts);
}

//修改某个联系人信息
void modifyPeoInfo(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入你要修改的联系人：>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("你输入的联系人不存在！\n");
		return;
	}
	printf("查找到如下联系人：\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "住址");
	PeoInfo* pi = &(pContacts->pis[idx]);
	printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	printf("请问你要修改哪部分？\n1 -- 姓名\t\t2 -- 性别\n3 -- 年龄\t\t4 -- 电话\n5 -- 住址\n");
	int input = 0;
	while (1)
	{
		scanf("%d", &input);
		if (input < 1 || input > 5)
			printf("输入有误，请重新输入\n");
		else
			break;
	}
	char str[MAX_ADDR] = { 0 };
	int num = 0;
	printf("请输入您要修改成什么：>");
	if (input != 3)
		scanf("%s", str);
	else
		scanf("%d", &num);
	switch (input)
	{
	case 1:
		strcpy(pi->name, str);
		break;
	case 2:
		strcpy(pi->sex, str);
		break;
	case 3:
		pi->age = num;
		break;
	case 4:
		strcpy(pi->tele, str);
		break;
	case 5:
		strcpy(pi->addr, str);
		break;
	}
	updateContacts(pContacts);
}

//查找某个联系人
void findPeoInfo(const Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入你要查找的联系人：>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("你查找的联系人不存在！\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "住址");
	PeoInfo* pi = &(pContacts->pis[idx]);
	printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
}

static int cmp_by_age(const PeoInfo* e1, const PeoInfo* e2)
{
	return e1->age - e2->age;
}

static int cmp_by_name(const PeoInfo* e1, const PeoInfo* e2)
{
	return strcmp(e1->name, e2->name);
}

//对通讯录排序
void sortContacts(Contacts* pContacts)
{
	int nPeo = pContacts->nPeo;
	PeoInfo* pis = pContacts->pis;
	if (!nPeo)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请选择排序规则：\n1 -- 姓名\t\t2 -- 性别\n3 -- 年龄\t\t4 -- 电话\n5 -- 住址\n");
	int input = 0;
	while (1)
	{
		scanf("%d", &input);
		if (input < 1 || input > 5)
			printf("输入有误，请重新输入\n");
		else
			break;
	}
	switch (input)
	{
	case 1:
		qsort(pis, nPeo, sizeof(PeoInfo), cmp_by_name);
		break;
	case 2:
		printf("功能尚未开发，请耐心等待\n");
		break;
	case 3:
		qsort(pis, nPeo, sizeof(PeoInfo), cmp_by_age);
		break;
	case 4:
		printf("功能尚未开发，请耐心等待\n");
		break;
	case 5:
		printf("功能尚未开发，请耐心等待\n");
		break;
	}
	printf("排序后顺序如下：\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "住址");
	int i = 0;
	for (i = 0; i < nPeo; i++)
	{
		PeoInfo* pi = &(pis[i]);
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	}
	printf("是否更新顺序？\n1 -- 更新\n2 -- 返回\n");
	int isUpdate = 0;
	while (1)
	{
		scanf("%d", &isUpdate);
		if (isUpdate == 1)
		{
			updateContacts(pContacts);
			return;
		}
		else if (isUpdate == 2)
			return;
		else
			printf("输入有误，请重新输入\n");
	}
}

//显示通讯录
void showContacts(const Contacts* pContacts)
{
	int nPeo = pContacts->nPeo;
	PeoInfo* pis = pContacts->pis;
	if (!nPeo)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("当前通讯录中有%d个联系人：\n", nPeo);
	//打印表头
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "住址");
	int i = 0;
	for (i = 0; i < nPeo; i++)
	{
		PeoInfo* pi = &(pis[i]);
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	}
}

//清空通讯录
void clearContacts(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("通讯录已经为空！\n");
		return;
	}
	printf("您确定要清空通讯录吗？\n1 -- 清空\n0 -- 返回\n");
	int isClear = 0;
	while (1)
	{
		if (!isClear)
			return;
		else if (isClear == 1)
		{
			FILE* fp = NULL;
			fp = fopen(DATA_PATH, "w");
			fclose(fp);
			pContacts->nPeo = 0;
			printf("通讯录已清空\n");
			return;
		}
		else
			printf("输入有误，请重新输入\n");
	}
}