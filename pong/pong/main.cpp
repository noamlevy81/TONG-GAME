#include "main.h"

int main()
{
	Ball b;
	Paddle P({10,12,PADDLE_SHAPE}, {10,14, PADDLE_SHAPE});

	b.drawBall();
	P.drawPaddle();

	int i = 0;

	/*while (i < 1000){
		b.move();
		i++;
		Sleep(150);
	}*/

	while (i < 10)
	{
		P.move();
		Sleep(150);
		i++;
	}
	system("pause");
}