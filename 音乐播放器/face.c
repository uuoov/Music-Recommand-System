#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <mmsystem.h>
#include"play.h"
#include"user.h"
#include"list.h"


<<<<<<< HEAD
extern char filepath2[100] = "C:\\Users\\m1342\\Music\\";
=======
extern char filepath2[100] ="C:\\Users\\m1342\\Music\\";
>>>>>>> dd859500d5116c2e1f8a968c3479419e0b9f4d4f

int face_user();
int face_play();

int face_user() {
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("\n\n\n");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U         __  _______ _____                                 �U\n");
	printf("\t\t\t\t�U        /  |/  / __ \\   /                                  �U\n");
	printf("\t\t\t\t�U       / /|_/ / /_/ //_ <                                  �U\n");
	printf("\t\t\t\t�U      / /  / / ____/__/ /                                  �U\n");
	printf("\t\t\t\t�U     /_/__/_/_/    /___/ ____________                      �U\n");
	printf("\t\t\t\t�U     / __ \\/ /   /   \\ \\/ / ____/ __ \\                     �U\n");
	printf("\t\t\t\t�U    / /_/ / /   / /| |\\  / __/ / /_/ /                     �U\n");
	printf("\t\t\t\t�U   / ____/ /___/ ___ |/ / /___/ _, _/                      �U\n");
	printf("\t\t\t\t�U  /_/   /_____/_/  |_/_/_____/_/ |_|     1.0  Ver          �U\n");
	printf("\t\t\t\t�U                                                           �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	int a;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                                           �U\n");
	printf("\t\t\t\t�U              *1.��¼           *2.ע��                    �U\n");
	printf("\t\t\t\t�U                                                           �U\n");
	printf("\t\t\t\t�U              *0.�˳�                                      �U\n");
	printf("\t\t\t\t�U                                                           �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t\t ");
	scanf("%d", &a);
	return a;
}

//����������
int face_play(struct media* p0) {


	system("CLS");
	struct media* p = p0;
	int a;

	int LENGTH = 50;//����������
	int MinTens_cur = 0, MinOnes_cur = 0, SecTens_cur = 0, SecOnes_cur = 0;
	int MinTens_total = 0, MinOnes_total = 0, SecTens_total = 0, SecOnes_total = 0;

	char st1[50] = { '\0' };
	char st2[50] = { '\0' };
	char file1[50] = "status ";
	char file2[50] = " length";
	char text1[50] = "status ";
	char text2[50] = " position";
	char cmd[100] = { '\0' };

	int length = 0;//�洢����ʱ��
	int current = 0;//�洢������ǰ����λ��

	sprintf(cmd, "%s%s", filepath2, p->name);
	strcat(file1, cmd);
	strcat(file1, file2);

	mciSendString(file1, st1, 50, 0);

	length = atoi(st1);

	MinTens_total = length / 600000;
	MinOnes_total = (length / 60000) % 10;
	SecTens_total = ((length / 1000) % 60) / 10;
	SecOnes_total = ((length / 1000) % 60) % 10;

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st2, 50, 0);
	current = atoi(st2);

	while (!(kbhit()))
	{
		mciSendString(text1, st2, 50, 0);
		current = atoi(st2);
		MinTens_cur = current / 600000;
		MinOnes_cur = (current / 60000) % 10;
		SecTens_cur = ((current / 1000) % 60) / 10;
		SecOnes_cur = ((current / 1000) % 60) % 10;

		printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *1.��ͣ/����              *2.ѡ������                       �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *3.��һ��                 *4.��һ��                         �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *5.����-                  *6.����+                          �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *7.���                   *8.����                           �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *9.չʾ�赥               *0.������һ��                     �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\n\n\t\t\t\t %d%d:%d%d/%d%d:%d%d  ",
			MinTens_cur, MinOnes_cur, SecTens_cur, SecOnes_cur,
			MinTens_total, MinOnes_total, SecTens_total, SecOnes_total);
		for (int j = 0; j <= LENGTH * current / length; j++) {
			printf("�T");
		}

		Sleep(1000);
		system("cls");
	}
	return getch() - 48;

}

void face_fileFailure() {
	system("CLS");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                 �ļ���ʧ�ܣ�                �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	return;
}

void face_userNotFound() {
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                 �Ҳ������û���                �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	Sleep(3000);
	return;
}

void face_passwordWrong() {
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                    �������                 �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	Sleep(3000);
}

void face_welcome(struct user* p) {
	system("CLS");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                   ��ӭ%-5s��                 �U\n", p->account);
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}

char* input_AC() {
	char account[100];
	system("CLS");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                �����������û�����             �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t\t ");
	scanf("%s", account);
	return account;
}

char* input_re_AC() {
	char account[100];
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U      �û����Ѵ��ڣ����������������û�����     �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t\t ");
	scanf("%s", account);
	return account;
}

char* input_PW() {
	char password[100];
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                 �������������룺              �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t\t ");
	scanf("%s", password);
	return password;
}

void face_newACsuc() {
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                   ע��ɹ���                  �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	Sleep(3000);
	return;
}

void listMedia(struct media* head) {
	struct media* p = head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                               �U\n");
	while (p != NULL)
	{
		printf("\t\t\t\t�U   \t*����%1d����������Ŀ%-10s\t    \t�U\n", p->num, p->name);
		p = p->next;
	}//��������е�ȫ����Ϣ
	printf("\t\t\t\t�U                                               �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}

void listSongList(struct list* head) {
	struct list* p = head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                               �U\n");
	while (p != NULL)
	{
		//printf("\t\t\t\t�U   \t*����%1d����չʾ�赥%-20s\t    \t�U\n", p->num, p->name);
		printf("\t\t\t\t�U   \t*����%1d����չʾ�赥\t    \t�U\n", p->num);
		p = p->next;
	}//��������е�ȫ����Ϣ
	printf("\t\t\t\t�U                                               �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}