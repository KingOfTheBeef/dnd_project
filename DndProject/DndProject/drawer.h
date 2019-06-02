#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <map>

enum rect_colour { RECT_GREEN, RECT_BROWN, RECT_RED, RECT_BLACK };
// enum font_type	{IMPACT, IMPACTED, UNICODEIMPACT};

static class drawer
{
public:
	static bool registerTexture(std::string textureName, char* filename);
	static bool registerFont(std::string fontName, char* filename, int size);
	static bool unregisterTexture(std::string textureID);
	static void setRenderer(SDL_Renderer* renderer);

	static void drawTexture(int xPos, int yPos, int width, int height, std::string textureID, bool flip);
	
	static void drawRect(int xPos, int yPos, int width, int height, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
	static void drawRect(int xPos, int yPos, int width, int height, rect_colour colour = RECT_BLACK);

	static void drawText(int xPos, int yPos, int width, int height, std::string fontName, char* text);

private:
	static std::map<std::string, SDL_Texture*> textureMap;
	static std::map<std::string, TTF_Font*> fontMap;
	static SDL_Renderer* renderer;
};