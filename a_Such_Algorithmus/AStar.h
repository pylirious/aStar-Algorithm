#pragma once

#include "MazeGenerator.h"
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <time.h>


//struct Point
struct Point
{
	int x = 0, y = 0, belegt = 0;
	float value = 0, toStart = 0, toEnd = 0;
	int xB = 0, yB = 0;

};
//struct Player
struct Player
{
	int posX, posY;
	float toStart;
};

//class AStar algorithm
class AStar
{
public:

	AStar(char playfield[MazeGenerator::MAX][MazeGenerator::MAX]);	// Constructor

	int tryit = MazeGenerator::MAX * MazeGenerator::MAX - 1;	// Max index of open and closed list


	static const int SQUARE_CODE = 'a';	// Wall-character
	static const char BLANK_CODE = ' ';	// Blank character

	void add(Player player, int nx, int ny);
	bool isIn(int x, int y);
	void printPlayfield();
	Point findBestes();
	void backtrack();
	int find();
	bool IsSomethingInOpen();

private:
	Point open[(MazeGenerator::MAX * MazeGenerator::MAX)];	// Open-List: A list of 'known' points with calculated Values	
	Point closed[(MazeGenerator::MAX * MazeGenerator::MAX)];	// Closed-List: A list of 'used' points of the open-list
	Point start;
	Point end;
	char playfield[MazeGenerator::MAX][MazeGenerator::MAX];	// The blank class-maze
};