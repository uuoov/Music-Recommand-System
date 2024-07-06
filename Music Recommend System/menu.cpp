#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <mmsystem.h>
#include "menu.h"
#include "MRS.h"

int LandMenu_System()
{
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
	printf("\t\t\t\t║              *3.修改           *4.退出                    ║\n");
	printf("\t\t\t\t║                                                           ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════════════════╝\n");
	printf("\t\t\t\t ");


	//printf("\t    欢迎使用会员登录系统\n\n");
	//printf("**********************************************");
	//printf("\n\n\t\t1.登录系统\n\n");
	//printf("\n\n\t\t2.创建账号\n\n");
	//printf("\n\n\t\t3.修改密码\n\n");
	//printf("\n\n\t\t4.退出系统\n\n");
	//printf("\n\n\t    请按键选择，回车确定\n");
	//printf("**********************************************\n");
	return 0;
}

int Menu_Print()
{
	/*这部分代码后续需要替换*/
	system("cls");

	printf("**************************************************");

	printf("\n\t\t1.音乐库\t\t2.我的音乐库\n");
	printf("\n\t\t3.音乐社区\t4.盲盒推荐\n");
	printf("\n\t\t5.定向推荐\t6.每日精选\n");
	printf("\n\t\t7.设置\n");

	printf("\n 请按键选择，回车确定\n");

	printf("*************************************************\n");

	return 0;
}



