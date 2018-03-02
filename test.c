#include <stdio.h>
#include <stdlib.h>

#define RADIO	0x01
#define TV	0x02
#define PC	0x04
#define HANDY	0x08

int main(int argc, char **argv)
{
	const char *c = argv[1];

	int sw = atoi(c);

	switch(sw)
	{
		case (RADIO):
			printf("Radio choosed");
			break;
		case(TV):
			printf("TV choosed");
			break;
		case (RADIO|TV):
			printf("TV & Radio choosed");
			break;
		case (PC):
			printf("PC choosed");
			break;
		case (PC|TV):
			printf("PC und TV");
			break;
		case (RADIO|PC):
			printf("Radio und PC choosed");
			break;
		case (RADIO|TV|PC):
			printf("Radio, TV und PC");
			break;
		case (HANDY):
			printf("Handy");
			break;
		case (HANDY|RADIO):
			printf("Handy und radio");
			break;
		case (HANDY|TV):
			printf("Handy und TV");
			break;
		case (HANDY|PC):
			printf("Handy und PC");
			break;
		case (HANDY|RADIO|TV):
			printf("Handy und radio und TV");
			break;
		case (HANDY|RADIO|TV|PC):
			printf("Handy und radio nd TV und PC");
			break;
		case (HANDY|TV|PC):
			printf("Handy und TV und PC");
			break;
		case (HANDY|RADIO|PC):
			printf("Handy und radio und PC");
			break;
		default:
			printf("It was something else");
	}
}

