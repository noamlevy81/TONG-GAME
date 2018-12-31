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
//using namespace std;
#include <typeinfo.h>

class Game
{
	Paddle* leftPlayer;
	Paddle* rightPlayer;
	Ball ball;
	KeyBoardManager kbManager;
	Tetris left, right;					
	Screen screen;
	Menu menu;
	
public:
	Game(): screen(leftPlayer ,rightPlayer,left ,right ) , ball(&screen) ,left(&screen),right(&screen) {}

	void start();

	void run();

	//this method initailzie the default paramater of the objects 
	void initializeGame();
	
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
		if (!strcmp(typeid(*leftPlayer).name(), typeid(HumanPlayer).name()))
			kbManager.registerKeyBoardManager((kbListener*)leftPlayer);
		if (!strcmp(typeid(*rightPlayer).name(), typeid(HumanPlayer).name()))
			kbManager.registerKeyBoardManager((kbListener*)rightPlayer);
	}

	void moveManager()
	{
		leftPlayer->move();
		rightPlayer->move();
	}
	void gameOver(int side)
	{
		menu.gameOver(side);
	}

	// this function check if game over ,and set the flag that says that one player miss the ball . 
	bool LoseOnePoint();

};


#endif // ! Game_h
