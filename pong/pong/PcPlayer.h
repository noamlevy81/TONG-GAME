#ifndef _PcPlayer
#define _PcPlayer

#include "Paddle.h"
#include "Ball.h"
#include "Point.h"

class PcPlayer : public Paddle
{
	Ball* balling; 

public:
	PcPlayer(const Point& up1, const Point& down1,Ball * theBall) : Paddle(up1,down1), balling(theBall) {}

	virtual void move() override
	{
		setDirY(balling->getDirY());
		Paddle::move();
	}

};

#endif 
