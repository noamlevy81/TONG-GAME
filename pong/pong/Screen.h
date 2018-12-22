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
private : 
	static Paddle* leftPaddle;
	static Paddle* rightPaddle;
	static bool pointLost;
	static Tetris left;//---------------------------added for check--------------------------------
public:

	static void setPaddles(Paddle* first, Paddle* second)
	{
		leftPaddle= first;
		rightPaddle = second;
	}
	static void pushPaddle(int ballDirX)					// this method update the x value of the paddle in case of lose one point 
	{	
		left.addToRightTetris(*rightPaddle); //------------------------------added for check-----------------------------
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
	static bool isOnXBorder(int ballx)
	{
		return ballx == leftPaddle->up.getX() || ballx == rightPaddle->up.getX();
	}

	static bool isOnYOfThePaddles(int ball_y , int dirx)
	{
		if (dirx == 1)
			 return ball_y >= rightPaddle->up.getY() && rightPaddle->up.getY() <= ball_y +2;
		else
			return ball_y >= leftPaddle->up.getY() && ball_y <= leftPaddle->up.getY() + 2;
	}
	
	//------------check corner of the right player --------//
	static bool isOnYCornerofTheRightPaddlesComeFromUp(int ball_y, int dirx)	//that check the case that we are going right and if on corner we get the right down point
	{
		return (ball_y == rightPaddle->up.getY() || ball_y + 1 == rightPaddle->up.getY());		//good logic .
	}
	static bool isOnYCornerofTheRightPaddlesComeFromDown(int ball_y, int dirx)
	{
		return (ball_y == rightPaddle->down.getY() || ball_y + 1 == rightPaddle->down.getY());		//good logic .
	}

	//------------check corner of the left paddle --------//
	static bool isOnYCornerofTheLeftPaddlesComeFromUp(int ball_y, int dirx)	//that check the case that we are going right and if on corner we get the right down point
	{

		return (ball_y == leftPaddle->up.getY() || ball_y + 1 == leftPaddle->up.getY());
	}
	static bool isOnYCornerofTheLeftPaddlesComeDownUp(int ball_y, int dirx)
	{
		return (ball_y == leftPaddle->down.getY() || ball_y + 1 == leftPaddle->down.getY());
	}

	void printBoard();	

	enum yLimints { TOP_BORDER = 4, BOTTOM_BORDER = 24 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 1, RIGHT_BORDER = 79 };
		
};

#endif // !Screen_h
