#ifndef _Point_h
#define _Point_h

#include <iostream>
using namespace std;

#include "Utils.h"

class Point
{
	int x, y;
	char ch;
	void draw(char c)
	{
		gotoxy(x, y);
		cout << c;
	}
public:
	Point(int x1, int y1, char c) :x(x1), y(y1), ch(c) {}

	/*void move() {			// to check if needs . 

	}*/

	void draw() {
		
		draw(ch);
	}
	void erase() {
		draw(' ');
	}
	void move(int dir_x, int dir_y) {
		x += dir_x;
		y += dir_y;
	}
	void setX(int x1) { x = x1; }
	void setY(int y1) { y= y1; }

	int getX() { return x; }
	int getY() { return y; }

	Point operator+(int toAdd) const
	{
		return Point(x + toAdd,y + toAdd,this->ch);	
	}
};

#endif

