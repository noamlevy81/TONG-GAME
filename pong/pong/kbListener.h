#pragma once
class kbListener
{
public:
	virtual void changeCurrentKey(char key) = 0; 
	virtual const char *getChars()  = 0;

	virtual ~kbListener(){}

};

