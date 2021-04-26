#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()//要放在main函数之前
{
	char board[ROW][COL];
	Initboard(board, ROW, COL);//初始化棋盘
	//打印棋盘
	Displayboard(board, ROW, COL);
	char ret = 0;
	
	while (1)
	{
		//玩家
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);

		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑
		Compumove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("恭喜你，你赢了\n！");
	}
	else if (ret == '#')
	{
		printf("震惊！电脑居然打败了你\n");
	}
	else
	{
		printf("你们打平了！\n");
	}
	Displayboard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新选择：>\n");
			break;
		}
	} while (input);
	return 0;
}

