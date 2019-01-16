#ifndef __BecomingAbombStater_h
#define __BecomingAbombStater_h

#include "BallState.h"
class BecomingAbombState:public BallState
{
public:
	BecomingAbombState(Ball& b,Screen& s) : BallState(b,s)  {}

	virtual void missedPaddle(){}
	virtual void hitCorner() override;
	virtual void hitPaddle() override;
	virtual void hitBorder()override;
	virtual void hitTetris(int x) override;
	virtual void timeEvent()override;
	int getColor()override;
};

#endif
