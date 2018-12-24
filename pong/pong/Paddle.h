#ifndef Paddle_h
#define Paddle_h 

#include "Point.h"

const char PADDLE_SHAPE = '#';

class Paddle
{
	char  keys[3];
	int dir_y = 1;
	Point down, up;

	void movePad(Point &first, Point & second);

public:
	Paddle(const Point& up1,const Point& down1) : up(up1), down(down1) {};

	//erase the paddle .
	void erase() {
		drawPaddle(' ');
	}

	void drawPaddle(char figure = PADDLE_SHAPE);


	//this function set the keys of the player . 
	void setKeys(char up, char down)
	{
		keys[0] = up;
		keys[1] = down;
	}

	void move()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);

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

	const char* getChars()
	{
		return keys;
	}

	//translate keyboard input to action
	void handleKey(char key) {
		if (key == keys[0])				//move up 
			dir_y = -1;
		else if (key == keys[1])
			dir_y = 1;
		move();
	}

	friend class Game;
	friend class Screen;
	friend class Tetris;

};
#endif // !Paddle_h
