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
	int center;				//will be the relevant ball point for calculations
	int myDir;				// will hold the dir of the ball when moving toards player
	
	void calculateLocation()
	{
		if (ball->getDirY() == -1)
		{
			if (abs(ball->getYFromArr(center) - 3) < 9)
			{
				goTo = ball->getYFromArr(center) - 1 - 1 - 3;	//3 is top border , -1 -1 because we look at the middle . 
				goTo = 3 + 2 + (9 - goTo);
			}
			else
			{
				goTo = ball->getYFromArr(center) - 9;
			}
		}
		else
		{
			if (abs(25 - ball->getYFromArr(center)) < 9)
			{
				goTo = 25 - ball->getYFromArr(center) - 1 - 1;	//3 is top border , -1 -1 because we look at the middle . 
				goTo = 25 - 2 - (9 - goTo);
			}
			else
			{
				goTo = ball->getYFromArr(center) + 9;
			}
		}
	}

public:
	PcPlayer(const Point& up1, const Point& down1, Ball * theBall,int dir,int center) : Paddle(up1, down1), ball(theBall),myDir(dir),center(center) {}

	virtual void move() override
	{
		if (!isInCenter)			//return the paddle to hte ceneter . 
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

		else if (abs(up.getX() - ball->getXFromArr(center)) == 9 && ball->getDirX() == myDir)
		{
			 calculateLocation();
		}

		//move the paddle to hit the ball . 
		else if (up.getY() + 1 != goTo) 
		{
			if (up.getY() + 1 > goTo)
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

		
		if (abs(up.getX() - ball->getXFromArr(center)) == 1)
		{
			isInCenter = false;
			goTo = 14;
		}
	}
};

#endif 
