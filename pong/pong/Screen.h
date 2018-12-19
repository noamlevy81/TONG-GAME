#ifndef	Screen_h
#define Screen_h

#include "Point.h"
#include <iostream>
using namespace std;

class Screen
{
private : 
	static Point* leftPaddle;
	static Point* rightPaddle;
public:

	static void setPaddles(Point* first, Point* second)
	{
		leftPaddle= first;
		rightPaddle = second;
	}

	static bool isOnXBorder(int ballx)
	{
		return ballx == leftPaddle->getX() || ballx == rightPaddle->getX();
	}

	static bool isOnYOfThePaddles(int ball_y , int dirx)
	{
		if (dirx == 1)
			 return ball_y-1 >= rightPaddle->getY() && rightPaddle->getY() <= ball_y +3;
		else
			return ball_y-1 >= leftPaddle->getY() && ball_y <= leftPaddle->getY() + 3;


	}
	

	void printBoard();

	enum yLimints { TOP_BORDER = 4, BOTTOM_BORDER = 24 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 1, RIGHT_BORDER = 79 };

};

#endif // !Screen_h
