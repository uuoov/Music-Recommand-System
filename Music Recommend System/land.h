#ifndef _LAND_H_


#include <stdio.h>
#include <io.h>
#include<string.h>

#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��
#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��


struct land//��¼��Ϣ
{
	int num;
	int account;
	char userName[50];
	char password[50];
	struct land* next;
};



//011 - ��¼�˵�
void Land_System();

//012 - �˺�����
int Match(int account, char password[20]);

//013 - ����˺�
void AddAccount_User();

//014 - �޸�����
void PasswordChange_User();

//015 - �˻�����
int User_Count();

//016 - �����޸�
void Change_Password(int searchAccount, char searchPassword[20]);

#endif // !_LAND_H_