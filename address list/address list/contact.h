#pragma once
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 50
#define MAX 1000

#include<string.h>
#include<stdio.h>
typedef struct People //������Ϣ
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int ago;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact//����ͨѶ¼
{
	PeoInfo data[MAX];
	int sz ;
}Contact;

void InnitContact(Contact* pc);
void Print(Contact* pc);
