#pragma once

#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <vector>

class Collider;

class Game {
	public:
		Game();
		~Game();

		//initialization mathod
		void init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen);
	
		void handleEvents();
		void update();
		void render();
		void clean();
		bool running() { return isRunning; }

		static SDL_Renderer *renderer;
		static SDL_Event event; 
		static TTF_Font *scoreFont;
		static bool isRunning;
		enum groupLabels : std::size_t
		{
			groupWalls,
			groupMap,
			groupPlayer,
			groupColliders,
			groupBackground,
		};

	private:
		int count = 0;
		SDL_Window *window;
};

#endif

