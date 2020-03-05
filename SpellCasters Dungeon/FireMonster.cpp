// Program name: FireMonster.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: FireMonster.cpp contains an implementation for the derived FireMonster class.
// FireMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#include "FireMonster.hpp"

FireMonster::FireMonster()
{
	this->name = "Fire Demon";
	this->hp = 20;
	this->damage = 10;
	this->weakness = WATER;
	this->resistance = WIND;
	this->type = FIRE;
}
