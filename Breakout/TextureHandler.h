#pragma once

#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#define SDL_MAIN_HANDLED
#include "SDL_image.h"
#include "SDL.h"
#include "game.h"

class TextureHandler {
	public:
		static SDL_Texture *LoadTexture(const char *fileName);
		static void DrawTexture(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};

#endif