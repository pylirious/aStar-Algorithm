// a_Such_Algorithmus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include "AStar.h"
#include "MazeGenerator.h"
#include "RandomPathFinder.h"

char playfield[MazeGenerator::MAX][MazeGenerator::MAX] = {};/* = {

"	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ",
"a   a               a               a           a                   a   a",
"a   a   aaaaaaaaa   a   aaaaa   aaaaaaaaa   aaaaa   aaaaa   aaaaa   a   a",
"a               a       a   a           a           a   a   a       a   a",
"aaaaaaaaa   a   aaaaaaaaa   aaaaaaaaa   aaaaa   a   a   a   aaaaaaaaa   a",
"a       a   a               a           a   a   a   a   a           a   a",
"a   a   aaaaaaaaaaaaa   a   a   aaaaaaaaa   aaaaa   a   aaaaaaaaa   a   a",
"a   a               a   a   a       a           a           a       a   a",
"a   aaaaaaaaaaaaa   aaaaa   aaaaa   a   aaaaa   aaaaaaaaa   a   aaaaa   a",
"a           a       a   a       a   a       a           a   a           a",
"a   aaaaa   aaaaa   a   aaaaa   a   aaaaaaaaa   a   a   a   aaaaaaaaaaaaa",
"a       a       a   a   a       a       a       a   a   a       a       a",
"aaaaaaaaaaaaa   a   a   a   aaaaaaaaa   a   aaaaa   a   aaaaa   aaaaa   a",
"a           a   a           a       a   a       a   a       a           a",
"a   aaaaa   a   aaaaaaaaa   aaaaa   a   aaaaa   aaaaa   aaaaaaaaaaaaa   a",
"a   a       a           a           a       a   a   a               a   a",
"a   a   aaaaaaaaa   a   aaaaa   aaaaaaaaa   a   a   aaaaaaaaaaaaa   a   a",
"a   a           a   a   a   a   a           a               a   a       a",
"a   aaaaaaaaa   a   a   a   aaaaa   aaaaaaaaa   aaaaaaaaa   a   aaaaaaaaa",
"a   a       a   a   a           a           a   a       a               a",
"a   a   aaaaa   aaaaa   aaaaa   aaaaaaaaa   aaaaa   a   aaaaaaaaa   a   a",
"a   a                   a           a               a               a   a",
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"



};*/

int main() {




	system("cls");
	
	MazeGenerator generator;
	generator.create(playfield);

	RandomPathFinder randFinder(playfield);
	int randTime = randFinder.find();
	MazeGenerator::gotoxy( MazeGenerator::MAX + 3, 3);
	std::cout << randTime << " MiliSec.";
	std::cin.ignore();


	AStar finder(playfield);
	if (finder.find()) {

	}

	return 1;
}