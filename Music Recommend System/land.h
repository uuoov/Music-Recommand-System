#ifndef _LAND_H_


#include <stdio.h>
#include <io.h>
#include<string.h>

#define LEN sizeof(struct book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct land)//有关登录系统的结构体


struct land//登录信息
{
	int num;
	int account;
	char userName[50];
	char password[50];
	struct land* next;
};



//011 - 登录菜单
void Land_System();

//012 - 账号密码
int Match(int account, char password[20]);

//013 - 添加账号
void AddAccount_User();

//014 - 修改密码
void PasswordChange_User();

//015 - 账户计数
int User_Count();

//016 - 密码修改
void Change_Password(int searchAccount, char searchPassword[20]);

#endif // !_LAND_H_