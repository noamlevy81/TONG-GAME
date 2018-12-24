#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "Paddle.h"

#include <conio.h>
using namespace std;

class Menu
{
public:

	static int printMenu(bool pause)
	{
		system("cls"); 
		int choice;
		cout << "MENU:\n";
		cout << "Choose one of the following:\n";

		cout << "1.Start new game\n\n";
		if (pause == true)
			cout << "2.to continue\n\n";
		cout << "3.Set up keys\n\n";
		cout << "8.How to play?\n\n";
		cout << "9.Exit\n\n";
		cin >> choice;
		system("cls");
		return choice;
	}

	static void instructions()
	{
		cout << "welcome to pong-tetris game ,\n this is two players game , you should .... ";
		cout << "\n enjoy - good luck .\n";
		cout << "pres any key to continue\n";
		char k = (_getch());
		system("cls");

	}

	static void setUpKeys(Paddle& l, Paddle& r)
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

	static void gameOver(int side)
	{
		system("cls");
		if (side == LEFT)
		{
			gotoxy(10, 10);
			cout << "right player win !! ";
		}
		else
		{
			gotoxy(10, 10);
			cout << "left player win !! ";
		}
		cout << endl;
		cout << "press any key to continue ";
		char ch = _getch();
	}

};

#endif

