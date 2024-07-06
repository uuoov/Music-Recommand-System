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
		printf("请输入账户");
		scanf_s("%d", &account);
		printf("确认输入请按“回车键”，重新输入请按“ESC”");

		hit = getch();
		for (; hit != 13 && hit != 27;)
		{
			hit = getch();
		}
	} while (hit == 27);

	printf("\n请输入密码\n");
	scanf_s("%s", password, 20);

	temp_1 = Match(account, password);

	if (temp_1 == 1)
	{
		printf("登录成功，按任意键继续");
		getch();
		Main_System();
	}
	else
	{
		if (temp_1 == -1)
		{
			printf("密码错误");
			getch();
			Land_System();
		}
		if (temp_1 == 0)
		{
			printf("不存在此用户");
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
		printf("\n还未存在用户！请新建账户");
		getch();
		system("cls");
		LandMain_System();
	}

	while (!feof(fp))
	{
		// 读取账号和密码
		if (fscanf_s(fp, "%d %19s", &account_temp, password_temp, sizeof(password_temp)) != 2)
		{
			if (feof(fp))
			{
				break;		//如果到达文件末尾，正常退出循环
			}
			else
			{
				printf("\n文件格式错误！\n");
				fclose(fp);
			}
		}

		// 检查账号和密码是否匹配
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

	//账号不存在，关闭文件并返回
	fclose(fp);
	return 0;
}

void LandMain_System()
{
	void Land_System();
	void AddAccount_User();

	char choose;

	LandMenu_System();

	//注意这里的识别输入
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
		//这里后面可以修改为用户ID
		printf("\n请按以下格式输入账户\n学号 密码\n");
		printf("请输入：");

		scanf_s("%d %s", &account, password, 20);

		printf("再次输入密码：\n");
		scanf_s("%s", password_check, 20);

		if (strcmp(password, password_check) == 0)
		{
			fprintf(fp, "%d %s\n", account, password);
			break;
		}
		else
		{
			printf("两次输入密码3不一致，继续创建请按“回车键”，退出请按“ESC”");
			hit = getch();
			if (hit == 27)
			{
				system("cls");
			}
			LandMain_System();
		}
	}
	fclose(fp);
	printf("创建成功，按任意键返回");
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
		printf("\n记录文件不存在，按任意键返回");
		getch();
		system("cls");
		LandMain_System();
	}
	system("cls");
	printf("请输入你的账号和原始密码：\n");
	scanf_s("%d %s", &searchAccount, searchPassword, 20);

	temp_1 = User_Count();

	for (temp_2 = 0; temp_2 <= temp_1; temp_2++)
	{
		fscanf_s(fp, "%d %s", &account, oldPassword, 20);
		if (account == searchAccount)
		{
			if (!strcmp(oldPassword, searchPassword))
			{
				printf("请输入新的密码：");
				scanf_s("%s", newPassword, 20);
				printf("再次输入密码：");
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
					printf("两次输入密码不一致，按任意键退出");
					hit = getch();
					system("cls");
					LandMain_System();
				}
			}
			else
			{
				printf("原始密码错误，按任意键返回！");
				getch();
				system("cls");
				LandMain_System();
			}
		}
	}
	printf("不存在此账号，按任意键返回！");
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
	return (cnt);	//返回个数
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