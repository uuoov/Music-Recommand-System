#include<stdio.h>
#include <io.h>
#include<string.h>

struct user {
	int num;
	char account[100];
	char password[100];
	struct user* next;
};

struct user* logIn(struct user* head);
void createAC(struct user* head);
struct user* pre_user();