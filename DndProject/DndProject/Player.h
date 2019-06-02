#pragma once

#include "Creature.h"
#include "inputHandler.h"

enum Facing {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

class Player : public Creature
{
private:

	bool aLeft = false, aRight = false, aUp = false, aDown = false;
	Facing facing;

public:
	Player(int xPos, int yPos, int width, int height, std::string textureID);
	void update();
};