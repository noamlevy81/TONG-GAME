#include "Tetris.h"
#include "Screen.h"

bool Tetris::collisionMade(int index,int toAdd_y_val) {
	for (auto& iterator : boards_history[index])
		if (std::abs(iterator.up.getY() - toAdd_y_val) <3)
			return true;

	return false;
}

void Tetris::printTetris() const 
{
	for (int arrInd=0; arrInd <MAX_LOSES; arrInd++)
		for (auto listIt : boards_history[arrInd])
			listIt.drawPaddle();
}

void Tetris:: free()
{
	for (int i = 0;i< 16; i++)
		boards_history[i].clear();
}

void Tetris::addToTetris(Paddle toAdd, int dir_x)
{
	int arrInd;
	if (dir_x == 1)
	{
		while (toAdd.up.getX() < 63)//arr[0] is on x = 63
		{
			movePaddleBack(toAdd, dir_x);
		}//x >=63 when exit loop
		arrInd = 79 - toAdd.up.getX(); //arr[15] is on x=79
	}
	else//dir x = -1
	{
		while (toAdd.up.getX() > MAX_LOSES + 1)
			movePaddleBack(toAdd, dir_x);
		arrInd =toAdd.up.getX() - 1; //arr[15] is on x = 1

	}
	arrInd = 15 - arrInd + 1; //get the location in arr
	
	for (arrInd; arrInd < MAX_LOSES; arrInd++) {
		if (collisionMade(arrInd, toAdd.up.getY()))
		{
			boards_history[arrInd - 1].push_back(toAdd);
			break;
		}
		movePaddleBack(toAdd, dir_x);
	}

	if (arrInd == MAX_LOSES)
		boards_history[MAX_LOSES - 1].push_back(toAdd);
		
	if (boards_history[arrInd - 1].size() == 7)
	{
		deleteLine(arrInd - 1,dir_x);
		theScreen->pushFiveSteps(dir_x);
	}
}

void Tetris::deleteLine(int ind,int dirX) {
	for (auto& iterator : boards_history[ind])
		iterator.erase();

	boards_history[ind].clear();

	for (int i = ind; i > 0; i--) {
		boards_history[i] = boards_history[i - 1];
		boards_history[i-1].clear();
		for (auto& iterator : boards_history[i])
		{
			movePaddleBack(iterator, dirX);
		}
	}
}