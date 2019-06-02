#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Text
{
private:
	float xPos, yPos, width, height;
	std::string text;

public:
	Text(float xPos, float yPos, float width, float height, std::string text);
	void update();
	void draw();
	void clean();
};