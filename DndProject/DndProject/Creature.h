#pragma once
#include "Actor.h"

class Creature : public Actor
{
private:
	float drawX, drawY;
	void updateMove();

public:
	Creature(int xPos, int yPos, int width, int height, std::string textureID);

	void setX(int x);
	void setY(int y);
	void shiftX(int x);
	void shiftY(int y);

	float getDrawX();
	float getDrawY();
	void update();
};