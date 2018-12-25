#ifndef Tetris_h
#define Tetris_h

#include <iostream>

#include <list>
#include "Paddle.h"
#include "Point.h"
#include "Utils.h"

class Screen;
using namespace std;
class Tetris
{
	enum {MAX_LOSES=16};
	list<Paddle> boards_history[MAX_LOSES];
	Screen* theScreen;

public:
	Tetris(Screen *screen):theScreen(screen){}

	void addToTetris(Paddle toAdd, int dir_x);
	void deleteLine(int ind,int dirX);

	//void addToLeftTetris(Paddle toAdd);
	//void addToRightTetris(Paddle toAdd);
	//void deleteLineLeft(int ind);
	//void deleteLineRight(int ind);

	bool collisionMade(int index, int toAdd_y_val);
	void printTetris()	const ;
	void free();

	void movePaddleBack(Paddle& toAdd,int dir)
	{
		toAdd.erase();
		toAdd.down.setX(toAdd.down.getX() + dir);
		toAdd.up.setX(toAdd.up.getX() + dir);
		toAdd.drawPaddle();
		Sleep(50);
	}

};

#endif

