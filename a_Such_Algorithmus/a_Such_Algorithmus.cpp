// a_Such_Algorithmus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include "gotoxy.h"
#include "wait.h"

struct Point;

void add(int valueX, int valueY, int beforetoStart, int xB, int yB);
void swap(int index1, int index2);
void sort(int length);
bool isIn(int x, int y);
void zeichne_spielfeld();
Point findBestes();
void backtrack();

const int MAX_HEIGHT = 60;
const int MAX_WIDTH = 100;

const int SQUARE_CODE = 'a';
const char BLANK_CODE = ' ';


char playfield[MAX_HEIGHT][MAX_WIDTH] = {

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



};



struct Player {
	int posX, posY;
};

struct Point {
	int x = 0, y = 0, belegt = 0;
	float value = 0, toStart = 0, toEnd = 0;
	int xB, yB;

};

Point open[(MAX_WIDTH * MAX_HEIGHT) / 2];
Point closed[(MAX_WIDTH * MAX_HEIGHT) / 2];
Point start;
Point end;



int main() {
	zeichne_spielfeld();
	int actual = 1;




	start.x = 1;
	start.y = 1;
	start.belegt = 1;


	end.x = 3;
	end.y = 70;




	Player player;
	player.posX = start.x;
	player.posY = start.y;



	closed[0] = start;
	closed[1] = start;

	int actually = 1;
	int maxOpen = 0;

	Point blank;


	gotoxy(start.x, start.y);
	printf("%c", 's');
	gotoxy(end.x, end.y);
	printf("%c", 'z');


	while (true) {
		//wait_milliseconds(10);
		if (playfield[player.posX][player.posY + 1] != SQUARE_CODE && !isIn(player.posX, player.posY + 1)) {
			add(player.posX, player.posY + 1, closed[actually].toStart, player.posX, player.posY);
			maxOpen++;
		}if (playfield[player.posX][player.posY - 1] != SQUARE_CODE && !isIn(player.posX, player.posY - 1)) {
			add(player.posX, player.posY - 1, closed[actually].toStart, player.posX, player.posY);
			maxOpen++;
		}if (playfield[player.posX - 1][player.posY] != SQUARE_CODE && !isIn(player.posX - 1, player.posY)) {
			add(player.posX - 1, player.posY, closed[actually].toStart, player.posX, player.posY);
			maxOpen++;
		}if (playfield[player.posX + 1][player.posY] != SQUARE_CODE && !isIn(player.posX + 1, player.posY)) {
			add(player.posX + 1, player.posY, closed[actually].toStart, player.posX, player.posY);
			maxOpen++;
		}
		gotoxy(player.posX, player.posY);
		printf("%c", BLANK_CODE);

		sort((MAX_WIDTH * MAX_HEIGHT) / 2);
		
		if (open[0].belegt == 0) {
			printf("Verloren");
			break;
		}


		closed[actually] = findBestes();

		player.posX = closed[actually].x;
		player.posY = closed[actually].y;
		actually++;


		gotoxy(player.posX, player.posY);
		printf("*");

		if (player.posX == end.x && player.posY == end.y) {
			backtrack();
			break;
		}

	}
	gotoxy(40, 100);

}

void add(int valueX, int valueY, int beforetoStart, int xB, int yB) {
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

	open[i].toStart = beforetoStart + 1;
	//open[i].toStart = sqrt(((start.x - open[i].x) * (start.x - open[i].x)) + ((start.y - open[i].y) * (start.y - open[i].y)));
	open[i].toEnd = sqrt(((end.x - open[i].x) * (end.x - open[i].x)) + ((end.y - open[i].y) * (end.y - open[i].y)));
	//open[i].toEnd = abs((end.x - open[i].x) + (end.y - open[i].y));
	open[i].value = open[i].toStart + open[i].toEnd;
	open[i].belegt = 1;
	open[i].xB = xB;
	open[i].yB = yB;
}


void swap(int index1, int index2) {
	Point temp = open[index1];
	open[index1] = open[index2];
	open[index2] = temp;
}

void sort(int length) {
	int flag = 0;

	for (int i = 0; i < length; i++) {
		if ((open[i].belegt == 0 && open[i + 1].belegt != 0) || (open[i].value > open[i + 1].value && open[i + 1].belegt != 0) || (open[i].value == open[i + 1].value && open[i].toEnd > open[i + 1].toEnd)) {
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
	for (i = 0; i < MAX_HEIGHT; i++)
	{
		for (j = 0; j < MAX_WIDTH; j++)
		{
			//SCHAUEN
			gotoxy(i, j);
			printf("%c", playfield[i][j]);
		}
	}
}
Point findBestes()
{
	Point usage;
	usage.value = 9999999;
	usage.toEnd = 9999999;
	int g = 1;
	for (int i = 0; i < (MAX_WIDTH * MAX_HEIGHT) / 2; i++) {
		if (open[i].value < usage.value && open[i].belegt != 0) {
			usage = open[i];
			g = i;
			
		}
		else if (open[i].value == usage.value && open[i].belegt != 0)
		{
			if (open[i].toEnd < usage.toEnd) {
				usage = open[i];
				g = i;
			}
		}
	}
	open[g].belegt = 0;
	return usage;
}

void backtrack() {
	Point point;
	int g;
	closed[0].belegt = 1;
	for (int i = 0; i < (MAX_WIDTH * MAX_HEIGHT) / 2; i++) {
		if (closed[i].belegt == 0) {
			point = closed[i - 1];
			break;

		}
	}
	while (point.x != start.x || point.y != start.y) {
		gotoxy(point.x, point.y);
		printf("%c", 219);
		for (int i = 0; i < (MAX_WIDTH * MAX_HEIGHT) / 2; i++) {
			if (closed[i].x == point.xB && closed[i].y == point.yB) {
				point = closed[i];
				break;
			}
		}
	}



}