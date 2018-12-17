#ifndef Paddle_h
#define Paddle_h 

#include "Point.h"
const char PADDLE_SHAPE = '#';

class Paddle
{
	char  keys[3];
	Point down, up;
	int dir_y = 1 ;

	void movePad(Point &first, Point & second)
	{
		first.erase();
		first.move(0, dir_y);
		second.move(0, dir_y);
		second.draw();
	}
public:
	Paddle(const Point& up1, const Point& down1) : down(down1), up(up1) {};

	//this method draw the paddle at the first time . 
	void drawPaddle() {
		int times = down.getY() - up.getY();

		int indexX = up.getX();
		int indexY = up.getY();

		for (int i = 0; i < times; i++)
		{
			gotoxy(indexX , indexY + i);
			cout << PADDLE_SHAPE;
		}
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
};
#endif // !Paddle_h
