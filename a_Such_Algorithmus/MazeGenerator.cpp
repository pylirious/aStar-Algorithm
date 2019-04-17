#include <pch.h>
//#include "random.h"
#include <iostream>
#include "MazeGenerator.h"
#include <random>
#include <time.h>

int MazeGenerator::random(int min, int max) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
	dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng); dist6(rng);
	return dist6(rng);
}


MazeGenerator::MazeGenerator() {
	
}

void MazeGenerator::create(char playfield[MazeGenerator::MAX][MazeGenerator::MAX])
{
	bool stay = true;
	int counter;
	int blank = ' ';
	char feld = 'a';

	std::cout << feld;
	

	for (int i = 0; i < this->MAX; i++)
	{
		for (int j = 0; j < this->MAX; j++)
		{
			playfield[i][j] = blank;
			
		}
	}

	for (int i = 0; i < this->MAX; i++) {
		playfield[i][this->MAX -1] = feld;
		gotoxy(i, this->MAX - 1);
		printf("%c", 219);
		playfield[i][0] = feld;
		gotoxy(i, 0);
		printf("%c", 219);
		playfield[this->MAX -1][i] = feld;
		gotoxy(this->MAX - 1, i);
		printf("%c", 219);
		playfield[0][i] = feld;
		gotoxy(0, i);
		printf("%c", 219);
	}
	
	

	int rX= 0, rY = 0, rR = 0, x, y, dx = 0 ,dy = 0;

	int time = clock();
	while (clock() - time < MAX * 120) {	//Edit to time stamp

		rR = random(0, 3);
		rX = random(0, this->MAX -1);
		rY = random(0, this->MAX -1);
		

		x = rX;
		y = rY;

		if (playfield[x][y] == feld) {
			if (rX == 0 || rR ==1) {
				
				dx = 1;
				dy = 0;
			}
			else if (rX == this->MAX - 1 || rR ==3) {
				
				dx = -1;
				dy = 0;
			}
			else if (rY == 0 || rR == 2) {
				
				dx = 0;
				dy = 1;
			}
			else if (rY == this->MAX - 1 || rR == 0) {
				
				dx = 0;
				dy = -1;
			}
			if (rX == 0) {
				rR = 1;
				dx = 1;
				dy = 0;
			}
			else if (rX == this->MAX - 1) {
				rR = 3;
				dx = -1;
				dy = 0;
			}
			else if (rY == 0) {
				rR = 2;
				dx = 0;
				dy = 1;
			}
			else if (rY == this->MAX - 1) {
				rR = 0;
				dx = 0;
				dy = -1;
			}


			stay = true;
			counter = 0;
			while (stay) {
				if (rR == 1 && (playfield[x + 2][y] == feld || playfield[x + 1][y + 1] == feld || playfield[x + 1][y - 1] == feld || playfield[x + 2][y - 1] == feld || playfield[x + 2][y + 1] == feld)) {
					stay = false;
					continue;
				}else if (rR == 3 && (playfield[x - 2][y] == feld || playfield[x - 1][y + 1] == feld || playfield[x - 1][y - 1] == feld || playfield[x - 2][y - 1] == feld || playfield[x - 2][y + 1] == feld)) {
					stay = false;
					continue;
				}else if (rR == 2 && (playfield[x][y + 2] == feld || playfield[x + 1][y + 1] == feld || playfield[x - 1][y + 1] == feld || playfield[x + 1][y + 2] == feld || playfield[x - 1][y + 2] == feld)) {
					stay = false;
					continue;
				}else if (rR == 0 && (playfield[x][y - 2] == feld || playfield[x + 1][y - 1] == feld || playfield[x - 1][y - 1] == feld || playfield[x + 1][y - 2] == feld || playfield[x - 1][y - 2] == feld)) {
					stay = false;
					continue;
				}

				
				x += dx;
				y += dy;
				playfield[x][y] = feld;
				
				counter++;


				gotoxy(x, y);
				printf("%c", 219);
				wait_milliseconds(1);

				if (counter == MAX * 0.5) {
					stay = false;
				}

			
			}

		}

	}

}

//void MazeGenerator::gotoxy(int x, int y)
//{
//	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos;
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(hCon, pos);
//}

void MazeGenerator::wait_milliseconds(int d_milliseconds) 		/* Zeitverzoegerung */
{
	clock_t endwait;
	endwait = clock() + d_milliseconds * CLK_TCK / 1000;
	while (clock() < endwait) {}
}