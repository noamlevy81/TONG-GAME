#include "Game.h"

void Game::run()
{
	screen.printBoard();

	leftPlayer.drawPaddle();
	rightPlayer.drawPaddle();
	ball.drawBall();

	kbManager.registerKeyBoardManager(&leftPlayer);
	kbManager.registerKeyBoardManager(&rightPlayer);

	screen.setPaddles(&(leftPlayer), &(rightPlayer));

	while (true)
	{
		int choice = kbManager.handleKb();	//move paddles
		if (Screen::ispointLost())
			choice = 2;
		if (choice >=1 && choice <= 5 )
		{
			if (choice == 1)	//how to play .
			{
				Menu::instructions();
			}
			if (choice == 2)
			{
				Screen::setPointLost(false);
				initializeGame();
			}
			if (choice == 4)// set keys and continue 
			{
				Menu::setUpKeys(leftPlayer, rightPlayer);
				updateKbManager();
			}
			if (choice == 5)	//exit . 
			{
				kbManager.clearKeysHistory();
				exit(1);
			}
			drawGame();
		}
		ball.move();
		Sleep(220);
	}
}






		  