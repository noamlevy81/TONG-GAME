#ifndef  Game_h
#define Game_h

#include "windows.h"

#include "Paddle.h"
#include "Ball.h"
#include "KeyBoardManager.h"
#include "Menu.h"

class Game
{
	Paddle leftPlayer;
	Paddle rightPlayer;
	Ball ball;
	KeyBoardManager kbManager;
	Screen screen;

public:
	Game(Paddle lplayer = { { 4,10,PADDLE_SHAPE }, { 4,12,PADDLE_SHAPE } }
		, Paddle rplayer = { { 76,11 ,PADDLE_SHAPE }, { 76,13,PADDLE_SHAPE } })
		:leftPlayer(lplayer), rightPlayer(rplayer) {}



	void start()
	{
		rightPlayer.setKeys('p', 'l');				//default keys for right player .
		leftPlayer.setKeys('q', 'a');				//default keys for left player . 

		while (true)
		{
			int option = Menu::firstMenu();
			switch (option)
			{
			case 1:
				Menu::instructions();
				break;
			case 2:
				run();
				break;
			case 3:
				Menu::setUpKeys(leftPlayer, rightPlayer);
				break;
			case 4:
				exit(1);
				break;
			}
		}
	}
	void run();

};

#endif // ! Game_h
