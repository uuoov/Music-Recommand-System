#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <io.h>

struct list {
	int num;
	char name[100];//¸èµ¥Ãû³Æ
	struct list* next;
};

struct list* pre_list();
struct list* getChoice_list(struct list* head);
struct media* loadMedia(struct list* p);
