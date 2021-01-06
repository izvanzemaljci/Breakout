#pragma once

#ifndef SCORE_H
#define SCORE_H

#define SDL_MAIN_HANDLED
#include "SDL_ttf.h"
#include "Vector2D.h"
#include "System/System.h"
#include "System/Components.h"
#include "TextureHandler.h"
class Score : public Component
{
	public:
		Score(Vector2D position, SDL_Renderer *renderer, TTF_Font *font);
		~Score();
		void draw() override;

		TTF_Font *font;
		SDL_Renderer *renderer;
		SDL_Surface *surface {};
		SDL_Texture *texture {};
		SDL_Rect srcRect, destRect;
};
#endif