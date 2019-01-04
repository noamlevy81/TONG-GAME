#ifndef  Utils_h
#define Utils_h

#include <Windows.h>

BOOL gotoxy(const WORD x, const WORD y);

	enum {MAXFORMISS =9 , CENTERFORPADDLE=13};
	enum yBorders{BUTTOM_Y =25 , UPPER_Y=3};
	enum rightPaddle { RIGHT_X = 76, RIGHT_UP_Y = 11, RIGHT_DOWN_Y = 13 };	//floor and ceilling borders
	enum leftPaddle { LEFT_X = 4, LEFT_UP_Y = 10, LEFT_DOWN_Y = 12 };
	enum ballDirection{LEFT=-1,RIGHT=1};
	enum ArenaCenter{ARENA_CENTER=40};

	void ShowConsoleCursor(bool showFlag);

#endif // ! Utils+h
