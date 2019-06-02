#include <iostream>
#include "Player.h"

Player::Player(int xPos, int yPos, int width, int height, std::string textureID) : Creature(xPos, yPos, width, height, textureID)
{
	facing = SOUTH;
}

void Player::update()
{

	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_UP))
		aUp = true;
	else if (aUp)
	{
		aUp = false;
		shiftY(-1);
		facing = NORTH;
	}

	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_LEFT))
		aLeft = true;
	else if (aLeft)
	{
		aLeft = false;
		shiftX(-1);
		facing = WEST;
	}

	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_RIGHT))
		aRight = true;
	else if (aRight)
	{
		aRight = false;
		shiftX(1);
		facing = EAST;
	}
	if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_DOWN))
		aDown = true;
	else if (aDown)
	{
		aDown = false;
		shiftY(1);
		facing = SOUTH;
	}
	Creature::update();
}
