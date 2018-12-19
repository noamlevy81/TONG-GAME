#include "KeyBoardManager.h"
#include "Menu.h"


void KeyBoardManager ::registerKeyBoardManager(Paddle* p)
{
	const char * keys = p->getChars();
	size_t numChars = strlen(keys);

	for (size_t i = 0; i < numChars; i++)
	{
		int index = getIndex(keys[i]);
		if (index != -1)
			objectsKeysMap[index].push_back(p);
	}
}

int KeyBoardManager::handleKb()		//cahgne to int 
{
	if (_kbhit())
	{
		char key = (_getch());

		if (key == Escape)
		{
			system("cls");
			int choice = Menu::firstMenu(true);
			return choice;
			//case new game - new game from the begining - void run  - get out from loop .
			//continue game - statys in the loop draw paddles and ball in their last places . 
			// instructions - write the instructions and get in back ? 
			//exit - exit . 
		}
		int index = getIndex(key);
		if (index != -1)
		
			for (auto p : objectsKeysMap[index])
			{
				p->handleKey(key);
			}
	}
		return 1;
}

