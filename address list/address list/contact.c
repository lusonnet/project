#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InnitContact(Contact* pc)
{
	//pc->data = 0;
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}

void Add(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满。无法添加\n");
		return;
	}
	printf("请输入名字、性别、年龄、号码、地址：\n");
	scanf("%s %s %d %s %s", pc->data[pc->sz].name,
							pc->data[pc->sz].sex,
							&pc->data[pc->sz].ago,
							pc->data[pc->sz].tele,
							pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n");

}

void Print(const Contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%s %s %d %s %s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].ago,
			pc->data[i].tele,
			pc->data[i].addr
		);
	}
}

int Findbyname(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return - 1;
}

void Del(Contact* pc)
{
	char name[MAX_NAME];
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要删除人的名字：");
	scanf("%s", name);
	int pos = Findbyname(pc,name);//判断该人是否存在,存在 - 1，不存在 - -1
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		for (int i = pos; i < pc->sz-1 ; i++)
		{
			pc->data[i] = pc->data[i+1];
		}
		
	}
	pc->sz--;
	printf("删除成功\n");
}

void Search(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);//判断该人是否存在,存在 - 1，不存在 - -1
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		printf("%s %s %d %s %s", pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].ago,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("删除成功\n");
	}
}

void Change(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入修改人的名字：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);//判断该人是否存在,存在 - 1，不存在 - -1
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字、性别、年龄、号码、地址：\n");
		scanf("%s %s %d %s %s", pc->data[pos].name,
			pc->data[pos].sex,
			&pc->data[pos].ago,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("修改成功\n");
	}

}

void Sort(Contact* pc)
{

}