#include "CPacMan.h"
#include "CMap.h"
#include<time.h>
#include<stdio.h>
#include <Windows.h>

static char ch;
int X=0;
int Y=0; 
int g_nLifeValue = 3;  //生命值
int g_nPoint=0;  //分数

CPacMan::CPacMan(int x, int y)
{
	_px = x;
	_py = y;
}

CPacMan::~CPacMan()
{
}

int CPacMan::getCPacManX()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (g_Map[i][j] == 3)
			{
				_px = i;
			}
		}
	}
	return _px;
}


int CPacMan::getCPacManY()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (g_Map[i][j] == 3)
			{
				_py = j;
			}
		}
	}
	return _py;
}


void CPacMan::PacManContral()
{
	ch = 'f';
	Sleep(100);  //游戏速度
	while (true)
	{
		if (! _kbhit())
		{
			switch (ch)
			{
			case 'w':
			case 'W':
				PacMoveUp();
				return;
			case 'a':
			case 'A':
				PacMoveLeft();
				return;
			case 's':
			case 'S':
				PacMoveDown();
				return;
			case 'd':
			case 'D':
				PacMoveRight();
				return;
			case'f':
					return;
			case'1':
				CMap().newGame();
				return;
			case'2':
				exit(0);
			}
		}
		else
		{
			ch = _getch();
		}
		}
}

void CPacMan::PacMoveUp()
{
	X = getCPacManX();
	Y = getCPacManY();
	if (g_Map[X - 1][Y] != 1 && g_Map[X - 1][Y] == 2)  //向上检测碰撞，是否被怪物吃掉
	{
		g_Map[X][Y] = 4;
		ManDead();
		return;
	}
	if (g_Map[X - 1][Y] != 1 && g_Map[X - 1][Y] == 0)
	{
		g_Map[X][Y] = 4;
		g_Map[X - 1][Y] = 3;
		g_nPoint++;
		return;
	}
	if (g_Map[X - 1][Y] != 1 && g_Map[X - 1][Y] != 0)
	{
		g_Map[X][Y] = 4;
		g_Map[X - 1][Y] = 3;
		return;
	}

}

void CPacMan::PacMoveDown()
{
	{
		X = getCPacManX();
		Y = getCPacManY();
		if (g_Map[X + 1][Y] != 1 && g_Map[X + 1][Y] == 2)  //向下检测碰撞，是否被怪物吃掉
		{
			g_Map[X][Y] = 4;
			ManDead();
			return;
		}
		if (g_Map[X+1][Y] != 1 && g_Map[X+1][Y] == 0)
		{
			g_Map[X][Y] = 4;
			g_Map[X+1][Y] = 3;
			g_nPoint++;
			return;
		}
		if (g_Map[X+1][Y] != 1 && g_Map[X +1][Y] != 0)
		{
			g_Map[X][Y] = 4;
			g_Map[X+1][Y] = 3;
			return;
		}
	}
}

void CPacMan::PacMoveLeft()
{
	X = getCPacManX();
	Y = getCPacManY();
	if (g_Map[X][Y - 1] != 1 && g_Map[X][Y - 1] == 2)
	{
		g_Map[X][Y] = 4;
		ManDead();
		return;
	}
	if (g_Map[X][Y - 1] != 1 && g_Map[X][Y - 1] == 0)
	{
		g_Map[X][Y - 1] = 3;
		g_Map[X][Y] = 4;
		g_nPoint++;
		return;
	}
	if (g_Map[X][Y - 1] != 1 && g_Map[X][Y - 1] != 0)
	{
		g_Map[X][Y - 1] = 3;
		g_Map[X][Y] = 4;
		return;
	}
}

void CPacMan::PacMoveRight()
{
	X = getCPacManX();
	Y = getCPacManY();
	if (g_Map[X][Y + 1] != 1 && g_Map[X][Y + 1] == 2)
	{
		g_Map[X][Y] = 4;
		ManDead();
		return;
	}
	if (g_Map[X][Y+1] != 1 && g_Map[X][Y+1] == 0)
	{
		g_Map[X][Y+1] = 3;
		g_Map[X][Y] = 4;
		g_nPoint++;
		return;
	}
	if (g_Map[X][Y+1] != 1 && g_Map[X][Y+1] != 0)
	{
		g_Map[X][Y+1] = 3;
		g_Map[X][Y] = 4;
		return;                                 
	}
}

void CPacMan::ManDead()
{
	g_nLifeValue--;
	if (g_nLifeValue <= 0)
	{
		CMap().DeadGame();
		return;
	}
	g_Map[19][13] = 3;

}

