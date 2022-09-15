#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	//�洢����
	char board[H][W];
	//��ʼ������ - ��ʼ��Ϊ�ո�
	InitBoard(board, H, W);
	//�������� - �����Ǵ�ӡ���������
	//ShowBoard(board, H, W);

	char ret = 0;//������Ϸ״̬
	while (1)
	{
		ShowBoard(board, H, W);
		//�������
		PlayerMove(board, H, W);
		system("cls");
		////��ʾ����
		ShowBoard(board, H, W);

		//�ж���Ӯ  
		//����ֵ�� ���Ӯ - *   ����Ӯ - #   ƽ�� - P  ���� - C
		ret = IsWin(board, H, W);
		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board, H, W);
		//�ж���Ϸ״̬
		ret = IsWin(board, H, W);
		if (ret != 'C')
		{
			break;
		}
		system("cls");
	}
	system("cls");
	if (ret == '*')
	{

		ShowBoard(board, H, W);
		printf("��ϲ�㣬��Ӯ�ˣ�����\n");
	}
	else if (ret == '#')
	{

		ShowBoard(board, H, W);
		printf("�ܱ�Ǹ��������......\n");
	}
	else if(ret == 'P')
	{

		ShowBoard(board, H, W);
		printf("ƽ��\n");
	}
}

void menu()
{
	printf("**************************************\n");
	printf("**********     1.play     ************\n");
	printf("**********     0.exit     ************\n");
	printf("**************************************\n");
}

int main()
{
	//����ϵͳʱ��Ϊ���������
	srand((unsigned)time(NULL));
	int input = 0;//����û�ѡ��
	do
	{
		//��ӡ�˵�
		menu();
		printf("����������ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//��ʼ��Ϸ
			game();
			break;
		case 0:
			//�˳���Ϸ
			printf("�˳���Ϸ\n");
			break;
		default:
			//�û�����ѡ������
			printf("ѡ���������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);//ѡ���˳���Ϸʱ�˳�ѭ��
}