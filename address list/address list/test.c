#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//创建通讯录
//初始化通讯录

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
	InnitContact(&con);//初始化
	menu();
	
	do
	{
		printf("请选择：");
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
			Sort(&con);//按年龄排序- 从小到大 从大到小
			break;
		case 6:
			Print(&con);
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("选择错误，请重新选择：");
			break;
		}
	} while (input);

}
