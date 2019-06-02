#pragma once

#include <string>

class Actor
{
protected:
	int xPos, yPos, width, height;
	std::string textureID;

public:
	Actor(int xPos, int yPos, int width, int height, std::string textureID);

	virtual void update();

	int getX();
	int getY();
	virtual float getDrawX();
	virtual float getDrawY();

	int getWidth();
	int getHeight();
	std::string getTextureID();
};