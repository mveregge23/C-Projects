// Program name: MonsterSpace.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: MonsterSpace.cpp contains an implementation of the derived
// MonsterSpace class. MonsterSpace inherits most data members and functions
// from the Space parent class, but defines its own monster data member, and 
// a constructor and accessor to manage it. 

#include "MonsterSpace.hpp"

//constructor inherits behavior from Space constructor, and  accepts a 
//Monster pointer to initialize the monster data member
MonsterSpace::MonsterSpace(Monster* m) : Space()
{
	this->monster = m;
	this->st = MONSTER;
}

//interact tells the user what will happen on this space
void MonsterSpace::interact() 
{
	std::cout << "You encountered a " << *this->monster << "! Press enter to battle...";
	std::cin.ignore();
}

//getMonster is an accessor for the monster data member
Monster* MonsterSpace::getMonster()
{
	return this->monster;
}

//destructor deallocates memory for the monster
MonsterSpace::~MonsterSpace()
{
	if (this->monster != nullptr)
	{
		delete this->monster;
	}
}