#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//����ͨѶ¼
//��ʼ��ͨѶ¼

void menu()
{
	printf("-----------------------------\n");
	printf("------- 1.add     2.del   ---\n");
	printf("------- 3.search  4.change---\n");
	printf("------- 5.sort    6.print ---\n");
	printf("------- 0.exit            ---\n");
	printf("-----------------------------\n");
}

int main()
{
	int input = 0;
	Contact con;
	InnitContact(&con);//��ʼ��
	menu();
	
	do
	{
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add(&con);
			break;
		case 2:
			Del(&con);
			break;
		case 3:
			Search(&con);
			break;
		case 4:
			Change(&con);
			break;
		case 5:
			Sort(&con);//����������- ��С���� �Ӵ�С
			break;
		case 6:
			Print(&con);
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}
	} while (input);

}
