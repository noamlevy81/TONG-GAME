#ifndef	Screen_h
#define Screen_h

#include <iostream>
using namespace std;

#include "Point.h"
#include "Paddle.h"
#include "Utils.h"
#include <iostream>
#include "Tetris.h"
using namespace std;

class Screen
{
private:
	static Paddle* leftPaddle;
	static Paddle* rightPaddle;
	static bool pointLost;
	static Tetris left,right;						//---------------------------added for check--------------------------------
public:

	static void setPaddles(Paddle* first, Paddle* second)
	{
		leftPaddle = first;
		rightPaddle = second;
	}

	static void pushPaddle(int ballDirX)					// this method update the x value of the paddle in case of lose one point 
	{
		if (ballDirX == 1)
			right.addToRightTetris(*rightPaddle);
		else
			left.addToLeftTetris(*leftPaddle);

		leftPaddle->erase();
		rightPaddle->erase();

		if (ballDirX == 1)
		{
			rightPaddle->up.setX(rightPaddle->up.getX() - 1);
			rightPaddle->down.setX(rightPaddle->down.getX() - 1);
			
		}
		else
		{
			leftPaddle->up.setX(leftPaddle->up.getX() + 1);
			leftPaddle->down.setX(leftPaddle->down.getX() + 1);
			

		}

		returnYPaddlesToDeafult();
	}

	static void pushFiveSteps (int to)
	{
		if (to == 1 )
		{
			rightPaddle->erase();
			rightPaddle->up.setX(rightPaddle->up.getX() + 5);
			rightPaddle->down.setX(rightPaddle->down.getX() + 5);
		}
		else
		{
			leftPaddle->erase();
			leftPaddle->up.setX(leftPaddle->up.getX() -5);
			leftPaddle->down.setX(leftPaddle->down.getX() -5);
		}
	}

	static void returnYPaddlesToDeafult()
	{
		rightPaddle->up.setY(RIGHT_UP_Y);
		rightPaddle->down.setY(RIGHT_DOWN_Y);

		leftPaddle->up.setY(LEFT_UP_Y);
		leftPaddle->down.setY(LEFT_DOWN_Y);
	}


	static bool ispointLost()
	{
		return pointLost;
	}
	static void setPointLost(bool val)
	{
		pointLost = val;
	}
	static bool isOnXBorder(int ballx, int dirx)
	{
		if (dirx == 1)
			return  ballx == rightPaddle->up.getX();
		else
			return ballx == leftPaddle->up.getX();
	}

	//get the dirx for knows with which paddle to check and the dir y for add it to the ball coordinate .
	static bool isOnYOfThePaddles(int ball_y, int dirx, int diry) {
		if (dirx == 1)
			return ball_y + diry >= rightPaddle->up.getY() && ball_y + diry <= rightPaddle->up.getY() + 2;
		else
			return ball_y + diry >= leftPaddle->up.getY() && ball_y + diry <= leftPaddle->up.getY() + 2;
	}

	//------------check corner of the right player --------//
	static bool isOnYCornerofTheRightPaddlesComeFromUp(int ball_y, int dirx)	//that check the case that we are going right and if on corner we get the right down point
	{
		return (ball_y == rightPaddle->up.getY() || ball_y + 1 == rightPaddle->up.getY());		//good logic .
	}
	static bool isOnYCornerofTheRightPaddlesComeFromDown(int ball_y, int dirx)
	{
		return (ball_y == rightPaddle->down.getY() || ball_y - 1 == rightPaddle->down.getY());		//good logic .
	}

	//------------check corner of the left paddle --------//
	static bool isOnYCornerofTheLeftPaddlesComeFromUp(int ball_y, int dirx)	//that check the case that we are going right and if on corner we get the right down point
	{
		return (ball_y == leftPaddle->up.getY() || ball_y + 1 == leftPaddle->up.getY());
	}
	static bool isOnYCornerofTheLeftPaddlesComeFromDown(int ball_y, int dirx)
	{
		return (ball_y == leftPaddle->down.getY() || ball_y - 1 == leftPaddle->down.getY());
	}

	void printTetris()
	{
		left.printTetris();
		right.printTetris();
	}
	static void freeTetris()
	{
		left.free();
		right.free();
	}
	void printBoard();

	enum yLimints { TOP_BORDER = 3, BOTTOM_BORDER = 25 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 0, RIGHT_BORDER = 80 };

};

#endif // !Screen_h

