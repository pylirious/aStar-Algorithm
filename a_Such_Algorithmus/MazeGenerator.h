#pragma once


#include <Windows.h>
#include "friendlyConsole/friendlyConsole.hpp"

//class Mazegenerator algorithm
class MazeGenerator
{
public:

	static const int MAX = 120;	// IMPORTANT: Size of one Border Wall, max Value is 123
	static const int FIELD_CODE = 'a';	// Wall-check character
	static int random(int min, int max);
	void create(char playfield[MAX][MAX]);
	void wait_milliseconds(int d_milliseconds);

};