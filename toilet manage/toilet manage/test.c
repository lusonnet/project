#define _CRT_SECURE_NO_WARNINGS 1

typedef struct EN//存用户和密码 
{
	char userName1[10];
	char passWorld1[10];
}EN;

void Primarymenu()
{
	printf("----欢迎来到厕所管理系统----\n");
	printf("--------您的身份-----------\n");
	printf("--------1.管理员-----------\n");
	printf("--------2.用户-------------\n");
	printf("--------0.退出-------------\n");
	printf("---------------------------\n");
}

void secondMenu()
{
	printf("--------1.登录-------------\n");
	printf("--------2.注册-------------\n");
	printf("--------0.返回-------------\n");
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