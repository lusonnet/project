#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initboard(char board[ROWS][COLS],int rows,int cols,char set)//����Ҫ�������ֿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//��ʼ��
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	printf("-------ɨ����Ϸ-------\n");
	int i = 0;
	int j = 0;
	//Ϊ�˷���ѡ��λ�����ǻ���Ҫ��ӡ���
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------ɨ����Ϸ-------\n");
}

void layoutbomb(char mine[ROWS][COLS], int row, int col)//������
{
	int count = BOMB_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int around_count(char mine[ROWS][COLS],int x,int y)
{
	int count = 0;
	if (mine[x - 1][y - 1] == '1')
		count++;
	if (mine[x - 1][y] == '1')
		count++;
	if (mine[x - 1][y + 1] == '1')
		count++;
	if (mine[x][y - 1] == '1')
		count++;
	if (mine[x][y + 1] == '1')
		count++;
	if (mine[x + 1][y - 1] == '1')
		count++;
	if (mine[x + 1][y] == '1')
		count++;
	if (mine[x + 1][y + 1] == '1')
		count++;
	return count;
}
//void openboard(char mine[ROWS][COLS],char show[ROWS][COLS],int x, int y)
//{
//	if (mine[x - 1][y - 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x - 1,y - 1);
//	if (mine[x - 1][y] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x - 1, y);
//	if (mine[x - 1][y + 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x - 1, y + 1);
//	if (mine[x][y - 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x , y - 1);
//	if (mine[x][y + 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x , y + 1);
//	if (mine[x + 1][y - 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x + 1, y - 1);
//	if (mine[x + 1][y] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x + 1, y );
//	if (mine[x + 1][y + 1] == '0');
//		show[ROWS][COLS] = around_count(mine[ROWS][COLS], x + 1, y + 1);
//}

void finebomb(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- BOMB_COUNT)
	{
		printf("������Ҫ�Ų��׵�����(x y):>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)//�ж�����Ϸ���
		{
			if (mine[x][y] == '1')//����
			{
				printf("��ȵ����ˣ���Ϸʧ��\n");
				break;
			}
			else
			{
				int count = around_count(mine, x, y);//����������ΧһȦ�ж��ٸ���
				show[x][y] = count + '0';//ת�����ַ��������ӡ
				Displayboard(show, row, col);
				//openboard(mine, show,  x, y);
				win++;
			}
		}
		else
		{
			printf("�������������ѡ��>");
		}

	}
	if (win == row * col - BOMB_COUNT)
	{
		printf("��ϲ�㣬������ȷ\n");
		Displayboard(mine, ROW, COL);
	}
}

