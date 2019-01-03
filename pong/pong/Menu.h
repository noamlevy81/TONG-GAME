#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "Paddle.h"

#include <conio.h>
using namespace std;

class Menu
{
public:

	int printMenu(bool pause);

	void instructions();

	void setUpKeys(Paddle* l, Paddle* r);

	void gameOver(int side);

	void printFace();

	void printHeader();

};

#endif

