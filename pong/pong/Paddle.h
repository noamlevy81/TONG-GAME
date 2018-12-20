#ifndef Paddle_h
#define Paddle_h 

#include "Point.h"

const char PADDLE_SHAPE = '#';

class Paddle
{
	char  keys[3];
	Point down, up;
	int dir_y = 1 ;
	
	void movePad(Point &first, Point & second);
	
public:
	Paddle(Point up1, Point down1) :  up(up1),down(down1) {};

	void erase() {
		drawPaddle(' ');
		/*
		up.erase();
		down.erase();
		Point p = {up.getX(),up.getY()+1,PADDLE_SHAPE};		
		p.erase();*/
}
	//this method draw the paddle at the first time . 
	void drawPaddle(char figure=PADDLE_SHAPE) {

		int times = down.getY() - up.getY()+1;

		int indexX = up.getX();
		int indexY = up.getY();

		for (int i = 0; i < times; i++)
		{
			gotoxy(indexX , indexY + i);
			cout << figure;
		}
	}
	void setKeys(char up, char down)
	{
		keys[0] = up;
		keys[1] = down;
	}
	void move()
	{
		if (dir_y == 1)
		{
			movePad(up, down);
		}
		else
		{
			movePad(down, up);
		}
	}

	const char* getChars()
	{
		return keys;
	}

	void handleKey(char key){
		if (key == keys[0])				//move up 
			dir_y = -1;
		else if (key == keys[1])
			dir_y = 1;
		move();
	}

	friend class Game; 
	friend class Screen;

};
#endif // !Paddle_h
