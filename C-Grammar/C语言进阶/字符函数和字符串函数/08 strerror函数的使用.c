#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

//ʹ�ÿ⺯����ʱ��
//���ÿ⺯��ʧ�ܵ�ʱ�򣬶������ô�����
////ʹ�ñ��� int errno; ���������
//int main()
//{
//	//printf("%s\n", strerror(0));//No error
//	//printf("%s\n", strerror(1));//Operation not permitted
//	//printf("%s\n", strerror(2));//No such file or directory
//	//printf("%s\n", strerror(3));//No such process
//	//printf("%s\n", strerror(4));//Interrupted function call
//	//printf("%s\n", strerror(5));//Input/output error
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno)); //No such file or directory
//		perror("fopen");//fopen: No such file or directory
//		return 1;
//	}
//	//��ȡ�ļ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}