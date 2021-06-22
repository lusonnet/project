#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define PASSWORD 123456//通行码


typedef struct EN//存用户和密码 
{
	char username[20];
	char passworld[20];
}EN;

typedef struct FOOD//食物
{
	char name[20];//菜品名
	float price;//菜品价格
	struct FOOD* next;
	int num;//菜品序号
}FOOD;

int Choice()//选择函数
{
	int choice;
	printf("请选择：>");
	scanf("%d", &choice);
	return choice;
}

void enter();//空函数

void Primarymenu()
{
	printf("----欢迎来到餐厅管理系统----\n");
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

void allowMenu()
{
	printf("--------1.增加菜品----------\n");
	printf("--------2.删除菜品----------\n");
	printf("--------3.查询菜品----------\n");
	printf("--------4.修改菜品价格----------\n");
}

int main()
{
	int choice;

	do
	{
		Primarymenu();//选择身份 - 1.管理员2.用户
		choice = Choice();
		switch (choice)
		{
		case 1://管理员
		{
			char allow[10];
			printf("请输入验证码：>");
			scanf("%s", allow);
			if (strcmp(allow, "PASSWORD"))//通行码错误则进入函数
			{
				printf("通行码错误-_-\n");
				enter();
			}
			printf("\t");
			allowMenu();//增删查改
			choice = Choice();
			switch(choice)
			{
			case 1: {//增加菜品

			}
				

			}
		}
		}
	} while (choice);
}