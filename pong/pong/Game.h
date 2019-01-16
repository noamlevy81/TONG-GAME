#ifndef  Game_h
#define Game_h

//#include "Paddle.h"

#include "Ball.h"
#include "KeyBoardManager.h"
#include "Menu.h"
#include "Tetris.h"
#include "Utils.h"
#include "HumanPlayer.h"
#include "PcPlayer.h"
#include <windows.h>				// check if need . 
#include <typeinfo.h>

class Game
{
	enum LEVELS{NOVICE,GOOD,BEST};
	Paddle* leftPlayer ;
	Paddle* rightPlayer;
	Ball ball;
	KeyBoardManager kbManager;
	Tetris left, right;					
	Screen screen;
	Menu menu;

	void returnToDefault()
	{
		*rightPlayer = Paddle({ RIGHT_X, RIGHT_UP_Y  ,PADDLE_SHAPE }, { RIGHT_X , RIGHT_DOWN_Y,PADDLE_SHAPE });
		*leftPlayer = Paddle({ LEFT_X,LEFT_UP_Y,PADDLE_SHAPE }, { LEFT_X,LEFT_DOWN_Y,PADDLE_SHAPE });
		ball.returnToDefault();
	}
	void setPcLevel();
	bool run();

	//draw all objects
	void drawGame()
	{
		screen.printBoard();
		screen.printTetris();
		leftPlayer->drawPaddle();
		rightPlayer->drawPaddle();

	}
	//update players keys
	void updateKbManager()
	{
		kbManager.clearKeysHistory();
		kbManager.registerKeyBoardManager(&ball);
		if (!strcmp(typeid(*leftPlayer).name(), typeid(HumanPlayer).name()))
			kbManager.registerKeyBoardManager((HumanPlayer*)leftPlayer);
		if (!strcmp(typeid(*rightPlayer).name(), typeid(HumanPlayer).name()))
			kbManager.registerKeyBoardManager((HumanPlayer*)rightPlayer);				//why if we make casting to kblisttener its crash ? 
	}
	//this method initailzie the default paramater of the objects 
	void initializeGame();
	void moveManager()
	{
		ball.move();
		leftPlayer->move();
		rightPlayer->move();
	}
	void gameOver(int side)
	{
		menu.gameOver(side);
	}
	// this function check if game over ,and set the flag that says that one player miss the ball . 
	bool LoseOnePoint();

public:
	Game():screen(left ,right ), ball(&screen) ,left(&screen),right(&screen) {}

	void start();
};

#endif // ! Game_h
