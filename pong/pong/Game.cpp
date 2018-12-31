#include "Game.h"

//this function let the player choose before start a game 
void Game::start()
{
	HumanPlayer hplayerLeft({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	HumanPlayer hplayerRight({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });

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
			option = 6;
			break;
		case 2:
			
			leftPlayer = &hplayerLeft;
			rightPlayer = &pcPlayerRight;
			option = 6;
		case 3 :
			leftPlayer = &pcPlayerLeft;
			rightPlayer = &pcPlayerRight;
			option = 6;
		/*case 5:
			menu.setUpKeys(leftPlayer, rightPlayer);
			break;*/
		case 6:
			run();
			break;
		case 8:
			menu.instructions();
			break;
		case 9:
			return;
			break;
		}
		if (option ==6 )
			run();
	}
}

//this function mange the game . 
bool Game::run()
{
	initializeGame();				///asjdhasjkdhasjkhdjkashdjkash
	drawGame();
	ball.drawBall();
	screen.setPaddles(leftPlayer, rightPlayer);

	while (true)
	{
		
		int choice = kbManager.handleKb(menu);	//move paddles
		moveManager();				/////asjdhasjkdhasjkhdjkashdjkash

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
	*rightPlayer = Paddle({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
	*leftPlayer = Paddle({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
	//leftPlayer->setKeys('q', 'a');
	//rightPlayer.setKeys('p', 'l');				//default keys for right player .
	//initalize the paddles whatever they are .			//TODODODODOODOD
	//screen = Screen(rightPlayer, leftPlayer, left, right);
	ball = Ball(&screen);
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

	ball = Ball(&screen);

	screen.setPointLost(false);

	return false;
}





		  