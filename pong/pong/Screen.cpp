#include "Screen.h"

using namespace std ;

void Screen::printBoard() const

{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h , BACKGROUND_INTENSITY);

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

	gotoxy(10, 1);

	SetConsoleTextAttribute(h, FOREGROUND_RED);

	cout << "life " << lifeLeft;
	lifeLeft <= 9 ? cout << " " : cout << "";

	gotoxy(50, 1);

	cout << "life " << lifeRight;
	lifeRight <= 9 ? cout << " " : cout << "";

	SetConsoleTextAttribute(h, 15);
}

bool Screen::ballHitTetris(int dirx,int diry,int ballx,int bally,int *ind)//ball x holds the leftest/rightest x val
{
	int arrInd;
	*ind = 15;
	if (dirx == 1)//right side of the screen
	{
		arrInd = 79 - ballx;
		arrInd = 15 - arrInd + 1;
		if (arrInd == 15)
			return true;
		*ind = arrInd;
		return rightTetris.collisionMade(arrInd, bally + diry);
	}
	else
	{
		arrInd =ballx-1;
		arrInd = 15 - arrInd + 1;
		if (arrInd == 15)
			return true;
		*ind = arrInd;

		return leftTetris.collisionMade(arrInd, bally + diry);
	}
}


