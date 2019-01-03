#ifndef _PcPlayer
#define _PcPlayer

#include "Paddle.h"
#include "Ball.h"
#include "Point.h"

class PcPlayer : public Paddle
{
	Ball* ball;
	bool isInCenter = false ;

public:
	PcPlayer(const Point& up1, const Point& down1,Ball * theBall) : Paddle(up1,down1),ball(theBall) {}

	virtual void move() override
	{
		if (!isInCenter)
		{
			if (up.getY() + 1 != 14)
			{
				Paddle::move();
				if (up.getY() + 1 == 14)
					isInCenter = true;
			}
		}
		else if(ball->getCenterX()-up.getX() )
	

		//setDirY(balling->getDirY());
		//Paddle::move();
	}

};

#endif 
