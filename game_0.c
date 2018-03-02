#include <stdio.h>
#include <SDL2/SDL.h>
#define WIDTH	640
#define HEIGHT	480
#define SCROLL_SPEED 200

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Window* window = SDL_CreateWindow(
			"Game no. 0",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIDTH, 
			HEIGHT,
			0
			);
	if(!window)
	{
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
	if(!renderer)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Surface* surface = SDL_LoadBMP("Untitled.bmp");
	if (!surface)
	{
		printf("error creating surface\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!tex)
	{
		printf("error creating texture\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Rect dest;
	SDL_QueryTexture (tex, NULL, NULL, &dest.w, &dest.h);
//	dest.x = (WIDTH - dest.w) / 2;
	float y_pos = HEIGHT;
	float x_pos = 0;

	while (dest.y >= -dest.h)
	{
		SDL_RenderClear(renderer);
		dest.y = (int) y_pos ;
		dest.x = (int) x_pos;
		SDL_RenderCopy(renderer, tex, NULL, &dest);
		SDL_RenderPresent(renderer);

		y_pos -= (float) SCROLL_SPEED / 60;
		x_pos += (float) SCROLL_SPEED / 90;


		SDL_Delay(1000/60);
	}



	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
