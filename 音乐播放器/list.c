#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <io.h>
#include"play.h"
#include"list.h"

char path_list[150] = "mediaList.txt";

//��ȡָ���ļ��е��û���Ϣ�����������Ϣ���浽����
struct list* pre_list() {
	FILE* fp;

	fp = fopen(path_list, "r");  //���ļ� 
	if (fp == NULL)
	{
		face_fileFailure();//����ļ���ʧ�ܣ�\n
		return NULL;
	}

	struct list* head, * p, * q;
	int number = 1;//��¼�赥����

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

//����赥��ţ�����ָ���Ӧ�赥��Ϣ��ָ��
struct list* getChoice_list(struct list* head)//���������ţ�����ָ���Ӧ������Ϣ��ָ��
{
	int choice_list;
	int flag_list = 0;//1��ʾ�ɹ������˸������
	struct list* p = head->next;

	printf("\t\t\t\t������赥���");
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
		printf("\t\t\t\t�����ڣ�����������");
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

//��ָ���赥�еĸ�����Ϣ���������У������������ͷ�ڵ�
struct media* loadMedia(struct list* p0) {

	FILE* fp;
	char path[150];

	strcpy(path, p0->name);

	fp = fopen(path, "r");  //���ļ� 
	if (fp == NULL)
	{
		face_fileFailure();//����ļ���ʧ�ܣ�\n
		return NULL;
	}

	struct list* head, * p, * q;
	int number = 1;//��¼��������

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