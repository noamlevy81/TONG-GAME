#include "Game.h"

void Game::run()
{
	drawGame();
	updateKbManager();
	
	screen.setPaddles(&(leftPlayer), &(rightPlayer));

	while (true)
	{
		int choice = kbManager.handleKb();	//move paddles
		if (Screen::ispointLost())
			choice = 6; 
		if (choice >=1 && choice <= 6 )
		{
			if (choice == 1)	//how to play .
			{
				Menu::instructions();
			}
			if (choice == 2)
			{
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
			if (choice == 6)
			{
				LoseOnePoint();
			}
			drawGame();
		}
		ball.move();		//in this function we could know about miss . 
		Sleep(220);
	}
}






		  