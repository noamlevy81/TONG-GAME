#ifndef _Ball_h
#define _Ball_h

#include "Point.h"
#include "Screen.h"

const char BALL_SHAPE = 'O';

class Ball
{
	Point p;

	enum { LEFT_BORDER, RIGHT_BORDER };
	int x_borders[2];								//contain the left and the right border of the x cordination .
	int dir_x, dir_y;

	//private methods:

	void draw() {
		p.draw();
	}
	void setDir() {
		setDirY();
		setDirX();
	}
	
	void setDirX() {

		if (Screen::isOnXBorder(p.getX()+dir_x))
		{
			if (Screen::isOnYOfThePaddles(p.getY() , dir_x)) 
				dir_x *= -1;
			else
			{
				Sleep(75);//gameOver()
				cout << "bye";
				exit(1);
			}
		}
	}


	void setDirY() {
		if (p.getY() + dir_y == Screen::TOP_BORDER || p.getY() + dir_y == Screen::BOTTOM_BORDER)
			dir_y *= -1;
	}

	//after calling this function dir x will be ok .

public:
	Ball(Point p1 = { 40,12,BALL_SHAPE }, int dir_x1 = -1, int dir_y1 =1) : p(p1), dir_x(dir_x1), dir_y(dir_y1) {
		x_borders[LEFT_BORDER] = 4;
		x_borders[RIGHT_BORDER] = 76;
	}

	//draw the ball when he born . 
	void drawBall()
	{
		gotoxy(p.getX(), p.getY());
		draw();
	}

	void move()
	{
		p.erase();
		setDir();						//case hit the border we need to change the direction
		p.setX(p.getX() + dir_x);
		p.setY(p.getY()+dir_y);//----------------------------------dir y----------------------------- 
		draw();
	}

	friend class Game;
	friend class Screen;
};

#endif 

