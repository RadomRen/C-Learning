#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define H 10//棋盘高度
#define W 10//棋盘宽度
#define N 10//雷的个数

//初始化棋盘
void InitMap(int mapMine[H][W], int mapStatus[H][W]);

//展示地图当前状态
void DrawMap(int mapTurn[H][W], int status);

//判断当前游戏状态，0 - 翻开地雷，游戏失败  1 - 所有非地雷都被翻开，游戏成功  2 - 游戏继续
int GetGameStatus(int x, int y, int mapMine[H][W], int mapStatus[H][W], int mapTurn[H][W]);