#ifndef __BallState_h
#define __BallState_h

class Ball;
class Screen;

enum { ONE_POINT = 1 };
class BallState
{
protected :
	Ball& ball;
	Screen& screen;
public:
	BallState(Ball& b,Screen& s) : ball(b),screen(s) {}

	virtual void missedPaddle() = 0;
	virtual void hitPaddle() {}
	virtual void hitBorder() {}
	virtual void hitCorner() {}
	virtual void bombKeyPressed(char key) {}
	virtual void hitTetris(int x) {}
	virtual void timeEvent(){}
	virtual int getColor() { return 8; }//default color

	virtual ~BallState() {}
	friend class Ball;
};

#endif

