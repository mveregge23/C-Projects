// Program name: SpellStoneSpace.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: SpellStoneSpace.cpp contains an implementation of the derived
// SpellStoneSpace class. SpellStoneSpace inherits most data members and functions
// from the Space parent class, but defines its own stone data member, and 
// a constructor and accessor to manage it. 

#include "SpellStoneSpace.hpp"

//constructor inherits behavior from the Space constructor, and
//accepts a SpellStone pointer to initialize the stone data member
SpellStoneSpace::SpellStoneSpace(SpellStone* ss) : Space()
{
	this->stone = ss;
	this->st = SPELLSTONE;
}

//interact tells the user what will happen on this space
void SpellStoneSpace::interact()
{
	std::cout << "You found a " << *this->stone << "! Press Enter to add it to your stone pack...";
	std::cin.ignore();
}

//getStone is an accessor for the stone data member
SpellStone* SpellStoneSpace::getStone()
{
	SpellStone* temp = this->stone;
	this->stone = nullptr;
	return temp;
}

//addStone is a mutator for the stone data member
void SpellStoneSpace::addStone(SpellStone* stone)
{
	this->stone = stone;
}

//destructor deallocates memory for the spell stone
SpellStoneSpace::~SpellStoneSpace()
{
	
	if (this->stone != nullptr)
	{ 
		delete this->stone;
	}
	
}