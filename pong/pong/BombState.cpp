#include "BombState.h"
#include "Ball.h"

void BombState::hitPaddle()
{
	screen.addToTetris(ball.getDirX());
	screen.pushPaddle(ball.getDirX(), 3);
	screen.setPointLost(true);
}
void BombState::hitCorner()
{
	hitPaddle();
}
void BombState::missedPaddle()
{
	//do nothing
}
int BombState::getColor() { return 4; }//red
void BombState::hitTetris(int x)
{
	int dirX = ball.getDirX();
	if (dirX == 1)
	{
		screen.getRTetris().deleteLine(x, dirX);

	}
	else
		screen.getLTetris().deleteLine(x, dirX);

	screen.pushPaddle(dirX, -1);
	ball.returnToDefault(dirX*-1);
	screen.setPointLost(true);
}
void BombState::hitBorder()
{
	int dirX = ball.getDirX();
	if (dirX == 1)
		screen.getRTetris().deleteLine(15, dirX);
	else
		screen.getLTetris().deleteLine(15, dirX);

	screen.pushPaddle(dirX, -1);
	ball.returnToDefault(dirX*-1);
	screen.setPointLost(true);
}

void BombState::timeEvent() {

	if (ball.getLoopGameCounter() == 4)
	{
		int ballXcoord = ball.getXFromArr(5);
		if (ballXcoord <= screen.getRPaddleX() && ballXcoord >= screen.getLPaddleX())
		{
			ballXcoord = ball.getXFromArr(2);
			if (ballXcoord <= screen.getRPaddleX() && ballXcoord >= screen.getLPaddleX())
				ball.setTheState(ball.getRegular());
		}
		else
			ball.setTheState(ball.getBomb());

	}
}

