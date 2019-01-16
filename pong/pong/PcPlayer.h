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
	void calculateLocation();

public:
	PcPlayer(const Point& up1, const Point& down1, Ball * theBall,int dir,int center) : Paddle(up1, down1), ball(theBall),myDir(dir),center(center) {}

	virtual void move() override; 

	void setLevel(int l) { level = l; }
};

#endif 
