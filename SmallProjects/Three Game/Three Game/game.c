#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化棋盘
void InitBoard(char board[H][W], int h, int w)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			board[i][j] = ' ';//将棋盘的每个位置都初始化为空格
		}
	}
}

//绘制棋盘
void ShowBoard(char board[H][W], int h, int w)
{
	int i = 0;
	//打印上部列号
	printf("  ");
	for (i = 0; i < w; i++)
	{
		printf(" %-2d ", i + 1);
	}
	printf("\n");
	//逐行打印棋盘，分两部分， 棋子行和分隔符行
	for (i = 0; i < h; i++)
	{
		//打印左侧行号
		printf("%-2d", i + 1);
		int j = 0;
		for (j = 0; j < w; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < w - 1)
			{
				printf("|");
			}
		}
		//打印右侧行号
		printf("%-2d\n", i + 1);
		if (i < h - 1)
		{
			printf("  ");
			for (j = 0; j < w; j++)
			{
				printf("---");
				if (j < w - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("  ");
	for (i = 0; i < w; i++)
	{
		printf(" %-2d ", i + 1);
	}
	printf("\n");
}

//玩家走棋
void PlayerMove(char board[H][W], int h, int w)
{
	printf("玩家落子:>\n");
	while (1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//判断玩家输入的坐标是否合法（是否在棋盘上）
		if ((x >= 1 && x <= h) && (y >= 1 && y <= w))
		{
			//判断玩家输入的坐标是否被占用（不是空字符）
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入：>");
			}
		}
		else
		{
			printf("坐标非法，请重新输入：>");
		}	
	}	
}

//判断某位置有无必要拦截或自动落子
int Necessity(int coord[2], int offset[2], int length)
{
	//根据目前的连子长度，和落子的方向，判断这个方向上N连子的边缘是否在棋盘内
	int condition = N - length - 1;
	int bord[2] = {coord[0] + condition * offset[0], coord[1] + condition * offset[1] };
	if (bord[0] >= 0 && bord[0] < H && bord[1] >= 0 && bord[1] < W)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

//智能堵截功能
//如果有智能推荐，则返回坐标，如果没有推荐，则返回[-1, -1]
void AICut(char board[H][W], int h, int w, int coord[3])
{
	//保存所有的堵截的待选位置坐标，
		//第一维有两个取值1，2，表示阻截的优先级，越靠近获胜条件，优先级越高，数字越小，比如一级比二级优先级要高
	int selects[N - C][S][2] = { 0 };
	int cntAll[N - C] = { 0 };		//统计所有可能坐标的个数

	//扫描每一行
	int counts1[H][W][2];//第一维为行数，第二维为连续的段数（默认为最多W段），第三维为每一段的起止坐标（列数）
	memset(counts1, -1, sizeof(counts1));//将统计用的数组 counts1 所有的元素置为-1；
	int i = 0;
	//统计当前棋盘中每行的连续 * 号的起止列号
	for (i = 0; i < h; i++)
	{
		int j = 0;
		int cnt = 0;//最大为 W-1
		for (j = 0; j < w; j++)
		{
			//如果当前符号为 * 
			if (board[i][j] == '*')
			{
				//如果当前段的起止位置为 -1（初始数据），说明当前段还有没 * 号存在，将起止位置都设置为当前列号
				if (counts1[i][cnt][0] == -1)
				{
					counts1[i][cnt][0] = j;
					counts1[i][cnt][1] = j;
				}
				//如果当前段已经有了 * 号，则将结束位置更新为当前列号
				else
				{
					counts1[i][cnt][1] = j;
				}
			}
			//如果当前符号不是 * ，跳过该段统计
			 else
			{
				cnt++;
			}
		}
	}
	//根据统计数据，筛选出快要赢的 * 段，长度为胜利条件减一（该条件可以优化），如五子棋为4
	//遍历每一行
	for (i = 0; i < h; i++)
	{
		int j = 0;
		//遍历当前行的所有 * 段，不论有无 * 段长度
		for (j = 0; j < W; j++)
		{
			// * 段的起始位置坐标不是 -1 的情况下
			//如果连续的 * 长度 = 胜利条件减一，则将两端添加到待选位置
			int length = counts1[i][j][1] - counts1[i][j][0] + 1;
			if (counts1[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果* 段的左侧不靠边，以及 * 段左端的相连位置没有落子，则将该相连位置坐标添加到待选位置
				if (counts1[i][j][0] > 0 && board[i][counts1[i][j][0] - 1] == ' ')
				{
					int offset[2] = { 0, -1 };
					int coordTmp[2] = { i, counts1[i][j][0] - 1 };
					if(Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果 * 段的右侧不靠边，并且 * 段的右端的相连位置没有落子，则将该相连为值坐标添加到待选位置
				if (counts1[i][j][1] < w - 1 && board[i][counts1[i][j][1] + 1] == ' ')
				{
					int offset[2] = { 0, 1 };
					int coordTmp[2] = { i, counts1[i][j][1] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
					
				}
			}
		}
	}

	//扫描每一列
	//每一列最多有H个 * 段（也不是，不过可以这么理解，只能怪C语言数组不是变长的，也可能是我因为还没有学到这部分）
	int counts2[W][H][2];//第一维是列号，第二维是连续的 * 段数，第三维是每段的起止位置（行号）
	memset(counts2, -1, sizeof(counts2));//数组所有元素赋初值为-1
	for (i = 0; i < w; i++)
	{
		int j = 0;
		int cnt = 0;
		for (j = 0; j < h; j++)
		{
			//如果当前位置为 * 号，统计该段
			if (board[j][i] == '*')
			{
				//如果当前 * 段起始位置为 -1，表示当前 * 段还没有 * 号，将起止位置设置为当前行号
				if (counts2[i][cnt][0] == -1)
				{
					counts2[i][cnt][0] = j;
					counts2[i][cnt][1] = j;
				}
				//如果当前段已经统计有 * 号，则将终止位置更新为当前行号
				else
				{
					counts2[i][cnt][1] = j;
				}
			}
			//如果当前位置为不是 * 号，则跳过当前段的统计
			else
			{
				cnt++;
			}
		}
	}
	//根据每列 * 段的统计起止位置，筛选出满足阻截要求的 * 段
	//遍历每一列
	for (i = 0; i < w; i++)
	{
		int j = 0;
		//遍历当前列的所有 * 段，不论有无 * 段长度
		for (j = 0; j < H; j++)
		{
			// * 段的起始位置坐标不是 -1 的情况下
			//当前的阻截要求为 * 段长度为胜利条件减一
			int length = counts2[i][j][1] - counts2[i][j][0] + 1;
			if (counts2[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果当前 * 段的上端不靠边，且上端相连的位置没有棋子，则添加该相连位置为待选位置
				if (counts2[i][j][0] > 0 && board[counts2[i][j][0] - 1][i] == ' ')
				{
					int offset[2] = { -1, 0 };
					int coordTmp[2] = { counts2[i][j][0] - 1, i };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果当前 * 段的下端不靠边，且下端相连的位置没有落子，则添加该相连位置为待选位置
				if (counts2[i][j][1] < w - 1 && board[counts2[i][j][1] + 1][i] == ' ')
				{
					int offset[2] = { 1, 0 };
					int coordTmp[2] = { counts2[i][j][1] + 1, i };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}

	//确定斜方向的情况
	//斜方向的条件判定的算法比较复杂，努力注释清楚

	//判断正斜方向
	//counts3：第一维是正斜方向的走向数目（参考函数IsWin()），第二维是最多段情况（伪）的个数（取最靠中间的走向的格数），
	//第三维是起止位置的坐标，前两个数字是起始位置坐标，后两个数字是终止位置的坐标
	int counts3[H + W - 1][min(H, W)][4];
	memset(counts3, -1, sizeof(counts3));//先将counts3的所有元素赋值为-1
	//因为不像行列那样只需统计一个方向，斜着的情况每条线都需要单独统计每个 * 段的长度，
	//所以使用数组表示，每个数字表示每个走向当前 * 段的长度
	int cnts1[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//当前位置为 * 号的情况下
			if (board[i][j] == '*')
			{
				//如果该位置所在走向的当前 * 段终止位置坐标为-1，表示当前段还没有 * 号，设置起止位置坐标为当前位置坐标
				if (counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] == -1)
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][0] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][1] = j;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
				//如果当前段已经存在 * 号，则将终止位置坐标更新为当前位置坐标
				else
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
			}
			//如果当前位置不是 * 号，则跳过当前段不统计
			else
			{
				cnts1[i - j + (w - 1)]++;
			}
		}
	}
	//根据统计得到的起止位置坐标，筛选符合阻截要求的 * 段
	//遍历每个正斜方向走向
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//遍历每个正斜方向上的 * 段
		for (j = 0; j < min(H, W); j++)
		{
			// * 段的起始位置坐标不是 -1 的情况下
			//如果当前 * 段长度满足阻截长度要求
			int length = counts3[i][j][2] - counts3[i][j][0] + 1;
			if (counts3[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果左上端不靠边，且与左上端相连的位置没有落子，则将该相连位置添加到待选位置
				if (counts3[i][j][0] > 0 && counts3[i][j][1] > 0 && board[counts3[i][j][0] - 1][counts3[i][j][1] - 1] == ' ')
				{
					int offset[2] = { -1, -1 };
					int coordTmp[2] = { counts3[i][j][0] - 1, counts3[i][j][1] - 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果右下端不靠边，且 * 段右下端相连位置没有落子，则将给相连位置添加到待选位置
				if (counts3[i][j][2] < h - 1 && counts3[i][j][3] < w - 1 && board[counts3[i][j][2] + 1][counts3[i][j][3] + 1] == ' ')
				{
					int offset[2] = { 1, 1 };
					int coordTmp[2] = { counts3[i][j][2] + 1, counts3[i][j][3] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}

	//判断反斜方向
	//counts4：第一维是反斜方向的走向数目（参考函数IsWin()），第二维是最多段情况（伪）的个数（取最靠中间的走向的格数），
	//第三维是起止位置的坐标，前两个数字是起始位置坐标，后两个数字是终止位置的坐标
	int counts4[H + W - 1][min(H, W)][4];
	memset(counts4, -1, sizeof(counts4));//先将counts4的所有元素赋值为-1
	//因为不像行列那样只需统计一个方向，斜着的情况每条线都需要单独统计每个 * 段的长度，
	//所以使用数组表示，每个数字表示每个走向当前 * 段的长度
	int cnts2[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//如果当前位置为 * 号
			if (board[i][j] == '*')
			{
				//如果该位置所在的反斜走向上当前 * 段终止位置坐标为-1，表示该 * 段还没有统计到 * 号，
				//所以将该 * 段的起止位置坐标设置为当前位置坐标
				if (counts4[i + j][cnts2[i + j]][2] == -1)
				{
					counts4[i + j][cnts2[i + j]][0] = i;
					counts4[i + j][cnts2[i + j]][1] = j;
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
				//如果该 * 段已经有 * 号，则更新终止位置坐标为当前位置坐标
				else
				{
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
			}
			//如果当前位置不是 * 号，则跳过当前 * 段，不统计
			else
			{
				cnts2[i + j]++;
			}
		}
	}

	//根据统计得到的起止位置坐标，筛选符合阻截要求的 * 段
	//遍历每个反斜方向走向
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//遍历每个反斜方向上的 * 段
		for (j = 0; j < min(H, W); j++)
		{
			// * 段的起始位置坐标不是 -1 的情况下
			//如果当前 * 段长度满足阻截长度要求
			int length = counts4[i][j][2] - counts4[i][j][0] + 1;
			if (counts4[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果右上端不靠边，且右上端连接位置没有落子，则将该连接位置添加到待选位置
				if (counts4[i][j][0] > 0 && counts4[i][j][1] < w - 1 && board[counts4[i][j][0] - 1][counts4[i][j][1] + 1] == ' ')
				{
					int offset[2] = { -1, 1 };
					int coordTmp[2] = { counts4[i][j][0] - 1, counts4[i][j][1] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果左下端不靠边，且左上端连接位置没有落子，则将该连接位置添加到待选位置
				if (counts4[i][j][2] < h - 1 && counts4[i][j][3] > 0 && board[counts4[i][j][2] + 1][counts4[i][j][3] - 1] == ' ')
				{
					int offset[2] = { 1, -1 };
					int coordTmp[2] = { counts4[i][j][2] + 1, counts4[i][j][3] - 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}
Final:
	//如果智能筛选到阻截位置坐标
	for (i = 0; i < N - C; i++)
	{
		//通过从小到大遍历优先级，可以控制选位置按照优先级顺序
		if (cntAll[i] > 0)
		{
			//从这些坐标中随机选出一个坐标落子 #
			int idx = rand() % cntAll[i];
			//前两个是坐标，最后一个是优先级
			coord[0] = selects[i][idx][0];
			coord[1] = selects[i][idx][1];
			coord[2] = i;
			return;
		}
	}
	for (i = 0; i < 3; i++)
	{
		coord[i] = -1;
	}
}


//智能主动走棋
//如果有智能推荐，则返回坐标，如果没有推荐，则返回[-1, -1]
void AIMove(char board[H][W], int h, int w, int coord[3])
{
	//保存所有的堵截的待选位置坐标，
		//第一维有两个取值1，2，表示阻截的优先级，越靠近获胜条件，优先级越高，数字越小，比如一级比二级优先级要高
	int selects[N - M][S][2] = { 0 };
	int cntAll[N - M] = { 0 };		//统计所有可能坐标的个数

	//扫描每一行
	int counts1[H][W][2];//第一维为行数，第二维为连续的段数（默认为最多W段），第三维为每一段的起止坐标（列数）
	memset(counts1, -1, sizeof(counts1));//将统计用的数组 counts1 所有的元素置为-1；
	int i = 0;
	//统计当前棋盘中每行的连续 # 号的起止列号
	for (i = 0; i < h; i++)
	{
		int j = 0;
		int cnt = 0;//最大为 W-1
		for (j = 0; j < w; j++)
		{
			//如果当前符号为 # 
			if (board[i][j] == '#')
			{
				//如果当前段的起止位置为 -1（初始数据），说明当前段还有没 # 号存在，将起止位置都设置为当前列号
				if (counts1[i][cnt][0] == -1)
				{
					counts1[i][cnt][0] = j;
					counts1[i][cnt][1] = j;
				}
				//如果当前段已经有了 # 号，则将结束位置更新为当前列号
				else
				{
					counts1[i][cnt][1] = j;
				}
			}
			//如果当前符号不是 # ，跳过该段统计
			else
			{
				cnt++;
			}
		}
	}
	//根据统计数据，筛选出快要赢的 # 段，长度为胜利条件减一（该条件可以优化），如五子棋为4
	//遍历每一行
	for (i = 0; i < h; i++)
	{
		int j = 0;
		//遍历当前行的所有 # 段，不论有无 # 段长度
		for (j = 0; j < W; j++)
		{
			// # 段的起始位置坐标不是 -1 的情况下
			//如果连续的 # 长度 = 胜利条件减一，则将两端添加到待选位置
			int length = counts1[i][j][1] - counts1[i][j][0] + 1;
			if (counts1[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果* 段的左侧不靠边，以及 * 段左端的相连位置没有落子，则将该相连位置坐标添加到待选位置
				if (counts1[i][j][0] > 0 && board[i][counts1[i][j][0] - 1] == ' ')
				{
					int offset[2] = { 0, -1 };
					int coordTmp[2] = { i, counts1[i][j][0] - 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果 * 段的右侧不靠边，并且 * 段的右端的相连位置没有落子，则将该相连为值坐标添加到待选位置
				if (counts1[i][j][1] < w - 1 && board[i][counts1[i][j][1] + 1] == ' ')
				{
					int offset[2] = { 0, 1 };
					int coordTmp[2] = { i, counts1[i][j][1] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}

				}
			}
		}
	}

	//扫描每一列
	//每一列最多有H个 # 段（也不是，不过可以这么理解，只能怪C语言数组不是变长的，也可能是我因为还没有学到这部分）
	int counts2[W][H][2];//第一维是列号，第二维是连续的 # 段数，第三维是每段的起止位置（行号）
	memset(counts2, -1, sizeof(counts2));//数组所有元素赋初值为-1
	for (i = 0; i < w; i++)
	{
		int j = 0;
		int cnt = 0;
		for (j = 0; j < h; j++)
		{
			//如果当前位置为 # 号，统计该段
			if (board[j][i] == '#')
			{
				//如果当前 # 段起始位置为 -1，表示当前 # 段还没有 # 号，将起止位置设置为当前行号
				if (counts2[i][cnt][0] == -1)
				{
					counts2[i][cnt][0] = j;
					counts2[i][cnt][1] = j;
				}
				//如果当前段已经统计有 # 号，则将终止位置更新为当前行号
				else
				{
					counts2[i][cnt][1] = j;
				}
			}
			//如果当前位置为不是 # 号，则跳过当前段的统计
			else
			{
				cnt++;
			}
		}
	}
	//根据每列 # 段的统计起止位置，筛选出满足阻截要求的 # 段
	//遍历每一列
	for (i = 0; i < w; i++)
	{
		int j = 0;
		//遍历当前列的所有 # 段，不论有无 # 段长度
		for (j = 0; j < H; j++)
		{
			// # 段的起始位置坐标不是 -1 的情况下
			//当前的阻截要求为 # 段长度为胜利条件减一
			int length = counts2[i][j][1] - counts2[i][j][0] + 1;
			if (counts2[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果当前 * 段的上端不靠边，且上端相连的位置没有棋子，则添加该相连位置为待选位置
				if (counts2[i][j][0] > 0 && board[counts2[i][j][0] - 1][i] == ' ')
				{
					int offset[2] = { -1, 0 };
					int coordTmp[2] = { counts2[i][j][0] - 1, i };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果当前 * 段的下端不靠边，且下端相连的位置没有落子，则添加该相连位置为待选位置
				if (counts2[i][j][1] < w - 1 && board[counts2[i][j][1] + 1][i] == ' ')
				{
					int offset[2] = { 1, 0 };
					int coordTmp[2] = { counts2[i][j][1] + 1, i };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}

	//确定斜方向的情况
	//斜方向的条件判定的算法比较复杂，努力注释清楚

	//判断正斜方向
	//counts3：第一维是正斜方向的走向数目（参考函数IsWin()），第二维是最多段情况（伪）的个数（取最靠中间的走向的格数），
	//第三维是起止位置的坐标，前两个数字是起始位置坐标，后两个数字是终止位置的坐标
	int counts3[H + W - 1][min(H, W)][4];
	memset(counts3, -1, sizeof(counts3));//先将counts3的所有元素赋值为-1
	//因为不像行列那样只需统计一个方向，斜着的情况每条线都需要单独统计每个 # 段的长度，
	//所以使用数组表示，每个数字表示每个走向当前 # 段的长度
	int cnts1[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//当前位置为 # 号的情况下
			if (board[i][j] == '#')
			{
				//如果该位置所在走向的当前 # 段终止位置坐标为-1，表示当前段还没有 # 号，设置起止位置坐标为当前位置坐标
				if (counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] == -1)
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][0] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][1] = j;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
				//如果当前段已经存在 # 号，则将终止位置坐标更新为当前位置坐标
				else
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
			}
			//如果当前位置不是 # 号，则跳过当前段不统计
			else
			{
				cnts1[i - j + (w - 1)]++;
			}
		}
	}
	//根据统计得到的起止位置坐标，筛选符合阻截要求的 # 段
	//遍历每个正斜方向走向
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//遍历每个正斜方向上的 # 段
		for (j = 0; j < min(H, W); j++)
		{
			// # 段的起始位置坐标不是 -1 的情况下
			//如果当前 # 段长度满足阻截长度要求
			int length = counts3[i][j][2] - counts3[i][j][0] + 1;
			if (counts3[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果左上端不靠边，且与左上端相连的位置没有落子，则将该相连位置添加到待选位置
				if (counts3[i][j][0] > 0 && counts3[i][j][1] > 0 && board[counts3[i][j][0] - 1][counts3[i][j][1] - 1] == ' ')
				{
					int offset[2] = { -1, -1 };
					int coordTmp[2] = { counts3[i][j][0] - 1, counts3[i][j][1] - 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果右下端不靠边，且 * 段右下端相连位置没有落子，则将给相连位置添加到待选位置
				if (counts3[i][j][2] < h - 1 && counts3[i][j][3] < w - 1 && board[counts3[i][j][2] + 1][counts3[i][j][3] + 1] == ' ')
				{
					int offset[2] = { 1, 1 };
					int coordTmp[2] = { counts3[i][j][2] + 1, counts3[i][j][3] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}

	//判断反斜方向
	//counts4：第一维是反斜方向的走向数目（参考函数IsWin()），第二维是最多段情况（伪）的个数（取最靠中间的走向的格数），
	//第三维是起止位置的坐标，前两个数字是起始位置坐标，后两个数字是终止位置的坐标
	int counts4[H + W - 1][min(H, W)][4];
	memset(counts4, -1, sizeof(counts4));//先将counts4的所有元素赋值为-1
	//因为不像行列那样只需统计一个方向，斜着的情况每条线都需要单独统计每个 # 段的长度，
	//所以使用数组表示，每个数字表示每个走向当前 # 段的长度
	int cnts2[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//如果当前位置为 # 号
			if (board[i][j] == '#')
			{
				//如果该位置所在的反斜走向上当前 # 段终止位置坐标为-1，表示该 # 段还没有统计到 # 号，
				//所以将该 # 段的起止位置坐标设置为当前位置坐标
				if (counts4[i + j][cnts2[i + j]][2] == -1)
				{
					counts4[i + j][cnts2[i + j]][0] = i;
					counts4[i + j][cnts2[i + j]][1] = j;
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
				//如果该 # 段已经有 # 号，则更新终止位置坐标为当前位置坐标
				else
				{
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
			}
			//如果当前位置不是 # 号，则跳过当前 # 段，不统计
			else
			{
				cnts2[i + j]++;
			}
		}
	}

	//根据统计得到的起止位置坐标，筛选符合阻截要求的 # 段
	//遍历每个反斜方向走向
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//遍历每个反斜方向上的 # 段
		for (j = 0; j < min(H, W); j++)
		{
			// # 段的起始位置坐标不是 -1 的情况下
			//如果当前 # 段长度满足阻截长度要求
			int length = counts4[i][j][2] - counts4[i][j][0] + 1;
			if (counts4[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//鉴于C语言中的数组不是变长的，只能给定长度，所以要限制cntALL的大小为数组长度，防止访问越界
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//如果右上端不靠边，且右上端连接位置没有落子，则将该连接位置添加到待选位置
				if (counts4[i][j][0] > 0 && counts4[i][j][1] < w - 1 && board[counts4[i][j][0] - 1][counts4[i][j][1] + 1] == ' ')
				{
					int offset[2] = { -1, 1 };
					int coordTmp[2] = { counts4[i][j][0] - 1, counts4[i][j][1] + 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
				//如果左下端不靠边，且左上端连接位置没有落子，则将该连接位置添加到待选位置
				if (counts4[i][j][2] < h - 1 && counts4[i][j][3] > 0 && board[counts4[i][j][2] + 1][counts4[i][j][3] - 1] == ' ')
				{
					int offset[2] = { 1, -1 };
					int coordTmp[2] = { counts4[i][j][2] + 1, counts4[i][j][3] - 1 };
					if (Necessity(coordTmp, offset, length))
					{
						selects[priority][cntAll[priority]][0] = coordTmp[0];
						selects[priority][cntAll[priority]][1] = coordTmp[1];
						cntAll[priority]++;
					}
				}
			}
		}
	}
Final:
	//如果智能筛选到阻截位置坐标
	for (i = 0; i < N - M; i++)
	{
		//通过从小到大遍历优先级，可以控制选位置按照优先级顺序
		if (cntAll[i] > 0)
		{
			//从这些坐标中随机选出一个坐标落子 #
			int idx = rand() % cntAll[i];
			//前两个是坐标，最后一个是优先级
			coord[0] = selects[i][idx][0];
			coord[1] = selects[i][idx][1];
			coord[2] = i;
			return;
		}
	}
	for (i = 0; i < 3; i++)
	{
		coord[i] = -1;
	}
}

//电脑走棋
void ComputerMove(char board[H][W], int h, int w)
{
	printf("电脑落子中......\n");
	Sleep(1000);
	//加入智能堵截功能
	//AICut函数返回一个含有两个坐标数字的数组
	int coordCut[3];
	AICut(board, h, w, coordCut);
	int coordMove[3];
	AIMove(board, h, w, coordMove);
	if (coordCut[0] != -1 && coordMove[0] != -1)
	{
		if (coordMove[2] <= coordCut[2])
		{
			board[coordMove[0]][coordMove[1]] = '#';
		}
		else
		{
			board[coordCut[0]][coordCut[1]] = '#';
		}
	}
	else if (coordCut[0] != -1)
	{
		board[coordCut[0]][coordCut[1]] = '#';
	}
	else
	{
		if (coordMove[0] != -1)
		{
			board[coordMove[0]][coordMove[1]] = '#';
		}
		else 
		{
			int cnt = 0;
			while (1)
			{
				//如果没有智能筛选到坐标，则随机生成坐标
				//坐标被限制在棋盘上
				if (cnt <= 100)
				{
					int x = 0, y = 0;
					x = rand() % (h - 2 * N) + N;
					y = rand() % (w - 2 * N) + N;
					if (board[x][y] == ' ')
					{
						board[x][y] = '#';
						break;
					}
					cnt++;
				}
				else
				{
					int x = 0, y = 0;
					x = rand() % h;
					y = rand() % w;
					if (board[x][y] == ' ')
					{
						board[x][y] = '#';
						break;
					}
				}
				
			}
			
		}
			
	}
	
}

//判断是否平局
int IsFull(char board[H][W], int h, int w)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断输赢
/*判断规则：
	行：每一行相连的*或者#的个数是否达到胜利条件的个数
	列：每一列相连的*或者#的个数是否达到胜利条件的个数
	正斜方向：判断每一个正斜方向上相连的 * 或者 # 的个数是否达到胜利条件的个数
		分析可知：正斜方向上总共有 W+H-1 条线，并且每一条线上的所有坐标的x - y 是固定的，
		并且发现再加上 w - 1 之后，刚好是一个 0 ~ w + h - 2 的序列，于是，可以设置一个二维数组，
		用作统计对弈双方正斜方向上相连棋子的个数：counts1[W + H - 1][2],第一维表示正斜方向的每一条线，
		并且发现第一维的下标刚好与 x - y + w - 1 的值一一对应，因此用作统计，刚刚好，第二维两个数据
		分别表示 * 的相连数和 # 的相连数
	反斜方向：判断每一个反斜方向上相连的 * 或者 # 的个数是否达到胜利条件的个数
		分析可知：反斜方向上总共有 W+H+1 条线，并且每一条线上的所有位置坐标的 x + y 是固定的，
		而且刚好是一个 0 ~ w + h - 2 的序列，于是，可以设置一个二维数组，用作统计对弈双方反斜方向上的
		相连棋子的个数：counts2[W + H - 1][2]，第一维表示反斜方向上的每一个走向，并且第一维的下标刚好与
		x + y 一一对应，因此用作统计刚好，第二维两个数据分别表示 * 号的相连数和 # 号的相连数
*/
char IsWin(char board[H][W], int h, int w)
{
	int i = 0;
	//判断每一行有没有获胜点
	for (i = 0; i < h; i++)
	{
		//每一行先把计数器置零
		int countP = 0;//统计玩家相连棋子数
		int countC = 0;//统计电脑相连棋子数
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//如果当前不是*号，则将*号相连计数器置为0
			if (board[i][j] != '*')
			{
				countP = 0;
			}
			else
			{
				//当前是*号，则将*号计数器+1
				countP++;
				//判断相连的*号是否满足胜利要求，若是，则返回玩家胜利标志‘*’
				if (countP >= N)
				{
					return '*';
				}
			}
			//如果当前不是#号，则将#号相连计数器置为0
			if (board[i][j] != '#')
			{
				countC = 0;
			}
			else
			{
				//当前是#号，则将#号计数器+1
				countC++;
				//判断相连的#号是否满足胜利要求，若是，则返回电脑胜利标志‘#’
				if (countC >= N)
				{
					return '#';
				}
			}
		}
	}

	//判断每一列是否有获胜点
	for (i = 0; i < w; i++)
	{
		//每一列先把计数器置零
		int countP = 0;//统计玩家相连棋子数
		int countC = 0;//统计电脑相连棋子数
		int j = 0;
		for (j = 0; j < h; j++)
		{
			//如果当前不是*号，则将*号相连计数器置为0
			if (board[j][i] != '*')
			{
				countP = 0;
			}
			else
			{
				//当前是*号，则将*号计数器+1
				countP++;
				//判断相连的*号是否满足胜利要求，若是，则返回玩家胜利标志‘*’
				if (countP >= N)
				{
					return '*';
				}
			}
			//如果当前不是#号，则将#号相连计数器置为0
			if (board[j][i] != '#')
			{
				countC = 0;
			}
			else
			{
				//当前是#号，则将#号计数器+1
				countC++;
				//判断相连的#号是否满足胜利要求，若是，则返回电脑胜利标志‘#’
				if (countC >= N)
				{
					return '#';
				}
			}
		}
	}

	//判断斜着的有没有胜利的
	//统计正斜方向各方落子个数，第一维表示所有的走向数，第二维表示第一个数表示玩家，第二个数表示电脑
	int counts1[W + H - 1][2] = {0};
	//统计反斜的各方落子个数，第一维表示总共的走向数，第二维表示第一个数表示玩家，第二个数表示电脑
	int counts2[W + H - 1][2] = {0};
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			if (board[i][j] != '*')
			{
				//如果当前符号不是 * ，则对应的走向线条的计数器置为0
				counts1[i - j + (w - 1)][0] = 0;
				counts2[i + j][0] = 0;
			}
			else
			{
				//如果当前符号为 *，则对应走向的计数器+1
				counts1[i - j + (w - 1)][0]++;
				counts2[i + j][0]++;
			}
			//统计 # 的方法与统计 * 的方法相同
			if (board[i][j] != '#')
			{
				counts1[i - j + (w - 1)][1] = 0;
				counts2[i + j][1] = 0;
			}
			else
			{
				counts1[i - j + (w - 1)][1]++;
				counts2[i + j][1]++;
			}
			int k = 0;
			//遍历每个走向的 * 和 # 的个数判断是否对应棋手胜利
			for (k = 0; k < W + H - 1; k++)
			{
				if (counts1[k][0] >= N || counts2[k][0] >= N)
				{
					return '*';
				}
				if (counts1[k][1] >= N || counts2[k][1] >= N)
				{
					return '#';
				}
			}
		}
	}
	//如果棋盘被占满，仍未决出胜负，为平局
	if (IsFull(board, h, w) == 1)
	{
		return 'P';
	}
	//如果没有胜负，也没有平局，则继续下棋
	return 'C';
}