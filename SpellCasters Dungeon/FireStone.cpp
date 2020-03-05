// Program name: FireStone.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: FireStone.cpp contains a specification for the derived
// FireStone class. FireStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#include "FireStone.hpp"

FireStone::FireStone()
{
	this->damage = 10;
	this->name = "fire stone";
	this->type = FIRE;
	this->uses = 10;
}
