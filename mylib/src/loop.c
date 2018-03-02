#include "../include/mylib.h"
#include <termios.h>

struct termios info;
tcgetattr(0, &info);

//info.c_lflag &= ~ICANON;
//info.c_cc[VMIN] = 1;
//info.c_cc[VTIME] = 0;
//tcsetattr(0, TCSANOW, &info);


void loop()
{
	int c ;

	while ((c = getchar()) != 'q')
	{
		display();
	}
}
