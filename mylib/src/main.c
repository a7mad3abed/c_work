#include "../include/mylib.h"

void disp_all();
void remove_book();
void new_book();
void  display();

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

void display()
{
	initscr();
	noecho();
	cbreak();
	char *welcome = "Welcome to my lib, a program to help sorting your books";
	int y, x;
	y = LINES/2;
	x = (COLS-strlen(welcome))/2;


	mvprintw(y, x, welcome);
	mvprintw(++y, x+1, "to display all books please press d");
	mvprintw(++y, x+1, "to add a new book please press n");
	mvprintw(++y, x+1, "to remove an existing book please press r");
	mvprintw(++y, x+1, "to quit the program please press q");
	endwin();
}
