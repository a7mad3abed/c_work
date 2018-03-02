#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	system("/bin/stty raw");
	while ((c = getchar()) != 'q')
	{
	}

	system("/bin/stty cooked");
	printf("\n");
	return 0;
}
