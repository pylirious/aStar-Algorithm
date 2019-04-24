#include "pch.h"
#include "RandomPathFinder.h"

RandomPathFinder::RandomPathFinder(char playfield[MazeGenerator::MAX][MazeGenerator::MAX])	// Constructor: applies parameter-maze to object-maze
{
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			this->playfield[j][i] = playfield[j][i];
		}
	}
}

int RandomPathFinder::find()	// Random pathfinding
{

	int direction = 0, x = 1, y = 1;
	int timeCounter = clock();
	while (true)
	{
		direction = MazeGenerator::random(0, 3);	// Get random direction


		// Go a step if there is no wall
		switch (direction)
		{
		case 0:
			if (playfield[x][y - 1] != MazeGenerator::FIELD_CODE)
			{
				y--;

			}
			break;
		case 1:
			if (playfield[x + 1][y] != MazeGenerator::FIELD_CODE)
			{
				x++;


			}
			break;
		case 2:
			if (playfield[x][y + 1] != MazeGenerator::FIELD_CODE)
			{
				y++;

			}
			break;
		case 3:
			if (playfield[x - 1][y] != MazeGenerator::FIELD_CODE)
			{
				x--;

			}
			break;
		default:
			break;
		}

		// Print a character on current pos
		
		gotoxy(x, y);
		std::cout << char(219);

		

		if (x == MazeGenerator::MAX - 2 && y == MazeGenerator::MAX - 2)	// End reached
		{
			return clock() - timeCounter;	// Return needed Time
		}

	}

}