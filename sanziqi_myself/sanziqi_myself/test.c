#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()//Ҫ����main����֮ǰ
{
	char board[ROW][COL];
	Initboard(board, ROW, COL);//��ʼ������
	//��ӡ����
	Displayboard(board, ROW, COL);
	char ret = 0;
	
	while (1)
	{
		//���
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);

		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//����
		Compumove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬��Ӯ��\n��");
	}
	else if (ret == '#')
	{
		printf("�𾪣����Ծ�Ȼ�������\n");
	}
	else
	{
		printf("���Ǵ�ƽ�ˣ�\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��>\n");
			break;
		}
	} while (input);
	return 0;
}

