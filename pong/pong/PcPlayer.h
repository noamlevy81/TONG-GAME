#ifndef _PcPlayer
#define _PcPlayer

#include "Paddle.h"
#include "Ball.h"
#include "Point.h"
#include "Screen.h"
#include "Utils.h"

class PcPlayer : public Paddle
{
	Ball* ball;
	bool isInCenter = false;
	int goTo = 14;
	int center; //will be the relevant ball point for calculations
	int myDir;// will hold the dir of the ball when moving toards player
	int level;
	void calculateLocation()
	{
		if (ball->getDirY() == ballDirection::LEFT)
		{
			if (abs(ball->getYFromArr(center) - yBorders::UPPER_Y) < MAXFORMISS)
			{
				goTo = ball->getYFromArr(center) - 1 - 1 - yBorders::UPPER_Y ;	//3 is top border , -1 -1 because we look at the middle . 
				goTo = 3 + 2 + (MAXFORMISS - goTo);
			}
			else
			{
				goTo = ball->getYFromArr(center) - MAXFORMISS;
			}
		}
		else
		{
			if (abs(25 - ball->getYFromArr(center)) < MAXFORMISS)
			{
				goTo = yBorders::BUTTOM_Y - ball->getYFromArr(center) - 1 - 1;	//3 is top border , -1 -1 because we look at the middle . 
				goTo = yBorders::BUTTOM_Y - 2 - (MAXFORMISS - goTo);			    //-2 because we look at the middle . 
			}
			else
			{
				goTo = ball->getYFromArr(center) + MAXFORMISS;
			}
		}
		if (std::rand() % level == 1)
		{
			int x = rand() % 5+3;
			goTo +=x*pow(-1,x%2);
		}
	}

public:
	PcPlayer(const Point& up1, const Point& down1, Ball * theBall,int dir,int center) : Paddle(up1, down1), ball(theBall),myDir(dir),center(center) {}

	virtual void move() override
	{
		if (!isInCenter)			//return the paddle to hte ceneter . 
		{
			if (up.getY() > CENTERFORPADDLE)
			{
				setDirY(ballDirection::LEFT);
				Paddle::move();
			}
			else
			{
				setDirY(ballDirection::RIGHT);
				Paddle::move();
			}

			if (up.getY() == CENTERFORPADDLE)
				isInCenter = true;
		}

		else if (abs(up.getX() - ball->getXFromArr(center)) == MAXFORMISS && ball->getDirX() == myDir)
		{
			 calculateLocation();
		}

		//move the paddle to hit the ball . 
		else if (up.getY() + 1 != goTo)
		{
			if (up.getY() + 1 > goTo)
			{
				setDirY(ballDirection::LEFT);
				Paddle::move();
			}
			else
			{
				setDirY(ballDirection::RIGHT);
				Paddle::move();
			}
		}

		if (abs(up.getX() - ball->getXFromArr(center)) == 1)
		{
			isInCenter = false;
			goTo = CENTERFORPADDLE+1;
		}
	}
	void setLevel(int l) { level = l; }
};

#endif 
