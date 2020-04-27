#include "CMonster.h"
#include "CMap.h"
#include"CPacMan.h"
//#include"CPacMan.cpp"

int I = 0;
int J = 0;

CMonster::CMonster(int x, int y)
{
	_mx=x;
	_my=y;
}

CMonster::~CMonster()
{
}

int CMonster::GetMonsterX()
{
	return _mx;
}
int CMonster::GetMonsterY()
{
	return _my;
}

void CMonster::SetMonsterX(int x)
{
	_mx = x;
}

void CMonster::SetMonsterY(int y)
{
	_my = y;
}

void CMonster::MonMoveUp()
{
	I = GetMonsterX();
	J = GetMonsterY();
	if (g_Map[I - 1][J] != 1 && g_Map[I- 1][J] == 3)  //���ϼ����ײ���Ƿ��ܰѹ���Ե�
	{
		g_Map[I-1][J] = 4;
		CPacMan(0,0).ManDead();
		return;
	}

	if (g_Map[I - 1][J] != 1 && g_Map[I - 1][J] == 0)
	{
		g_Map[I][J] = 0;
		g_Map[I - 1][J] = 2;
		SetMonsterX(I - 1);
		return;
	}
	if (g_Map[I - 1][J] != 1 && g_Map[I - 1][J] == 4)
	{
		g_Map[I][J] = 4;
		g_Map[I - 1][J] = 2;
		SetMonsterX(I - 1);
		return;
	}
	else {
		MonMoveRight();
	}
}

void CMonster::MonMoveDown()
{
	I = GetMonsterX();
	J = GetMonsterY();

	if (g_Map[I +1][J] != 1 && g_Map[I + 1][J] == 3)  //���ϼ����ײ���Ƿ��ܰѹ���Ե�
	{
		g_Map[I+1][J] = 4;
		CPacMan(0, 0).ManDead();
		return;
	}
	if (g_Map[I+1][J] != 1 && g_Map[I +1][J] == 0)
	{
		g_Map[I][J] = 0;
		g_Map[I + 1][J] = 2;
		SetMonsterX(I + 1);
		return;
	}
	if (g_Map[I + 1][J] != 1 && g_Map[I + 1][J] == 4)
	{
		g_Map[I][J] = 4;
		g_Map[I + 1][J] = 2;
		SetMonsterX(I + 1);
		return;
	}
	else {
		MonMoveLeft();
	}
}

void CMonster::MonMoveLeft()
{
	I = GetMonsterX();
	J = GetMonsterY();

	if (g_Map[I][J-1] != 1 && g_Map[I][J-1] == 3)  //��������ײ���Ƿ��ܰѹ���Ե�
	{
		g_Map[I][-1] = 4;
		CPacMan(0, 0).ManDead();
		return;
	}
	if (g_Map[I][J-1] != 1 && g_Map[I][J-1] == 0)
	{
		g_Map[I][J] = 0;
		g_Map[I][J-1] = 2;
		SetMonsterY(J - 1);
		return;
	}
	if (g_Map[I][J-1] != 1 && g_Map[I][J-1] == 4)
	{
		g_Map[I][J] = 4;
		g_Map[I][J-1] = 2;
		SetMonsterY(J - 1);
		return;
	}
	else {
		MonMoveUp();
	}

}

void CMonster::MonMoveRight()
{
	I = GetMonsterX();
	J = GetMonsterY();

	if (g_Map[I][J + 1] != 1 && g_Map[I][J + 1] == 3)  //���Ҽ����ײ���Ƿ��ܰѹ���Ե�
	{
		g_Map[I][J+1] = 4;
		CPacMan(0, 0).ManDead();
		return;
	}

	if (g_Map[I][J + 1] != 1 && g_Map[I][J + 1] == 0)
	{
		g_Map[I][J] = 0;
		g_Map[I][J + 1] = 2;
		SetMonsterY(J + 1);
		return;
	}
	if (g_Map[I][J + 1] != 1 && g_Map[I][J + 1] == 4)
	{
		g_Map[I][J] = 4;
		g_Map[I][J + 1] = 2;
		SetMonsterY(J + 1);
		return;
	}
	else {
		MonMoveDown();
	}
}

