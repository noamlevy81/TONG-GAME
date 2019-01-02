#ifndef __bombState
#define __bombState

#include "BallState.h"

class BombState : public BallState
{
public:
	BombState(Ball& b) : BallState(b) {}
	~BombState();

	void missedPaddle()
	{
		//hitDeadPaddle()

	}
	void hitPaddle();
	void hitBorder();
};

#endif
