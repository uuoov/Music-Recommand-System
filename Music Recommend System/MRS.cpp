#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "MRS.h"
#include "menu.h"
#include "land.h"
#include "play.h"





void Main_System()
{
	/*这个部分放音乐管理相关函数*/

	char choose;

	Menu_Print();

	scanf_s("%c", &choose);

	switch (choose)
	{
	case '1':
		/*这部分带啊需要后面不断补充*/
		break;
	case '3':
		system("cls");
		getch();
		exit(0);
		system("cls");
		break;
	default:
		Main_System();
		break;

	}
}


void main()
{
	system("color e");

	while (1)
	{
		LandMain_System();
	}
}

