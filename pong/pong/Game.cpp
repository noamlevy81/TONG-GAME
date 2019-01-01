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

	ShowConsoleCursor(false);
	int option;
	while (true)
	{
		option = menu.printMenu(false);

		switch (option)
		{
		case 1:
			leftPlayer = &hplayerLeft;
			rightPlayer = &hplayerRight;
			run();
			break;
		case 2:
			
			leftPlayer = &hplayerLeft;
			rightPlayer = &pcPlayerRight;
			run();
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
			if (choice == 1)
			{
				initializeGame();
			}
			//if (choice == 3)// set keys and continue 
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
		ball.move();		//in this function we could know about miss . 
		Sleep(80);

	}
}

//this fucntion initalize all the game objects to their default . 
void Game::initializeGame()
{
	screen.freeTetris();
	returnToDefault();
	ball = Ball(&screen);
	updateKbManager();
	screen.setLife();
}
void Game::returnToDefault()
{
	*rightPlayer = Paddle({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
	*leftPlayer = Paddle({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	
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

	ball = Ball(&screen);

	screen.setPointLost(false);

	return false;
}





		  