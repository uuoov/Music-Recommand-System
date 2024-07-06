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

char path_user[150] = "userInfo.txt";  //�����û���Ϣ���ļ�

//��ȡָ���ļ��е��û���Ϣ�����������Ϣ���浽����
struct user* pre_user()
{
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, path_user, "r"); // ʹ��fopen_s���ļ�
	if (err != 0) {
		face_fileFailure(); // ����ļ���ʧ�ܣ�
		return NULL;
	}

	struct user* head = NULL, * p = NULL, * q = NULL;
	int number = 0; // ��¼�û�����

	while (1) {
		q = (struct user*)malloc(sizeof(struct user));
		if (q == NULL) {
			// �����ڴ�ʧ�ܣ��ͷ������ѷ�����ڴ�
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

		// ��ȡaccount��password
		if (fscanf_s(fp, "%100s", q->account, sizeof(q->account)) != 1) break;
		if (fscanf_s(fp, "%100s", q->password, sizeof(q->password)) != 1) break;
		q->num = number;
		q->next = NULL;
	}

	if (feof(fp)) {
		// �ļ���ȡ��������
		p->next = NULL; // ȷ�����һ���ڵ��nextָ��ΪNULL
	}
	else {
		// ��ȡ��������������
		face_fileFailure();
		// �ͷ������ڴ�
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

//�û���¼
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
		face_userNotFound();//���"�Ҳ������û�"
		return NULL;
	}

	strcpy(password, input_PW());

	if (strcmp(p->password, password) != 0) {
		face_passwordWrong();//��� "�������";
		return NULL;
	}
	if (strcmp(p->password, password) == 0) {
		face_welcome(p);//printf"��ӭp->account";
		return p;
	}
}

//�û�ע��
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
		int flag_repe = 0;//0��ʾ���û���û�кͱ����account�ظ���1��ʾ�ظ���
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