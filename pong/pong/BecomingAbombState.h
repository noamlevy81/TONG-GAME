#ifndef __BecomingAbombStater
#define __BecomingAbombStater

#include "BallState.h"
class BecomingAbombState:public BallState
{
public:
	BecomingAbombState(Ball& b,Screen& s) : BallState(b,s)  {}
	//~BecomingAbombState();

	void missedPaddle()
	{
	 //hitDeadPaddle()
	//theScreen->pushPaddle(dir_x);
	//theScreen->setPointLost(true);

	}
	virtual void hitPaddle() override;
	virtual void bombKeyPressed() override;
	virtual void hitBorder()override;
	virtual void hitTetris() override;

};

#endif
