#include <stdio.h>
#include <unistd.h>

void printName()
{
	printf("Ahmed\n");
}

int main()
{
	void (*print)();
	print = &printName;
	print();
	print();
	print();
	print();
	sleep(5);
}


