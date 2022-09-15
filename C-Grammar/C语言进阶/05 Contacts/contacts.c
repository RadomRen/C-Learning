#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//��ʼ��ͨѶ¼
void initContacts(Contacts* pContacts)
{
	FILE* fpData = NULL;
	FILE* fpNum = NULL;
	if (!(fpData = fopen(DATA_PATH, "r")) || !(fpNum = fopen(NUM_PATH, "r")))
	{
		printf("ͨѶ¼�����ڣ������ͨѶ¼����\n");
		//ͨѶ¼����ϵ�˵�����
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
		printf("��ȡ��������ȱʧ������ȡ��������Ϊ׼\n");
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
		puts("�ļ���ʧ�ܡ���\n");
		return;
	}
	fwrite(pContacts->pis, sizeof(PeoInfo), pContacts->nPeo, fpData);
	fprintf(fpNum, "%d", pContacts->nPeo);
	printf("ͨѶ¼���³ɹ���\n");
	fclose(fpData);
	fclose(fpNum);
}

//���һ����ϵ��
//����ֵ��1 -- ��ӳɹ�   0 -- ���ʧ��
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
	printf("������������>");
	scanf("%s", pi.name);
	
	printf("�������Ա�>");
	scanf("%s", pi.sex);

	printf("���������䣺>");
	scanf("%d", &pi.age);

	printf("������绰���룺>");
	scanf("%s", pi.tele);

	printf("������סַ��>");
	scanf("%s", pi.addr);

	pContacts->pis[pContacts->nPeo] = pi;
	pContacts->nPeo++;
	return 1;
}

//�����ϵ��
void addContacts(Contacts* pContacts)
{
	if (pContacts->nPeo == pContacts->capacity)
	{
		pContacts->capacity += ADD_CAPACITY;
		realloc(pContacts->pis, pContacts->capacity * sizeof(PeoInfo));
	}
	printf("�����������ϵ�˵�������>");
	int numAdd = 0;
	scanf("%d", &numAdd);
	int i = 0;
	for (i = 0; (i < numAdd); i++)
	{ 
		printf("--------����ӵ�%d����ϵ��--------\n", i + 1);
		if (!addOne(pContacts))
		{
			break;
		}
	}
	//����ͨѶ¼
	updateContacts(pContacts);
}

//����ĳ����ϵ�˵��±�
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

//ɾ��ĳ����ϵ��
void delOnePeople(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��������Ҫɾ������ϵ��������>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("���������ϵ�˲����ڣ�\n");
		return;
	}
	printf("���ҵ�������ϵ�ˣ�\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n","����","�Ա�","����","�绰","סַ");
	PeoInfo* pi = &(pContacts->pis[idx]);
	printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	printf("ȷ��Ҫɾ����\n1 -- ɾ��\n0 -- ����\n");
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
			printf("������������������\n");
		}
	}
	int j = 0;
	for (j = idx; j < pContacts->nPeo -1; j++)
	{
		pContacts->pis[j] = pContacts->pis[j + 1];
	}
	pContacts->nPeo--;
	printf("  %s  ɾ���ɹ���\n", name);
	updateContacts(pContacts);
}

//�޸�ĳ����ϵ����Ϣ
void modifyPeoInfo(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��������Ҫ�޸ĵ���ϵ�ˣ�>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("���������ϵ�˲����ڣ�\n");
		return;
	}
	printf("���ҵ�������ϵ�ˣ�\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "סַ");
	PeoInfo* pi = &(pContacts->pis[idx]);
	printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	printf("������Ҫ�޸��Ĳ��֣�\n1 -- ����\t\t2 -- �Ա�\n3 -- ����\t\t4 -- �绰\n5 -- סַ\n");
	int input = 0;
	while (1)
	{
		scanf("%d", &input);
		if (input < 1 || input > 5)
			printf("������������������\n");
		else
			break;
	}
	char str[MAX_ADDR] = { 0 };
	int num = 0;
	printf("��������Ҫ�޸ĳ�ʲô��>");
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

//����ĳ����ϵ��
void findPeoInfo(const Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��������Ҫ���ҵ���ϵ�ˣ�>");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int idx = findPeoInfoIdx(pContacts, name);
	if (idx == -1)
	{
		printf("����ҵ���ϵ�˲����ڣ�\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "סַ");
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

//��ͨѶ¼����
void sortContacts(Contacts* pContacts)
{
	int nPeo = pContacts->nPeo;
	PeoInfo* pis = pContacts->pis;
	if (!nPeo)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��ѡ���������\n1 -- ����\t\t2 -- �Ա�\n3 -- ����\t\t4 -- �绰\n5 -- סַ\n");
	int input = 0;
	while (1)
	{
		scanf("%d", &input);
		if (input < 1 || input > 5)
			printf("������������������\n");
		else
			break;
	}
	switch (input)
	{
	case 1:
		qsort(pis, nPeo, sizeof(PeoInfo), cmp_by_name);
		break;
	case 2:
		printf("������δ�����������ĵȴ�\n");
		break;
	case 3:
		qsort(pis, nPeo, sizeof(PeoInfo), cmp_by_age);
		break;
	case 4:
		printf("������δ�����������ĵȴ�\n");
		break;
	case 5:
		printf("������δ�����������ĵȴ�\n");
		break;
	}
	printf("�����˳�����£�\n");
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "סַ");
	int i = 0;
	for (i = 0; i < nPeo; i++)
	{
		PeoInfo* pi = &(pis[i]);
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	}
	printf("�Ƿ����˳��\n1 -- ����\n2 -- ����\n");
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
			printf("������������������\n");
	}
}

//��ʾͨѶ¼
void showContacts(const Contacts* pContacts)
{
	int nPeo = pContacts->nPeo;
	PeoInfo* pis = pContacts->pis;
	if (!nPeo)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��ǰͨѶ¼����%d����ϵ�ˣ�\n", nPeo);
	//��ӡ��ͷ
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "סַ");
	int i = 0;
	for (i = 0; i < nPeo; i++)
	{
		PeoInfo* pi = &(pis[i]);
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-10s\n", pi->name, pi->sex, pi->age, pi->tele, pi->addr);
	}
}

//���ͨѶ¼
void clearContacts(Contacts* pContacts)
{
	if (!pContacts->nPeo)
	{
		printf("ͨѶ¼�Ѿ�Ϊ�գ�\n");
		return;
	}
	printf("��ȷ��Ҫ���ͨѶ¼��\n1 -- ���\n0 -- ����\n");
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
			printf("ͨѶ¼�����\n");
			return;
		}
		else
			printf("������������������\n");
	}}