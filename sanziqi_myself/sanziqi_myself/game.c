#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("*******1.play     ********\n");
	printf("*******0.exit     ********\n");
	printf("**************************\n");
}

void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int	j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col -1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");

	while (1)
	{
		
		printf("请选择坐标:(x y):>");
		scanf("%d %d", &x, &y);
		//判断下标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = "*";
				break;
			}
			else
			{
				printf("此坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("此坐标非法，请重新输入\n");
		}
	}
}

void Compumove(char board[ROW][COL], int row, int col)
{

	printf("电脑走：>\n");
	while (1)
	{
		//获取随机下标
		int x = rand() % row;
		int y = rand() % col;

		//判断下标是否合法
		if (board[x][y] == ' ')
		{
			board[x][y] = "#";
			break;
		}
		
	}
}
int Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//判断三列
	for ( i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
	int ret = Isfull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}
