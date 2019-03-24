// a_Such_Algorithmus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include "gotoxy.h"
#include "wait.h"

void add(int valueX, int valueY);
void swap(int index1, int index2);
void sort(int length);
bool isIn(int x, int y);
void zeichne_spielfeld();

const int MAX_HEIGHT = 60;
const int MAX_WIDTH = 60;

const int SQUARE_CODE = 'a';
const char BLANK_CODE = ' ';


char playfield[MAX_WIDTH][MAX_HEIGHT] = {
	/*
	"aaaaaaaaaaaaaaaaaaa",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"a    aa           a",
	"a  a  a           a",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"a     a            ",
	"a     a           a",
	"a     a           a",
	"a                 a",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"a     a           a",
	"aaaaaaaaaaa aaaaaaa"
	*/

};


struct Player {
	int posX, posY;
};

struct Point {
	int x = 0, y = 0, belegt = 0;
	float value = 0, toStart = 0, toEnd = 0;

};

Point open[(MAX_WIDTH * MAX_HEIGHT) / 2];
Point closed[(MAX_WIDTH * MAX_HEIGHT) / 2];
Point start;
Point end;



int main() {
	zeichne_spielfeld();
	int actual = 1;
	


	
	start.x = 1;
	start.y = 4;
	
	
	end.x = 4;
	end.y = 40;
	


	
	Player player;
	player.posX = start.x;
	player.posY = start.y;



	closed[0] = start;

	int actually = 1;
	int maxOpen = 0;

	Point blank;
	

	gotoxy(start.x, start.y);
	printf("%c", 's');
	gotoxy(end.x, end.y);
	printf("%c", 'z');


	while (true) {
		wait_milliseconds(20);
		if (playfield[player.posX][player.posY + 1] != SQUARE_CODE && !isIn(player.posX, player.posY + 1)) {
			add(player.posX, player.posY + 1);
			maxOpen++;
		}if (playfield[player.posX][player.posY - 1] != SQUARE_CODE && !isIn(player.posX, player.posY - 1)) {
			add(player.posX, player.posY - 1);
			maxOpen++;
		}if (playfield[player.posX - 1][player.posY] != SQUARE_CODE && !isIn(player.posX -1 , player.posY)) {
			add(player.posX - 1, player.posY);
			maxOpen++;
		}if (playfield[player.posX + 1][player.posY] != SQUARE_CODE && !isIn(player.posX + 1, player.posY )) {
			add(player.posX + 1, player.posY);
			maxOpen++;
		}
		gotoxy(player.posX, player.posY);
		//printf("%c", BLANK_CODE);

		sort((MAX_WIDTH * MAX_HEIGHT) / 2);
		if (open[0].belegt== 0) {
			printf("Verloren");
			break;
		}
		closed[actually] = open[0];
		player.posX = closed[actually].x;
		player.posY = closed[actually].y;
		actually++;
		open[0] = blank;

		gotoxy(player.posX, player.posY);
		printf("u");

		if (player.posX == end.x && player.posY == end.y) {
			std::cout << "gewonnen!";
			break;
		}

	}

}

void add(int valueX, int valueY) {
	Point placeHolder;
	placeHolder.x = valueX;
	placeHolder.y = valueY;

	int i = 0;
	bool stay = true;
	while (stay) {
		if (open[i].belegt == 0) {
			stay = false;
			continue;
		}
		i++;
	}
	open[i] = placeHolder;

	open[i].toStart = sqrt(((start.x - open[i].x) * (start.x - open[i].x))   + ((start.y - open[i].y) * (start.y - open[i].y)));
	open[i].toEnd = sqrt(((end.x - open[i].x) * (end.x - open[i].x))   + ((end.y - open[i].y) * (end.y - open[i].y)));

	open[i].value = open[i].toStart + open[i].toEnd;
	open[i].belegt = 1;
}


void swap(int index1, int index2) {
	Point temp = open[index1];
	open[index1] = open[index2];
	open[index2] = temp;
}

void sort(int length) {
	int flag = 0;

	for (int i = 0; i < length; i++) {
		if ((open[i].belegt == 0 && open[i + 1].belegt != 0) || open[i].value > open[i + 1].value && open[i +1].belegt != 0) {
			swap(i, i + 1);
			flag + 1;
		}
	}
	if (flag != 0) {
		sort(length - 1);
	}

	
}

bool isIn(int x, int y) {
	for (int i = 0; i < (MAX_WIDTH*MAX_HEIGHT) / 2; i++) {
		if (x == open[i].x && y == open[i].y || x == closed[i].x && y == closed[i].y) {
			return true;
		}
	}
	return false;
}

void zeichne_spielfeld()
{
	int i, j;
	// Belegung des Arrays spielfeld
	for (i = 0; i < MAX_WIDTH; i++)
	{
		for (j = 0; j < MAX_HEIGHT; j++)
		{
			//SCHAUEN
			gotoxy(i, j);
			printf("%c", playfield[i][j]);
		}
	}
}