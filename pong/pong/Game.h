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
	Tetris left, right;					
	Screen screen;
	Menu menu;
	
public:
	Game(Paddle lplayer = { { LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE } }
		, Paddle rplayer = { { RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, {RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE } })
		:leftPlayer(lplayer), rightPlayer(rplayer), screen(&leftPlayer ,&rightPlayer,left ,right ) , ball(&screen) ,left(&screen),right(&screen) {}


	void start();

	void run();

	//this method initailzie the default paramater of the objects 
	void initializeGame();
	
	//draw all objects
	void drawGame()
	{
		screen.printBoard();
		screen.printTetris();
		leftPlayer.drawPaddle();
		rightPlayer.drawPaddle();
		
	}

	//update players keys
	void updateKbManager()
	{
		kbManager.clearKeysHistory();
		kbManager.registerKeyBoardManager(&leftPlayer);
		kbManager.registerKeyBoardManager(&rightPlayer);
	}

	void gameOver(int side)
	{
		menu.gameOver(side);
	}

	// this function check if game over ,and set the flag that says that one player miss the ball . 
	bool LoseOnePoint();

};


#endif // ! Game_h
