#pragma once


#include <Windows.h>
#include "friendlyConsole/friendlyConsole.hpp"

//class Mazegenerator algorithm
class MazeGenerator {
public:

	static int random(int min, int max);
	static const int MAX = 77;
	static const int FIELD_CODE = 'a';
	MazeGenerator();
	void create(char playfield[MAX][MAX]);
	//static void gotoxy(int x, int y);
	void wait_milliseconds(int d_milliseconds);
	
private:
};