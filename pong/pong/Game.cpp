#include "Game.h"

//this function let the player choose before start a game 
void Game::start()
{
	HumanPlayer hplayerLeft({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	HumanPlayer hplayerRight({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
		hplayerLeft.setKeys('q', 'a');
		hplayerRight.setKeys('p', 'l');
	PcPlayer pcPlayerLeft({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE } ,&ball,ballDirection::LEFT,2);
	PcPlayer pcPlayerRight({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE },&ball, ballDirection::RIGHT,5);

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
			setPcLevel();
			if (!run())
				return;
			break;
		case 3 :
			leftPlayer = &pcPlayerLeft;
			rightPlayer = &pcPlayerRight;
			setPcLevel();
			if (!run())
				return;
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
			if (choice >=1 && choice <=3 )	//to add 2 and 3 
			{
				return true;
			}
			if (choice == 5)// set keys and continue 
			{
				menu.setUpKeys(leftPlayer, rightPlayer);
				updateKbManager();
			}
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
		Sleep(50);
	}
}

void Game:: setPcLevel()
{
	int rightLevel = menu.getLevelRight();
	if (rightLevel == NOVICE)
		((PcPlayer*)rightPlayer)->setLevel(10);
	else if (rightLevel == GOOD)
		((PcPlayer*)rightPlayer)->setLevel(40);
	else
		((PcPlayer*)rightPlayer)->setLevel(2);
	int leftLevel;
	if (!strcmp(typeid(*leftPlayer).name(), typeid(PcPlayer).name()))
	{
		leftLevel = menu.getLevelLeft();
		if (leftLevel == NOVICE)
			((PcPlayer*)leftPlayer)->setLevel(10);
		else if (leftLevel == GOOD)
			((PcPlayer*)leftPlayer)->setLevel(40);
		else
			((PcPlayer*)leftPlayer)->setLevel(1);
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
		gameOver(LEFTS);
		return true;
	}
	else if (rightPlayer->up.getX() == 60)
	{
		gameOver(RIGHTS);
		return true;
	}

	ball.eraseBall();

	ball.returnToDefault();

	screen.setPointLost(false);

	return false;
}





		  