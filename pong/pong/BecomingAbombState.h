#ifndef __BecomingAbombStater
#define __BecomingAbombStater
#include "BallState.h"

class Ball;
class BecomingAbombState:public BallState
{
public:
	BecomingAbombState(Ball& b,Screen& s) : BallState(b,s)  {}
	~BecomingAbombState();

	void missedPaddle()
	{
	 //hitDeadPaddle()
	//theScreen->pushPaddle(dir_x);
	//theScreen->setPointLost(true);

	}
	void hitPaddle()
	{
		ball.setTheState(ball.getRegular());
		ball.theState->hitPaddle();
	}
	void hitBorder();
};

#endif
