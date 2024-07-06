#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <io.h>
#include"play.h"
#pragma comment(lib,"winmm.lib")

//  "C:\Users\m1342\Music\��;����.mp3"
char filepath[100] = "C:\\Users\\m1342\\Music\\";//����MP3�ļ���Ŀ¼��������mciSendString��������ָ��
char catalog[150] = "C://Users//m1342//Music";  //����MP3�ļ���Ŀ¼�����ڶ�ȡָ���ļ����е��ļ�
char type[20] = "mp3";//�ļ�����

//����
void play(struct media* p0)
{
	char cmd[100];
	char file[100] = "open ";
	char play[100] = "play ";
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	printf("%s", cmd);
	strcat(file, cmd);
	strcat(play, cmd);
	mciSendString(file, NULL, 0, NULL);
	mciSendString(play, NULL, 0, NULL);
}

//��ȡ��һ�׸��ָ��
struct media* getNext(struct media* p0, struct media* head)
{
	struct media* p = NULL;
	if (p0->next == NULL) {
		p = head->next;
	}
	else {
		p = p0->next;
	}
	return p;
}

//��ȡ��һ�׸��ָ��
struct media* getLast(struct media* p0, struct media* head)
{
	struct media* p = head->next;
	while (p != NULL) {
		if (p->next == p0) {
			return p;
		}
		p = p->next;
	}
	if (p == NULL) {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		return p;
	}
}

//��ͣ����
void pause(struct media* p0)
{
	char cmd[100];
	char file[100] = "pause ";
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	strcat(file, cmd);
	mciSendString(file, NULL, 0, NULL);
}

//��������
void continue_play(struct media* p0)
{
	char cmd[100];
	char file[100] = "resume ";
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	strcat(file, cmd);
	mciSendString(file, NULL, 0, NULL);
}

//��ȡ�����Ĳ���״̬
char* getState(struct media* p0)
{
	char state[20];
	char cmd[100] = "status ";
	strcat(cmd, filepath);
	strcat(cmd, p0->musicName);
	strcat(cmd, " mode");
	mciSendString(cmd, state, 20, 0);
	return state;
}

//���Ż���ͣ
void switchPlay(struct media* p0)
{
	struct media* p = p0;
	struct media* p2 = p0;
	int a;
	char state[20];
	strcpy(state, getState(p));
	if (strcmp(state, "playing") == 0) {
		pause(p);
	}
	else if (strcmp(state, "paused") == 0) {
		continue_play(p);
	}
	else if (strcmp(state, "stopped") == 0) {
		stop(p);
		play(p);
	}
	else {
		printf("ERROR!\n");
	}
}

//ֹͣ����
void stop(struct media* p0)
{
	char cmd[100];
	char file[100] = "close ";
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	strcat(file, cmd);
	mciSendString(file, NULL, 0, NULL);
}

//��������
void volumeDown(struct media* p0)
{
	char res[260];
	char cmd[100];
	char file1[100] = "status ";
	char file2[100] = " volume";
	char text1[100] = "setaudio ";
	char text2[100] = " volume to ";
	char vo[20];
	int a;
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	strcat(file1, cmd);
	strcat(file1, file2);
	mciSendString(file1, res, 260, NULL);
	int  volume = 0;
	volume = atoi(res);
	volume -= 200;
	itoa(volume, vo, 10);
	strcat(text1, cmd);
	strcat(text1, text2);
	strcat(text1, vo);
	mciSendString(text1, NULL, 0, NULL);
}

//��������
void volumeUp(struct media* p0)
{
	char res[260];
	char cmd[100];
	char file1[100] = "status ";
	char file2[100] = " volume";
	char text1[100] = "setaudio ";
	char text2[100] = " volume to ";
	char vo[20];
	int a;
	sprintf(cmd, "%s%s", filepath, p0->musicName);
	strcat(file1, cmd);
	strcat(file1, file2);
	mciSendString(file1, res, 260, NULL);
	int  volume = 0;
	volume = atoi(res);
	volume += 200;
	itoa(volume, vo, 10);
	strcat(text1, cmd);
	strcat(text1, text2);
	strcat(text1, vo);
	mciSendString(text1, NULL, 0, NULL);
}

