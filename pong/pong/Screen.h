#ifndef	Screen_h
#define Screen_h

#include "Point.h"
#include "Paddle.h"

#include <iostream>
using namespace std;

class Screen
{
private : 
	static Paddle* leftPaddle;
	static Paddle* rightPaddle;
	static bool pointLost;
public:

	static void setPaddles(Paddle* first, Paddle* second)
	{
		leftPaddle= first;
		rightPaddle = second;
	}
	static void pushPaddle(int ballDirX)
	{
		if (ballDirX == 1)
		{
			rightPaddle->up.setX(rightPaddle->up.getX() - 1);
		}
		else
		{
			leftPaddle->up.setX(leftPaddle->up.getX() + 1);

		}
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
			 return ball_y-1 >= rightPaddle->up.getY() && rightPaddle->up.getY() <= ball_y +3;
		else
			return ball_y-1 >= leftPaddle->up.getY() && ball_y <= leftPaddle->up.getY() + 3;


	}
	

	void printBoard();

	enum yLimints { TOP_BORDER = 4, BOTTOM_BORDER = 24 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 1, RIGHT_BORDER = 79 };

};

#endif // !Screen_h
