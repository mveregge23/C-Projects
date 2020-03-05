// Program name: WindMonster.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WindMonster.cpp contains an implementation for the derived WindMonster class.
// WindMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#include "WindMonster.hpp"

WindMonster::WindMonster()
{
	this->name = "Wind Rider";
	this->hp = 30;
	this->damage = 7;
	this->weakness = WIND;
	this->resistance = EARTH;
	this->type = WIND;
}