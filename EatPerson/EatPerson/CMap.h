#pragma once

#define ROW 25   //横排
#define COL 28    //竖排

extern  int g_nPoint; //计分器
extern  int g_nLifeValue;  //生命值
extern  int g_Map[ROW][COL]; //地图
extern const  int g_MapInit[ROW][COL]; //初始化地图

using namespace std;

class CMap
{
public:
	void ShowMap();		//显示地图
	void WinGame();  //获胜事件
	void gotoxy(short y, short x);   //屏幕刷新
	void NewInitMap(); //初始化地图
	void SelectQuit();  //选择退出事件
	void newGame(); //初始化游戏
	static void DeadGame();     //死亡事件
};

