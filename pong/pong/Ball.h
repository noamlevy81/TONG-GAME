#ifndef _Ball_h
#define _Ball_h

#include "Screen.h"
#include "Point.h"
#include <vector>

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
		for (int i = 0; i < NUM_POINTS; i++)
			ballPoints.at(i).draw();
	}
	void setDir() {
		setDirY();
		setDirX();
	}

	void setDirX()
	{
		if (dir_x == 1)
		{
			if (Screen::isOnXBorder(ballPoints.at(5).getX() + dir_x))
			{
				if (Screen::isOnYOfThePaddles(ballPoints.at(5).getY(), dir_x))
					dir_x *= -1;

				else if (dir_y == 1)
				{
					if (Screen::isOnYCornerofTheRightPaddlesComeFromUp(ballPoints.at(7).getY(), dir_y))
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
				else if (Screen::isOnYCornerofTheRightPaddlesComeFromDown(ballPoints.at(1).getY(), dir_y))
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

		else                       //dir_x is -1 means that we goes left . 
		{
			if (Screen::isOnXBorder(ballPoints.at(2).getX() + dir_x))
			{
				if (Screen::isOnYOfThePaddles(ballPoints.at(2).getY(), dir_x))		// if on y just dir_x *= -1 .
					dir_x *= -1;

				else if (dir_y == 1)					//check corner come from up
				{
					if (Screen::isOnYCornerofTheLeftPaddlesComeFromUp(ballPoints.at(6).getY(), dir_y))
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
				else if (Screen::isOnYCornerofTheLeftPaddlesComeFromUp(ballPoints.at(6).getY(), dir_y)) // (dir_y == -1) // means come from down 
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


	void setDirY() {
		if (ballPoints.at(0).getY() + dir_y == Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y == Screen::BOTTOM_BORDER)
			dir_y *= -1;
	}

public:
	Ball(int dir_x1 = -1, int dir_y1 = 1) : dir_x(dir_x1), dir_y(dir_y1)
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

