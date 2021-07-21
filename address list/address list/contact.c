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
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("���������֡��Ա����䡢���롢��ַ��\n");
	scanf("%s %s %d %s %s", pc->data[pc->sz].name,
							pc->data[pc->sz].sex,
							&pc->data[pc->sz].ago,
							pc->data[pc->sz].tele,
							pc->data[pc->sz].addr);
	pc->sz++;
	printf("���ӳɹ�\n");

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
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ���˵����֣�");
	scanf("%s", name);
	int pos = Findbyname(pc,name);//�жϸ����Ƿ����,���� - 1�������� - -1
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
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
	printf("ɾ���ɹ�\n");
}

void Search(Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�");
	scanf("%s", name);
	int pos = Findbyname(pc, name);//�жϸ����Ƿ����,���� - 1�������� - -1
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		printf("%s %s %d %s %s", pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].ago,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("ɾ���ɹ�\n");
	}
}

void Change(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("�������޸��˵����֣�");
	scanf("%s", name);
	int pos = Findbyname(pc, name);//�жϸ����Ƿ����,���� - 1�������� - -1
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("���������֡��Ա����䡢���롢��ַ��\n");
		scanf("%s %s %d %s %s", pc->data[pos].name,
			pc->data[pos].sex,
			&pc->data[pos].ago,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}

}

void Sort(Contact* pc)
{

}