#pragma once

#define ROW 25   //����
#define COL 28    //����

extern  int g_nPoint; //�Ʒ���
extern  int g_nLifeValue;  //����ֵ
extern  int g_Map[ROW][COL]; //��ͼ
extern const  int g_MapInit[ROW][COL]; //��ʼ����ͼ

using namespace std;

class CMap
{
public:
	void ShowMap();		//��ʾ��ͼ
	void WinGame();  //��ʤ�¼�
	void gotoxy(short y, short x);   //��Ļˢ��
	void NewInitMap(); //��ʼ����ͼ
	void SelectQuit();  //ѡ���˳��¼�
	void newGame(); //��ʼ����Ϸ
	static void DeadGame();     //�����¼�
};

