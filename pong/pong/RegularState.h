#ifndef _RegularState
#define _RegularState
#include "BallState.h"
#include"Ball.h"
class RegularState :public BallState
{
public:
	RegularState(Ball& b,Screen& s) : BallState(b,s) {}
	~RegularState();

	void missedPaddle()
	{
		screen.pushPaddle(ball.getDirX());
		screen.setPointLost(true);
	}
	void hitPaddle()
	{
		int temp = ball.getY();
		ball.animationHitPaddleRight();
		ball.setDirY(temp);
		ball.setDirX(-1);
	}

	void hitCorner()
	{
		ball.setDirX(ball.getDirX()*-1);
		ball.setDirY(ball.getDirY()*-1);
	}
	void hitBorder();
};

#endif 