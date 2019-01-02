#ifndef __BecomingAbombStater
#define __BecomingAbombStater

#include "BallState.h"
class BecomingAbombState:public BallState
{
public:
	BecomingAbombState(Ball& b,Screen& s) : BallState(b,s)  {}
	//~BecomingAbombState();

	virtual void missedPaddle(){}
	virtual void hitCorner() override;
	virtual void hitPaddle() override;
	virtual void bombKeyPressed() override;
	virtual void hitBorder()override;
	virtual void hitTetris() override;

};

#endif
