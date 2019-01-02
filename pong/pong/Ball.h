#ifndef _Ball_h
#define _Ball_h

#include "windows.h"
#include "Screen.h"
#include "Point.h"
#include <vector>
#include <math.h>

#include "RegularState.h"
//#include "bombState.h"
//#include "BecomingAbombState.h"
//#include "BallState.h"

//class bombState;
//class BecomingAbombState;
class BallState;


enum { NUM_POINTS = 8 };
const char BALL_SHAPE = 'O';

class Ball {
	Screen *theScreen;						//we hold a reference to screen, because we want to call screen functions inside ball functions
	vector <Point> ballPoints;				//save points for all the ball points .
	int dir_x, dir_y;
	
	//BombState bomb_s;
	//BecomingAbombState BecomingABomb_s;

	RegularState regular_s;

	BallState* theState; 

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

	
public:
	Ball(Screen *the_screen , int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2)) :theScreen(the_screen), dir_x(dir_x1), dir_y(dir_y1),
		regular_s(*this, *the_screen)				//,BecomingABomb_s(*this, *the_screen) bomb_s(*this,*the_screen)
	{
		initalizeBall();
		theState = &regular_s;

	}
	void animationHitPaddleRight();
	void animationHitPaddleLeft();

	void setDirY(int y) { dir_y = y; }
	void setDirX(int x) { dir_x = x; }

	int getY() 
	{
		return dir_y;
	}
	int getX()
	{
		return dir_x;
	}
	//draw the ball for the first time . 
	void drawBall()
	{
		initalizeBall();
		draw();
	}
	void draw(); 
	RegularState* getRegular();
	void move()
	{
		eraseBall();
		setDir();						//case hit the border we need to change the direction
		changePointsByDir();
		draw();
	}

	void changePointsByDir();

	void eraseBall();

	//BecomingAbombState& getBcomingBomb()
	//{
	//	return BecomingABomb_s;
	//}
//	BombState& getBomb() 
	//{
	//	return bomb_s;
	//}
	
	void returnToDefault(int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2))
	{
		dir_x = dir_x1;
		dir_y = dir_y1;
		initalizeBall();
		theState =&regular_s;

	}
	BallState& getCurrState() { return *theState; }
	void setTheState(BallState& newState)
	{
		theState = &newState;
	}

	friend class Screen;
};

#endif 

