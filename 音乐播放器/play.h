#include <stdio.h>
#include <io.h>

struct media {
	int num; // ���
	char name[100]; //��������
	struct media* next; // �洢��һ���ĵ�ַ
};

struct media* pre_media();
struct media* getChoice_media(struct media* head);
void play(struct media* p0);//����
void pause(struct media* p0);//��ͣ����
void continue_play(struct media* p0);//��������
void stop(struct media* p0);//ֹͣ����
void volumeDown(struct media* p0);//������С
void volumeUp(struct media* p0);//��������
struct media* getNext(struct media* p0, struct media* head);
struct media* getLast(struct media* p0, struct media* head);
void volumeDown(struct media* p0);
void volumeUp(struct media* p0);
void switchPlay(struct media* p0);
char* getState(struct media* p0);
void goAhead15(struct media* p0);
void drawBack15(struct media* p0);
