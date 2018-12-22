#include "Screen.h"

Paddle* Screen::leftPaddle = nullptr;
Paddle* Screen::rightPaddle = nullptr;

Tetris Screen::left = Tetris();//--------------------------added for check-----------------------

bool Screen::pointLost = false;

void Screen::printBoard()
{
	int x = 1;
	int y = 4;
    //prints horizonal game borders
	for (int i = 0; i < 158 ; i++)
	{
		if (i == 79)
		{
			y = 24;
			x -= 79;
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
