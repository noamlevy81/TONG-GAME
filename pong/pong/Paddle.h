#ifndef Paddle_h
#define Paddle_h 

#include "Point.h"

const char PADDLE_SHAPE = '#';

class Paddle
{
	int dir_y = 1;
	Point down, up;

	void movePad(Point &first, Point & second);

protected:
	void setDirY(int diry)
	{
		dir_y = diry;
	}
public:
	Paddle(const Point& up1,const Point& down1) : up(up1), down(down1) {};

	//erase the paddle .
	void erase() {
		drawPaddle(' ');
	}

	void drawPaddle(char figure = PADDLE_SHAPE) const ;

	virtual void move()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);

		if (dir_y == 1)
		{
			movePad(up, down);
		}
		else
		{
			movePad(down, up);
		}
		SetConsoleTextAttribute(h, 15);
	}

	virtual~Paddle() {};



	friend class Game;
	friend class Screen;
	friend class Tetris;

};
#endif // !Paddle_h
