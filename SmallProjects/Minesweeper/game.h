#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define H 10//���̸߶�
#define W 10//���̿��
#define N 10//�׵ĸ���

//��ʼ������
void InitMap(int mapMine[H][W], int mapStatus[H][W]);

//չʾ��ͼ��ǰ״̬
void DrawMap(int mapTurn[H][W], int status);

//�жϵ�ǰ��Ϸ״̬��0 - �������ף���Ϸʧ��  1 - ���зǵ��׶�����������Ϸ�ɹ�  2 - ��Ϸ����
int GetGameStatus(int x, int y, int mapMine[H][W], int mapStatus[H][W], int mapTurn[H][W]);