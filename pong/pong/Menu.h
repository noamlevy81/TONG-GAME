#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "Paddle.h"

#include <conio.h>
using namespace std;

class Menu
{
public:

	int printMenu(bool pause)
	{
		int x = 30;
		int y = 7;
		system("cls"); 
		int choice;
		gotoxy(x, y);
		cout << "MENU:";
		gotoxy(x, y+2);
		cout << "Choose one of the following:";
		gotoxy(x, y+4);
		cout << "1.Start new game";
		if (pause == true) {
			gotoxy(x,y+6);
			cout << "2.to continue";
			y += 2;
		}
		gotoxy(x, y+6);
		cout << "3.Set up keys";
		gotoxy(x, y+8);
		cout << "8.How to play?";
		gotoxy(x, y+10);
		cout << "9.Exit";
		cin >> choice;
		system("cls");
		return choice;
	}

	void instructions()
	{
		int x = 1;
		int y = 7;
		gotoxy(x, y);
		cout << "welcome to pong-tetris game ,this is two players game.";
		gotoxy(x, y+2);
		cout << "each player should keep the ball out of his goal (his side of the screen)";
		gotoxy(x, y+4);
		cout << "in case a player misses the ball, he will lose one point";
		gotoxy(x, y+6);
		cout << "and then the paddle will fall back toards the loses player goal.";
		gotoxy(x, y+8);
		cout << "each player can miss the ball 16 times before losing the game.";
		gotoxy(x, y+10);
		cout << "you can gain 5 more points of life by completing a full line";
		gotoxy(x, y+12);
		cout<<"using the falling boards(like tetris)";
		gotoxy(x,y+14);
		cout << "enjoy - good luck .";
		gotoxy(x, y +14);
		cout << "pres any key to continue";
		char k = (_getch());
		system("cls");

	}

	void setUpKeys(Paddle& l, Paddle& r)
	{
		char temp[2];
		int wantL;
		int wantR;

		cout << "if you want to change key for the left player press 1 else press 0 ";
		cin >> wantL;

		if (wantL == 1) {
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			l.setKeys(temp[0], temp[1]);
		}

		cout << "if you want to change key for the right player press 1 else press 0 ";
		cin >> wantR;

		if (wantR == 1) {
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			r.setKeys(temp[0], temp[1]);
		}


		cout << "keys changed succesfully ";
		Sleep(250);
		system("cls");
	}

	void gameOver(int side)
	{
		system("cls");
		printFace();
		if (side == LEFT)
		{
			gotoxy(50, 10);
			cout << "right player win !! ";
		}
		
		else
		{
			gotoxy(50, 10);
			cout << "left player win !! ";
		}
		char ch = _getch();
	}


	void printFace() {
		int x = 2, y = 7;
		gotoxy(x, y++);
		cout << "´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶¶";
		gotoxy(x, y++);

		cout << "´´´´´´´´´´´´´´´´´´´´¶¶´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´´¶¶¶¶¶´´´´´´´¶¶´´´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´¶´´´´´¶´´´´¶¶´´´´´¶¶´´´´¶¶´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´¶´´´´´¶´´´¶¶´´´´´´¶¶´´´´¶¶´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´¶´´´´¶´´¶¶´´´´´´´´¶¶´´´´¶¶´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´´¶´´´¶´´´¶´´´´´´´´´´´´´´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´¶´´´´´´´´´´´´¶´¶¶´´´´´´´´´´´´´¶¶´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´¶¶´´´´´´´´´´´´¶´´¶¶´´´´´´´´´´´´¶¶´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´¶¶´´´¶¶¶¶¶¶¶¶¶¶¶´´´´¶¶´´´´´´´´¶¶´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´¶´´´´´´´´´´´´´´´¶´´´´´¶¶¶¶¶¶¶´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´¶¶´´´´´´´´´´´´´´¶´´´´´´´´´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´¶´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´¶¶´´´´´´´´´´´¶´´¶¶´´´´´´´´´´´´´´´´¶¶";
			gotoxy(x, y++);

		cout << "´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´¶¶´´´´´´´´´´´´¶¶";
		gotoxy(x, y++);

		cout << "´´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶";

	}

	


	
	
};

#endif

