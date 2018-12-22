#include "Screen.h"

using namespace std ;

Paddle* Screen::leftPaddle = nullptr;
Paddle* Screen::rightPaddle = nullptr;

Tetris Screen::left = Tetris();//--------------------------added for check-----------------------

bool Screen::pointLost = false;

void Screen::printBoard()
{
	int x = 0;
	int y = 3;
    //prints horizonal game borders
	for (int i = 0; i < 162 ; i++)
	{
		if (i == 81)
		{
			y = 25;
			x -= 81;
		}
		gotoxy(x + i, y);
		cout << "-";
	}

	x = 1;
	y = 5;
    //prints vertical game borders
	for (int i = 0; i < 38; i++)
	{
		if (i == 19)
		{
			x = 79;
			y -= 19;
		}
		gotoxy(x, y + i);
		cout << '|';
	}

}
