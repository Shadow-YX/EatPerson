#include<iostream>
#include<time.h>

#include"CMap.h"
#include"CPacMan.h"
#include"CMonster.h"
#include<time.h>

void MonsterMove();
void StartGame();

CMap map1;
CPacMan player(0, 0);  //Íæ¼Ò
CMonster monster1(2, 1);  //¹ÖÎï1 ºÅ
CMonster monster2(2, 26);
CMonster monster3(19, 1);
CMonster monster4(19, 26);

int main()
{
	StartGame();  
	return 0;
}


void StartGame()
{

	while (1)
	{
		map1.ShowMap();
		MonsterMove();
		player.PacManContral();
	}

	return;
}

void MonsterMove()    //¹ÖÎïAIÑ²Âß
{
	srand((int)time(NULL));
	int nIndex = rand() % 4;
	switch (nIndex)
	{
	case 0:
		monster1.MonMoveUp();
		break;
	case 1:
		monster1.MonMoveDown();
		break;
	case 2:
		monster1.MonMoveLeft();
		break;
	case 3:
		monster1.MonMoveRight();
		break;
	}
	nIndex = rand() % 4;
	switch (nIndex)
	{
	case 0:
		monster2.MonMoveUp();
		break;
	case 1:
		monster2.MonMoveDown();
		break;
	case 2:
		monster2.MonMoveLeft();
		break;
	case 3:
		monster2.MonMoveRight();
		break;
	}
	nIndex = rand() % 4;
	switch (nIndex)
	{
	case 0:
		monster3.MonMoveUp();
		break;
	case 1:
		monster3.MonMoveDown();
		break;
	case 2:
		monster3.MonMoveLeft();
		break;
	case 3:
		monster3.MonMoveRight();
		break;
	}
	nIndex = rand() % 4;
	switch (nIndex)
	{
	case 0:
		monster4.MonMoveUp();
		break;
	case 1:
		monster4.MonMoveDown();
		break;
	case 2:
		monster4.MonMoveLeft();
		break;
	case 3:
		monster4.MonMoveRight();
		break;
	}

	CMap().gotoxy(0,0);
} 

