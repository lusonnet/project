#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define PASSWORD 123456//ͨ����


typedef struct EN//���û������� 
{
	char username[20];
	char passworld[20];
}EN;

typedef struct FOOD//ʳ��
{
	char name[20];//��Ʒ��
	float price;//��Ʒ�۸�
	struct FOOD* next;
	int num;//��Ʒ���
}FOOD;

int Choice()//ѡ����
{
	int choice;
	printf("��ѡ��>");
	scanf("%d", &choice);
	return choice;
}

void enter();//�պ���

void Primarymenu()
{
	printf("----��ӭ������������ϵͳ----\n");
	printf("--------�������-----------\n");
	printf("--------1.����Ա-----------\n");
	printf("--------2.�û�-------------\n");
	printf("--------0.�˳�-------------\n");
	printf("---------------------------\n");
}

void secondMenu()
{
	printf("--------1.��¼-------------\n");
	printf("--------2.ע��-------------\n");
	printf("--------0.����-------------\n");
}

void allowMenu()
{
	printf("--------1.���Ӳ�Ʒ----------\n");
	printf("--------2.ɾ����Ʒ----------\n");
	printf("--------3.��ѯ��Ʒ----------\n");
	printf("--------4.�޸Ĳ�Ʒ�۸�----------\n");
}

int main()
{
	int choice;

	do
	{
		Primarymenu();//ѡ����� - 1.����Ա2.�û�
		choice = Choice();
		switch (choice)
		{
		case 1://����Ա
		{
			char allow[10];
			printf("��������֤�룺>");
			scanf("%s", allow);
			if (strcmp(allow, "PASSWORD"))//ͨ�����������뺯��
			{
				printf("ͨ�������-_-\n");
				enter();
			}
			printf("\t");
			allowMenu();//��ɾ���
			choice = Choice();
			switch(choice)
			{
			case 1: {//���Ӳ�Ʒ

			}
				

			}
		}
		}
	} while (choice);
}