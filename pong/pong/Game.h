#ifndef  Game_h
#define Game_h

#include "windows.h"

#include "Paddle.h"
#include "Ball.h"
#include "KeyBoardManager.h"
#include "Menu.h"

class Game
{
	enum rightPaddle { RIGHT_X = 76, RIGHT_UP_Y = 11, RIGHT_DOWN_Y = 13 };	//floor and ceilling borders
	enum leftPaddle { LEFT_X = 4, LEFT_UP_Y = 10, LEFT_DOWN_Y = 12 };

	Paddle leftPlayer;
	Paddle rightPlayer;
	Ball ball;
	KeyBoardManager kbManager;
	Screen screen;

public:
	Game(Paddle lplayer = { { LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,12,PADDLE_SHAPE } }
		, Paddle rplayer = { { RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, {RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE } })
		:leftPlayer(lplayer), rightPlayer(rplayer) {}

	void start()
	{
		rightPlayer.setKeys('p', 'l');				//default keys for right player .
		leftPlayer.setKeys('q', 'a');				//default keys for left player . 

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

	void initializeGame()
	{
		
		rightPlayer = Paddle({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
		leftPlayer = Paddle({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,12,PADDLE_SHAPE });

		rightPlayer.setKeys('p', 'l');				//default keys for right player .
		leftPlayer.setKeys('q', 'a');

		ball = Ball();
	}
	void run();
	void drawGame()
	{
		screen.printBoard();
		leftPlayer.drawPaddle();
		rightPlayer.drawPaddle();
		ball.drawBall();
	}
	void updateKbManager()
	{
		kbManager.clearKeysHistory();
		kbManager.registerKeyBoardManager(&leftPlayer);
		kbManager.registerKeyBoardManager(&rightPlayer);
	}

};

#endif // ! Game_h
