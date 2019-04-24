// a_Such_Algorithmus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include "AStar.h"
#include "MazeGenerator.h"
#include "RandomPathFinder.h"

char playfield[MazeGenerator::MAX][MazeGenerator::MAX] = {};	// Empty maze Array


int main()
{

	int algTime = 0;	// Variable for the needed time of the A* algorithm
	int randTime = 0;	// Variable for the needed time of the random pathfinder

	//Preparing the console
	fc::setWindowSize(1600, 1200);	// Set console size
	fc::setFontSize(10, 10);		// Set font size
	system("cls");					// Clear screen of previous logs

	//Creating the maze
	MazeGenerator generator;		// Create maze generator object
	generator.create(playfield);	// Generate maze into Array


	//Run A* Algorithm
	AStar finder(playfield);		// Create algorithm object
	algTime = finder.find();	// search for shortest path & return needed time

	//Display the needed algorithm time
	gotoxy(MazeGenerator::MAX + 3, 3);
	std::cout << "Algorithm Time:" << algTime << " MiliSec.	Press Enter";
	std::cin.ignore();


	//Run random pathfinder
	RandomPathFinder randFinder(playfield);	// Create random pathfinder object
	randTime = randFinder.find();			// search the exit using random pathfinding & return needed time

	//Display the needed random path time
	gotoxy(MazeGenerator::MAX + 3, 5);
	std::cout << "Random Time " << randTime << " MiliSec.	Press Enter";
	std::cin.ignore();



	return 1;
}