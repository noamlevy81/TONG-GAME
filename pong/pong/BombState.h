#ifndef __bombState_h
#define __bombState_h

#include "BallState.h"

class Ball;
class Screen;

class BombState : public BallState
{
public:
	BombState(Ball& b, Screen& s) : BallState(b, s) {}

	virtual void hitPaddle() override;
	virtual void hitCorner() override;
	virtual void missedPaddle() override;
	virtual void hitTetris(int x) override;
	virtual void hitBorder()override;
	virtual void timeEvent() override;
	virtual int getColor()override;
};
#endif
