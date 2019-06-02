#pragma once

#include <string>
#include <vector>

#include "items.h"

class characterSheet
{
private:
	std::string name;
	int str, dex, spd, atk, def, exp;

	int carryCap;
	std::vector<item*> inventory;


};