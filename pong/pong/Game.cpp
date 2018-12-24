#include "Game.h"

//this function let the player choose before start a game 
void Game::start()
{
	ShowConsoleCursor(false);

	while (true)
	{
		int option = Menu::firstMenu(false);
		switch (option)
		{
		case 1:
			Menu::instructions();
			break;
		case 2:
			run();
			break;
		case 4:
			Menu::setUpKeys(leftPlayer, rightPlayer);
			break;
		case 5:
			exit(1);
			break;
		}
	}
}

//this function mange the game . 
void Game::run()
{
	initializeGame();
	drawGame();
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
				if (LoseOnePoint())
				{
					Screen::freeTetris();
					kbManager.clearKeysHistory();
					break;
				}
			}
			drawGame();
		}
		ball.move();		//in this function we could know about miss . 
		Sleep(10);

	}
}

//this fucntion initalize all the game objects to their default . 
void Game::initializeGame()
{
	Screen::freeTetris();
	rightPlayer = Paddle({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
	leftPlayer = Paddle({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	rightPlayer.setKeys('p', 'l');				//default keys for right player .
	leftPlayer.setKeys('q', 'a');
	ball = Ball();
	updateKbManager();
}

// this function set the flag that says that one player miss the ball , and check if game over ,and
bool Game:: LoseOnePoint()
{
	if (leftPlayer.up.getX() == 20)
	{
		gameOver(LEFT);
		return true;
	}
	else if (rightPlayer.up.getX() == 60)
	{
		gameOver(RIGHT);
		return true;
	}

	ball.eraseBall();
	ball = Ball();

	Screen::setPointLost(false);

	return false;
}





		  