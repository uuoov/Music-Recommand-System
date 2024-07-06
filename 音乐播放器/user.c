#include<stdio.h>
#include <io.h>
#include<string.h>
#include"face.h"

struct user {
	int num;
	char account[101];
	char password[101];
	struct user* next;
};

char path_user[150] = "userInfo.txt";  //储存用户信息的文件

//读取指定文件中的用户信息，并把相关信息储存到链表
struct user* pre_user()
{
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, path_user, "r"); // 使用fopen_s打开文件
	if (err != 0) {
		face_fileFailure(); // 输出文件打开失败！
		return NULL;
	}

	struct user* head = NULL, * p = NULL, * q = NULL;
	int number = 0; // 记录用户个数

	while (1) {
		q = (struct user*)malloc(sizeof(struct user));
		if (q == NULL) {
			// 分配内存失败，释放所有已分配的内存
			struct user* temp;
			while (head != NULL) {
				temp = head;
				head = head->next;
				free(temp);
			}
			fclose(fp);
			return NULL;
		}
		if (number == 0) {
			head = q;
			p = q;
		}
		else {
			p->next = q;
			p = q;
		}
		number++;

		// 读取account和password
		if (fscanf_s(fp, "%100s", q->account, sizeof(q->account)) != 1) break;
		if (fscanf_s(fp, "%100s", q->password, sizeof(q->password)) != 1) break;
		q->num = number;
		q->next = NULL;
	}

	if (feof(fp)) {
		// 文件读取正常结束
		p->next = NULL; // 确保最后一个节点的next指针为NULL
	}
	else {
		// 读取过程中遇到错误
		face_fileFailure();
		// 释放链表内存
		while (head != NULL) {
			p = head;
			head = head->next;
			free(p);
		}
		head = NULL;
	}

	fclose(fp);
	return head;
}

//用户登录
struct user* logIn(struct user* head)
{
	char account[100];
	char password[100];
	struct user* p = head->next;

	strcpy(account, input_AC());

	while (p != NULL && strcmp(p->account, account) != 0)
	{
		p = p->next;
	}
	if (p == NULL) {
		face_userNotFound();//输出"找不到该用户"
		return NULL;
	}

	strcpy(password, input_PW());

	if (strcmp(p->password, password) != 0) {
		face_passwordWrong();//输出 "密码错误";
		return NULL;
	}
	if (strcmp(p->password, password) == 0) {
		face_welcome(p);//printf"欢迎p->account";
		return p;
	}
}

//用户注册
void createAC(struct user* head)
{

	FILE* fp;
	fp = fopen(path_user, "a");
	if (fp == NULL) {
		face_fileFailure();
	}
	else {
		char account[100];
		char password[100];
		struct user* p = NULL;
		int flag_repe = 0;//0表示该用户名没有和别个的account重复，1表示重复了
		struct user* q = (struct user*)malloc(sizeof(struct user));

		strcpy(account, input_AC());

		p = head->next;
		while (p != NULL) {
			if (strcmp(p->account, account) == 0) {
				flag_repe = 1;
			}
			p = p->next;
		}
		while (flag_repe == 1) {
			p = head->next;
			flag_repe = 0;
			strcpy(account, input_re_AC());
			while (p != NULL) {
				if (strcmp(p->account, account) == 0) {
					flag_repe = 1;
				}
				p = p->next;
			}
		}

		strcpy(password, input_PW());

		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		strcpy(q->account, account);
		strcpy(q->password, password);
		q->next = NULL;
		p->next = q;

		fprintf(fp, "\n%s\n%s", account, password);
		fclose(fp);

		face_newACsuc();
	}
}