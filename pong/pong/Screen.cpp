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

void Screen::pushFiveSteps(int to)
{
	if (to == 1)
	{
		rightPaddle->erase();
		rightPaddle->up.setX(rightPaddle->up.getX() + 5);
		rightPaddle->down.setX(rightPaddle->down.getX() + 5);
		lifeRight += 5;
	}
	else
	{
		leftPaddle->erase();
		leftPaddle->up.setX(leftPaddle->up.getX() - 5);
		leftPaddle->down.setX(leftPaddle->down.getX() - 5);
		lifeLeft += 5;
	}
}


void Screen:: pushPaddle(int ballDirX, int numOfTimes)	// this method update the x value of the paddle in case of lose one point 
{
	leftPaddle->erase();
	rightPaddle->erase();
	if (ballDirX == 1)
	{
		rightPaddle->up.setX(rightPaddle->up.getX() - numOfTimes);
		rightPaddle->down.setX(rightPaddle->down.getX() - numOfTimes);
		lifeRight -= numOfTimes;
	}
	else
	{
		leftPaddle->up.setX(leftPaddle->up.getX() + numOfTimes);
		leftPaddle->down.setX(leftPaddle->down.getX() + numOfTimes);
		lifeLeft -= numOfTimes;
	}

	returnYPaddlesToDeafult();
}

