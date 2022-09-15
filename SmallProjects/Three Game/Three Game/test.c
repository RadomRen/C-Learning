#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	//存储数据
	char board[H][W];
	//初始化棋盘 - 初始化为空格
	InitBoard(board, H, W);
	//绘制棋盘 - 本质是打印数组的内容
	//ShowBoard(board, H, W);

	char ret = 0;//接收游戏状态
	while (1)
	{
		ShowBoard(board, H, W);
		//玩家走棋
		PlayerMove(board, H, W);
		system("cls");
		////显示棋盘
		ShowBoard(board, H, W);

		//判断输赢  
		//返回值： 玩家赢 - *   电脑赢 - #   平局 - P  继续 - C
		ret = IsWin(board, H, W);
		if (ret != 'C')
		{
			break;
		}

		//电脑走棋
		ComputerMove(board, H, W);
		//判断游戏状态
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
		printf("恭喜你，你赢了！！！\n");
	}
	else if (ret == '#')
	{

		ShowBoard(board, H, W);
		printf("很抱歉，你输了......\n");
	}
	else if(ret == 'P')
	{

		ShowBoard(board, H, W);
		printf("平局\n");
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
	//设置系统时间为随机数种子
	srand((unsigned)time(NULL));
	int input = 0;//存放用户选择
	do
	{
		//打印菜单
		menu();
		printf("请输入您的选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//开始游戏
			game();
			break;
		case 0:
			//退出游戏
			printf("退出游戏\n");
			break;
		default:
			//用户输入选择有误
			printf("选择错误，重新选择\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);//选择退出游戏时退出循环
}