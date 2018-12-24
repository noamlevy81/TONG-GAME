#ifndef _Ball_h
#define _Ball_h

#include "windows.h"
#include "Screen.h"
#include "Point.h"
#include <vector>
#include <math.h>

enum { NUM_POINTS = 8 };
const char BALL_SHAPE = 'O';

class Ball {
	vector <Point> ballPoints;				//save points for all the ball points .
	int dir_x, dir_y;

	//private methods:
	void initalizeBall()
	{
		ballPoints.clear();
		ballPoints.push_back({ 39,11,'O' });
		ballPoints.push_back({ 40,11,'O' });
		ballPoints.push_back({ 38,12,'O' });
		ballPoints.push_back({ 39,12,'O' });
		ballPoints.push_back({ 40,12,'O' });
		ballPoints.push_back({ 41,12,'O' });
		ballPoints.push_back({ 39,13,'O' });
		ballPoints.push_back({ 40,13,'O' });
	}

	void draw() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_RED);

		for (int i = 0; i < NUM_POINTS; i++)
			ballPoints.at(i).draw();

		SetConsoleTextAttribute(h, 15);

	}
	void setDir() {
		setDirY();
		setDirX();
	}

	void setDirX()
	{
		if (dir_x == 1)
		{
			if (Screen::isOnXBorder(ballPoints.at(5).getX() + dir_x, dir_x))
			{
				if (Screen::isOnYOfThePaddles(ballPoints.at(5).getY(), dir_x, dir_y))//goes right and hit the board dirx = 1 diry = 1 or -1 . 
				{
					int temp = dir_y;
					animationHitPaddleRight();
					dir_y = temp;
					dir_x = -1;
				}

				else if (Screen::isOnYCornerofTheRightPaddle(ballPoints.at(5).getY() + dir_y, dir_y))
				{
					animationHitCornerPaddleRight();
					dir_x *= -1;
					dir_y *= -1;
				}
				else
				{
					Screen::pushPaddle(dir_x);
					Screen::setPointLost(true);
				}
			}
		}

		else      //dir_x is -1 means that we goes left . 
		{
			if (Screen::isOnXBorder(ballPoints.at(2).getX() + dir_x, dir_x))
			{
				// if on y just dir_x *= -1 .
				if (Screen::isOnYOfThePaddles(ballPoints.at(2).getY(), dir_x, dir_y))
				{
					dir_x *= -1;
				}
				else if (Screen::isOnYCornerofTheLeftPaddle(ballPoints.at(2).getY() + dir_y, dir_y))
				{
					dir_x *= -1;
					dir_y *= -1;
				}
				else
				{
					Screen::pushPaddle(dir_x);
					Screen::setPointLost(true);
				}
			}
		}
	}

	void animationHitPaddleRight()
	{
		int direction = dir_y;

		eraseBall();

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_RED);

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

		ballPoints.at(0).erase();
		ballPoints.at(1).erase();
		ballPoints.at(2).erase();
		ballPoints.at(3).erase();
		ballPoints.at(4).erase();
		ballPoints.at(6).erase();
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

	void animationHitCornerPaddleRight()
	{

	}


	void setDirY() {
		if (ballPoints.at(0).getY() + dir_y <= Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y >= Screen::BOTTOM_BORDER)
			dir_y *= -1;
	}

public:
	Ball(int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2)) : dir_x(dir_x1), dir_y(dir_y1)
	{
		initalizeBall();
	}

	//draw the ball when he born . 
	void drawBall()
	{
		initalizeBall();
		draw();
	}

	void move()
	{
		eraseBall();
		setDir();						//case hit the border we need to change the direction
		changePointsByDir();
		draw();
	}

	void changePointsByDir()
	{
		for (int i = 0; i < NUM_POINTS; i++)
		{
			ballPoints.at(i).setX(ballPoints.at(i).getX() + dir_x);
			ballPoints.at(i).setY(ballPoints.at(i).getY() + dir_y);
		}
	}

	void eraseBall()
	{
		for (int i = 0; i < NUM_POINTS; i++)
			ballPoints.at(i).erase();
	}

	friend class Game;
	friend class Screen;
};

#endif 

