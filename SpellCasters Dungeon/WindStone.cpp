// Program name: WindStone.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WindStone.cpp contains a specification for the derived
// WindStone class. WindStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#include "WindStone.hpp"

WindStone::WindStone()
{
	this->damage = 10;
	this->name = "wind stone";
	this->type = WIND;
	this->uses = 10;
}
