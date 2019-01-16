#ifndef _Ball_h
#define _Ball_h

#include "windows.h"
#include "Screen.h"
#include "Point.h"
#include <vector>
#include <math.h>
#include "kbListener.h"

#include "RegularState.h"
#include "BombState.h"
#include "BecomingAbombState.h"

const char BALL_SHAPE = 'O';
enum { NUM_POINTS = 8 };

class Ball : public kbListener {
	Screen *theScreen;						//hold a reference to screen, because we want to call screen functions inside ball functions
	vector <Point> ballPoints;				//save points for all the ball points .
	int dir_x, dir_y;

	size_t gameLoopCount; 

	BombState bomb_s;
	BecomingAbombState BecomingABomb_s;
	RegularState regular_s;
	BallState* theState;
	int bombPressedLeft, bombPressedRight;
	char bombKeys[MAX_KEYS] = { 's','k' };
	//private methods:

	void initalizeBall();
	

	void setDir() {
		setDirX();
		setDirY();
	}
	void setDirX();
	void setDirY() {
		if (ballPoints.at(0).getY() + dir_y <= Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y >= Screen::BOTTOM_BORDER)
			dir_y *= -1;
	}
	void changePointsByDir();
	void setBombPressed() {
		if (ballPoints.at(5).getX() == ArenaCenter::ARENA_CENTER)
		{
			bombPressedLeft++;
			bombPressedRight++;
		}
	}

public:
	Ball(Screen *the_screen, int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2)) :theScreen(the_screen), dir_x(dir_x1), dir_y(dir_y1),
		regular_s(*this, *the_screen), BecomingABomb_s(*this, *the_screen),bomb_s(*this,*the_screen)
	{
		initalizeBall();
		setTheState(regular_s);

	}
	void resetBombPressedLeft() { bombPressedLeft = 0; }
	void resetBombPressedRight() { bombPressedRight = 0; }

	void setDirY(int y) { dir_y = y; }
	void setDirX(int x) { dir_x = x; }


	int getDirY() const
	{
		return dir_y;
	}
	int getDirX() const
	{
		return dir_x;
	}
	
	void draw();

	void animationHitPaddleRight();
	void animationHitPaddleLeft();

	//draw the ball for the first time . 
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
		gameLoopCount++;
		theState->timeEvent();
		setBombPressed();
	}

	void eraseBall();

	void returnToDefault(int dir_x1 = pow(-1, rand() % 2), int dir_y1 = pow(-1, rand() % 2))
	{
		eraseBall();
		initalizeBall();
		dir_x = dir_x1;
		dir_y = dir_y1;
		setTheState(regular_s);
	}

	int getXFromArr(int x) const
	{
		return ballPoints.at(x).getX();
	}
	int getYFromArr(int x) const
	{
		return ballPoints.at(x).getY();
	}
	size_t getLoopGameCounter()
	{
		return gameLoopCount;
	}
	const char * getChars()
	{
		return bombKeys;
	}
	//one of the players pressed bomb key 
	void changeCurrentKey(char key)
	{
		theState->bombKeyPressed(key);
	}
	void setGameLoopCounter(int x = 0) {
		if (x)
			gameLoopCount++;
		else
			gameLoopCount = 0;
	}

	void setTheState(BallState& newState)
	{
		theState = &newState;
		setGameLoopCounter();
	}
	int getBombPressedLeft() { return bombPressedLeft; }
	int getBombPressedRight() { return bombPressedRight; }

	BallState& getCurrState() { return *theState; }
	BecomingAbombState& getBcomingBomb();
	RegularState& getRegular();
	BombState& getBomb();


	friend class Screen;
};

#endif 

