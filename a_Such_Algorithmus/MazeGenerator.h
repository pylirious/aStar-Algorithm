#pragma once


#include "AStar.h"


class MazeGenerator {
public:
	static const int MAX = 99;
	MazeGenerator();
	void create(char playfield[MAX][MAX]);
	void gotoxy(int x, int y);
	
	
private:
};