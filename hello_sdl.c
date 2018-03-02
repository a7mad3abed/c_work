#include <stdio.h>
#include <SDL2/SDL.h>
#define WIDTH 640
#define HEIGHT 480

SDL_Window *window;
int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}
	printf("initialization successful!\n");
	window = SDL_CreateWindow(
			"A new game",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIDTH,
			HEIGHT,
			SDL_WINDOW_RESIZABLE
			);
	if(window == NULL)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Delay(4000);

	SDL_DestroyWindow(window);


	SDL_Quit();
}
