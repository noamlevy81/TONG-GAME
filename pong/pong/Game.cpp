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
		int choice = kbManager.handleKb();	//move paddles
		if (choice == 1)
		{
			break;
		}
		if (choice == 3)
		{
			screen.printBoard();
			leftPlayer.drawPaddle();
			rightPlayer.drawPaddle();
			ball.drawBall();
		}
		ball.move();
		Sleep(120);
	}
}