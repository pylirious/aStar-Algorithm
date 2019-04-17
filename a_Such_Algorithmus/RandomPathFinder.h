#pragma once
#include "MazeGenerator.h"
#include <time.h>
#include <iostream>

//Random Pathfinder algorithm
class RandomPathFinder {
public:
	RandomPathFinder(char playfield[MazeGenerator::MAX][MazeGenerator::MAX]);

	int find();
	
private:

	char playfield[MazeGenerator::MAX][MazeGenerator::MAX];
};