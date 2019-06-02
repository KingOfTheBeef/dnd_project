#include <string>
#include "gameObject.h"

#pragma once

class playerObject : public gameObject {

private:
	int *xPos, *yPos, width, height;
	std::string texture = "player";

protected:
	void update();
	void draw();
	void clean();

public:
	int* getX();
	int* getY();
	int getWidth();
	int getHeight();
};