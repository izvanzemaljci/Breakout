#include "TextureHandler.h"

SDL_Texture *TextureHandler::LoadTexture(const char *fileName)
{
	SDL_Surface *tempSurface = IMG_Load(fileName);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureHandler::DrawTexture(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}