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
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	Initboard(mine, ROWS, COLS, '0');//
	Initboard(show, ROWS, COLS, '*');//��ҿ�������'*'

	//Displayboard(mine,ROW,COL);//��ӡ���� - ������
	Displayboard(show,ROW,COL);//ֻ��ӡ�м�����

	layoutbomb(mine, ROW, COL);//������
	Displayboard(mine, ROW, COL);
	finebomb(mine,show,ROW, COL);//�Ų���

}

int main()//������������
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			printf("ɨ����Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}