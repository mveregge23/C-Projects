// Program name: WaterMonster.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WaterMonster.cpp contains an implementation for the derived WaterMonster class.
// WaterMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#include "WaterMonster.hpp"

WaterMonster::WaterMonster()
{
	this->name = "Water Sprite";
	this->hp = 40;
	this->damage = 5;
	this->weakness = EARTH;
	this->resistance = FIRE;
	this->type = WATER;
}