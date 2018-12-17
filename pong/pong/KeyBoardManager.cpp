#include "KeyBoardManager.h"


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

void KeyBoardManager::handleKb()
{
	if (_kbhit())
	{

	}
}

