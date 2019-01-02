#include "BombState.h"
#include "Ball.h"

 void BombState:: hitPaddle()
{
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
void BombState::hitTetris(int x) 
{
	int dirX = ball.getDirX();
	if (dirX == 1)
	{
		screen.getRTetris().deleteLine(x,dirX);
		
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
		 int ballXcoord = ball.getCenterX();
		 if (ballXcoord <= screen.getRPaddleX()
			 && ballXcoord >= screen.getLPaddleX())
			 ball.setTheState(ball.getRegular());
	 }
 }

 void bombKeyPressed() 
 {
	 //do nothing
 }