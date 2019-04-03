#include "pch.h"
#include "RandomPathFinder.h"

RandomPathFinder::RandomPathFinder(char playfield[MazeGenerator::MAX][MazeGenerator::MAX]) {
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			this->playfield[j][i] = playfield[j][i];
		}
	}
}

int RandomPathFinder::find() {
	int direction = 0, x = 1, y = 1;
	int timeCounter = clock();
	while (true) {
		direction = MazeGenerator::random(0, 3);

		switch (direction)
		{
		case 0:
			if (playfield[x][y - 1] != MazeGenerator::FIELD_CODE) {
				y--;

			}
			break;
		case 1:
			if (playfield[x + 1][y] != MazeGenerator::FIELD_CODE) {
				x++;
				

			}
			break;
		case 2:
			if (playfield[x][y + 1] != MazeGenerator::FIELD_CODE) {
				y++;

			}
			break;
		case 3:
			if (playfield[x - 1][y] != MazeGenerator::FIELD_CODE) {
				x--;

			}
			break;
		default:
			break;
		}

		/*MazeGenerator::gotoxy(x, y);
		std::cout << 'a';*/
		
		if (x == MazeGenerator::MAX - 2 && y == MazeGenerator::MAX - 2) {
			return clock() - timeCounter;
		}

	}

}