// Program name: EarthStone.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: EarthStone.cpp contains a specification for the derived
// EarthStone class. EarthStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#include "EarthStone.hpp"

EarthStone::EarthStone()
{
	this->damage = 10;
	this->name = "earth stone";
	this->type = EARTH;
	this->uses = 10;
}
