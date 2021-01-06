#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "System/Components.h"

class Collider;

enum class CollisionType
{
	None,
	Top,
	Bottom,
	Middle,
	Left,
	Right
};

struct Contact
{
	CollisionType type;
	float penetration;
};

class Collision
{
public:
	static bool AABB(const SDL_Rect &rectA, const SDL_Rect &rectB);
	static bool AABB(const Collider &colA, const Collider &colB);
	static void OnCollision();
	static Contact BallVesselCollision(TransformComponent const  &ball, TransformComponent const &vessel);
	static void VesselCollision(TransformComponent &ball, Contact const &contact);
	static Contact CheckWallCollisionType(TransformComponent &ball);
	static void WallCollision(TransformComponent &ball, Contact const &contact);
};

#endif
