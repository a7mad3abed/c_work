#include <stdio.h>
#include <stdlib.h>

#define SUMOF(a, b, c, d) (printf("%d\n", ((atoi(a))+(atoi(b))+(atoi(c))+(atoi(d)))))


int main(int argc, char *argv[])
{

	SUMOF(argv[1],argv[2],argv[3],argv[4]);
}

