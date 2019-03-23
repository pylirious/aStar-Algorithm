// a_Such_Algorithmus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

void add(int valueX, int valueY, int list[][2]);


const int MAX_HEIGHT = 20;
const int MAX_WIDTH = 20;

const int SQUARE_CODE = 219;



struct Player {
	int posX, posY;
};

struct Point {
	int x, y;
};

void main(){

	int open[(MAX_WIDTH * MAX_HEIGHT) / 2][2] = { {0, -255}};
	int closed[(MAX_WIDTH * MAX_HEIGHT) / 2][2];


	char playfield[MAX_WIDTH][MAX_HEIGHT] = {
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   "

	};

	Point start;
	start.x = 0;
	start.y = 4;
	Point end;
	end.x = 14;
	end.y = 2;

	Player player;
	player.posX = start.x;
	player.posY = start.y;


	
	closed[0][0] = start.x;
	closed[0][1] = start.y;

	while (true) {
		if (playfield[player.posX][player.posY - 1] != SQUARE_CODE) {

		}if (playfield[player.posX][player.posY +1 ] != SQUARE_CODE) {

		}if (playfield[player.posX -1][player.posY] != SQUARE_CODE) {

		}if (playfield[player.posX +1][player.posY] != SQUARE_CODE) {

		}
	}
	
}

void add(int valueX, int valueY, int list[][2]) {
	int i = 0;
	bool stay = true;
	while (stay) {
		if (list[i][0] == -255) {
			stay = false;
			continue;
		}
		i++;
	}
	list[i][0] = valueX;
	list[i][1] = valueY;
	list[i + 1][0] = -255;

}