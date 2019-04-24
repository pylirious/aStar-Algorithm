#include <pch.h>
#include <iostream>
#include "MazeGenerator.h"
#include <random>
#include <time.h>


int MazeGenerator::random(int min, int max)	// Random number generator
{	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
	dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng);
	return dist6(rng);
}



void MazeGenerator::create(char playfield[MazeGenerator::MAX][MazeGenerator::MAX])	// Function for generating a maze into an array 
{
	bool stay = true;
	int step;
	char blank = ' ';	// empty-character 
	char feld = 'a';	// 'wall'-character
	int rR = 0, x, y, dx = 0, dy = 0;


	// Fill the array with blank characters
	for (int i = 0; i < this->MAX; i++)
	{
		for (int j = 0; j < this->MAX; j++)
		{
			playfield[i][j] = blank;

		}
	}

	// Fill in and print the border
	for (int i = 0; i < this->MAX; i++)
	{
		playfield[i][this->MAX - 1] = feld;
		gotoxy(i, this->MAX - 1);
		printf("%c", 219);

		playfield[i][0] = feld;
		gotoxy(i, 0);
		printf("%c", 219);

		playfield[this->MAX - 1][i] = feld;
		gotoxy(this->MAX - 1, i);
		printf("%c", 219);

		playfield[0][i] = feld;
		gotoxy(0, i);
		printf("%c", 219);
	}


	int time = clock();	// Get actual time

	// Keep looking for starting points for (border-length on one side * 120) Mili sec
	while (clock() - time < MAX * 120)
	{	
		// Get random values
		rR = random(0, 3);				// Random Direction
		x = random(0, this->MAX - 1);	// Random x-coordinate
		y = random(0, this->MAX - 1);	// Random y-coordinate



		if (playfield[x][y] == feld)	// starting-point must be a 'wall'-character
		{
			// Check if rand pos matches with border (preferred) or rand direction matches, set difference in pos accordingly
			

			if (x == 0 || rR == 1)				// Left border or rightwards
			{
				rR = 1;
				dx = 1;
				dy = 0;
			}
			if (x == this->MAX - 1 || rR == 3)	// Right border or leftwards
			{
				rR = 3;
				dx = -1;
				dy = 0;
			}
			if (y == 0 || rR == 2)				// Upper border or downwards
			{
				rR = 2;
				dx = 0;
				dy = 1;
			}
			if (y == this->MAX - 1 || rR == 0)	// Lower border or upwards
			{
				rR = 0;
				dx = 0;
				dy = -1;
			}



			stay = true;
			step = 0;

			// Fill the new walls stepwise
			while (stay)
			{
				// Check if next step is not surrounded by a single wall piece
				if (rR == 1 && (playfield[x + 2][y] == feld || playfield[x + 1][y + 1] == feld || playfield[x + 1][y - 1] == feld || playfield[x + 2][y - 1] == feld || playfield[x + 2][y + 1] == feld))
				{
					stay = false;
					continue;
				}
				else if (rR == 3 && (playfield[x - 2][y] == feld || playfield[x - 1][y + 1] == feld || playfield[x - 1][y - 1] == feld || playfield[x - 2][y - 1] == feld || playfield[x - 2][y + 1] == feld))
				{
					stay = false;
					continue;
				}
				else if (rR == 2 && (playfield[x][y + 2] == feld || playfield[x + 1][y + 1] == feld || playfield[x - 1][y + 1] == feld || playfield[x + 1][y + 2] == feld || playfield[x - 1][y + 2] == feld))
				{
					stay = false;
					continue;
				}
				else if (rR == 0 && (playfield[x][y - 2] == feld || playfield[x + 1][y - 1] == feld || playfield[x - 1][y - 1] == feld || playfield[x + 1][y - 2] == feld || playfield[x - 1][y - 2] == feld))
				{
					stay = false;
					continue;
				}

				//Go in direction by adding difference
				x += dx;
				y += dy;
				playfield[x][y] = feld;

				step++;

				//print new wall piece
				gotoxy(x, y);
				printf("%c", 219);
				wait_milliseconds(1);	// time delay between each piece

				//Wall must not succeed a third of max border length on one side
				if (step >= MAX * 0.3)
				{
					stay = false;
				}


			}

		}

	}

}


void MazeGenerator::wait_milliseconds(int d_milliseconds)	//time delay 
{
	clock_t endwait;
	endwait = clock() + d_milliseconds * CLK_TCK / 1000;
	while (clock() < endwait) {}
}