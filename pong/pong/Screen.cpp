#include "Screen.h"

using namespace std ;

void Screen::printBoard()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h , BACKGROUND_GREEN);

	int x = 0;
	int y = 3;
	//prints horizonal game borders
	for (int i = 0; i < 162; i++)
	{
		if (i == 81)
		{
			y = 25;
			x -= 81;
		}
		gotoxy(x + i, y);
		cout << " ";
	}

	x = 0;
	y = 4;
	//prints vertical game borders
	for (int i = 0; i < 42; i++)
	{
		if (i == 21)
		{
			x = 80;
			y -= 21;
		}
		gotoxy(x, y + i);
		cout << " ";
	}

	SetConsoleTextAttribute(h, 15);

	gotoxy(10, 2);

	cout << "life " << lifeLeft;
	lifeLeft == 9 ? cout << " " : cout << "";

	gotoxy(50, 2);

	cout << "life " << lifeRight;
	lifeRight == 9 ? cout << " " : cout << "";


}