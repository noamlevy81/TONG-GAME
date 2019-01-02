#ifndef __BallState
#define __BallState
class BallState
{
protected :
	Ball& ball;
	Screen& screen;
public:
	BallState(Ball& b,Screen& s) : ball(b),screen(s) {}
	virtual ~BallState() {}

	virtual void missedPaddle();
	virtual void hitPaddle();
	virtual void hitBorder();
	virtual void hitCorner();


	friend class Ball;
};

#endif

