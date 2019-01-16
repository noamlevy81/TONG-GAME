#ifndef	Screen_h
#define Screen_h

#include <iostream>
using namespace std;

#include "Point.h"
#include "Paddle.h"
#include "Utils.h"
#include "Tetris.h"

class Screen
{
	Paddle* leftPaddle;
	Paddle* rightPaddle;
	Tetris & leftTetris;
	Tetris & rightTetris;

	int lifeLeft = 16;
	int lifeRight = 16;
	bool pointLost;

	void returnYPaddlesToDeafult()
	{
		rightPaddle->up.setY(RIGHT_UP_Y);
		rightPaddle->down.setY(RIGHT_DOWN_Y);

		leftPaddle->up.setY(LEFT_UP_Y);
		leftPaddle->down.setY(LEFT_DOWN_Y);
	}

public:
	Screen(Tetris& left_tetris, Tetris& right_tetris) : leftTetris(left_tetris), rightTetris(right_tetris) {}


	bool ballHitTetris(int dirx, int diry, int ballx, int bally,int *ind);

	void addToTetris(int dirX)
	{
		if (dirX == 1)
			this->rightTetris.addToTetris(*rightPaddle, dirX);
		else
			this->leftTetris.addToTetris(*leftPaddle, dirX);

		leftPaddle->erase();
		rightPaddle->erase();

	}

	void setLife()
	{
		lifeLeft = 16;
		lifeRight = 16;
	}

	void setPaddles(Paddle *left, Paddle*right)
	{
		leftPaddle = left;
		rightPaddle = right;
	}

	void pushPaddle(int ballDirX, int numOfTimes);			// this method update the x value of the paddle in case of lose one point 

	void pushFiveSteps(int to);

	Tetris& getRTetris() { return rightTetris; }
	Tetris& getLTetris() { return leftTetris; }

	int getRPaddleX() { 
		return rightPaddle->up.getX(); 
	}
	int getLPaddleX() {
		return leftPaddle->up.getX();
	}

	bool ispointLost()
	{
		return pointLost;
	}
	void setPointLost(bool val)
	{
		pointLost = val;
	}
	bool isOnXBorder(int ballx, int dirx)
	{
		if (dirx == 1)
			return  ballx == rightPaddle->up.getX();
		else
			return ballx == leftPaddle->up.getX();
	}
	bool isOnXAfterDeath(int ballx, int dirx)
	{
		if (dirx == 1)
			return  ballx >= rightPaddle->up.getX();
		else
			return ballx <= leftPaddle->up.getX();
	}
	//get the dirx for knows with which paddle to check and the dir y for add it to the ball coordinate .
	bool isOnYOfThePaddles(int ball_y, int dirx, int diry) {
		if (dirx == 1)
			return ball_y + diry >= rightPaddle->up.getY() && ball_y + diry <= rightPaddle->down.getY();
		else
			return ball_y + diry >= leftPaddle->up.getY() && ball_y + diry <= leftPaddle->down.getY();
	}

	//------------check corner of the right player --------//
	bool isOnYCornerofTheRightPaddle(int ball_y, int diry)	//that check the case that we are going right and if on corner we get the right down point
	{
		if (diry == 1)
			return (ball_y <= rightPaddle->up.getY() && ball_y >= rightPaddle->up.getY() - 2);		//good logic .
		else
			return (ball_y >= rightPaddle->down.getY() && ball_y <= rightPaddle->down.getY() + 2);		//good logic .
	}

	//------------check corner of the left paddle --------//
	bool isOnYCornerofTheLeftPaddle(int ball_y, int diry)	//that check the case that we are going right and if on corner we get the right down point
	{
		if (diry == 1)
			return (ball_y <= leftPaddle->up.getY() && ball_y >= leftPaddle->up.getY() - 2);
		else
			return (ball_y >= leftPaddle->down.getY() && ball_y <= leftPaddle->down.getY() + 2);
	}

	void printTetris() const
	{
		leftTetris.printTetris();
		rightTetris.printTetris();
	}

	void freeTetris()
	{
		leftTetris.free();
		rightTetris.free();
	}

	void printBoard() const;

	enum yLimints { TOP_BORDER = 3, BOTTOM_BORDER = 25 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 0, RIGHT_BORDER = 80 };

};

#endif // !Screen_h