//��ȡָ���ļ����е�MP3�ļ������Ѹ��������Ϣ���浽����
struct media* pre_media()
{
	struct media* head, * p, * q;
	int number = 1;//��¼MP3�ļ�����

	head = (struct media*)malloc(sizeof(struct media));
	head->next = NULL;
	p = (struct media*)malloc(sizeof(struct media));

	long handle;    //���
	struct _finddata_t fileinfo;   //�ļ���Ϣ�ṹ��

	char search[150];  //�����ҵ��ļ���֧��ͨ���
	strcpy(search, catalog);
	strcat(search, "\\\\*.");
	strcat(search, type);  // search = C:/Users/�����/Music/*.mp3

	handle = _findfirst(search, &fileinfo);    //��һ�β���
	if (-1 == handle)
	{
		printf("δ�ҵ������ļ���\n");
		return head;
	}

	strcpy(p->musicName, fileinfo.name);
	p->num = number;
	head->next = p;
	while (!_findnext(handle, &fileinfo)) //ѭ�������������ϵ��ļ���ֱ���Ҳ���������Ϊֹ
	{
		number++;
		q = (struct media*)malloc(sizeof(struct media));
		strcpy(q->musicName, fileinfo.name);
		q->num = number;
		q->next = NULL;
		p->next = q;
		p = q;
	}//����������ӵ�ǰ���ҵ���MP3�ļ�
	_findclose(handle); //�رվ��

	return head;
}

//���������ţ�����ָ���Ӧ������Ϣ��ָ��
struct media* getChoice_media(struct media* head)
{
	int choice_media;
	int flag_media = 0;//1��ʾ�ɹ������˸������
	struct media* p = head->next;

	printf("\t\t\t\t������������");
	scanf("%d", &choice_media);
	while (p != NULL) {
		if (p->num == choice_media) {
			flag_media = 1;
			break;
		}
		p = p->next;
	}

	while (flag_media == 0) {
		p = head->next;
		printf("\t\t\t\t�����ڣ�����������");
		scanf("%d", &choice_media);
		while (p != NULL) {
			if (p->num == choice_media) {
				flag_media = 1;
				break;
			}
			p = p->next;
		}
	}
	return p;
}

//���15��
void goAhead15(struct media* p0)
{
	int position;
	char cmd[100];
	char file1[100] = "seek ";
	char file2[100] = " to ";
	char file3[100];
	char text1[100] = "status ";
	char text2[100] = " position";
	char st[100];
	char word1[100] = "play ";

	sprintf(cmd, "%s%s", filepath, p0->musicName);

	strcat(file1, cmd);
	strcat(file1, file2);

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st, 100, 0);

	position = atoi(st);
	position += 15000;
	itoa(position, file3, 10);
	strcat(file1, file3);
	mciSendString(file1, NULL, 0, NULL);

	strcat(word1, cmd);
	mciSendString(word1, NULL, 0, NULL);
}

//����15��
void drawBack15(struct media* p0)
{
	int position;
	char cmd[100];
	char file1[100] = "seek ";
	char file2[100] = " to ";
	char file3[100];
	char text1[100] = "status ";
	char text2[100] = " position";
	char st[100];
	char word1[100] = "play ";

	sprintf(cmd, "%s%s", filepath, p0->musicName);

	strcat(file1, cmd);
	strcat(file1, file2);

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st, 100, 0);

	position = atoi(st);
	position -= 15000;
	itoa(position, file3, 10);
	strcat(file1, file3);
	mciSendString(file1, NULL, 0, NULL);

	strcat(word1, cmd);
	mciSendString(word1, NULL, 0, NULL);
}