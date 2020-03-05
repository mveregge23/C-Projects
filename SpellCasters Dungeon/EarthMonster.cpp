// Program name: EarthMonster.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: EarthMonster.cpp contains an implementation for the derived EarthMonster class.
// EarthMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#include "EarthMonster.hpp"

EarthMonster::EarthMonster()
{
	this->name = "Earth Mover";
	this->hp = 30;
	this->damage = 7;
	this->weakness = FIRE;
	this->resistance = WATER;
	this->type = EARTH;
}