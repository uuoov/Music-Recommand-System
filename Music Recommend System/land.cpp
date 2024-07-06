#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <conio.h>
#include <mmsystem.h>

#include "land.h"
#include "MRS.h"
#include "menu.h"

void Land_System()
{
	int account;
	char password[20];
	int temp_1 = 2, temp_2, temp_3;

	char hit = 0;
	system("cls");

	do
	{
		printf("�������˻�");
		scanf_s("%d", &account);
		printf("ȷ�������밴���س����������������밴��ESC��");

		hit = getch();
		for (; hit != 13 && hit != 27;)
		{
			hit = getch();
		}
	} while (hit == 27);

	printf("\n����������\n");
	scanf_s("%s", password, 20);

	temp_1 = Match(account, password);

	if (temp_1 == 1)
	{
		printf("��¼�ɹ��������������");
		getch();
		Main_System();
	}
	else
	{
		if (temp_1 == -1)
		{
			printf("�������");
			getch();
			Land_System();
		}
		if (temp_1 == 0)
		{
			printf("�����ڴ��û�");
		}
		getch();
		system("cls");
		LandMain_System();
	}
}

int Match(int account, char password[20])
{
	FILE* fp;
	int n = 0, i = 0;
	int account_temp = 0;
	char password_temp[20];

	if ((fp = fopen("land.txt", "r")) == NULL)
	{
		system("cls");
		printf("\n��δ�����û������½��˻�");
		getch();
		system("cls");
		LandMain_System();
	}

	while (!feof(fp))
	{
		// ��ȡ�˺ź�����
		if (fscanf_s(fp, "%d %19s", &account_temp, password_temp, sizeof(password_temp)) != 2)
		{
			if (feof(fp))
			{
				break;		//��������ļ�ĩβ�������˳�ѭ��
			}
			else
			{
				printf("\n�ļ���ʽ����\n");
				fclose(fp);
			}
		}

		// ����˺ź������Ƿ�ƥ��
		if (account == account_temp)
		{
			if (strcmp(password, password_temp) == 0)
			{
				fclose(fp);
				return 1;
			}
			else
			{
				fclose(fp);
				return -1;
			}
		}
	}

	//�˺Ų����ڣ��ر��ļ�������
	fclose(fp);
	return 0;
}

void LandMain_System()
{
	void Land_System();
	void AddAccount_User();

	char choose;

	LandMenu_System();

	//ע�������ʶ������
	scanf_s("%c", &choose);

	switch (choose)
	{
	case '1':
		Land_System();
		break;
	case '2':
		AddAccount_User();
		break;
	case '3':
		PasswordChange_User();
		break;
	case '4':
		system("cls");
		getch();
		exit(0);
		system("cls");
		break;
	default:
		system("cls");
		LandMenu_System();
		break;
	}
}

void AddAccount_User()
{
	FILE* fp;
	int account;
	char password[20], password_check[20];

	char hit = 0;

	if ((fp = fopen("land.txt", "r")) == NULL)
	{
		fp = fopen("land.txt", "w");
		fclose(fp);
	}
	system("cls");
	fp = fopen("land.txt", "a");

	for (; ;)
	{
		//�����������޸�Ϊ�û�ID
		printf("\n�밴���¸�ʽ�����˻�\nѧ�� ����\n");
		printf("�����룺");

		scanf_s("%d %s", &account, password, 20);

		printf("�ٴ��������룺\n");
		scanf_s("%s", password_check, 20);

		if (strcmp(password, password_check) == 0)
		{
			fprintf(fp, "%d %s\n", account, password);
			break;
		}
		else
		{
			printf("������������3��һ�£����������밴���س��������˳��밴��ESC��");
			hit = getch();
			if (hit == 27)
			{
				system("cls");
			}
			LandMain_System();
		}
	}
	fclose(fp);
	printf("�����ɹ��������������");
	getch();
	system("cls");
	LandMain_System();
}

void PasswordChange_User()
{
	FILE* fp;

	int account = 0, temp_1 = 0, temp_2 = 0;
	int searchAccount;
	char oldPassword[20] = { '\0' }, searchPassword[20] = { '\0' };
	char newPassword[20] = { '\0' }, newPassword_check[20] = { '\0' };
	char hit = 0;

	if ((fp = fopen("land.txt", "r")) == NULL)
	{
		system("cls");
		printf("\n��¼�ļ������ڣ������������");
		getch();
		system("cls");
		LandMain_System();
	}
	system("cls");
	printf("����������˺ź�ԭʼ���룺\n");
	scanf_s("%d %s", &searchAccount, searchPassword, 20);

	temp_1 = User_Count();

	for (temp_2 = 0; temp_2 <= temp_1; temp_2++)
	{
		fscanf_s(fp, "%d %s", &account, oldPassword, 20);
		if (account == searchAccount)
		{
			if (!strcmp(oldPassword, searchPassword))
			{
				printf("�������µ����룺");
				scanf_s("%s", newPassword, 20);
				printf("�ٴ��������룺");
				scanf_s("%s", newPassword_check, 20);
				if (strcmp(newPassword, newPassword_check) == 0)
				{
					Change_Password(searchAccount, newPassword);
					getch();
					LandMain_System();
					system("cls");
				}
				else
				{
					printf("�����������벻һ�£���������˳�");
					hit = getch();
					system("cls");
					LandMain_System();
				}
			}
			else
			{
				printf("ԭʼ������󣬰���������أ�");
				getch();
				system("cls");
				LandMain_System();
			}
		}
	}
	printf("�����ڴ��˺ţ�����������أ�");
	fclose(fp);
	getch();
	system("cls");
	LandMain_System();
}

int User_Count()
{
	FILE* fp;
	int account = 0, cnt;
	char password[20] = { '\0' };
	fp = fopen("land.txt", "r");
	for (cnt = 0; !feof(fp); cnt++)
	{
		fscanf(fp, "%d %s", &account, password, 20);
	}
	cnt--;
	fclose(fp);
	return (cnt);	//���ظ���
}

void Change_Password(int searchAccount, char searchPassword[20])
{
	FILE* fp;
	int account, n = 0, j, k;

	char password[20] = { '\0' };

	struct land* head = NULL, * p, * p1 = NULL, * p2 = NULL;

	fp = fopen("land.txt", "r");

	j = User_Count();

	for (k = 0; k <= j; k++)
	{
		fscanf_s(fp, "%d %s", &account, password, 20);
		if (searchAccount != account)
		{
			n++;
			if (n == 1)
			{
				p1 = p2 = (struct land*)malloc(LEN2);
				head = p1;
			}
			else
			{
				p2->next = p1;
				p2 = p1;
				p1 = (struct land*)malloc(LEN2);
			}
			p1->account = account;
			strcpy(p1->password, password);
		}
	}

	if (n == 0)
	{
		head = NULL;
	}
	else
	{
		p2->next = p1;
		p1->next = NULL;
		fclose(fp);
	}
	fp = fopen("land.txt", "w");
	fclose(fp);
	fp = fopen("land.txt", "a");
	p = head;
	for (; p != NULL;)
	{
		fprintf(fp, "%d %s\n", account, password);
		fclose(fp);
		system("cls");
	}
	LandMain_System();
}