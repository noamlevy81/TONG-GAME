#ifndef Tetris_h
#define Tetris_h
#include <list>
#include "Paddle.h"
#include "Point.h"
#include <iostream>
using namespace std;
class Tetris
{
	enum {MAX_LOSES=16};
	enum {LEFT,RIGHT};
	list<Paddle> boards_history[MAX_LOSES];
	int lists_sizes[MAX_LOSES] = { 0 };

public:
	//void addToTetris(Paddle toAdd, int to);
	void addToLeftTetris(Paddle toAdd);
	void addToRightTetris(Paddle toAdd);

	bool collisionMade(int index, int toAdd_y_val);
	void printTetris();
	
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

