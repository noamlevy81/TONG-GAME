#ifndef _KeyBoardManager_h
#define _KeyBoardManager_h

#include <iostream>
#include <conio.h>
using namespace std;

#include "Menu.h"
#include "Paddle.h"
#include <list>


class KeyBoardManager
{
	enum { Escape = 27 };
	enum { NUM_OF_CHARS = 26 };
	list<Paddle*> objectsKeysMap[NUM_OF_CHARS];

	int getIndex(char key)
	{
		key = tolower(key);
		int index = key - 'a';

		if (index < 0 || index >25)
			return -1;

		return index;
	}

public:

	void registerKeyBoardManager(Paddle* p);
	void clearKeysHistory();
	int handleKb(Menu& menu);

};

#endif

