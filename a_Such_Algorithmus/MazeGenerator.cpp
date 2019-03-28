#include "pch.h"
#include "random.h"
#include "MazeGenerator.h"
MazeGenerator::MazeGenerator() {

}

void MazeGenerator::create(char playfield[MazeGenerator::MAX][MazeGenerator::MAX])
{
	bool stay = true;
	int counter;
	int blank = ' ';
	int feld = 'a';

	for (int i = 0; i < this->MAX; i++)
	{
		for (int j = 0; j < this->MAX; j++)
		{
			playfield[i][j] = blank;
			
		}
	}

	for (int i = 0; i < this->MAX; i++) {
		playfield[i][this->MAX -1] = feld;
		playfield[i][0] = feld;
		playfield[this->MAX -1][i] = feld;
		playfield[0][i] = feld;
	}
	
	

	int rX, rY, rR, x, y, dx ,dy;

	int time = clock();
	while (clock() - time < 3000) {	//Edit to time stamp
		rR = getrandom_int(0, 3);
		rX = getrandom_int(0, this->MAX -1);
		rY = getrandom_int(0, this->MAX -1);

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
				if (counter == 5) {
					stay = false;
				}

			
			}

		}

	}

}

void MazeGenerator::gotoxy(int x, int y)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon, pos);
}

