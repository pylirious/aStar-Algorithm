#pragma once

#include "MazeGenerator.h"
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

struct Point {
	int x = 0, y = 0, belegt = 0;
	float value = 0, toStart = 0, toEnd = 0;
	int xB = 0, yB = 0;

};

struct Player {
	int posX, posY;
	float toStart;
};

class AStar {
public:

	int tryit = MazeGenerator::MAX * MazeGenerator::MAX / 2 - 1;

	AStar(char playfield[MazeGenerator::MAX][MazeGenerator::MAX]);

	static const int SQUARE_CODE = 'a';
	static const char BLANK_CODE = ' ';

	void add(Player player, int nx, int ny);
	void swap(int index1, int index2);
	void sort(int length);
	bool isIn(int x, int y);
	void zeichne_spielfeld();
	Point findBestes();
	void backtrack();
	bool find();
	void gotoxy(int x, int y);
	void wait_milliseconds(int d_milliseconds);

private:
	Point open[(MazeGenerator::MAX * MazeGenerator::MAX) / 2];
	Point closed[(MazeGenerator::MAX * MazeGenerator::MAX) / 2];
	Point start;
	Point end;
	char playfield[MazeGenerator::MAX][MazeGenerator::MAX];
};