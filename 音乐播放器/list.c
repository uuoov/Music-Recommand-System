#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <io.h>
#include"play.h"
#include"list.h"

char path_list[150] = "mediaList.txt";

//读取指定文件中的用户信息，并把相关信息储存到链表
struct list* pre_list() {
	FILE* fp;

	fp = fopen(path_list, "r");  //打开文件 
	if (fp == NULL)
	{
		face_fileFailure();//输出文件打开失败！\n
		return NULL;
	}

	struct list* head, * p, * q;
	int number = 1;//记录歌单个数

	head = (struct list*)malloc(sizeof(struct list));
	head->next = NULL;
	p = (struct list*)malloc(sizeof(struct list));

	fscanf(fp, "%s", p->name);
	p->num = number;
	head->next = p;

	while (!feof(fp)) {

		number++;
		q = (struct list*)malloc(sizeof(struct list));
		fscanf(fp, "%s", q->name);
		q->num = number;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	p = head->next;

	fclose(fp);

	return head;

}

//输入歌单编号，返回指向对应歌单信息的指针
struct list* getChoice_list(struct list* head)//输入歌曲编号，返回指向对应歌曲信息的指针
{
	int choice_list;
	int flag_list = 0;//1表示成功输入了歌曲编号
	struct list* p = head->next;

	printf("\t\t\t\t请输入歌单编号");
	scanf("%d", &choice_list);
	while (p != NULL) 
	{
		if (p->num == choice_list) 
		{
			flag_list = 1;
			break;
		}
		p = p->next;
	}

	while (flag_list == 0) 
	{
		p = head->next;
		printf("\t\t\t\t不存在！请重新输入");
		scanf("%d", &choice_list);
		while (p != NULL) 
		{
			if (p->num == choice_list) 
			{
				flag_list = 1;
				break;
			}
			p = p->next;
		}
	}
	return p;
}

//将指定歌单中的歌曲信息存入链表中，并返回链表的头节点
struct media* loadMedia(struct list* p0) {

	FILE* fp;
	char path[150];

	strcpy(path, p0->name);

	fp = fopen(path, "r");  //打开文件 
	if (fp == NULL)
	{
		face_fileFailure();//输出文件打开失败！\n
		return NULL;
	}

	struct list* head, * p, * q;
	int number = 1;//记录歌曲个数

	head = (struct media*)malloc(sizeof(struct media));
	head->next = NULL;
	p = (struct media*)malloc(sizeof(struct media));

	fscanf(fp, "%s", p->name);
	p->num = number;
	head->next = p;

	while (!feof(fp)) {

		number++;
		q = (struct list*)malloc(sizeof(struct list));
		fscanf(fp, "%s", q->name);
		q->num = number;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	p = head->next;

	fclose(fp);

	return head;
}