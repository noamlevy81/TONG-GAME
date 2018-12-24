#include "Paddle.h"

#include "Screen.h"

void Paddle:: movePad(Point &first, Point & second)
{
	if (up.getY() + dir_y != Screen::TOP_BORDER && down.getY() + dir_y != Screen::BOTTOM_BORDER) {
		first.erase();
		first.move(0, dir_y);
		second.move(0, dir_y);
		second.draw();
	}
}

void Paddle::drawPaddle(char figure )
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	int times = down.getY() - up.getY() + 1;

	int indexX = up.getX();
	int indexY = up.getY();

	for (int i = 0; i < times; i++)
	{
		gotoxy(indexX, indexY + i);
		cout << figure;
	}
	SetConsoleTextAttribute(h, 15);
}