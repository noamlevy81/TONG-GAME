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
	Screen *theScreen;						//we hold a reference to screen, because we want to call screen functions inside ball functions
	vector <Point> ballPoints;				//save points for all the ball points .
	int dir_x, dir_y;

	//private methods:
	void initalizeBall()
	{
		ballPoints.clear();
		ballPoints.push_back({ 39,11,BALL_SHAPE });
		ballPoints.push_back({ 40,11,BALL_SHAPE });
		ballPoints.push_back({ 38,12,BALL_SHAPE });
		ballPoints.push_back({ 39,12,BALL_SHAPE });
		ballPoints.push_back({ 40,12,BALL_SHAPE });
		ballPoints.push_back({ 41,12,BALL_SHAPE });
		ballPoints.push_back({ 39,13,BALL_SHAPE });
		ballPoints.push_back({ 40,13,BALL_SHAPE });
	}

	void setDir() {
		setDirY();
		setDirX();
	}
	void setDirX();
	void setDirY() {
		if (ballPoints.at(0).getY() + dir_y <= Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y >= Screen::BOTTOM_BORDER)
			dir_y *= -1;
	}

	void animationHitPaddleRight();
	void animationHitPaddleLeft();

	//need to implement . 
	
public:
	Ball(Screen *the_screen , int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2)) :theScreen(the_screen), dir_x(dir_x1), dir_y(dir_y1)
	{
		initalizeBall();
	}

	int getY()
	{
		return dir_y;
	}
	//draw the ball for the first time . 
	void drawBall()
	{
		initalizeBall();
		draw();
	}
	void draw(); 

	void move()
	{
		eraseBall();
		setDir();						//case hit the border we need to change the direction
		changePointsByDir();
		draw();
	}

	void changePointsByDir();

	void eraseBall();

	friend class Screen;
};

#endif 

