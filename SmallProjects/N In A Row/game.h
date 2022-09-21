#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define H 20	//棋盘的高度（有多少行）
#define W 20	//棋盘的宽度（有多少列）
#define N 5		//下棋的规则（是几字棋）
#define M 1		//电脑主动下棋的规则，大于1
#define C (N - 3)	//电脑拦截的规则
#define S (H / N * W + W / N * H) 	//电脑智能选坐标的最大选择数

//函数声明

//初始化棋盘
void InitBoard(char board[H][W], int h, int w);

//绘制棋盘
void ShowBoard(char board[H][W], int h, int w);

//玩家走棋
void PlayerMove(char board[H][W], int h, int w);

//电脑走棋
void ComputerMove(char board[H][W], int h, int w);

//判断输赢  
//返回值： 玩家赢 - *   电脑赢 - #   平局 - P  继续 - C
char IsWin(char board[H][W], int h, int w);