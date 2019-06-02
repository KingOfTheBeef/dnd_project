#pragma once

#include "gameObject.h"

enum OBJECT_TYPE
{
	charcter = 0,
	object = 1,

};


class worldObject : gameObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;


	worldObject(std::string ptextureID) : textureID(ptextureID) {}
	void setX(int pX_coord) { x_coord = pX_coord; }
	void setY(int pY_coord) { y_coord = pY_coord; }

	int getX() { return x_coord; }
	int getY() { return y_coord; }



private:
	int x_coord = 0, y_coord = 0;
	std::string textureID;
};