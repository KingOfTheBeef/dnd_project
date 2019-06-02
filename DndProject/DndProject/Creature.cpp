#include <iostream>
#include "Creature.h"

Creature::Creature(int xPos, int yPos, int width, int height, std::string textureID) : Actor(xPos, yPos,width, height, textureID)
{
	this->drawX = xPos;
	this->drawY = yPos;
}

void Creature::setX(int x)
{
	xPos = x;
}

void Creature::setY(int y)
{
	yPos = y;
}

void Creature::shiftX(int x)
{
	xPos += x;
}

void Creature::shiftY(int y)
{
	yPos += y;
}

float Creature::getDrawX()
{
	return drawX;
}

float Creature::getDrawY()
{
	return drawY;
}

void Creature::update()
{
	updateMove();
}

void Creature::updateMove()
{
	if (drawX < xPos)
	{
		drawX += 0.3;
		if (drawX > xPos)
		{
			drawX = xPos;
		}
	}
	else if (drawX > xPos)
	{
		drawX -= 0.3;
		if (drawX < xPos)
		{
			drawX = xPos;
		}
	}

	if (drawY < yPos)
	{
		drawY += 0.3;
		if (drawY > yPos)
		{
			drawY = yPos;
		}
	}
	else if (drawY > yPos)
	{
		drawY -= 0.3;
		if (drawY < yPos)
		{
			drawY = yPos;
		}
	}
}