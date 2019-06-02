#include "playerObject.h"
#include "drawer.h"

void playerObject::draw()
{
	drawer::drawTexture(*xPos, *yPos, width, height, "player", true);
}

int* playerObject::getX()
{
	return xPos;
}

int* playerObject::getY()
{
	return yPos;
}

int playerObject::getWidth()
{
	return width;
}

int playerObject::getHeight()
{
	return height;
}
