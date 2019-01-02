#include "RegularState.h"
#include "Ball.h"
#include "Screen.h"
void RegularState::missedPaddle()
{
	screen.pushPaddle(ball.getX());
	screen.setPointLost(true);
}
void RegularState::hitPaddle()
{
	int temp = ball.getY();
	ball.animationHitPaddleRight();
	ball.setDirY(temp);
	ball.setDirX(-1);
}
void RegularState::bombKeyPressed()
{
	ball.setTheState(ball.getBcomingBomb());
	ball.setGameLoopCounter();
}
void RegularState::hitCorner()
{
	ball.setDirX(ball.getX()*-1);
	ball.setDirY(ball.getY()*-1);
}