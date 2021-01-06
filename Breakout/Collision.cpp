#include "Collision.h"
#include "System\Collider.h"

bool Collision::AABB(const SDL_Rect & rectA, const SDL_Rect & rectB)
{
	if (SDL_HasIntersection(&rectA, &rectB))
	{
		return true;
	}
	else {
		return false;
	}
}

bool Collision::AABB(const Collider & colA, const Collider & colB)
{
	if (AABB(colA.collider, colB.collider))
	{
		std::cout << colA.tag << " hit: " << colB.tag << std::endl;
		return true;
	}
	return false;
}