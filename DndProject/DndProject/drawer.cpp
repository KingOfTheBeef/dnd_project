#include "drawer.h"
#include <iostream>
#include <SDL_image.h>

SDL_Renderer* drawer::renderer = 0;
std::map<std::string, SDL_Texture*> drawer::textureMap;
std::map<std::string, TTF_Font*> drawer::fontMap;

bool drawer::registerTexture(std::string textureName, char* filename)
{
	if (!filename)
	{
		std::cout << "No filename" << std::endl;
		return false;
	}
	else if (textureName == "")
	{
		std::cout << "No texture name" << std::endl;
		return false;
	}

	SDL_Surface* temp = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	textureMap[textureName] = texture;
	SDL_FreeSurface(temp);
	return true;
}

bool drawer::registerFont(std::string fontName, char * filename, int size)
{
	if (!filename)
	{
		std::cout << "No filename" << std::endl;
		return false;
	}
	else if (fontName == "")
	{
		std::cout << "No font name" << std::endl;
		return false;
	}

	TTF_Font* font = TTF_OpenFont(filename, size);
	fontMap[fontName] = font;
	return true;
}

bool drawer::unregisterTexture(std::string textureID)
{
	std::map<std::string, SDL_Texture*>::iterator iter = drawer::textureMap.find(textureID);
	if (iter == drawer::textureMap.end())
	{
		std::cout << "Couldn't unregister texture. " + textureID << std::endl;
		return false;
	}
	else
	{
		drawer::textureMap.erase(textureID);
		return true;
	}
}

void drawer::setRenderer(SDL_Renderer* renderer)
{
	drawer::renderer = renderer;
}

void drawer::drawTexture(int xPos, int yPos, int width, int height, std::string textureID, bool flip) {
	SDL_Rect dest;
	dest.x = xPos;
	dest.y = yPos;
	dest.w = width;
	dest.h = height;

	SDL_RenderCopyEx(renderer, textureMap[textureID], NULL, &dest, NULL, NULL, (flip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void drawer::drawRect(int xPos, int yPos, int width, int height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_Rect rect;
	rect.x = xPos;
	rect.y = yPos;
	rect.w = width;
	rect.h = height;

	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
}

void drawer::drawRect(int xPos, int yPos, int width, int height, rect_colour colour)
{
	switch (colour)
	{
		case(RECT_BROWN):
			drawRect(xPos, yPos, width, height, 255, 204, 153);
			break;
		case(RECT_GREEN):
			drawRect(xPos, yPos, width, height, 178, 255, 102);
			break;
		case(RECT_RED):
			drawRect(xPos, yPos, width, height, 255, 0, 0);
			break;
		default:
			drawRect(xPos, yPos, width, height, 0, 0, 0);
			break;
	}
}

void drawer::drawText(int xPos, int yPos, int width, int height, std::string fontName, char* text)
{
	SDL_Surface* temp = TTF_RenderText_Solid(fontMap[fontName], text, { 255, 255, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_Rect rect = { xPos, yPos, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(temp);
	SDL_DestroyTexture(texture);
}
