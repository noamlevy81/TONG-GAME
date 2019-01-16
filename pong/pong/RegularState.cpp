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
int RegularState::getColor() { return 8; }//grey

void RegularState::missedPaddle()
{
	screen.addToTetris(ball.getDirX());
	screen.pushPaddle(ball.getDirX(),ONE_POINT);
	screen.setPointLost(true);
}
void RegularState::bombKeyPressed(char key)
{
	if (key == ball.getChars()[0])// case 's' pressed
	{
		if (ball.getBombPressedLeft() >= 4)
		{
			ball.resetBombPressedLeft();
			ball.setTheState(ball.getBcomingBomb());
		}
	}
	else {// key == 'k'
		if (ball.getBombPressedRight() >= 4)
		{
			ball.resetBombPressedRight();
			ball.setTheState(ball.getBcomingBomb());
		}
	}
}
