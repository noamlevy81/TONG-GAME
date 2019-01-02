#ifndef _RegularState
#define _RegularState
#include "BallState.h"
class Ball;
class Screen;
class RegularState :public BallState
{
public:
	RegularState(Ball& b,Screen& s) : BallState(b,s) {}
	//~RegularState();


	//void hitBorder();
	virtual void missedPaddle() override;
	virtual void hitPaddle() override;
	virtual void hitCorner() override;
};

#endif 