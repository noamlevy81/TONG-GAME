#ifndef Menu_h
#define Menu_h

#include <iostream>
using namespace std;
#include "Paddle.h"

class Menu
{
public:

	static int firstMenu()
	{
		int choice;
		cout << "MENU:\n";
		cout << "Choose one of the following:\n";
		cout << "1.How to play?\n\n";
		cout << "2.Start new game\n\n";
		cout << "3.Set up keys\n\n";
		cout << "4.Exit\n\n";
		cin >> choice;
		system("cls");
		return choice;
	}

	static void instructions()
	{
		cout << "some instructions...";
	}

	static void setUpKeys(Paddle& l, Paddle& r)
	{
		char temp[2];
		int wantL;
		int wantR;

		cout << "if you want to change key for the left player press 1 else press 0 ";
		cin >> wantL;

		if (wantL == 1){
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			l.setKeys(temp[0], temp[1]);
		}

		cout << "if you want to change key for the right player press 1 else press 0 ";
		cin >> wantR;

		if (wantR == 1){
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			r.setKeys(temp[0], temp[1]);
		}
	}
};

#endif

