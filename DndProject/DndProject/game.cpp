#include "game.h"
#include <iostream>
#include "inputHandler.h"
#include "Player.h"

game * game::instance = 0;

game::game()
{
	running = true;
	world = new World();
}

game* game::Instance()
{
	if (!instance)
	{
		instance = new game();
		std::cout << "Something" << std::endl;
	}
	return instance;
}

void game::update()
{
	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_W))
		up = true;
	else if (up)
	{
		world->shiftYview(-4);
		up = false;
	}
	
	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_A))
		left = true;
	else if (left)
	{
		world->shiftXview(-4);
		left = false;
	}

	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_S))
		down = true;
	else if (down)
	{
		world->shiftYview(4);
		down = false;
	}

	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_SPACE)) {
		world->setXview(0);
		world->setYview(0);
	}
	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_D))
		right = true;
	else if (right)
	{
		world->shiftXview(4);
		right = false;
	}

	world->update();
}
void game::draw()
{
	world->draw();
}
void game::clean()
{

}

void game::load()
{
	world->load();
	world->addActor(new Player(0, 0, 50, 50, "player"));
}