#include "../include/mylib.h"

void disp_all();
void remove_book();
void new_book();

int main()
{
	display();

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

void disp_all()
{
	mvprintw(LINES-2, 0, "all displayed");

}

void new_book()
{
	mvprintw(LINES-2, 0, "new book created                ");
}

void remove_book()
{
	mvprintw(LINES-2, 0, "selected book removed successfully");
}
