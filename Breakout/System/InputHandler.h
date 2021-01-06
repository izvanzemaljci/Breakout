#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#define SDL_MAIN_HANDLED
#include "../game.h"
#include "System.h"
#include "Components.h"

class InputHandler : public Component
{
public:
	TransformComponent *transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			default:
				break;
			}
		}

		if (transform->position.x < 98) {
			transform->position.x = 98;
		}
		else if (transform->position.x > 682) {
			transform->position.x = 682;
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			case SDLK_ESCAPE:
				Game::isRunning = false;
			default:
				break;
			}
		}
	}
};

#endif