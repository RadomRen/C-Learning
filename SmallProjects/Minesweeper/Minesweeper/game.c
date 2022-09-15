#pragma once

#include "game.h"

//��ʼ������
void InitMap(int mapMine[H][W], int mapStatus[H][W])
{
	//�������N���������
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int x = rand() % H;
		int y = rand() % W;
		//��ʼ���׵�λ��
		mapMine[x][y] = 1;
	}
	//��ʼ������ÿ������ʱ��ʾ��״̬
	int offset[8][2] = {
				{-1, -1}, 
				{-1, 0},
				{-1, 1},
				{0, 1},
				{1, 1},
				{1, 0},
				{1, -1},
				{0, -1}
	};
	for (i = 0; i < H; i++)
	{
		int j = 0;
		for (j = 0; j < W; j++)
		{
			int cnt = 0;
			int k = 0;
			for (k = 0; k < 8; k++)
			{
				//�ų�����Χ���ڵ�ͼ��ĸ��ӣ�ͬʱ������Χ�������е���
				if ((i + offset[k][0] >= 0 && i + offset[k][0] < H) && (j + offset[k][1] >= 0 && j + offset[k][1] < W)
					&& mapMine[i + offset[k][0]][j + offset[k][1]] == 1)
				{
					cnt++;
				}
			}
			mapStatus[i][j] = cnt;
		}
	}
}

//չʾ��ͼ��ǰ״̬
void DrawMap(int mapTurn[H][W], int status)
{
	int i = 0;
	printf("  ");
	for (i = 0; i < W; i++)
	{
		printf(" %d", i + 1);
	}
	printf("\n");
	if (status == 0)
	{
		for (i = 0; i < W; i++)
		{
			printf("%2d", i + 1);
			int j = 0;
			for (j = 0; j < H; j++)
			{
				printf(" #");
			}
			printf(" %d", i + 1);
			printf("\n");
		}
		printf("  ");
		for (i = 0; i < W; i++)
		{
			printf(" %d", i + 1);
		}
		printf("\n");
	}
	else if (status == 1 || status == 2)
	{
		for (i = 0; i < W; i++)
		{
			printf("%2d", i + 1);
			int j = 0;
			for (j = 0; j < H; j++)
			{
				if (mapTurn[i][j] == -1)
					printf(" *");
				else
					printf(" %d", mapTurn[i][j]);
			}
			printf(" %d", i + 1);
			printf("\n");
		}
		printf("  ");
		for (i = 0; i < W; i++)
		{
			printf(" %d", i + 1);
		}
		printf("\n");
	}
}

int IsWin(int mapMine[H][W], int mapTurn[H][W])
{
	int i = 0;
	for (i = 0; i < H; i++)
	{
		int j = 0;
		for (j = 0; j < H; j++)
		{
			//�������û�з����ĵؿ鶼�ǵ��ף����ʾʤ��
			if (!(mapTurn[i][j] == -1 && mapMine[i][j] == 1))
			{
				return 0;
			}
				
		}
	}
	return 1;
}

//�жϵ�ǰ��Ϸ״̬��0 - �������ף���Ϸʧ��  1 - ���зǵ��׶�����������Ϸ�ɹ�  2 - ��Ϸ����
int GetGameStatus(int x, int y, int mapMine[H][W], int mapStatus[H][W], int mapTurn[H][W])
{
	if (mapMine[x][y] == 0)
	{
		mapTurn[x][y] = mapStatus[x][y];	
	}
	else
	{
		return 0;
	}
	if (IsWin(mapMine, mapTurn) == 1)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}