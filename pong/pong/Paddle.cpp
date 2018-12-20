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