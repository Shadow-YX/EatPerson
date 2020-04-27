#pragma once
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>

class CPacMan
{
public:
	CPacMan(int x, int y);
	~CPacMan();
	int getCPacManX();
	int getCPacManY();

public:
	void PacManContral();
	void PacMoveUp();
	void PacMoveDown();
	void PacMoveLeft();
	void PacMoveRight();
	static void ManDead();  //ËÀÍö×´Ì¬

private:
	int _px;
	int _py;
};

