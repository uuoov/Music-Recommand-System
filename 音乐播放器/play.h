#include <stdio.h>
#include <io.h>

struct media {
	int num; // 编号
	char name[100]; //歌曲名称
	struct media* next; // 存储下一曲的地址
};

struct media* pre_media();
struct media* getChoice_media(struct media* head);
void play(struct media* p0);//播放
void pause(struct media* p0);//暂停播放
void continue_play(struct media* p0);//继续播放
void stop(struct media* p0);//停止播放
void volumeDown(struct media* p0);//音量减小
void volumeUp(struct media* p0);//音量增大
struct media* getNext(struct media* p0, struct media* head);
struct media* getLast(struct media* p0, struct media* head);
void volumeDown(struct media* p0);
void volumeUp(struct media* p0);
void switchPlay(struct media* p0);
char* getState(struct media* p0);
void goAhead15(struct media* p0);
void drawBack15(struct media* p0);
