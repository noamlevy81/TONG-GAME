#include "Ball.h"

#include "Screen.h"

void Ball::draw() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	for (int i = 0; i < NUM_POINTS; i++)
		ballPoints.at(i).draw();

	SetConsoleTextAttribute(h, 15);
}

void Ball:: setDirX()
{
	if (dir_x == 1)
	{
		if (theScreen->isOnXBorder(ballPoints.at(5).getX() + dir_x, dir_x))
		{
			if (theScreen->isOnYOfThePaddles(ballPoints.at(5).getY(), dir_x, dir_y))//goes right and hit the board dirx = 1 diry = 1 or -1 . 
			{
				int temp = dir_y;
				animationHitPaddleRight();
				dir_y = temp;
				dir_x = -1;
			}

			else if (theScreen->isOnYCornerofTheRightPaddle(ballPoints.at(5).getY() + dir_y, dir_y))
			{
				dir_x *= -1;
				dir_y *= -1;
			}
			else
			{
				theScreen->pushPaddle(dir_x);
				theScreen->setPointLost(true);
			}
		}
	}

	else      //dir_x is -1 means that we goes left . 
	{
		if (theScreen->isOnXBorder(ballPoints.at(2).getX() + dir_x, dir_x))
		{
			// if on y just dir_x *= -1 .
			if (theScreen->isOnYOfThePaddles(ballPoints.at(2).getY(), dir_x, dir_y))
			{
				int temp = dir_y;
				animationHitPaddleLeft();
				dir_y = temp;
				dir_x = 1;
			}
			else if (theScreen->isOnYCornerofTheLeftPaddle(ballPoints.at(2).getY() + dir_y, dir_y))
			{
				dir_x *= -1;
				dir_y *= -1;
			}
			else
			{
				theScreen->pushPaddle(dir_x);
				theScreen->setPointLost(true);
			}
		}
	}
}

void Ball::animationHitPaddleLeft()
{
	int direction = dir_y;

	eraseBall();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	//this block take the ball one step to the paddle . 
	dir_x = -1;
	dir_y = 0;
	changePointsByDir();

	if (direction != 1)
		ballPoints.at(1).draw();
	else
		ballPoints.at(7).draw();

	ballPoints.at(0).draw();
	ballPoints.at(3).draw();
	ballPoints.at(4).draw();
	ballPoints.at(5).draw();
	ballPoints.at(6).draw();

	Sleep(50);

	SetConsoleTextAttribute(h, 15);
	////////////////////////////////////////////

	if (direction != 1)
		ballPoints.at(1).erase();
	else
		ballPoints.at(7).erase();

	ballPoints.at(0).erase();
	ballPoints.at(3).erase();
	ballPoints.at(4).erase();
	ballPoints.at(5).erase();
	ballPoints.at(6).erase();


	dir_y = direction;
	dir_x = 1;

	changePointsByDir();

	int point1, point2;

	if (direction == -1)
	{
		point1 = 6;
		point2 = 7;
	}
	else
	{
		point1 = 0;
		point2 = 1;
	}

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() + 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() + 1);

	Sleep(50);
	draw();


	dir_x = 0;

	eraseBall();

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() -1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() - 1);

	Sleep(20);
	draw();
	Sleep(20);
	eraseBall();

	dir_x = 1;
}
void Ball:: animationHitPaddleRight()
{
	int direction = dir_y;

	eraseBall();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	//this block take the ball one step to the paddle . 
	dir_x = 1;
	dir_y = 0;
	changePointsByDir();

	if (direction != 1)
		ballPoints.at(0).draw();
	else
		ballPoints.at(6).draw();

	ballPoints.at(1).draw();
	ballPoints.at(2).draw();
	ballPoints.at(3).draw();
	ballPoints.at(4).draw();
	ballPoints.at(7).draw();

	Sleep(50);

	SetConsoleTextAttribute(h, 15);
	////////////////////////////////////////////

	if (direction != 1)
		ballPoints.at(0).erase();
	else
		ballPoints.at(6).erase();

	ballPoints.at(1).erase();
	ballPoints.at(2).erase();
	ballPoints.at(3).erase();
	ballPoints.at(4).erase();
	ballPoints.at(7).erase();

	dir_y = direction;
	dir_x = -1;

	changePointsByDir();

	int point1, point2;

	if (direction == -1)
	{
		point1 = 6;
		point2 = 7;
	}
	else
	{
		point1 = 0;
		point2 = 1;
	}

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() + 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() + 1);

	Sleep(50);
	draw();


	dir_x = 0;

	eraseBall();

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() - 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() - 1);

	Sleep(20);
	draw();
	Sleep(20);
	eraseBall();

	dir_x = -1;
}

void Ball::changePointsByDir()
{
	for (int i = 0; i < NUM_POINTS; i++)
	{
		ballPoints.at(i).setX(ballPoints.at(i).getX() + dir_x);
		ballPoints.at(i).setY(ballPoints.at(i).getY() + dir_y);
	}
}

void Ball::eraseBall()
	{
		for (int i = 0; i < NUM_POINTS; i++)
			ballPoints.at(i).erase();
	}