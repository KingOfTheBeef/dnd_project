#include "Actor.h"

Actor::Actor(int xPos, int yPos, int width, int height, std::string textureID)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
	this->textureID = textureID;
}

int Actor::getX()
{
	return xPos;
}

int Actor::getY()
{
	return yPos;
}

void Actor::update()
{

}

float Actor::getDrawX()
{
	return (float)xPos;
}

float Actor::getDrawY()
{
	return (float)yPos;
}

int Actor::getWidth()
{
	return width;
}

int Actor::getHeight()
{
	return height;
}

std::string Actor::getTextureID()
{
	return textureID;
}
