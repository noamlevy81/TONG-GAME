#include "RegularState.h"
#include "Ball.h"
#include "Screen.h"
void RegularState::hitPaddle()
{
	int temp = ball.getDirY();
	int temp1 = ball.getDirX();
	ball.animationHitPaddleRight();
	ball.setDirY(temp);
	ball.setDirX(temp1*-1);
}
void RegularState::hitCorner()
{
	ball.setDirX(ball.getDirX()*-1);
	ball.setDirY(ball.getDirY()*-1);
}
void RegularState::missedPaddle()
{
	screen.pushPaddle(ball.getDirX());
	screen.setPointLost(true);
}
void RegularState::bombKeyPressed()
{
	ball.setTheState(ball.getBcomingBomb());
}
