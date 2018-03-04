#include "../include/mylib.h"
void display()
{
	char *welcome = "Welcome to my lib, a program to help sorting your books";
	int y, x;
	y = LINES/2;
	x = (COLS-strlen(welcome))/2;


	mvprintw(y, x, welcome);
	mvprintw(++y, x+1, "to display all books please press d");
	mvprintw(++y, x+1, "to add a new book please press n");
	mvprintw(++y, x+1, "to remove an existing book please press r");
	mvprintw(++y, x+1, "to quit the program please press q");
}
