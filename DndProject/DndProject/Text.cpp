#include "Text.h"



Text::Text(float xPos, float yPos, float width, float height, std::string text)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
	this->text = text;

	TTF_Font *font = TTF_OpenFont("impact.ttf", 500);
	SDL_Surface *surface = TTF_RenderText_Solid(font, "D N D", { 255, 255, 255 });
	SDL_Texture *text = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_Rect *textBox = new SDL_Rect();
	textBox->x = 0;
	textBox->y = 300;
	textBox->h = 100;
	textBox->w = 400;
}
