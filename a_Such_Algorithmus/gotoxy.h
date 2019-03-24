#include <Windows.h>

void gotoxy(int x, int y)
{
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hCon, pos); 
}
