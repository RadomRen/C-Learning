#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��ʼ������
void InitBoard(char board[H][W], int h, int w)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			board[i][j] = ' ';//�����̵�ÿ��λ�ö���ʼ��Ϊ�ո�
		}
	}
}

//��������
void ShowBoard(char board[H][W], int h, int w)
{
	int i = 0;
	//��ӡ�ϲ��к�
	printf("  ");
	for (i = 0; i < w; i++)
	{
		printf(" %-2d ", i + 1);
	}
	printf("\n");
	//���д�ӡ���̣��������֣� �����кͷָ�����
	for (i = 0; i < h; i++)
	{
		//��ӡ����к�
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
		//��ӡ�Ҳ��к�
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

//�������
void PlayerMove(char board[H][W], int h, int w)
{
	printf("�������:>\n");
	while (1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//�ж��������������Ƿ�Ϸ����Ƿ��������ϣ�
		if ((x >= 1 && x <= h) && (y >= 1 && y <= w))
		{
			//�ж��������������Ƿ�ռ�ã����ǿ��ַ���
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã����������룺>");
			}
		}
		else
		{
			printf("����Ƿ������������룺>");
		}	
	}	
}

//�ж�ĳλ�����ޱ�Ҫ���ػ��Զ�����
int Necessity(int coord[2], int offset[2], int length)
{
	//����Ŀǰ�����ӳ��ȣ������ӵķ����ж����������N���ӵı�Ե�Ƿ���������
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

//���ܶ½ع���
//����������Ƽ����򷵻����꣬���û���Ƽ����򷵻�[-1, -1]
void AICut(char board[H][W], int h, int w, int coord[3])
{
	//�������еĶ½صĴ�ѡλ�����꣬
		//��һά������ȡֵ1��2����ʾ��ص����ȼ���Խ������ʤ���������ȼ�Խ�ߣ�����ԽС������һ���ȶ������ȼ�Ҫ��
	int selects[N - C][S][2] = { 0 };
	int cntAll[N - C] = { 0 };		//ͳ�����п�������ĸ���

	//ɨ��ÿһ��
	int counts1[H][W][2];//��һάΪ�������ڶ�άΪ�����Ķ�����Ĭ��Ϊ���W�Σ�������άΪÿһ�ε���ֹ���꣨������
	memset(counts1, -1, sizeof(counts1));//��ͳ���õ����� counts1 ���е�Ԫ����Ϊ-1��
	int i = 0;
	//ͳ�Ƶ�ǰ������ÿ�е����� * �ŵ���ֹ�к�
	for (i = 0; i < h; i++)
	{
		int j = 0;
		int cnt = 0;//���Ϊ W-1
		for (j = 0; j < w; j++)
		{
			//�����ǰ����Ϊ * 
			if (board[i][j] == '*')
			{
				//�����ǰ�ε���ֹλ��Ϊ -1����ʼ���ݣ���˵����ǰ�λ���û * �Ŵ��ڣ�����ֹλ�ö�����Ϊ��ǰ�к�
				if (counts1[i][cnt][0] == -1)
				{
					counts1[i][cnt][0] = j;
					counts1[i][cnt][1] = j;
				}
				//�����ǰ���Ѿ����� * �ţ��򽫽���λ�ø���Ϊ��ǰ�к�
				else
				{
					counts1[i][cnt][1] = j;
				}
			}
			//�����ǰ���Ų��� * �������ö�ͳ��
			 else
			{
				cnt++;
			}
		}
	}
	//����ͳ�����ݣ�ɸѡ����ҪӮ�� * �Σ�����Ϊʤ��������һ�������������Ż�������������Ϊ4
	//����ÿһ��
	for (i = 0; i < h; i++)
	{
		int j = 0;
		//������ǰ�е����� * �Σ��������� * �γ���
		for (j = 0; j < W; j++)
		{
			// * �ε���ʼλ�����겻�� -1 �������
			//��������� * ���� = ʤ��������һ����������ӵ���ѡλ��
			int length = counts1[i][j][1] - counts1[i][j][0] + 1;
			if (counts1[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//���* �ε���಻���ߣ��Լ� * ����˵�����λ��û�����ӣ��򽫸�����λ��������ӵ���ѡλ��
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
				//��� * �ε��Ҳ಻���ߣ����� * �ε��Ҷ˵�����λ��û�����ӣ��򽫸�����Ϊֵ������ӵ���ѡλ��
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

	//ɨ��ÿһ��
	//ÿһ�������H�� * �Σ�Ҳ���ǣ�����������ô��⣬ֻ�ܹ�C�������鲻�Ǳ䳤�ģ�Ҳ����������Ϊ��û��ѧ���ⲿ�֣�
	int counts2[W][H][2];//��һά���кţ��ڶ�ά�������� * ����������ά��ÿ�ε���ֹλ�ã��кţ�
	memset(counts2, -1, sizeof(counts2));//��������Ԫ�ظ���ֵΪ-1
	for (i = 0; i < w; i++)
	{
		int j = 0;
		int cnt = 0;
		for (j = 0; j < h; j++)
		{
			//�����ǰλ��Ϊ * �ţ�ͳ�Ƹö�
			if (board[j][i] == '*')
			{
				//�����ǰ * ����ʼλ��Ϊ -1����ʾ��ǰ * �λ�û�� * �ţ�����ֹλ������Ϊ��ǰ�к�
				if (counts2[i][cnt][0] == -1)
				{
					counts2[i][cnt][0] = j;
					counts2[i][cnt][1] = j;
				}
				//�����ǰ���Ѿ�ͳ���� * �ţ�����ֹλ�ø���Ϊ��ǰ�к�
				else
				{
					counts2[i][cnt][1] = j;
				}
			}
			//�����ǰλ��Ϊ���� * �ţ���������ǰ�ε�ͳ��
			else
			{
				cnt++;
			}
		}
	}
	//����ÿ�� * �ε�ͳ����ֹλ�ã�ɸѡ���������Ҫ��� * ��
	//����ÿһ��
	for (i = 0; i < w; i++)
	{
		int j = 0;
		//������ǰ�е����� * �Σ��������� * �γ���
		for (j = 0; j < H; j++)
		{
			// * �ε���ʼλ�����겻�� -1 �������
			//��ǰ�����Ҫ��Ϊ * �γ���Ϊʤ��������һ
			int length = counts2[i][j][1] - counts2[i][j][0] + 1;
			if (counts2[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//�����ǰ * �ε��϶˲����ߣ����϶�������λ��û�����ӣ�����Ӹ�����λ��Ϊ��ѡλ��
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
				//�����ǰ * �ε��¶˲����ߣ����¶�������λ��û�����ӣ�����Ӹ�����λ��Ϊ��ѡλ��
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

	//ȷ��б��������
	//б����������ж����㷨�Ƚϸ��ӣ�Ŭ��ע�����

	//�ж���б����
	//counts3����һά����б�����������Ŀ���ο�����IsWin()�����ڶ�ά�����������α���ĸ�����ȡ��м������ĸ�������
	//����ά����ֹλ�õ����꣬ǰ������������ʼλ�����꣬��������������ֹλ�õ�����
	int counts3[H + W - 1][min(H, W)][4];
	memset(counts3, -1, sizeof(counts3));//�Ƚ�counts3������Ԫ�ظ�ֵΪ-1
	//��Ϊ������������ֻ��ͳ��һ������б�ŵ����ÿ���߶���Ҫ����ͳ��ÿ�� * �εĳ��ȣ�
	//����ʹ�������ʾ��ÿ�����ֱ�ʾÿ������ǰ * �εĳ���
	int cnts1[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//��ǰλ��Ϊ * �ŵ������
			if (board[i][j] == '*')
			{
				//�����λ����������ĵ�ǰ * ����ֹλ������Ϊ-1����ʾ��ǰ�λ�û�� * �ţ�������ֹλ������Ϊ��ǰλ������
				if (counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] == -1)
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][0] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][1] = j;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
				//�����ǰ���Ѿ����� * �ţ�����ֹλ���������Ϊ��ǰλ������
				else
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
			}
			//�����ǰλ�ò��� * �ţ���������ǰ�β�ͳ��
			else
			{
				cnts1[i - j + (w - 1)]++;
			}
		}
	}
	//����ͳ�Ƶõ�����ֹλ�����꣬ɸѡ�������Ҫ��� * ��
	//����ÿ����б��������
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//����ÿ����б�����ϵ� * ��
		for (j = 0; j < min(H, W); j++)
		{
			// * �ε���ʼλ�����겻�� -1 �������
			//�����ǰ * �γ���������س���Ҫ��
			int length = counts3[i][j][2] - counts3[i][j][0] + 1;
			if (counts3[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//������϶˲����ߣ��������϶�������λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
				//������¶˲����ߣ��� * �����¶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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

	//�жϷ�б����
	//counts4����һά�Ƿ�б�����������Ŀ���ο�����IsWin()�����ڶ�ά�����������α���ĸ�����ȡ��м������ĸ�������
	//����ά����ֹλ�õ����꣬ǰ������������ʼλ�����꣬��������������ֹλ�õ�����
	int counts4[H + W - 1][min(H, W)][4];
	memset(counts4, -1, sizeof(counts4));//�Ƚ�counts4������Ԫ�ظ�ֵΪ-1
	//��Ϊ������������ֻ��ͳ��һ������б�ŵ����ÿ���߶���Ҫ����ͳ��ÿ�� * �εĳ��ȣ�
	//����ʹ�������ʾ��ÿ�����ֱ�ʾÿ������ǰ * �εĳ���
	int cnts2[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//�����ǰλ��Ϊ * ��
			if (board[i][j] == '*')
			{
				//�����λ�����ڵķ�б�����ϵ�ǰ * ����ֹλ������Ϊ-1����ʾ�� * �λ�û��ͳ�Ƶ� * �ţ�
				//���Խ��� * �ε���ֹλ����������Ϊ��ǰλ������
				if (counts4[i + j][cnts2[i + j]][2] == -1)
				{
					counts4[i + j][cnts2[i + j]][0] = i;
					counts4[i + j][cnts2[i + j]][1] = j;
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
				//����� * ���Ѿ��� * �ţ��������ֹλ������Ϊ��ǰλ������
				else
				{
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
			}
			//�����ǰλ�ò��� * �ţ���������ǰ * �Σ���ͳ��
			else
			{
				cnts2[i + j]++;
			}
		}
	}

	//����ͳ�Ƶõ�����ֹλ�����꣬ɸѡ�������Ҫ��� * ��
	//����ÿ����б��������
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//����ÿ����б�����ϵ� * ��
		for (j = 0; j < min(H, W); j++)
		{
			// * �ε���ʼλ�����겻�� -1 �������
			//�����ǰ * �γ���������س���Ҫ��
			int length = counts4[i][j][2] - counts4[i][j][0] + 1;
			if (counts4[i][j][0] != -1 && length >= C)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - C; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//������϶˲����ߣ������϶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
				//������¶˲����ߣ������϶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
	//�������ɸѡ�����λ������
	for (i = 0; i < N - C; i++)
	{
		//ͨ����С����������ȼ������Կ���ѡλ�ð������ȼ�˳��
		if (cntAll[i] > 0)
		{
			//����Щ���������ѡ��һ���������� #
			int idx = rand() % cntAll[i];
			//ǰ���������꣬���һ�������ȼ�
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


//������������
//����������Ƽ����򷵻����꣬���û���Ƽ����򷵻�[-1, -1]
void AIMove(char board[H][W], int h, int w, int coord[3])
{
	//�������еĶ½صĴ�ѡλ�����꣬
		//��һά������ȡֵ1��2����ʾ��ص����ȼ���Խ������ʤ���������ȼ�Խ�ߣ�����ԽС������һ���ȶ������ȼ�Ҫ��
	int selects[N - M][S][2] = { 0 };
	int cntAll[N - M] = { 0 };		//ͳ�����п�������ĸ���

	//ɨ��ÿһ��
	int counts1[H][W][2];//��һάΪ�������ڶ�άΪ�����Ķ�����Ĭ��Ϊ���W�Σ�������άΪÿһ�ε���ֹ���꣨������
	memset(counts1, -1, sizeof(counts1));//��ͳ���õ����� counts1 ���е�Ԫ����Ϊ-1��
	int i = 0;
	//ͳ�Ƶ�ǰ������ÿ�е����� # �ŵ���ֹ�к�
	for (i = 0; i < h; i++)
	{
		int j = 0;
		int cnt = 0;//���Ϊ W-1
		for (j = 0; j < w; j++)
		{
			//�����ǰ����Ϊ # 
			if (board[i][j] == '#')
			{
				//�����ǰ�ε���ֹλ��Ϊ -1����ʼ���ݣ���˵����ǰ�λ���û # �Ŵ��ڣ�����ֹλ�ö�����Ϊ��ǰ�к�
				if (counts1[i][cnt][0] == -1)
				{
					counts1[i][cnt][0] = j;
					counts1[i][cnt][1] = j;
				}
				//�����ǰ���Ѿ����� # �ţ��򽫽���λ�ø���Ϊ��ǰ�к�
				else
				{
					counts1[i][cnt][1] = j;
				}
			}
			//�����ǰ���Ų��� # �������ö�ͳ��
			else
			{
				cnt++;
			}
		}
	}
	//����ͳ�����ݣ�ɸѡ����ҪӮ�� # �Σ�����Ϊʤ��������һ�������������Ż�������������Ϊ4
	//����ÿһ��
	for (i = 0; i < h; i++)
	{
		int j = 0;
		//������ǰ�е����� # �Σ��������� # �γ���
		for (j = 0; j < W; j++)
		{
			// # �ε���ʼλ�����겻�� -1 �������
			//��������� # ���� = ʤ��������һ����������ӵ���ѡλ��
			int length = counts1[i][j][1] - counts1[i][j][0] + 1;
			if (counts1[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//���* �ε���಻���ߣ��Լ� * ����˵�����λ��û�����ӣ��򽫸�����λ��������ӵ���ѡλ��
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
				//��� * �ε��Ҳ಻���ߣ����� * �ε��Ҷ˵�����λ��û�����ӣ��򽫸�����Ϊֵ������ӵ���ѡλ��
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

	//ɨ��ÿһ��
	//ÿһ�������H�� # �Σ�Ҳ���ǣ�����������ô��⣬ֻ�ܹ�C�������鲻�Ǳ䳤�ģ�Ҳ����������Ϊ��û��ѧ���ⲿ�֣�
	int counts2[W][H][2];//��һά���кţ��ڶ�ά�������� # ����������ά��ÿ�ε���ֹλ�ã��кţ�
	memset(counts2, -1, sizeof(counts2));//��������Ԫ�ظ���ֵΪ-1
	for (i = 0; i < w; i++)
	{
		int j = 0;
		int cnt = 0;
		for (j = 0; j < h; j++)
		{
			//�����ǰλ��Ϊ # �ţ�ͳ�Ƹö�
			if (board[j][i] == '#')
			{
				//�����ǰ # ����ʼλ��Ϊ -1����ʾ��ǰ # �λ�û�� # �ţ�����ֹλ������Ϊ��ǰ�к�
				if (counts2[i][cnt][0] == -1)
				{
					counts2[i][cnt][0] = j;
					counts2[i][cnt][1] = j;
				}
				//�����ǰ���Ѿ�ͳ���� # �ţ�����ֹλ�ø���Ϊ��ǰ�к�
				else
				{
					counts2[i][cnt][1] = j;
				}
			}
			//�����ǰλ��Ϊ���� # �ţ���������ǰ�ε�ͳ��
			else
			{
				cnt++;
			}
		}
	}
	//����ÿ�� # �ε�ͳ����ֹλ�ã�ɸѡ���������Ҫ��� # ��
	//����ÿһ��
	for (i = 0; i < w; i++)
	{
		int j = 0;
		//������ǰ�е����� # �Σ��������� # �γ���
		for (j = 0; j < H; j++)
		{
			// # �ε���ʼλ�����겻�� -1 �������
			//��ǰ�����Ҫ��Ϊ # �γ���Ϊʤ��������һ
			int length = counts2[i][j][1] - counts2[i][j][0] + 1;
			if (counts2[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//�����ǰ * �ε��϶˲����ߣ����϶�������λ��û�����ӣ�����Ӹ�����λ��Ϊ��ѡλ��
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
				//�����ǰ * �ε��¶˲����ߣ����¶�������λ��û�����ӣ�����Ӹ�����λ��Ϊ��ѡλ��
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

	//ȷ��б��������
	//б����������ж����㷨�Ƚϸ��ӣ�Ŭ��ע�����

	//�ж���б����
	//counts3����һά����б�����������Ŀ���ο�����IsWin()�����ڶ�ά�����������α���ĸ�����ȡ��м������ĸ�������
	//����ά����ֹλ�õ����꣬ǰ������������ʼλ�����꣬��������������ֹλ�õ�����
	int counts3[H + W - 1][min(H, W)][4];
	memset(counts3, -1, sizeof(counts3));//�Ƚ�counts3������Ԫ�ظ�ֵΪ-1
	//��Ϊ������������ֻ��ͳ��һ������б�ŵ����ÿ���߶���Ҫ����ͳ��ÿ�� # �εĳ��ȣ�
	//����ʹ�������ʾ��ÿ�����ֱ�ʾÿ������ǰ # �εĳ���
	int cnts1[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//��ǰλ��Ϊ # �ŵ������
			if (board[i][j] == '#')
			{
				//�����λ����������ĵ�ǰ # ����ֹλ������Ϊ-1����ʾ��ǰ�λ�û�� # �ţ�������ֹλ������Ϊ��ǰλ������
				if (counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] == -1)
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][0] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][1] = j;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
				//�����ǰ���Ѿ����� # �ţ�����ֹλ���������Ϊ��ǰλ������
				else
				{
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][2] = i;
					counts3[i - j + (w - 1)][cnts1[i - j + (w - 1)]][3] = j;
				}
			}
			//�����ǰλ�ò��� # �ţ���������ǰ�β�ͳ��
			else
			{
				cnts1[i - j + (w - 1)]++;
			}
		}
	}
	//����ͳ�Ƶõ�����ֹλ�����꣬ɸѡ�������Ҫ��� # ��
	//����ÿ����б��������
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//����ÿ����б�����ϵ� # ��
		for (j = 0; j < min(H, W); j++)
		{
			// # �ε���ʼλ�����겻�� -1 �������
			//�����ǰ # �γ���������س���Ҫ��
			int length = counts3[i][j][2] - counts3[i][j][0] + 1;
			if (counts3[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//������϶˲����ߣ��������϶�������λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
				//������¶˲����ߣ��� * �����¶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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

	//�жϷ�б����
	//counts4����һά�Ƿ�б�����������Ŀ���ο�����IsWin()�����ڶ�ά�����������α���ĸ�����ȡ��м������ĸ�������
	//����ά����ֹλ�õ����꣬ǰ������������ʼλ�����꣬��������������ֹλ�õ�����
	int counts4[H + W - 1][min(H, W)][4];
	memset(counts4, -1, sizeof(counts4));//�Ƚ�counts4������Ԫ�ظ�ֵΪ-1
	//��Ϊ������������ֻ��ͳ��һ������б�ŵ����ÿ���߶���Ҫ����ͳ��ÿ�� # �εĳ��ȣ�
	//����ʹ�������ʾ��ÿ�����ֱ�ʾÿ������ǰ # �εĳ���
	int cnts2[H + W - 1] = { 0 };
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//�����ǰλ��Ϊ # ��
			if (board[i][j] == '#')
			{
				//�����λ�����ڵķ�б�����ϵ�ǰ # ����ֹλ������Ϊ-1����ʾ�� # �λ�û��ͳ�Ƶ� # �ţ�
				//���Խ��� # �ε���ֹλ����������Ϊ��ǰλ������
				if (counts4[i + j][cnts2[i + j]][2] == -1)
				{
					counts4[i + j][cnts2[i + j]][0] = i;
					counts4[i + j][cnts2[i + j]][1] = j;
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
				//����� # ���Ѿ��� # �ţ��������ֹλ������Ϊ��ǰλ������
				else
				{
					counts4[i + j][cnts2[i + j]][2] = i;
					counts4[i + j][cnts2[i + j]][3] = j;
				}
			}
			//�����ǰλ�ò��� # �ţ���������ǰ # �Σ���ͳ��
			else
			{
				cnts2[i + j]++;
			}
		}
	}

	//����ͳ�Ƶõ�����ֹλ�����꣬ɸѡ�������Ҫ��� # ��
	//����ÿ����б��������
	for (i = 0; i < w + h - 1; i++)
	{
		int j = 0;
		//����ÿ����б�����ϵ� # ��
		for (j = 0; j < min(H, W); j++)
		{
			// # �ε���ʼλ�����겻�� -1 �������
			//�����ǰ # �γ���������س���Ҫ��
			int length = counts4[i][j][2] - counts4[i][j][0] + 1;
			if (counts4[i][j][0] != -1 && length >= M)
			{
				int priority = N - length - 1;
				//����C�����е����鲻�Ǳ䳤�ģ�ֻ�ܸ������ȣ�����Ҫ����cntALL�Ĵ�СΪ���鳤�ȣ���ֹ����Խ��
				for (int k = 0; k < N - M; k++)
				{
					if (cntAll[k] > S)
					{
						goto Final;
					}
				}
				//������϶˲����ߣ������϶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
				//������¶˲����ߣ������϶�����λ��û�����ӣ��򽫸�����λ����ӵ���ѡλ��
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
	//�������ɸѡ�����λ������
	for (i = 0; i < N - M; i++)
	{
		//ͨ����С����������ȼ������Կ���ѡλ�ð������ȼ�˳��
		if (cntAll[i] > 0)
		{
			//����Щ���������ѡ��һ���������� #
			int idx = rand() % cntAll[i];
			//ǰ���������꣬���һ�������ȼ�
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

//��������
void ComputerMove(char board[H][W], int h, int w)
{
	printf("����������......\n");
	Sleep(1000);
	//�������ܶ½ع���
	//AICut��������һ�����������������ֵ�����
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
				//���û������ɸѡ�����꣬�������������
				//���걻������������
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

//�ж��Ƿ�ƽ��
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

//�ж���Ӯ
/*�жϹ���
	�У�ÿһ��������*����#�ĸ����Ƿ�ﵽʤ�������ĸ���
	�У�ÿһ��������*����#�ĸ����Ƿ�ﵽʤ�������ĸ���
	��б�����ж�ÿһ����б������������ * ���� # �ĸ����Ƿ�ﵽʤ�������ĸ���
		������֪����б�������ܹ��� W+H-1 ���ߣ�����ÿһ�����ϵ����������x - y �ǹ̶��ģ�
		���ҷ����ټ��� w - 1 ֮�󣬸պ���һ�� 0 ~ w + h - 2 �����У����ǣ���������һ����ά���飬
		����ͳ�ƶ���˫����б�������������ӵĸ�����counts1[W + H - 1][2],��һά��ʾ��б�����ÿһ���ߣ�
		���ҷ��ֵ�һά���±�պ��� x - y + w - 1 ��ֵһһ��Ӧ���������ͳ�ƣ��ոպã��ڶ�ά��������
		�ֱ��ʾ * ���������� # ��������
	��б�����ж�ÿһ����б������������ * ���� # �ĸ����Ƿ�ﵽʤ�������ĸ���
		������֪����б�������ܹ��� W+H+1 ���ߣ�����ÿһ�����ϵ�����λ������� x + y �ǹ̶��ģ�
		���Ҹպ���һ�� 0 ~ w + h - 2 �����У����ǣ���������һ����ά���飬����ͳ�ƶ���˫����б�����ϵ�
		�������ӵĸ�����counts2[W + H - 1][2]����һά��ʾ��б�����ϵ�ÿһ�����򣬲��ҵ�һά���±�պ���
		x + y һһ��Ӧ���������ͳ�Ƹպã��ڶ�ά�������ݷֱ��ʾ * �ŵ��������� # �ŵ�������
*/
char IsWin(char board[H][W], int h, int w)
{
	int i = 0;
	//�ж�ÿһ����û�л�ʤ��
	for (i = 0; i < h; i++)
	{
		//ÿһ���ȰѼ���������
		int countP = 0;//ͳ���������������
		int countC = 0;//ͳ�Ƶ�������������
		int j = 0;
		for (j = 0; j < w; j++)
		{
			//�����ǰ����*�ţ���*��������������Ϊ0
			if (board[i][j] != '*')
			{
				countP = 0;
			}
			else
			{
				//��ǰ��*�ţ���*�ż�����+1
				countP++;
				//�ж�������*���Ƿ�����ʤ��Ҫ�����ǣ��򷵻����ʤ����־��*��
				if (countP >= N)
				{
					return '*';
				}
			}
			//�����ǰ����#�ţ���#��������������Ϊ0
			if (board[i][j] != '#')
			{
				countC = 0;
			}
			else
			{
				//��ǰ��#�ţ���#�ż�����+1
				countC++;
				//�ж�������#���Ƿ�����ʤ��Ҫ�����ǣ��򷵻ص���ʤ����־��#��
				if (countC >= N)
				{
					return '#';
				}
			}
		}
	}

	//�ж�ÿһ���Ƿ��л�ʤ��
	for (i = 0; i < w; i++)
	{
		//ÿһ���ȰѼ���������
		int countP = 0;//ͳ���������������
		int countC = 0;//ͳ�Ƶ�������������
		int j = 0;
		for (j = 0; j < h; j++)
		{
			//�����ǰ����*�ţ���*��������������Ϊ0
			if (board[j][i] != '*')
			{
				countP = 0;
			}
			else
			{
				//��ǰ��*�ţ���*�ż�����+1
				countP++;
				//�ж�������*���Ƿ�����ʤ��Ҫ�����ǣ��򷵻����ʤ����־��*��
				if (countP >= N)
				{
					return '*';
				}
			}
			//�����ǰ����#�ţ���#��������������Ϊ0
			if (board[j][i] != '#')
			{
				countC = 0;
			}
			else
			{
				//��ǰ��#�ţ���#�ż�����+1
				countC++;
				//�ж�������#���Ƿ�����ʤ��Ҫ�����ǣ��򷵻ص���ʤ����־��#��
				if (countC >= N)
				{
					return '#';
				}
			}
		}
	}

	//�ж�б�ŵ���û��ʤ����
	//ͳ����б����������Ӹ�������һά��ʾ���е����������ڶ�ά��ʾ��һ������ʾ��ң��ڶ�������ʾ����
	int counts1[W + H - 1][2] = {0};
	//ͳ�Ʒ�б�ĸ������Ӹ�������һά��ʾ�ܹ������������ڶ�ά��ʾ��һ������ʾ��ң��ڶ�������ʾ����
	int counts2[W + H - 1][2] = {0};
	for (i = 0; i < h; i++)
	{
		int j = 0;
		for (j = 0; j < w; j++)
		{
			if (board[i][j] != '*')
			{
				//�����ǰ���Ų��� * �����Ӧ�����������ļ�������Ϊ0
				counts1[i - j + (w - 1)][0] = 0;
				counts2[i + j][0] = 0;
			}
			else
			{
				//�����ǰ����Ϊ *�����Ӧ����ļ�����+1
				counts1[i - j + (w - 1)][0]++;
				counts2[i + j][0]++;
			}
			//ͳ�� # �ķ�����ͳ�� * �ķ�����ͬ
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
			//����ÿ������� * �� # �ĸ����ж��Ƿ��Ӧ����ʤ��
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
	//������̱�ռ������δ����ʤ����Ϊƽ��
	if (IsFull(board, h, w) == 1)
	{
		return 'P';
	}
	//���û��ʤ����Ҳû��ƽ�֣����������
	return 'C';
}