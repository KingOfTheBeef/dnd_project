#include <iostream>
#include <string>
#include <SDL.h>
#include <vector>
#include<SDL_image.h>
#include <SDL_ttf.h>

#include "items.h"
#include "game.h"
#include "inputHandler.h"
#include "drawer.h"
#include "world.h"
#include "Actor.h"
#include "Camera.h"
#include "Creature.h"
#include "game.h"

/*
SDL_Surface* resizeSurface(SDL_Surface* surface, Uint16 width, Uint16 height)
{
	if (!surface || !width || !height)
		return 0;
	SDL_Surface* resizedSurface = SDL_CreateRGBSurface(surface->flags, width, height, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask);
	double y_scalefactor = static_cast<double>(width) / static_cast<double> (surface->w);
	double x_scalefactor = static_cast<double>(height) / static_cast<double>(surface->h);

	for (Sint32 y = 0; y < surface->h; y++) {
		for (Sint32 x = 0; x < surface->w; x++) {
			for (Sint32 o_y = 0; o_y < y_scalefactor; o_y++) {
				for (Sint32 o_x = 0; o_x < x_scalefactor; o_x++) {
					Draw_Pixel
				}
			}
		}
	}

}

class character
{
public:
	character(std::string pname) {
		m_name = pname;
	}
	void displayName() {
		std::cout << m_name << std::endl;
	}

private:
	std::string m_name;

};

typedef std::vector < std::vector <int> > Vector2D;


Vector2D collisionsLayer = {
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 }
};

Vector2D bombLayer = {
	{ 1, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1 }
};

Vector2D map = {
	{ 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 2, 2 },
	{ 0, 1, 1, 1, 0, 0, 2, 2 },
	{ 0, 0, 0, 1, 0, 0, 2, 2 },
	{ 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0 }
};


void checkBomb(int x, int y)
{
	if (bombLayer[y][x] == 1)
		std::cout << "BOOM!" << std::endl;
	else
		std::cout << "SAFE" << std::endl;
}

int checkCollision(int x, int y)
{
	return collisionsLayer[y][x];
}
*/

int main(int argc, char* args[])
{
	const int FPS = 60;
	const float frameDelay = 1000.0f / FPS;

	Uint32 frameStart, frameTime;

	// World* world = new World();

	game::Instance();
	Camera::Instance();

	Creature *act = new Creature(0, 0, 50, 50, "player");
	Actor *act2 = act;
	// world->addActor(act);

	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;

	bool aUp = 0, aDown = 0, aLeft = 0, aRight = 0;



	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		TTF_Init();

		std::cout << "SDL Initialised" << std::endl;
		
		
		SDL_Window* m_window = SDL_CreateWindow("DnD Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 50* 8, 50 * 8, SDL_WINDOW_SHOWN);
		SDL_Renderer* m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		
		drawer::registerFont("impact", "impact.ttf", 100);

		/*
		TTF_Font *font = TTF_OpenFont("impact.ttf", 500);
		SDL_Surface *surface = TTF_RenderText_Solid(font, "D N D", { 255, 255, 255 });
		SDL_Texture *text = SDL_CreateTextureFromSurface(m_renderer, surface);
		SDL_Rect *textBox = new SDL_Rect();
		textBox->x = 0;
		textBox->y = 300;
		textBox->h = 100;
		textBox->w = 400;
		*/

		drawer::setRenderer(m_renderer);
		drawer::registerTexture("player", "player.png");
		
		game::Instance()->load();
		// world->load();

		int c = 0;
		// bool m_running = game::Instance()->checkRunning();


		while (game::Instance()->checkRunning())
		{
			c++;
			frameStart = SDL_GetTicks();

			// DO STUFF

			inputHandler::Instance()->update();
			/*
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_W))
				up = true;
			else if (up)
			{
				world->shiftYview(-4);
				up = false;
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_A))
				left = true;
			else if (left)
			{
				world->shiftXview(-4);
				left = false;
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_S))
				down = true;
			else if (down)
			{
				world->shiftYview(4);
				down = false;
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_D))
				right = true;
			else if (right)
			{
				world->shiftXview(4);
				right = false;
				act->shiftX(1);
			}
			
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_UP))
				aUp = true;
			else if (aUp)
			{
				aUp = false;
				act->shiftY(-1);
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_LEFT))
				aLeft = true;
			else if (aLeft)
			{
				aLeft = false;
				act->shiftX(-1);
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_RIGHT))
				aRight = true;
			else if (aRight)
			{
				aRight = false;
				act->shiftX(1);
			}
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_DOWN))
				aDown = true;
			else if (aDown)
			{
				aDown = false;
				act->shiftY(1);
			}

			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_SPACE)) {
				world->setXview(0);
				world->setYview(0);
			}
			*/

			game::Instance()->update();
			Camera::Instance()->update();
			//act2->update();
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_Q))
			{
				c = 0;
			}
			// SDL_SetRenderDrawColor(m_renderer, c % 256, (c + 128) % 256, c % 128, 255);

			SDL_RenderClear(m_renderer);

			game::Instance()->draw();

			// world->draw();

			SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
			// drawer::drawTexture(player.x, player.y, player.w, player.h, "player", true);
			if (inputHandler::Instance()->checkKeyboard(SDL_SCANCODE_E))
			{
				drawer::drawText(0, 300, 400, 33, "impact", "Hello, drawn from the drawer");
				drawer::drawText(0, 333, 400, 33, "impact", "This is the second line, so mean!");
				drawer::drawText(0, 366, 400, 33, "impact", "Wub dub, end of text");
				// SDL_RenderFillRect(m_renderer, textBox);
				// SDL_RenderCopy(m_renderer, text, NULL, textBox);
			}
			SDL_RenderPresent(m_renderer);

			game::Instance()->clean();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < frameDelay)
				SDL_Delay((int)(frameDelay - frameTime));
			// m_running = game::Instance()->checkRunning();

		}

	}

	/*
	character* player = new character("Jonathan");
	player->displayName();

	weapon* sword = new weapon("Rusty Ol Blade", "A rusty ol blade found, hasn't been used in years...", 5, 20);

	std::cout << "Weapon Effects" << std::endl;
	for (int i = 0; i < sword->getEffects().size(); i++)
	{
		std::cout << sword->getEffects()[i];
	}
	std::cout << sword->getName() << std::endl;
	std::cout << sword->getDesc() << std::endl;


	// std::cout << sword->getEffects()[0];
	*/

	//std::cin.get();
	// std::cin.ignore();
	return 0;
}