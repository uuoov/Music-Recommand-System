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
	printf("\t\t\t\t�U              *3.�޸�           *4.�˳�                    �U\n");
	printf("\t\t\t\t�U                                                           �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t\t\t\t ");


	//printf("\t    ��ӭʹ�û�Ա��¼ϵͳ\n\n");
	//printf("**********************************************");
	//printf("\n\n\t\t1.��¼ϵͳ\n\n");
	//printf("\n\n\t\t2.�����˺�\n\n");
	//printf("\n\n\t\t3.�޸�����\n\n");
	//printf("\n\n\t\t4.�˳�ϵͳ\n\n");
	//printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
	//printf("**********************************************\n");
	return 0;
}

int Menu_Print()
{
	/*�ⲿ�ִ��������Ҫ�滻*/
	system("cls");

	printf("**************************************************");

	printf("\n\t\t1.���ֿ�\t\t2.�ҵ����ֿ�\n");
	printf("\n\t\t3.��������\t4.ä���Ƽ�\n");
	printf("\n\t\t5.�����Ƽ�\t6.ÿ�վ�ѡ\n");
	printf("\n\t\t7.����\n");

	printf("\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("*************************************************\n");

	return 0;
}



