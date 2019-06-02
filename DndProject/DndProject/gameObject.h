#pragma once

#include <string>

class gameObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;
};