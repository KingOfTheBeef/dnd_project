#pragma once
#include <SDL.h>

#include "World.h"

class game
{
public:
	game();
	static game* Instance();

	void update();
	void draw();
	void clean();
	void load();

	bool checkRunning() { return running; }
	void stopRunning() { running = false; }

private:
	bool up = false, down = false, left = false, right = false;


	bool running;
	static game* instance;
	World *world;
};