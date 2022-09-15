#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//�˵�
void menu()
{
	printf("*******************************\n");
	printf("**********   1. play  *********\n");
	printf("**********   0. exit  *********\n");
	printf("*******************************\n");
}

void test(int boardMine[H][W], int boardStatus[H][W])
{
	int i = 0;
	for (i = 0; i < H; i++)
	{
		int j = 0;
		for (j = 0; j < W; j++)
		{
			if (boardMine[i][j] == 0)
				printf(" *");
			else
				printf(" #");
		}
		printf("\n");
	}
	for (i = 0; i < H; i++)
	{
		int j = 0;
		for (j = 0; j < W; j++)
		{
			printf(" %d", boardStatus[i][j]);
		}
		printf("\n");
	}
}

//ɨ����Ϸ
void game()
{
	//�Ƿ����׵ĵ�ͼ
	int mapMine[H][W] = { 0 };
	//ÿ����ʾ���ӵ�����״̬
	int mapStatus[H][W] = { 0 };
	//��ͼչʾ - δ����Ϊ-1 - ����Ϊ�ܱߵ�����
	int mapTurn[H][W];
	memset(mapTurn, -1, sizeof(mapTurn));
	int gameStatus = 2;


	//��ʼ������
	InitMap(mapMine, mapStatus);
	//���Ե�ͼ��״̬
	//test(boardMine, boardStatus);
	//չʾ��ͼ��ǰ״̬
	while (1)
	{
		DrawMap(mapTurn, gameStatus);
		int x = 0, y = 0;
		while (1)
		{
			printf("���������뷭����λ�����꣺>");
			scanf("%d%d", &x, &y);
			//���λ�÷Ƿ�����������
			if (x > H || x < 1 || y > W || y < 1)
			{
				printf("���������Ƿ�������������\n");
			}
			else
			{
				//�����λ���Ѿ���������������
				if (mapTurn[x - 1][y - 1] != -1)
				{
					printf("��λ���Ѿ�����������������\n");
				}
				else
				{
					break;
				}
			}
		}
		//�жϵ�ǰ��Ϸ״̬��0 - �������ף���Ϸʧ��  1 - ���зǵ��׶�����������Ϸ�ɹ�  2 - ��Ϸ����
		gameStatus = GetGameStatus(x - 1, y - 1, mapMine, mapStatus, mapTurn);
		
		if (gameStatus == 0 )
		{
			printf("�������ף���Ϸʧ�ܣ�����\n");
			break;
		}
		else if (gameStatus == 1)
		{
			printf("��ϲ�㣬��Ϸ��ʤ������\n");
			break;
		}
		else
		{
			system("cls");
		}
	}
	DrawMap(mapTurn, gameStatus);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��>");
		
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//��ʼɨ����Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");

	} while (input);
	return 0;
}