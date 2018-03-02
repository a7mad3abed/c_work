#include "../include/mylib.h"
#define clrscr() printf("\e[1;1H\e[2J")
#include <sys/ioctl.h>

void display()
{
//	clrscr();
	system("clear");
	printf("\n\n\n\t\tWelcome to mylib, a program that should help you keep track of readings\n\n\
			- do display all books please press d\n\n\
			- to add a new book please press n\n\n\
			- to remove an existing book please press r\n\n\
			- to quit the program please press q");
}
