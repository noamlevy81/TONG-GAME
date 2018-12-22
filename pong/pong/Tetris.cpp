#include "Tetris.h"

void Tetris::addToRightTetris(Paddle toAdd)
{
	while (toAdd.up.getX() < 62)				//arr[0] is on x = 62
	{
		movePaddleBack(toAdd, 1);
		Sleep(50);
	}//x >=62 when exit loop

	int i = toAdd.up.getX() - 62;

	for (i; i < 16; i++)
	{
		if (collisionMade(i, toAdd.up.getY()))
		{
			boards_history[i - 1].push_back(toAdd);
			break;
		}
		movePaddleBack(toAdd, 1);
		Sleep(50);
	}
	if (i == 16)
	{
		boards_history[15].push_back(toAdd);
	}
}
void Tetris::addToLeftTetris(Paddle toAdd)
{

	while (toAdd.up.getX() > MAX_LOSES + 2)
	//arr[15] is on x = 17 = MAX_LOSES+1 so we want to check colisions only when the paddle x is on this position
	{
		movePaddleBack(toAdd, -1);
		Sleep(50);
	}//x <=18 when exit loop

	int i = toAdd.up.getX()-3;				// x = i+2 and we want to check the paddle next step which is x-3
	for (i; i >= 0; i--)
	{
		if (collisionMade(i,toAdd.up.getY()))
		{
			boards_history[i+1].push_back(toAdd);
			break;
		}
		movePaddleBack(toAdd, -1);
		Sleep(50);
	}

	//case was no collision add to arr[0]
	if (i == -1)
		boards_history[0].push_back(toAdd);
}


bool Tetris::collisionMade(int index,int toAdd_y_val) {
	for (auto iterator : boards_history[index])
		if (std::abs(iterator.up.getY() - toAdd_y_val) <3)
			return true;

	return false;
}
//-------------------------needs to be added to the resume part--------------------------
void Tetris::printTetris() {
	for (int arrInd=0; arrInd <MAX_LOSES; arrInd++)
		for (auto listIt : boards_history[arrInd])
			listIt.drawPaddle();
}