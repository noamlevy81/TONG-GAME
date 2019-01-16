#include "PcPlayer.h"

void PcPlayer::move() 
{
	if (!isInCenter)			//return the paddle to hte ceneter . 
	{
		if (getUp().getY() > CENTERFORPADDLE)
		{
			setDirY(ballDirection::LEFT);
			Paddle::move();
		}
		else
		{
			setDirY(ballDirection::RIGHT);
			Paddle::move();
		}

		if (getUp().getY() == CENTERFORPADDLE)
			isInCenter = true;
	}

	else if (abs(getUp().getX() - ball->getXFromArr(center)) == MAXFORMISS && ball->getDirX() == myDir)
	{
		calculateLocation();
	}

	//move the paddle to hit the ball . 
	else if (getUp().getY() + 1 != goTo)
	{
		if (getUp().getY() + 1 > goTo)
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

	if (abs(getUp().getX() - ball->getXFromArr(center)) == 1)
	{
		isInCenter = false;
		goTo = CENTERFORPADDLE + 1;
	}
}

void PcPlayer :: calculateLocation()
{
	if (ball->getDirY() == ballDirection::LEFT)
	{
		if (abs(ball->getYFromArr(center) - yBorders::UPPER_Y) < MAXFORMISS)
		{
			goTo = ball->getYFromArr(center) - 1 - 1 - yBorders::UPPER_Y;	//3 is top border , -1 -1 because we look at the middle . 
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
	if (std::rand() % level == 3)
	{
		int x = rand() % 5 + 3;
		goTo += x * pow(-1, x % 2);
	}
}


