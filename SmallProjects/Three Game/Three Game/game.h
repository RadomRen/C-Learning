#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define H 20	//���̵ĸ߶ȣ��ж����У�
#define W 20	//���̵Ŀ�ȣ��ж����У�
#define N 5		//����Ĺ����Ǽ����壩
#define M 1		//������������Ĺ��򣬴���1
#define C (N - 3)	//�������صĹ���
#define S (H / N * W + W / N * H) 	//��������ѡ��������ѡ����

//��������

//��ʼ������
void InitBoard(char board[H][W], int h, int w);

//��������
void ShowBoard(char board[H][W], int h, int w);

//�������
void PlayerMove(char board[H][W], int h, int w);

//��������
void ComputerMove(char board[H][W], int h, int w);

//�ж���Ӯ  
//����ֵ�� ���Ӯ - *   ����Ӯ - #   ƽ�� - P  ���� - C
char IsWin(char board[H][W], int h, int w);