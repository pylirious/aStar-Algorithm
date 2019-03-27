#pragma once

#include <math.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

struct Point {
	int x = 0, y = 0, belegt = 0;
	float value = 0, toStart = 0, toEnd = 0;
	int xB, yB;

};

struct Player {
	int posX, posY;
	float toStart;
};

class AStar {
public:
	static const int MAX_HEIGHT = 100;
	static const int MAX_WIDTH = 100;
	int tryit = MAX_WIDTH * MAX_HEIGHT / 2 - 1;

	AStar(char playfield[][MAX_HEIGHT]);

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
	Point open[(MAX_WIDTH * MAX_HEIGHT) / 2];
	Point closed[(MAX_WIDTH * MAX_HEIGHT) / 2];
	Point start;
	Point end;
	char playfield[MAX_WIDTH][MAX_HEIGHT];
};