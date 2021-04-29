#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initboard(char board[ROWS][COLS],int rows,int cols,char set)//函数要满足两种可能性
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//初始化
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	printf("-------扫雷游戏-------\n");
	int i = 0;
	int j = 0;
	//为了方便选择方位，我们还需要打印序号
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
	printf("-------扫雷游戏-------\n");
}

void layoutbomb(char mine[ROWS][COLS], int row, int col)//布置雷
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
		printf("请输入要排查雷的坐标(x y):>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)//判断坐标合法性
		{
			if (mine[x][y] == '1')//是雷
			{
				printf("你踩到雷了，游戏失败\n");
				break;
			}
			else
			{
				int count = around_count(mine, x, y);//计算坐标周围一圈有多少个雷
				show[x][y] = count + '0';//转换成字符，方便打印
				Displayboard(show, row, col);
				//openboard(mine, show,  x, y);
				win++;
			}
		}
		else
		{
			printf("坐标错误，请重新选择>");
		}

	}
	if (win == row * col - BOMB_COUNT)
	{
		printf("恭喜你，排雷正确\n");
		Displayboard(mine, ROW, COL);
	}
}

