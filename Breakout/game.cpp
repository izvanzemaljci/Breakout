#include "game.h"
#include "TextureHandler.h"
#include "BrickMap.h"
#include "System\Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "Score.h"

Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
TTF_Font *Game::scoreFont = nullptr;

bool Game::isRunning = false;

auto& background(manager.addEntity());
auto& wall1(manager.addEntity());
auto& wall2(manager.addEntity());
auto& wall3(manager.addEntity());
auto& wall4(manager.addEntity());
auto& playerBall(manager.addEntity());
auto& playerVessel(manager.addEntity());
auto& playerScore(manager.addEntity());

Game::Game()
{
}


Game::~Game()
{
	
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised!" << std::endl;

		TTF_Init();

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		
		scoreFont = TTF_OpenFont("Files/atari-abandoned.ttf", 15);
		
		isRunning = true;
	} else {
		isRunning = false;
	}

	BrickMap::loadBrickMap("Files/map.map.txt", 20, 3, 3, 3);
	playerScore.addComponent<Score>(Vector2D(70, 520), renderer, scoreFont);

	playerBall.addComponent<TransformComponent>((800 / 2.0f) - (8 / 2.0f), 496.0f, 8, 8, 1);
	playerBall.addComponent<SpriteComponent>("Textures/Player.png");
	playerBall.addComponent<Collider>("playerBall");
	playerBall.addGroup(Game::groupPlayer);

	playerVessel.addComponent<TransformComponent>((800 / 2.0f) - (24 / 2.0f), 504.0f, 8, 24, 1);
	playerVessel.addComponent<SpriteComponent>("Textures/PlayerVessel.png");
	playerVessel.addComponent<InputHandler>();

	background.addComponent<TransformComponent>(0.0f, 0.0f, 600, 800, 1);
	background.addComponent<SpriteComponent>("Textures/Boards/Board_01.png");
	background.addGroup(Game::groupBackground);
}

auto &backgrounds(manager.getGroup(Game::groupBackground));
auto &tiles(manager.getGroup(Game::groupMap));
auto &players(manager.getGroup(Game::groupPlayer));
auto &walls(manager.getGroup(Game::groupWalls));

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update() 
{
	manager.refresh();
	manager.update();

	TransformComponent *pBall = &playerBall.getComponent<TransformComponent>();

	playerBall.getComponent<TransformComponent>().update(0);
	playerBall.getComponent<TransformComponent>().move(-1.0f, -1.0f, 3);

	pBall->update(0);
	pBall->move(0.0f, -1.0f, 3);
	
	if (pBall->position.x + pBall->width > 704.0f) {
		pBall->position.x = 693.0f;
		pBall->move(-1.0f, -1.0f, -3);
	}
	else if (pBall->position.x < 96.0f) {
		pBall->position.x = 97.0f;
		pBall->move(1.0f, -1.0f, 3);
	}
	else if (pBall->position.y < 128.0f) {
		pBall->position.y = 129.0f;
		pBall->move(1.0f, -1.0f, -3);
	}
	else if (pBall->position.y + pBall->height > 520.0f)
	{
		pBall->position.y = 511.0f;
		pBall->move(1.0f, -1.0f, 3);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto &b : backgrounds)
	{
		b->draw();
	}
	for (auto &t : tiles)
	{
		t->draw();
	}
	for (auto &p : players)
	{
		p->draw();
	}
	
	playerScore.draw();
	
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(scoreFont);
	TTF_Quit();
	SDL_Quit();
}
