#pragma once
#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#define SDL_MAIN_HANDLED
#include "System.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "../game.h"
#include "../TextureHandler.h"

class TileComponent : public Component
{
public:
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;
	int tileID;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 24;
		srcRect.h = 8;

		destRect.x = x;
		destRect.y = y;
		destRect.w = w;
		destRect.h = h;

		tileID = id;

		switch (tileID)
		{
		case 72: //H
			texture = TextureHandler::LoadTexture("Textures/Bricks/Hard.png");
			break;
		case 73: //I
			texture = TextureHandler::LoadTexture("Textures/Bricks/Medium.png");
			break;
		case 77: //M
			texture = TextureHandler::LoadTexture("Textures/Bricks/Medium.png");
			break;
		case 83: //S
			texture = TextureHandler::LoadTexture("Textures/Bricks/Soft.png");
			break;
		default:
			break;
		}
	}

	void draw() override
	{
		TextureHandler::DrawTexture(texture, srcRect, destRect);
	}
};
#endif
