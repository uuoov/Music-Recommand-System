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
	printf("\t\t\t\t╔═══════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║         __  _______ _____                                 ║\n");
	printf("\t\t\t\t║        /  |/  / __ \\   /                                  ║\n");
	printf("\t\t\t\t║       / /|_/ / /_/ //_ <                                  ║\n");
	printf("\t\t\t\t║      / /  / / ____/__/ /                                  ║\n");
	printf("\t\t\t\t║     /_/__/_/_/    /___/ ____________                      ║\n");
	printf("\t\t\t\t║     / __ \\/ /   /   \\ \\/ / ____/ __ \\                     ║\n");
	printf("\t\t\t\t║    / /_/ / /   / /| |\\  / __/ / /_/ /                     ║\n");
	printf("\t\t\t\t║   / ____/ /___/ ___ |/ / /___/ _, _/                      ║\n");
	printf("\t\t\t\t║  /_/   /_____/_/  |_/_/_____/_/ |_|     1.0  Ver          ║\n");
	printf("\t\t\t\t║                                                           ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════════════════╝\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	int a;
	printf("\t\t\t\t╔═══════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                                           ║\n");
	printf("\t\t\t\t║              *1.登录           *2.注册                    ║\n");
	printf("\t\t\t\t║                                                           ║\n");
	printf("\t\t\t\t║              *0.退出                                      ║\n");
	printf("\t\t\t\t║                                                           ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════════════════╝\n");
	printf("\t\t\t\t ");
	scanf("%d", &a);
	return a;
}

//包含进度条
int face_play(struct media* p0) {


	system("CLS");
	struct media* p = p0;
	int a;

	int LENGTH = 50;//进度条长度
	int MinTens_cur = 0, MinOnes_cur = 0, SecTens_cur = 0, SecOnes_cur = 0;
	int MinTens_total = 0, MinOnes_total = 0, SecTens_total = 0, SecOnes_total = 0;

	char st1[50] = { '\0' };
	char st2[50] = { '\0' };
	char file1[50] = "status ";
	char file2[50] = " length";
	char text1[50] = "status ";
	char text2[50] = " position";
	char cmd[100] = { '\0' };

	int length = 0;//存储歌曲时长
	int current = 0;//存储歌曲当前播放位置

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

		printf("\t\t\t\t╔═════════════════════════════════════════════════════════════════╗\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *1.暂停/继续              *2.选曲播放                       ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *3.上一曲                 *4.下一曲                         ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *5.音量-                  *6.音量+                          ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *7.快进                   *8.快退                           ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *9.展示歌单               *0.返回上一级                     ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t╚═════════════════════════════════════════════════════════════════╝\n");
		printf("\n\n\t\t\t\t %d%d:%d%d/%d%d:%d%d  ",
			MinTens_cur, MinOnes_cur, SecTens_cur, SecOnes_cur,
			MinTens_total, MinOnes_total, SecTens_total, SecOnes_total);
		for (int j = 0; j <= LENGTH * current / length; j++) {
			printf("═");
		}

		Sleep(1000);
		system("cls");
	}
	return getch() - 48;

}

void face_fileFailure() {
	system("CLS");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                 文件打开失败！                ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	return;
}

void face_userNotFound() {
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                 找不到该用户！                ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	Sleep(3000);
	return;
}

void face_passwordWrong() {
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                    密码错误！                 ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	Sleep(3000);
}

void face_welcome(struct user* p) {
	system("CLS");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                   欢迎%-5s！                 ║\n", p->account);
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
}

char* input_AC() {
	char account[100];
	system("CLS");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                请输入您的用户名：             ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	printf("\t\t\t\t ");
	scanf("%s", account);
	return account;
}

char* input_re_AC() {
	char account[100];
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║      用户名已存在，请重新输入您的用户名：     ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	printf("\t\t\t\t ");
	scanf("%s", account);
	return account;
}

char* input_PW() {
	char password[100];
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                 请输入您的密码：              ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	printf("\t\t\t\t ");
	scanf("%s", password);
	return password;
}

void face_newACsuc() {
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                   注册成功！                  ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	Sleep(3000);
	return;
}

void listMedia(struct media* head) {
	struct media* p = head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                               ║\n");
	while (p != NULL)
	{
		printf("\t\t\t\t║   \t*输入%1d，将播放曲目%-10s\t    \t║\n", p->num, p->name);
		p = p->next;
	}//输出链表中的全部信息
	printf("\t\t\t\t║                                               ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

}

void listSongList(struct list* head) {
	struct list* p = head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                               ║\n");
	while (p != NULL)
	{
		//printf("\t\t\t\t║   \t*输入%1d，将展示歌单%-20s\t    \t║\n", p->num, p->name);
		printf("\t\t\t\t║   \t*输入%1d，将展示歌单\t    \t║\n", p->num);
		p = p->next;
	}//输出链表中的全部信息
	printf("\t\t\t\t║                                               ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

}