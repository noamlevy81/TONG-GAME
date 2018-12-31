#include "KeyBoardManager.h"
#include "Menu.h"
#include "kbListener.h"

void KeyBoardManager ::registerKeyBoardManager(kbListener * p)
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
int KeyBoardManager::handleKb(Menu& menu)		
{
	if (_kbhit())
	{
		char key = (_getch());
		if (key == Escape)
		{
			system("cls");
			int choice = menu.printMenu(true);
			return choice;
		}
		int index = getIndex(key);
		if (index != -1)
		
			for (auto p : objectsKeysMap[index])
			{
				p->changeCurrentKey(key);
			}
	}
		return 10;			//return 10 for do nothing in run loop . 
}

void KeyBoardManager::clearKeysHistory(){
	for(int i=0;i< NUM_OF_CHARS;i++)
	{
		objectsKeysMap[i].clear();
	}
}

