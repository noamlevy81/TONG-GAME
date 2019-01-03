#ifndef _PcPlayer
#define _PcPlayer

#include "Paddle.h"
#include "Ball.h"
#include "Point.h"
#include "Screen.h"

class PcPlayer : public Paddle
{
	Ball* ball;
	bool isInCenter = false;
	int goTo = 14;

public:
	PcPlayer(const Point& up1, const Point& down1, Ball * theBall) : Paddle(up1, down1), ball(theBall) {}

	virtual void move() override
	{
		if (!isInCenter)			//return the paddle to hte ceneter . 
		{
			if (up.getY() != 13)
			{
				if (up.getY() > 13)
				{
					setDirY(-1);
					Paddle::move();
				}
				else
				{
					setDirY(1);
					Paddle::move();
				}

				if (up.getY() == 13)
					isInCenter = true;
			}
		}
		else if (up.getX() - ball->getXFromArr(5)  == 9)
		{
			if (ball->getDirX() == 1)
			{
				if (ball->getDirY() == -1)
				{
					if (abs(ball->getYFromArr(5) - 3) < 9)
					{
						goTo = ball->getYFromArr(5) - 1 - 1 - 3;	//3 is top border , -1 -1 because we look at the middle . 
						goTo = 3 + 2 + (9 - goTo);
					}
					else
					{
						goTo = ball->getYFromArr(5) - 9;
					}
				}
				else
				{
					if (abs(25 - ball->getYFromArr(5)) < 9)
					{
						goTo = 25 - ball->getYFromArr(5) - 1 - 1;	//3 is top border , -1 -1 because we look at the middle . 
						goTo = 25 - 2 - (9 - goTo);
					}
					else
					{
						goTo = ball->getYFromArr(5) + 9;
					}
				}
			}
		}
		//move the paddle to hit the ball . 
		else if (up.getY() + 1 != goTo)
		{
			if (up.getY() > goTo)
			{
				setDirY(-1);
				Paddle::move();
			}
			else
			{
				setDirY(1);
				Paddle::move();
			}
		}
		if (ball->getXFromArr(5) - up.getX() == 1)
			isInCenter = false;
	}
};

#endif 
