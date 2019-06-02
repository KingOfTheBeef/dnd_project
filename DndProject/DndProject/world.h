
#pragma once

#include <vector>

#include "Actor.h"

typedef std::vector < std::vector <int> > mapLayer;

class World {
private:
	const int TILE_HEIGHT = 50;
	const int TILE_WIDTH = 50;
	int x_view = 0;
	int y_view = 0;
	float targetX, targetY = 0;

	mapLayer drawLayer, collisionLayer;
	std::vector<Actor*> actors;

public:
	World();

	void load();
	void draw();
	void update();
	void clean();

	void shiftXview(int shift);
	void shiftYview(int shift);
	void setXview(int xView);
	void setYview(int yView);

	void addActor(Actor* actor);
};