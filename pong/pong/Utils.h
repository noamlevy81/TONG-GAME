#ifndef  Utils_h
#define Utils_h

#include <Windows.h>

BOOL gotoxy(const WORD x, const WORD y);
	enum rightPaddle { RIGHT_X = 76, RIGHT_UP_Y = 11, RIGHT_DOWN_Y = 13 };	//floor and ceilling borders
	enum leftPaddle { LEFT_X = 4, LEFT_UP_Y = 10, LEFT_DOWN_Y = 12 };
#endif // ! Utils+h
