#ifndef  Game_h
#define Game_h

#include "Paddle.h"
#include "Ball.h"
#include "KeyBoardManager.h"
#include "Menu.h"
#include "Tetris.h"
#include "Utils.h"

#include <windows.h>				// check if need . 

class Game
{
	Paddle leftPlayer;
	Paddle rightPlayer;
	Ball ball;
	KeyBoardManager kbManager;
	Screen screen;					//check about the scrreen chagne static functions to regular . 
	
public:
	Game(Paddle lplayer = { { LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE } }
		, Paddle rplayer = { { RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, {RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE } })
		:leftPlayer(lplayer), rightPlayer(rplayer) {}

	void start();

	//this method initailzie the default paramater of the objects 
	void initializeGame()
	{
		Screen::freeTetris();
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
		screen.printTetris();
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

	void gameOver(int side)
	{
		if (side == LEFT)
		{
			cout << "right win";
			
		}
		else
		{
			cout << "left win ";
		}
	}
	bool LoseOnePoint()
	{
		if (leftPlayer.up.getX() == 20)
		{
			Menu::gameOver(LEFT) ;
			return true;
		}
		else if (rightPlayer.up.getX() == 60)
		{
			Menu::gameOver(RIGHT);
			return true;
		}

		ball.eraseBall();
		ball = Ball();

		Screen::setPointLost(false);

		return false;
	}
};


#endif // ! Game_h
