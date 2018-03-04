#include "../include/mylib.h"

extern void disp_all();
extern void remove_book();
extern void new_book();
extern void  display();
int c;
int main()
{
	initscr();
	noecho();
	cbreak();

	clear();
	display();

	while ((c = getch()) != 'q')
	{
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
				mvprintw(LINES-2, 0, "                                 ");
				mvprintw(LINES-2, 0, "not a valid option");
		}
	}

	endwin();
}
