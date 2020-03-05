// Program name: ArmorSpace.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: ArmorSpace.cpp contains an implementation of the derived
// ArmorSpace class. ArmorSpace inherits most data members and functions
// from the Space parent class, but defines its own armor data member, and 
// a constructor and accessor to manage it. 

#include "ArmorSpace.hpp"

//constructor inherits behavior from the Space constructor, and
//accepts a SpellStone pointer to initialize the stone data member
ArmorSpace::ArmorSpace(Armor* a) : Space()
{
	this->armor = a;
	this->st = ARMOR;
}

//interact tells the user what will happen on this space
void ArmorSpace::interact()
{
	std::cout << "You found " << *this->armor << "! Press Enter to put it on...";
	std::cin.ignore();
}

//getStone is an accessor for the stone data member that removes the armor
//member from the Armor space
Armor* ArmorSpace::getArmor()
{
	Armor* temp = this->armor;
	this->armor = nullptr;
	return temp;
}

//addArmor is a mutator for the stone data member
void ArmorSpace::addArmor(Armor* a)
{
	this->armor = a;
}

//destructor deallocates memory for the armor
ArmorSpace::~ArmorSpace()
{

	//check if armor pointer is not equal to nullptr
	if (this->armor != nullptr)
	{

		//yes: deallocate memory for armor
		delete this->armor;
	}
	
}