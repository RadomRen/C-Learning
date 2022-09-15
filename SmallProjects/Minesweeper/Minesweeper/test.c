#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//菜单
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

//扫雷游戏
void game()
{
	//是否埋雷的地图
	int mapMine[H][W] = { 0 };
	//每个提示格子的数字状态
	int mapStatus[H][W] = { 0 };
	//地图展示 - 未翻开为-1 - 翻开为周边地雷数
	int mapTurn[H][W];
	memset(mapTurn, -1, sizeof(mapTurn));
	int gameStatus = 2;


	//初始化棋盘
	InitMap(mapMine, mapStatus);
	//测试地图和状态
	//test(boardMine, boardStatus);
	//展示地图当前状态
	while (1)
	{
		DrawMap(mapTurn, gameStatus);
		int x = 0, y = 0;
		while (1)
		{
			printf("请输入你想翻开的位置坐标：>");
			scanf("%d%d", &x, &y);
			//如果位置非法，重新输入
			if (x > H || x < 1 || y > W || y < 1)
			{
				printf("输入的坐标非法，请重新输入\n");
			}
			else
			{
				//如果该位置已经翻开，重新输入
				if (mapTurn[x - 1][y - 1] != -1)
				{
					printf("该位置已经翻开，请重新输入\n");
				}
				else
				{
					break;
				}
			}
		}
		//判断当前游戏状态，0 - 翻开地雷，游戏失败  1 - 所有非地雷都被翻开，游戏成功  2 - 游戏继续
		gameStatus = GetGameStatus(x - 1, y - 1, mapMine, mapStatus, mapTurn);
		
		if (gameStatus == 0 )
		{
			printf("翻到地雷，游戏失败！！！\n");
			break;
		}
		else if (gameStatus == 1)
		{
			printf("恭喜你，游戏获胜！！！\n");
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
		//打印菜单
		menu();
		printf("请选择：>");
		
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//开始扫雷游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
		system("pause");
		system("cls");

	} while (input);
	return 0;
}