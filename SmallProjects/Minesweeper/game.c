#pragma once

#include "game.h"

//初始化棋盘
void InitMap(int mapMine[H][W], int mapStatus[H][W])
{
	//随机产生N个类的坐标
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int x = rand() % H;
		int y = rand() % W;
		//初始化雷的位置
		mapMine[x][y] = 1;
	}
	//初始化翻开每个格子时显示的状态
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
				//排除掉周围坑在地图外的格子，同时满足周围格子中有地雷
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

//展示地图当前状态
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
			//如果凡是没有翻开的地块都是地雷，则表示胜利
			if (!(mapTurn[i][j] == -1 && mapMine[i][j] == 1))
			{
				return 0;
			}
				
		}
	}
	return 1;
}

//判断当前游戏状态，0 - 翻开地雷，游戏失败  1 - 所有非地雷都被翻开，游戏成功  2 - 游戏继续
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