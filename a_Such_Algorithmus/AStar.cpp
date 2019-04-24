#include "pch.h"
#include "AStar.h"
#include "friendlyConsole/friendlyConsole.hpp"


AStar::AStar(char playfield[MazeGenerator::MAX][MazeGenerator::MAX])	// Constructor: applies parameter-maze to object-maze
{
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			this->playfield[j][i] = playfield[j][i];
		}
	}
}

void AStar::add(Player player, int nx, int ny)	//Adds new Point to open-List
{
	Point placeHolder;		// Assign the
	placeHolder.x = nx;		// new coordinate to
	placeHolder.y = ny;		// a placeholder

	placeHolder.toStart = player.toStart + 1;	// Inherit previous toStart
	placeHolder.toEnd = sqrt(((end.x - placeHolder.x) * (end.x - placeHolder.x)) + ((end.y - placeHolder.y) * (end.y - placeHolder.y)));	// Linear distance to goal

	placeHolder.value = placeHolder.toStart + placeHolder.toEnd;
	placeHolder.belegt = 1;

	placeHolder.xB = player.posX;	// Inherit previous
	placeHolder.yB = player.posY;	// position
							
	bool stay = true;
	int i = 0;

	// Look for open spot in open
	while (stay)
	{
		if (open[i].belegt == 0)
		{
			stay = false;
			continue;
		}
		i++;
	}
	
	open[i] = placeHolder;	// Assign placeholder to opne spot

}


bool AStar::isIn(int x, int y)	// Checks  if coordinate already exits in any List
{
	for (int i = 0; i < (tryit); i++)
	{
		if (x == open[i].x && y == open[i].y || x == closed[i].x && y == closed[i].y)
		{
			return true;
		}
	}
	return false;
}

void AStar::printPlayfield()	// Prints maze
{
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			gotoxy(i, j);
			printf("%c", playfield[i][j]);
		}
	}
}

Point AStar::findBestes()	// Looks for best Point in open-list
{
	Point placeholder;
	placeholder.value = 9999999;
	placeholder.toEnd = 9999999;
	int g = 1;
	for (int i = 0; i < (tryit); i++)
	{
		if (open[i].value < placeholder.value && open[i].belegt != 0)	// Check if current value is lower than placeholder's
		{
			placeholder = open[i];	
			g = i;

		}
		else if (open[i].value == placeholder.value && open[i].belegt != 0)	// Check if value is the same 
		{
			if (open[i].toEnd < placeholder.toEnd)	// Check if toEnd is smaller 
			{
				placeholder = open[i];
				g = i;
			}
		}
	}
	open[g].belegt = 0;	// Mark as open
	return placeholder;
}

void AStar::backtrack()	// Prints shortest way from end to start
{
	Point placeholder;
	closed[0].belegt = 1;
	for (int i = 0; i < (tryit) / 2; i++)	
	{
		if (closed[i].belegt == 0)	
		{
			placeholder = closed[i - 1];	// Last Point
			break;

		}
	}

	while (placeholder.x != start.x || placeholder.y != start.y)	// While current position is not start
	{
		// Print path-piece
		gotoxy(placeholder.x, placeholder.y);
		printf("%c", 219);

		//Look for previous-point
		for (int i = 0; i < (tryit); i++)
		{
			if (closed[i].x == placeholder.xB && closed[i].y == placeholder.yB)
			{
				placeholder = closed[i];
				break;
			}
		}
	}



}

int AStar::find()	// A* Algorithm
{
	printPlayfield();

	// Create start point values
	start.x = 1;
	start.y = 1;
	start.belegt = 1;

	// Create end point values
	end.x = MazeGenerator::MAX - 2;
	end.y = MazeGenerator::MAX - 2;


	// Create Player
	Player player;
	player.posX = start.x;
	player.posY = start.y;



	closed[0] = start;
	closed[1] = start;


	int current = 1;	// Latest closed list pos


	int timerino = clock();	// Get current time for time measure
	while (true)
	{
		

		// Look for empty points around current pos and add them to open
		if (playfield[player.posX][player.posY + 1] != SQUARE_CODE && !isIn(player.posX, player.posY + 1))
		{
			add(player, player.posX, player.posY + 1);
		}
		if (playfield[player.posX][player.posY - 1] != SQUARE_CODE && !isIn(player.posX, player.posY - 1))
		{
			add(player, player.posX, player.posY - 1);
		}
		if (playfield[player.posX - 1][player.posY] != SQUARE_CODE && !isIn(player.posX - 1, player.posY))
		{
			add(player, player.posX - 1, player.posY);
		}
		if (playfield[player.posX + 1][player.posY] != SQUARE_CODE && !isIn(player.posX + 1, player.posY))
		{
			add(player, player.posX + 1, player.posY);
		}


		if (!IsSomethingInOpen())
		{
			return false;	// There is no path to end
		}

		
		closed[current] = findBestes();			// Add best Point of the open-list to the closed-list
		

		// Assign best point to player
		player.posX = closed[current].x;			
		player.posY = closed[current].y;			
		player.toStart = closed[current].toStart;	
		current++;									// Update new latest pos in closed


		if (player.posX == end.x && player.posY == end.y)	// Print shortest Path if end is reached
		{
			backtrack();
			return clock() - timerino;	// Return needed Time
		}

	}


}


bool AStar::IsSomethingInOpen()	// Checks if open is empty
{
	for (int i = 0; i < tryit; i++)
	{
		if (open[i].belegt == 1)
		{
			return true;
		}
	}
	return false;
}