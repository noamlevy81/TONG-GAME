#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "Paddle.h"

#include <conio.h>
using namespace std;

class Menu
{
	void printFace() const ;
	void printHeader() const ;

public:
	int printMenu(bool pause) const ;
	void instructions() const ;
	void setUpKeys(Paddle* l, Paddle* r) const ;
	void gameOver(int side) const ;
	int getLevelRight() const;
	int getLevelLeft() const ;

};

#endif

