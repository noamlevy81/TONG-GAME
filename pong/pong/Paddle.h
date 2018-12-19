#ifndef Paddle_h
#define Paddle_h 

#include "Point.h"
#include "Screen.h"

const char PADDLE_SHAPE = '#';

class Paddle
{
	char  keys[3];
	Point down, up;
	int dir_y = 1 ;
	
	void movePad(Point &first, Point & second)
	{
		if (up.getY() + dir_y != Screen::TOP_BORDER && down.getY() + dir_y != Screen::BOTTOM_BORDER){
			first.erase();
			first.move(0, dir_y);
			second.move(0, dir_y);
			second.draw();
		}
	}
	
public:
	Paddle(Point up1, Point down1) :  up(up1),down(down1) {};

	//this method draw the paddle at the first time . 
	void drawPaddle() {

		int times = down.getY() - up.getY()+1;

		int indexX = up.getX();
		int indexY = up.getY();

		for (int i = 0; i < times; i++)
		{
			gotoxy(indexX , indexY + i);
			cout << PADDLE_SHAPE;
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
};
#endif // !Paddle_h
