#pragma once
#include <SDL.h>
enum MOUSE
{
	LEFT = 0,
	RIGHT = 1,
	MIDDLE = 2,
	MAXBUTTONS = 3
};

class inputHandler {
public:
	static inputHandler* Instance();

	void update();	// must be called each loop to update all the inputs

	bool checkKeyboard(SDL_Scancode SDL_SCANCODE);
	bool checkMouseButton(int mouseButton);
	int getMouseX();
	int getMouseY();

private:
	const Uint8* keyboardState;

	void updateKeyboard();
	void updateMousePosition();
	void updateMouseButton(int pMouseButton, bool state); // event.button.button, true is pressed false is released

	int mouseX, mouseY;
	bool mouseButtons[MOUSE::MAXBUTTONS];

	static inputHandler* instance;

};