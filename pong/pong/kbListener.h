#ifndef __kbListener_h
#define __kbListener_h

enum{MAX_KEYS=3};

class kbListener
{
public:
	virtual void changeCurrentKey(char key) {}
	virtual const char *getChars() = 0;
	virtual ~kbListener(){}

};
#endif
