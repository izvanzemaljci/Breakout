#pragma once
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#define SDL_MAIN_HANDLED
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
	public:
		Vector2D position;
		Vector2D velocity;

		int height = 0;
		int width = 0;
		int scale = 1;

		int speed = 0;


		TransformComponent()
		{
			position.Zero();
		}

		TransformComponent(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		TransformComponent(float x, float y, int h, int w, int s)
		{
			position.x = x;
			position.y = y;
			height = h;
			width = w;
			scale = s;
		}

		void setVelocity(float x, float y)
		{
			velocity.x = x;
			velocity.y = y;
		}

		void move(float x, float y, int speed)
		{
			setVelocity(x, y);
			this->speed = speed;
		}

		void init() override
		{
			velocity.Zero(); 
		}

		void update() override 
		{ 
			position.x += velocity.x * speed;
			position.y += velocity.y * speed;
		}

		void update(int speed)
		{
			position.x += velocity.x * speed;
			position.y += velocity.y * speed;
		}

};

#endif