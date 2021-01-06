#include "Score.h"

Score::Score(Vector2D position, SDL_Renderer *renderer, TTF_Font *font)
	: renderer(Game::renderer), font(Game::scoreFont)
{
	surface = TTF_RenderText_Solid(font, "0", { 0xFF, 0xFF, 0xFF, 0xFF });
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	srcRect.x = srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;
	destRect.x = static_cast<int>(position.x);
	destRect.y = static_cast<int>(position.y);
	destRect.w = width;
	destRect.h = height;
}

Score::~Score()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Score::draw()
{
	TextureHandler::DrawTexture(texture, srcRect, destRect);
}