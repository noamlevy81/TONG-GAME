#ifndef _HumanPlayer
#define _HumanPlayer

#include "Paddle.h"
#include "kbListener.h"

class HumanPlayer : public Paddle, public kbListener
{
private:
	char  keys[MAX_KEYS];
	char currentKey = 0;

	void handleKey()
	{
		if (currentKey == 0)
			return;
		if (currentKey == keys[0])				//move up 
			setDirY(ballDirection::LEFT);					
		else if (currentKey == keys[1])
			setDirY(1);
	}

public:
	HumanPlayer(const Point& up1, const Point& down1) : Paddle(up1, down1)
	{
		keys[0] = 'q';
		keys[1] = 'a';
	}
	
	//this function set the keys of the player . 
	void setKeys(char up, char down)
	{
		keys[0] = up;
		keys[1] = down;
	}

	virtual void changeCurrentKey(char key) override
	{
		currentKey = key;
	}

	virtual const char* getChars() override
	{
		return keys;
	}

	//translate keyboard input to action
	virtual void move() override
	{
		handleKey();
		if(currentKey)
			Paddle::move();

		currentKey = 0;

	}

};


#endif // !
