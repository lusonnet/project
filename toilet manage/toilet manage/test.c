#define _CRT_SECURE_NO_WARNINGS 1

typedef struct EN//���û������� 
{
	char userName1[10];
	char passWorld1[10];
}EN;

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

int main()
{
	int input;
	int choice;
	Primarymenu();
	scanf("%d", &input);
	do
	{

	} while (input);
}