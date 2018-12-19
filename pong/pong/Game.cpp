#include "Game.h"

void Game ::run()
{
	screen.printBoard();

	leftPlayer.drawPaddle();
	rightPlayer.drawPaddle();
	ball.drawBall();
	kbManager.registerKeyBoardManager(&leftPlayer);
	kbManager.registerKeyBoardManager(&rightPlayer);

	screen.setPaddles(&(leftPlayer.up), &(rightPlayer.up));

	while (true)
	{
		kbManager.handleKb();	//move paddles
		ball.move();
		Sleep(75);
	}
}