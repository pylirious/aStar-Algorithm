#include "pch.h"
#include "AStar.h"

AStar::AStar(char playfield[MazeGenerator::MAX][MazeGenerator::MAX]) {
	// Belegung des Arrays spielfeld
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			this->playfield[j][i] = playfield[j][i];
		}
	}
}

void AStar::add(Player player, int nx, int ny) {
	Point placeHolder;
	placeHolder.x = nx; 
	placeHolder.y = ny;

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

	open[i].toStart = player.toStart + 1;
	open[i].toEnd = sqrt(((end.x - open[i].x) * (end.x - open[i].x)) + ((end.y - open[i].y) * (end.y - open[i].y)));	//Luftlinie zum Ziel
	//open[i].toEnd = abs((end.x - open[i].x) + (end.y - open[i].y));				//X + Y Abstand Variation
	open[i].value = open[i].toStart + open[i].toEnd;
	open[i].belegt = 1;
	open[i].xB = player.posX;
	open[i].yB = player.posY;
}

void AStar::swap(int index1, int index2) {
	Point temp = open[index1];
	open[index1] = open[index2];
	open[index2] = temp;
}

void AStar::sort(int length) {
	int flag = 0;

	for (int i = 0; i < length; i++) {
		if ((open[i].belegt == 0 && open[i + 1].belegt != 0) || (open[i].value > open[i + 1].value && open[i + 1].belegt != 0) || (open[i].value == open[i + 1].value && open[i].toEnd > open[i + 1].toEnd)) {
			
			swap(i, i + 1);
			flag++;

		}
	}
	if (flag != 0) {
		sort(length - 1);
	}


}

bool AStar::isIn(int x, int y) {
	for (int i = 0; i < (tryit); i++) {
		if (x == open[i].x && y == open[i].y || x == closed[i].x && y == closed[i].y) {
			return true;
		}
	}
	return false;
}

void AStar::zeichne_spielfeld()
{
	// Belegung des Arrays spielfeld
	for (int i = 0; i < MazeGenerator::MAX; i++)
	{
		for (int j = 0; j < MazeGenerator::MAX; j++)
		{
			//SCHAUEN
			gotoxy(i, j);
			printf("%c", playfield[i][j]);
		}
	}
}

Point AStar::findBestes()
{
	Point usage;
	usage.value = 9999999;
	usage.toEnd = 9999999;
	int g = 1;
	for (int i = 0; i < (tryit); i++) {
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

void AStar::backtrack() {
	Point point;
	closed[0].belegt = 1;
	for (int i = 0; i < (tryit) / 2; i++) {
		if (closed[i].belegt == 0) {
			point = closed[i - 1];
			break;

		}
	}
	while (point.x != start.x || point.y != start.y) {
		gotoxy(point.x, point.y);
		printf("%c", 219);
		for (int i = 0; i < (tryit); i++) {
			if (closed[i].x == point.xB && closed[i].y == point.yB) {
				point = closed[i];
				break;
			}
		}
	}



}

bool AStar::find() {
	zeichne_spielfeld();

	start.x = 1;
	start.y = 1;
	start.belegt = 1;


	end.x = 48;
	end.y = 48;

	Player player;
	player.posX = start.x;
	player.posY = start.y;



	closed[0] = start;
	closed[1] = start;

	int actually = 1;

	Point blank;


	gotoxy(start.x, start.y);
	printf("%c", 219);
	gotoxy(end.x, end.y);
	printf("%c", 219);


	while (true) {
		wait_milliseconds(10);
		if (playfield[player.posX][player.posY + 1] != SQUARE_CODE && !isIn(player.posX, player.posY + 1)) {
			add(player, player.posX, player.posY + 1);
		}if (playfield[player.posX][player.posY - 1] != SQUARE_CODE && !isIn(player.posX, player.posY - 1)) {
			add(player, player.posX, player.posY - 1);
		}if (playfield[player.posX - 1][player.posY] != SQUARE_CODE && !isIn(player.posX - 1, player.posY)) {
			add(player, player.posX - 1, player.posY);
		}if (playfield[player.posX + 1][player.posY] != SQUARE_CODE && !isIn(player.posX + 1, player.posY)) {
			add(player, player.posX + 1, player.posY);
		}
		gotoxy(player.posX, player.posY);
		printf("%c", BLANK_CODE);

		sort((tryit));

		if (open[0].belegt == 0 && open[1].belegt == 0) {
			return false;
		}

		
		closed[actually] = findBestes();

		player.posX = closed[actually].x;
		player.posY = closed[actually].y;
		player.toStart = closed[actually].toStart;
		actually++;


		gotoxy(player.posX, player.posY);
		printf("*");

		if (player.posX == end.x && player.posY == end.y) {
			backtrack();
			return true;
		}

	}
	

}

void AStar::gotoxy(int x, int y)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon, pos);
}

void AStar::wait_milliseconds(int d_milliseconds) 		/* Zeitverzoegerung */
{
	clock_t endwait;
	endwait = clock() + d_milliseconds * CLK_TCK / 1000;
	while (clock() < endwait) {}
}
