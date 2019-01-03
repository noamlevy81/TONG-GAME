#include "Game.h"

//this function let the player choose before start a game 
void Game::start()
{
	HumanPlayer hplayerLeft({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	HumanPlayer hplayerRight({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
		hplayerLeft.setKeys('q', 'a');
		hplayerRight.setKeys('p', 'l');
	PcPlayer pcPlayerLeft({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE } ,&ball);
	PcPlayer pcPlayerRight({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE },&ball);

	/*void takeComputersToCenter()
	{

	}*/
	ShowConsoleCursor(false);
	int option;
	while (true)
	{
		option = menu.printMenu(false);

		switch (option)
		{
		case 1:							//case multiple players
			leftPlayer = &hplayerLeft;
			rightPlayer = &hplayerRight;
			if (!run())
				return;
			break;
		case 2:
			leftPlayer = &hplayerLeft;
			rightPlayer = &pcPlayerRight;
			if (!run())
				return;
			break;
		case 3 :
			leftPlayer = &pcPlayerLeft;
			rightPlayer = &pcPlayerRight;
			run();
			break;
		case 8:
			menu.instructions();
			break;
		case 9:
			return;
		}
	}
}

//this function mange the game . 
bool Game::run()
{
	initializeGame();				
	drawGame();
	ball.drawBall();
	screen.setPaddles(leftPlayer, rightPlayer);

	while (true)
	{
		int choice = kbManager.handleKb(menu);	
		moveManager();				

		if (screen.ispointLost())
			choice = 6; 
		if (choice >=1 && choice <= 9 )
		{
			if (choice == 1 )	//to add 2 and 3 
			{
				initializeGame();
			}
			//if (choice == 4)// set keys and continue 
			//{
			//	menu.setUpKeys(leftPlayer, rightPlayer);
			//	updateKbManager();
			//}
			if (choice == 6)
			{
				if (LoseOnePoint())
				{
					screen.freeTetris();
					kbManager.clearKeysHistory();
					return true;
				}
			}
			if (choice == 8)	//how to play .
			{
				menu.instructions();
			}
			if (choice == 9)	//exit . 
			{	
				kbManager.clearKeysHistory();
				return false;
			}
			drawGame();
			ball.draw();
		}
		Sleep(200);
	}
}

//this fucntion initalize all the game objects to their default . 
void Game::initializeGame()
{
	screen.freeTetris();
	returnToDefault();
	updateKbManager();
	screen.setLife();
}


// this function set the flag that says that one player miss the ball , and check if game over ,and
bool Game:: LoseOnePoint()
{
	if (leftPlayer->up.getX() == 20)
	{
		gameOver(LEFT);
		return true;
	}
	else if (rightPlayer->up.getX() == 60)
	{
		gameOver(RIGHT);
		return true;
	}

	ball.eraseBall();

	ball.returnToDefault();

	screen.setPointLost(false);

	return false;
}





		  