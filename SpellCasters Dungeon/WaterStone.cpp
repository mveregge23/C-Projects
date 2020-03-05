// Program name: WaterStone.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WaterStone.cpp contains a specification for the derived
// WaterStone class. WaterStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#include "WaterStone.hpp"

WaterStone::WaterStone()
{
	this->damage = 10;
	this->name = "water stone";
	this->type = WATER;
	this->uses = 10;
}
