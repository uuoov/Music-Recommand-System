#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"user.h"
#include"face.h"
#include"play.h"
#include"list.h"

int main() {

	struct media* HEAD_MEDIA = NULL; //歌曲信息以链表形式存储，HEAD_MEDIA为链表头
	struct user* HEAD_USER = pre_user();//用户信息以链表形式存储，HEAD_USER为链表头
	struct list* HEAD_LIST = pre_list();//歌单信息以链表形式存储，HEAD_LIST为链表头
	struct user* p_user = NULL;//指针，指向当前用户的节点
	struct media* p_media = NULL;//指针，指向当前播放的歌曲的节点
	struct list* p_list = NULL;

	int choice;					//储存选择的登录、注册或退出的选项
	int flag_logIn = 0;	//记录登录状态，1表示已登录
	int choice_play = 0;//储存选择的播放功能的选项
	int choice_song = 0;//储存选择的播放曲目的序号
	int flag_play = 1;	//记录播放状态，0表示退出播放

	while (flag_logIn == 0) {

		choice = face_user();//输出列表——1.登录，2.注册，3.输入；返回代表选项的int值

		switch (choice)
		{
		case 1://登录并播放歌曲
			HEAD_MEDIA = pre_media();
			p_user = logIn(HEAD_USER);
			if (p_user != NULL) {
				flag_logIn = 1;
				listMedia(HEAD_MEDIA);//显示歌曲列表
				p_media = getChoice_media(HEAD_MEDIA);//输入歌曲编号，返回指向对应歌曲信息的指针
				play(p_media);
				flag_play = 1;
				while (flag_play == 1) {
					choice_play = face_play(p_media);

					switch (choice_play)
					{
					case 1://暂停or继续
						switchPlay(p_media);
						break;
					case 2://选曲播放
						stop(p_media);
						listMedia(HEAD_MEDIA);
						p_media = getChoice_media(HEAD_MEDIA);
						play(p_media);
						break;
					case 3://上一首
						stop(p_media);
						p_media = getLast(p_media, HEAD_MEDIA);
						play(p_media);
						break;
					case 4://下一首
						stop(p_media);
						p_media = getNext(p_media, HEAD_MEDIA);
						play(p_media);
						break;
					case 5://音量-
						volumeDown(p_media);
						break;
					case 6://音量+
						volumeUp(p_media);
						break;
					case 7://快进15秒
						goAhead15(p_media);
						break;
					case 8://快退15秒
						drawBack15(p_media);
						break;
					case 9://展示歌单
						stop(p_media);
						p_list = HEAD_LIST->next;
						listSongList(HEAD_LIST);
						p_list = getChoice_list(HEAD_LIST);
						printf("\n\t\t\t\t %s\n", p_list->name);
						HEAD_MEDIA = loadMedia(p_list);
						listMedia(HEAD_MEDIA);//显示歌曲列表
						p_media = getChoice_media(HEAD_MEDIA);//输入歌曲编号，返回指向对应歌曲信息的指针
						play(p_media);
						break;
					case 0://退出播放
						stop(p_media);
						flag_play = 0;
						flag_logIn = 0;
						break;
					}
				}
			}
			break;
		case 2://注册账号
			createAC(HEAD_USER);
			break;
		case 0://退出程序
			return 0;
		}
	}
}
