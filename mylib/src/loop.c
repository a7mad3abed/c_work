
#include "../include/mylib.h"



void loop()
{

	while ((c = getchar()) != 'q')
	{
		display();
		switch (c)
		{
			case 'd':
				disp_all();
				break;
			case 'n':
				new_book();
				break;
			case 'r':
				remove_book();
				break;
			case 'q':
				break;
			default:
				mvprintw(LINES, COLS, "not a valid option");
		}
	}
}
