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
	virtual ~BallState() {}

	virtual void missedPaddle() {}
	virtual void hitPaddle() {}
	virtual void hitBorder() {}
	virtual void hitCorner() {}
	virtual void bombKeyPressed() {}
	virtual void hitTetris(int x) {}
	virtual void timeEvent(){}
	friend class Ball;
};

#endif

