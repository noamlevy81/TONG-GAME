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
	//Screen(Point* first, Point* second): paddles[0](first ) , paddles[1](second) {} 

	static void setPaddles(Point* first, Point* second)
	{
		leftPaddle= first;
		rightPaddle = second;
	}

	static bool isOnXBorder(Point  ball)
	{
		return ball.getX() == leftPaddle->getX() || ball.getX() == rightPaddle->getX();
	}
	static bool isOnYOfThePaddles(Point ball)
	{
		return (ball.getY() >= leftPaddle->getY() && ball.getY() <= leftPaddle->getY() + 2)
			|| (ball.getY() >= rightPaddle->getY() && ball.getY() <= rightPaddle->getY() + 2);
	}

	void printBoard();


	enum yLimints { TOP_BORDER = 4, BOTTOM_BORDER = 24 };	//floor and ceilling borders
	enum xLimits { LEFT_BORDER = 1, RIGHT_BORDER = 79 };

};

#endif // !Screen_h
