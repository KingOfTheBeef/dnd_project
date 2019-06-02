#include "inputHandler.h"
#include "game.h"

inputHandler* inputHandler::instance = 0;

inputHandler* inputHandler::Instance()
{
	if (!inputHandler::instance)
		inputHandler::instance = new inputHandler();
	return inputHandler::instance;
}

void inputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		switch (event.type) {
		case(SDL_MOUSEMOTION):
			mouseX = event.motion.x;
			mouseY = event.motion.y;
			break;
		case(SDL_MOUSEBUTTONDOWN):
			updateMouseButton(event.button.button, true);
			break;
		case(SDL_MOUSEBUTTONUP):
			updateMouseButton(event.button.button, false);
			break;
		case(SDL_QUIT):
			game::Instance()->stopRunning();
			break;
		}
	}

	updateKeyboard();


}

void inputHandler::updateMouseButton(int pMouseButton, bool pState)
{
	switch (pMouseButton)
	{
	case(SDL_BUTTON_LEFT):
		mouseButtons[MOUSE::LEFT] = pState;
	case(SDL_BUTTON_RIGHT):
		mouseButtons[MOUSE::RIGHT] = pState;
	case(SDL_BUTTON_MIDDLE):
		mouseButtons[MOUSE::MIDDLE] = pState;
	}
}

void inputHandler::updateKeyboard()
{
	keyboardState = SDL_GetKeyboardState(NULL);
}

bool inputHandler::checkMouseButton(int pMouseButton)
{
	return mouseButtons[pMouseButton];
}

bool inputHandler::checkKeyboard(SDL_Scancode pScancode)
{
	if (keyboardState[pScancode])
		return true;
	else
		return false;
}

int inputHandler::getMouseX()
{
	return mouseX;
}

int inputHandler::getMouseY()
{
	return mouseY;
}