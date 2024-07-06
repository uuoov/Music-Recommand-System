#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"user.h"
#include"face.h"
#include"play.h"
#include"list.h"

int main() {

	struct media* HEAD_MEDIA = NULL; //������Ϣ��������ʽ�洢��HEAD_MEDIAΪ����ͷ
	struct user* HEAD_USER = pre_user();//�û���Ϣ��������ʽ�洢��HEAD_USERΪ����ͷ
	struct list* HEAD_LIST = pre_list();//�赥��Ϣ��������ʽ�洢��HEAD_LISTΪ����ͷ
	struct user* p_user = NULL;//ָ�룬ָ��ǰ�û��Ľڵ�
	struct media* p_media = NULL;//ָ�룬ָ��ǰ���ŵĸ����Ľڵ�
	struct list* p_list = NULL;

	int choice;					//����ѡ��ĵ�¼��ע����˳���ѡ��
	int flag_logIn = 0;	//��¼��¼״̬��1��ʾ�ѵ�¼
	int choice_play = 0;//����ѡ��Ĳ��Ź��ܵ�ѡ��
	int choice_song = 0;//����ѡ��Ĳ�����Ŀ�����
	int flag_play = 1;	//��¼����״̬��0��ʾ�˳�����

	while (flag_logIn == 0) {

		choice = face_user();//����б���1.��¼��2.ע�ᣬ3.���룻���ش���ѡ���intֵ

		switch (choice)
		{
		case 1://��¼�����Ÿ���
			HEAD_MEDIA = pre_media();
			p_user = logIn(HEAD_USER);
			if (p_user != NULL) {
				flag_logIn = 1;
				listMedia(HEAD_MEDIA);//��ʾ�����б�
				p_media = getChoice_media(HEAD_MEDIA);//���������ţ�����ָ���Ӧ������Ϣ��ָ��
				play(p_media);
				flag_play = 1;
				while (flag_play == 1) {
					choice_play = face_play(p_media);

					switch (choice_play)
					{
					case 1://��ͣor����
						switchPlay(p_media);
						break;
					case 2://ѡ������
						stop(p_media);
						listMedia(HEAD_MEDIA);
						p_media = getChoice_media(HEAD_MEDIA);
						play(p_media);
						break;
					case 3://��һ��
						stop(p_media);
						p_media = getLast(p_media, HEAD_MEDIA);
						play(p_media);
						break;
					case 4://��һ��
						stop(p_media);
						p_media = getNext(p_media, HEAD_MEDIA);
						play(p_media);
						break;
					case 5://����-
						volumeDown(p_media);
						break;
					case 6://����+
						volumeUp(p_media);
						break;
					case 7://���15��
						goAhead15(p_media);
						break;
					case 8://����15��
						drawBack15(p_media);
						break;
					case 9://չʾ�赥
						stop(p_media);
						p_list = HEAD_LIST->next;
						listSongList(HEAD_LIST);
						p_list = getChoice_list(HEAD_LIST);
						printf("\n\t\t\t\t %s\n", p_list->name);
						HEAD_MEDIA = loadMedia(p_list);
						listMedia(HEAD_MEDIA);//��ʾ�����б�
						p_media = getChoice_media(HEAD_MEDIA);//���������ţ�����ָ���Ӧ������Ϣ��ָ��
						play(p_media);
						break;
					case 0://�˳�����
						stop(p_media);
						flag_play = 0;
						flag_logIn = 0;
						break;
					}
				}
			}
			break;
		case 2://ע���˺�
			createAC(HEAD_USER);
			break;
		case 0://�˳�����
			return 0;
		}
	}
}
