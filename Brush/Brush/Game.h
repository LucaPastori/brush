#include <SDL.h>
#include <string>
#pragma once
class Game
{
public:
	Game(int w, int h);
	~Game();

	bool init();
	bool loadMedia();
	void update();
	void close();


private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* imageSurface;
	std::string title;
	int width;
	int height;


};

