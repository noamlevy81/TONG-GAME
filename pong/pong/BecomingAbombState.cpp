#include "BecomingAbombState.h"
#include "Ball.h"
#include "Screen.h"

void BecomingAbombState::hitPaddle()
{
	ball.setTheState(ball.getRegular());
	ball.getCurrState().hitPaddle();
}
void BecomingAbombState::hitTetris()
{
	hitBorder();
}
void  BecomingAbombState::bombKeyPressed()
{
	//do nothing
}

void BecomingAbombState::hitBorder() {
	ball.setTheState(ball.getRegular());
	ball.getCurrState().missedPaddle();
}