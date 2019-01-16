#include "Ball.h"
#include "Utils.h"
#include "Screen.h"
#include "RegularState.h"

void Ball::initalizeBall()
{
	bombPressedRight = bombPressedLeft = 4;// when game started player can use bomb
	gameLoopCount = 0;
	ballPoints.clear();
	ballPoints.push_back({ 39,11,BALL_SHAPE });
	ballPoints.push_back({ 40,11,BALL_SHAPE });
	ballPoints.push_back({ 38,12,BALL_SHAPE });
	ballPoints.push_back({ 39,12,BALL_SHAPE });
	ballPoints.push_back({ 40,12,BALL_SHAPE });
	ballPoints.push_back({ 41,12,BALL_SHAPE });
	ballPoints.push_back({ 39,13,BALL_SHAPE });
	ballPoints.push_back({ 40,13,BALL_SHAPE });

}

void Ball::draw() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = theState->getColor();
	SetConsoleTextAttribute(h, color);

	for (int i = 0; i < NUM_POINTS; i++)
		ballPoints.at(i).draw();

	SetConsoleTextAttribute(h, 15);
}

void Ball::setDirX()
{
	int ind;
	if (dir_x == ballDirection::RIGHT)
	{
		if (theScreen->isOnXBorder(ballPoints.at(5).getX() + dir_x, dir_x))
		{
			if (theScreen->isOnYOfThePaddles(ballPoints.at(5).getY(), dir_x, dir_y))
			{
				theState->hitPaddle();
			}

			else if (theScreen->isOnYCornerofTheRightPaddle(ballPoints.at(5).getY() + dir_y, dir_y))
			{
				theState->hitCorner();
			}
			else                            //miss paddle 
			{
				theState->missedPaddle();
			}
		}
		else if (theScreen->isOnXAfterDeath(ballPoints.at(5).getX() + dir_x, dir_x))
		{
			//check border collision 
			if (ballPoints.at(0).getY() + dir_y <= Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y >= Screen::BOTTOM_BORDER)
				theState->hitBorder();
			//check tetris collision
			if (theScreen->ballHitTetris(dir_x, dir_y, ballPoints.at(5).getX(), ballPoints.at(5).getY(), &ind))
				theState->hitTetris(ind);
		}
	}

	else      //dir_x is -1 means that we go left . 
	{
		if (theScreen->isOnXBorder(ballPoints.at(2).getX() + dir_x, dir_x))
		{
			if (theScreen->isOnYOfThePaddles(ballPoints.at(2).getY(), dir_x, dir_y))   //hit paddle
			{
				theState->hitPaddle();
			}
			else if (theScreen->isOnYCornerofTheLeftPaddle(ballPoints.at(2).getY() + dir_y, dir_y))
			{
				theState->hitCorner();
			}
			else                      //miss paddle
			{
				theState->missedPaddle();

			}
		}
		else if (theScreen->isOnXAfterDeath(ballPoints.at(2).getX() + dir_x, dir_x))
		{
			//check border collision 
			if (ballPoints.at(0).getY() + dir_y <= Screen::TOP_BORDER || ballPoints.at(7).getY() + dir_y >= Screen::BOTTOM_BORDER)
				theState->hitBorder();
			//check tetris collision
			if (theScreen->ballHitTetris(dir_x, dir_y, ballPoints.at(2).getX(), ballPoints.at(2).getY(), &ind))
				theState->hitTetris(ind);
		}
	}
}

void Ball::animationHitPaddleLeft()
{
	int direction = dir_y;

	eraseBall();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	//this block take the ball one step to the paddle . 
	dir_x = -1;
	dir_y = 0;
	changePointsByDir();

	if (direction != ballDirection::RIGHT)
		ballPoints.at(1).draw();
	else
		ballPoints.at(7).draw();

	ballPoints.at(0).draw();
	ballPoints.at(3).draw();
	ballPoints.at(4).draw();
	ballPoints.at(5).draw();
	ballPoints.at(6).draw();

	Sleep(50);

	SetConsoleTextAttribute(h, 15);
	////////////////////////////////////////////

	if (direction != ballDirection::RIGHT)
		ballPoints.at(1).erase();
	else
		ballPoints.at(7).erase();

	ballPoints.at(0).erase();
	ballPoints.at(3).erase();
	ballPoints.at(4).erase();
	ballPoints.at(5).erase();
	ballPoints.at(6).erase();


	dir_y = direction;
	dir_x = 1;

	changePointsByDir();

	int point1, point2;

	if (direction == ballDirection::LEFT)
	{
		point1 = 6;
		point2 = 7;
	}
	else
	{
		point1 = 0;
		point2 = 1;
	}

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() + 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() + 1);

	Sleep(50);
	draw();


	dir_x = 0;

	eraseBall();

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() - 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() - 1);

	Sleep(20);
	draw();
	Sleep(20);
	eraseBall();

	dir_x = 1;
}
void Ball::animationHitPaddleRight()
{
	int direction = dir_y;

	eraseBall();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);

	//this block take the ball one step to the paddle . 
	dir_x = 1;
	dir_y = 0;
	changePointsByDir();

	if (direction != ballDirection::RIGHT)
		ballPoints.at(0).draw();
	else
		ballPoints.at(6).draw();

	ballPoints.at(1).draw();
	ballPoints.at(2).draw();
	ballPoints.at(3).draw();
	ballPoints.at(4).draw();
	ballPoints.at(7).draw();

	Sleep(50);

	SetConsoleTextAttribute(h, 15);
	////////////////////////////////////////////

	if (direction != ballDirection::RIGHT)
		ballPoints.at(0).erase();
	else
		ballPoints.at(6).erase();

	ballPoints.at(1).erase();
	ballPoints.at(2).erase();
	ballPoints.at(3).erase();
	ballPoints.at(4).erase();
	ballPoints.at(7).erase();

	dir_y = direction;
	dir_x = -1;

	changePointsByDir();

	int point1, point2;

	if (direction == ballDirection::LEFT)
	{
		point1 = 6;
		point2 = 7;
	}
	else
	{
		point1 = 0;
		point2 = 1;
	}

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() + 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() + 1);

	Sleep(50);
	draw();


	dir_x = 0;

	eraseBall();

	ballPoints.at(point1).setX(ballPoints.at(point1).getX() - 1);
	ballPoints.at(point2).setX(ballPoints.at(point2).getX() - 1);

	Sleep(20);
	draw();
	Sleep(20);
	eraseBall();

	dir_x = -1;
}

void Ball::changePointsByDir()
{
	for (int i = 0; i < NUM_POINTS; i++)
	{
		ballPoints.at(i).setX(ballPoints.at(i).getX() + dir_x);
		ballPoints.at(i).setY(ballPoints.at(i).getY() + dir_y);
	}
}

void Ball::eraseBall()
{
	for (int i = 0; i < NUM_POINTS; i++)
		ballPoints.at(i).erase();
}

//states methods
RegularState& Ball::getRegular()
{
	return regular_s;
}

BecomingAbombState& Ball::getBcomingBomb()
{
	return BecomingABomb_s;
}
BombState& Ball::getBomb()
{
	return bomb_s;
}