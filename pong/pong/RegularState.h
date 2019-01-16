#ifndef _RegularState
#define _RegularState
#include "BallState.h"
class Ball;
class Screen;
class RegularState :public BallState
{
public:
	RegularState(Ball& b,Screen& s) : BallState(b,s) {}

	virtual void hitPaddle() override;
	virtual void hitCorner() override;
	virtual void missedPaddle() override;
	virtual void hitBorder() override {}
	virtual void bombKeyPressed(char key)override;
	virtual int getColor()override;

};

#endif 