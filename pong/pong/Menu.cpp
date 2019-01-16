#include "Menu.h"
#include "HumanPlayer.h"

void Menu ::instructions() const
{
	int x = 1;
	int y = 7;
	gotoxy(x, y);
	cout << "welcome to pong-tetris game ,this is two players game.";
	gotoxy(x, y + 2);
	cout << "each player should keep the ball out of his goal (his side of the screen)";
	gotoxy(x, y + 4);
	cout << "in case a player misses the ball, he will lose one point";
	gotoxy(x, y + 6);
	cout << "and then the paddle will fall back toards the loses player goal.";
	gotoxy(x, y + 8);
	cout << "each player can miss the ball 16 times before losing the game.";
	gotoxy(x, y + 10);
	cout << "you can gain 5 more points of life by completing a full line";
	gotoxy(x, y + 12);
	cout << "using the falling boards(like tetris)";
	gotoxy(x, y + 14);
	cout << "enjoy - good luck .";
	gotoxy(x, y + 14);
	cout << "pres any key to continue";
	char k = (_getch());
	system("cls");

}

void Menu:: setUpKeys(Paddle* l, Paddle* r) const 
{
	system("cls");

	char temp[2];
	int wantL;
	int wantR;

	if (strcmp(typeid(*l).name(), typeid(HumanPlayer).name()) == 0)
	{
		cout << "if you want to change key for the left player press 1 else press 0 ";
		cin >> wantL;

		if (wantL == 1) {
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			((HumanPlayer*)l)->setKeys(temp[0], temp[1]) ;

		}
	}

	if (strcmp(typeid(*r).name(), typeid(HumanPlayer).name()) == 0)
	{
		cout << "if you want to change key for the right player press 1 else press 0 ";
		cin >> wantR;

		if (wantR == 1) {
			cout << "Enter key to move up:\n\n";
			cin >> temp[0];
			cout << "Enter key to move down:\n\n";
			cin >> temp[1];
			((HumanPlayer*)r)->setKeys(temp[0], temp[1]);
		}
	}
	
	cout << "keys changed succesfully ";
	Sleep(250);
	system("cls");
}

void Menu :: printFace()  const  {
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

void Menu:: gameOver(int side) const
{
	system("cls");
	printFace();
	if (side == LEFTS)
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

void Menu:: printHeader()const 
{
	int x = 0, y = 2;
	gotoxy(x, y++);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);

	cout << " ######  ####### #     #  #####     ####### ####### ####### ######  ###  #####";
	gotoxy(x, y++);
	cout << " #     # #     # ##    # #     #       #    #          #    #     #  #  #     # ";
	gotoxy(x, y++);

	cout << " #     # #     # # #   # #             #    #          #    #     #  #  #";
	gotoxy(x, y++);

	cout << " ######  #     # #  #  # #  #### ###   #    #####      #    ######   #   #####";
	gotoxy(x, y++);

	cout << " #       #     # #   # # #     #       #    #          #    #   #    #        #";
	gotoxy(x, y++);

	cout << " #       #     # #    ## #     #       #    #          #    #    #   #  #     #";
	gotoxy(x, y++);

	cout << " #       ####### #     #  #####        #    #######    #    #     # ###  #####";

	SetConsoleTextAttribute(h, 15);
}

int Menu::getLevelRight() const
{
	system("cls");
	int x = 30;
	int y = 12;
	gotoxy(x, y);
	cout << "Enter level for right pc player:0 for novice,";
	gotoxy(x, y + 2);
	cout<< "1 for good and 2 for expert ";
	gotoxy(x, y + 4);

	int z;
	cin >> z;
	system("cls");
	return z;

}

int Menu::getLevelLeft() const
{
	system("cls");
	int x = 30;
	int y = 12;
	gotoxy(x, y);
	cout << "Enter level for left pc player:0 for novice,";
	gotoxy(x, y + 2);
	cout <<"1 for good and 2 for expert ";
	gotoxy(x, y + 4);

	int z;
	cin >> z;
	system("cls");

	return z;

}

int Menu ::printMenu(bool pause) const
{
	int x = 30;
	int y = 8;
	system("cls");
	printHeader();
	int choice;
	if (pause == false)
	{
		gotoxy(x, y + 2);
		cout << "Choose one of the following:";
		gotoxy(x, y + 4);
		cout << "1.Start new game human Vs human";
		gotoxy(x, y + 6);
		cout << "2.Start new game human Vs computer";
		gotoxy(x, y + 8);
		cout << "3.Start new game computer Vs computer";
	}
	else
	{
		gotoxy(x, y + 8);
		cout << "1.start a new game ";
		gotoxy(x, y + 10);
		cout << "4.to continue";
		gotoxy(x, y + 12);
		cout << "5.Set up keys";
	}
	gotoxy(x, y + 14);
	cout << "8.How to play?";
	gotoxy(x, y + 16);
	cout << "9.Exit";
	gotoxy(x, y + 18);

	cin >> choice;
	system("cls");
	return choice;
}
