#pragma once
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#pragma once
class CMonster
{
public:
	CMonster(int x,int y);
	~CMonster();
	int GetMonsterX();
	int GetMonsterY();
	void  SetMonsterX(int x);
	void  SetMonsterY(int y);

public:
	void MonMoveUp();
	void MonMoveDown();
	void MonMoveLeft();
	void MonMoveRight();

private:
	int _mx;
	int _my;

};

