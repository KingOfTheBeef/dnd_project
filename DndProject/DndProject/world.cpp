#include <algorithm>
#include <iostream>

#include "world.h"
#include "drawer.h"
#include "Actor.h"
#include "Camera.h"



World::World()
{
	collisionLayer = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	drawLayer = {
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0 },
		{ 0, 1, 0, 2, 2, 2, 2, 0, 0 },
		{ 0, 1, 0, 0, 7, 0, 0, 0, 0 },
		{ 0, 1, 0, 7, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 2, 0 },
		{ 0, 1, 1, 1, 0, 0, 2, 2, 0 },
		{ 0, 0, 0, 1, 0, 0, 2, 2, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0 }
	};

	actors = {};

	Camera::Instance()->setTargetX(&targetX);
	Camera::Instance()->setTargetY(&targetY);

}

void World::load()
{
	drawer::registerTexture("grass", "ColourBlocks\\grass.bmp");
	drawer::registerTexture("path", "ColourBlocks\\path.bmp");
	drawer::registerTexture("playerf", "ColourBlocks\\playerf.png");
	drawer::registerTexture("wall", "ColourBlocks\\wall.bmp");
	addActor(new Actor(4, 7, 50, 50, "playerf"));
}

void World::addActor(Actor* actor)
{
	actors.push_back(actor);
}

void World::draw() 
{
	// Draw the map layer


	// for (mapLayer::iterator it = drawLayer.begin(); it != drawLayer.end(); it++)
	
	/*
	for (int i = std::max(0, y_view * -1); i < std::min(8, (int)drawLayer.size() - y_view); i++)
	{
		// for (std::vector<int>::iterator it2 = it->begin() + 1; it2 != it->end() + 1; it2++)
		for (int j = std::max(0, x_view * -1) ; j < std::min(8, (int) drawLayer[i].size() - x_view); j++)
		{
			switch (drawLayer[i + y_view][j + x_view])
			{
				case(0):
					drawer::drawRect((j + x_view) * TILE_WIDTH - Camera::Instance()->getX(), (i + y_view) * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_GREEN);
					break;
				case(1):
					drawer::drawRect((j + x_view) * TILE_WIDTH - Camera::Instance()->getX(), (i + y_view) * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BROWN);
					break;
				case(2):
					drawer::drawRect((j + x_view) * TILE_WIDTH - Camera::Instance()->getX(), (i + y_view) * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BLACK);
					break;
				default:
					drawer::drawRect((j + x_view) * TILE_WIDTH - Camera::Instance()->getX(), (i + y_view) * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_RED);
					break;
			}
		}
	}
	*/
	for (int i = 0; i < drawLayer.size(); i++)
	{
		// for (std::vector<int>::iterator it2 = it->begin() + 1; it2 != it->end() + 1; it2++)
		for (int j = 0; j < (int)drawLayer[i].size(); j++)
		{
			switch (drawLayer[i][j])
			{
			case(0):
				//drawer::drawRect( j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_GREEN);
				drawer::drawTexture(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, "grass", false);
				break;
			case(1):
				//drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BROWN);
				drawer::drawTexture(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, "path", false);
				break;
			case(2):
				// drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BLACK);
				drawer::drawTexture(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, "wall", false);
				break;
			default:
				drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_RED);
				break;
			}
		}
	}
	/*
	for (int i = std::max(0, y_view); i < std::min(8, (int)drawLayer.size() - y_view); i++)
	{
		// for (std::vector<int>::iterator it2 = it->begin() + 1; it2 != it->end() + 1; it2++)
		for (int j = std::max(0, x_view); j < std::min(8, (int)drawLayer[i].size() - x_view); j++)
		{
			switch (drawLayer[i + y_view][j + x_view])
			{
			case(0):
				drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_GREEN);
				break;
			case(1):
				drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BROWN);
				break;
			case(2):
				drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_BLACK);
				break;
			default:
				drawer::drawRect(j * TILE_WIDTH - Camera::Instance()->getX(), i * TILE_HEIGHT - Camera::Instance()->getY(), TILE_WIDTH, TILE_HEIGHT, RECT_RED);
				break;
			}
		}
	}
	*/


	// Draw the actors onto the map
	/*
	for (int i = 0; i < actors.size(); i++)
	{
		if (x_view - 1 <= actors[i]->getX() && actors[i]->getX() < x_view + 9
			&& y_view - 1 <= actors[i]->getY() && actors[i]->getY() < y_view + 9)
		{
			drawer::drawTexture(actors[i]->getDrawX() * TILE_WIDTH - Camera::Instance()->getX(), actors[i]->getDrawY() * TILE_HEIGHT - Camera::Instance()->getY(), actors[i]->getWidth(), actors[i]->getHeight(), actors[i]->getTextureID(), false);
		}
	}
	*/

	for (int i = 0; i < actors.size(); i++)
	{
		drawer::drawTexture(actors[i]->getDrawX() * TILE_WIDTH - Camera::Instance()->getX(), actors[i]->getDrawY() * TILE_HEIGHT - Camera::Instance()->getY(), actors[i]->getWidth(), actors[i]->getHeight(), actors[i]->getTextureID(), false);
	}
}

void World::shiftXview(int shift)
{
	x_view += shift;
	targetX = (float)(x_view * TILE_WIDTH);
}

void World::shiftYview(int shift)
{
	y_view += shift;
	targetY = (float)(y_view * TILE_HEIGHT);
}

void World::setXview(int xView)
{
	x_view = xView;
	targetX = (float)(x_view * TILE_WIDTH);
}

void World::setYview(int yView)
{
	y_view = yView;
	targetY = (float)(y_view * TILE_HEIGHT);
}

void World::update()
{
	for (int i = 0; i < actors.size(); i++)
	{
		actors[i]->update();
	}
}