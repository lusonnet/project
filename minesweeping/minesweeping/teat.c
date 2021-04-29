#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("*******  1.play   *******\n");
	printf("*******  0.exit   *******\n");
	printf("*************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	Initboard(mine, ROWS, COLS, '0');//
	Initboard(show, ROWS, COLS, '*');//玩家看到的是'*'

	//Displayboard(mine,ROW,COL);//打印棋盘 - 供测试
	Displayboard(show,ROW,COL);//只打印中间棋盘

	layoutbomb(mine, ROW, COL);//布置雷
	Displayboard(mine, ROW, COL);
	finebomb(mine,show,ROW, COL);//排查雷

}

int main()//与三子棋类似
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			printf("扫雷游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}