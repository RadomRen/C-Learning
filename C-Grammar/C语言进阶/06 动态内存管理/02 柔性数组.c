#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////��������
//struct S
//{
//	int n;
//	int arr[];//��������
//};

////���������ʹ��
//int main()
//{
//	//����arr�Ĵ�СΪ10������
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	if(ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//������������Ĵ�С
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 10; i < 20; i++)
//	{
//		ps->arr[i] = i;
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//��ͬ���ܵ�����ʵ��
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		return 1;
	}
	ps->n = 10;
	ps->arr = (int*)malloc(10 * sizeof(int));
	if (ps->arr == NULL)
	{
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	int* ptr = (int*)realloc(ps->arr, 20 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	//ʹ�ýṹ��S

	//�ͷŶ�̬�ڴ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}