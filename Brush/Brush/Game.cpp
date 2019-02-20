#include "game.h"


Game::Game(int w, int h)
{
	window = NULL;
	screenSurface = NULL;
	imageSurface = NULL;
	width = w;
	height = h;
}

Game::~Game() {}


bool Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
		return true;
	}
}
bool Game::loadMedia()
{
	//facciamo un'immagine
	imageSurface = SDL_LoadBMP("aborto.bmp");
	if (imageSurface == NULL)
	{
		return false;
	}
	return true;
}

void Game::update()
{
	SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}

void Game::close()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}